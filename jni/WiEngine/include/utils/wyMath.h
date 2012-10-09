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
 * \if English
 * Mathematical methods definition
 * \else
 * 数学相关工具方法
 * \endif
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
	 * \if English
	 * Return a number which is power of two and closest to given \c x
	 *
	 * @param x reference number
	 * @return a number which is power of two and closest to given \c x
	 * \else
	 * 返回一个大于x的数，要求最接近x，且是2的整数次方。比如如果x是5，则返回8
	 *
	 * @param x 参考值
	 * @return 最接近x的2的整数次方值
	 * \endif
	 */
	static int getNextPOT(int x);

	/**
	 * \if English
	 * Convert degree to radian
	 *
	 * @param degree value in degree
	 * @return value in radian
	 * \else
	 * 把角度转换为弧度
	 *
	 * @param degree 角度值
	 * @return 弧度值
	 * \endif
	 */
	static float d2r(float degree);

	/**
	 * \if English
	 * Convert radian to degree
	 *
	 * @param radian value in radian
	 * @return value in degree
	 * \else
	 * 把弧度转换为角度
	 *
	 * @param radian 弧度
	 * @return 角度
	 * \endif
	 */
	static float r2d(float radian);

	/**
	 * \if English
	 * Generate a random number between -1 and 1
	 *
	 * @return random number
	 * \else
	 * 产生一个在[-1, 1]范围内的随机数
	 *
	 * @return 随机数
	 * \endif
	 */
	static float randMinusOneToOne();

	/**
	 * \if English
	 * Generate a random number between 0 and 1
	 *
	 * @return random number
	 * \else
	 * 产生一个在[0, 1]范围内的随机数
	 *
	 * @return 随机数
	 * \endif
	 */
	static float randZeroToOne();

	/**
	 * \if English
	 * Generate a random number between 0 and \c max
	 *
	 * @param max max value
	 * @return random number
	 * \else
	 * 尝试一个[0, max]之间的随机数
	 *
	 * @param max 随机数最大值
	 * @return 随机数
	 * \endif
	 */
	static int randMax(int max);

	/**
	 * \if English
	 * Check two segments are intersected or not
	 *
	 * @param p1 start point of segment 1
	 * @param p2 end point of segment 1
	 * @param q1 start point of segment 2
	 * @paarm q2 end point of segment 2
	 * @return true means two segments are intersected, or false if not
	 * \else
	 * 检查是否两个线段相交
	 *
	 * @param p1 线段1的起点和终点
	 * @param p2 线段1的终点
	 * @param q1 线段2的起点和终点
	 * @param q2 线段2的终点
	 * @return true表示两个线段相交, false表示不相交
	 * \endif
	 */
	static bool isIntersected(wyPoint p1, wyPoint p2, wyPoint q1, wyPoint q2);

	/**
	 * \if English
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
	 * \else
	 * 浮点的取模运算, 类似于fmod, 实际上它也调用fmod. 但是它保证返回的结果永远为正值. 比如cyclic(-2.0, 12.0)会
	 * 返回10.0, 而fmod(-2.0, 12.0)会返回-2.0
	 *
	 * @param value 值
	 * @param period 模数
	 * @return 余数, 必为正值
	 * \endif
	 */
	static float cyclic(float value, float period);

	/**
	 * \if English
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
	 * \else
	 * 计算一个减数和被减数在某个周期模数下的最小差值, 返回值可能为正也可能为负, 但是肯定在
	 * (+period/2)到(-period/2)的范围内
	 *
	 * \par
	 * 例如: 对于罗盘来说, 角度范围360度, cyclicDifference(350, 10, 360)将得到-20, 因为从10度到
	 * 350度的最小移动范围是反向移动20度.
	 *
	 * @param minuend 被减数
	 * @param subtrahend 减数
	 * @param period 模数
	 * @return 最小差值
	 * \endif
	 */
	static float cyclicDifference(float minuend, float subtrahend, float period);

	/**
	 * \if English
	 * Optimized sin method
	 * 
	 * @param r radian
	 * @return sine result
	 * \else
	 * 经过优化的正弦计算方法
	 *
	 * @param r 弧度
	 * @return 正弦
	 * \endif
	 */
	static float sin(float r);

	/**
	 * \if English
	 * Optimized cos method
	 * 
	 * @param r radian
	 * @param cosine result
	 * \else
	 * 经过优化的余弦计算方法 
	 *
	 * @param r 弧度
	 * @return 余弦
	 * \endif
	 */
	static float cos(float r);

	/**
	 * \if English
	 * Optimized sqrt method
	 *
	 * @param f float value
	 * @return sqrt result
	 * \else
	 * 经过优化的平方根计算方法
	 *
	 * @param f 参数
	 * @return 平方根
	 * \endif
	 */
	static float sqrt(float f);
};

#endif // __wyMath_h__
