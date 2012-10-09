package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.types.WYPoint;


public class FrictionJoint extends Joint {
	public static FrictionJoint from(int pointer) {
		return pointer == 0 ? null : new FrictionJoint(pointer);
	}

	protected FrictionJoint() {
	}

	protected FrictionJoint(int pointer) {
		super(pointer);
	}
	
	/**
	 * 获得锚点a, 相对于第一个刚体的局部坐标
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
	 * 获得锚点b, 相对于第二个刚体的局部坐标
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getLocalAnchorB() {
		WYPoint a = WYPoint.makeZero();
		nativeGetLocalAnchorB(a);
		return a;
	}
	
	private native void nativeGetLocalAnchorB(WYPoint a);
	
	/**
	 * Set the maximum friction force in N.
	 */
	public native void setMaxForce(float force);

	/**
	 * Get the maximum friction force in N.
	 */
	public native float getMaxForce();

	/**
	 * Set the maximum friction torque in N*m.
	 */
	public native void setMaxTorque(float torque);

	/**
	 * Get the maximum friction torque in N*m.
	 */
	public native float getMaxTorque();
}
