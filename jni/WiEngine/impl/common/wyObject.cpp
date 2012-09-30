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
#include "wyObject.h"
#include <stdlib.h>
#include "wyHashSet.h"
#include "wyLog.h"
#include <pthread.h>
#include "wyTargetSelector.h"
#include <typeinfo>
#include "wyTextureManager.h"
#include "wyEventDispatcher.h"
#include "wyAutoReleasePool.h"
#include "wyUtils.h"
#include <string>

using namespace std;

extern pthread_mutex_t gMutex;

#if ANDROID
	#include "wyUtils_android.h"
	extern jmethodID g_mid_BaseWYObject_onTargetSelectorInvoked;
#endif

// for tracing retain/release
#define RETAIN_TRACE false
#define RELEASE_TRACE false
#define DESTROY_TRACE false

// release pools
static wyArray* sAutoReleasePool = NULL;
static wyArray* sLazyReleasePool = NULL;

// comment following line when leak tracing is not needed
#define LEAK_TRACE
#ifdef LEAK_TRACE
static wyArray* sLeakPool = NULL;
#endif

wyObject::wyObject() : 
        m_retainCount(1),
#if ANDROID
        m_jTSConnector(NULL),
#endif
        m_name(NULL) {
#ifdef LEAK_TRACE
	if(sLeakPool != NULL)
		wyArrayPush(sLeakPool, this);
#endif
}

wyObject::~wyObject() {
	if(DESTROY_TRACE) {
		const char* name = getClassName();
		if(name != NULL)
			LOGD("Destroyed: %s, %d", name, this);
	}

#ifdef LEAK_TRACE
	if(sLeakPool != NULL)
		wyArrayDeleteObj(sLeakPool, this, NULL, NULL);
#endif

#if ANDROID
	if(m_jTSConnector) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->DeleteGlobalRef(m_jTSConnector);
		m_jTSConnector = NULL;
	}
#endif

    if(m_name)
        wyFree((void*)m_name);
}

const char* wyObject::getClassName() {
	char* name = (char*)typeid(*this).name();
	while('0' <= *name && *name <= '9')
		name++;
	return (const char*)name;
}

wyObject* wyObject::retain() {
	m_retainCount++;

	if(RETAIN_TRACE) {
		const char* name = getClassName();
		if(name != NULL)
			LOGD("Retained: %s, %d, %d", name, this, m_retainCount);
	}

	return this;
}

void wyObject::javaRelease() {
	// we need find the object in lazy release pool, if found, decrease retain count
	int index = wyArrayIndexOf(sLazyReleasePool, this, NULL, NULL);
	if(index != -1) {
		wyArrayDeleteIndex(sLazyReleasePool, index);
		autoRelease();
	}
}

void wyObject::release() {
	if(m_retainCount <= 0)
		return;

	m_retainCount--;

	if(RELEASE_TRACE) {
		const char* name = getClassName();
		if(name != NULL)
			LOGD("Released: %s, %d, %d", name, this, m_retainCount);
	}

	if(m_retainCount <= 0)
		WYDELETE(this);
}

wyObject* wyObject::lazyRelease() {
	if(sLazyReleasePool != NULL) {
		wyArrayPush(sLazyReleasePool, this);
	}
	return this;
}

wyObject* wyObject::autoRelease() {
	if(isGLThread()) {
		if(sAutoReleasePool != NULL)
			wyArrayPush(sAutoReleasePool, this);
	} else {
		wyAutoReleasePool::addToPool(this);
	}
	return this;
}

int wyObject::getRetainCount() {
	return m_retainCount;
}

void wyObject::onTargetSelectorInvoked(wyTargetSelector* ts) {
#if ANDROID
	if(m_jTSConnector) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jTSConnector, g_mid_BaseWYObject_onTargetSelectorInvoked, ts->getId(), ts->getDelta());
	}
#endif
}

