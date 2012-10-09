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
#include "wySkewBy.h"
#include "wyNode.h"
#include "wyLog.h"

wySkewBy::wySkewBy(float duration, float skewX, float skewY) :
		wyIntervalAction(duration),
		m_skewX(skewX),
		m_skewY(skewY) {
}

wySkewBy::~wySkewBy() {
}

wySkewBy* wySkewBy::make(float duration, float skewX, float skewY) {
	wySkewBy* s = WYNEW wySkewBy(duration, skewX, skewY);
	return (wySkewBy*)s->autoRelease();
}

wyAction* wySkewBy::copy() {
	return wySkewBy::make(m_duration, m_skewX, m_skewY);
}

wyAction* wySkewBy::reverse() {
	return wySkewBy::make(m_duration, -m_skewX, -m_skewY);
}

void wySkewBy::start(wyNode* target) {
	wyIntervalAction::start(target);
	m_startSkewX = target->getSkewX();
	m_startSkewY = target->getSkewY();
}

void wySkewBy::update(float t) {
	m_target->setSkewX(m_startSkewX + m_skewX * t);
	m_target->setSkewY(m_startSkewY + m_skewY * t);

	// super only call callback
	wyIntervalAction::update(t);
}
