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
#ifndef __wyColor3B_h__
#define __wyColor3B_h__

#include "wyGlobal.h"

#ifdef __cplusplus
extern "C" {
#endif

WIENGINE_API extern const wyColor3B wyc3bWhite;
WIENGINE_API extern const wyColor3B wyc3bBlack;
WIENGINE_API extern const wyColor3B wyc3bGray;
WIENGINE_API extern const wyColor3B wyc3bRed;
WIENGINE_API extern const wyColor3B wyc3bGreen;
WIENGINE_API extern const wyColor3B wyc3bBlue;
WIENGINE_API extern const wyColor3B wyc3bTransparent;

static inline wyColor4B wyc4b(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

static inline wyColor3B wyc3b(unsigned char r, unsigned char g, unsigned char b) {
	wyColor3B c = { r, g, b };
	return c;
}

static inline wyColor4F wyc3b2c4f(wyColor3B& c) {
	return wyc4f(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, 1.0f);
}

static inline wyColor4B wyc3b2c4b(wyColor3B& c) {
	return wyc4b(c.r, c.g, c.b, 255);
}

static inline wyColor3B wyc3bFromInteger(int argb) {
	wyColor3B c = { (argb >> 16) & 0xff, (argb >> 8) & 0xff, argb & 0xff };
	return c;
}

/**
 * \if English
 * Convert RGB color to HSV color
 *
 * @param c \link wyColor3B wyColor3B\endlink
 * @return \link wyColorHSV wyColorHSV\endlink
 * \else
 * 将RGB颜色转换为HSV颜色
 *
 * @param c \link wyColor3B wyColor3B\endlink
 * @return \link wyColorHSV wyColorHSV\endlink
 * \endif
 */
wyColorHSV wyc3b2hsv(wyColor3B& c);

#ifdef __cplusplus
}
#endif

#endif // __wyColor3B_h__
