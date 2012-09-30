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
#include "wyEmbossColorFilter.h"
#include "wyMath.h"

wyEmbossColorFilter::wyEmbossColorFilter(unsigned int grayLevel) :
		m_grayLevel(MAX(0, MIN(255, grayLevel))) {
}

wyEmbossColorFilter::~wyEmbossColorFilter() {
}

wyEmbossColorFilter* wyEmbossColorFilter::make(unsigned int grayLevel) {
	wyEmbossColorFilter* f = WYNEW wyEmbossColorFilter(grayLevel);
	return (wyEmbossColorFilter*)f->autoRelease();
}

void wyEmbossColorFilter::apply(void* data, int width, int height) {
	unsigned char* row1 = NULL;
	unsigned char* row2 = (unsigned char*)data;
	unsigned char* result = NULL;
	for(int y = 0; y < height; y++) {
		// set row1 and row2 and result
		if(y < height - 1) {
			row1 = row2;
			row2 = row1 + width * 4;
			result = row1;
		} else {
			result = row2;
		}

		int start = 0;
		unsigned int first, second;
		for(int x = 0; x < width; x++) {
			unsigned int diffR, diffG, diffB;
			if(x < 2) {
				// for first two columns, compare the target pixel to the pixel above
				diffR = abs(row2[start] - row1[start]);
				diffG = abs(row2[start + 1] - row1[start + 1]);
				diffB = abs(row2[start + 2] - row1[start + 2]);
			} else {
				// for all columns after the second column, compare the target pixel
				// to the pixel two pixels to the left on the row above
				diffR = abs(row2[start] - row1[start - 8]);
				diffG = abs(row2[start + 1] - row1[start - 7]);
				diffB = abs(row2[start + 2] - row1[start - 6]);
			}

			// calculate gray level
			unsigned int max = MAX(diffR, MAX(diffG, diffB));
			unsigned int gray = MAX(0, MIN(255, m_grayLevel + max));
			
			/*
			 * we can't write gray back immediately because the color will be accessed
			 * later. so we must wait two pixels
			 */
			if(x < 1) {
				first = gray;
			} else if(x < 2) {
				second = gray;
			} else {
				result[start - 8] = first;
				result[start - 7] = first;
				result[start - 6] = first;
				first = second;
				second = gray;
			}

			// increase start
			start += 4;
		}
		
		// write last two pixels of this line
		result[start - 8] = first;
		result[start - 7] = first;
		result[start - 6] = first;
		result[start - 4] = second;
		result[start - 3] = second;
		result[start - 2] = second;
	}
}
