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
#include "wyClipOut.h"
#include "wyClipIn.h"
#include "wyTypes.h"
#include "wyNode.h"

wyClipOut::wyClipOut(float duration, Direction direction) :
		wyIntervalAction(duration),
		m_direction(direction) {
}

wyClipOut::~wyClipOut() {
}

wyClipOut* wyClipOut::make(float duration, Direction direction) {
	wyClipOut* c = WYNEW wyClipOut(duration, direction);
	return (wyClipOut*)c->autoRelease();
}

wyAction* wyClipOut::copy() {
	return wyClipOut::make(m_duration, m_direction);
}

wyAction* wyClipOut::reverse() {
	wyClipIn::Direction d;
	switch(m_direction) {
		case LEFT_TO_RIGHT:
			d = wyClipIn::RIGHT_TO_LEFT;
			break;
		case RIGHT_TO_LEFT:
			d = wyClipIn::LEFT_TO_RIGHT;
			break;
		case TOP_TO_BOTTOM:
			d = wyClipIn::BOTTOM_TO_TOP;
			break;
		case BOTTOM_TO_TOP:
			d = wyClipIn::TOP_TO_BOTTOM;
			break;
	}

	return wyClipIn::make(m_duration, d);
}

void wyClipOut::update(float t) {
	// max clip rect
	wyRect r = {
			0,
			0,
			m_target->getWidth(),
			m_target->getHeight()
	};

	// decide clip rect
	switch(m_direction) {
		case LEFT_TO_RIGHT:
			r.x = r.width * t;
			break;
		case RIGHT_TO_LEFT:
			r.width = r.width * (1 - t);
			break;
		case TOP_TO_BOTTOM:
			r.height = r.height * (1 - t);
			break;
		case BOTTOM_TO_TOP:
			r.y = r.height * t;
			break;
	}

	// set new clip rect
	m_target->setClipRect(r, true);

	// super only call callback
	wyIntervalAction::update(t);
}

void wyClipOut::stop() {
	m_target->setClipRect(wyrZero, true);

	wyIntervalAction::stop();
}

void wyClipOut::start(wyNode* target) {
	wyIntervalAction::start(target);

	target->clearClipRect();
}
