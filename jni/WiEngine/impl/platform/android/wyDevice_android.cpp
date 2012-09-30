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

#include "wyDevice.h"
#include "wyUtils_android.h"
#include <jni.h>
#include "wyMD5.h"
#include "wyLog.h"

extern jclass gClass_Director;
extern jmethodID g_mid_Director_getLanguage;
extern jmethodID g_mid_Director_getCountry;
extern jmethodID g_mid_Director_getDeviceIMEI;
extern jmethodID g_mid_Director_hasExternalStorage;

// language code
static char sLanguage[3];

// country code
static char sCountry[3];

// uuid
static char sIMEI[64];

const char* wyDevice::getLanguage() {
	// basic checking
	JNIEnv* env = wyUtils::getJNIEnv();
	if(!env)
		return "en";

	// get language from java side
	jstring lan = (jstring)env->CallStaticObjectMethod(gClass_Director, g_mid_Director_getLanguage);
	if(!lan)
		return "en";

	// get c string and copy it into static area
	const char* cLan = (const char*)env->GetStringUTFChars(lan, NULL);
	sLanguage[0] = cLan[0];
	sLanguage[1] = cLan[1];
	sLanguage[2] = 0;

	// release
	env->ReleaseStringUTFChars(lan, cLan);

	// return
	return sLanguage;
}

const char* wyDevice::getCountry() {
	// basic checking
	JNIEnv* env = wyUtils::getJNIEnv();
	if(!env)
		return "US";

	// get country from java side
	jstring c = (jstring)env->CallStaticObjectMethod(gClass_Director, g_mid_Director_getCountry);
	if(!c)
		return "US";

	// get c string and copy it into static area
	const char* cc = (const char*)env->GetStringUTFChars(c, NULL);
	sCountry[0] = cc[0];
	sCountry[1] = cc[1];
	sCountry[2] = 0;

	// release
	env->ReleaseStringUTFChars(c, cc);

	// return
	return sCountry;
}

const char* wyDevice::getDeviceId() {
	// basic checking
	JNIEnv* env = wyUtils::getJNIEnv();
	if(!env)
		return NULL;

	// check permission
	if(wyUtils_android::hasPermission("android.permission.READ_PHONE_STATE")) {
		LOGW("wyDevice::getDeviceId: you don't have READ_PHONE_STATE permission, add it!");
		return NULL;
	}

	// get country from java side
	jstring s = (jstring)env->CallStaticObjectMethod(gClass_Director, g_mid_Director_getDeviceIMEI);
	if(!s)
		return NULL;

	// get c string
	const char* cs = (const char*)env->GetStringUTFChars(s, NULL);

	// copy to static buffer
	sprintf(sIMEI, "%s", cs);

	// free
	env->ReleaseStringUTFChars(s, cs);

	// return
	return sIMEI;
}

bool wyDevice::hasExternalStorage() {
	// basic checking
	JNIEnv* env = wyUtils::getJNIEnv();
	if(!env)
		return false;

	return env->CallStaticBooleanMethod(gClass_Director, g_mid_Director_hasExternalStorage);
}

#endif // #if ANDROID
