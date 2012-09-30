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
#include "wyTintTo.h"
#include "wyNode.h"

wyAction* wyTintTo::copy() {
	return wyTintTo::make(m_duration, m_fromR, m_fromG, m_fromB, m_toR, m_toG, m_toB);
}

wyAction* wyTintTo::reverse() {
	return wyTintTo::make(m_duration,m_toR, m_toG, m_toB, m_fromR, m_fromG, m_fromB);
}

void wyTintTo::update(float t) {
	wyColor3B c = {
			m_fromR + m_deltaR * t,
			m_fromG + m_deltaG * t,
			m_fromB + m_deltaB * t
	};
	m_target->setColor(c);

	// super only call callback
	wyIntervalAction::update(t);
}

wyTintTo::~wyTintTo() {
}

wyTintTo::wyTintTo(float duration, int fromR, int fromG, int fromB, int toR, int toG, int toB) :
		wyIntervalAction(duration),
		m_fromR(fromR),
		m_fromG(fromG),
		m_fromB(fromB),
		m_toR(toR),
		m_toG(toG),
		m_toB(toB),
		m_deltaR(toR - fromR),
		m_deltaG(toG - fromG),
		m_deltaB(toB - fromB) {
}

wyTintTo* wyTintTo::make(float duration, int fromR, int fromG, int fromB, int toR, int toG, int toB) {
	wyTintTo* a = WYNEW wyTintTo(duration, fromR, fromG, fromB, toR, toG, toB);
	return (wyTintTo*)a->autoRelease();
}
