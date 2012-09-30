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

#include "wyNetwork.h"
#include "wyUtils.h"
#include <jni.h>

// global classes
jclass gClass_Network;
jclass gClass_ArrayList;

// method or field id list
jmethodID g_mid_Network_getNetworkType;
jmethodID g_mid_Network_createHttpClient;
jmethodID g_mid_Network_createHttpRequest;
jmethodID g_mid_Network_syncExec;
jmethodID g_mid_Network_asyncExec;
jmethodID g_mid_Network_shutdown;
jmethodID g_mid_Network_getStatusCode;
jmethodID g_mid_Network_getHeader;
jmethodID g_mid_Network_getBodyAsBytes;
jmethodID g_mid_Network_getEntityContentStream;
jmethodID g_mid_Network_readEntity;
jmethodID g_mid_Network_addStringPart;
jmethodID g_mid_Network_addFilePart;
jmethodID g_mid_Network_setMultipartEntity;
jmethodID g_mid_Network_setUrlEncodedEntity;
jmethodID g_mid_Network_addNameValuePair;

// HttpMessage
jmethodID g_mid_HttpMessage_setHeader;

// ArrayList
jmethodID g_mid_ArrayList_init;

wyNetwork::NetworkType wyNetwork::getNetworkType() {
	JNIEnv* env = wyUtils::getJNIEnv();
	return (wyNetwork::NetworkType)env->CallStaticIntMethod(gClass_Network, g_mid_Network_getNetworkType);
}

void wyNetwork::init() {
	if(!s_inited) {
		s_inited = true;

		// get jni env
		JNIEnv* env = wyUtils::getJNIEnv();

		// find global classes
		jclass clazz = env->FindClass("com/wiyun/engine/network/Network");
		gClass_Network = (jclass)env->NewGlobalRef(clazz);
		clazz = env->FindClass("java/util/ArrayList");
		gClass_ArrayList = (jclass)env->NewGlobalRef(clazz);

		// Network
		g_mid_Network_getNetworkType = env->GetStaticMethodID(gClass_Network, "getNetworkType", "()I");
		g_mid_Network_createHttpClient = env->GetStaticMethodID(gClass_Network, "createHttpClient", "(I)Lorg/apache/http/impl/client/DefaultHttpClient;");
		g_mid_Network_createHttpRequest = env->GetStaticMethodID(gClass_Network, "createHttpRequest", "(Ljava/lang/String;I)Lorg/apache/http/client/methods/HttpUriRequest;");
		g_mid_Network_syncExec = env->GetStaticMethodID(gClass_Network, "syncExec", "(Lorg/apache/http/impl/client/DefaultHttpClient;Lorg/apache/http/client/methods/HttpUriRequest;)Lorg/apache/http/HttpResponse;");
		g_mid_Network_asyncExec = env->GetStaticMethodID(gClass_Network, "asyncExec", "(Lorg/apache/http/impl/client/DefaultHttpClient;Lorg/apache/http/client/methods/HttpUriRequest;II)V");
		g_mid_Network_shutdown = env->GetStaticMethodID(gClass_Network, "shutdown", "(Lorg/apache/http/impl/client/DefaultHttpClient;)V");
		g_mid_Network_getStatusCode = env->GetStaticMethodID(gClass_Network, "getStatusCode", "(Lorg/apache/http/HttpResponse;)I");
		g_mid_Network_getHeader = env->GetStaticMethodID(gClass_Network, "getHeader", "(Lorg/apache/http/HttpResponse;Ljava/lang/String;)Ljava/lang/String;");
		g_mid_Network_getBodyAsBytes = env->GetStaticMethodID(gClass_Network, "getBodyAsBytes", "(Lorg/apache/http/HttpResponse;)[B");
		g_mid_Network_getEntityContentStream = env->GetStaticMethodID(gClass_Network, "getEntityContentStream", "(Lorg/apache/http/HttpResponse;)Ljava/io/InputStream;");
		g_mid_Network_readEntity = env->GetStaticMethodID(gClass_Network, "readEntity", "(Ljava/io/InputStream;[B)I");
		g_mid_Network_addStringPart = env->GetStaticMethodID(gClass_Network, "addStringPart", "(Ljava/util/List;Ljava/lang/String;Ljava/lang/String;)V");
		g_mid_Network_addFilePart = env->GetStaticMethodID(gClass_Network, "addFilePart", "(Ljava/util/List;Ljava/lang/String;[B)V");
		g_mid_Network_setMultipartEntity = env->GetStaticMethodID(gClass_Network, "setMultipartEntity", "(Lorg/apache/http/client/methods/HttpEntityEnclosingRequestBase;Ljava/util/List;)V");
		g_mid_Network_setUrlEncodedEntity = env->GetStaticMethodID(gClass_Network, "setUrlEncodedEntity", "(Lorg/apache/http/client/methods/HttpEntityEnclosingRequestBase;Ljava/util/List;)V");
		g_mid_Network_addNameValuePair = env->GetStaticMethodID(gClass_Network, "addNameValuePair", "(Ljava/util/List;Ljava/lang/String;Ljava/lang/String;)V");

		// HttpMessage
		clazz = env->FindClass("org/apache/http/HttpMessage");
		g_mid_HttpMessage_setHeader = env->GetMethodID(clazz, "setHeader", "(Ljava/lang/String;Ljava/lang/String;)V");

		// ArrayList
		g_mid_ArrayList_init = env->GetMethodID(gClass_ArrayList, "<init>", "()V");
	}
}

void wyNetwork::cleanup() {
	if(s_inited) {
		// get jni env
		JNIEnv* env = wyUtils::getJNIEnv();

		// release classes
		env->DeleteGlobalRef(gClass_Network);
		env->DeleteGlobalRef(gClass_ArrayList);

		// set flag
		s_inited = false;
	}
}

#endif // #if ANDROID
