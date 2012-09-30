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
#include "wyMath.h"
#include <math.h>
#include <stdlib.h>

#ifdef WY_CFLAG_OPTIMIZE_MATH

/* INTORFLOAT union for easy access to bits of a float. */
typedef union {
    // as integer
    int i;

    // as float
    float f;

    // as bit fields
    struct {
        unsigned int sign:1;
        unsigned int biasedexponent:8;
        unsigned int significand;
    } bits;
} wyIntOrFloat;

// init flag
static bool sInited = false;

// sin table
static const int sSinTableSize = 1024;
static const int sCosOffset = sSinTableSize / 4;
static const int sSinTableMask = sSinTableSize - 1;
static float sSinTable[sSinTableSize];
static const float sSinConst = sSinTableSize / (2.0f * M_PI);

// sqrt table
static const int sSqrtTableSize = 256;
static unsigned int sSqrtTable[sSqrtTableSize];

#endif // WY_CFLAG_OPTIMIZE_MATH

int wyMath::getNextPOT(int x) {
	x = x - 1;
	x = x | (x >> 1);
	x = x | (x >> 2);
	x = x | (x >> 4);
	x = x | (x >> 8);
	x = x | (x >> 16);
	return x + 1;
}

float wyMath::d2r(float degree) {
	return (degree / 180.0f * M_PI);
}

float wyMath::r2d(float radian) {
	return (radian / M_PI * 180.0f);
}

float wyMath::randMinusOneToOne() {
	float base = (float)rand() / RAND_MAX;
	return base * 2.f - 1.f;
}

float wyMath::randZeroToOne() {
	return (float)rand() / RAND_MAX;
}

int wyMath::randMax(int max) {
	return rand() % (max + 1);
}

bool wyMath::isIntersected(wyPoint p1, wyPoint p2, wyPoint q1, wyPoint q2) {
	// check rectangle to decide quickly
	float left1 = MIN(p1.x, p2.x);
	float bottom1 = MIN(p1.y, p2.y);
	float width1 = MAX(p1.x, p2.x) - left1;
	float height1 = MAX(p1.y, p2.y) - bottom1;
	float left2 = MIN(q1.x, q2.x);
	float bottom2 = MIN(q1.y, q2.y);
	float width2 = MAX(q1.x, q2.x) - left2;
	float height2 = MAX(q1.y, q2.y) - bottom2;
	float d1 = left1 - left2;
	float d2 = bottom1 - bottom2;
	bool mayIntersectHorizontal = d1 <= 0 && d1 >= -width1 || d1 > 0 && d1 <= width2;
	bool mayIntersectVertical = d2 <= 0 && d2 >= -height1 || d2 > 0 && d2 <= height2;
	if(!mayIntersectHorizontal && !mayIntersectVertical)
		return false;

	// 如果快速检查不能得到确定结果, 使用跨立算法判断
	// ( P1 - Q1 ) × ( Q2 - Q1 ) * ( Q2 - Q1 ) × ( P2 - Q1 ) >= 0
	// ( Q1 - P1 ) × ( P2 - P1 ) * ( P2 - P1 ) × ( Q2 - P1 ) >= 0
	wyPoint p1q1 = wypSub(p1, q1);
	wyPoint p2q1 = wypSub(p2, q1);
	wyPoint q2q1 = wypSub(q2, q1);
	if(wypCross(p1q1, q2q1) * wypCross(q2q1, p2q1) < 0)
		return false;
	wyPoint q1p1 = wypSub(q1, p1);
	wyPoint q2p1 = wypSub(q2, p1);
	wyPoint p2p1 = wypSub(p2, p1);
	return wypCross(q1p1, p2p1) * wypCross(p2p1, q2p1) >= 0;
}

float wyMath::cyclic(float value, float period) {
	float modVal = fmod(value, period);
	return (modVal < 0.0) ? (modVal + period) : modVal;
}

