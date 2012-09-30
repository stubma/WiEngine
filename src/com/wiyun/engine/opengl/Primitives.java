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
package com.wiyun.engine.opengl;

import com.wiyun.engine.types.WYBezierConfig;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYHypotrochoidConfig;
import com.wiyun.engine.types.WYLagrangeConfig;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;

/**
 * 封装了一些基本形状的绘制操作
 */ 
public class Primitives {
	/**
	 * 画点
	 * 
	 * @param x 点的x位置
	 * @param y 点的y位置
	 */
	public native static void drawPoint(float x, float y);
	
	/**
	 * 画点
	 * 
	 * @param points {@link WYPoint}数组
	 */
	public native static void drawPoints(WYPoint[] points);
	
	/**
	 * 画点
	 * 
	 * @param points 点坐标数组，偶数位置是x坐标，奇数位置是y坐标
	 */
	public native static void drawPoints(float[] points);

	/**
	 * 画线
	 * 
	 * @param origin 起始点
	 * @param destination 结束点
	 */
	public static void drawLine(WYPoint origin, WYPoint destination) {
		drawLine(origin.x, origin.y, destination.x, destination.y);
	}
	
	/**
	 * 画线
	 * 
	 * @param x1 起始点x位置
	 * @param y1 起始点y位置
	 * @param x2 结束点x位置
	 * @param y2 结束点y位置
	 */
	public native static void drawLine(float x1, float y1, float x2, float y2);
	
	/**
	 * 画虚线
	 *
	 * @param x1 起始点x位置
	 * @param y1 起始点y位置
	 * @param x2 结束点x位置
	 * @param y2 结束点y位置
	 * @param dashLength 虚线间隔
	 */
	public native static void drawDashLine(float x1, float y1, float x2, float y2, float dashLength);

	/**
	 * 画一条路径
	 *
	 * @param points 路径上的点，偶数位置是x坐标，奇数位置是y坐标
	 */
	public native static void drawPath(float[] points);

	/**
	 * 画一条虚线路径
	 *
	 * @param points 路径上的点，偶数位置是x坐标，奇数位置是y坐标
	 * @param dashLength 虚线间隔
	 */
	public native static void drawDashPath(float[] points, float dashLength);
	
	/**
	 * 画矩形
	 * 
	 * @param rect {@link WYRect}
	 */
	public native static void drawRect(WYRect rect);

	/**
	 * 画多边形
	 * 
	 * @param poli 多边形的端点
	 * @param closePolygon 是否闭合多边形
	 */
	public native static void drawPoly(WYPoint[] poli, boolean closePolygon);

	/**
	 * 画圆形，这里画的是一个近似原型
	 * 
	 * @param centerX 圆心x位置
	 * @param centerY 圆心y位置
	 * @param r 半径
	 * @param radiusLineAngle 半径线与x轴成的角度，正值表示逆时针，负值表示顺时针
	 * @param segments 圆周分段数，分段越多越近似圆形
	 * @param drawLineToCenter 是否绘制半径线
	 */
	public native static void drawCircle(float centerX, float centerY, float r, float radiusLineAngle, int segments, boolean drawLineToCenter);
	
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
	public native static void drawSolidCircle(float centerX, float centerY, float r, int segments, WYColor4B color);

	/**
	 * 画贝塞尔曲线
	 * 
	 * @param c {@link WYBezierConfig}
	 * @param segments 分段数，分段数越多，曲线越平滑 
	 */
	public native static void drawBezier(WYBezierConfig c, int segments);
	
	/**
	 * 画拉格朗日曲线
	 * 
	 * @param c {@link WYLagrangeConfig}
	 * @param segments 分段数，分段数越多，曲线越平滑 
	 */
	public native static void drawLagrange(WYLagrangeConfig c, int segments);
	
	/**
	 * 画内旋轮线
	 * 
	 * @param c {@link WYHypotrochoidConfig}
	 * @param segments 分段数，分段数越多，曲线越平滑 
	 */
	public native static void drawHypotrochoid(WYHypotrochoidConfig c, int segments);
	
	/**
	 * 画填充矩形
	 * 
	 * @param rect {@link WYRect}
	 * @param color {@link WYColor4B}
	 */
	public native static void drawSolidRect(WYRect rect, WYColor4B color);

	/**
	 * 画填充多边形
	 * 
	 * @param poli 多边形的端点
	 * @param color {@link WYColor4B}
	 */
	public native static void drawSolidPoly(WYPoint[] poli, WYColor4B color);
}
