/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "wyDirector.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "glu.h"
#include "wyTypes.h"
#include "wyActionManager.h"
#include "wyTextureManager.h"
#include "wyZwoptexManager.h"
#include "wyScheduler.h"
#include "wyEventDispatcher.h"
#include "wyMWManager.h"
#include "wySPXManager.h"
#include "wySPX3Manager.h"
#include "wyArcticManager.h"
#include "wyAuroraManager.h"
#include "wyTransitionScene.h"
#include "wyUtils.h"
#include "wyThread.h"
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyBitmapFont.h"
#include "wyToast.h"
#include "wyAutoReleasePool.h"
#include "wyMath.h"

/// global director instance
extern wyDirector* gDirector;

/// director是否正在销毁的标志
bool g_Director_isEnding;

/// global resource decoder
extern wyResourceDecoder* gResDecoder;

/**
 * 抓屏模式, 此模式下以60fps进行抓屏, 即1秒钟产生60张png图片
 * 当想对某个demo做连续抓屏时
 * 1. 确定sd卡可用
 * 2. 确定SCREENSHOT_MODE被定义
 * 3. 运行程序
 * 4. 录制完毕后, 在sd卡的WiEngine目录下获得所有截图图片
 */
//#define SCREENSHOT_MODE

// 只要不重新install apk, 这个index一直增加，因此可以录制多个连起来
#ifdef SCREENSHOT_MODE
	static int sScreenshotFrameIndex = 1;
#endif

extern pthread_mutex_t gMutex;
extern pthread_mutex_t gCondMutex;

// other singleton
extern wyEventDispatcher* gEventDispatcher;
extern wyTextureManager* gTextureManager;
extern wyActionManager* gActionManager;
extern wyScheduler* gScheduler;
extern wyZwoptexManager* gZwoptexManager;
extern wyMWManager* gMWManager;
extern wySPXManager* gSPXManager;
extern wySPX3Manager* gSPX3Manager;
extern wyArcticManager* gArcticManager;
extern wyAuroraManager* gAuroraManager;

#ifdef __cplusplus
extern "C" {
#endif

// extern methods
extern void wyInitAutoReleasePool();
extern void wyClearAutoReleasePool();
extern void wyDestroyAutoReleasePool();
extern void wyOutputLeakPool();
extern void wyClearLeakPool();

#ifdef WY_CFLAG_MEMORY_TRACKING
extern void wyMemoryDumpRecord(bool fullLog);
extern void wyMemoryUsageReport();
#endif
    
#ifdef __cplusplus
}
#endif

