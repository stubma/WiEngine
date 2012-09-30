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
#include "wyAnimation.h"
#include "wySpriteFrame.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"

#if ANDROID
#include "wyUtils_android.h"

extern jmethodID g_mid_IAnimationCallback_onAnimationFrameChanged;
extern jmethodID g_mid_IAnimationCallback_onAnimationEnded;
#endif

wyAnimation* wyAnimation::make(int id) {
	wyAnimation* a = WYNEW wyAnimation(id);
	return (wyAnimation*)a->autoRelease();
}

bool wyAnimation::releaseFrame(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

wyAnimation::~wyAnimation() {
#if ANDROID
	if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->DeleteGlobalRef(m_jCallback);
		m_jCallback = NULL;
	}
#endif
	wyArrayEach(m_frames, releaseFrame, NULL);
	wyArrayClear(m_frames);
	wyArrayDestroy(m_frames);
	m_frames = NULL;
}

wyAnimation::wyAnimation(int id) :
		m_id(id),
		m_frames(wyArrayNew(10)),
		m_duration(0),
#if ANDROID
		m_jCallback(NULL),
#endif
		m_data(NULL) {
	memset(&m_callback, 0, sizeof(wyAnimationCallback));
}

void wyAnimation::addFrame(float frameDuration, wyTexture2D* tex) {
	wySpriteFrame* frame = wySpriteFrame::make(frameDuration, tex);
	m_duration += frameDuration;
	wyArrayPush(m_frames, frame);
	frame->retain();
}

void wyAnimation::addFrame(float frameDuration, wyRect rect) {
	wySpriteFrame* frame = wySpriteFrame::make(frameDuration, rect);
	m_duration += frameDuration;
	wyArrayPush(m_frames, frame);
	frame->retain();
}

void wyAnimation::addFrame(wyFrame* f) {
	m_duration += f->getDuration();
	wyArrayPush(m_frames, f);
	f->retain();
}

void wyAnimation::notifyAnimationFrameChanged(int index) {
#if ANDROID
	if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_IAnimationCallback_onAnimationFrameChanged, (jint)this, index);
	} else 
#endif
	if(m_callback.onAnimationFrameChanged != NULL) {
		(*m_callback.onAnimationFrameChanged)(this, index, m_data);
	}
}

void wyAnimation::notifyAnimationEnded() {
#if ANDROID
	if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_IAnimationCallback_onAnimationEnded, (jint)this);
	} else 
#endif
	if(m_callback.onAnimationEnded != NULL) {
		(*m_callback.onAnimationEnded)(this, m_data);
	}
}

void wyAnimation::setCallback(wyAnimationCallback* callback, void* data) {
	if(callback == NULL) {
		memset(&m_callback, 0, sizeof(wyAnimationCallback));
		m_data = NULL;
	} else {
		memcpy(&m_callback, callback, sizeof(wyAnimationCallback));
		m_data = data;
	}
}

#if ANDROID

void wyAnimation::setCallback(jobject jCallback) {
	JNIEnv* env = wyUtils::getJNIEnv();
	if(m_jCallback != NULL) {
		env->DeleteGlobalRef(m_jCallback);
		m_jCallback = NULL;
	}

	if(jCallback != NULL) {
		m_jCallback = env->NewGlobalRef(jCallback);
	}
}

#endif
