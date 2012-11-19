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
#ifndef __wyMath_h__
#define __wyMath_h__

#include "wyGlobal.h"

struct wyPoint;
class wyDirector;

/** Returns the larger value */
#ifndef MAX
	#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

/** Returns the smaller value */
#ifndef MIN
	#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

/** Returns the value clamped to be between the min and max values */
#ifndef CLAMP
	#define CLAMP(val, min, max) (MIN(MAX((val), (min)), (max)))
#endif

/** Returns -1, 0 or +1 if the argument is negative, zero or positive respectively. */
#ifndef SIGN
	#define SIGN(A)	((A) < 0 ? -1 :((A) > 0 ? 1 : 0))
#endif

/** Returns a weighted average of the two values, where weight is between zero and one, inclusive. */
#ifndef WAVG
	#define WAVG(val1, val2, weight) ((val1) + (((val2) - (val1)) * CLAMP(weight, 0.0, 1.0)))
#endif

/** sqrt(3) */
#define M_SQRT3  1.732050807568877f

// epsilon
#ifndef FLT_EPSILON
	#define FLT_EPSILON 1.19209290e-07f
#endif

// golden mean
#define GOLDEN_MEAN 1.1547f

// max value
#if WINDOWS
	#define MAX_FLOAT FLT_MAX
#else
	#define MAX_FLOAT 3.4028235E38f
#endif
#define MAX_INT 0x7fffffff

/**
 * @class wyMath
 *
 * Mathematical methods definition
 */
class WIENGINE_API wyMath {
	friend class wyDirector;

private:
	/// setup method of math library, called when director create
	static void init();

	/// init sqrt table
	static void initSqrt();

public:
	/**
	 * Return a number which is power of two and closest to given \c x
	 *
	 * @param x reference number
	 * @return a number which is power of two and closest to given \c x
	 */
	static int getNextPOT(int x);

	/**
	 * Convert degree to radian
	 *
	 * @param degree value in degree
	 * @return value in radian
	 */
	static float d2r(float degree);

	/**
	 * Convert radian to degree
	 *
	 * @param radian value in radian
	 * @return value in degree
	 */
	static float r2d(float radian);

	/**
	 * Generate a random number between -1 and 1
	 *
	 * @return random number
	 */
	static float randMinusOneToOne();

	/**
	 * Generate a random number between 0 and 1
	 *
	 * @return random number
	 */
	static float randZeroToOne();

	/**
	 * Generate a random number between 0 and \c max
	 *
	 * @param max max value
	 * @return random number
	 */
	static int randMax(int max);

	/**
	 * Check two segments are intersected or not
	 *
	 * @param p1 start point of segment 1
	 * @param p2 end point of segment 1
	 * @param q1 start point of segment 2
	 * @paarm q2 end point of segment 2
	 * @return true means two segments are intersected, or false if not
	 */
	static bool isIntersected(wyPoint p1, wyPoint p2, wyPoint q1, wyPoint q2);

	/**
	 * Returns the positive modulo remainder of value divided by period.
	 *
	 * \par
	 * This function is similar to fmod() (and uses fmod()), but converts a negative result
	 * into a positive value that is the same distance away from the end of the cycle as the
	 * result was below zero. In this sense, this function behaves like the numbers on a clock,
	 * and cyclic(-2.0, 12.0) will return 10.0 rather than -2.0.
	 *
	 * @param value value
	 * @param period modulo
	 * @return remainder which is always positive
	 */
	static float cyclic(float value, float period);

	/**
	 * Returns the difference between the specified minuend and subtrahend, in terms of the
	 * minimum difference within the specified periodic cycle. Therefore, the result may be
	 * positive or negative, but will always be between (+period/2) and (-period/2).
	 *
	 * \par
	 * For example, for the numbers on a compass, the period is 360, and
	 * CyclicDifference(350, 10, 360) will yield -20 (ie- the smallest change from 10 degrees
	 * to 350 degrees is -20 degrees) rather than +340 (from simple subtraction). Similarly,
	 * CyclicDifference(10, 350, 360) will yield +20 (ie- the smallest change from 350 degrees
	 * to 10 degrees is +20 degrees) rather than -340 (from simple subtraction).
	 *
	 * @param minuend minuend
	 * @param subtrahend subtrahend
	 * @param period modulo
	 * @return minimum difference
	 */
	static float cyclicDifference(float minuend, float subtrahend, float period);

	/**
	 * Optimized sin method
	 * 
	 * @param r radian
	 * @return sine result
	 */
	static float sin(float r);

	/**
	 * Optimized cos method
	 * 
	 * @param r radian
	 * @param cosine result
	 */
	static float cos(float r);

	/**
	 * Optimized sqrt method
	 *
	 * @param f float value
	 * @return sqrt result
	 */
	static float sqrt(float f);
};

#endif // __wyMath_h__
