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
#include "wyLightingColorFilter.h"
#include "wyMath.h"

wyLightingColorFilter::wyLightingColorFilter(int mul, int add) :
		m_mul(mul),
		m_add(add) {
}

wyLightingColorFilter::~wyLightingColorFilter() {
}

wyLightingColorFilter* wyLightingColorFilter::make(int mul, int add) {
	wyLightingColorFilter* f = WYNEW wyLightingColorFilter(mul, add);
	return (wyLightingColorFilter*)f->autoRelease();
}

void wyLightingColorFilter::apply(void* data, int width, int height) {
	/*
	 * Plus 1 to turn 0..255 into 0..256 by adding 1 at the half-way point. Used to turn a
	 * byte into a scale value, so that we can say scale * value >> 8 instead of
	 * alpha * value / 255.
	 */

	unsigned int scaleR = ((m_mul >> 16) & 0xFF) + 1;
	unsigned int scaleG = ((m_mul >> 8) & 0xFF) + 1;
	unsigned int scaleB = (m_mul & 0xFF) + 1;
	unsigned int addR = (m_add >> 16) & 0xFF;
	unsigned int addG = (m_add >> 8) & 0xFF;
	unsigned int addB = m_add & 0xFF;

	char* p = (char*)data;
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			unsigned int r = p[0] & 0xFF;
			unsigned int g = p[1] & 0xFF;
			unsigned int b = p[2] & 0xFF;
			unsigned int a = p[3] & 0xFF;
			unsigned int scaleA = a + 1;
			p[0] = MIN(a, ((r * scaleR) >> 8) + ((addR * scaleA) >> 8));
			p[1] = MIN(a, ((g * scaleG) >> 8) + ((addG * scaleA) >> 8));
			p[2] = MIN(a, ((b * scaleB) >> 8) + ((addB * scaleA) >> 8));
			p[3] = a;
			p += 4;
		}
	}
}