float wyMath::cyclicDifference(float minuend, float subtrahend, float period) {
	float semiPeriod = period / 2.0f;
	float diff = minuend - subtrahend;

	// If the difference is outside the range (period/2 >= diff >= -period/2),
	// adjust it so that it takes the difference in the other direction to
	// arrive at a smaller change.
	if(diff > semiPeriod) {
		diff -= period;
	} else if(diff < -semiPeriod) {
		diff += period;
	}
	return diff;
}

void wyMath::init() {
#ifdef WY_CFLAG_OPTIMIZE_MATH
	if(!sInited) {
		// init sin table
		for(int i = 0; i < sSinTableSize; i++) {
			sSinTable[i] = sinf(i / sSinConst);
		}

		// init sqrt table
		initSqrt();

		sInited = true;
	}
#endif
}

float wyMath::sin(float r) {
#ifdef WY_CFLAG_OPTIMIZE_MATH
	int i = r * sSinConst;
	i &= sSinTableMask;
	return sSinTable[i];
#else
	return sinf(r);
#endif
}

float wyMath::cos(float r) {
#ifdef WY_CFLAG_OPTIMIZE_MATH
	int i = r * sSinConst + sCosOffset;
	i &= sSinTableMask;
	return sSinTable[i];
#else
	return cosf(r);
#endif
}

void wyMath::initSqrt() {
#ifdef WY_CFLAG_OPTIMIZE_MATH
	int i;
	wyIntOrFloat fi;
	unsigned int e0;

	/*
	 * These two tables are indexed into by the least significant bit (e0)
	 * of the biased exponent. exponent[] gives the biased exponent
	 * corresponding to e0, while biasrestore[] gives the amount to be
	 * added back to the exponent after dividing it by 2 in order to
	 * restore the bias to the correct value.
	 */
	unsigned int exponent[2] = { (1 + 127) << 23, (0 + 127) << 23 };
	unsigned int biasrestore[2] = { 63 << 23, 64 << 23 };

	for(i = 0; i < sSqrtTableSize; ++i) {
		/*
		 * Build the floating point number for this table entry. Table index
		 * is 8 bits, which we use as e0m22m21...m16. To turn this into a
		 * floating point number we add in the correct exponent bias and set
		 * m15 to 1 (which is like adding 0.5, so we hit the middle of the
		 * range of numbers that we're estimating).
		 */
		e0 = (i >> 7);
		fi.i = exponent[e0] | (i << 16) | (1 << 15);

		// Compute square root
		fi.f = sqrtf(fi.f);

		// Extract 23 bit mantissa of square root
		sSqrtTable[i] = fi.i & ((1 << 23) - 1);

		/*
		 * Exponent is calculated programmatically by fsqrt, so we don't
		 * include it in the table. However, the programmatic calculation
		 * divides the exponent bias by 2, so we put a bias restore into
		 * the table -- basically adding 63 or 64, depending on whether the
		 * exponent was odd or even, which we can determine from e0.
		 */
		sSqrtTable[i] += biasrestore[e0];
	}
#endif
}

float wyMath::sqrt(float f) {
#ifdef WY_CFLAG_OPTIMIZE_MATH
	wyIntOrFloat fi;
	unsigned int e, n;

	// Get raw bits of floating point f
	fi.f = f;
	n = fi.i;

	/*
	 * Divide exponent by 2 -- this is done in-place, no need to shift all
	 * the way down to 0 the least significant bits and then back up again.
	 * Note that we are also dividing the exponent bias (127) by 2, this
	 * gets corrected when we add in the sqrttable entry.
	 */
	e = (n >> 1) & 0x3f800000;

	/*
	 * n is the table index -- we're using 1 bit from the original exponent
	 * (e0) plus 7 bits from the mantissa.
	 */
	n = (n >> 16) & 0xff;

	// Add calculated exponent to mantissa + re-biasing constant from table
	fi.i = e + sSqrtTable[n];

	// Return floating point result
	return fi.f;
#else
	return sqrtf(f);
#endif
}
