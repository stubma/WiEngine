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
