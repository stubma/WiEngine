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
#include "wyMemoryInputStream.h"
#include "wyMath.h"
#include <stdio.h>

wyMemoryInputStream::wyMemoryInputStream(char* buffer, size_t length, bool release) : 
        m_buffer(buffer),
        m_length(length),
        m_release(release),
        m_position(0) {
}

wyMemoryInputStream::~wyMemoryInputStream() {
    if(m_release) {
        if(m_buffer) {
            free(m_buffer);
        }
    }
}

wyMemoryInputStream* wyMemoryInputStream::make(char* buffer, size_t length, bool release) {
    wyMemoryInputStream* s = new wyMemoryInputStream(buffer, length, release);
    return (wyMemoryInputStream*)s->autoRelease();
}

char* wyMemoryInputStream::getBuffer() {
    return m_buffer;
}

size_t wyMemoryInputStream::getPosition() {
    return m_position;
}

size_t wyMemoryInputStream::getLength() {
    return m_length;
}

size_t wyMemoryInputStream::available() {
    return m_length - m_position;
}

void wyMemoryInputStream::close() {
    // do nothing
}

ssize_t wyMemoryInputStream::read(char* buffer, size_t length) {
    int canRead = MIN(length, available());
    memcpy(buffer, m_buffer + m_position, canRead);
    m_position += canRead;
    return canRead;
}

size_t wyMemoryInputStream::seek(int offset, int mode) {
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
