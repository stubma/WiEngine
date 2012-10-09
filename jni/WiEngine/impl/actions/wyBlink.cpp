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
#include "wyBlink.h"
#include "wyNode.h"

wyAction* wyBlink::copy() {
	return wyBlink::make(m_duration, m_times);
}

wyAction* wyBlink::reverse() {
	return copy();
}

void wyBlink::update(float t) {
    float slice = 1.0f / m_times;
    float m = t - (int)(t / slice) * slice;
    m_target->setVisible((m > slice / 2) ? true : false);

	// super only call callback
	wyIntervalAction::update(t);
}

void wyBlink::stop() {
	m_target->setVisible(true);
	wyIntervalAction::stop();
}

wyBlink::wyBlink(float duration, float times) : wyIntervalAction(duration), m_times(times) {
}

wyBlink::~wyBlink() {
}

wyBlink* wyBlink::make(float duration, float times) {
	wyBlink* a = WYNEW wyBlink(duration, times);
	return (wyBlink*)a->autoRelease();
}
