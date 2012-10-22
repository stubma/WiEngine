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
#include "wyBuffer.h"
#include "wyTypes.h"
#include "wyLog.h"
#include "wyUtils.h"

#define DEFAULT_CAPACITY 29

wyBuffer::wyBuffer(void* data, Format format, int capacity, int elements, int bytePerElement) :
		m_format(format),
		m_data(data),
		m_elements(elements),
		m_capacity(capacity),
		m_bytePerElement(bytePerElement) {
}

wyBuffer::~wyBuffer() {
	if(m_data)
		wyFree(m_data);
}

wyBuffer* wyBuffer::makeFloat(void* data, int elements) {
	wyBuffer* b = WYNEW wyBuffer(data, FLOAT, elements, elements, sizeof(float));
	return (wyBuffer*)b->autoRelease();
}

wyBuffer* wyBuffer::makeShort(void* data, int elements) {
	wyBuffer* b = WYNEW wyBuffer(data, UNSIGNED_SHORT, elements, elements, sizeof(unsigned short));
	return (wyBuffer*)b->autoRelease();
}

wyBuffer* wyBuffer::makeByte(void* data, int elements) {
	wyBuffer* b = WYNEW wyBuffer(data, UNSIGNED_BYTE, elements, elements, sizeof(unsigned char));
	return (wyBuffer*)b->autoRelease();
}

wyBuffer* wyBuffer::makeCustom(void* data, int elements, int bytePerElement) {
	wyBuffer* b = WYNEW wyBuffer(data, STRUCTURE, elements, elements, bytePerElement);
	return (wyBuffer*)b->autoRelease();
}

wyBuffer* wyBuffer::makeByte() {
	void* data = wyMalloc(DEFAULT_CAPACITY * sizeof(unsigned char));
	wyBuffer* b = WYNEW wyBuffer(data, UNSIGNED_BYTE, DEFAULT_CAPACITY, 0, sizeof(unsigned char));
	return (wyBuffer*)b->autoRelease();
}

wyBuffer* wyBuffer::makeFloat() {
	void* data = wyMalloc(DEFAULT_CAPACITY * sizeof(float));
	wyBuffer* b = WYNEW wyBuffer(data, FLOAT, DEFAULT_CAPACITY, 0, sizeof(float));
	return (wyBuffer*)b->autoRelease();
}

wyBuffer* wyBuffer::makeShort() {
	void* data = wyMalloc(DEFAULT_CAPACITY * sizeof(unsigned short));
	wyBuffer* b = WYNEW wyBuffer(data, UNSIGNED_SHORT, DEFAULT_CAPACITY, 0, sizeof(unsigned short));
	return (wyBuffer*)b->autoRelease();
}

wyBuffer* wyBuffer::makeCustom(int bytePerElement) {
	void* data = wyMalloc(DEFAULT_CAPACITY * bytePerElement);
	wyBuffer* b = WYNEW wyBuffer(data, STRUCTURE, DEFAULT_CAPACITY, 0, bytePerElement);
	return (wyBuffer*)b->autoRelease();
}

void wyBuffer::fill(void* data) {
	char* p = (char*)m_data;
	for(int i = 0; i < m_capacity; i++, p += m_bytePerElement) {
		memcpy(p, data, m_bytePerElement);
	}
	m_elements = m_capacity;
}

void wyBuffer::enlarge(int times) {
	m_capacity *= times;
	m_data = wyRealloc(m_data, m_capacity * m_bytePerElement);
}

void wyBuffer::reserve(int capacity) {
	if(m_capacity < capacity) {
		m_capacity = capacity;
		m_data = wyRealloc(m_data, m_capacity * m_bytePerElement);
	}
}

void wyBuffer::copy(wyBuffer* src) {
	// check data format
	if(src->getFormat() != m_format) {
		LOGW("wyBuffer::copy: two buffer has different data format");
		return;
	}

	// check element size if element is structure
	if(m_format == STRUCTURE && m_bytePerElement != src->getBytePerElement()) {
		LOGW("wyBuffer::copy: two buffer has different structure size");
		return;
	}

	// ensure capacity
	int minCapacity = src->getElementCount();
	while(m_capacity < minCapacity) {
		enlarge();
	}

	// copy data
	memcpy((char*)m_data, src->getData(), m_bytePerElement * src->getElementCount());

	// update elements
	m_elements = minCapacity;
}

