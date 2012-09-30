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
#include "wyBlurColorFilter.h"
#include "wyMath.h"

wyBlurColorFilter::wyBlurColorFilter(int radius) :
		m_radius(radius) {
}

wyBlurColorFilter::~wyBlurColorFilter() {
}

wyBlurColorFilter* wyBlurColorFilter::make(int radius) {
	wyBlurColorFilter* f = WYNEW wyBlurColorFilter(radius);
	return (wyBlurColorFilter*)f->autoRelease();
}

void wyBlurColorFilter::apply(void* data, int width, int height) {
	// if radius is less than 1, just do nothing
	if(m_radius < 1)
		return;

	// radius can be more than width or height
	int radius = m_radius;
	if(m_radius >= width || m_radius >= height)
		radius = MIN(width, MIN(height, m_radius)) - 1;

	// initialize cache
	int cacheSize = MIN(radius * 2 + 1, height);
	wyArray* rowCache = wyArrayNew(MIN(radius * 2 + 1, height));

	// which row of imageData the cache begins with
	int cacheStartIndex = 0;
	for (int row = 0; row < cacheSize; row++) {
		// row data is horizontally blurred before caching
		wyArrayPush(rowCache, blurRow(data, width, row, radius));
	}

	// sum red, green, and blue values separately for averaging
	unsigned int* rowRGBSums = (unsigned int*)wyCalloc(width * 4, sizeof(int));
	unsigned char* newData = (unsigned char*)wyMalloc(width * height * 4 * sizeof(char));
	unsigned char* rowRGBAverages = newData;
	
	// follow original data
	unsigned char* line = (unsigned char*)data;

	// current top row of summed values scope
	int topSumBoundary = 0;

	// row with RGB averages to be determined
	int targetRow = 0;

	// current bottom row of summed values scope
	int bottomSumBoundary = 0;

	// number of rows included in current summing scope
	int numRows = 0;

	while (targetRow < height) {
		if (bottomSumBoundary < height) {
			do {
				// sum pixel RGB values for each column in our radius scope
				for (int col = 0; col < width; col++) {
					unsigned char* cache = (unsigned char*)wyArrayGet(rowCache, bottomSumBoundary - cacheStartIndex);
					rowRGBSums[col * 4] += cache[col * 4];
					rowRGBSums[col * 4 + 1] += cache[col * 4 + 1];
					rowRGBSums[col * 4 + 2] += cache[col * 4 + 2];
				}
				numRows++;

				// move bottom scope boundary lower
				bottomSumBoundary++;
				if (bottomSumBoundary < height && bottomSumBoundary - cacheStartIndex > radius * 2) {
					// grow cache
					wyArrayPush(rowCache, blurRow(data, width, bottomSumBoundary, radius));
				}
			} while (bottomSumBoundary <= radius);
		}

		if (targetRow - topSumBoundary > radius) {
			// subtract values of top row from sums as scope of summed values moves down
			for (int col = 0; col < width; col++) {
				unsigned char* cache = (unsigned char*)wyArrayGet(rowCache, topSumBoundary - cacheStartIndex);
				rowRGBSums[col * 4] -= cache[col * 4];
				rowRGBSums[col * 4 + 1] -= cache[col * 4 + 1];
				rowRGBSums[col * 4 + 2] -= cache[col * 4 + 2];
			}
			numRows--;

			// move top scope boundary lower
			topSumBoundary++;

			// remove top row which is out of summing scope
			wyFree(wyArrayGet(rowCache, 0));
			wyArrayDeleteIndex(rowCache, 0);
			cacheStartIndex++;
		}

		// calculate each column's RGB-averaged pixel
		for (int col = 0; col < width; col++) {
			rowRGBAverages[col * 4] = rowRGBSums[col * 4] / numRows;
			rowRGBAverages[col * 4 + 1] = rowRGBSums[col * 4 + 1] / numRows;
			rowRGBAverages[col * 4 + 2] = rowRGBSums[col * 4 + 2] / numRows;
			rowRGBAverages[col * 4 + 3] = line[col * 4 + 3];
		}
		rowRGBAverages += width * 4;
		line += width * 4;

		targetRow++;
	}

	// copy new data
	memcpy(data, newData, width * height * 4 * sizeof(char));

	// release cache
	for(int i = 0; i < rowCache->num; i++) {
		wyFree(wyArrayGet(rowCache, i));
	}
	wyArrayDestroy(rowCache);

	// free others
	wyFree(rowRGBSums);
	wyFree(newData);
}

unsigned char* wyBlurColorFilter::blurRow(void* data, int width, int row, int radius) {
	// resulting rgb averages
	unsigned char* rowRGBAverages = (unsigned char*)wyMalloc(width * sizeof(char) * 4);
	unsigned char* lineData = (unsigned char*)data + row * width * 4;

	// sum red, green, and blue values separately for averaging
	unsigned int r = 0, g = 0, b = 0;

	// beginning index of summed values scope
	int leftSumBoundary = 0;

	// column of RGB average to be determined
	int targetColumn = 0;

	// ending index of summed values scope
	int rightSumBoundary = 0;

	// number of columns included in current summing scope
	unsigned int numCols = 0;
	while (targetColumn < width) {
		if (rightSumBoundary < width) {
			// sum RGB values for each pixel in our radius scope
			do {
				r += lineData[rightSumBoundary * 4];
				g += lineData[rightSumBoundary * 4 + 1];
				b += lineData[rightSumBoundary * 4 + 2];
				numCols++;
				rightSumBoundary++;
			} while (rightSumBoundary <= radius);
		}

		// subtract sum of left pixel as summing scope moves right
		if ((targetColumn - leftSumBoundary) > radius) {
			r -= lineData[leftSumBoundary * 4];
			g -= lineData[leftSumBoundary * 4 + 1];
			b -= lineData[leftSumBoundary * 4 + 2];
			numCols--;
			leftSumBoundary++;
		}

		// calculate RGB averages
		rowRGBAverages[targetColumn * 4] = r / numCols;
		rowRGBAverages[targetColumn * 4 + 1] = g / numCols;
		rowRGBAverages[targetColumn * 4 + 2] = b / numCols;
		targetColumn++;
	}

	return rowRGBAverages;
}
