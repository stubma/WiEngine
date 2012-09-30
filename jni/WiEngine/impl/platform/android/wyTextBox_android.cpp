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

#include "wyTextBox_android.h"
#include "wyTypes.h"
#include "wyUtils_android.h"

extern jclass gClass_TextBox;
extern jmethodID g_mid_TextBox_showInputDialog;
extern jmethodID g_mid_ITextBoxCallback_onBeginEditing;
extern jmethodID g_mid_ITextBoxCallback_onEndEditing;
extern jmethodID g_mid_ITextBoxCallback_onTextChanged;

wyTextBox* wyTextBox::make(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyNode* label) {
	wyTextBox* n = WYNEW wyTextBox_android(normal, selected, disabled, focused, label);
	return (wyTextBox*)n->autoRelease();
}

wyTextBox_android::wyTextBox_android(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyNode* label) :
		wyTextBox(normal, selected, disabled, focused, label),
		m_jCallback(NULL) {
}

wyTextBox_android::~wyTextBox_android() {
	JNIEnv* env = wyUtils::getJNIEnv();
	if(m_jCallback != NULL) {
		if(env != NULL) {
			env->DeleteGlobalRef(m_jCallback);
			m_jCallback = NULL;
		}
	}
}

void wyTextBox_android::showInputDialog() {
	JNIEnv* env = wyUtils::getJNIEnv();
	env->CallStaticVoidMethod(gClass_TextBox, g_mid_TextBox_showInputDialog, (jint)this);
}

void wyTextBox_android::setCallback(jobject jcallback) {
	JNIEnv* env = wyUtils::getJNIEnv();
	if(m_jCallback != NULL) {
		env->DeleteGlobalRef(m_jCallback);
		m_jCallback = NULL;
	}

	if(jcallback != NULL) {
		m_jCallback = env->NewGlobalRef(jcallback);
	}
}

jobject wyTextBox_android::getCallback() {
	return m_jCallback;
}

void wyTextBox_android::notifyOnTextChanged() {
	wyTextBox::notifyOnTextChanged();

	if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_ITextBoxCallback_onTextChanged, (jint)this);
	}
}

void wyTextBox_android::notifyOnBeginEditing() {
	wyTextBox::notifyOnBeginEditing();

	if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_ITextBoxCallback_onBeginEditing, (jint)this);
	}
}

void wyTextBox_android::notifyOnEndEditing() {
	wyTextBox::notifyOnEndEditing();

	if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_ITextBoxCallback_onEndEditing, (jint)this);
	}
}

#endif // #if ANDROID
