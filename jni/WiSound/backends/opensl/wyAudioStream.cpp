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

#include "wyAudioStream.h"
#include "wyLog.h"
#include <stdio.h>

wyAudioStream::wyAudioStream(int resId) :
		m_bitsPerSample(0),
		m_channel(0),
		m_sampleRate(0),
		m_stream(NULL) {
	// open audio file stream
	m_stream = wyAssetInputStream::make(resId);
	m_stream->retain();
	m_stream->open();
}

wyAudioStream::wyAudioStream(const char* path, bool isFile) :
		m_bitsPerSample(0),
		m_channel(0),
		m_sampleRate(0),
		m_stream(NULL) {
	m_stream = wyAssetInputStream::make(path, isFile);
	m_stream->retain();
	m_stream->open();
}

wyAudioStream::~wyAudioStream() {
	// free stream
	m_stream->close();
	m_stream->release();
	m_stream = NULL;
}

void wyAudioStream::setup() {
	// init
	initInfo();
}

int wyAudioStream::read(char* buffer, size_t length) {
	return m_stream->read(buffer, length);
}

void wyAudioStream::skip(size_t length) {
	m_stream->seek(length, SEEK_CUR);
}

void wyAudioStream::reset() {
	m_stream->seek(0, SEEK_SET);
}

#endif // #if BACKEND_OPENSL
