package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.types.WYPoint;

public class RevoluteJoint extends Joint {
	public static RevoluteJoint from(int pointer) {
		return pointer == 0 ? null : new RevoluteJoint(pointer);
	}

	protected RevoluteJoint() {
	}

	protected RevoluteJoint(int pointer) {
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
	 * Get the current joint angle in radians.
	 */
	public native float getJointAngle();

	/**
	 * Get the current joint angle speed in radians per second.
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
	 * Get the lower joint limit in radians.
	 */
	public native float getLowerLimit();

	/**
	 * Get the upper joint limit in radians.
	 */
	public native float getUpperLimit();

	/**
	 * Set the joint limits in radians.
	 */
	public native void setLimits(float lower, float upper);

	/**
	 * Set the motor speed in radians per second.
	 */
	public native void setMotorSpeed(float speed);

	/**
	 * Get the motor speed in radians per second.
	 */
	public native float getMotorSpeed();

	/**
	 * Set the maximum motor torque, usually in N-m.
	 */
	public native void setMaxMotorTorque(float torque);
	
	/**
	 * Get the maximum motor torque, usually in N-m.
	 */
	public native float getMaxMotorTorque();

	/**
	 * Get the current motor torque given the inverse time step.
	 * Unit is N*m.
	 */
	public native float getMotorTorque(float inv_dt);
}
