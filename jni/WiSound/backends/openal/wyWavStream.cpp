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

#include "wyWavStream.h"
#include <stdio.h>
#include "wyGlobal.h"
#include "wyLog.h"

/**
 * @struct wyWavHeader
 *
 * Wav文件的头部结构, 其字节序是little endian
 */
typedef struct wyWavHeader {
	char riff[4]; //'RIFF'
	unsigned int riffSize;
	char wave[4]; //'WAVE'
	char fmt[4]; //'fmt '
	unsigned int fmtSize;
	unsigned short format;
	unsigned short channels;
	unsigned int samplesPerSec;
	unsigned int bytesPerSec;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
} wyWavHeader;

/**
 * @struct wyChunkHeader
 *
 * 一个chunk的开头
 */
typedef struct wyChunkHeader {
	char data[4];
	unsigned int dataSize;
} wyChunkHeader;

wyWavStream::wyWavStream(int resId) :
		wyAudioStream(resId),
		m_dataStartPosition(0) {
}

wyWavStream::wyWavStream(const char* path, bool isFile) :
		wyAudioStream(path, isFile),
		m_dataStartPosition(0) {
}

wyWavStream::wyWavStream(char* buffer, size_t length, bool release) :
        wyAudioStream(buffer, length, release),
        m_dataStartPosition(0) {
}

wyWavStream::~wyWavStream() {
}

wyWavStream* wyWavStream::make(int resId) {
	wyWavStream* s = WYNEW wyWavStream(resId);
	return (wyWavStream*)s->autoRelease();
}

wyWavStream* wyWavStream::make(const char* path, bool isFile) {
	wyWavStream* s = WYNEW wyWavStream(path, isFile);
	return (wyWavStream*)s->autoRelease();
}

wyWavStream* wyWavStream::make(char* buffer, size_t length, bool release) {
	wyWavStream* s = WYNEW wyWavStream(buffer, length, release);
	return (wyWavStream*)s->autoRelease();
}

void wyWavStream::initInfo() {
	// read header
	wyWavHeader header;
	read((char*)&header, sizeof(wyWavHeader));

	// do byte endian conversion
	header.fmtSize = letoh32(header.fmtSize);
	header.format = letoh16(header.format);
	header.channels = letoh16(header.channels);
	header.samplesPerSec = letoh32(header.samplesPerSec);
	header.bytesPerSec = letoh32(header.bytesPerSec);
	header.blockAlign = letoh16(header.blockAlign);
	header.bitsPerSample = letoh16(header.bitsPerSample);

	// do validation
	if(memcmp("RIFF", header.riff, 4)) {
		LOGE("Wav RIFF header not found");
	} else if(memcmp("WAVE", header.wave, 4)) {
		LOGE("Wav WAVE chunk not found");
	} else if(memcmp("fmt ", header.fmt, 4)) {
		LOGE("Wav fmt chunk not found");
	} else if(header.format != 1) {
		LOGE("Wav file must be PCM format");
	} else if(header.channels != 1 && header.channels != 2) {
		LOGE("Wav file must has 1 or 2 channels");
	} else if(header.bitsPerSample != 16 && header.bitsPerSample != 8) {
		LOGE("Wav file must use 8 or 16 bit sample");
	} else {
		// skip fmt chunk
		skip(header.fmtSize - 16);

		// read following chunk until we found data chunk
		wyChunkHeader chunk;
		size_t length = read((char*)&chunk, sizeof(wyChunkHeader));
		while(length == sizeof(wyChunkHeader)) {
			chunk.dataSize = letoh32(chunk.dataSize);
			if(memcmp("data", chunk.data, 4)) {
				skip(chunk.dataSize);
				read((char*)&chunk, sizeof(wyChunkHeader));
			} else {
				break;
			}
		}

		// validate data chunk
		if(memcmp("data", chunk.data, 4)) {
			LOGE("Wav data chunk not found");
		} else {
			// save info
			m_bitsPerSample = header.bitsPerSample;
			m_channel = header.channels;
			m_sampleRate = header.samplesPerSec;
			m_dataStartPosition = m_stream->getPosition();
		}
	}
}

void wyWavStream::reset() {
	m_stream->seek(m_dataStartPosition, SEEK_SET);
}

#endif // #if BACKEND_OPENAL
