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
#ifndef __wyColor4B_h__
#define __wyColor4B_h__

#include "wyGlobal.h"

#ifdef __cplusplus
extern "C" {
#endif

WIENGINE_API extern const wyColor4B wyc4bWhite;
WIENGINE_API extern const wyColor4B wyc4bBlack;
WIENGINE_API extern const wyColor4B wyc4bGray;
WIENGINE_API extern const wyColor4B wyc4bRed;
WIENGINE_API extern const wyColor4B wyc4bGreen;
WIENGINE_API extern const wyColor4B wyc4bBlue;
WIENGINE_API extern const wyColor4B wyc4bTransparent;

static inline wyColor4B wyc4b(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	wyColor4B c = { r, g, b, a };
	return c;
}

static inline wyColor3B wyc4b2c3b(wyColor4B& c) {
	return wyc3b(c.r, c.g, c.b);
}

static inline wyColor4F wyc4b2c4f(wyColor4B& c) {
	return wyc4f(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
}

static inline wyColor4B wyc4bFromInteger(int argb) {
	wyColor4B c = { (argb >> 16) & 0xff, (argb >> 8) & 0xff, argb & 0xff, (argb >> 24) & 0xff };
	return c;
}

#ifdef __cplusplus
}
#endif

#endif // __wyColor4B_h__
