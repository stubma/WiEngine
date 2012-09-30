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
#if WINDOWS

#include "wyAssetOutputStream_win.h"
#include "wyLog.h"
#include <stdio.h>
#include <errno.h>
#include "wyGlobal.h"
#include "wyTypes.h"
#include "wyUtils.h"

#define ERROR_RETURN -1

wyAssetOutputStream* wyAssetOutputStream::make(const char* path, bool append) {
	wyAssetOutputStream* aos = WYNEW wyAssetOutputStream_win(path, append);
	return (wyAssetOutputStream*)aos->autoRelease();
}

wyAssetOutputStream_win::wyAssetOutputStream_win(const char* path, bool append) :
		wyAssetOutputStream(path, append),
		m_fp(NULL) {
	// map path to local platform
	const char* mappedPath = wyUtils::mapLocalPath(path);

	// ensure folder is here
	wyUtils::createIntermediateFolders(path);

	// open file
	if (m_append) {
		if((m_fp = fopen(mappedPath, "ab")) == NULL) {
			LOGW("open file %s failed: %s", mappedPath, strerror(errno));
			m_fp = NULL;
		}
	} else {
		if((m_fp = fopen(mappedPath, "wb")) == NULL) {
			LOGW("open file %s failed: %s", mappedPath, strerror(errno));
			m_fp = NULL;
		}
	}

	// free
	free((void*)mappedPath);
}

wyAssetOutputStream_win::~wyAssetOutputStream_win() {
	if(m_fp != NULL) {
		fclose(m_fp);
		m_fp = NULL;
	}
}

void wyAssetOutputStream_win::close() {
	if(m_fp != NULL) {
		fclose(m_fp);
		m_fp = NULL;
	}
}

ssize_t wyAssetOutputStream_win::write(const char* data, size_t len) {
	if (data == NULL)
		return ERROR_RETURN;

	if(m_fp != NULL)
		return fwrite((void*)data, sizeof(char) * len, 1, m_fp);
	else
		return ERROR_RETURN;
}

ssize_t wyAssetOutputStream_win::write(const int* data, size_t len) {
	if (data == NULL)
		return ERROR_RETURN;

	if(m_fp != NULL)
		return fwrite((void*)data, sizeof(int) * len, 1, m_fp);
	else
		return ERROR_RETURN;
}

size_t wyAssetOutputStream_win::getPosition() {
	if(m_fp != NULL)
		return ftell(m_fp);
	else
		return 0;
}

size_t wyAssetOutputStream_win::seek(int offset, int mode) {
	if(m_fp != NULL)
		return fseek(m_fp, offset, mode);
	else
		return 0;
}

#endif // #if WINDOWS