void wyObject::setName(const char* name) {
	if(m_name)
		wyFree((void*)m_name);

    m_name = wyUtils::copy(name);
}

#if ANDROID

void wyObject::setJavaTSConnector(jobject c) {
	JNIEnv* env = wyUtils::getJNIEnv();
	if(m_jTSConnector) {
		env->DeleteGlobalRef(m_jTSConnector);
		m_jTSConnector = NULL;
	}

	if(c) {
		m_jTSConnector = env->NewGlobalRef(c);
	}
}

#endif // #if ANDROID

#ifdef __cplusplus
extern "C" {
#endif

wyObject* wyObjectRetain(wyObject* obj) {
	if(obj == NULL)
		return NULL;

	obj->retain();
	return obj;
}

wyObject* wyObjectAutoRelease(wyObject* obj) {
	if(obj == NULL)
		return NULL;

	obj->autoRelease();
	return obj;
}

wyObject* wyObjectLazyRelease(wyObject* obj) {
	if(obj == NULL)
		return NULL;

	obj->lazyRelease();
	return obj;
}

void wyObjectRelease(wyObject* obj) {
	if(obj != NULL) {
		obj->release();
	}
}

static bool releaseObject(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

#ifdef LEAK_TRACE
static bool outputLeak(wyArray* arr, void* ptr, int index, void* data) {
	wyObject* obj = (wyObject*)ptr;
	LOGD("unreleased object: %s, addr: %x, retain count: %d", obj->getClassName(), obj, obj->getRetainCount());
	return true;
}
#endif

void wyInitAutoReleasePool() {
	if(sAutoReleasePool == NULL) {
		sAutoReleasePool = wyArrayNew(100);
	}
	if(sLazyReleasePool == NULL) {
		sLazyReleasePool = wyArrayNew(100);
	}

	// for tracing leak
#ifdef LEAK_TRACE
	if(sLeakPool == NULL) {
		sLeakPool = wyArrayNew(100);
	}
#endif
}

void wyClearLazyReleasePool() {
	if(sLazyReleasePool != NULL && sLazyReleasePool->num > 0) {
		// clear pool
		wyArrayEach(sLazyReleasePool, releaseObject, NULL);
		wyArrayClear(sLazyReleasePool);
	}
}

void wyClearAutoReleasePool() {
	if(sAutoReleasePool != NULL && sAutoReleasePool->num > 0) {
		// clear pool
		wyArrayEach(sAutoReleasePool, releaseObject, NULL);
		wyArrayClear(sAutoReleasePool);
	}
}

void wyDestroyAutoReleasePool() {
	if(sAutoReleasePool != NULL) {
		// clear auto release pool
		wyArrayEach(sAutoReleasePool, releaseObject, NULL);
		wyArrayClear(sAutoReleasePool);
		wyArrayDestroy(sAutoReleasePool);
		sAutoReleasePool = NULL;
	}
	wyClearLazyReleasePool();
}

void wyOutputLeakPool() {
#ifdef LEAK_TRACE
	if(sLeakPool != NULL) {
		if(sLeakPool->num > 0)
			LOGD("leak pool count: %d", sLeakPool->num);
		wyArrayEach(sLeakPool, outputLeak, NULL);
	}
#endif
}

void wyClearLeakPool() {
#ifdef LEAK_TRACE
	if(sLeakPool != NULL) {
		wyArrayClear(sLeakPool);
		wyArrayDestroy(sLeakPool);
		sLeakPool = NULL;
	}
#endif
}

void wyOutputLazyPool() {
	LOGD("+++ objects still not autoreleased +++");
	for(int i = 0; i < sLazyReleasePool->num; i++) {
		wyObject* obj = (wyObject*)wyArrayGet(sLazyReleasePool, i);
		LOGD("%s", obj->getClassName());
	}
	LOGD("--- objects still not autoreleased ---");
}

#ifdef __cplusplus
}
#endif
