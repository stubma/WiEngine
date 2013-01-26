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

#include "wyEventDispatcher_android.h"
#include "wyJNI.h"
#include "wyLog.h"
#include "wyRunnable.h"
#include "wyNode.h"

// shared instance
wyEventDispatcher_android* gEventDispatcher;

// mutex
extern pthread_mutex_t gMutex;

// preload class
extern jclass gClass_Accelerometer;

// for java method callback
extern jmethodID g_mid_Accelerometer_getInstance;
extern jmethodID g_mid_Accelerometer_checkAccelHandlers;

// for java side event handler
extern jmethodID g_mid_Runnable_run;

wyEventDispatcher* wyEventDispatcher::getInstance() {
	if(gEventDispatcher == NULL) {
		gEventDispatcher = WYNEW wyEventDispatcher_android();
	}
	return gEventDispatcher;
}

wyEventDispatcher* wyEventDispatcher::getInstanceNoCreate() {
	return gEventDispatcher;
}

void wyEventDispatcher::recycleEvent(wyEvent* e) {
	switch(e->type) {
		case ET_TOUCH_BEGAN:
		case ET_TOUCH_MOVED:
		case ET_TOUCH_ENDED:
		case ET_TOUCH_CANCELLED:
		case ET_TOUCH_POINTER_BEGAN:
		case ET_TOUCH_POINTER_END:
		case ET_DOUBLE_TAP:
		case ET_DOUBLE_TAP_EVENT:
		case ET_SINGLE_TAP_CONFIRMED:
			if(e->me.pe != NULL) {
				JNIEnv* env = getEnv();
				env->DeleteGlobalRef(e->me.pe);
				e->me.pe = NULL;
			}
			break;
		case ET_KEY_DOWN:
		case ET_KEY_UP:
		case ET_KEY_MULTIPLE:
			if(e->ke.pe != NULL) {
				JNIEnv* env = getEnv();
				env->DeleteGlobalRef(e->ke.pe);
				e->ke.pe = NULL;
			}
			break;
		case ET_ON_DOWN:
		case ET_ON_FLING:
		case ET_ON_SCROLL:
		case ET_ON_SINGLE_TAP_UP:
		case ET_ON_LONG_PRESS:
		case ET_ON_SHOW_PRESS:
			if(e->ge.pe1 != NULL) {
				JNIEnv* env = getEnv();
				env->DeleteGlobalRef(e->ge.pe1);
				e->ge.pe1 = NULL;
			}
			if(e->ge.pe2 != NULL) {
				JNIEnv* env = getEnv();
				env->DeleteGlobalRef(e->ge.pe2);
				e->ge.pe2 = NULL;
			}
			break;
		case ET_RUNNABLE:
			wyObjectRelease(e->r.runnable);
			e->r.runnable = NULL;
			break;
		case ET_JAVA_RUNNABLE:
		{
			JNIEnv* env = getEnv();
			if (e->jr.runnable != NULL) {
				env->DeleteGlobalRef(e->jr.runnable);
				e->jr.runnable = NULL;
			}
			break;
		}
	}
}

wyEventDispatcher_android::wyEventDispatcher_android() {
}

wyEventDispatcher_android::~wyEventDispatcher_android() {
	gEventDispatcher = NULL;
}

void wyEventDispatcher_android::queueRunnableLocked(jobject runnable) {
	if(isGLThread()) {
		JNIEnv* env = getEnv();
		env->CallVoidMethod(runnable, g_mid_Runnable_run);
	} else {
		pthread_mutex_lock(&gMutex);

		JNIEnv* env = getEnv();
		wyEvent* e = popEvent();
		e->type = ET_JAVA_RUNNABLE;
		e->jr.runnable = env->NewGlobalRef(runnable);
		m_pendingAddEvents.push_back(e);

		pthread_mutex_unlock(&gMutex);
	}
}

void wyEventDispatcher_android::checkAccelHandlers() {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	jobject d = env->CallStaticObjectMethod(gClass_Accelerometer, g_mid_Accelerometer_getInstance);
	env->CallVoidMethod(d, g_mid_Accelerometer_checkAccelHandlers);
	env->DeleteLocalRef(d);
}

void wyEventDispatcher_android::checkDoubleTapHandlers() {
}

void wyEventDispatcher_android::checkGestureHandlers() {
}

wyEvent* wyEventDispatcher_android::buildKeyEvent(wyEventType type, wyPlatformKeyEvent pe) {
	// get pooled event
	JNIEnv* env = getEnv();
	wyEvent* e = popEvent();
	e->type = type;
	e->ke.pe = env->NewGlobalRef(pe);
	return e;
}

void wyEventDispatcher_android::queueMotionEvent(wyEventType type, wyPlatformMotionEvent pe) {
	JNIEnv* env = getEnv();
	wyEvent* e = popEvent();
	e->type = type;
	e->me.pe = env->NewGlobalRef(pe);
	m_pendingAddEvents.push_back(e);
}

void wyEventDispatcher_android::queueMotionEvent(wyEventType type, wyPlatformMotionEvent pe1, wyPlatformMotionEvent pe2, float vx, float vy) {
	wyEvent* e = popEvent();
	e->type = type;
	e->ge.vx = vx;
	e->ge.vy = vy;
	JNIEnv* env = getEnv();
	e->ge.pe1 = pe1 == NULL ? NULL : env->NewGlobalRef(pe1);
	e->ge.pe2 = pe2 == NULL ? NULL : env->NewGlobalRef(pe2);

	m_pendingAddEvents.push_back(e);
}

void wyEventDispatcher_android::processUncommonEvent(wyEvent* e) {
	switch(e->type) {
		case ET_JAVA_RUNNABLE:
		{
			JNIEnv* env = getEnv();
			env->CallVoidMethod(e->jr.runnable, g_mid_Runnable_run);
			break;
		}
	}
}

#endif // #if ANDROID
