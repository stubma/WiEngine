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
#ifndef __wyLagrangeConfig_h__
#define __wyLagrangeConfig_h__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 创建一个二次拉格朗日曲线配置
 *
 * @param startX 起始点x位置
 * @param startY 起始点y位置
 * @param endX 结束点x位置
 * @param endY 结束点y位置
 * @param cp1X 控制点x位置
 * @param cp1Y 控制点y位置
 * @return \link wyLagrangeConfig wyLagrangeConfig\endlink
 */
static inline wyLagrangeConfig wylcQuad(float startX, float startY, float endX, float endY, float cp1X, float cp1Y) {
	wyLagrangeConfig c = {
		false,
		startX, startY, endX, endY,
		cp1X, cp1Y, 0, 0,
		0, 0.5f, 1.0f, 0
	};
	return c;
}

/**
 * 创建一个三次拉格朗日曲线配置
 *
 * @param startX 起始点x位置
 * @param startY 起始点y位置
 * @param endX 结束点x位置
 * @param endY 结束点y位置
 * @param cp1X 第一控制点x位置
 * @param cp1Y 第一控制点y位置
 * @param cp2X 第二控制点x位置
 * @param cp2Y 第二控制点y位置
 * @return \link wyLagrangeConfig wyLagrangeConfig\endlink
 */
static inline wyLagrangeConfig wylcCubic(float startX, float startY, float endX, float endY, float cp1X, float cp1Y, float cp2X, float cp2Y) {
	wyLagrangeConfig c = {
		true,
		startX, startY, endX, endY,
		cp1X, cp1Y, cp2X, cp2Y,
		0, 0.33333f, 0.66666f, 1.0f
	};
	return c;
}

/**
 * 给定一个t值，区间0到1，计算拉格朗日曲线在t位置的坐标
 *
 * @param c \link wyLagrangeConfig wyLagrangeConfig\endlink
 * @param t 取样值，从0到1
 * @return 计算出来的点坐标
 */
static wyPoint wylcPointAt(wyLagrangeConfig& c, float t) {
	wyPoint v;

	if(c.cubic) {
		float ti[] = { c.t0, c.t1, c.t2, c.t3 };
		float bF[4];
		for(int j = 0; j < 4; j++) {
			float P = 1;
			for(int i = 0; i < 4; i++) {
				if(i != j)
					P = P * (t - ti[i]) / (ti[j] - ti[i]);
			}
			bF[j] = P;
		}

		wyPoint start = wyp(c.startX, c.startY);
		start = wypMul2(start, bF[0]);
		wyPoint cp1 = wyp(c.cp1X, c.cp1Y);
		cp1 = wypMul2(cp1, bF[1]);
		wyPoint cp2 = wyp(c.cp2X, c.cp2Y);
		cp2 = wypMul2(cp2, bF[2]);
		wyPoint end = wyp(c.endX, c.endY);
		end = wypMul2(end, bF[3]);
		v = wypAdd(wypAdd(wypAdd(start, cp1), cp2), end);
	} else {
		float ti[] = { c.t0, c.t1, c.t2 };
		float bF[3];
		for(int j = 0; j < 3; j++) {
			float P = 1;
			for(int i = 0; i < 3; i++) {
				if(i != j)
					P = P * (t - ti[i]) / (ti[j] - ti[i]);
			}
			bF[j] = P;
		}

		wyPoint start = wyp(c.startX, c.startY);
		start = wypMul2(start, bF[0]);
		wyPoint cp1 = wyp(c.cp1X, c.cp1Y);
		cp1 = wypMul2(cp1, bF[1]);
		wyPoint end = wyp(c.endX, c.endY);
		end = wypMul2(end, bF[2]);
		v = wypAdd(wypAdd(start, cp1), end);
	}

	return v;
}

#ifdef __cplusplus
}
#endif

#endif // __wyLagrangeConfig_h__
