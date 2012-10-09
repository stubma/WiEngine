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
#if BACKEND_OPENAL

#ifndef __wyOggStream_h__
#define __wyOggStream_h__

#include "wyAudioStream.h"
#include "ivorbisfile.h"

class wyOggStream : public wyAudioStream {
private:
	/// OGG file structure
	OggVorbis_File* m_oggFile;

private:
	/*
	 * ogg file redirect routine
	 */

	static size_t oggRead(void* ptr, size_t size, size_t nmemb, void* datasource);
	static int oggSeek(void* datasource, ogg_int64_t offset, int whence);
	static int oggClose(void* datasource);
	static long oggTell(void* datasource);

protected:
	/**
	 * 通过资源id创建音频流
	 *
	 * @param resId Ogg文件的资源id
	 */
	wyOggStream(int resId);
	
	/**
	 * 通过路径创建音频流
	 *
	 * @param path Ogg文件的路径
	 * @param isFile false表示path是一个assets下的相对路径, true表示path是一个文件系统路径
	 */
	wyOggStream(const char* path, bool isFile);
	
    /**
     * Create a memory buffer audio stream
     *
     * @param buffer buffer
     * @param length buffer data length
     * @param release true means this buffer should be mananged
     */
    wyOggStream(char* buffer, size_t length, bool release);
	
	/// @see wyAudioStream::reset
	virtual void reset();

	/// @see wyAudioStream::initInfo
	virtual void initInfo();

	/// @see wyAudioStream::read
	virtual int read(char* buffer, size_t length);

public:
    static wyOggStream* make(int resId);
	static wyOggStream* make(const char* path, bool isFile = false);
	static wyOggStream* make(char* buffer, size_t length, bool release = false);
    
	/**
	 * 析构函数
	 */
	virtual ~wyOggStream();
};

#endif // __wyOggStream_h__

#endif // #if BACKEND_OPENAL
