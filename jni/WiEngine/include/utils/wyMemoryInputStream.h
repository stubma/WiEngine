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
#ifndef __wyMemoryInputStream_h__
#define __wyMemoryInputStream_h__

#include "wyAssetInputStream.h"

/**
 * @class wyMemoryInputStream
 *
 * \if English
 * A stream which read a memory buffer
 * \else
 * 一个把内存数组封装成流的实现, 其是\link wyAssetInputStream wyAssetInputStream\endlink的子类
 * \endif
 */
class WIENGINE_API wyMemoryInputStream : public wyAssetInputStream {
private:
    /// buffer
    char* m_buffer;
    
    /// buffer data length
    size_t m_length;
    
    /// position
    size_t m_position;
    
    /// release by self or not
    bool m_release;
    
protected:
    /**
     * Constructor
     * 
     * @param buffer memory buffer
     * @param length buffer data length
     * @param release true means it will be released by memory input stream
     */
    wyMemoryInputStream(char* buffer, size_t length, bool release);
    
public:
    virtual ~wyMemoryInputStream();
    
    /**
     * \if English
     * Create a memory input stream
     *
     * @param buffer memory buffer
     * @param length buffer data length
     * @param release true means this buffer will be released by this stream
     * @return memory buffer input stream
     * \else
     * 创建一个内存流
     *
     * @param buffer 内存数组
     * @param length 字节长度
     * @param release true表示这个内存由该流对象负责释放, false表示由调用者释放
     * @return 内存流对象
     * \endif
     */
    static wyMemoryInputStream* make(char* buffer, size_t length, bool release = false);
    
    /// @see wyAssetInputStream::getBuffer
	virtual char* getBuffer();
    
	/// @see wyAssetInputStream::getPosition
	virtual size_t getPosition();
    
	/// @see wyAssetInputStream::getLength
	virtual size_t getLength();
    
	/// @see wyAssetInputStream::available
	virtual size_t available();
    
	/// @see wyAssetInputStream::close
	virtual void close();
    
	/// @see wyAssetInputStream::read
	virtual ssize_t read(char* buffer, size_t length);
    
	/// @see wyAssetInputStream::seek
	virtual size_t seek(int offset, int mode);
};

#endif // __wyMemoryInputStream_h__
