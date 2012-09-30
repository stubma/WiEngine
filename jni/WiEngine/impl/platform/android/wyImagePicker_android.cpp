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

#include "wyImagePicker.h"
#include "wyTypes.h"
#include "wyUtils_android.h"
#include <jni.h>

// class
extern jclass gClass_ImagePicker;

// ImagePicker
extern jmethodID g_mid_ImagePicker_hasCamera;
extern jmethodID g_mid_ImagePicker_hasFrontCamera;
extern jmethodID g_mid_ImagePicker_pickFromCamera;
extern jmethodID g_mid_ImagePicker_pickFromAlbum;

bool wyImagePicker::hasCamera() {
	JNIEnv* env = wyUtils::getJNIEnv();
	return env->CallStaticBooleanMethod(gClass_ImagePicker, g_mid_ImagePicker_hasCamera);
}

bool wyImagePicker::hasFrontCamera() {
	JNIEnv* env = wyUtils::getJNIEnv();
	return env->CallStaticBooleanMethod(gClass_ImagePicker, g_mid_ImagePicker_hasFrontCamera);
}

void wyImagePicker::pickFromCamera(wyImagePickerCallback* callback, void* data, int w, int h, bool keepRatio, bool front) {
	if(front && !hasFrontCamera())
		return;
	if(!front && !hasCamera())
		return;

	JNIEnv* env = wyUtils::getJNIEnv();
	env->CallStaticVoidMethod(gClass_ImagePicker, g_mid_ImagePicker_pickFromCamera, (jint)callback, (jint)data, w, h, keepRatio, front);
}

void wyImagePicker::pickFromAlbum(wyImagePickerCallback* callback, void* data, int w, int h, bool keepRatio) {
	JNIEnv* env = wyUtils::getJNIEnv();
	env->CallStaticVoidMethod(gClass_ImagePicker, g_mid_ImagePicker_pickFromAlbum, (jint)callback, (jint)data, w, h, keepRatio);
}

#endif // #if ANDROID
