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
#include "wyCustomColorFilter.h"

#if ANDROID
#include "wyUtils_android.h"

extern jmethodID g_mid_IColorFilterDelegate_apply;
#endif

wyCustomColorFilter::wyCustomColorFilter(wyColorFilterDelegate* delegate, void* userData) :
#if ANDROID
		m_jDelegate(NULL),
#endif
		m_userData(NULL) {
	memset(&m_delegate, 0, sizeof(wyColorFilterDelegate));
	setDelegate(delegate, userData);
}

wyCustomColorFilter::~wyCustomColorFilter() {
#if ANDROID
	if(m_jDelegate != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->DeleteGlobalRef(m_jDelegate);
		m_jDelegate = NULL;
	}
#endif
}

wyCustomColorFilter* wyCustomColorFilter::make(wyColorFilterDelegate* delegate, void* userData) {
	wyCustomColorFilter* f = WYNEW wyCustomColorFilter(delegate, userData);
	return (wyCustomColorFilter*)f->autoRelease();
}

void wyCustomColorFilter::apply(void* data, int width, int height) {
	if(m_delegate.apply)
		m_delegate.apply(data, width, height, m_userData);
#if ANDROID
	else if(m_jDelegate != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		jbyteArray array = env->NewByteArray(width * height * 4);
		env->SetByteArrayRegion(array, 0, width * height * 4, (jbyte*)data);
		env->CallVoidMethod(m_jDelegate, g_mid_IColorFilterDelegate_apply, array, width, height);
		jbyte* arrayData = env->GetByteArrayElements(array, NULL);
		memcpy(data, arrayData, width * height * 4 * sizeof(char));
		env->ReleaseByteArrayElements(array, arrayData, 0);
		env->DeleteLocalRef(array);
	}
#endif
}

void wyCustomColorFilter::setDelegate(wyColorFilterDelegate* delegate, void* data) {
	if(delegate == NULL) {
		memset(&m_delegate, 0, sizeof(wyColorFilterDelegate));
		m_userData = NULL;
	} else {
		memcpy(&m_delegate, delegate, sizeof(wyColorFilterDelegate));
		m_userData = data;
	}
}

#if ANDROID
void wyCustomColorFilter::setDelegate(jobject delegate) {
	JNIEnv* env = wyUtils::getJNIEnv();
	if(m_jDelegate != NULL) {
		env->DeleteGlobalRef(m_jDelegate);
		m_jDelegate = NULL;
	}
	m_jDelegate = env->NewGlobalRef(delegate);
}
#endif
