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
#include "wyJumpTo.h"
#include "wyNode.h"
#include "wyLog.h"
#include <math.h>

wyAction* wyJumpTo::copy() {
	return wyJumpTo::make(m_duration, m_startX, m_startY, m_endX, m_endY, m_height, m_jumps);
}

wyAction* wyJumpTo::reverse() {
	return wyJumpTo::make(m_duration, m_endX, m_endY, m_startX, m_startY, m_height, m_jumps);
}

void wyJumpTo::update(float t) {
    float y = m_height * fabs(wyMath::sin(t * M_PI * m_jumps));
    y += m_deltaY * t;
    float x = m_deltaX * t;
    m_target->setPosition(m_startX + x, m_startY + y);

	// super only call callback
	wyIntervalAction::update(t);
}

wyJumpTo::~wyJumpTo() {
}

wyJumpTo::wyJumpTo(float duration, float startX, float startY, float endX, float endY, float height, int jumps) :
		wyIntervalAction(duration),
		m_startX(startX),
		m_startY(startY),
		m_endX(endX),
		m_endY(endY),
		m_deltaX(endX - startX),
		m_deltaY(endY - startY),
		m_height(height),
		m_jumps(jumps) {
}

wyJumpTo* wyJumpTo::make(float duration, float startX, float startY, float endX, float endY, float height, int jumps) {
	wyJumpTo* a = WYNEW wyJumpTo(duration, startX, startY, endX, endY, height, jumps);
	return (wyJumpTo*)a->autoRelease();
}
