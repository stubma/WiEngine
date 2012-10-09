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
 * \if English
 * A \c wyBuffer is an objective representative of a data pointer
 * \else
 * \c wyBuffer是一个对数据指针的对象形式封装
 * \endif
 */
class WIENGINE_API wyBuffer : public wyObject {
public:
	/**
	 * \if English
	 * data format
	 * \else
	 * 数据格式
	 * \endif
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
	 * \if English
	 * Create a data buffer whose element is float number
	 *
	 * @param data data with bytes
	 * @param elements element count in data buffer
	 * @return \link wyBuffer wyBuffer\endlink
	 * \else
	 * 创建一个浮点数据缓冲区
	 *
	 * @param data 数据缓冲区指针
	 * @param elements 缓冲区中的元素个数
	 * @return \link wyBuffer wyBuffer\endlink
	 * \endif
	 */
	static wyBuffer* makeFloat(void* data, int elements);

	/**
	 * \if English
	 * Create a data buffer whose element is short number
	 *
	 * @param data data with bytes
	 * @param elements element count in data buffer
	 * @return \link wyBuffer wyBuffer\endlink
	 * \else
	 * 创建一个短整形数据缓冲区
	 *
	 * @param data 数据缓冲区指针
	 * @param elements 缓冲区中的元素个数
	 * @return \link wyBuffer wyBuffer\endlink
	 * \endif
	 */
	static wyBuffer* makeShort(void* data, int elements);

	/**
	 * \if English
	 * Create a data buffer whose element is byte
	 *
	 * @param data data with bytes
	 * @param elements element count in data buffer
	 * @return \link wyBuffer wyBuffer\endlink
	 * \else
	 * 创建一个字节数据缓冲区
	 *
	 * @param data 数据缓冲区指针
	 * @param elements 缓冲区中的元素个数
	 * @return \link wyBuffer wyBuffer\endlink
	 * \endif
	 */
	static wyBuffer* makeByte(void* data, int elements);

	/**
	 * \if English
	 * Create a buffer which contains structural element
	 *
	 * @param data data buffer pointer
	 * @param elements element count
	 * @param bytePerElement byte size of structure
	 * @return \link wyBuffer wyBuffer\endlink
	 * \else
	 * 创建一个数据缓冲区, 缓冲区的元素是自定义的结构体
	 *
	 * @param data 数据缓冲区
	 * @param elements 缓冲区中的元素个数
	 * @param bytePerElement 结构体的字节数
	 * @return \link wyBuffer wyBuffer\endlink
	 * \endif
	 */
	static wyBuffer* makeCustom(void* data, int elements, int bytePerElement);

	/**
	 * \if English
	 * Create a default byte buffer
	 * \else
	 * 创建一个缺省的unsigned char类型缓冲区
	 * \endif
	 */
	static wyBuffer* makeByte();

	/**
	 * \if English
	 * Create a default float buffer
	 * \else
	 * 创建一个缺省的float类型缓冲区
	 * \endif
	 */
	static wyBuffer* makeFloat();

	/**
	 * \if English
	 * Create a default short buffer
	 * \else
	 * 创建一个缺省的short类型缓冲区
	 * \endif
	 */
	static wyBuffer* makeShort();

	/**
	 * \if English
	 * Create a buffer whose element count is zero
	 *
	 * @param bytePerElement byte size of structure
	 * @return \link wyBuffer wyBuffer\endlink
	 * \else
	 * 创建一个数据缓冲区, 初始元素为0
	 *
	 * @param bytePerElement 结构体的字节数
	 * @return \link wyBuffer wyBuffer\endlink
	 * \endif
	 */
	static wyBuffer* makeCustom(int bytePerElement);

	virtual ~wyBuffer();

	/**
	 * \if English
	 * Enlarge buffer with specified times
	 *
	 * @param times times to be enlarged
	 * \else
	 * 扩大缓冲区容量
	 *
	 * @param times 扩大的倍数, 缺省是2倍
	 * \endif
	 */
	void enlarge(int times = 2);

	/**
	 * \if English
	 * Append other buffer to current buffer. Data format of two buffers must be
	 * matched otherwise nothing will be done. Current buffer will be enlarged if
	 * no enough memory to hold other buffer data
	 *
	 * @param buf buffer to be appended, data in this buffer will be copied to current
	 * 		buffer so it is safe to release it after returns.
	 * \else
	 * 将其它缓冲区的数据追加到当前缓冲区. 两个缓冲区的数据格式必须相同, 否则不做任何操作. 如果
	 * 当前缓冲区容量不够, 则会自动扩大
	 *
	 * @param buf 要追加的缓冲区, 该缓冲区数据将被拷贝到当前缓冲区, 因此追加之后可以释放.
	 * \endif
	 */
	void append(wyBuffer* buf);

	/**
	 * \if English
	 * Append data to this buffer, the data in buffer must be same format as this buffer
	 *
	 * @param data data buffer
	 * @param elements element count in \c data
	 * \else
	 * 追加一段数据到缓冲区, 数据中的格式比如和该缓冲区格式相同
	 *
	 * @param data 数据
	 * @param elements \c data中的数据元素个数
	 * \endif
	 */
	void append(void* data, int elements);

