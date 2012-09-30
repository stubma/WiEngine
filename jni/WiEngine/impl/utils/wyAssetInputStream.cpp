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
#include "wyAssetInputStream.h"
#include "wyLog.h"
#include <errno.h>
#include "wyGlobal.h"

wyAssetInputStream::wyAssetInputStream() :
        m_endian(LITTLE_ENDIAN) {
}

wyAssetInputStream::wyAssetInputStream(int resId) :
        m_endian(LITTLE_ENDIAN) {
}

wyAssetInputStream::wyAssetInputStream(const char* path, bool isFile) :
        m_endian(LITTLE_ENDIAN) {
}

wyAssetInputStream::~wyAssetInputStream() {
}

bool wyAssetInputStream::open() {
	return true;
}

ssize_t wyAssetInputStream::readByte(char* ret) {
	return read(ret, sizeof(char));
}

ssize_t wyAssetInputStream::readShort(short* ret) {
	*ret = 0;
	ssize_t readBytes = read((char*)ret, sizeof(short));
	if(readBytes > 0) {
		if(isBigEndian())
			*ret = betoh16(*ret);
		else
			*ret = letoh16(*ret);
	}

	return readBytes;
}

ssize_t wyAssetInputStream::readInt(int* ret) {
	*ret = 0;
	ssize_t readBytes = read((char*)ret, sizeof(int));
	if(readBytes > 0) {
		if(isBigEndian())
			*ret = betoh32(*ret);
		else
			*ret = letoh32(*ret);
	}

	return readBytes;
}

ssize_t wyAssetInputStream::readInt64(int64_t* ret) {
	*ret = 0;
	ssize_t readBytes = read((char*)ret, sizeof(int64_t));
	if(readBytes > 0) {
		if(isBigEndian())
			*ret = betoh64(*ret);
		else
			*ret = letoh64(*ret);
	}

	return readBytes;
}

void wyAssetInputStream::setBigEndian(bool big) {
	m_endian = big ? BIG_ENDIAN : LITTLE_ENDIAN;
}

bool wyAssetInputStream::isBigEndian() {
	return m_endian == BIG_ENDIAN;
}
