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
#include "WiEngine-IAP.h"
#include "wyIAPBackend_androidmarket.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_com_wiyun_engine_iap_androidmarket_PurchaseObserver_nativeNotifyOnBuyProductFailed
  (JNIEnv * env, jobject thiz, jstring productId, jint errorCode) {
	wyIAP* iap = wyIAP::getInstanceNoCreate();
	if(iap) {
		wyIAPBackend* backend = iap->getActiveBackend();
		const char* pid = (const char*)env->GetStringUTFChars(productId, NULL);
		backend->notifyOnBuyProductFailed(pid, (wyIAPListener::Error)errorCode, NULL);
		env->ReleaseStringUTFChars(productId, pid);
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_iap_androidmarket_PurchaseObserver_nativeNotifyOnBuyProductOK
  (JNIEnv * env, jobject thiz, jstring productId, jstring signedData, jstring signature) {
	wyIAP* iap = wyIAP::getInstanceNoCreate();
	if(iap) {
		wyIAPBackend* backend = iap->getActiveBackend();
		const char* pid = (const char*)env->GetStringUTFChars(productId, NULL);
		const char* data = (const char*)env->GetStringUTFChars(signedData, NULL);
		const char* sig = (const char*)env->GetStringUTFChars(signature, NULL);

		wyIAPBackend_androidmarket::Receipt receipt = {
				pid,
				data,
				sig
		};

		backend->notifyOnBuyProductOK(pid, (const void*)&receipt, sizeof(wyIAPBackend_androidmarket::Receipt));

		env->ReleaseStringUTFChars(productId, pid);
		env->ReleaseStringUTFChars(signedData, data);
		env->ReleaseStringUTFChars(signature, sig);
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_iap_androidmarket_PurchaseObserver_nativeNotifyOnBuyProductRestored
  (JNIEnv * env, jobject thiz, jstring productId, jstring signedData, jstring signature) {
	wyIAP* iap = wyIAP::getInstanceNoCreate();
	if(iap) {
		wyIAPBackend* backend = iap->getActiveBackend();
		const char* pid = (const char*)env->GetStringUTFChars(productId, NULL);
		const char* data = (const char*)env->GetStringUTFChars(signedData, NULL);
		const char* sig = (const char*)env->GetStringUTFChars(signature, NULL);

		wyIAPBackend_androidmarket::Receipt receipt = {
				pid,
				data,
				sig
		};

		backend->notifyOnBuyProductRestored(pid, (const void*)&receipt, sizeof(wyIAPBackend_androidmarket::Receipt));

		env->ReleaseStringUTFChars(productId, pid);
		env->ReleaseStringUTFChars(signedData, data);
		env->ReleaseStringUTFChars(signature, sig);
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_iap_androidmarket_PurchaseObserver_nativeNotifyOnBuyProductRefunded
  (JNIEnv * env, jobject thiz, jstring productId, jstring signedData, jstring signature) {
	wyIAP* iap = wyIAP::getInstanceNoCreate();
	if(iap) {
		wyIAPBackend* backend = iap->getActiveBackend();
		const char* pid = (const char*)env->GetStringUTFChars(productId, NULL);
		const char* data = (const char*)env->GetStringUTFChars(signedData, NULL);
		const char* sig = (const char*)env->GetStringUTFChars(signature, NULL);

		wyIAPBackend_androidmarket::Receipt receipt = {
				pid,
				data,
				sig
		};

		// notify
		backend->notifyOnBuyProductRefunded(pid, (const void*)&receipt, sizeof(wyIAPBackend_androidmarket::Receipt));

		// release
		env->ReleaseStringUTFChars(productId, pid);
		env->ReleaseStringUTFChars(signedData, data);
		env->ReleaseStringUTFChars(signature, sig);
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_iap_androidmarket_PurchaseObserver_nativeNotifyOnVerifyPurchaseOK
  (JNIEnv * env, jobject thiz, jstring productId) {
	wyIAP* iap = wyIAP::getInstanceNoCreate();
	if(iap) {
		wyIAPBackend* backend = iap->getActiveBackend();
		const char* pid = (const char*)env->GetStringUTFChars(productId, NULL);
		backend->notifyOnVerifyReceiptOK(pid);
		env->ReleaseStringUTFChars(productId, pid);
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_iap_androidmarket_PurchaseObserver_nativeNotifyOnVerifyPurchaseFailed
  (JNIEnv * env, jobject thiz, jstring productId) {
	wyIAP* iap = wyIAP::getInstanceNoCreate();
	if(iap) {
		wyIAPBackend* backend = iap->getActiveBackend();
		const char* pid = (const char*)env->GetStringUTFChars(productId, NULL);
		backend->notifyOnVerifyReceiptFailed(pid, wyIAPListener::E_GENERAL, NULL);
		env->ReleaseStringUTFChars(productId, pid);
	}
}

#ifdef __cplusplus
}
#endif

#endif // #if ANDROID
