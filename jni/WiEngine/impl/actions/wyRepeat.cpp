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
#include "wyRepeat.h"
#include "wyNode.h"

wyRepeat::wyRepeat(wyFiniteTimeAction* other, int times) :
		wyIntervalAction(other->getDuration() * times),
		m_times(times),
		m_other(other),
		m_total(0) {
	wyObjectRetain(m_other);
	m_other->setParent(this);
}

wyRepeat::~wyRepeat() {
	wyObjectRelease(m_other);
}

wyRepeat* wyRepeat::make(wyFiniteTimeAction* other, int times) {
	wyRepeat* repeat = WYNEW wyRepeat(other, times);
	return (wyRepeat*)repeat->autoRelease();
}

wyAction* wyRepeat::copy() {
	return wyRepeat::make((wyFiniteTimeAction*)m_other->copy(), m_times);
}

wyAction* wyRepeat::reverse() {
	return wyRepeat::make((wyFiniteTimeAction*)m_other->reverse(), m_times);
}

void wyRepeat::start(wyNode* target) {
	m_total = 0;
    wyIntervalAction::start(target);
    m_other->start(target);
}

void wyRepeat::stop() {
	m_other->stop();
    wyIntervalAction::stop();
}

void wyRepeat::update(float dt) {
	// Instead of hooking step:, hook update: since it can be called by any
	// container action like Repeat, Sequence, etc..
    float t = dt * m_times;
    float r = t - (int)(t / 1);
    if (t > m_total + 1) {
    	m_other->update(1.0f);
    	m_total++;
    	m_other->setElapsed(m_other->getDuration());
        m_other->stop();
        m_other->start(m_target);

    	/**
    	 * when action is done, update is called with 1.0f.
    	 * If we don't set firstTick to false, next frame will
    	 * be updated with 0.0f so it is same as 1.0f. This makes
    	 * a stop feeling at the beginning of action. Also remember
    	 * reset elapsed to zero because it is only set when firstTick
    	 * is true.
    	 */
    	m_other->m_firstTick = false;
    	m_other->setElapsed(0);
    } else {
        // fix last repeat position
        // else it could be 0.
        if (dt == 1.0f) {
        	m_total++;
        	r = 1.0f;
        }
        m_other->update(MIN(r, 1));
    }

	// super only call callback
	wyIntervalAction::update(dt);
}

bool wyRepeat::isDone() {
	return m_total == m_times;
}
