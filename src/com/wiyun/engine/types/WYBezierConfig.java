package com.wiyun.engine.types;

import static java.lang.Math.*;

public class WYBezierConfig {
	/**
	 * true表示这是一个三次贝赛尔曲线，false表示这是一个二次贝赛尔曲线
	 */
	boolean cubic;
	
    /**
     * startPosition of the bezier
     */
	public float startX, startY;
	
	/**
	 * end position of the bezier
	 */
	public float endX, endY;
	
	/**
	 * Bezier control point 1
	 */
	public float cp1X, cp1Y;
	
	/**
	 * Bezier control point 2
	 */
	public float cp2X, cp2Y;
	
	/**
	 * 创建一个二次贝赛尔曲线配置
	 *
	 * @param startX 起始点x位置
	 * @param startY 起始点y位置
	 * @param endX 结束点x位置
	 * @param endY 结束点y位置
	 * @param cp1X 控制点x位置
	 * @param cp1Y 控制点y位置
	 * @return \link WYBezierConfig WYBezierConfig\endlink
	 */
	public static WYBezierConfig makeQuad(float startX, float startY, float endX, float endY, float cp1X, float cp1Y) {
		WYBezierConfig c = new WYBezierConfig();
		c.startX = startX;
		c.startY = startY;
		c.endX = endX;
		c.endY = endY;
		c.cp1X = cp1X;
		c.cp1Y = cp1Y;
		c.cubic = false;
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
	 * @return \link WYBezierConfig WYBezierConfig\endlink
	 */
	public static WYBezierConfig makeCubic(float startX, float startY, float endX, float endY, float cp1X, float cp1Y, float cp2X, float cp2Y) {
		WYBezierConfig c = new WYBezierConfig();
		c.startX = startX;
		c.startY = startY;
		c.endX = endX;
		c.endY = endY;
		c.cp1X = cp1X;
		c.cp1Y = cp1Y;
		c.cp2X = cp2X;
		c.cp2Y = cp2Y;
		c.cubic = true;
		return c;
	}
	
	static float bezierAt(float a, float b, float c, float d, float t) {
		return (float)(pow(1 - t, 3) * a + 3 * t * (pow(1 - t, 2)) * b + 3 * pow(t, 2) * (1 - t) * c + pow(t, 3) * d);
	}
	
	/**
	 * 给定一个t值，区间0到1，计算贝赛尔曲线在t位置的坐标
	 *
	 * @param t 取样值，从0到1
	 * @return 计算出来的点坐标
	 */
	public WYPoint pointAt(float t) {
		return WYPoint.make(bezierAt(startX, cp1X, cp2X, endX, t), bezierAt(startY, cp1Y, cp2Y, endY, t));
	}
}
