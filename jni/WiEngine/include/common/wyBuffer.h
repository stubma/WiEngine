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
#ifndef __wyBuffer_h__
#define __wyBuffer_h__

#include "wyObject.h"

/**
 * @class wyBuffer
 *
 * A \c wyBuffer is an objective representative of a data pointer
 */
class WIENGINE_API wyBuffer : public wyObject {
public:
	/**
	 * data format
	 */
	enum Format {
        /**
         * Single precision floating point.
         * 4 bytes, signed
         */
        FLOAT,

        /**
         * 1 byte integer, unsigned.
         */
        UNSIGNED_BYTE,

        /**
         * 2 byte integer, unsigned.
         */
        UNSIGNED_SHORT,

        /**
         * custom structure
         */
        STRUCTURE
	};

private:
	/// data format
	Format m_format;

	/// data pointer
	void* m_data;

	/// element count
	int m_elements;

	/// byte size of one element
	int m_bytePerElement;

	/// buffer capacity of element
	int m_capacity;

protected:
	/**
	 * Constructor
	 *
	 * @param data data buffer pointer
	 * @param format element format
	 * @param capacity buffer capacity to hold how many element
	 * @param elements element already exists in \c data
	 * @param bytePerElement byte size of one element
	 */
	wyBuffer(void* data, Format format, int capacity, int elements, int bytePerElement);

public:
	/**
	 * Create a data buffer whose element is float number
	 *
	 * @param data data with bytes
	 * @param elements element count in data buffer
	 * @return \link wyBuffer wyBuffer\endlink
	 */
	static wyBuffer* makeFloat(void* data, int elements);

	/**
	 * Create a data buffer whose element is short number
	 *
	 * @param data data with bytes
	 * @param elements element count in data buffer
	 * @return \link wyBuffer wyBuffer\endlink
	 */
	static wyBuffer* makeShort(void* data, int elements);

	/**
	 * Create a data buffer whose element is byte
	 *
	 * @param data data with bytes
	 * @param elements element count in data buffer
	 * @return \link wyBuffer wyBuffer\endlink
	 */
	static wyBuffer* makeByte(void* data, int elements);

	/**
	 * Create a buffer which contains structural element
	 *
	 * @param data data buffer pointer
	 * @param elements element count
	 * @param bytePerElement byte size of structure
	 * @return \link wyBuffer wyBuffer\endlink
	 */
	static wyBuffer* makeCustom(void* data, int elements, int bytePerElement);

	/**
	 * Create a default byte buffer
	 */
	static wyBuffer* makeByte();

	/**
	 * Create a default float buffer
	 */
	static wyBuffer* makeFloat();

	/**
	 * Create a default short buffer
	 */
	static wyBuffer* makeShort();

	/**
	 * Create a buffer whose element count is zero
	 *
	 * @param bytePerElement byte size of structure
	 * @return \link wyBuffer wyBuffer\endlink
	 */
	static wyBuffer* makeCustom(int bytePerElement);

	virtual ~wyBuffer();

	/**
	 * Enlarge buffer with specified times
	 *
	 * @param times times to be enlarged
	 */
	void enlarge(int times = 2);

	/**
	 * Allocate wanted space for this buffer. If this buffer is already larger than the capacity,
	 * then nothing to do.
	 *
	 * @param capacity the minimum capacity we want the buffer has
	 */
	void reserve(int capacity);

	/**
	 * Append other buffer to current buffer. Data format of two buffers must be
	 * matched otherwise nothing will be done. Current buffer will be enlarged if
	 * no enough memory to hold other buffer data
	 *
	 * @param buf buffer to be appended, data in this buffer will be copied to current
	 * 		buffer so it is safe to release it after returns.
	 */
	void append(wyBuffer* buf);

	/**
	 * Append data to this buffer, the data in buffer must be same format as this buffer
	 *
	 * @param data data buffer
	 * @param elements element count in \c data
	 */
	void append(void* data, int elements);

	/**
	 * Insert a buffer content into specified index
	 *
	 * @param buf buffer to be inserted. Data in buffer will be copied so it is safe
	 * 		to release it after returns
	 * @param index insertion point
	 */
	void insert(wyBuffer* buf, int index);

	/**
	 * Insert a data buffer into current buffer. The data to be inserted must have same
	 * format as current buffer
	 *
	 * @param data data buffer pointer
	 * @param elements element count in \c data
	 * @param index insertion index
	 */
	void insert(void* data, int elements, int index);

	/**
	 * Update a data buffer into current buffer. The data to be updated must have same
	 * format as current buffer
	 *
	 * @param data data buffer pointer
	 * @param elements element count in \c data
	 * @param index start update index
	 */
	void update(void* data, int elements, int index);

	/**
	 * Remove one element
	 *
	 * @param element index
	 */
	void remove(int index);

	/**
	 * Remove a range of element
	 *
	 * @param start start index to be removed from
	 * @param count how many element to be deleted
	 * @return element actually deleted
	 */
	int remove(int start, int count);

	/**
	 * Get element count in buffer
	 *
	 * @return element count
	 */
	int getElementCount() { return m_elements; }

	/**
	 * Get data format
	 *
	 * @return data format
	 */
	Format getFormat() { return m_format; }

	/**
	 * Get data pointer
	 *
	 * @return data pointer
	 */
	void* getData() { return m_data; }

	/**
	 * Get byte size of one element
	 *
	 * @return byte size of one element
	 */
	int getBytePerElement() { return m_bytePerElement; }

	/**
	 * get capacity of buffer which means how many elements it can hold
	 */
	int getCapacity() { return m_capacity; }

	/**
	 * Flag a buffer full, but doesn't fill it with actual data, just flag the element count
	 * is same as capacity
	 */
	void setFull() { m_elements = m_capacity; }

	/**
	 * True means this buffer is full
	 */
	bool isFull() { return m_elements >= m_capacity; }

	/**
	 * Manually set element count
	 */
	void setElementCount(int c) { m_elements = c; }

	/**
	 * Fill whole buffer with a specified element repeatly. So the element count
	 * will be set to capacity value
	 *
	 * @param data data buffer, the data in buffer must be an element
	 */
	void fill(void* data);

	/**
	 * Reset this buffer element count to zero
	 */
	void clear();

	/**
	 * Get pointer of a element
	 *
	 * @param index index of element
	 * @return pointer of element, or NULL if \c index is invalid
	 */
	void* elementAt(int index);

	/**
	 * Copy a buffer data into this buffer. So this buffer will contains same data
	 * as the source one. The source and destination buffer must have same element type.
	 *
	 * @param src source buffer to be copied
	 */
	void copy(wyBuffer* src);
};

#endif // __wyBuffer_h__
