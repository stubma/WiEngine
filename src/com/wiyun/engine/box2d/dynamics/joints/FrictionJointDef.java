package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.types.WYPoint;

public class FrictionJointDef extends JointDef {
	public static FrictionJointDef make() {
		return new FrictionJointDef();
	}
	
	protected FrictionJointDef() {
		nativeNew();
	}

	private native void nativeNew();

	protected FrictionJointDef(int pointer) {
		super(pointer);
	}
	
	/**
	 * 设置锚点a
	 * 
	 * @param x 锚点a的x坐标
	 * @param y 锚点a的y坐标
	 */
	public native void setLocalAnchorA(float x, float y);
	
	/**
	 * 设置锚点b
	 * 
	 * @param x 锚点b的x坐标
	 * @param y 锚点b的y坐标
	 */
	public native void setLocalAnchorB(float x, float y);
	
	/**
	 * 设置可以施加的最大力
	 * 
	 * @param maxForce 最大力
	 */
	public native void setMaxForce(float maxForce);
	
	/**
	 * 获得可以施加的最大力
	 * 
	 * @return 可以施加的最大力
	 */
	public native float getMaxForce();
	
	/**
	 * 设置最大力矩
	 * 
	 * @param maxTorque 最大力矩
	 */
	public native void setMaxTorque(float maxTorque);
	
	/**
	 * 获得最大力矩
	 * 
	 * @return 最大力矩
	 */
	public native float getMaxTorque();
	
	/**
	 * 获得锚点a
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getLocalAnchorA() {
		WYPoint a = WYPoint.makeZero();
		nativeGetLocalAnchorA(a);
		return a;
	}
	
	private native void nativeGetLocalAnchorA(WYPoint a);
	
	/**
	 * 获得锚点b
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getLocalAnchorB() {
		WYPoint a = WYPoint.makeZero();
		nativeGetLocalAnchorB(a);
		return a;
	}
	
	private native void nativeGetLocalAnchorB(WYPoint a);
}