void wyBuffer::append(wyBuffer* buf) {
	// check data format
	if(buf->getFormat() != m_format) {
		LOGW("wyBuffer::append: two buffer has different data format");
		return;
	}

	// check element size if element is structure
	if(m_format == STRUCTURE && m_bytePerElement != buf->getBytePerElement()) {
		LOGW("wyBuffer::append: two buffer has different structure size");
		return;
	}

	// ensure capacity
	int minCapacity = m_elements + buf->getElementCount();
	while(m_capacity < minCapacity) {
		enlarge();
	}

	// copy data
	memcpy((char*)m_data + m_elements * m_bytePerElement, buf->getData(), m_bytePerElement * buf->getElementCount());

	// update elements
	m_elements = minCapacity;
}

void wyBuffer::append(void* data, int elements) {
	// check data
	if(!data) {
		LOGW("wyBuffer::append: append get a null data");
		return;
	}

	// ensure capacity
	int minCapacity = m_elements + elements;
	while(m_capacity < minCapacity) {
		enlarge();
	}

	// copy data
	memcpy((char*)m_data + m_elements * m_bytePerElement, data, m_bytePerElement * elements);

	// update elements
	m_elements += elements;
}

void wyBuffer::insert(wyBuffer* buf, int index) {
	// check data format
	if(buf->getFormat() != m_format) {
		LOGW("wyBuffer::insert: two buffer has different data format");
		return;
	}

	// check element size if element is structure
	if(m_format == STRUCTURE && m_bytePerElement != buf->getBytePerElement()) {
		LOGW("wyBuffer::insert: two buffer has different structure size");
		return;
	}

	// ensure capacity
	int bufElements = buf->getElementCount();
	int minCapacity = m_elements + bufElements;
	while(m_capacity < minCapacity) {
		enlarge();
	}

	// first move data, then copy data
	char* start = (char*)m_data + index * m_bytePerElement;
	if(index < m_elements)
		memmove(start + bufElements * m_bytePerElement, start, (m_elements - index) * m_bytePerElement);
	memcpy(start, buf->getData(), m_bytePerElement * bufElements);

	// update elements
	m_elements = minCapacity;
}

void wyBuffer::insert(void* data, int elements, int index) {
	// check data
	if(!data) {
		LOGW("wyBuffer::insert: insert get a null data");
		return;
	}

	// check index
	if(index < 0 || index > m_elements) {
		LOGW("wyBuffer::insert: illegal insertion index");
		return;
	}

	// ensure capacity
	int minCapacity = m_elements + elements;
	while(m_capacity < minCapacity) {
		enlarge();
	}

	// first move data, then copy data
	char* start = (char*)m_data + index * m_bytePerElement;
	if(index < m_elements)
		memmove(start + elements * m_bytePerElement, start, (m_elements - index) * m_bytePerElement);
	memcpy(start, data, m_bytePerElement * elements);

	// update elements
	m_elements += elements;
}

void wyBuffer::update(void* data, int elements, int index) {
	// check data
	if(!data) {
		LOGW("wyBuffer::update: update get a null data");
		return;
	}

	// check index
	if(index < 0 || index > m_elements) {
		LOGW("wyBuffer::update: illegal update start index");
		return;
	}

	// ensure capacity
	int minCapacity = MAX(m_elements, index + elements);
	while(m_capacity < minCapacity) {
		enlarge();
	}

	// copy data
	char* start = (char*)m_data + index * m_bytePerElement;
	memcpy(start, data, m_bytePerElement * elements);

	// update elements
	m_elements = minCapacity;
}

void wyBuffer::clear() {
	m_elements = 0;
}

void wyBuffer::remove(int index) {
	if(index < m_elements - 1) {
		char* start = (char*)m_data + index * m_bytePerElement;
		memmove(start, start + m_bytePerElement, (m_elements - index - 1) * m_bytePerElement);
	} else if(index == m_elements - 1) {
		m_elements--;
	}
}

int wyBuffer::remove(int start, int count) {
	// basic validation
	if(start >= m_elements)
		return 0;
	if(start < 0)
		start = 0;
	if(start + count > m_elements)
		count = m_elements - start;

	// move
	int remaining = m_elements - start - count;
	if(remaining > 0) {
		memmove((char*)m_data + start * m_bytePerElement,
				(GLubyte*)m_data + (start + count) * m_bytePerElement,
				remaining * m_bytePerElement);
	}

	// adjust count
	m_elements -= count;

	// return actual removed element
	return count;
}

void* wyBuffer::elementAt(int index) {
	if(index < 0 || index >= m_elements)
		return NULL;
	else
		return (char*)m_data + index * m_bytePerElement;
}
