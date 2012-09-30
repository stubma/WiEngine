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
#include "wyJumpBy.h"
#include "wyNode.h"
#include "wyLog.h"
#include <math.h>

wyJumpBy::~wyJumpBy() {
}

wyJumpBy::wyJumpBy(float duration, float x, float y, float height, int jumps) :
		wyIntervalAction(duration),
		m_startPosition(wypZero),
		m_delta(wyp(x, y)),
		m_height(height),
		m_jumps(jumps) {
}

wyJumpBy* wyJumpBy::make(float duration, float x, float y, float height, int jumps) {
	wyJumpBy* a = WYNEW wyJumpBy(duration, x, y, height, jumps);
	return (wyJumpBy*)a->autoRelease();
}

wyAction* wyJumpBy::copy() {
	return wyJumpBy::make(m_duration, m_delta.x, m_delta.y, m_height, m_jumps);
}

wyAction* wyJumpBy::reverse() {
	return wyJumpBy::make(m_duration, -m_delta.x, -m_delta.y, m_height, m_jumps);
}

void wyJumpBy::start(wyNode* target) {
    wyIntervalAction::start(target);
    m_startPosition.x = target->getPositionX();
    m_startPosition.y = target->getPositionY();
}

void wyJumpBy::update(float t) {
    float y = m_height * fabs(wyMath::sin(t * M_PI * m_jumps));
    y += m_delta.y * t;
    float x = m_delta.x * t;
    m_target->setPosition(m_startPosition.x + x, m_startPosition.y + y);

	// super only call callback
	wyIntervalAction::update(t);
}
