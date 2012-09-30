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
#include "wyVerletStick.h"
#include "wyTypes.h"
#include "wyLog.h"

wyVerletStick::wyVerletStick(wyVerletPoint* a, wyVerletPoint* b) :
		m_pointA(a),
		m_pointB(b),
		m_length(0),
		m_currentLength(0) {
	a->retain();
	b->retain();
	m_length = wypDistance(wyp(a->m_x, a->m_y), wyp(b->m_x, b->m_y));
	m_currentLength = m_length;
}

wyVerletStick::~wyVerletStick() {
	m_pointA->release();
	m_pointB->release();
}

void wyVerletStick::setLength(float length) {
	m_length = length;
	m_currentLength = length;
}

void wyVerletStick::contract(bool reverse) {
	float dx = m_pointB->m_x - m_pointA->m_x;
	float dy = m_pointB->m_y - m_pointA->m_y;
	float h = wypDistance(wyp(m_pointA->m_x, m_pointA->m_y), wyp(m_pointB->m_x, m_pointB->m_y));
	float diff = m_length - h;
	float offx = diff * dx / h;
	float offy = diff * dy / h;
	if(reverse) {
		m_pointA->m_x -= offx;
		m_pointA->m_y -= offy;
	} else {
		m_pointB->m_x += offx;
		m_pointB->m_y += offy;
	}
	m_currentLength = wypDistance(wyp(m_pointA->m_x, m_pointA->m_y), wyp(m_pointB->m_x, m_pointB->m_y));
}
