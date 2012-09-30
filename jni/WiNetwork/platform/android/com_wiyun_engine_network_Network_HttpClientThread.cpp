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

#include <jni.h>
#include "wyHttpRequest.h"
#include "wyHttpListener.h"
#include "wyHttpResponse_android.h"
#include "wyLog.h"
#include "wyNotifyOnReceiveHttpResponseRunnable.h"
#include "wyNotifyOnHttpFinishLoadingRunnable.h"
#include "wyNotifyOnHttpLoadingFailedRunnable.h"
#include "wyNotifyOnHttpReceiveDataRunnable.h"
#include "wyEventDispatcher.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_com_wiyun_engine_network_Network_00024HttpClientThread_releaseResponse
  (JNIEnv * env, jobject thiz, jint responsePointer) {
	wyHttpResponse* r = (wyHttpResponse*)responsePointer;
	wyObjectRelease(r);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_network_Network_00024HttpClientThread_createHttpResponse
  (JNIEnv * env, jobject thiz) {
	wyHttpResponse_android* r = wyHttpResponse_android::make(NULL);
	r->retain();
	return (jint)r;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_network_Network_00024HttpClientThread_notifyOnHttpReceiveResponse
  (JNIEnv * env, jobject thiz, jobject response, jint requestPointer, jint listenerPointer) {
	// must retain response because it should be hold before request done
	wyHttpResponse_android* r = wyHttpResponse_android::make(response);
	r->retain();

	// must release request because it hold self when start to request
	wyHttpRequest* req = (wyHttpRequest*)requestPointer;
	r->setRequest(req);
	wyObjectRelease(req);

	// notify listener
	if(listenerPointer && !req->isCancelled()) {
		wyEventDispatcher* d = wyEventDispatcher::getInstanceNoCreate();
		if(d) {
			wyNotifyOnReceiveHttpResponseRunnable* n = wyNotifyOnReceiveHttpResponseRunnable::make(r, (wyHttpListener*)listenerPointer);
			d->queueRunnableLocked(n);
		}
	}

	return (jint)r;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_network_Network_00024HttpClientThread_notifyOnHttpReceiveData
  (JNIEnv * env, jobject thiz, jint responsePointer, jint listenerPointer) {
	wyHttpResponse_android* r = (wyHttpResponse_android*)responsePointer;
	ssize_t ret = r->read(8192);
	if(ret > 0) {
		if(listenerPointer && !r->getRequest()->isCancelled()) {
			wyEventDispatcher* d = wyEventDispatcher::getInstanceNoCreate();
			if(d) {
				wyNotifyOnHttpReceiveDataRunnable* n = wyNotifyOnHttpReceiveDataRunnable::make(r, (wyHttpListener*)listenerPointer, r->getBody(), r->getBodyLength());
				d->queueRunnableLocked(n);
			}
		}
	}

	return (jint)ret;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_network_Network_00024HttpClientThread_notifyOnHttpFinishLoading
  (JNIEnv * env, jobject thiz, jint responsePointer, jint listenerPointer) {
	if(listenerPointer) {
		wyHttpResponse* r = (wyHttpResponse*)responsePointer;
		if(!r->getRequest()->isCancelled()) {
			wyEventDispatcher* d = wyEventDispatcher::getInstanceNoCreate();
			if(d) {
				wyNotifyOnHttpFinishLoadingRunnable* n = wyNotifyOnHttpFinishLoadingRunnable::make(r, (wyHttpListener*)listenerPointer);
				d->queueRunnableLocked(n);
			}
		}
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_network_Network_00024HttpClientThread_notifyOnHttpLoadingFailed
  (JNIEnv * env, jobject thiz, jint responsePointer, jint listenerPointer) {
	if(listenerPointer) {
		wyHttpResponse* r = (wyHttpResponse*)responsePointer;
		if(!r->getRequest()->isCancelled()) {
			wyEventDispatcher* d = wyEventDispatcher::getInstanceNoCreate();
			if(d) {
				wyNotifyOnHttpLoadingFailedRunnable* n = wyNotifyOnHttpLoadingFailedRunnable::make(r, (wyHttpListener*)listenerPointer);
				d->queueRunnableLocked(n);
			}
		}
	}
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_network_Network_00024HttpClientThread_isRequestCancelled
  (JNIEnv * env, jobject thiz, jint requestPointer) {
	wyHttpRequest* req = (wyHttpRequest*)requestPointer;
	return req->isCancelled();
}

#ifdef __cplusplus
}
#endif

#endif // #if ANDROID
