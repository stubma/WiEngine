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
#include "wyFixtureAnimation.h"
#include "wySpriteFrame.h"
#include "wyTextureManager.h"
#include <stdlib.h>
#include <stdarg.h>
#include "wyBox2D.h"
#include "wyLog.h"

#if ANDROID
	#include "wyJNI.h"
	extern jmethodID g_mid_FixtureAnimationCallback_onAnimationEnd;
	extern jmethodID g_mid_FixtureAnimationCallback_onAnimationAborted;
#endif

void wyFixtureAnimation::invokeOnEnd() {
#if ANDROID
	if(m_jCallback != NULL) {
		JNIEnv* env = getEnv();
		if(env != NULL) {
			env->CallVoidMethod(m_jCallback, g_mid_FixtureAnimationCallback_onAnimationEnd, (jint)m_fixture);
		}
	} else 
#endif
	if(m_callback != NULL) {
		m_callback->onAnimationEnd(m_fixture);
	}
}

void wyFixtureAnimation::invokeOnAborted() {
#if ANDROID
	if(m_jCallback != NULL) {
		JNIEnv* env = getEnv();
		if(env != NULL) {
			env->CallVoidMethod(m_jCallback, g_mid_FixtureAnimationCallback_onAnimationAborted, (jint)m_fixture);
		}
	} else 
#endif
	if(m_callback != NULL) {
		m_callback->onAnimationAborted(m_fixture);
	}
}

bool wyFixtureAnimation::releaseFrame(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

wyFixtureAnimation::~wyFixtureAnimation() {
	wyArrayEach(m_frames, releaseFrame, NULL);
	wyArrayDestroy(m_frames);

	if(m_timer != NULL) {
		wyScheduler::getInstance()->unscheduleLocked(m_timer);
		m_timer = NULL;

		invokeOnEnd();
	}

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

wyFixtureAnimation::wyFixtureAnimation() :
		m_frames(wyArrayNew(10)),
		m_fixture(NULL),
		m_timer(NULL),
		m_duration(0),
		m_frameTotalDuration(0),
		m_loop(false),
		m_elapsed(0),
#if ANDROID
		m_jCallback(NULL),
#endif
		m_callback(NULL) {
}

wyFixtureAnimation* wyFixtureAnimation::make(float duration, ...) {
	va_list ids;
	va_start(ids, duration);

	wyFixtureAnimation* anim = WYNEW wyFixtureAnimation();
	for(int id = va_arg(ids, int); id != 0; id = va_arg(ids, int)) {
		wyTexture2D* tex = wyTexture2D::makePNG(id);
		anim->addFrame(duration, tex);
	}

	va_end(ids);

	return (wyFixtureAnimation*)anim->autoRelease();
}

void wyFixtureAnimation::addFrame(float duration, wyTexture2D* tex) {
	wySpriteFrame* frame = wySpriteFrame::make(duration, tex);
	wyArrayPush(m_frames, frame);
	frame->retain();
	m_frameTotalDuration += duration;
	if(!m_loop)
		m_duration = m_frameTotalDuration;
}

wyBox2DRender* wyFixtureAnimation::getBox2DRender() {
	b2Body* body = m_fixture->GetBody();
	if(body != NULL) {
		b2World* world = body->GetWorld();
		if(world != NULL) {
			wyBox2D* box2d = world->GetBox2D();
			if(box2d != NULL) {
				return box2d->getBox2DRender();
			}
		}
	}

	return NULL;
}

void wyFixtureAnimation::update(wyTargetSelector* ts) {
	float delta = ts->getDelta();
	m_elapsed += delta;
	if(m_elapsed > m_duration) {
		wyScheduler::getInstance()->unscheduleLocked(m_timer);
		m_timer = NULL;

		invokeOnEnd();

		m_fixture->SetAnimation(NULL);
	} else {
		float remainder = ((long)(m_elapsed * 1000L) % (long)(m_frameTotalDuration * 1000L)) / 1000.f;
		int size = m_frames->num;
		for(int i = 0; i < size; i++) {
			wySpriteFrame* frame = (wySpriteFrame*)wyArrayGet(m_frames, i);
			remainder -= frame->getDuration();
			if(remainder < 0.f) {
				wyBox2DRender* render = getBox2DRender();
				if(render != NULL) {
					render->bindTexture(m_fixture, frame->getTexture(), frame->getRect());
				}
				break;
			}
		}
	}
}

void wyFixtureAnimation::start(b2Fixture* fixture) {
	this->m_fixture = fixture;
	fixture->SetAnimation(this);

    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyFixtureAnimation::update));
    m_timer = wyTimer::make(ts);
    wyScheduler::getInstance()->scheduleLocked(m_timer);
}

void wyFixtureAnimation::stop() {
	if(m_timer != NULL) {
		wyScheduler::getInstance()->unscheduleLocked(m_timer);
		m_timer = NULL;

		invokeOnAborted();
	}

	// clear binding texture
	wyBox2DRender* render = getBox2DRender();
	if(render != NULL)
		render->bindTexture(m_fixture, NULL);

	// clear animation in fixture
	m_fixture->SetAnimation(NULL);
}

void wyFixtureAnimation::setLoop(bool loop) {
	m_loop = loop;
	if(m_loop) {
		m_duration = MAX_FLOAT;
	} else {
		m_duration = m_frameTotalDuration;
	}
}

#if ANDROID
void wyFixtureAnimation::setJavaCallback(jobject callback) {
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
