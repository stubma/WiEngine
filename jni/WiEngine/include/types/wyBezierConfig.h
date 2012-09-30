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
#ifndef __wyBezierConfig_h__
#define __wyBezierConfig_h__

#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 创建一个二次贝赛尔曲线配置
 *
 * @param startX 起始点x位置
 * @param startY 起始点y位置
 * @param endX 结束点x位置
 * @param endY 结束点y位置
 * @param cp1X 控制点x位置
 * @param cp1Y 控制点y位置
 * @return \link wyBezierConfig wyBezierConfig\endlink
 */
static inline wyBezierConfig wybcQuad(float startX, float startY, float endX, float endY, float cp1X, float cp1Y) {
	wyBezierConfig c = {
		false,
		startX, startY, endX, endY,
		cp1X, cp1Y, 0, 0
	};
	return c;
}

/**
 * 创建一个三次贝赛尔曲线配置
 *
 * @param startX 起始点x位置
 * @param startY 起始点y位置
 * @param endX 结束点x位置
 * @param endY 结束点y位置
 * @param cp1X 第一控制点x位置
 * @param cp1Y 第一控制点y位置
 * @param cp2X 第二控制点x位置
 * @param cp2Y 第二控制点y位置
 * @return \link wyBezierConfig wyBezierConfig\endlink
 */
static inline wyBezierConfig wybcCubic(float startX, float startY, float endX, float endY, float cp1X, float cp1Y, float cp2X, float cp2Y) {
	wyBezierConfig c = {
		true,
		startX, startY, endX, endY,
		cp1X, cp1Y, cp2X, cp2Y
	};
	return c;
}

/**
 * 根据参数计算贝赛尔曲线上的点
 *
 * Bezier cubic formulae :
 * ((1 - t) + t)3 = 1 expands to (1 - t)3 + 3t(1-t)2 + 3t2(1 - t) + t3 = 1
 */
static float bezierAt(float a, float b, float c, float d, float t) {
	return pow(1 - t, 3) * a + 3 * t * (pow(1 - t, 2)) * b + 3 * pow(t, 2) * (1 - t) * c + pow(t, 3) * d;
}

/**
 * 给定一个t值，区间0到1，计算贝赛尔曲线在t位置的坐标
 *
 * @param c \link wyBezierConfig wyBezierConfig\endlink
 * @param t 取样值，从0到1
 * @return 计算出来的点坐标
 */
static wyPoint wybcPointAt(wyBezierConfig& c, float t) {
	wyPoint v;
	v.x = bezierAt(c.startX, c.cp1X, c.cp2X, c.endX, t);
	v.y = bezierAt(c.startY, c.cp1Y, c.cp2Y, c.endY, t);
	return v;
}

#ifdef __cplusplus
}
#endif

#endif // __wyBezierConfig_h__
