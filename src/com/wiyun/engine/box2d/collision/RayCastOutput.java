package com.wiyun.engine.box2d.collision;

import com.wiyun.engine.types.WYPoint;

/**
 * 光线测试的输出结果
 */
public class RayCastOutput {
	/**
	 * 碰撞点法线
	 */
	public WYPoint normal;
	
	/**
	 * 光线撞击点在线段之中的相对位置。假如在RayCastInput时，设置的p1和p2分别是
	 * (10, 10), (110, 110), 如果fraction是0.4, 则碰撞点在（50, 50)
	 */
	public float fraction;
}