bool wyDirector::releaseScene(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

bool wyDirector::notifySurfaceCreated(wyArray* arr, void* ptr, int index, void* data) {
	wyDirectorLifecycleListener* l = (wyDirectorLifecycleListener*)ptr;
	if(l->onSurfaceCreated != NULL)
		l->onSurfaceCreated(data);
	return true;
}

bool wyDirector::notifySurfaceChanged(wyArray* arr, void* ptr, int index, void* data) {
	wyDirectorLifecycleListener* l = (wyDirectorLifecycleListener*)ptr;
	if(l->onSurfaceChanged != NULL)
		l->onSurfaceChanged(wyDevice::winWidth, wyDevice::winHeight, data);
	return true;
}

bool wyDirector::notifySurfaceDestroyed(wyArray* arr, void* ptr, int index, void* data) {
	wyDirectorLifecycleListener* l = (wyDirectorLifecycleListener*)ptr;
	if(l->onSurfaceDestroyed != NULL)
		l->onSurfaceDestroyed(data);
	return true;
}

bool wyDirector::notifyDirectorPaused(wyArray* arr, void* ptr, int index, void* data) {
	wyDirectorLifecycleListener* l = (wyDirectorLifecycleListener*)ptr;
	if(l->onDirectorPaused != NULL)
		l->onDirectorPaused(data);
	return true;
}

bool wyDirector::notifyDirectorResumed(wyArray* arr, void* ptr, int index, void* data) {
	wyDirectorLifecycleListener* l = (wyDirectorLifecycleListener*)ptr;
	if(l->onDirectorResumed != NULL)
		l->onDirectorResumed(data);
	return true;
}

bool wyDirector::notifyDirectorEnded(wyArray* arr, void* ptr, int index, void* data) {
	wyDirectorLifecycleListener* l = (wyDirectorLifecycleListener*)ptr;
	if(l->onDirectorEnded != NULL)
		l->onDirectorEnded(data);
	return true;
}

bool wyDirector::notifyDirectorScreenCaptured(wyArray* arr, void* ptr, int index, void* data) {
	wyDirectorLifecycleListener* l = (wyDirectorLifecycleListener*)ptr;
	if(l->onDirectorScreenCaptured != NULL)
		l->onDirectorScreenCaptured(getInstance()->m_screenshotPath, data);
	return true;
}

wyDirector* wyDirector::getInstanceNoCreate() {
	return gDirector;
}

void wyDirector::printUnreleasedObjects() {
	wyOutputLeakPool();
}

void wyDirector::printUnreleasedMemory(bool fullLog) {
#ifdef WY_CFLAG_MEMORY_TRACKING
	wyMemoryDumpRecord(fullLog);
#else
	LOGW("This method is only available for WiEngine memory debug version");
#endif
}

void wyDirector::printMemoryUsage() {
#ifdef WY_CFLAG_MEMORY_TRACKING
	wyMemoryUsageReport();
#else
	LOGW("This method is only available for WiEngine memory debug version");
#endif
}

wyDirector::wyDirector() :
		m_projection(PROJECTION_DEFAULT),
		m_delta(0.f),
		m_frameDelta(0.f),
		m_frameRate(0.f),
		m_tickFactor(1),
		m_frames(0),
		m_lastUpdateTime(0),
		m_needCheckTexture(false),
		m_paused(false),
		m_UIPaused(false),
		m_displayFPS(false),
		m_calculateFPS(false),
		m_surfaceCreated(false),
		m_enableDepthTest(false),
		m_makeScreenshot(false),
		m_focusEnabled(true),
		m_screenshotPath(NULL),
		m_maxFrameRate(0),
		m_lastFrameTime(0),
		m_minFrameInterval(0),
		m_savedDelta(0),
		m_nextScene(NULL),
		m_runningScene(NULL),
		m_fpsLabel(NULL),
		m_scenesStack(NULL),
		m_lifecycleListeners(wyArrayNew(3)),
		m_clipStack((wyRect*)wyMalloc(10 * sizeof(wyRect))),
		m_clipStackCount(0),
		m_clipStackCapacity(10),
		m_glView(NULL),
		m_context(NULL),
		m_lifecycleData(NULL) {
	// reset global variable
	g_Director_isEnding = false;

	// init math library
#ifdef WY_CFLAG_OPTIMIZE_MATH
	wyMath::init();
#endif

	// create mutex
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&gMutex, &attr);
	pthread_mutex_init(&gCondMutex, &attr);
	pthread_mutexattr_destroy(&attr);

	// ensure other singleton class existence
	wyInitAutoReleasePool();
	wyEventDispatcher::getInstance();
	wyScheduler::getInstance();
	wyActionManager::getInstance();
	wyTextureManager::getInstance();
	wyZwoptexManager::getInstance();

	// create stack
	m_scenesStack = wyArrayNew(10);
}

void wyDirector::notifySurfaceCreated() {
	wyArrayEach(m_lifecycleListeners, notifySurfaceCreated, m_lifecycleData);
}

void wyDirector::notifySurfaceChanged() {
	wyArrayEach(m_lifecycleListeners, notifySurfaceChanged, m_lifecycleData);
}

void wyDirector::notifySurfaceDestroyed() {
	wyArrayEach(m_lifecycleListeners, notifySurfaceDestroyed, m_lifecycleData);
}

void wyDirector::notifyDirectorPaused() {
	wyArrayEach(m_lifecycleListeners, notifyDirectorPaused, m_lifecycleData);
}

void wyDirector::notifyDirectorResumed() {
	wyArrayEach(m_lifecycleListeners, notifyDirectorResumed, m_lifecycleData);
}

