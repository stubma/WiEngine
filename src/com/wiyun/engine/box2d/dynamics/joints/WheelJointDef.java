package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.types.WYPoint;

public class WheelJointDef extends JointDef {
	public static WheelJointDef make() {
		return new WheelJointDef();
	}
	
	protected WheelJointDef() {
		nativeNew();
	}

	private native void nativeNew();

	protected WheelJointDef(int pointer) {
		super(pointer);
	}
	
	/**
	 * Initialize the bodies, anchors, axis, and reference angle using the world
	 * anchor and world axis.
	 */
	public native void initialize(Body bodyA, Body bodyB, float anchorX, float anchorY, float axisX, float axisY);
	
	/**
	 * The local anchor point relative to body1's origin.
	 */
	public native void setLocalAnchorA(float x, float y);

	/**
	 * The local anchor point relative to body2's origin.
	 */
	public native void setLocalAnchorB(float x, float y);
	
	/**
	 * The local translation axis in body1.
	 */
	public native void setLocalAxisA(float x, float y);

	/**
	 * A flag to enable the joint motor.
	 */
	public native void setEnableMotor(boolean flag);
	
	/**
	 * A flag to enable the joint motor.
	 */
	public native boolean isEnableMotor();

	/**
	 * The desired motor speed. Usually in radians per second.
	 */
	public native void setMotorSpeed(float speed);
	
	/**
	 * The desired motor speed. Usually in radians per second.
	 */
	public native float getMotorSpeed();

	/**
	 * The maximum motor torque used to achieve the desired motor speed.
	 * Usually in N-m.
	 */
	public native void setMaxMotorTorque(float torque);
	
	/**
	 * The maximum motor torque used to achieve the desired motor speed.
	 * Usually in N-m.
	 */
	public native float getMaxMotorTorque();
	
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
	
	/**
	 * The local translation axis in body1.
	 */
	public WYPoint getLocalAxisA() {
		WYPoint a = WYPoint.makeZero();
		nativeGetLocalAxisA(a);
		return a;
	}
	
	private native void nativeGetLocalAxisA(WYPoint a);
	
	/**
	 * Suspension frequency, zero indicates no suspension
	 */
	public native void setFrequency(float f);
	
	/**
	 * Suspension frequency, zero indicates no suspension
	 * @return
	 */
	public native float getFrequency();
	
	/**
	 * Suspension damping ratio, one indicates critical damping
	 * @param dr
	 */
	public native void setDampingRatio(float dr);
	
	/**
	 * Suspension damping ratio, one indicates critical damping
	 * @return
	 */
	public native float getDampingRatio();
}
