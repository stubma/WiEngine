package com.wiyun.engine.types;

import static java.lang.Math.*;

import com.wiyun.engine.utils.Utilities;

public class WYHypotrochoidConfig {
	
    /**
     * 内旋轮线(hypotrochoid)是追踪附着在围绕半径为 R 的固定的圆内侧滚转的半径为 r 的圆上的一个点得到的转迹线,
	 * 这个点到内部滚动的圆的中心的距离是 d.
	 * 特殊情况包括 d = r 的内摆线和 R = 2r 的椭圆。
     */
	public float R, r, d;
	
	/**
	 * Hypotrochoid angle
	 */
	public float startAngle, endAngle;
	
	/**
	 * Hypotrochoid centre point
	 */
	public float centreX, centreY;
	

	private float deltaAngle, temp1, temp2;
	
	/**
	 * 创建一个内旋轮线配置
	 * 内旋轮线(hypotrochoid)是追踪附着在围绕半径为 R 的固定的圆内侧滚转的半径为 r 的圆上的一个点得到的转迹线,
	 * 这个点到内部滚动的圆的中心的距离是 d.
	 *
	 * @param R 半径为 R 的固定的圆
	 * @param r 内侧滚转的半径
	 * @param d 这个点到内部滚动的圆的中心的距离是 d
	 * @param startAngle 起始角度,x轴正方向为0
	 * @param endAngle 结束角度,x轴正方向为0
	 * @param centreX 中心点x坐标
	 * @param centreY 中心点y坐标
	 * @return \link WYHypotrochoidConfig WYHypotrochoidConfig\endlink
	 */
	public static WYHypotrochoidConfig makeQuad(float R, float r, float d, float startAngle, float endAngle, float centreX, float centreY) {
		WYHypotrochoidConfig c = new WYHypotrochoidConfig();
		c.R = R;
		c.r = r;
		c.d = d;
		c.startAngle = startAngle;
		c.endAngle = endAngle;
		c.centreX = centreX;
		c.centreY = centreY;
		c.deltaAngle = endAngle - startAngle;
		c.temp1 = R - r;
		c.temp2 = c.temp1 / r;
		return c;
	}
	
	/**
	 * 创建一个椭圆配置
	 *
	 * @param r 
	 * @param d 
	 * @param startAngle 起始角度,x轴正方向为0
	 * @param endAngle 结束角度,x轴正方向为0
	 * @param centreX 中心点x坐标
	 * @param centreY 中心点y坐标
	 * @return \link WYHypotrochoidConfig WYHypotrochoidConfig\endlink
	 */
	public static WYHypotrochoidConfig makeEllipse(float r, float d, float startAngle, float endAngle, float centreX, float centreY) {
		WYHypotrochoidConfig c = new WYHypotrochoidConfig();
		c.R = 2 * r;
		c.r = r;
		c.d = d;
		c.startAngle = startAngle;
		c.endAngle = endAngle;
		c.centreX = centreX;
		c.centreY = centreY;
		c.deltaAngle = endAngle - startAngle;
		c.temp1 = r;
		c.temp2 = 1;
		return c;
	}
	
	/**
	 * 创建一个椭圆配置
	 *
	 * @param r 圆半径
	 * @param startAngle 起始角度,x轴正方向为0
	 * @param endAngle 结束角度,x轴正方向为0
	 * @param centreX 中心点x坐标
	 * @param centreY 中心点y坐标
	 * @return \link WYHypotrochoidConfig WYHypotrochoidConfig\endlink
	 */
	public static WYHypotrochoidConfig makeCircle(float r, float startAngle, float endAngle, float centreX, float centreY) {
		WYHypotrochoidConfig c = new WYHypotrochoidConfig();
		c.R = 2 * r;
		c.r = r;
		c.d = 0;
		c.startAngle = startAngle;
		c.endAngle = endAngle;
		c.centreX = centreX;
		c.centreY = centreY;
		c.deltaAngle = endAngle - startAngle;
		c.temp1 = r;
		c.temp2 = 1;
		return c;
	}

	
	/**
	 * 给定一个t值，区间0到1，计算内旋轮线在t位置的坐标
	 *
	 * @param t 取样值，从0到1
	 * @return 计算出来的点坐标
	 */
	public WYPoint pointAt(float t) {
		float radian = Utilities.d2r(startAngle + deltaAngle * t);
		float x = (float)(centreX + temp1 * cos(radian) + d * cos(radian * temp2));
		float y = (float)(centreY + temp1 * sin(radian) - d * sin(radian * temp2));
		return WYPoint.make(x, y);
	}
}