void wyDirector::notifyDirectorEnded() {
	wyArrayEach(m_lifecycleListeners, notifyDirectorEnded, m_lifecycleData);
}

void wyDirector::notifyDirectorScreenCaptured() {
	wyArrayEach(m_lifecycleListeners, notifyDirectorScreenCaptured, m_lifecycleData);
}

void wyDirector::setResourceDecoder(wyResourceDecoder* decoder) {
	gResDecoder = decoder;
}

bool wyDirector::pause() {
	if(m_paused || m_glView == NULL)
		return false;

	// set flag
	m_paused = true;

	// stop render
	stopRender();

	// notify
	notifyDirectorPaused();

	return true;
}

bool wyDirector::resume() {
	if(!m_paused || m_glView == NULL)
		return false;

	// set current time as last update time
	m_lastUpdateTime = wyUtils::currentTimeMillis();

	// reset flag
	m_paused = false;
	m_delta = 0;

	// call gl view
	startRender();

	// notify listener
	notifyDirectorResumed();

	return true;
}

bool wyDirector::isEnding() {
	return g_Director_isEnding;
}

wySize wyDirector::getWindowSize() {
	return wys(wyDevice::winWidth, wyDevice::winHeight);
}

int wyDirector::getWindowWidth() {
	return wyDevice::winWidth;
}

int wyDirector::getWindowHeight() {
	return wyDevice::winHeight;
}

void wyDirector::calculateDeltaTime() {
	int64_t now = wyUtils::currentTimeMillis();

	// new delta time
	if(m_lastUpdateTime == 0 || m_nextDeltaTimeZero) {
		m_delta = 0;
		m_nextDeltaTimeZero = false;
	} else {
		m_delta = (now - m_lastUpdateTime) / 1000.0f;
		m_delta = MAX(0, m_delta);
	}

	m_lastUpdateTime = now;
}

void wyDirector::calculateFPS() {
	m_frames++;
	m_frameDelta += m_delta;

	if(m_frames >= 20) {
		m_frameRate = m_frames / m_frameDelta;
		m_frames = 0;
		m_frameDelta = 0;
	}
}

void wyDirector::showFPS() {
	// check fps label
	if(m_fpsLabel == NULL)
		return;

	char buf[20];
	sprintf(buf, "%.1f", m_frameRate);
	m_fpsLabel->setString(buf);
	m_fpsLabel->draw();
}

void wyDirector::setShowFPS(bool show) {
	m_displayFPS = show;
	if(m_displayFPS)
		m_calculateFPS = m_displayFPS;
}

void wyDirector::onSurfaceCreated() {
	// set flag
	m_surfaceCreated = true;

	// get GL thread id
	tagGLThread();

	// 返回OpenGL支持的最大贴图尺寸,设置到wyDevice::maxTextureSize
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &wyDevice::maxTextureSize);

	// 选项:禁用抖动特效，以提高性能。
	glDisable(GL_DITHER);

	// 对透视进行修正
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);

	// enable alpha blending
	setAlphaBlending(true);

	// disable depth test
	setDepthTest(m_enableDepthTest);

	// 指定象素的算法
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// 选项:禁用光照特效
	glDisable(GL_LIGHTING);

	// 禁用剪刀测试
	glDisable(GL_SCISSOR_TEST);

	// 选择平滑方式
	glShadeModel(GL_FLAT);

	// 设置背景色黑色
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// enable event
	gEventDispatcher->setDispatchEvent(true);

	// notify listener
	notifySurfaceCreated();
}

