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

#include "wyTypes.h"
#include "wyPrefs.h"
#include "wyUtils.h"
#include "wyResMap.h"
#include <tchar.h>
#include <Windows.h>

// buffer
#define MAX_SIZE 32767
static char s_buf[MAX_SIZE];

int wyPrefs::getInt(const char* key, int defValue) {
	DWORD ret = GetPrivateProfileString(_T("Default"), key, NULL, s_buf, MAX_SIZE, wyResMap::getInstance()->getConfigINI());
	if(GetLastError() == ERROR_SUCCESS) {
		return atoi(s_buf);
	} else {
		return defValue;
	}
}

void wyPrefs::setInt(const char* key, int value) {
	char buf[64];
	sprintf(buf, "%d", value);
	WritePrivateProfileString(_T("Default"), key, buf, wyResMap::getInstance()->getConfigINI());
}

bool wyPrefs::getBool(const char* key, bool defValue) {
	DWORD ret = GetPrivateProfileString(_T("Default"), key, NULL, s_buf, MAX_SIZE, wyResMap::getInstance()->getConfigINI());
	if(GetLastError() == ERROR_SUCCESS) {
		return !strcmp(s_buf, "true");
	} else {
		return defValue;
	}
}

void wyPrefs::setBool(const char* key, bool value) {
	WritePrivateProfileString(_T("Default"), key, value ? "true" : "false", wyResMap::getInstance()->getConfigINI());
}

void wyPrefs::setInt64(const char* key, int64_t value) {
	char buf[64];
	sprintf(buf, "%lld", value);
	WritePrivateProfileString(_T("Default"), key, buf, wyResMap::getInstance()->getConfigINI());
}

int64_t wyPrefs::getInt64(const char* key, int64_t defValue) {
	DWORD ret = GetPrivateProfileString(_T("Default"), key, NULL, s_buf, MAX_SIZE, wyResMap::getInstance()->getConfigINI());
	if(GetLastError() == ERROR_SUCCESS) {
		int64_t v;
		sscanf(s_buf, "%lld", &v);
		return v;
	} else {
		return defValue;
	}
}

const char* wyPrefs::getString(const char* key, const char* defValue) {
	DWORD ret = GetPrivateProfileString(_T("Default"), key, NULL, s_buf, MAX_SIZE, wyResMap::getInstance()->getConfigINI());
	if(GetLastError() == ERROR_SUCCESS) {
		return wyUtils::copy(s_buf);
	} else {
		return wyUtils::copy(defValue);
	}
}

void wyPrefs::setString(const char* key, const char* value) {
	WritePrivateProfileString(_T("Default"), key, value, wyResMap::getInstance()->getConfigINI());
}

void wyPrefs::clear() {
	DeleteFile(wyResMap::getInstance()->getConfigINI());
}

void wyPrefs::remove(const char* key) {
	WritePrivateProfileString(_T("Default"), key, NULL, wyResMap::getInstance()->getConfigINI());
}

#endif // #if WINDOWS
