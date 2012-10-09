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
#include "wyScaleBy.h"
#include "wyNode.h"

wyAction* wyScaleBy::copy() {
	return wyScaleBy::make(m_duration, m_deltaX, m_deltaY);
}

wyAction* wyScaleBy::reverse() {
	return wyScaleBy::make(m_duration, 1 / m_deltaX, 1 / m_deltaY);
}

void wyScaleBy::update(float t) {
	m_target->setScaleX(m_startScaleX + (m_endScaleX - m_startScaleX) * t);
	m_target->setScaleY(m_startScaleY + (m_endScaleY - m_startScaleY) * t);

	// super only call callback
	wyIntervalAction::update(t);
}

void wyScaleBy::start(wyNode* target) {
	wyIntervalAction::start(target);

	m_startScaleX = target->getScaleX();
	m_startScaleY = target->getScaleY();
	m_endScaleX = m_startScaleX * m_deltaX;
	m_endScaleY = m_startScaleY * m_deltaY;
}

wyScaleBy::~wyScaleBy() {
}

wyScaleBy::wyScaleBy(float duration, float scaleX, float scaleY) : wyIntervalAction(duration) {
	m_deltaX = scaleX;
	m_deltaY = scaleY;
}

wyScaleBy::wyScaleBy(float duration, float scale) : wyIntervalAction(duration) {
	m_deltaX = scale;
	m_deltaY = scale;
}

wyScaleBy* wyScaleBy::make(float duration, float scaleX, float scaleY) {
	wyScaleBy* a = WYNEW wyScaleBy(duration, scaleX, scaleY);
	return (wyScaleBy*)a->autoRelease();
}

wyScaleBy* wyScaleBy::make(float duration, float scale) {
	wyScaleBy* a = WYNEW wyScaleBy(duration, scale);
	return (wyScaleBy*)a->autoRelease();
}
