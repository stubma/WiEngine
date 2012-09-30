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
#ifndef __wyHypotrochoidConfig_h__
#define __wyHypotrochoidConfig_h__

#include "wyMath.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 创建一个内旋轮线曲线配置
 *
 * @param R 大圆半径
 * @param r 小圆半径
 * @param d 距离小圆半径距离
 * @param startAngle 起始角度
 * @param endAngle 结束角度
 * @param centreX 中心x坐标
 * @param centreY 中心y坐标
 * @return \link wyHypotrochoidConfig wyHypotrochoidConfig\endlink
 */
static inline wyHypotrochoidConfig wyhcQuad(float R, float r, float d, float startAngle, float endAngle, float centreX, float centreY) {
	wyHypotrochoidConfig c = {
		R, r, d,
		startAngle, endAngle,
		centreX, centreY,
		(endAngle-startAngle), (R - r), (R - r) / r
	};
	return c;
}

/**
 * 创建一个椭圆曲线配置
 *
 * @param r 小圆半径
 * @param d 距离小圆半径距离
 * @param startAngle 起始角度
 * @param endAngle 结束角度
 * @param centreX 中心x坐标
 * @param centreY 中心y坐标
 * @return \link wyHypotrochoidConfig wyHypotrochoidConfig\endlink
 */
static inline wyHypotrochoidConfig wyhcEllipse(float r, float d, float startAngle, float endAngle, float centreX, float centreY) {
	wyHypotrochoidConfig c = {
		2 * r, r, d,
		startAngle, endAngle,
		centreX, centreY,
		(endAngle-startAngle), r, 1.0f
	};
	return c;
}

/**
 * 创建一个圆曲线配置
 *
 * @param r 半径
 * @param startAngle 起始角度
 * @param endAngle 结束角度
 * @param centreX 中心x坐标
 * @param centreY 中心y坐标
 * @return \link wyHypotrochoidConfig wyHypotrochoidConfig\endlink
 */
static inline wyHypotrochoidConfig wyhcCircle(float r, float startAngle, float endAngle, float centreX, float centreY) {
	wyHypotrochoidConfig c = {
		2 * r, r, 0.0f,
		startAngle, endAngle,
		centreX, centreY,
		(endAngle-startAngle), r, 1.0f
	};
	return c;
}

/**
 * 给定一个弧度值，计算内旋轮线位置的坐标
 *
 * @param c \link wyHypotrochoidConfig wyHypotrochoidConfig\endlink
 * @param t  0到1
 * @return 计算出来的点坐标
 */
static wyPoint wyhcPointAt(wyHypotrochoidConfig& c, float t) {
	wyPoint v;
	float radian = wyMath::d2r(c.startAngle + c.deltaAngle * t);

	v.x = c.centreX + c.temp1 * cos(radian) + c.d * cos(radian * c.temp2);
	v.y = c.centreY + c.temp1 * sin(radian) - c.d * sin(radian * c.temp2);
	return v;
}

#ifdef __cplusplus
}
#endif

#endif // __wyHypotrochoidConfig_h__
