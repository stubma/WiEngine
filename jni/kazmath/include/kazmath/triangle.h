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
#ifndef __triangle_h__
#define __triangle_h__

#include "kazmath/utility.h"

struct kmVec3;

/// triangle definition
typedef struct kmTriangle {
	/// point a
	kmVec3 a;

	/// point b
	kmVec3 b;

	/// point c
	kmVec3 c;

	/// center of triangle
	kmVec3 center;

	/// normal vector
	kmVec3 normal;

	/// vertices relative to the line origin
	kmScalar projection;

	/// an index that this triangle represents if it is contained in a OBBTree
	int index;
} kmTriangle;

KAZMATH_API kmTriangle* kmTriangleFill(kmTriangle* pOut, const kmVec3* a, const kmVec3* b, const kmVec3* c);
KAZMATH_API kmTriangle* kmTriangleCopy(kmTriangle* pOut, const kmTriangle* pIn);
KAZMATH_API kmVec3* kmTriangleGetPoint(kmTriangle* pIn, int index);
KAZMATH_API kmTriangle* kmTriangleSetPoint(kmTriangle* pIn, int index, const kmVec3* p);
KAZMATH_API kmTriangle* kmTriangleSet(kmTriangle* pIn, const kmVec3* a, const kmVec3* b, const kmVec3* c);

#endif // __triangle_h__
