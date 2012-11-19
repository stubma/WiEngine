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
#ifndef __wyColorMatrix_h__
#define __wyColorMatrix_h__

#include "wyObject.h"

/**
 * @class wyColorMatrix
 *
 * 5x4 matrix for transforming the color+alpha components of a Bitmap.
 * The matrix is stored in a single array, and its treated as follows:
 *  [ a, b, c, d, e,
 *    f, g, h, i, j,
 *    k, l, m, n, o,
 *    p, q, r, s, t ]
 *
 * \par
 * When applied to a color [r, g, b, a], the resulting color is computed as
 * (after clamping)
 *   R' = a*R + b*G + c*B + d*A + e;
 *   G' = f*R + g*G + h*B + i*A + j;
 *   B' = k*R + l*G + m*B + n*A + o;
 *   A' = p*R + q*G + r*B + s*A + t;
 */
class WIENGINE_API wyColorMatrix : public wyObject {
private:
	/**
	 * matrix elements array
	 */
	float m_matrix[20];

protected:
	wyColorMatrix();

public:
	virtual ~wyColorMatrix();

	/**
	 * create a matrix
	 *
	 * @param m matrix elements, must have 20 elements. elements will be copied so
	 * 		caller can release the pointer when make returns. if m is NULL then create
	 * 		an identity color matrix
	 * @return \link wyColorMatrix wyColorMatrix\endlink
	 */
	static wyColorMatrix* make(float* m = NULL);

	/**
	 * reset matrix to identity
	 */
	void reset();

	/**
	 * get matrix elements
	 *
	 * @return matrix element pointer, caller should not release it
	 */
	float* getMatrix() { return m_matrix; }

	/**
	 * copy elements of other matrix
	 *
	 * @param m other \link wyColorMatrix wyColorMatrix\endlink object
	 */
	void setMatrix(wyColorMatrix* m);

	/**
	 * copy elements from a float array, float array must at least contain 20 float number
	 *
	 * @param m float array
	 */
	void setMatrix(float* m);

    /**
     * Set this color matrix to scale by the specified values.
     *
     * @param rScale scale of red
     * @param gScale scale of green
     * @param bScale scale of blue
     * @param aScale scale of alpha
     */
    void setScale(float rScale, float gScale, float bScale, float aScale);

    /**
     * Set the rotation on a color axis by the specified values.
     *
     * @param axis axis value
     * 		axis=0 correspond to a rotation around the RED color
     * 		axis=1 correspond to a rotation around the GREEN color
     * 		axis=2 correspond to a rotation around the BLUE color
     * @param degrees rotation degrees
     */
    void setRotate(int axis, float degrees);

    /**
     * Set this color matrix to the concatenation of the two specified
     * color matrices, such that the resulting color matrix has the same effect
     * as applying matB and then applying matA. It is legal for either matA or
     * matB to be the same color matrix as this.
     *
     * @param matA matrix A
     * @param matB matrix B
     */
    void setConcat(wyColorMatrix* matA, wyColorMatrix* matB);

    /**
     * Concat this colormatrix with the specified prematrix. This is logically
     * the same as calling setConcat(this, prematrix);
     *
     * @param prematrix matrix to be concated
     */
    void preConcat(wyColorMatrix* prematrix) { setConcat(this, prematrix); }

    /**
     * Concat this colormatrix with the specified postmatrix. This is logically
     * the same as calling setConcat(postmatrix, this);
     *
     * @param postmatrix matrix to be concated
     */
    void postConcat(wyColorMatrix* postmatrix) { setConcat(postmatrix, this); }

    /**
     * Set the matrix to affect the saturation of colors. A value of 0 maps the
     * color to gray-scale. 1 is identity.
     *
     * @param sat saturation, from 0 from 1
     */
    void setSaturation(float sat);

    /**
     * Set the matrix to convert RGB to YUV
     */
    void setRGB2YUV();

    /**
     * Set the matrix to convert from YUV to RGB
     */
    void setYUV2RGB();

    /**
     * set the matrix to convert image to digital nagative
     */
    void setNegative();
};

#endif // __wyColorMatrix_h__
