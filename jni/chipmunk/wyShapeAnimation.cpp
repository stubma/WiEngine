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
#include "wyShapeAnimation.h"
#include "wySpriteFrame.h"
#include "wyTextureManager.h"
#include "wyScheduler.h"
#include <stdlib.h>
#include <stdarg.h>

#if ANDROID
	#include "wyJNI.h"
	extern jmethodID g_mid_ShapeAnimationCallback_onAnimationEnd;
	extern jmethodID g_mid_ShapeAnimationCallback_onAnimationAborted;
#endif

#define TS_UPDATE -10000

void wyShapeAnimation::invokeOnEnd() {
#if ANDROID
	if(m_jCallback != NULL) {
		JNIEnv* env = getEnv();
		if(env != NULL) {
			env->CallVoidMethod(m_jCallback, g_mid_ShapeAnimationCallback_onAnimationEnd, (jint)m_shape);
		}
	} else
#endif
	if(m_callback != NULL) {
		m_callback->onAnimationEnd(m_shape);
	}
}

void wyShapeAnimation::invokeOnAborted() {
#if ANDROID
	if(m_jCallback != NULL) {
		JNIEnv* env = getEnv();
		if(env != NULL) {
			env->CallVoidMethod(m_jCallback, g_mid_ShapeAnimationCallback_onAnimationAborted, (jint)m_shape);
		}
	} else
#endif
	if(m_callback != NULL) {
		m_callback->onAnimationAborted(m_shape);
	}
}

bool wyShapeAnimation::releaseFrame(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

wyShapeAnimation::~wyShapeAnimation() {
	wyArrayEach(m_frames, releaseFrame, NULL);
	wyArrayDestroy(m_frames);

    if(m_callback)
        delete m_callback;

#if ANDROID
	JNIEnv* env = getEnv();
	if(env != NULL) {
		if(m_jCallback != NULL) {
			env->DeleteGlobalRef(m_jCallback);
			m_jCallback = NULL;
		}
	}
#endif
}

wyShapeAnimation::wyShapeAnimation() :
		m_frames(wyArrayNew(10)),
		m_shape(NULL),
		m_timer(NULL),
		m_duration(0),
		m_frameTotalDuration(0),
		m_loop(false),
		m_elapsed(0),
		m_callback(NULL),
#if ANDROID
		m_jCallback(NULL),
#endif
		m_autoSize(false) {
}

wyShapeAnimation* wyShapeAnimation::make(float duration, ...) {
	va_list ids;
	va_start(ids, duration);

	wyShapeAnimation* anim = WYNEW wyShapeAnimation();
	for(int id = va_arg(ids, int); id != 0; id = va_arg(ids, int)) {
		wyTexture2D* tex = wyTexture2D::make(id);
		anim->addFrame(duration, tex);
	}

	va_end(ids);

	return (wyShapeAnimation*)anim->autoRelease();
}

void wyShapeAnimation::addFrame(float duration, wyTexture2D* tex) {
	wySpriteFrame* frame = wySpriteFrame::make(duration, tex);
	wyArrayPush(m_frames, frame);
	frame->retain();
	m_frameTotalDuration += duration;
	if(!m_loop)
		m_duration = m_frameTotalDuration;
}

void wyShapeAnimation::addFrame(wySpriteFrame* frame) {
	wyArrayPush(m_frames, frame);
	frame->retain();
	m_frameTotalDuration += frame->getDuration();
	if(!m_loop)
		m_duration = m_frameTotalDuration;
}

void wyShapeAnimation::update(wyTargetSelector* ts) {
	float delta = ts->getDelta();
	m_elapsed += delta;
	if(m_elapsed > m_duration) {
		wyScheduler::getInstance()->unscheduleLocked(m_timer);
		m_timer = NULL;

		invokeOnEnd();

		cpShapeSetAnimation(m_shape, NULL);
	} else {
		float remainder = ((long)(m_elapsed * 1000L) % (long)(m_frameTotalDuration * 1000L)) / 1000.f;
		int size = m_frames->num;
		for(int i = 0; i < size; i++) {
			wySpriteFrame* frame = (wySpriteFrame*)wyArrayGet(m_frames, i);
			remainder -= frame->getDuration();
			if(remainder < 0.f) {
				cpShapeSetTexture2(m_shape, frame->getTexture(), frame->getRect(), m_autoSize);
				break;
			}
		}
	}
}

void wyShapeAnimation::start(cpShape* shape) {
	this->m_shape = shape;
	cpShapeSetAnimation(m_shape, this);

    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyShapeAnimation::update));
    m_timer = wyTimer::make(ts);
	wyScheduler::getInstance()->scheduleLocked(m_timer);
}

void wyShapeAnimation::stop() {
	if(m_timer != NULL) {
		wyScheduler::getInstance()->unscheduleLocked(m_timer);
		m_timer = NULL;

		invokeOnAborted();
		cpShapeSetAnimation(m_shape, NULL);
	}
}

void wyShapeAnimation::setLoop(bool loop) {
	m_loop = loop;
	if(m_loop) {
		m_duration = MAX_FLOAT;
	} else {
		m_duration = m_frameTotalDuration;
	}
}

#if ANDROID
void wyShapeAnimation::setJavaCallback(jobject callback) {
	JNIEnv* env = getEnv();
	if(m_jCallback != NULL) {
		env->DeleteGlobalRef(m_jCallback);
		m_jCallback = NULL;
	}

	if(callback != NULL) {
		m_jCallback = env->NewGlobalRef(callback);
	}
}
#endif

void wyShapeAnimation::setCallback(wyShapeAnimationCallback* cb) {
	if(!m_callback)
		m_callback = new wyShapeAnimationCallback;
    
    *m_callback = *cb;
}
