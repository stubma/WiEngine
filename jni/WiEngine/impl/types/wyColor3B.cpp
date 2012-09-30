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
#include "wyTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

const wyColor3B wyc3bWhite = { 255, 255, 255 };
const wyColor3B wyc3bBlack = { 0, 0, 0 };
const wyColor3B wyc3bGray = { 126, 126, 126 };
const wyColor3B wyc3bRed = { 255, 0, 0 };
const wyColor3B wyc3bGreen = { 0, 255, 0 };
const wyColor3B wyc3bBlue = { 0, 0, 255 };
const wyColor3B wyc3bTransparent = { 0, 0, 0 };

wyColorHSV wyc3b2hsv(wyColor3B& c) {
    unsigned char min = MIN(c.r, MIN(c.g, c.b));
    unsigned char max = MAX(c.r, MAX(c.g, c.b));
    unsigned char delta = max - min;

    // get v
    float v = max / 255.f;

    // if input color a gray color?
    if(delta == 0) {
    	return wychsv(0, 0, v);
    }

    // get s
    float s = (float)delta / max;

    // get h
    float h;
    if(c.r == max) {
        h = (float)(c.g - c.b) / delta;
    } else if (c.g == max) {
        h = 2 + (float)(c.b - c.r) / delta;
    } else { // b == max
        h = 4 + (float)(c.r - c.g) / delta;
    }

    // adjust h
    h *= 60;
    if (h < 0) {
        h += 360;
    }

    return wychsv(h, s, v);
}

#ifdef __cplusplus
}
#endif
