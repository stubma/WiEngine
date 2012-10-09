package com.wiyun.engine.chipmunk;

import com.wiyun.engine.types.WYPoint;

/**
 * 枢轴连接点 
 */
public class PivotJoint extends Constraint {
	/**
	 * 创建一个车轴关节
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param anchor1 锚点1
	 * @param anchor2 锚点2
	 * @return {@link PivotJoint}
	 */
	public static PivotJoint make(Body b1, Body b2, WYPoint anchor1, WYPoint anchor2) {
		return make(b1, b2, anchor1.x, anchor1.y, anchor2.x, anchor2.y);
	}
	
	/**
	 * 创建一个车轴关节
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param pivot 轴点
	 * @return {@link PivotJoint}
	 */
	public static PivotJoint make(Body b1, Body b2, WYPoint pivot) {
		return new PivotJoint(b1, b2, pivot.x, pivot.y);
	}
	
	/**
	 * 创建一个车轴关节
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param pivotX 轴点x位置
	 * @param pivotY 轴点y位置
	 * @return {@link PivotJoint}
	 */
	public static PivotJoint make(Body b1, Body b2, float pivotX, float pivotY) {
		return new PivotJoint(b1, b2, pivotX, pivotY);
	}

	/**
	 * 创建一个车轴关节
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param anchor1X 锚点1的x坐标
	 * @param anchor1Y 锚点1的y坐标
	 * @param anchor2X 锚点2的x坐标 
	 * @param anchor2Y 锚点2的y坐标
	 * @return {@link PivotJoint}
	 */
	public static PivotJoint make(Body b1, Body b2, float anchor1X, float anchor1Y, float anchor2X, float anchor2Y) {
		return new PivotJoint(b1, b2, anchor1X, anchor1Y, anchor2X, anchor2Y);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param anchor1X 锚点1的x坐标
	 * @param anchor1Y 锚点1的y坐标
	 * @param anchor2X 锚点2的x坐标
	 * @param anchor2Y 锚点2的y坐标
	 */
	protected PivotJoint(Body b1, Body b2, float anchor1X, float anchor1Y, float anchor2X, float anchor2Y) {
		init2(b1, b2, anchor1X, anchor1Y, anchor2X, anchor2Y);
	}
	
	public static PivotJoint from(int pointer) {
		return pointer == 0 ? null : new PivotJoint(pointer);
	}
	
	protected PivotJoint(int pointer) {
		super(pointer);
	}

	/**
	 * 构造函数
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param pivotX 轴点x位置
	 * @param pivotY 轴点y位置
	 */
	protected PivotJoint(Body b1, Body b2, float pivotX, float pivotY) {
		init(b1, b2, pivotX, pivotY);
	}

	/**
	 * 创建一个车轴关节
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param x 轴点x位置
	 * @param y 轴点y位置
	 */
	private native void init(Body b1, Body b2, float x, float y);

	/**
	 * 创建一个车轴关节
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param anchor1X 锚点1的x坐标
	 * @param anchor1Y 锚点1的y坐标
	 * @param anchor2X 锚点2的x坐标
	 * @param anchor2Y 锚点2的y坐标
	 */
	private native void init2(Body b1, Body b2, float anchor1X, float anchor1Y, float anchor2X, float anchor2Y);
	
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
