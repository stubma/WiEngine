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

#include "wyOggStream.h"
#include "wyLog.h"

wyOggStream::wyOggStream(int resId) :
		wyAudioStream(resId),
		m_oggFile(new OggVorbis_File()) {
}

wyOggStream::wyOggStream(const char* path, bool isFile) :
		wyAudioStream(path, isFile),
		m_oggFile(new OggVorbis_File()) {
}

wyOggStream::~wyOggStream() {
	if(m_oggFile) {
		ov_clear(m_oggFile);
		delete m_oggFile;
		m_oggFile = NULL;
	}
}

size_t wyOggStream::oggRead(void* ptr, size_t size, size_t nmemb, void* datasource) {
	wyAssetInputStream* stream = (wyAssetInputStream*)datasource;
	return stream->read((char*)ptr, size * nmemb) / size;
}

int wyOggStream::oggSeek(void* datasource, ogg_int64_t offset, int whence) {
	wyAssetInputStream* stream = (wyAssetInputStream*)datasource;
	return stream->seek(offset, whence);
}

int wyOggStream::oggClose(void* datasource) {
	return 0;
}

long wyOggStream::oggTell(void* datasource) {
	wyAssetInputStream* stream = (wyAssetInputStream*)datasource;
	return stream->getPosition();
}

void wyOggStream::reset() {
	ov_pcm_seek(m_oggFile, 0);
}

void wyOggStream::initInfo() {
	// open ogg file with stream
	static ov_callbacks callback = {
		oggRead,
		oggSeek,
		oggClose,
		oggTell
	};
	ov_open_callbacks(m_stream, m_oggFile, 0, 0, callback);

	// get ogg info
	vorbis_info* info = ov_info(m_oggFile, -1);
	m_channel = info->channels;
	m_sampleRate = info->rate;
	m_bitsPerSample = 16;
}

int wyOggStream::read(char* buffer, size_t length) {
	int bitstream;
	int read = 0;
	while(read != length) {
		int ret = ov_read(m_oggFile, buffer + read, length - read, &bitstream);
		if(ret == OV_HOLE)
			continue;
		if(ret == OV_EBADLINK || ret == OV_EINVAL || ret == 0)
			return read;
		read += ret;
	}

	return read;
}

#endif // #if BACKEND_OPENSL
