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
#include "wyColorMatrix.h"
#include <math.h>
#include "wyLog.h"
#include "wyMemory.h"
#include "wyMath.h"

wyColorMatrix::wyColorMatrix() {
	reset();
}

wyColorMatrix::~wyColorMatrix() {
}

wyColorMatrix* wyColorMatrix::make(float* m) {
	wyColorMatrix* cm = WYNEW wyColorMatrix();
	if(cm)
		cm->setMatrix(m);
	return (wyColorMatrix*)cm->autoRelease();
}

void wyColorMatrix::reset() {
	memset(m_matrix, 0, sizeof(float) * 20);
	m_matrix[0] = m_matrix[6] = m_matrix[12] = m_matrix[18] = 1;
}

void wyColorMatrix::setMatrix(wyColorMatrix* m) {
	if(m)
		memcpy(m_matrix, m->getMatrix(), sizeof(float) * 20);
}

void wyColorMatrix::setMatrix(float* m) {
	if(m)
		memcpy(m_matrix, m, sizeof(float) * 20);
}

void wyColorMatrix::setScale(float rScale, float gScale, float bScale, float aScale) {
	memset(m_matrix, 0, sizeof(float) * 20);
	m_matrix[0] = rScale;
	m_matrix[6] = gScale;
	m_matrix[12] = bScale;
	m_matrix[18] = aScale;
}

void wyColorMatrix::setRotate(int axis, float degrees) {
    reset();
	float radians = degrees * M_PI / 180;
	float cosine = wyMath::cos(radians);
	float sine = wyMath::sin(radians);
	switch(axis) {
		case 0:
			// Rotation around the red color
			m_matrix[6] = m_matrix[12] = cosine;
			m_matrix[7] = sine;
			m_matrix[11] = -sine;
			break;
		case 1:
			// Rotation around the green color
			m_matrix[0] = m_matrix[12] = cosine;
			m_matrix[2] = -sine;
			m_matrix[10] = sine;
			break;
		case 2:
			// Rotation around the blue color
			m_matrix[0] = m_matrix[6] = cosine;
			m_matrix[1] = sine;
			m_matrix[5] = -sine;
			break;
		default:
			LOGE("wyColorMatrix::setRotate: axis value %d is invalid", axis);
			break;
	}
}

void wyColorMatrix::setConcat(wyColorMatrix* matA, wyColorMatrix* matB) {
    float* tmp = NULL;

    if (matA == this || matB == this) {
        tmp = (float*)wyMalloc(20 * sizeof(float));
    } else {
        tmp = m_matrix;
    }

    float* a = matA->getMatrix();
    float* b = matB->getMatrix();
    int index = 0;
    for (int j = 0; j < 20; j += 5) {
        for (int i = 0; i < 4; i++) {
            tmp[index++] = a[j + 0] * b[i + 0] +  a[j + 1] * b[i + 5] +
                           a[j + 2] * b[i + 10] + a[j + 3] * b[i + 15];
        }
        tmp[index++] = a[j + 0] * b[4] +  a[j + 1] * b[9] +
                       a[j + 2] * b[14] + a[j + 3] * b[19] +
                       a[j + 4];
    }

    if (tmp != m_matrix) {
    	memcpy(m_matrix, tmp, sizeof(float) * 20);
    	wyFree(tmp);
    }
}

void wyColorMatrix::setSaturation(float sat) {
    reset();
    float* m = m_matrix;

    float invSat = 1 - sat;
    float R = 0.213f * invSat;
    float G = 0.715f * invSat;
    float B = 0.072f * invSat;

    m[0] = R + sat;
	m[1] = G;
	m[2] = B;
	m[5] = R;
	m[6] = G + sat;
	m[7] = B;
	m[10] = R;
	m[11] = G;
	m[12] = B + sat;
}

void wyColorMatrix::setRGB2YUV() {
    reset();
	float* m = m_matrix;

	// these coefficients match those in libjpeg
	m[0] = 0.299f;
	m[1] = 0.587f;
	m[2] = 0.114f;
	m[5] = -0.16874f;
	m[6] = -0.33126f;
	m[7] = 0.5f;
	m[10] = 0.5f;
	m[11] = -0.41869f;
	m[12] = -0.08131f;
}

void wyColorMatrix::setYUV2RGB() {
    reset();
	float* m = m_matrix;

	// these coefficients match those in libjpeg
	m[2] = 1.402f;
	m[5] = 1;
	m[6] = -0.34414f;
	m[7] = -0.71414f;
	m[10] = 1;
	m[11] = 1.772f;
	m[12] = 0;
}

void wyColorMatrix::setNegative() {
	float v[] = {
		-1, 0, 0, 0, 1,
		0, -1, 0, 0, 1,
		0, 0, -1, 0, 1,
		0, 0, 0, 1, 0,
		0, 0, 0, 0, 1
	};
	setMatrix(v);
}
