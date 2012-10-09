package com.wiyun.engine.box2d.collision;

import com.wiyun.engine.types.WYPoint;

/**
 * 光线测试的输入条件
 */
public class RayCastInput {
	/**
	 * 光线测试起始点
	 */
	public WYPoint p1;
	
	/**
	 * 光线测试结束点 
	 */
	public WYPoint p2;
	
	/**
	 * 实际的光线照射距离，假如p1和p2分别是(10, 10)和(110, 110), 如果maxFraction是0.4,
	 * 则实际上光线的范围是(10, 10)到(50, 50)
	 */
	public float maxFraction;
}
