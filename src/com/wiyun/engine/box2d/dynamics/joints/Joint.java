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

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.types.WYPoint;

public class Joint extends BaseObject {
	// limit state for rope joint
	public static final int LIMIT_STATE_INACTIVE = 0;
	public static final int LIMIT_STATE_AT_LOWER = 1;
	public static final int LIMIT_STATE_AT_UPPER = 2;
	public static final int LIMIT_STATE_EQUAL = 3;
	
	public static Joint from(int pointer) {
		return pointer == 0 ? null : new Joint(pointer);
	}
	
	protected Joint() {
	}

	protected Joint(int pointer) {
		super(pointer);
	}
	
	/**
	 * 获得连接点的刚体A
	 * 
	 * @return {@link Body}
	 */
	public Body getBodyA() {
		return Body.from(nativeGetBodyA());
	}
	
	private native int nativeGetBodyA();
	
	/**
	 * 获得连接点的刚体B
	 * 
	 * @return {@link Body}
	 */
	public Body getBodyB() {
		return Body.from(nativeGetBodyB());
	}
	
	private native int nativeGetBodyB();
	
	/**
	 * 获得锚点a, 坐标为box2d的全局坐标
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getAnchorA() {
		WYPoint a = WYPoint.makeZero();
		nativeGetAnchorA(a);
		return a;
	}
	
	private native void nativeGetAnchorA(WYPoint a);
	
	/**
	 * 获得锚点b, 坐标为box2d的全局坐标
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getAnchorB() {
		WYPoint a = WYPoint.makeZero();
		nativeGetAnchorB(a);
		return a;
	}
	
	private native void nativeGetAnchorB(WYPoint a);
	
	
	/**
	 * Get the reaction force given the inverse time step.
	 * Unit is N.
	 */
	public WYPoint getReactionForce(float inv_dt) {
		WYPoint a = WYPoint.makeZero();
		nativeGetReactionForce(a, inv_dt);
		return a;
	}
	
	private native void nativeGetReactionForce(WYPoint p, float inv_dt);

	/**
	 * Get the reaction torque given the inverse time step.
	 * Unit is N*m. This is always zero for a distance joint.
	 */
	public native float getReactionTorque(float inv_dt);
	
	/**
	 * 得到用户自定义数据对象
	 * 
	 * @return {@link Object}
	 */
	public native Object getUserData();
	
	/**
	 * 设置用户自定义数据对象
	 * 
	 * @param obj {@link Object}
	 */
	public native void setUserData(Object obj);
}
