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

#include "wyMp3Stream.h"
#include "wyLog.h"
#include <stdio.h>

wyMp3Stream::wyMp3Stream(int resId) :
		wyAudioStream(resId),
		m_handle(NULL) {
}

wyMp3Stream::wyMp3Stream(const char* path, bool isFile) :
		wyAudioStream(path, isFile),
		m_handle(NULL) {
}

wyMp3Stream::wyMp3Stream(char* buffer, size_t length, bool release) :
        wyAudioStream(buffer, length, release),
        m_handle(NULL) {
}

wyMp3Stream::~wyMp3Stream() {
	mpg123_close(m_handle);
	mpg123_delete(m_handle);
	m_handle = NULL;
}

wyMp3Stream* wyMp3Stream::make(int resId) {
	wyMp3Stream* s = WYNEW wyMp3Stream(resId);
	return (wyMp3Stream*)s->autoRelease();
}

wyMp3Stream* wyMp3Stream::make(const char* path, bool isFile) {
	wyMp3Stream* s = WYNEW wyMp3Stream(path, isFile);
	return (wyMp3Stream*)s->autoRelease();
}

wyMp3Stream* wyMp3Stream::make(char* buffer, size_t length, bool release) {
	wyMp3Stream* s = WYNEW wyMp3Stream(buffer, length, release);
	return (wyMp3Stream*)s->autoRelease();
}

ssize_t wyMp3Stream::mp3Read(void* fp, void* buffer, size_t count) {
	wyAssetInputStream* stream = (wyAssetInputStream*)fp;
	return stream->read((char*)buffer, count);
}

off_t wyMp3Stream::mp3Seek(void* fp, off_t offset, int mode) {
	wyAssetInputStream* stream = (wyAssetInputStream*)fp;
	return stream->seek(offset, mode);
}

void wyMp3Stream::mp3Cleanup(void* fp) {
}

void wyMp3Stream::reset() {
	mpg123_seek(m_handle, 0, SEEK_SET);
}

int wyMp3Stream::read(char* buffer, size_t length) {
	size_t count = 0;
	int error = mpg123_read(m_handle, (unsigned char*)buffer, length, &count);
    if (error == MPG123_DONE) {
        return count;
    } else if (error != MPG123_OK) {
		LOGE("wyMp3Stream::read: %s", mpg123_strerror(m_handle));
        return -1;
	}

    return count;
}

void wyMp3Stream::initInfo() {
	// create handle
	int error;
	m_handle = mpg123_new(NULL, &error);
	if(m_handle == NULL){
		LOGE("wyMp3Stream::initInfo 1: %s", mpg123_plain_strerror(error));
		return;
	}

	// redirect IO routines
	error = mpg123_replace_reader_handle(m_handle, mp3Read, mp3Seek, mp3Cleanup);
	if (error == MPG123_ERR) {
		LOGE("wyMp3Stream::initInfo 2: %s", mpg123_strerror(m_handle));
		return;
	}

	/*
	 * Now mpg123 is being prepared for feeding. The main loop will read chunks from
	 * stdin and feed them to mpg123 then take decoded data as available to write to stdout.
	 */
	error = mpg123_open_handle(m_handle, m_stream);
	if (error == MPG123_ERR) {
		LOGE("wyMp3Stream::initInfo 3: %s", mpg123_strerror(m_handle));
		return;
	}

	// get audio info
	long sampleRate;
	int channel;
	int format;
	error = mpg123_getformat(m_handle, &sampleRate, &channel, &format);
	if (error != MPG123_OK) {
		LOGE("wyMp3Stream::initInfo 4: %s", mpg123_strerror(m_handle));
		return;
	}

	// Ensure that this output format will not change (it could, when we allow it)
	mpg123_format_none(m_handle);
	mpg123_format(m_handle, sampleRate, channel, MPG123_ENC_SIGNED_16);

	// save info
	m_sampleRate = sampleRate;
	m_channel = channel;
	m_bitsPerSample = 16;
}

#endif // #if BACKEND_OPENAL
