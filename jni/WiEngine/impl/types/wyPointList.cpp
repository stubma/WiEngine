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
#include "wyTypes.h"
#include "wyPointList.h"
#include "wyLog.h"

wyPointList::wyPointList() :
		m_capacity(10),
		m_count(0) {
	m_buffer = (wyPoint*)wyMalloc(m_capacity * sizeof(wyPoint));
}

wyPointList::~wyPointList() {
	wyFree(m_buffer);
}

void wyPointList::addPoint(float x, float y) {
	while(m_count >= m_capacity) {
		m_capacity *= 2;
		m_buffer = (wyPoint*)wyRealloc(m_buffer, m_capacity * sizeof(wyPoint));
	}

	m_buffer[m_count].x = x;
	m_buffer[m_count].y = y;
	m_count++;
}

void wyPointList::addPoints(wyPointList& plist) {
	while(m_count + plist.getCount() >= m_capacity) {
		m_capacity *= 2;
		m_buffer = (wyPoint*)wyRealloc(m_buffer, m_capacity * sizeof(wyPoint));
	}

	memcpy(m_buffer + m_count * sizeof(wyPoint), plist.getBuffer(), plist.getCount() * sizeof(wyPoint));
	m_count += plist.getCount();
}

void wyPointList::clear() {
	m_count = 0;
}

void wyPointList::deletePointAt(int index) {
	if(index < 0 || index >= m_count)
		return;

	if(index == m_count - 1) {
		m_count--;
	} else {
		memmove(m_buffer + index * sizeof(wyPoint), m_buffer + (index + 1) * sizeof(wyPoint), (m_count - index - 1) * sizeof(wyPoint));
		m_count--;
	}
}

wyPoint wyPointList::getPointAt(int index) {
	if(m_buffer) {
		if(index < 0 || index >= m_count)
			return wypZero;
		else
			return m_buffer[index];
	} else {
		return wypZero;
	}
}
