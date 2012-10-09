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

static unsigned char UnitScalarToByte(float x) {
    if (x < 0) {
        return 0;
    }
    if (x >= 1) {
        return 255;
    }
    return (int)(x * (1 << 16)) >> 8;
}

wyColor3B wychsv2c3b(wyColorHSV& c) {
    unsigned char s = UnitScalarToByte(c.s);
    unsigned char v = UnitScalarToByte(c.v);

    // if s is zero then rgb color is gray
    if (0 == s) {
    	return wyc3b(v, v, v);
    }

    int hx = (c.h < 0 || c.h >= 360.f) ? 0 : (int)((c.h / 60) * (1 << 16));
    int f = hx & 0xFFFF;

    unsigned char v_scale = v + 1;
    unsigned char p = ((255 - s) * v_scale) >> 8;
    unsigned char q = ((255 - (s * f >> 16)) * v_scale) >> 8;
    unsigned char t = ((255 - (s * ((1 << 16) - f) >> 16)) * v_scale) >> 8;

    unsigned char r, g, b;
    switch (hx >> 16) {
        case 0:
        	r = v;
        	g = t;
        	b = p;
        	break;
        case 1:
        	r = q;
        	g = v;
        	b = p;
        	break;
        case 2:
        	r = p;
        	g = v;
        	b = t;
        	break;
        case 3:
        	r = p;
        	g = q;
        	b = v;
        	break;
        case 4:
        	r = t;
        	g = p;
        	b = v;
        	break;
        default:
        	r = v;
        	g = p;
        	b = q;
        	break;
    }

    return wyc3b(r, g, b);
}

wyColor4B wychsv2c4b(wyColorHSV& c, unsigned char alpha) {
	wyColor3B c3b = wychsv2c3b(c);
	return wyc4b(c3b.r, c3b.g, c3b.b, alpha);
}

#ifdef __cplusplus
}
#endif