void wyDirector::onSurfaceChanged(int w, int h) {
	// save real size
	wyDevice::realWidth = w;
	wyDevice::realHeight = h;

	// based on scale mode, save real size or recalculate scale
	if(wyDevice::scaleMode == SCALE_MODE_BY_DENSITY) {
		wyDevice::winWidth = w;
		wyDevice::winHeight = h;
	} else {
		wyDevice::baseScaleX = (float)w / wyDevice::winWidth;
		wyDevice::baseScaleY = (float)h / wyDevice::winHeight;
		wyDevice::defaultInDensity = wyDevice::density;
	}

	// create fps label
	if(!m_fpsLabel) {
	    m_fpsLabel = wyLabel::make("00.0", SP(24));
	    m_fpsLabel->retain();
	}

	/*
	 * Here, we only set check texture flag when there is a running scene, that
	 * is to avoid the flag is set during first start
	 */
	if(m_runningScene)
		setNeedCheckTexture(true);

	// set viewport and projection
	setDefaultProjection();

	// ensure we don't have a frame loss when returns
	m_nextDeltaTimeZero = true;

	// notify listener
	notifySurfaceChanged();
}

void wyDirector::onSurfaceDestroyed() {
	if(m_surfaceCreated) {
		m_surfaceCreated = false;
		setNeedCheckTexture(true);

		// notify listener
		notifySurfaceDestroyed();
	}
}

void wyDirector::addLifecycleListener(const wyDirectorLifecycleListener* l, void* data) {
	wyArrayPush(m_lifecycleListeners, (void*)l);
	m_lifecycleData = data;
}

void wyDirector::drawFrame() {
	// process auto release pool
	wyClearAutoReleasePool();

	// check frame rate setting, but neglect it if in screenshot mode
#ifndef SCREENSHOT_MODE
	if(m_maxFrameRate > 0) {
		int64_t now = wyUtils::currentTimeMillis();
		m_savedDelta += now - m_lastFrameTime;
		m_lastFrameTime = now;
		if(m_savedDelta < m_minFrameInterval) {
			// sleep to save power
			usleep((m_minFrameInterval - m_savedDelta) * 1000);

			// recalculate saved delta
			now = wyUtils::currentTimeMillis();
			m_savedDelta += now - m_lastFrameTime;
			m_lastFrameTime = now;
			m_savedDelta %= m_minFrameInterval;
		} else {
			m_savedDelta %= m_minFrameInterval;
		}
	}
#endif

	// need check texture?
	if(m_needCheckTexture) {
		gTextureManager->invalidateAllTextures();
		m_needCheckTexture = false;
	}

	// set default state
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);

	// if we have next scene to set, reset delta time
	if(!m_UIPaused) {
		if(m_nextScene != NULL) {
			m_nextDeltaTimeZero = true;
		}
	}

	// calculate global delta
	calculateDeltaTime();

	// if in screenshot mode, use 60fps always
#ifdef SCREENSHOT_MODE
	m_delta = 1.f / 60.f;
#endif

	if (!m_UIPaused) {
		// update scheduler and actions
		if(!m_paused) {
			gScheduler->tickLocked(m_delta * m_tickFactor);
		}

		// to avoid flicker, nextScene MUST be here: after tick and before draw
		if(m_nextScene != NULL) {
			gotoNextScene();
		}
	}

	if(!m_paused) {
		// draw the scene
		if(m_runningScene != NULL) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			m_runningScene->visit();
		}

		/*
		 * can't move action tick before visit running scene. sometimes the internal
		 * state may not consistent because scheduler already updated before visit.
		 * an example is: move a particle system with an action, can see particle system
		 * shaked consistently.
		 */
        if(!m_UIPaused)
        	gActionManager->tick(m_delta * m_tickFactor);

#ifndef SCREENSHOT_MODE
        // calcuate fps or not
		// but don't calculate fps if in screenshot mode
        if(m_calculateFPS)
        	calculateFPS();

		// show fps or not
		// but don't show fps if in screenshot mode
		if(m_displayFPS)
			showFPS();

		// make screenshot
		if(m_makeScreenshot) {
			m_makeScreenshot = false;

			// make screenshot
			wyUtils::makeScreenshot(m_screenshotPath, m_screenshotRect);

            // notify
			notifyDirectorScreenCaptured();
            
			// free path
			wyFree((void*)m_screenshotPath);
			m_screenshotPath = NULL;
		}
#endif // #ifndef SCREENSHOT_MODE
	}

	// make screenshot
