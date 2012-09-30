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
#include "wyColorMatrixColorFilter.h"
#include "wyGlobal.h"
#include "wyLog.h"
#include "wyMath.h"

wyColorMatrixColorFilter::wyColorMatrixColorFilter(wyColorMatrix* m) {
	m_matrix = m;
	wyObjectRetain(m_matrix);
}

wyColorMatrixColorFilter::~wyColorMatrixColorFilter() {
	wyObjectRelease(m_matrix);
}

wyColorMatrixColorFilter* wyColorMatrixColorFilter::make(wyColorMatrix* m) {
	wyColorMatrixColorFilter* f = WYNEW wyColorMatrixColorFilter(m);
	return (wyColorMatrixColorFilter*)f->autoRelease();
}

void wyColorMatrixColorFilter::apply(void* data, int width, int height) {
	float* m = m_matrix->getMatrix();
	char* p = (char*)data;
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			int r = p[0] & 0xFF;
			int g = p[1] & 0xFF;
			int b = p[2] & 0xFF;
			int a = p[3] & 0xFF;
			p[0] = MAX(0, MIN(255, r * m[0] + g * m[1] + b * m[2] + a * m[3] + 255 * m[4]));
			p[1] = MAX(0, MIN(255, r * m[5] + g * m[6] + b * m[7] + a * m[8] + 255 * m[9]));
			p[2] = MAX(0, MIN(255, r * m[10] + g * m[11] + b * m[12] + a * m[13] + 255 * m[14]));
			p[3] = MAX(0, MIN(255, r * m[15] + g * m[16] + b * m[17] + a * m[18] + 255 * m[19]));
			p += 4;
		}
	}
}
