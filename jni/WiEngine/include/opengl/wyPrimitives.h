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
#ifndef __wyPrimitives_h__
#define __wyPrimitives_h__

#include "wyTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 画点
 *
 * @param x 点的x位置
 * @param y 点的y位置
 */
WIENGINE_API void wyDrawPoint(float x, float y);

/**
 * 画点,可以画多个点，报存在p指针中，length是p浮点的长度
 *
 * @param p 点坐标
 * @param length p的长度, 是点数乘以2，注意不是点数
 */
WIENGINE_API void wyDrawPoints(float* p, size_t length);

/**
 * 画线
 *
 * @param x1 起始点x位置
 * @param y1 起始点y位置
 * @param x2 结束点x位置
 * @param y2 结束点y位置
 */
WIENGINE_API void wyDrawLine(float x1, float y1, float x2, float y2);

/**
 * 画一条路径
 *
 * @param points 路径上的点，偶数位置是x坐标，奇数位置是y坐标
 * @param length points长度，是点数乘以2，注意不是点数
 */
WIENGINE_API void wyDrawPath(float* points, size_t length);

/**
 * 画一条虚线路径
 *
 * @param points 路径上的点，偶数位置是x坐标，奇数位置是y坐标
 * @param length points长度，是点数乘以2，注意不是点数
 * @param dashLength 虚线间隔
 */
WIENGINE_API void wyDrawDashPath(float* points, size_t length, float dashLength);

/**
 * 画虚线
 *
 * @param x1 起始点x位置
 * @param y1 起始点y位置
 * @param x2 结束点x位置
 * @param y2 结束点y位置
 * @param dashLength 虚线间隔
 */
WIENGINE_API void wyDrawDashLine(float x1, float y1, float x2, float y2, float dashLength);

/**
 * 画多边形
 *
 * @param p 多边形的端点
 * @param length \c p中浮点数个数
 * @param close 是否闭合多边形
 */
WIENGINE_API void wyDrawPoly(float* p, size_t length, bool close);

/**
 * 画矩形
 *
 * @param p 矩形顶点, 必须包含8个元素以表示4个顶点坐标
 */
WIENGINE_API void wyDrawRect(float* p);

/**
 * \if English
 * Draw a rect
 *
 * @param r \link wyRect wyRect\endlink
 * \else
 * 画矩形
 *
 * @param r \link wyRect wyRect\endlink
 * \endif
 */
WIENGINE_API void wyDrawRect2(wyRect& r);

/**
 * 画圆形，这里画的是一个近似圆型
 *
 * @param centerX 圆心x位置
 * @param centerY 圆心y位置
 * @param r 半径
 * @param radiusLineAngle 半径线与x轴成的角度，正值表示逆时针，负值表示顺时针
 * @param segments 圆周分段数，分段越多越近似圆形
 * @param drawLineToCenter 是否绘制半径线
 */
WIENGINE_API void wyDrawCircle(float centerX, float centerY, float r, float radiusLineAngle, int segments, bool drawLineToCenter);

/**
 * \if English
 * Draw a circle with a fill color
 *
 * @param centerX center x position of circle
 * @param centerY center y position of circle
 * @param r radius
 * @param segments segments of circle, the more it is, the more smoother circle is
 * @param color fill color
 * \else
 * 画圆形，这里画的是一个近似圆型
 *
 * @param centerX 圆心x位置
 * @param centerY 圆心y位置
 * @param r 半径
 * @param segments 圆周分段数，分段越多越近似圆形
 * @param color 填充色
 * \endif
 */
WIENGINE_API void wyDrawSolidCircle(float centerX, float centerY, float r, int segments, wyColor4B color);

/**
 * 画贝塞尔曲线
 *
 * @param c \link wyBezierConfig wyBezierConfig\endlink
 * @param segments 分段数，分段数越多，曲线越平滑
 */
WIENGINE_API void wyDrawBezier(wyBezierConfig& c, int segments);

/**
 * 画拉格朗日曲线
 *
 * @param c \link wyLagrangeConfig wyLagrangeConfig\endlink
 * @param segments 线段数，越多画的越精细，当然速度也越慢
 */
WIENGINE_API void wyDrawLagrange(wyLagrangeConfig& c, int segments);

/**
 * 内旋轮线
 *
 * @param c \link wyHypotrochoidConfig wyHypotrochoidConfig\endlink
 * @param segments 分段数，分段数越多，曲线越平滑
 */
WIENGINE_API void wyDrawHypotrochoid(wyHypotrochoidConfig& c, int segments);

/**
 * 画贴图
 *
 * @param texture
 * @param texW 贴图的有效宽度
 * @param texH 贴图的有效高度
 * @param x 贴图绘制目标区域的x坐标
 * @param y 贴图绘制目标区域的y坐标
 * @param w 贴图绘制目标区域的宽度
 * @param h 贴图绘制目标区域的高度
 * @param flipX 标识是否以Y轴为转动轴翻转图片
 * @param flipY 标识是否以X轴为转动轴翻转图片
 */
WIENGINE_API void wyDrawTexture(int texture, float texW, float texH, float x, float y, float w, float h, bool flipX, bool flipY);

/**
 * 画贴图
 *
 * @param texture
 * @param texRect 使用的贴图区域，x，y为左下点
 * @param texW 贴图的有效宽度
 * @param texH 贴图的有效高度
 * @param x 贴图绘制目标区域的x坐标
 * @param y 贴图绘制目标区域的y坐标
 * @param w 贴图绘制目标区域的宽度
 * @param h 贴图绘制目标区域的高度
 * @param flipX 标识是否以Y轴为转动轴翻转图片
 * @param flipY 标识是否以X轴为转动轴翻转图片
 */
WIENGINE_API void wyDrawTexture2(int texture, wyRect texRect, float texW, float texH, float x, float y, float w, float h, bool flipX, bool flipY);

/**
 * 画填充多边形, 顶点采用逆时针或顺时针
 *
 * @param p 矩形顶点
 * @param length 长度
 * @param color 填充颜色
 */
WIENGINE_API void wyDrawSolidPoly(float* p, size_t length, wyColor4B color);

/**
 * 画填充矩形, 顶点采用逆时针或顺时针
 *
 * @param p 矩形顶点
 * @param color 填充颜色
 */
WIENGINE_API void wyDrawSolidRect(float* p, wyColor4B color);

#ifdef __cplusplus
}
#endif

#endif // __wyPrimitives_h__