#ifdef SCREENSHOT_MODE
    char fsPath[128];
    sprintf(fsPath, "/sdcard/WiEngine/%06d.png", sScreenshotFrameIndex++);
    const char* path = wyUtils::mapLocalPath(fsPath);
	wyUtils::makeScreenshot(path);
	wyFree((void*)path);
#endif // #ifdef SCREENSHOT_MODE

	// process events
	gEventDispatcher->processEventsLocked();
}

wyDirector::~wyDirector() {
}

void wyDirector::commonDestroy() {
	g_Director_isEnding = true;

	// notify listener
	notifyDirectorEnded();
	
	// stop dispatch events and remove all handlers
	gEventDispatcher->setDispatchEvent(false);

	// remove all textures
	gTextureManager->removeAllTextures();

	// remove all actions
	gActionManager->removeAllActionsLocked();

	// release auto release pool
	wyDestroyAutoReleasePool();

	// free members
	wyObjectRelease(m_fpsLabel);
	if(m_runningScene != NULL) {
		m_runningScene->onExit();
		m_runningScene->cleanup();
	}
	if(m_screenshotPath != NULL) {
		wyFree((void*)m_screenshotPath);
		m_screenshotPath = NULL;
	}
	setRunningScene(NULL);
	setNextScene(NULL);
	wyArrayEach(m_scenesStack, releaseScene, NULL);
	wyArrayDestroy(m_scenesStack);
	wyArrayDestroy(m_lifecycleListeners);
	wyFree(m_clipStack);

	// clear singleton instance
	wyObjectRelease(gTextureManager);
	wyObjectRelease(gScheduler);
	wyObjectRelease(gEventDispatcher);
	wyObjectRelease(gActionManager);
	wyObjectRelease(gZwoptexManager);
	wyObjectRelease(gMWManager);
	wyObjectRelease(gSPXManager);
	wyObjectRelease(gSPX3Manager);
	wyObjectRelease(gArcticManager);
	wyObjectRelease(gAuroraManager);
	wyBitmapFont::unloadAll();
    wyToast::clear();

    // clear resource decoder
	gResDecoder = NULL;

	// now flush all existing auto release pool
	wyAutoReleasePool::flush();

	// check leak
	wyOutputLeakPool();
	wyClearLeakPool();

	// free mutex
	pthread_mutex_destroy(&gMutex);
	pthread_mutex_destroy(&gCondMutex);
	
#ifdef WY_CFLAG_MEMORY_TRACKING
	printUnreleasedMemory(true);
#endif
}

void wyDirector::setDepthTest(bool on) {
	m_enableDepthTest = on;
	if(m_surfaceCreated && isGLThread()) {
		/* 启动禁用深度测试 */
		if(on) {
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LEQUAL);
			glDepthRangef(0, 1);
			glClearDepthf(1);
		} else {
			glDisable(GL_DEPTH_TEST);
		}
	}
}

void wyDirector::setProjection(wyProjectionType projection) {
	switch(projection) {
		case PROJECTION_2D:
			// set projection matrix
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrthof(0, wyDevice::realWidth, 0, wyDevice::realHeight, -1024, 1024);

			// set model view matrix
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			break;
		case PROJECTION_3D:
			// viewport should be whole screen
			glViewport(0, 0, wyDevice::realWidth, wyDevice::realHeight);

			// set projection matrix
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(60, (GLfloat)wyDevice::winWidth / wyDevice::winHeight, 0.5, 1500);

			// set model view matrix
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			// set camera
			gluLookAt(wyDevice::winWidth / 2, wyDevice::winHeight / 2, wyDevice::winHeight / GOLDEN_MEAN, wyDevice::winWidth / 2, wyDevice::winHeight / 2, 0, 0.0f, 1.0f, 0.0f);
			break;
		case PROJECTION_CUSTOM:
			// if custom, ignore it.
			// The user is responsible for setting the correct projection
			break;
		default:
			LOGW("Director: Unrecognized projection");
			break;
	}

	m_projection = projection;
}

void wyDirector::set2DProjection() {
	setProjection(PROJECTION_2D);
}

