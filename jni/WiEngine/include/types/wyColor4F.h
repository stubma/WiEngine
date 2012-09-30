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
#ifndef __wyColor4F_h__
#define __wyColor4F_h__

#include "wyGlobal.h"

#ifdef __cplusplus
extern "C" {
#endif

WIENGINE_API extern const wyColor4F wyc4fWhite;
WIENGINE_API extern const wyColor4F wyc4fBlack;

static inline wyColor4F wyc4f(float r, float g, float b, float a) {
	wyColor4F c = { r, g, b, a };
	return c;
}

static inline wyColor4F wyc4fFromInteger(int argb) {
	wyColor4F c = { ((argb >> 16) & 0xff) / 255.0f, ((argb >> 8) & 0xff) / 255.0f, (argb & 0xff) / 255.0f, ((argb >> 24) & 0xff) / 255.0f };
	return c;
}

#ifdef __cplusplus
}
#endif

#endif // __wyColor4F_h__
