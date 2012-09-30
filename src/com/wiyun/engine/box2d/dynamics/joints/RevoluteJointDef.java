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

import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.types.WYPoint;

public class RevoluteJointDef extends JointDef {
	public static RevoluteJointDef make() {
		return new RevoluteJointDef();
	}

	protected RevoluteJointDef() {
		nativeNew();
	}

	private native void nativeNew();

	protected RevoluteJointDef(int pointer) {
		super(pointer);
	}
	
	/**
	 * Initialize the bodies, anchors, and reference angle using a world
	 * anchor point.
	 */
	public native void initialize(Body bodyA, Body bodyB, float anchorX, float anchorY);
	
	/**
	 * The local anchor point relative to body1's origin.
	 */
	public native void setLocalAnchorA(float x, float y);
	
	/**
	 * The local anchor point relative to body1's origin.
	 */
	public native void setLocalAnchorA(WYPoint a);

	/**
	 * The local anchor point relative to body2's origin.
	 */
	public native void setLocalAnchorB(float x, float y);
	
	/**
	 * The local anchor point relative to body2's origin.
	 */
	public native void setLocalAnchorB(WYPoint a);
	
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
	 * The body2 angle minus body1 angle in the reference state (radians).
	 */
	public native void setReferenceAngle(float angle);
	
	/**
	 * The body2 angle minus body1 angle in the reference state (radians).
	 */
	public native float getReferenceAngle();

	/**
	 * A flag to enable joint limits.
	 */
	public native void setEnableLimit(boolean flag);
	
	/**
	 * A flag to enable joint limits.
	 */
	public native boolean isEnableLimit();

	/**
	 * The lower angle for the joint limit (radians).
	 */
	public native void setLowerAngle(float angle);
	
	/**
	 * The lower angle for the joint limit (radians).
	 */
	public native float getLowerAngle();

	/**
	 * The upper angle for the joint limit (radians).
	 */
	public native void setUpperAngle(float angle);
	
	/**
	 * The upper angle for the joint limit (radians).
	 */
	public native float getUpperAngle();

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
}
