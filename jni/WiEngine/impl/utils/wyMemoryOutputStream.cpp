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
#include "wyMemoryOutputStream.h"
#include "wyMath.h"
#include <stdio.h>

wyMemoryOutputStream::wyMemoryOutputStream(char* buffer, size_t capacity, bool release) :
		m_buffer(buffer),
		m_capacity(capacity),
		m_length(0),
		m_position(0),
		m_release(release) {
}

wyMemoryOutputStream::~wyMemoryOutputStream() {
	if(m_release) {
		wyFree((void*)m_buffer);
	}
}

wyMemoryOutputStream* wyMemoryOutputStream::make() {
	char* buffer = (char*)wyMalloc(64 * 1024 * sizeof(char));
	wyMemoryOutputStream* s = WYNEW wyMemoryOutputStream(buffer, 64 * 1024, true);
	return (wyMemoryOutputStream*)s->autoRelease();
}

wyMemoryOutputStream* wyMemoryOutputStream::make(size_t capacity, bool release) {
	char* buffer = (char*)wyMalloc(capacity);
	wyMemoryOutputStream* s = WYNEW wyMemoryOutputStream(buffer, capacity, release);
	return (wyMemoryOutputStream*)s->autoRelease();
}

void wyMemoryOutputStream::ensureCapacity(size_t len) {
	if(m_position + len > m_capacity - 1) {
		m_capacity = (m_position + len) * 2;
		m_buffer = (char*)wyRealloc(m_buffer, m_capacity * sizeof(char));
	}
}

ssize_t wyMemoryOutputStream::write(const char* data, size_t len) {
	ensureCapacity(len);
	memcpy(m_buffer + m_position, data, len);
	m_position += len;
	m_length = MAX(m_position, m_length);
	return len;
}

ssize_t wyMemoryOutputStream::write(const int* data, size_t len) {
	ensureCapacity(len * sizeof(int));
	memcpy(m_buffer + m_position, data, len * sizeof(int));
	m_position += len * sizeof(int);
	m_length = MAX(m_position, m_length);
	return len;
}

size_t wyMemoryOutputStream::getPosition() {
	return m_position;
}

void wyMemoryOutputStream::reset() {
	m_position = 0;
	m_length = 0;
}

size_t wyMemoryOutputStream::seek(int offset, int mode) {
    switch(mode) {
        case SEEK_CUR:
            m_position = CLAMP(m_position + offset, 0, m_length);
            break;
        case SEEK_END:
            m_position = CLAMP(m_length + offset, 0, m_length);
            break;
        case SEEK_SET:
            m_position = CLAMP(offset, 0, m_length);
            break;
    }

	return m_position;
}

const char* wyMemoryOutputStream::getBuffer() {
	// end position as a c string
	m_buffer[m_position] = 0;
	return m_buffer;
}
