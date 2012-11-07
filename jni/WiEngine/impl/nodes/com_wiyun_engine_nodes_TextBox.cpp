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

#include "com_wiyun_engine_nodes_TextBox.h"
#include "wyTextBox_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextBox_nativeInit
  (JNIEnv * env, jobject thiz, jobject normalSprite, jobject selectedSprite, jobject disabledSprite, jobject focusedSprite, jobject label) {
	wyNode* normal = (wyNode*)env->GetIntField(normalSprite, g_fid_BaseObject_mPointer);
	wyNode* selected = selectedSprite == NULL ? NULL : (wyNode*)env->GetIntField(selectedSprite, g_fid_BaseObject_mPointer);
	wyNode* disabled = disabledSprite == NULL ? NULL : (wyNode*)env->GetIntField(disabledSprite, g_fid_BaseObject_mPointer);
	wyNode* focused = focusedSprite == NULL ? NULL : (wyNode*)env->GetIntField(focusedSprite, g_fid_BaseObject_mPointer);
	wyNode* labelNode = (wyNode*)env->GetIntField(label, g_fid_BaseObject_mPointer);
	wyTextBox* box = wyTextBox::make(normal, selected, disabled, focused, labelNode);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)box);
	box->retain();
	box->lazyRelease();
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_nodes_TextBox_getText
  (JNIEnv * env, jobject thiz) {
	wyTextBox* box = (wyTextBox*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* text = box->getText();
	jstring s = env->NewStringUTF(text);
	return s;
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_nodes_TextBox_getTitle
  (JNIEnv * env, jobject thiz) {
	wyTextBox* box = (wyTextBox*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* title = box->getTitle();
	jstring t = env->NewStringUTF(title);
	return t;
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_nodes_TextBox_getMessage
  (JNIEnv * env, jobject thiz) {
	wyTextBox* box = (wyTextBox*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* m = box->getMessage();
	jstring t = env->NewStringUTF(m);
	return t;
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_nodes_TextBox_getPositiveButton
  (JNIEnv * env, jobject thiz) {
	wyTextBox* box = (wyTextBox*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* m = box->getPositiveButton();
	if(m == NULL)
		return NULL;
	else {
		jstring t = env->NewStringUTF(m);
		return t;
	}
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_nodes_TextBox_getNegativeButton
  (JNIEnv * env, jobject thiz) {
	wyTextBox* box = (wyTextBox*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* m = box->getNegativeButton();
	if(m == NULL)
		return NULL;
	else {
		jstring t = env->NewStringUTF(m);
		return t;
	}
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TextBox_isPassword
  (JNIEnv * env, jobject thiz) {
	wyTextBox* box = (wyTextBox*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return box->isPassword();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextBox_onOKButtonClicked
  (JNIEnv * env, jobject thiz, jstring text) {
	wyTextBox* box = (wyTextBox*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* t = (const char*)env->GetStringUTFChars(text, NULL);
	box->onPositiveButtonClicked(t);
	env->ReleaseStringUTFChars(text, t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextBox_onCancelButtonClicked
  (JNIEnv * env, jobject thiz) {
	wyTextBox* box = (wyTextBox*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	box->onNegativeButtonClicked();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextBox_onTextChanged
  (JNIEnv * env, jobject thiz, jstring newText) {
	wyTextBox* box = (wyTextBox*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* t = (const char*)env->GetStringUTFChars(newText, NULL);
	box->onTextChanged(t);
	env->ReleaseStringUTFChars(newText, t);
}

#endif // #if ANDROID
