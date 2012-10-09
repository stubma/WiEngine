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
#include "wyHypotrochoid.h"
#include "wyTypes.h"
#include "wyNode.h"

wyHypotrochoid::~wyHypotrochoid() {
}

wyHypotrochoid::wyHypotrochoid(float duration, wyHypotrochoidConfig c) :
		wyIntervalAction(duration),
		m_config(c),
		m_pinPoint(wyp(MAX_FLOAT, MAX_FLOAT)),
		m_pinDelta(0),
		m_autoRotate(false),
		m_angleDelta(0) {
}

wyHypotrochoid* wyHypotrochoid::make(float duration, wyHypotrochoidConfig c) {
	wyHypotrochoid* a = WYNEW wyHypotrochoid(duration, c);
	return (wyHypotrochoid*)a->autoRelease();
}

wyAction* wyHypotrochoid::copy() {
	wyHypotrochoid* h = wyHypotrochoid::make(m_duration, m_config);
	h->setAutoRotate(m_autoRotate, m_angleDelta);
	h->setPinAngleDelta(m_pinDelta);
	h->setPinPoint(m_pinPoint);
	return h;
}

wyAction* wyHypotrochoid::reverse() {
	wyHypotrochoid* h = wyHypotrochoid::make(m_duration, m_config);
	h->setAutoRotate(m_autoRotate, 180 - m_angleDelta);
	h->setPinAngleDelta(m_pinDelta);
	h->setPinPoint(m_pinPoint);
	return h;
}

void wyHypotrochoid::update(float t) {
	wyPoint p = wyhcPointAt(m_config, t);
	m_target->setPosition(p.x, p.y);

	// check direction
	if(m_autoRotate) {
		wyPoint p2 = wyhcPointAt(m_config, t + 0.016f);
		wyPoint d = wypSub(p2, p);
		float angle = -wypToDegree(d);
		angle += m_angleDelta;
		m_target->setRotation(angle);
	} else if(m_pinPoint.x != MAX_FLOAT && m_pinPoint.y != MAX_FLOAT) {
		wyPoint anchor = wyp(m_target->getAnchorPointX(), m_target->getAnchorPointY());
		anchor = m_target->nodeToWorldSpace(anchor);
		float angle = wypToDegree(wypSub(m_pinPoint, anchor));
		m_target->setRotation(-angle + m_pinDelta);
	}

	// super only call callback
	wyIntervalAction::update(t);
}

void wyHypotrochoid::setAutoRotate(bool flag, float angleDelta) {
	m_autoRotate = flag;
	m_angleDelta = angleDelta;
}