void wyDirector::set3DProjection() {
	setProjection(PROJECTION_3D);
}

void wyDirector::setDefaultProjection() {
	setProjection(PROJECTION_DEFAULT);
}

void wyDirector::setAlphaBlending(bool on) {
	if(on)
		glEnable(GL_BLEND); // 启用融合
	else
		glDisable(GL_BLEND); // 关闭融合
}

void wyDirector::setCullFace(bool on) {
	if(on) {
		// Counter-clockwise winding.
		glFrontFace(GL_CCW);

		// Enable face culling.
		glEnable(GL_CULL_FACE);

		// What faces to remove with the face culling.
		glCullFace(GL_BACK);
	} else {
		// Disable face culling.
		glDisable(GL_CULL_FACE);
	}
}

void wyDirector::setMaxFrameRate(int maxFrameRate) {
	m_maxFrameRate = maxFrameRate;
	if(m_maxFrameRate > 0) {
		m_savedDelta = 0;
		m_minFrameInterval = 1000 / m_maxFrameRate;
		m_lastFrameTime = wyUtils::currentTimeMillis();
	}
}

void wyDirector::runWithScene(wyScene* scene) {
	if(scene != NULL && m_runningScene == NULL)
		pushScene(scene);
}

void wyDirector::popScene() {
	// check current scene
	if(m_runningScene == NULL)
		return;

	// end or set top scene as the next scene
	if(m_scenesStack->num <= 1) {
		end();
	} else {
		wyObjectRelease((wyObject*)wyArrayPop(m_scenesStack));
		setNextScene((wyScene*)wyArrayPeek(m_scenesStack));
	}
}

void wyDirector::popSceneWithTransition(wyTransitionScene* trans) {
	// check current scene
	if(m_runningScene == NULL)
		return;

	// validate
	if(trans == NULL) {
		LOGW("popSceneWithTransition: transition is null!");
		return;
	}

	// end if only 1 scene
	if(m_scenesStack->num <= 1) {
		end();
	} else {
		wyScene* outScene = (wyScene*)wyArrayPop(m_scenesStack);
		wyScene* inScene = (wyScene*)wyArrayPop(m_scenesStack);
		trans->setInScene(inScene);
		trans->setOutScene(outScene);
		wyObjectRelease(inScene);
		wyObjectRelease(outScene);
		setRunningScene(NULL);
		setNextScene(trans);
	}
}

void wyDirector::pushScene(wyScene* scene) {
	if(m_nextScene) {
		LOGW("wyDirector::pushScene: next scene is already set, you call pushScene multiple times?");
	} else if(scene != NULL) {
		wyArrayPush(m_scenesStack, scene);
		wyObjectRetain(scene);
		setNextScene(scene);
	}
}

void wyDirector::replaceScene(wyScene* scene) {
	if(m_nextScene) {
		LOGW("wyDirector::replaceScene: next scene is already set, you call replaceScene multiple times?");
	} else if(scene != NULL) {
		wyObjectRelease((wyObject*)wyArrayPop(m_scenesStack));
		wyArrayPush(m_scenesStack, scene);
		wyObjectRetain(scene);
		setNextScene(scene);
	}
}

void wyDirector::setRunningScene(wyScene* scene) {
	wyObjectRetain(scene);
	wyObjectRelease(m_runningScene);
	m_runningScene = scene;
}

void wyDirector::setNextScene(wyScene* scene) {
	wyObjectRetain(scene);
	wyObjectRelease(m_nextScene);
	m_nextScene = scene;
}

void wyDirector::gotoNextScene() {
	// check scene type, will do something special if in transition
	bool runningIsTransition = m_runningScene != NULL && m_runningScene->isTransition();
	bool newIsTransition = m_nextScene != NULL && m_nextScene->isTransition();

	// If it is not a transition, call onExit
	if(m_runningScene != NULL && !newIsTransition)
		m_runningScene->onExit();

	// set running scene
	setRunningScene(m_nextScene);
	setNextScene(NULL);

	// if not in transition, enter now
	if(!runningIsTransition) {
		m_runningScene->onEnter();
		m_runningScene->onEnterTransitionDidFinish();
	}
}

