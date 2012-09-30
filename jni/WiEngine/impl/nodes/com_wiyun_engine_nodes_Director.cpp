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
#if ANDROID

#include "com_wiyun_engine_nodes_Director.h"
#include "wyInit.h"
#include "wyDirector_android.h"
#include "wyGlobal.h"
#include "wyEventDispatcher_android.h"
#include "wyLog.h"
#include "wyUtils_android.h"
#include "wyJavaResourceDecoder.h"
#include "wyAutoReleasePool.h"

extern JavaVM* gVM;
extern wyDirector_android* gDirector;
extern wyEventDispatcher_android* gEventDispatcher;
extern bool g_Director_isEnding;
extern jfieldID g_fid_BaseObject_mPointer;
extern wyResourceDecoder* gResDecoder;

#ifdef __cplusplus
extern "C" {
#endif

extern void globalInit(JNIEnv* env);
extern void wyOutputLazyPool();

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyDirector::getInstance();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_nativeDestroy
	(JNIEnv * env, jobject thiz) {
	wyObjectRelease(gDirector);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_nativeOnSurfaceCreated
  (JNIEnv * env, jobject thiz) {
	gDirector->onSurfaceCreated();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_nativeOnSurfaceChanged
  (JNIEnv * env, jobject thiz, jint width, jint height) {
	gDirector->onSurfaceChanged(width, height);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_nativeOnSurfaceDestroyed
  (JNIEnv * env, jobject thiz) {
	gDirector->onSurfaceDestroyed();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_nativeOnDrawFrame
  (JNIEnv * env, jobject thiz) {
	gDirector->drawFrame();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_pause
  (JNIEnv * env, jobject thiz) {
	gDirector->pause();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Director_isUIPaused
  (JNIEnv * env, jobject thiz) {
	return gDirector->isUIPaused();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_pauseUI
  (JNIEnv * env, jobject thiz) {
	gDirector->pauseUI();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_resumeUI
  (JNIEnv * env, jobject thiz) {
	gDirector->resumeUI();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_resume
  (JNIEnv * env, jobject thiz) {
	gDirector->resume();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Director_isPaused
  (JNIEnv * env, jobject thiz) {
	return gDirector->isPaused();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_attachInView
  (JNIEnv * env, jobject thiz, jobject glView) {
	gDirector->attachInView(glView);
}

JNIEXPORT jobject JNICALL Java_com_wiyun_engine_nodes_Director_getOpenGLView
  (JNIEnv * env, jobject thiz) {
	return gDirector->getGLView();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_nativeAttachContext
  (JNIEnv * env, jobject thiz, jobject context) {
	// get java VM
	env->GetJavaVM(&gVM);

	// attach context
	gDirector->attachContext(context);
}

JNIEXPORT jobject JNICALL Java_com_wiyun_engine_nodes_Director_getContext
  (JNIEnv * env, jobject thiz) {
	return gDirector->getContext();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Director_getSurfaceWidth
  (JNIEnv * env, jobject thiz) {
	return wyDevice::winWidth;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Director_getSurfaceHeight
  (JNIEnv * env, jobject thiz) {
	return wyDevice::winHeight;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Director_getRealWidth
  (JNIEnv * env, jobject thiz) {
	return wyDevice::realWidth;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Director_getRealHeight
  (JNIEnv * env, jobject thiz) {
	return wyDevice::realHeight;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Director_getScaleMode
  (JNIEnv * env, jobject thiz) {
	return (jint)wyDevice::scaleMode;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setDefaultInDensity
  (JNIEnv * env, jclass clazz, jfloat density) {
	if(wyDevice::scaleMode == SCALE_MODE_BY_DENSITY)
		wyDevice::defaultInDensity = density;
	else
		LOGW("setDefaultInDensity: can't set default in density if scale mode is not density mode");
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Director_getDefaultInDensity
  (JNIEnv * env, jclass clazz) {
	return wyDevice::defaultInDensity;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_printUnreleasedObjects
  (JNIEnv * env, jclass clazz) {
	gDirector->printUnreleasedObjects();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_printUnreleasedMemory
(JNIEnv * env, jclass clazz, jboolean fullLog) {
	gDirector->printUnreleasedMemory(fullLog);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_printMemoryUsage
(JNIEnv * env, jclass clazz) {
	gDirector->printMemoryUsage();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_runWithScene
  (JNIEnv * env, jobject thiz, jobject scene) {
	wyScene* s = (wyScene*)env->GetIntField(scene, g_fid_BaseObject_mPointer);
	gDirector->runWithScene(s);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_pushScene
  (JNIEnv * env, jobject thiz, jobject scene) {
	wyScene* s = (wyScene*)env->GetIntField(scene, g_fid_BaseObject_mPointer);
	gDirector->pushScene(s);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_popScene
  (JNIEnv * env, jobject thiz) {
	gDirector->popScene();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_replaceScene
  (JNIEnv * env, jobject thiz, jobject scene) {
	wyScene* s = (wyScene*)env->GetIntField(scene, g_fid_BaseObject_mPointer);
	gDirector->replaceScene(s);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Director_nativeGetPreviousScene
  (JNIEnv * env, jobject thiz) {
	return (jint)gDirector->getPreviousScene();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Director_nativeGetRunningScene
  (JNIEnv * env, jobject thiz) {
	return (jint)gDirector->getRunningScene();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setAlphaBlending
  (JNIEnv * env, jobject thiz, jboolean on) {
	gDirector->setAlphaBlending(on);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Director_getMaxTextureSize
  (JNIEnv * env, jobject thiz) {
	return wyDevice::maxTextureSize;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Director_getProjection
  (JNIEnv * env, jobject thiz) {
	return gDirector->getProjection();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setProjection
  (JNIEnv * env, jobject thiz, jint projection) {
	gDirector->setProjection((wyProjectionType)projection);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setDepthTest
  (JNIEnv * env, jobject thiz, jboolean on) {
	gDirector->setDepthTest(on);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_set2DProjection
  (JNIEnv * env, jobject thiz) {
	gDirector->set2DProjection();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_set3DProjection
  (JNIEnv * env, jobject thiz) {
	gDirector->set3DProjection();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setCullFace
  (JNIEnv * env, jobject thiz, jboolean on) {
	gDirector->setCullFace(on);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setDisplayFPS
  (JNIEnv * env, jobject thiz, jboolean displayFPS) {
	gDirector->setShowFPS(displayFPS);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setCalculateFPS
(JNIEnv * env, jobject thiz, jboolean flag) {
	gDirector->setCalculateFPS(flag);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Director_getMaxFrameRate
  (JNIEnv * env, jobject thiz) {
	return gDirector->getMaxFrameRate();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setMaxFrameRate
  (JNIEnv * env, jobject thiz, jint maxFrameRate) {
	gDirector->setMaxFrameRate(maxFrameRate);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_addLifecycleListener
  (JNIEnv * env, jobject thiz, jobject listener) {
	gDirector->addLifecycleListener(listener);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Director_isExtensionSupported
  (JNIEnv * env, jobject thiz, jstring ext) {
	const char* extension = (const char*)env->GetStringUTFChars(ext, NULL);
	bool ret = gDirector->isExtensionSupported(extension);
	env->ReleaseStringUTFChars(ext, extension);
	return ret;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_makeScreenshot__Ljava_lang_String_2
  (JNIEnv * env, jobject thiz, jstring path) {
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	gDirector->makeScreenshot(p);
	env->ReleaseStringUTFChars(path, p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_makeScreenshot__Ljava_lang_String_2Lcom_wiyun_engine_types_WYRect_2
  (JNIEnv * env, jobject thiz, jstring path, jobject rect) {
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	gDirector->makeScreenshot(p, wyUtils_android::to_wyRect( rect));
	env->ReleaseStringUTFChars(path, p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_makeScreenshot__Ljava_lang_String_2Lcom_wiyun_engine_nodes_Node_2
  (JNIEnv * env, jobject thiz, jstring path, jobject node) {
	wyNode* n = (wyNode*)env->GetIntField(node, g_fid_BaseObject_mPointer);
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	gDirector->makeScreenshot(p, n);
	env->ReleaseStringUTFChars(path, p);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Director_isEnding
  (JNIEnv * env, jclass clazz) {
	return g_Director_isEnding;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Director_getCurrentFrameRate
  (JNIEnv * env, jobject thiz) {
	return gDirector->getCurrentFrameRate();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setFocusEnabled
  (JNIEnv * env, jobject thiz, jboolean flag) {
	gDirector->setFocusEnabled(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Director_isFocusEnabled
  (JNIEnv * env, jobject thiz) {
	return gDirector->isFocusEnabled();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setNextDeltaTimeZero
  (JNIEnv * env, jobject thiz, jboolean flag) {
	gDirector->setNextDeltaTimeZero(flag);
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_nodes_Director_getVersion
  (JNIEnv * env, jclass clazz) {
	return env->NewStringUTF(WIENGINE_VERSION);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_popSceneWithTransition
  (JNIEnv * env, jobject thiz, jobject trans) {
	wyTransitionScene* t = (wyTransitionScene*)env->GetIntField(trans, g_fid_BaseObject_mPointer);
	gDirector->popSceneWithTransition(t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setAllowBackgroundRunning
  (JNIEnv * env, jobject thiz, jboolean flag) {
	gDirector->setAllowBackgroundRunning(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Director_isAllowBackgroundRunning
  (JNIEnv * env, jobject thiz) {
	return gDirector->isAllowBackgroundRunning();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setScaleMode
  (JNIEnv * env, jobject thiz, jint mode) {
	gDirector->setScaleMode((wyScaleMode)mode);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setBaseSize
  (JNIEnv * env, jobject thiz, jint w, jint h) {
	gDirector->setBaseSize(w, h);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_changeBaseSize
  (JNIEnv * env, jobject thiz, jint w, jint h) {
	gDirector->changeBaseSize(w, h);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_runOnGLThread
  (JNIEnv * env, jobject thiz, jobject runnable) {
	if(gEventDispatcher)
		gEventDispatcher->queueRunnableLocked(runnable);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_invokeNativeTargetSelector
  (JNIEnv * env, jclass clazz, jint pointer) {
	if(pointer) {
		wyTargetSelector* ts = (wyTargetSelector*)pointer;
		ts->invoke();
		ts->release();
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setResourceDecoder
  (JNIEnv * env, jclass clazz, jobject decoder) {
	wyJavaResourceDecoder* wrapper = wyJavaResourceDecoder::make(decoder);
	wyDirector::setResourceDecoder(wrapper);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setResourceDecoderFlags
  (JNIEnv * env, jclass clazz, jint flags) {
	if(gResDecoder)
		gResDecoder->setFlags(flags);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_drainAutoReleasePool
  (JNIEnv * env, jobject thiz) {
	wyAutoReleasePool::drainCurrent();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_setTickFactor
  (JNIEnv * env, jobject thiz, jfloat r) {
	gDirector->setTickFactor(r);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Director_getTickFactor
  (JNIEnv * env, jobject thiz) {
	return gDirector->getTickFactor();
}

#ifdef __cplusplus
}
#endif

#endif // #if ANDROID
