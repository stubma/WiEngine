/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.types.WYPoint;

public class WheelJoint extends Joint {
	public static WheelJoint from(int pointer) {
		return pointer == 0 ? null : new WheelJoint(pointer);
	}

	protected WheelJoint() {
	}

	protected WheelJoint(int pointer) {
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
	 * Get the current joint translation, usually in meters.
	 */
	public native float getJointTranslation();

	/**
	 * Get the current joint translation speed, usually in meters per second.
	 */
	public native float getJointSpeed();

	/**
	 * Is the joint motor enabled?
	 */
	public native boolean isMotorEnabled();

	/**
	 * Enable/disable the joint motor.
	 */
	public native void enableMotor(boolean flag);

	/**
	 * Set the motor speed, usually in meters per second.
	 */
	public native void setMotorSpeed(float speed);

	/**
	 * Get the motor speed, usually in meters per second.
	 */
	public native float getMotorSpeed();

	/**
	 * Set/Get the maximum motor torque
	 */
	public native void setMaxMotorTorque(float torque);
	
	/**
	 * Set/Get the maximum motor torque, usually in N.
	 */
	public native float getMaxMotorTorque();
	
	/**
	 * Get the current motor torque given the inverse time step, usually in N-m.
	 */
	public native float getMotorTorque(float inv_dt);
	
	/**
	 * Set/Get the spring frequency in hertz. Setting the frequency to zero disables the spring.
	 */
	public native void setSpringFrequencyHz(float hz);
	
	/**
	 * Set/Get the spring frequency in hertz. Setting the frequency to zero disables the spring.
	 */
	public native float getSpringFrequencyHz();

	/**
	 * Set/Get the spring damping ratio
	 */
	public native void setSpringDampingRatio(float ratio);
	
	/**
	 * Set/Get the spring damping ratio
	 */
	public native float getSpringDampingRatio();
}
