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

#include "wyIAPBackend_androidmarket.h"
#include "wyIAP.h"
#include "wyUtils.h"
#include "wyLog.h"

// extern functions
#ifdef __cplusplus
extern "C" {
#endif

extern void initIAPJNI(JNIEnv* env);
extern void deinitIAPJNI(JNIEnv* env);

#ifdef __cplusplus
}
#endif

// extern variables
extern jclass gClass_BillingService;
extern jfieldID g_fid_BillingService_PUBLIC_KEY;
extern jmethodID g_mid_BillingService_getInstance;
extern jmethodID g_mid_BillingService_checkBillingSupported;
extern jmethodID g_mid_BillingService_destroy;
extern jmethodID g_mid_BillingService_requestPurchase;
extern jmethodID g_mid_BillingService_restoreTransactions;
extern jmethodID g_mid_BillingService_verifyPurchase;

wyIAPBackend_androidmarket::wyIAPBackend_androidmarket() :
		m_billingService(NULL) {
	// set name
	setName(IAP_BACKEND_ANDROID_MARKET);

	// init JNI
	JNIEnv* env = wyUtils::getJNIEnv();
	initIAPJNI(env);

	// get billing service instance
	m_billingService = env->CallStaticObjectMethod(gClass_BillingService, g_mid_BillingService_getInstance);
	m_billingService = env->NewGlobalRef(m_billingService);
}

wyIAPBackend_androidmarket::~wyIAPBackend_androidmarket() {
	// release java side billing service object
	JNIEnv* env = wyUtils::getJNIEnv();
	if(m_billingService) {
		env->CallVoidMethod(m_billingService, g_mid_BillingService_destroy);
		env->DeleteGlobalRef(m_billingService);
		m_billingService = NULL;
	}

	// destroy jni
	deinitIAPJNI(env);
}

wyIAPBackend_androidmarket* wyIAPBackend_androidmarket::make() {
	wyIAPBackend_androidmarket* b = WYNEW wyIAPBackend_androidmarket();
	return (wyIAPBackend_androidmarket*)b->autoRelease();
}

bool wyIAPBackend_androidmarket::isAvailable() {
	JNIEnv* env = wyUtils::getJNIEnv();
	return env->CallBooleanMethod(m_billingService, g_mid_BillingService_checkBillingSupported);
}

void wyIAPBackend_androidmarket::buy(const char* productId, int quantity) {
	if(quantity > 1) {
		LOGW("Android Market IAP backend only support quantity 1");
	}

	JNIEnv* env = wyUtils::getJNIEnv();
	env->CallBooleanMethod(m_billingService, g_mid_BillingService_requestPurchase,
			env->NewStringUTF(productId), NULL);
}

void wyIAPBackend_androidmarket::restoreTransactions() {
	JNIEnv* env = wyUtils::getJNIEnv();
	env->CallBooleanMethod(m_billingService, g_mid_BillingService_restoreTransactions);
}

void wyIAPBackend_androidmarket::verifyTransaction(const char* pid, const void* receipt, size_t length, bool sandbox) {
    /*
     * receipt data format:
     * 1. signed data, null terminated
     * 2. signature, null terminated
     */

	// parse receipt data
	JNIEnv* env = wyUtils::getJNIEnv();
	Receipt* r = (Receipt*)receipt;
	jstring jPid = env->NewStringUTF(r->pid);
	jstring jSignedData = env->NewStringUTF(r->signedData);
	jstring jSignature = env->NewStringUTF(r->signature);

	// call
	env->CallVoidMethod(m_billingService, g_mid_BillingService_verifyPurchase, jPid, jSignedData, jSignature);

	// release
	env->DeleteLocalRef(jPid);
	env->DeleteLocalRef(jSignedData);
	env->DeleteLocalRef(jSignature);
}

void wyIAPBackend_androidmarket::config(const char* key, const char* value) {
	if(!strcmp("public_key", key)) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->SetStaticObjectField(gClass_BillingService, g_fid_BillingService_PUBLIC_KEY, env->NewStringUTF(value));
	}
}

#endif // #if ANDROID
