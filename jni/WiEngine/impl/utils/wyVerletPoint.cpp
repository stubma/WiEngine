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
#include "wyVerletPoint.h"

wyVerletPoint::wyVerletPoint() :
		m_x(0),
		m_y(0),
		m_oldX(0),
		m_oldY(0) {
}

wyVerletPoint::~wyVerletPoint() {
}

void wyVerletPoint::setPosition(float x, float y) {
	m_x = m_oldX = x;
	m_y = m_oldY = y;
}

void wyVerletPoint::update() {
	float tempX = m_x;
	float tempY = m_y;
	m_x += m_x - m_oldX;
	m_y += m_y - m_oldY;
	m_oldX = tempX;
	m_oldY = tempY;
}

void wyVerletPoint::applyGravity(float dt) {
	// 10 is gravity magic number
	m_y -= 10.f * dt;
}

void wyVerletPoint::attenuate(float percent) {
	float dx = m_x - m_oldX;
	float dy = m_y - m_oldY;
	m_oldX += dx * percent;
	m_oldY += dy * percent;
}

wyVerletPoint* wyVerletPoint::copy() {
	wyVerletPoint* p = WYNEW wyVerletPoint();
	p->m_x = m_x;
	p->m_y = m_y;
	p->m_oldX = m_oldX;
	p->m_oldY = m_oldY;
	p->autoRelease();
	return p;
}