wyScene* wyDirector::getPreviousScene() {
	int c = m_scenesStack->num;
	if(c > 1)
		return (wyScene*)wyArrayGet(m_scenesStack, c - 2);
	else
		return NULL;
}

bool wyDirector::isExtensionSupported(const char* name) {
	const char* extensions = (const char*)glGetString(GL_EXTENSIONS);
	return extensions == NULL ? false : (strstr(extensions, name) != NULL);
}

void wyDirector::makeScreenshot(const char* path) {
	if(path != NULL) {
		if(m_screenshotPath != NULL) {
			wyFree((void*)m_screenshotPath);
			m_screenshotPath = NULL;
		}
		m_makeScreenshot = true;
		m_screenshotPath = wyUtils::copy(path);
	}
	m_screenshotRect = wyr(0, 0, wyDevice::realWidth, wyDevice::realHeight);
}

void wyDirector::makeScreenshot(const char* path, wyRect rect) {
	makeScreenshot(path);
	m_screenshotRect = rect;

	// if base size mode, need scale rect
	if(wyDevice::scaleMode == SCALE_MODE_BASE_SIZE_FIT_XY) {
		m_screenshotRect.x *= wyDevice::baseScaleX;
		m_screenshotRect.y *= wyDevice::baseScaleY;
		m_screenshotRect.width *= wyDevice::baseScaleX;
		m_screenshotRect.height *= wyDevice::baseScaleY;
	}
}

void wyDirector::makeScreenshot(const char* path, wyNode* node) {
	makeScreenshot(path);
	m_screenshotRect = node->getBoundingBoxRelativeToWorld();

	// if base size mode, need scale rect
	if(wyDevice::scaleMode == SCALE_MODE_BASE_SIZE_FIT_XY) {
		m_screenshotRect.x *= wyDevice::baseScaleX;
		m_screenshotRect.y *= wyDevice::baseScaleY;
		m_screenshotRect.width *= wyDevice::baseScaleX;
		m_screenshotRect.height *= wyDevice::baseScaleY;
	}
}

void wyDirector::setScaleMode(wyScaleMode mode) {
	wyDevice::scaleMode = mode;
}

void wyDirector::setBaseSize(int w, int h) {
	wyDevice::winWidth = w;
	wyDevice::winHeight = h;
}

void wyDirector::changeBaseSize(int w, int h) {
	wyDevice::scaleMode = SCALE_MODE_BASE_SIZE_FIT_XY;
	wyDevice::winWidth = w;
	wyDevice::winHeight = h;

	wyDevice::baseScaleX = (float)wyDevice::realWidth / wyDevice::winWidth;
	wyDevice::baseScaleY = (float)wyDevice::realHeight / wyDevice::winHeight;
	wyDevice::defaultInDensity = wyDevice::density;

	setDefaultProjection();
}

void wyDirector::pushClipRect(wyRect& rect) {
	// ensure capacity
	while(m_clipStackCount >= m_clipStackCapacity) {
		m_clipStackCapacity *= 2;
		m_clipStack = (wyRect*)wyRealloc(m_clipStack, m_clipStackCapacity * sizeof(wyRect));
	}

	// enable scissor if this is first clip rect
	if(m_clipStackCount == 0) {
		glEnable(GL_SCISSOR_TEST);
	}

	// push clip rect
	m_clipStack[m_clipStackCount++] = rect;

	// enable rect
	glScissor(rect.x, rect.y, rect.width, rect.height);
}

void wyDirector::popClipRect() {
	// check count
	if(m_clipStackCount <= 0)
		return;

	// decrease count
	m_clipStackCount--;

	// if this is last clip rect
	if(m_clipStackCount == 0) {
		glDisable(GL_SCISSOR_TEST);
	} else {
		// enable previous rect
		glScissor(m_clipStack[m_clipStackCount - 1].x,
				m_clipStack[m_clipStackCount - 1].y,
				m_clipStack[m_clipStackCount - 1].width,
				m_clipStack[m_clipStackCount - 1].height);
	}
}
