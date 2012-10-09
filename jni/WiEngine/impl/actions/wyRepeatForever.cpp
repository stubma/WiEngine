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
#include "wyRepeatForever.h"
#include "wyNode.h"

wyRepeatForever* wyRepeatForever::make(wyIntervalAction* other) {
	wyRepeatForever* rf = WYNEW wyRepeatForever(other);
	return (wyRepeatForever*)rf->autoRelease();
}

wyRepeatForever::~wyRepeatForever() {
	wyObjectRelease(m_other);
}

wyAction* wyRepeatForever::copy() {
	return wyRepeatForever::make((wyIntervalAction*)m_other->copy());
}

wyAction* wyRepeatForever::reverse() {
	return wyRepeatForever::make((wyIntervalAction*)m_other->reverse());
}

void wyRepeatForever::start(wyNode* target) {
	wyAction::start(target);
	m_other->start(target);
}

void wyRepeatForever::stop() {
	wyAction::stop();
	m_other->stop();
}

void wyRepeatForever::step(float t) {
	m_other->step(t);
    if (m_other->isDone()) {
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
    }
}

void wyRepeatForever::update(float t) {
	// do nothing
}

bool wyRepeatForever::isDone() {
	// it is repeat forever, so no end
    return false;
}

wyRepeatForever::wyRepeatForever(wyIntervalAction* other) : m_other(other) {
	wyObjectRetain(m_other);
	m_other->setParent(this);
}
