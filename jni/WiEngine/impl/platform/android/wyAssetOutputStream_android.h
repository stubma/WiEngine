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

#ifndef __wyAssetOutputStream_android_h__
#define __wyAssetOutputStream_android_h__

#if ANDROID

#include "wyAssetOutputStream.h"
#include <stdio.h>

/**
 * @class wyAssetOutputStream_android
 *
 * \if English
 * Android implementation of output stream
 * \else
 * Android平台的文件输出流实现
 * \endif
 */
class wyAssetOutputStream_android : public wyAssetOutputStream {
	friend class wyAssetOutputStream;

private:
	/**
	 * \if English
	 * FILE pointer used for file path
	 * \else
	 * 文件指针
	 * \endif
	 */
	FILE* m_fp;

protected:
	/**
	 * \if English
	 * constructor
	 *
	 * @param path write file path
	 * @param append append file
	 * \else
	 * 构造函数
	 *
	 * @param path 写入文件完整路径
	 * @param append true为追加模式,默认false
	 * \endif
	 */
	wyAssetOutputStream_android(const char* path, bool append = false);

public:
	virtual ~wyAssetOutputStream_android();

	/// @see wyAssetOutputStream::close
	virtual void close();

	/// @see wyAssetOutputStream::write
	virtual ssize_t write(const char* data, size_t len);

	/// @see wyAssetOutputStream::write
	virtual ssize_t write(const int* data, size_t len);

	/// @see wyAssetOutputStream::getPosition
	virtual size_t getPosition();

	/// @see wyAssetOutputStream::seek
	virtual size_t seek(int offset, int mode);
};

#endif // #if ANDROID

#endif // __wyAssetOutputStream_android_h__
