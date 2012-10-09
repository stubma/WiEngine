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
#ifndef __wyMemoryOutputStream_h__
#define __wyMemoryOutputStream_h__

#include "wyAssetOutputStream.h"

/**
 * @class wyMemoryOutputStream
 *
 * \if English
 * Output stream which writes to a memory data
 * \else
 * 输入流, 目标是一段内存缓冲区
 * \endif
 */
class WIENGINE_API wyMemoryOutputStream : public wyAssetOutputStream {
private:
    /// buffer
    char* m_buffer;

    /// buffer data length
    size_t m_length;

    /// buffer capacity
    size_t m_capacity;

    /// position
    size_t m_position;

    /// release by self or not
    bool m_release;

protected:
    /**
     * Constructor
     *
     * @param buffer memory buffer
     * @param capacity buffer capacity
     * @param release true means it will be released by memory output stream
     */
    wyMemoryOutputStream(char* buffer, size_t capacity, bool release);

    /// ensure capacity is enough after write \c len bytes
    void ensureCapacity(size_t len);

public:
    virtual ~wyMemoryOutputStream();

    /**
     * \if English
     * Create a default memory output stream and the output buffer is maintained by stream.
     *
     * @return output stream
     * \else
     * 创建一个缺省的内存输出流, 内存缓冲区将由流自身维护
     *
     * @return 输出流对象
     * \endif
     */
    static wyMemoryOutputStream* make();

    /**
     * \if English
     * Create a memory output stream, and buffer is created by stream but may not released by it
     *
     * @param capacity buffer byte capacity
     * @param release true means \c buffer should be released by stream, or false means \c buffer
     * 		will be released by caller
     * @return output stream
     * \else
     * 创建一个内存输出流, 缓冲区由流分配并且可以指定是否由流释放该缓冲区
     *
     * @param capacity 缓冲区的字节容量
     * @param release true表示\c buffer由流负责释放, false表示\c buffer由调用者自己释放
     * @return 输出流对象
     * \endif
     */
    static wyMemoryOutputStream* make(size_t capacity, bool release = false);

    /// @see wyAssetOutputStream::close
	virtual void close() {}

    /// @see wyAssetOutputStream::write
	virtual ssize_t write(const char* data, size_t len);

    /// @see wyAssetOutputStream::write
	virtual ssize_t write(const int* data, size_t len);

    /// @see wyAssetOutputStream::getPosition
	virtual size_t getPosition();

    /// @see wyAssetOutputStream::seek
	virtual size_t seek(int offset, int mode);

	/**
	 * \if English
	 * Get data written in buffer
	 *
	 * @return data length written to buffer
	 * \else
	 * 得到总共写入的数据字节数
	 *
	 * @return 总共写入的数据字节数
	 * \endif
	 */
	size_t getLength() { return m_length; }

	/**
	 * \if English
	 * Get buffer pointer
	 *
	 * @return buffer pointer
	 * \else
	 * 得到缓冲区指针, 返回的缓冲区会是一个0结尾的内存块, 可以当成c字符串使用(当前中间部分是否有
	 * 0字节不能保证)
	 *
	 * @return 缓冲区指针
	 * \endif
	 */
	const char* getBuffer();

	/**
	 * \if English
	 * Reset stream to be ready for write new data
	 * \else
	 * 重置流状态, 抛弃所有现有数据重新开始
	 * \endif
	 */
	void reset();
};

#endif // __wyMemoryOutputStream_h__
