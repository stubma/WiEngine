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

#include "wyHttpResponse_android.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyUtils_android.h"
#include "wyLog.h"

extern jclass gClass_Network;
extern jmethodID g_mid_Network_getStatusCode;
extern jmethodID g_mid_Network_getHeader;
extern jmethodID g_mid_Network_getBodyAsBytes;
extern jmethodID g_mid_Network_getEntityContentStream;
extern jmethodID g_mid_Network_readEntity;

wyHttpResponse_android::wyHttpResponse_android(jobject response) :
		m_jResponse(NULL),
		m_jContentStream(NULL) {
	if(response) {
		JNIEnv* env = wyUtils::getJNIEnv();
		m_jResponse = env->NewGlobalRef(response);
	}
}

wyHttpResponse_android::~wyHttpResponse_android() {
	JNIEnv* env = wyUtils::getJNIEnv();
	if(m_jResponse) {
		env->DeleteGlobalRef(m_jResponse);
	}
	if(m_jContentStream) {
		env->DeleteGlobalRef(m_jContentStream);
	}
}

wyHttpResponse_android* wyHttpResponse_android::make(jobject response) {
	wyHttpResponse_android* r = WYNEW wyHttpResponse_android(response);
	return (wyHttpResponse_android*)r->autoRelease();
}

const char* wyHttpResponse_android::getHeader(const char* name) {
	if(m_jResponse) {
		JNIEnv* env = wyUtils::getJNIEnv();
		jstring jName = env->NewStringUTF(name);
		jstring jValue = (jstring)env->CallStaticObjectMethod(gClass_Network, g_mid_Network_getHeader, m_jResponse, jName);
		const char* value = wyUtils_android::to_CString(jValue);
		env->DeleteLocalRef(jName);
		return value;
	} else {
		return NULL;
	}
}

int wyHttpResponse_android::getStatusCode() {
	if(m_jResponse) {
		JNIEnv* env = wyUtils::getJNIEnv();
		return env->CallStaticIntMethod(gClass_Network, g_mid_Network_getStatusCode, m_jResponse);
	} else {
		return 500;
	}
}

ssize_t wyHttpResponse_android::read(size_t max) {
	// check response
	if(!m_jResponse)
		return -2;

	// ensure env is available
	JNIEnv* env = wyUtils::getJNIEnv();
	if(!env)
		return -2;

	// get stream
	if(!m_jContentStream) {
		jobject is = env->CallStaticObjectMethod(gClass_Network, g_mid_Network_getEntityContentStream, m_jResponse);
		if(is) {
			m_jContentStream = env->NewGlobalRef(is);
		} else {
			return -2;
		}
	}

	// read it
	jbyteArray jArr = env->NewByteArray(max);
	int ret = env->CallStaticIntMethod(gClass_Network, g_mid_Network_readEntity, m_jContentStream, jArr);
	if(ret > 0) {
		jbyte* arrBytes = env->GetByteArrayElements(jArr, NULL);
		m_body->reset();
		m_body->write((const char*)arrBytes, ret);
		env->ReleaseByteArrayElements(jArr, arrBytes, 0);
	}

	// release
	env->DeleteLocalRef(jArr);

	return ret;
}

#endif // #if ANDROID
