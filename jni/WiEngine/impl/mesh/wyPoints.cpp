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
#include "wyPoints.h"
#include "wyAttribute.h"

wyPoints::wyPoints() {
	m_mode = POINTS;

	// create buffer
	m_buf = wyBuffer::makeCustom(sizeof(Vertex));

	// connect attribute
	connectAttribute(wyAttribute::NAME[wyAttribute::POSITION], m_buf, 0, 3);
	connectAttribute(wyAttribute::NAME[wyAttribute::COLOR], m_buf, sizeof(kmVec3) + sizeof(kmVec2), 4);
}

wyPoints::~wyPoints() {
}

wyPoints* wyPoints::make() {
	wyPoints* p = WYNEW wyPoints();
	return (wyPoints*)p->autoRelease();
}

int wyPoints::getElementCount() {
	return m_buf->getElementCount();
}

void wyPoints::addPoint(float x, float y, float z, wyColor4B c) {
	Vertex v;
	kmVec4Fill(&v.color, c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
	kmVec3Fill(&v.pos, x, y, z);
	m_buf->append(&v, 1);
}
