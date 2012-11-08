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
#include "wyGLES2Renderer.h"
#include "wyShaderManager.h"
#include "wyRenderManager.h"
#include "wyViewport.h"
#include "wyLabel.h"
#include "wyScene.h"
#include "wyTransitionScene.h"
#include "wyMath.h"

/// global director instance
extern wyDirector* gDirector;

/// director是否正在销毁的标志
bool g_Director_isEnding;

/// global resource decoder
extern wyResourceDecoder* gResDecoder;

// 只要不重新install apk, 这个index一直增加，因此可以录制多个连起来
#ifdef WY_CFLAG_SCREENSHOT_MODE
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
extern wyShaderManager* gShaderManager;

#ifdef __cplusplus
extern "C" {
#endif

// extern methods
extern void wyInitAutoReleasePool();
extern void wyClearAutoReleasePool();
extern void wyDestroyAutoReleasePool();

#ifdef WY_CFLAG_MEMORY_TRACKING
extern void wyOutputLeakPool();
extern void wyClearLeakPool();
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

wyDirector* wyDirector::getInstanceNoCreate() {
	return gDirector;
}

void wyDirector::printUnreleasedObjects() {
#ifdef WY_CFLAG_MEMORY_TRACKING
	wyOutputLeakPool();
#else
	LOGW("This method is only available when WY_CFLAG_MEMORY_TRACKING flag is on (in wyBuildConfig.h)");
#endif
}

void wyDirector::printUnreleasedMemory(bool fullLog) {
#ifdef WY_CFLAG_MEMORY_TRACKING
	wyMemoryDumpRecord(fullLog);
#else
	LOGW("This method is only available when WY_CFLAG_MEMORY_TRACKING flag is on (in wyBuildConfig.h)");
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
		m_lifecycleListeners(WYNEW vector<wyDirectorLifecycleListener*>()),
		m_glView(NULL),
		m_context(NULL),
		m_lifecycleData(NULL),
		m_renderManager(NULL),
		m_mainViewport(NULL) {
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
	int size = m_lifecycleListeners->size();
	for(int i = 0; i < size; i++) {
		wyDirectorLifecycleListener* l = m_lifecycleListeners->at(i);
		if(l->onSurfaceCreated != NULL)
			l->onSurfaceCreated(m_lifecycleData);
	}
}

void wyDirector::notifySurfaceChanged() {
	int size = m_lifecycleListeners->size();
	for(int i = 0; i < size; i++) {
		wyDirectorLifecycleListener* l = m_lifecycleListeners->at(i);
		if(l->onSurfaceChanged != NULL)
			l->onSurfaceChanged(wyDevice::winWidth, wyDevice::winHeight, m_lifecycleData);
	}
}

void wyDirector::notifySurfaceDestroyed() {
	int size = m_lifecycleListeners->size();
	for(int i = 0; i < size; i++) {
		wyDirectorLifecycleListener* l = m_lifecycleListeners->at(i);
		if(l->onSurfaceDestroyed != NULL)
			l->onSurfaceDestroyed(m_lifecycleData);
	}
}

void wyDirector::notifyDirectorPaused() {
	int size = m_lifecycleListeners->size();
	for(int i = 0; i < size; i++) {
		wyDirectorLifecycleListener* l = m_lifecycleListeners->at(i);
		if(l->onDirectorPaused != NULL)
			l->onDirectorPaused(m_lifecycleData);
	}
}

void wyDirector::notifyDirectorResumed() {
	int size = m_lifecycleListeners->size();
	for(int i = 0; i < size; i++) {
		wyDirectorLifecycleListener* l = m_lifecycleListeners->at(i);
		if(l->onDirectorResumed != NULL)
			l->onDirectorResumed(m_lifecycleData);
	}
}

void wyDirector::notifyDirectorEnded() {
	int size = m_lifecycleListeners->size();
	for(int i = 0; i < size; i++) {
		wyDirectorLifecycleListener* l = m_lifecycleListeners->at(i);
		if(l->onDirectorEnded != NULL)
			l->onDirectorEnded(m_lifecycleData);
	}
}

void wyDirector::notifyDirectorScreenCaptured() {
	int size = m_lifecycleListeners->size();
	for(int i = 0; i < size; i++) {
		wyDirectorLifecycleListener* l = m_lifecycleListeners->at(i);
		if(l->onDirectorScreenCaptured != NULL)
			l->onDirectorScreenCaptured(m_screenshotPath, m_lifecycleData);
	}
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
	m_fpsLabel->setText(buf);
}

void wyDirector::setShowFPS(bool show) {
	m_displayFPS = show;
	if(m_displayFPS)
		m_calculateFPS = m_displayFPS;
}

void wyDirector::onSurfaceCreated() {
	/*
	 * surface created but we still get surface create callback?
	 * ok, we assume a surface destroy is leaked and it will happen when user locks
	 * screen in Android, so we manually invoke surface destroy callback
	 */
	if(m_surfaceCreated) {
		onSurfaceDestroyed();
	}

	// set flag
	m_surfaceCreated = true;

	// get GL thread id
	tagGLThread();

	// 返回OpenGL支持的最大贴图尺寸,设置到wyDevice::maxTextureSize
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &wyDevice::maxTextureSize);

	// enable event
	gEventDispatcher->setDispatchEvent(true);

	// create shader manager so that built-in shader will be loaded
	wyShaderManager::getInstance();

	// create render manager and main viewport
	if(!m_renderManager) {
		// create render manager with opengl es 2.0 implementation
		m_renderManager = wyRenderManager::make(wyGLES2Renderer::make());
		m_renderManager->retain();

		// create main view port
		wyCamera* cam = wyCamera::make();
		cam->setPerspective(60, 1, 1, 0.5f, 1500.0f);
		cam->setEye(0.5f, 0.5f, 1 / GOLDEN_MEAN);
		cam->setCenter(0.5f, 0.5f, 0);
		cam->setUp(0, 1, 0);
		cam->setUseRelativeValue(true);
		m_mainViewport = wyViewport::make("main", cam);
		m_mainViewport->setClearFlag(true, true, true);
		m_renderManager->addViewport(m_mainViewport);

		// if running scene is not NULL, attach it to viewport now
		if(m_runningScene)
			m_mainViewport->attachRoot(m_runningScene);
	}

	// notify render about surface created
	m_renderManager->getRenderer()->onSurfaceCreated();

	// notify listener
	notifySurfaceCreated();
}

void wyDirector::onSurfaceChanged(int w, int h) {
	// surface not created?
	if(!m_surfaceCreated)
		return;

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

	/*
	 * create fps label
	 * however, we don't create it if in memory debug mode because fps
	 * label changes constantly and it will print lots of malloc messages
	 */
	if(!m_fpsLabel && m_displayFPS) {
		// create fps label and make it in GUI bucket
	    m_fpsLabel = wyLabel::make("00.0", SP(24));
	    m_fpsLabel->retain();
	    m_fpsLabel->setAnchor(0, 0);
	    m_fpsLabel->setQueueBucket(wyRenderQueue::GUI_BUCKET);

	    // create fps viewport
		wyCamera* cam = wyCamera::make();
		cam->setOrtho(0, 1, 0, 1, -1024, 1024);
		wyViewport* fpsViewport = wyViewport::make("fps", cam);
		m_renderManager->addPostViewport(fpsViewport);

		// attach fps label to viewport
		fpsViewport->attachRoot(m_fpsLabel);
	}

	/*
	 * Here, we only set check texture flag when there is a running scene, that
	 * is to avoid the flag is set during first start
	 */
	if(m_runningScene)
		setNeedCheckTexture(true);

	// ensure we don't have a frame loss when returns
	m_nextDeltaTimeZero = true;

	// notify listener
	notifySurfaceChanged();
}

void wyDirector::onSurfaceDestroyed() {
	if(m_surfaceCreated) {
		m_surfaceCreated = false;
		setNeedCheckTexture(true);

		// release shader manager because surface is destroy, shader should also be invalid
		wyObjectRelease(gShaderManager);

		// reset render
		m_renderManager->getRenderer()->onSurfaceDestroyed();

		// notify listener
		notifySurfaceDestroyed();
	}
}

void wyDirector::addLifecycleListener(wyDirectorLifecycleListener* l, void* data) {
	m_lifecycleListeners->push_back(l);
	m_lifecycleData = data;
}

void wyDirector::drawFrame() {
	// process auto release pool
	wyClearAutoReleasePool();

	// check frame rate setting, but neglect it if in screenshot mode
#ifndef WY_CFLAG_SCREENSHOT_MODE
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
#ifdef WY_CFLAG_SCREENSHOT_MODE
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
		// render frame
		m_renderManager->render(m_delta);

		/*
		 * can't move action tick before visit running scene. sometimes the internal
		 * state may not consistent because scheduler already updated before visit.
		 * an example is: move a particle system with an action, can see particle system
		 * shaked consistently.
		 */
        if(!m_UIPaused)
        	gActionManager->tick(m_delta * m_tickFactor);

#ifndef WY_CFLAG_SCREENSHOT_MODE
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
#endif // #ifndef WY_CFLAG_SCREENSHOT_MODE
	}

	// make screenshot
#ifdef WY_CFLAG_SCREENSHOT_MODE
    char fsPath[128];
    sprintf(fsPath, "/sdcard/WiEngine/%06d.png", sScreenshotFrameIndex++);
    const char* path = wyUtils::mapLocalPath(fsPath);
	wyUtils::makeScreenshot(path);
	wyFree((void*)path);
#endif // #ifdef WY_CFLAG_SCREENSHOT_MODE

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

	// release matrix stack
	kmGLFreeAll();

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
	WYDELETE(m_lifecycleListeners);

	// release render manager
	wyObjectRelease(m_renderManager);

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

	// free mutex
	pthread_mutex_destroy(&gMutex);
	pthread_mutex_destroy(&gCondMutex);
	
	// check leak
#ifdef WY_CFLAG_MEMORY_TRACKING
	wyOutputLeakPool();
	wyClearLeakPool();

	printUnreleasedMemory(true);
#endif
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

	// attach to main view port
	if(m_mainViewport)
		m_mainViewport->attachRoot(m_runningScene);
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
	LOGD("%s", extensions);
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

	m_mainViewport->getCamera()->setDirty(true);
}