	/**
	 * \if English
	 * Insert a buffer content into specified index
	 *
	 * @param buf buffer to be inserted. Data in buffer will be copied so it is safe
	 * 		to release it after returns
	 * @param index insertion point
	 * \else
	 * 在指定元素位置处插入其它缓冲区内容
	 *
	 * @param buf 要插入的缓冲区, 该缓冲区数据将被拷贝到当前缓冲区, 因此插入之后可以释放.
	 * @param index 插入的元素位置
	 * \endif
	 */
	void insert(wyBuffer* buf, int index);

	/**
	 * \if English
	 * Insert a data buffer into current buffer. The data to be inserted must have same
	 * format as current buffer
	 *
	 * @param data data buffer pointer
	 * @param elements element count in \c data
	 * @param index insertion index
	 * \else
	 * 插入一段数据到缓冲区中, 要插入的数据必须具有和当前缓冲区相同的数据格式
	 *
	 * @param data 要插入的数据
	 * @param elements \c data中的元素个数
	 * @param index 插入点
	 * \endif
	 */
	void insert(void* data, int elements, int index);

	/**
	 * \if English
	 * Update a data buffer into current buffer. The data to be updated must have same
	 * format as current buffer
	 *
	 * @param data data buffer pointer
	 * @param elements element count in \c data
	 * @param index start update index
	 * \else
	 * 更新一段数据到缓冲区中, 要更新的数据必须具有和当前缓冲区相同的数据格式
	 *
	 * @param data 要更新的数据
	 * @param elements \c data中的元素个数
	 * @param index 更新的起始元素索引
	 * \endif
	 */
	void update(void* data, int elements, int index);

	/**
	 * \if English
	 * Remove one element
	 *
	 * @param element index
	 * \else
	 * 删除一个元素
	 *
	 * @param index 元素索引
	 * \endif
	 */
	void remove(int index);

	/**
	 * \if English
	 * Remove a range of element
	 *
	 * @param start start index to be removed from
	 * @param count how many element to be deleted
	 * @return element actually deleted
	 * \else
	 * 删除指定范围内的元素
	 *
	 * @param start 起始索引
	 * @param count 删除总数
	 * @return 实际删除的数量
	 * \endif
	 */
	int remove(int start, int count);

	/**
	 * \if English
	 * Get element count in buffer
	 *
	 * @return element count
	 * \else
	 * 得到缓冲区中的元素个数, 比如缓冲区的类型是浮点数, 那么一个元素就是一个浮点数
	 *
	 * @return 元素个数
	 * \endif
	 */
	int getElementCount() { return m_elements; }

	/**
	 * \if English
	 * Get data format
	 *
	 * @return data format
	 * \else
	 * 得到数据类型
	 *
	 * @return 数据类型
	 * \endif
	 */
	Format getFormat() { return m_format; }

	/**
	 * \if English
	 * Get data pointer
	 *
	 * @return data pointer
	 * \else
	 * 得到数据指针
	 *
	 * @return 数据指针
	 * \endif
	 */
	void* getData() { return m_data; }

	/**
	 * \if English
	 * Get byte size of one element
	 *
	 * @return byte size of one element
	 * \else
	 * 得到一个元素的字节数
	 *
	 * @return 一个元素的字节数
	 * \endif
	 */
	int getBytePerElement() { return m_bytePerElement; }

	/**
	 * \if English
	 * get capacity of buffer which means how many elements it can hold
	 * \else
	 * 得到缓冲区能够容纳的元素个数
	 * \endif
	 */
	int getCapacity() { return m_capacity; }

	/**
	 * \if English
	 * Flag a buffer full, but doesn't fill it with actual data, just flag the element count
	 * is same as capacity
	 * \else
	 * 标记一个缓冲区满员, 但不填充实际数据, 只是让元素个数等于容量
	 * \endif
	 */
	void setFull() { m_elements = m_capacity; }

	/**
	 * \if English
	 * True means this buffer is full
	 * \else
	 * true表示这个缓冲区已经填满
	 * \endif
	 */
	bool isFull() { return m_elements >= m_capacity; }

	/**
	 * \if English
	 * Manually set element count
	 * \else
	 * 手动调整元素个数值
	 * \endif
	 */
	void setElementCount(int c) { m_elements = c; }

	/**
	 * \if English
	 * Fill whole buffer with a specified element repeatly. So the element count
	 * will be set to capacity value
	 *
	 * @param data data buffer
	 * \else
	 * 以同一个元素数据填充缓冲区, 因此缓冲区内的元素个数会被设置成容量
	 *
	 * @param data 数据缓冲区
	 * \endif
	 */
	void fill(void* data);

	/**
	 * \if English
	 * Reset this buffer element count to zero
	 * \else
	 * 清空这个缓冲区, 其实就是设置元素个数为0
	 * \endif
	 */
	void clear();

	/**
	 * \if English
	 * Get pointer of a element
	 *
	 * @param index index of element
	 * @return pointer of element, or NULL if \c index is invalid
	 * \else
	 * 得到某个位置元素的指针
	 *
	 * @param index 元素位置索引
	 * @return 元素指针, 如果索引无效, 返回NULL
	 * \endif
	 */
	void* elementAt(int index);
};

#endif // __wyBuffer_h__
