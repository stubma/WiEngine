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
#include "wySpawn.h"
#include "wySequence.h"
#include "wyDelayTime.h"
#include "wyNode.h"
#include "wyLog.h"

wySpawn::~wySpawn() {
	wyObjectRelease(m_one);
	wyObjectRelease(m_two);
}

wyAction* wySpawn::copy() {
	return wySpawn::make((wyFiniteTimeAction*)m_one->copy(), (wyFiniteTimeAction*)m_two->copy());
}

wyAction* wySpawn::reverse() {
	return wySpawn::make((wyFiniteTimeAction*)m_one->reverse(), (wyFiniteTimeAction*)m_two->reverse());
}

void wySpawn::start(wyNode* target) {
	wyIntervalAction::start(target);
	m_one->start(target);
	m_two->start(target);
}

void wySpawn::stop() {
	m_one->stop();
	m_two->stop();
	wyIntervalAction::stop();
}

void wySpawn::update(float t) {
	// if t is 1, manually set elapsed time so isDone can return true
	if(t >= 1.0f) {
		m_one->setElapsed(m_one->getDuration());
		m_two->setElapsed(m_one->getDuration());
	}

	// deliver update
	m_one->update(t);
	m_two->update(t);

	// super only call callback
	wyIntervalAction::update(t);
}

wySpawn::wySpawn(wyFiniteTimeAction* one, wyFiniteTimeAction* two) : wyIntervalAction(MAX(one->getDuration(), two->getDuration())) {
	float d1 = one->getDuration();
	float d2 = two->getDuration();

	if(d1 > d2) {
		wyDelayTime* delay = wyDelayTime::make(d1 - d2);
		m_two = wySequence::make(two, delay, NULL);
		m_one = one;
		wyObjectRetain(m_one);
		wyObjectRetain(m_two);
	} else if(d1 < d2) {
		wyDelayTime* delay = wyDelayTime::make(d2 - d1);
		m_one = wySequence::make(one, delay, NULL);
		m_two = two;
		wyObjectRetain(m_one);
		wyObjectRetain(m_two);
	} else {
		m_one = one;
		m_two = two;
		wyObjectRetain(m_one);
		wyObjectRetain(m_two);
	}

	m_one->setParent(this);
	m_two->setParent(this);
}

wySpawn* wySpawn::make(wyFiniteTimeAction* one, wyFiniteTimeAction* two) {
	wySpawn* a = WYNEW wySpawn(one, two);
	return (wySpawn*)a->autoRelease();
}
