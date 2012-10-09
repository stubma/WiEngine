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
#ifndef __wyAssetInputStream_win_h__
#define __wyAssetInputStream_win_h__

#if WINDOWS

#include "wyAssetInputStream.h"
#include <stdio.h>

/**
 * @class wyAssetInputStream_win
 *
 * Asset input stream implementation for windows platform
 */
class wyAssetInputStream_win : public wyAssetInputStream {
	friend class wyAssetInputStream;

private:
	/**
	 * FILE pointer used for file path
	 */
	FILE* m_fp;

protected:
	/**
	 * constructor
	 *
	 * @param resId resource id
	 */
	wyAssetInputStream_win(int resId);

	/**
	 * constructor
	 *
	 * @param path file path
	 * @param isFile true means \c path is an absolute path in file system, false
	 * 		means path is relative path in assets
	 */
	wyAssetInputStream_win(const char* path, bool isFile);

public:
	virtual ~wyAssetInputStream_win();

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

#endif // #if WINDOWS

#endif // __wyAssetInputStream_win_h__
