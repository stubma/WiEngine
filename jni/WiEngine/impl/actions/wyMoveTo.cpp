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
#include "wyMoveTo.h"
#include "wyNode.h"

wyMoveTo::~wyMoveTo() {
}

wyMoveTo::wyMoveTo(float duration, float startX, float startY, float endX, float endY) :
		wyIntervalAction(duration),
		m_endX(endX),
		m_endY(endY),
		m_startX(startX),
		m_startY(startY),
		m_pinPoint(wyp(MAX_FLOAT, MAX_FLOAT)),
		m_pinDelta(0),
		m_deltaX(endX - startX),
		m_deltaY(endY - startY) {
}

wyMoveTo* wyMoveTo::make(float duration, float startX, float startY, float endX, float endY) {
	wyMoveTo* a = WYNEW wyMoveTo(duration, startX, startY, endX, endY);
	return (wyMoveTo*)a->autoRelease();
}

wyAction* wyMoveTo::copy() {
	wyMoveTo* m = wyMoveTo::make(m_duration, m_startX, m_startY, m_endX, m_endY);
	m->setPinAngleDelta(m_pinDelta);
	m->setPinPoint(m_pinPoint);
	return m;
}

wyAction* wyMoveTo::reverse() {
	wyMoveTo* m = wyMoveTo::make(m_duration, m_endX, m_endY, m_startX, m_startY);
	m->setPinAngleDelta(m_pinDelta);
	m->setPinPoint(m_pinPoint);
	return m;
}

void wyMoveTo::update(float t) {
	m_target->setPosition(m_startX + m_deltaX * t, m_startY + m_deltaY * t);

	// check pin point
	if(m_pinPoint.x != MAX_FLOAT && m_pinPoint.y != MAX_FLOAT) {
		wyPoint anchor = wyp(m_target->getAnchorPointX(), m_target->getAnchorPointY());
		anchor = m_target->nodeToWorldSpace(anchor);
		float angle = wypToDegree(wypSub(m_pinPoint, anchor));
		m_target->setRotation(-angle + m_pinDelta);
	}

	// super only call callback
	wyIntervalAction::update(t);
}
