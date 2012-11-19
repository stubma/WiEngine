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
#ifndef __wyAssetInputStream_h__
#define __wyAssetInputStream_h__

#include "wyObject.h"

/**
 * @class wyAssetInputStream
 *
 * A cross platform input stream implementation for reading resources
 */
class WIENGINE_API wyAssetInputStream : public wyObject {
protected:
	/**
	 * byte order, default is little endian
	 */
	int m_endian;

protected:
    /**
     * empty constructor
     */
    wyAssetInputStream();
    
	/**
	 * constructor
	 *
	 * @param resId resource id
	 */
	wyAssetInputStream(int resId);

	/**
	 * constructor
	 *
	 * @param path file path
	 * @param isFile true means \c path is an absolute path in file system, false
	 * 		means path is relative path in assets
	 */
	wyAssetInputStream(const char* path, bool isFile);

public:
	/**
	 * static constructor
	 *
	 * @param resId resource id
	 * @return \link wyAssetInputStream wyAssetInputStream\endlink
	 */
	static wyAssetInputStream* make(int resId);

	/**
	 * static constructor
	 *
	 * @param path file path
	 * @param isFile true means \c path is an absolute path in file system, false
	 * 		means path is relative path in assets
	 * @return \link wyAssetInputStream wyAssetInputStream\endlink
	 */
	static wyAssetInputStream* make(const char* path, bool isFile = false);

	virtual ~wyAssetInputStream();

	/**
	 * get buffer of resource, it contains all data
	 *
	 * @return buffer contains data of resource
	 */
	virtual char* getBuffer() = 0;

	/**
	 * get offset from start to current position
	 *
	 * @return offset from start to current position
	 */
	virtual size_t getPosition() = 0;

	/**
	 * get length of all data
	 *
	 * @return length of all data
	 */
	virtual size_t getLength() = 0;

	/**
	 * get length of available data
	 *
	 * @return length of available data
	 */
	virtual size_t available() = 0;

	/**
	 * open asset
	 *
	 * @return true means successful
	 */
	virtual bool open();

	/**
	 * close asset
	 */
	virtual void close() = 0;

	/**
	 * read data into a buffer
	 *
	 * @param buffer buffer pointer
	 * @param length byte to read at most
	 * @return byte read actually, 0 means no more data, -1 means error
	 */
	virtual ssize_t read(char* buffer, size_t length) = 0;

	/**
	 * read a byte
	 *
	 * @param ret return the byte read
	 * @return byte read in fact, 0 means no more data, -1 means error
	 */
	virtual ssize_t readByte(char* ret);

	/**
	 * read a short int
	 *
	 * @param ret return the byte read
	 * @return byte read in fact, 0 means no more data, -1 means error
	 */
	virtual ssize_t readShort(short* ret);

	/**
	 * read a int and the read value will reflect current byte order setting
	 *
	 * @param ret return the int read
	 * @return byte read in fact, 0 means no more data, -1 means error
	 */
	virtual ssize_t readInt(int* ret);

	/**
	 * read a int 64 and the read value will reflect current byte order setting
	 *
	 * @param ret return the int read
	 * @return byte read in fact, 0 means no more data, -1 means error
	 */
	virtual ssize_t readInt64(int64_t* ret);

	/**
	 * change pointer position
	 *
	 * @param offset offset
	 * @param mode seek mode
	 * @return new offset after changed
	 */
	virtual size_t seek(int offset, int mode) = 0;

	/**
	 * set use big endian or not, default is little endian
	 *
	 * @param big true means use big endian
	 */
	virtual void setBigEndian(bool big);

	/**
	 * is big endian or not?
	 *
	 * @return true means current byte order is big endian
	 */
	virtual bool isBigEndian();
};

#endif // __wyAssetInputStream_h__
