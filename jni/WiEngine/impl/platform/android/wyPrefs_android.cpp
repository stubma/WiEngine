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

#include "wyPrefs.h"
#include "wyJNI.h"
#include "wyTypes.h"
#include "wyUtils.h"

extern jclass gClass_PrefUtil;
extern jmethodID g_mid_PrefUtil_getLongPref;
extern jmethodID g_mid_PrefUtil_setLongPref;
extern jmethodID g_mid_PrefUtil_getIntPref;
extern jmethodID g_mid_PrefUtil_setIntPref;
extern jmethodID g_mid_PrefUtil_getStringPref;
extern jmethodID g_mid_PrefUtil_setStringPref;
extern jmethodID g_mid_PrefUtil_getBoolPref;
extern jmethodID g_mid_PrefUtil_setBoolPref;
extern jmethodID g_mid_PrefUtil_getLongPref;
extern jmethodID g_mid_PrefUtil_setLongPref;
extern jmethodID g_mid_PrefUtil_clear;
extern jmethodID g_mid_PrefUtil_remove;

int wyPrefs::getInt(const char* key, int defValue) {
	int ret = 0;

	JNIEnv* env = getEnv();
	if(env != NULL) {
		jstring k = env->NewStringUTF(key);
		ret = env->CallStaticIntMethod(gClass_PrefUtil, g_mid_PrefUtil_getIntPref, k, defValue);
		env->DeleteLocalRef(k);
	}

	return ret;
}

void wyPrefs::setInt(const char* key, int value) {
	JNIEnv* env = getEnv();
	if(env != NULL) {
		jstring k = env->NewStringUTF(key);
		env->CallStaticVoidMethod(gClass_PrefUtil, g_mid_PrefUtil_setIntPref, k, value);
		env->DeleteLocalRef(k);
	}
}

bool wyPrefs::getBool(const char* key, bool defValue) {
	bool ret = 0;

	JNIEnv* env = getEnv();
	if(env != NULL) {
		jstring k = env->NewStringUTF(key);
		ret = env->CallStaticBooleanMethod(gClass_PrefUtil, g_mid_PrefUtil_getBoolPref, k, defValue);
		env->DeleteLocalRef(k);
	}

	return ret;
}

void wyPrefs::setBool(const char* key, bool value) {
	JNIEnv* env = getEnv();
	if(env != NULL) {
		jstring k = env->NewStringUTF(key);
		env->CallStaticVoidMethod(gClass_PrefUtil, g_mid_PrefUtil_setBoolPref, k, value);
		env->DeleteLocalRef(k);
	}
}

void wyPrefs::setInt64(const char* key, int64_t value) {
	JNIEnv* env = getEnv();
	if(env != NULL) {
		jstring k = env->NewStringUTF(key);
		env->CallStaticVoidMethod(gClass_PrefUtil, g_mid_PrefUtil_setLongPref, k, value);
		env->DeleteLocalRef(k);
	}
}

int64_t wyPrefs::getInt64(const char* key, int64_t defValue) {
	int64_t ret = 0;

	JNIEnv* env = getEnv();
	if(env != NULL) {
		jstring k = env->NewStringUTF(key);
		ret = env->CallStaticLongMethod(gClass_PrefUtil, g_mid_PrefUtil_getLongPref, k, defValue);
		env->DeleteLocalRef(k);
	}

	return ret;
}

const char* wyPrefs::getString(const char* key, const char* defValue) {
	const char* ret = 0;

	JNIEnv* env = getEnv();
	if(env != NULL) {
		jstring k = env->NewStringUTF(key);
		jstring def = defValue == NULL ? NULL : env->NewStringUTF(defValue);
		jstring v = (jstring)env->CallStaticObjectMethod(gClass_PrefUtil, g_mid_PrefUtil_getStringPref, k, def);
		const char* vStr = (const char*)env->GetStringUTFChars(v, NULL);
		ret = wyUtils::copy(vStr);
		env->ReleaseStringUTFChars(v, vStr);
		env->DeleteLocalRef(k);
		env->DeleteLocalRef(def);
		env->DeleteLocalRef(v);
	}

	return ret;
}

void wyPrefs::setString(const char* key, const char* value) {
	JNIEnv* env = getEnv();
	if(env != NULL) {
		jstring k = env->NewStringUTF(key);
		jstring v = value == NULL ? NULL : env->NewStringUTF(value);
		env->CallStaticVoidMethod(gClass_PrefUtil, g_mid_PrefUtil_setStringPref, k, v);
		env->DeleteLocalRef(k);
		env->DeleteLocalRef(v);
	}
}

void wyPrefs::clear() {
	JNIEnv* env = getEnv();
	if(env != NULL) {
		env->CallStaticVoidMethod(gClass_PrefUtil, g_mid_PrefUtil_clear);
	}
}

void wyPrefs::remove(const char* key) {
	JNIEnv* env = getEnv();
	if(env != NULL) {
		jstring k = env->NewStringUTF(key);
		env->CallStaticVoidMethod(gClass_PrefUtil, g_mid_PrefUtil_remove, k);
		env->DeleteLocalRef(k);
	}
}

#endif // #if ANDROID
