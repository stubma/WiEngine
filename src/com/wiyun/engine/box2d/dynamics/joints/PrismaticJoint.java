package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.types.WYPoint;


public class PrismaticJoint extends Joint {
	public static PrismaticJoint from(int pointer) {
		return pointer == 0 ? null : new PrismaticJoint(pointer);
	}

	protected PrismaticJoint() {
	}

	protected PrismaticJoint(int pointer) {
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
	 * The local translation axis in body1.
	 */
	public WYPoint getLocalAxisA() {
		WYPoint a = WYPoint.makeZero();
		nativeGetLocalAxisA(a);
		return a;
	}
	
	private native void nativeGetLocalAxisA(WYPoint a);
	
	/**
	 * The body2 angle minus body1 angle in the reference state (radians).
	 */
	public native float getReferenceAngle();

	/**
	 * Is the joint motor enabled?
	 */
	public native boolean isMotorEnabled();

	/**
	 * Enable/disable the joint motor.
	 */
	public native void enableMotor(boolean flag);
	
	/**
	 * Get the current joint translation, usually in meters.
	 */
	public native float getJointTranslation();

	/**
	 * Get the current joint translation speed, usually in meters per second.
	 */
	public native float getJointSpeed();

	/**
	 * Is the joint limit enabled?
	 */
	public native boolean isLimitEnabled();

	/**
	 * Enable/disable the joint limit.
	 */
	public native void enableLimit(boolean flag);

	/**
	 * Get the lower joint limit, usually in meters.
	 */
	public native float getLowerLimit();

	/**
	 * Get the upper joint limit, usually in meters.
	 */
	public native float getUpperLimit();

	/**
	 * Set the joint limits, usually in meters.
	 */
	public native void setLimits(float lower, float upper);

	/**
	 * Set the motor speed, usually in meters per second.
	 */
	public native void setMotorSpeed(float speed);

	/**
	 * Get the motor speed, usually in meters per second.
	 */
	public native float getMotorSpeed();

	/**
	 * Set the maximum motor force, usually in N.
	 */
	public native void setMaxMotorForce(float force);
	
	/**
	 * Get the maximum motor torque, usually in N-m.
	 */
	public native float getMaxMotorForce();

	/**
	 * Get the current motor force given the inverse time step, usually in N.
	 */
	public native float getMotorForce(float inv_dt);
}
