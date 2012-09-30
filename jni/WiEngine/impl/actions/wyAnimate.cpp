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
#include "wyAnimate.h"
#include "wyNode.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyAnimation.h"
#include "wySprite.h"

wyAnimate::wyAnimate(wyAnimation* anim, bool fillAfter) :
		wyIntervalAction(anim->getDuration()),
		m_anim(anim),
		m_originFrame(NULL),
		m_originFrameSaved(false),
		m_fillAfter(fillAfter) {
	wyObjectRetain(anim);
}

wyAnimate::~wyAnimate() {
	wyObjectRelease(m_originFrame);
	wyObjectRelease(m_anim);
}

wyAnimate* wyAnimate::make(wyAnimation* anim, bool fillAfter) {
	wyAnimate* a = WYNEW wyAnimate(anim, fillAfter);
	return (wyAnimate*)a->autoRelease();
}

wyAction* wyAnimate::copy() {
	return wyAnimate::make(m_anim, m_fillAfter);
}

wyAction* wyAnimate::reverse() {
	return wyAnimate::make(m_anim, m_fillAfter);
}

void wyAnimate::update(float t) {
	int idx = -1;

	// find current frame
	wyArray* frames = m_anim->getFrames();
	int count = frames->num;
	float animTime = t * m_anim->getDuration();
	float frameTime = 0;
	for(int i = 0; i < count; i++) {
		if(animTime >= frameTime) {
			wyFrame* frame = (wyFrame*)wyArrayGet(frames, i);
			frameTime += frame->getDuration();
		} else {
			idx = i - 1;
			break;
		}
	}

	// if not found, set to last frame
	if(idx == -1)
		idx = count - 1;

	// set current frame
	wyFrame* frame = (wyFrame*)wyArrayGet(frames, idx);
	if(!m_target->isFrameDisplayed(frame)) {
		m_target->setDisplayFrame(frame);

		// notify callback
		m_anim->notifyAnimationFrameChanged(idx);
	}

	// super only call callback
	wyIntervalAction::update(t);
    
    // end if elapsed >= duration
    if (isDone()) {
        m_anim->notifyAnimationEnded();
    }
}

void wyAnimate::start(wyNode* target) {
	wyIntervalAction::start(target);

	// get current frame and hold it
    if(!m_originFrameSaved) {
        m_originFrame = target->getDisplayFrame();
        wyObjectRetain(m_originFrame);
        m_originFrameSaved = true;
    }
}

void wyAnimate::stop() {
	if(!m_fillAfter && m_target) {
		if(!m_parent || m_parent->isDone() || !m_parent->isRunning())
			m_target->setDisplayFrame(m_originFrame);
	}

	wyIntervalAction::stop();
}
