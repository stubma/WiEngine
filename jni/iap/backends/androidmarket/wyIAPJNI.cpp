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
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CLASS_BILLINGSERVICE "com/wiyun/engine/iap/androidmarket/BillingService"

// class
jclass gClass_BillingService;

// BillingService
jfieldID g_fid_BillingService_PUBLIC_KEY;
jmethodID g_mid_BillingService_getInstance;
jmethodID g_mid_BillingService_checkBillingSupported;
jmethodID g_mid_BillingService_destroy;
jmethodID g_mid_BillingService_requestPurchase;
jmethodID g_mid_BillingService_restoreTransactions;
jmethodID g_mid_BillingService_verifyPurchase;

void initIAPJNI(JNIEnv* env) {
	jclass c = env->FindClass(CLASS_BILLINGSERVICE);
	gClass_BillingService = (jclass)env->NewGlobalRef(c);

	// BillingService
	g_fid_BillingService_PUBLIC_KEY = env->GetStaticFieldID(gClass_BillingService, "PUBLIC_KEY", "Ljava/lang/String;");
	g_mid_BillingService_getInstance = env->GetStaticMethodID(gClass_BillingService, "getInstance", "()Lcom/wiyun/engine/iap/androidmarket/BillingService;");
	g_mid_BillingService_checkBillingSupported = env->GetMethodID(gClass_BillingService, "checkBillingSupported", "()Z");
	g_mid_BillingService_destroy = env->GetMethodID(gClass_BillingService, "destroy", "()V");
	g_mid_BillingService_requestPurchase = env->GetMethodID(gClass_BillingService, "requestPurchase", "(Ljava/lang/String;Ljava/lang/String;)Z");
	g_mid_BillingService_restoreTransactions = env->GetMethodID(gClass_BillingService, "restoreTransactions", "()Z");
	g_mid_BillingService_verifyPurchase = env->GetMethodID(gClass_BillingService, "verifyPurchase", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
}

void deinitIAPJNI(JNIEnv* env) {
	env->DeleteGlobalRef(gClass_BillingService);
	gClass_BillingService = NULL;
}

#ifdef __cplusplus
}
#endif

#endif // #if ANDROID
