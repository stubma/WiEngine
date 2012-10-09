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
#if BACKEND_OPENSL

#ifndef __wyMp3Stream_h__
#define __wyMp3Stream_h__

#include "wyAudioStream.h"
#include "mpg123.h"

class wyMp3Stream : public wyAudioStream {
private:
	/// mp3资源句柄
	mpg123_handle* m_handle;

private:
	/*
	 * custom IO methods for mpg123
	 */

	static ssize_t mp3Read(void* fp, void* buffer, size_t count);
	static off_t mp3Seek(void* fp, off_t offset, int mode);
	static void mp3Cleanup(void* fp);

protected:
	/// @see wyAudioStream::initInfo
	virtual void initInfo();

public:
	/**
	 * 通过资源id创建音频流
	 *
	 * @param resId wav文件的资源id
	 */
	wyMp3Stream(int resId);

	/**
	 * 通过路径创建音频流
	 *
	 * @param path wav文件的路径
	 * @param isFile false表示path是一个assets下的相对路径, true表示path是一个文件系统路径
	 */
	wyMp3Stream(const char* path, bool isFile = false);

	/**
	 * 析构函数
	 */
	virtual ~wyMp3Stream();

	/// @see wyAudioStream::reset
	virtual void reset();

	/// @see wyAudioStream::read
	virtual int read(char* buffer, size_t length);
};

#endif // __wyMp3Stream_h__

#endif // #if BACKEND_OPENSL
