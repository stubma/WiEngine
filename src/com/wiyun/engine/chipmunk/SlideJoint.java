package com.wiyun.engine.chipmunk;

import com.wiyun.engine.types.WYPoint;

/**
 * 一个滑动接触点 
 */
public class SlideJoint extends Constraint {
	public static SlideJoint make(Body b1, Body b2, WYPoint anchor1, WYPoint anchor2, float min, float max) {
		return new SlideJoint(b1, b2, anchor1.x, anchor1.y, anchor2.x, anchor2.y, min, max);
	}
	
	protected SlideJoint(Body b1, Body b2, float anchor1X, float anchor1Y, float anchor2X, float anchor2Y, float min, float max) {
		init(b1, b2, anchor1X, anchor1Y, anchor2X, anchor2Y, min, max);
	}
	
	public static SlideJoint from(int pointer) {
		return pointer == 0 ? null : new SlideJoint(pointer);
	}
	
	protected SlideJoint(int pointer) {
		super(pointer);
	}

	private native void init(Body b1, Body b2, float anchor1x, float anchor1y, float anchor2x, float anchor2y, float min, float max);
	
	public native float getMin();
	
	public native void setMin(float min);
	
	public native float getMax();
	
	public native void setMax(float max);
	
	/**
	 * 得到锚点1的x位置
	 * 
	 * @return 锚点1的x位置
	 */
	public native float getAnchor1X();
	
	/**
	 * 得到锚点1的y位置
	 * 
	 * @return 锚点1的y位置
	 */
	public native float getAnchor1Y();
	
	/**
	 * 得到锚点1
	 * 
	 * @return 锚点1
	 */
	public WYPoint getAnchor1() {
		return WYPoint.make(getAnchor1X(), getAnchor1Y());
	}
	
	/**
	 * 得到锚点2的x位置
	 * 
	 * @return 锚点2的x位置
	 */
	public native float getAnchor2X();
	
	/**
	 * 得到锚点2的y位置
	 * 
	 * @return 锚点2的y位置
	 */
	public native float getAnchor2Y();
	
	/**
	 * 得到锚点2
	 * 
	 * @return 锚点2
	 */
	public WYPoint getAnchor2() {
		return WYPoint.make(getAnchor2X(), getAnchor2Y());
	}
	
	/**
	 * 设置锚点1
	 * 
	 * @param p {@link WYPoint}
	 */
	public void setAnchor1(WYPoint p) {
		setAnchor1(p.x, p.y);
	}
	
	/**
	 * 设置锚点2
	 * 
	 * @param p {@link WYPoint}
	 */
	public void setAnchor2(WYPoint p) {
		setAnchor2(p.x, p.y);
	}
	
	/**
	 * 设置锚点1
	 * 
	 * @param x 锚点1的x位置
	 * @param y 锚点1的y位置
	 */
	public native void setAnchor1(float x, float y);
	
	/**
	 * 设置锚点2
	 * 
	 * @param x 锚点2的x位置
	 * @param y 锚点2的y位置
	 */
	public native void setAnchor2(float x, float y);
}
