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
#include "wyAutoReleasePool.h"
#include "wyTargetSelector.h"

extern JavaVM* gVM;
extern wyDirector_android* gDirector;
extern wyEventDispatcher_android* gEventDispatcher;
extern bool g_Director_isEnding;

#ifdef __cplusplus
extern "C" {
#endif

extern void globalInit(JNIEnv* env);

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

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_resume
  (JNIEnv * env, jobject thiz) {
	gDirector->resume();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_attachInView
  (JNIEnv * env, jobject thiz, jobject glView) {
	gDirector->attachInView(glView);
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

JNIEXPORT jobject JNICALL Java_com_wiyun_engine_nodes_Director_getOpenGLView
  (JNIEnv * env, jobject thiz) {
	return gDirector->getGLView();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_invokeNativeTargetSelector
  (JNIEnv * env, jclass clazz, jint pointer) {
	if(pointer) {
		wyTargetSelector* ts = (wyTargetSelector*)pointer;
		ts->invoke();
		ts->release();
	}
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Director_isEnding
  (JNIEnv * env, jclass clazz) {
	return g_Director_isEnding;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_runOnGLThread
  (JNIEnv * env, jobject thiz, jobject runnable) {
	if(gEventDispatcher)
		gEventDispatcher->queueRunnableLocked(runnable);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Director_drainAutoReleasePool
  (JNIEnv * env, jobject thiz) {
	wyAutoReleasePool::drainCurrent();
}

#ifdef __cplusplus
}
#endif

#endif // #if ANDROID
