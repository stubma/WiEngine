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

public class MouseJoint extends Joint {
	public static MouseJoint from(int pointer) {
		return pointer == 0 ? null : new MouseJoint(pointer);
	}
	
	protected MouseJoint() {
	}

	protected MouseJoint(int pointer) {
		super(pointer);
	}

	public native void setTarget(float x, float y);
	
	public void setTarget(WYPoint p) {
		setTarget(p.x, p.y);
	}
	
	public WYPoint getTarget() {
		WYPoint p = WYPoint.makeZero();
		nativeGetTarget(p);
		return p;
	}
	
	private native void nativeGetTarget(WYPoint p);

	/**
	 * Set/get the maximum force in Newtons.
	 */
	public native void setMaxForce(float force);
	
	/**
	 * Set/get the maximum force in Newtons.
	 */
	public native float getMaxForce();

	/**
	 * Set/get the frequency in Hertz.
	 */
	public native void setFrequency(float hz);
	
	/**
	 * Set/get the frequency in Hertz.
	 */
	public native float getFrequency();

	/**
	 * Set/get the damping ratio (dimensionless).
	 */
	public native void setDampingRatio(float ratio);
	
	/**
	 * Set/get the damping ratio (dimensionless).
	 */
	public native float getDampingRatio();
}
