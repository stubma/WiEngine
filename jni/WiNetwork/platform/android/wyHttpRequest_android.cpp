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

#include "wyHttpRequest_android.h"
#include "wyHttpResponse_android.h"
#include "wyTypes.h"
#include "wyUtils.h"

extern jclass gClass_Network;
extern jclass gClass_ArrayList;
extern jmethodID g_mid_Network_createHttpClient;
extern jmethodID g_mid_Network_createHttpRequest;
extern jmethodID g_mid_Network_syncExec;
extern jmethodID g_mid_Network_asyncExec;
extern jmethodID g_mid_Network_shutdown;
extern jmethodID g_mid_Network_getBodyAsBytes;
extern jmethodID g_mid_HttpMessage_setHeader;
extern jmethodID g_mid_Network_addStringPart;
extern jmethodID g_mid_Network_addFilePart;
extern jmethodID g_mid_Network_setMultipartEntity;
extern jmethodID g_mid_Network_setUrlEncodedEntity;
extern jmethodID g_mid_Network_addNameValuePair;
extern jmethodID g_mid_ArrayList_init;

wyHttpRequest_android::wyHttpRequest_android(const char* url, Method method) :
		wyHttpRequest(url, method),
		m_jHttpClient(NULL) {
}

wyHttpRequest_android::~wyHttpRequest_android() {
	if(m_jHttpClient) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallStaticVoidMethod(gClass_Network, g_mid_Network_shutdown, m_jHttpClient);
		env->DeleteGlobalRef(m_jHttpClient);
	}
}

wyHttpRequest* wyHttpRequest::make(const char* url, Method method) {
	wyHttpRequest_android* r = WYNEW wyHttpRequest_android(url, method);
	return (wyHttpRequest*)r->autoRelease();
}

wyHttpResponse* wyHttpRequest_android::syncExec() {
	// get env
	JNIEnv* env = wyUtils::getJNIEnv();

	// create http client
	jobject client = createHttpClient(env);
	m_jHttpClient = env->NewGlobalRef(client);

	// create request
	jobject request = createHttpRequest(env);

	// execute
	jobject response = env->CallStaticObjectMethod(gClass_Network, g_mid_Network_syncExec, client, request);
	wyHttpResponse_android* r = wyHttpResponse_android::make(response);
	r->setRequest(this);

	// read all body if response is not null
	if(response) {
		jbyteArray body = (jbyteArray)env->CallStaticObjectMethod(gClass_Network, g_mid_Network_getBodyAsBytes, response);
		jsize len = env->GetArrayLength(body);
		jbyte* bodyArr = env->GetByteArrayElements(body, NULL);
		r->getBodyStream()->write((const char*)bodyArr, len);
		env->ReleaseByteArrayElements(body, bodyArr, 0);
	}

	return r;
}

void wyHttpRequest_android::asyncExec(wyHttpListener* listener) {
	// get env
	JNIEnv* env = wyUtils::getJNIEnv();

	// create http client
	jobject client = createHttpClient(env);
	m_jHttpClient = env->NewGlobalRef(client);

	// create request
	jobject request = createHttpRequest(env);

	// hold self because it is an asynchronous request
	retain();

	// execute
	env->CallStaticObjectMethod(gClass_Network, g_mid_Network_asyncExec, client, request, (jint)this, (jint)listener);
}

jobject wyHttpRequest_android::createHttpRequest(JNIEnv* env) {
	// check method, create java side request object
	jobject request = NULL;
	switch(m_method) {
		case wyHttpRequest::GET:
		case wyHttpRequest::DELETE:
		{
			const char* fullUrl = buildQueryString();
			jstring jFullUrl = env->NewStringUTF(fullUrl);
			request = env->CallStaticObjectMethod(gClass_Network, g_mid_Network_createHttpRequest, jFullUrl, (jint)m_method);
			env->DeleteLocalRef(jFullUrl);
			wyFree((void*)fullUrl);
			break;
		}
		default:
		{
			// create request for post or put
			jstring jUrl = env->NewStringUTF(m_url);
			request = env->CallStaticObjectMethod(gClass_Network, g_mid_Network_createHttpRequest, jUrl, (jint)m_method);
			env->DeleteLocalRef(jUrl);

			// build post body
			if(hasBlobParam())
				buildMultipart(env, request);
			else
				buildKeyValuePost(env, request);

			break;
		}
	}

	// install headers
	setHeaders(env, request);

	// return
	return request;
}

void wyHttpRequest_android::buildKeyValuePost(JNIEnv* env, jobject request) {
	if(m_parameters->size() > 0) {
		// create a list for all parts
		jobject list = env->NewObject(gClass_ArrayList, g_mid_ArrayList_init);

		// build parts
		for(vector<Parameter>::iterator iter = m_parameters->begin(); iter != m_parameters->end(); iter++) {
			if(!iter->blob) {
				jstring jKey = env->NewStringUTF(iter->key);
				jstring jValue = env->NewStringUTF(iter->value);
				env->CallStaticVoidMethod(gClass_Network, g_mid_Network_addNameValuePair, list, jKey, jValue);
				env->DeleteLocalRef(jKey);
				env->DeleteLocalRef(jValue);
			}
		}

		// build url encoded entity
		env->CallStaticVoidMethod(gClass_Network, g_mid_Network_setUrlEncodedEntity, request, list);

		// release list
		env->DeleteLocalRef(list);
	}
}

void wyHttpRequest_android::buildMultipart(JNIEnv* env, jobject request) {
	if(m_parameters->size() > 0) {
		// create a list for all parts
		jobject list = env->NewObject(gClass_ArrayList, g_mid_ArrayList_init);

		// build parts
		for(vector<Parameter>::iterator iter = m_parameters->begin(); iter != m_parameters->end(); iter++) {
			if(iter->blob) {
				jbyteArray jBlob = env->NewByteArray(iter->length);
				env->SetByteArrayRegion(jBlob, 0, iter->length, (const jbyte*)iter->value);
				jstring jKey = env->NewStringUTF(iter->key);
				env->CallStaticVoidMethod(gClass_Network, g_mid_Network_addFilePart, list, jKey, jBlob);
				env->DeleteLocalRef(jBlob);
				env->DeleteLocalRef(jKey);
			} else {
				jstring jKey = env->NewStringUTF(iter->key);
				jstring jValue = env->NewStringUTF(iter->value);
				env->CallStaticVoidMethod(gClass_Network, g_mid_Network_addStringPart, list, jKey, jValue);
				env->DeleteLocalRef(jKey);
				env->DeleteLocalRef(jValue);
			}
		}

		// build multipart finally
		env->CallStaticVoidMethod(gClass_Network, g_mid_Network_setMultipartEntity, request, list);

		// release list
		env->DeleteLocalRef(list);
	}
}

void wyHttpRequest_android::setHeaders(JNIEnv* env, jobject request) {
	for(vector<Header>::iterator iter = m_headers->begin(); iter != m_headers->end(); iter++) {
		jstring jKey = env->NewStringUTF(iter->key);
		jstring jValue = env->NewStringUTF(iter->value);
		env->CallVoidMethod(request, g_mid_HttpMessage_setHeader, jKey, jValue);
		env->DeleteLocalRef(jKey);
		env->DeleteLocalRef(jValue);
	}
}

jobject wyHttpRequest_android::createHttpClient(JNIEnv* env) {
	return env->CallStaticObjectMethod(gClass_Network, g_mid_Network_createHttpClient, m_timeout);
}

#endif // #if ANDROID
