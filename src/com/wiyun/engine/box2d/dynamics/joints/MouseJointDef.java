package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.types.WYPoint;


public class MouseJointDef extends JointDef {
	public static MouseJointDef make() {
		return new MouseJointDef();
	}

	protected MouseJointDef() {
		nativeNew();
	}

	private native void nativeNew();

	protected MouseJointDef(int pointer) {
		super(pointer);
	}
	
	/**
	 * 设置初始坐标
	 * 
	 * @param x 初始坐标x位置
	 * @param y 初始坐标y位置
	 */
	public native void setTarget(float x, float y);
	
	/**
	 * 得到初始坐标
	 */
	public WYPoint getTarget() {
		WYPoint a = WYPoint.makeZero();
		nativeGetTarget(a);
		return a;
	}
	
	private native void nativeGetTarget(WYPoint a);
	
	/**
	 * 设置可以施加的最大力
	 * 
	 * @param maxForce 最大力
	 */
	public native void setMaxForce(float maxForce);
	
	/**
	 * 获得可以施加的最大力
	 * 
	 * @return 最大力
	 */
	public native float getMaxForce();
	
	/**
	 * The response speed.
	 */
	public native void setFrequencyHz(float f);
	
	/**
	 * The response speed.
	 */
	public native float getFrequencyHz();

	/**
	 * The damping ratio. 0 = no damping, 1 = critical damping.
	 */
	public native void setDampingRatio(float damping);
	
	/**
	 * The damping ratio. 0 = no damping, 1 = critical damping.
	 */
	public native float getDampingRatio();
}
