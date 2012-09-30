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
#include "wyScaleTo.h"
#include "wyNode.h"

wyAction* wyScaleTo::copy() {
	return wyScaleTo::make(m_duration, m_startScaleX, m_startScaleY, m_endScaleX, m_endScaleY);
}

wyAction* wyScaleTo::reverse() {
	return wyScaleTo::make(m_duration, m_endScaleX, m_endScaleY, m_startScaleX, m_startScaleY);
}

void wyScaleTo::update(float t) {
	m_target->setScaleX(m_startScaleX + m_deltaX * t);
	m_target->setScaleY(m_startScaleY + m_deltaY * t);

	// super only call callback
	wyIntervalAction::update(t);
}

wyScaleTo::~wyScaleTo() {
}

void wyScaleTo::init(float startScaleX, float startScaleY, float endScaleX, float endScaleY) {
	m_startScaleX = startScaleX;
	m_startScaleY = startScaleY;
	m_endScaleX = endScaleX;
	m_endScaleY = endScaleY;
	m_deltaX = m_endScaleX - m_startScaleX;
	m_deltaY = m_endScaleY - m_startScaleY;
}

wyScaleTo::wyScaleTo(float duration, float startScaleX, float startScaleY, float endScaleX, float endScaleY) :
		wyIntervalAction(duration) {
	init(startScaleX, startScaleY, endScaleX, endScaleY);
}

wyScaleTo::wyScaleTo(float duration, float startScale, float endScale) :
		wyIntervalAction(duration) {
	init(startScale, startScale, endScale, endScale);
}

wyScaleTo* wyScaleTo::make(float duration, float startScaleX, float startScaleY, float endScaleX, float endScaleY) {
	wyScaleTo* a = WYNEW wyScaleTo(duration, startScaleX, startScaleY, endScaleX, endScaleY);
	return (wyScaleTo*)a->autoRelease();
}

wyScaleTo* wyScaleTo::make(float duration, float startScale, float endScale) {
	wyScaleTo* a = WYNEW wyScaleTo(duration, startScale, endScale);
	return (wyScaleTo*)a->autoRelease();
}
