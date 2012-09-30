/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wySize_h__
#define __wySize_h__

#include <stdbool.h>
#include <stdio.h>
#include "wyTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

WIENGINE_API extern const wySize wysZero;

static inline wySize wys(const float w, const float h) {
	wySize s = { w, h };
	return s;
}

/**
 * 把一个字符串转换为wySize结构, 字符串的格式必须是{x,y}, 例如"{3.2,3.4}"
 *
 * @param s 字符串形式
 * @return \link wySize wySize\endlink 结构
 */
WIENGINE_API wySize wysFromString(const char* s);

static inline bool isEqual(wySize s1, wySize s2) {
	return s1.width == s2.width && s1.height == s2.height;
}

#ifdef __cplusplus
}
#endif

#endif // __wySize_h__
