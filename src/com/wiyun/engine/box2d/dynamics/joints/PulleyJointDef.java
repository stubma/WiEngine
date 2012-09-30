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

public class PulleyJointDef extends JointDef {
	public static PulleyJointDef make() {
		return new PulleyJointDef();
	}

	protected PulleyJointDef() {
		nativeNew();
	}

	private native void nativeNew();

	protected PulleyJointDef(int pointer) {
		super(pointer);
	}
	
	/**
	 * Initialize the bodies, anchors, lengths, max lengths, and ratio using the world anchors.
	 */
	public native void initialize(Body bodyA, Body bodyB,
					WYPoint groundAnchorA, WYPoint groundAnchorB,
					WYPoint anchorA, WYPoint anchorB,
					float ratio);

	/**
	 * The first ground anchor in world coordinates. This point never moves.
	 */
	public native void setGroundAnchorA(WYPoint a);

	/**
	 * The second ground anchor in world coordinates. This point never moves.
	 */
	public native void setGroundAnchorB(WYPoint a);

	/**
	 * The local anchor point relative to bodyA's origin.
	 */
	public native void setLocalAnchorA(WYPoint a);

	/**
	 * The local anchor point relative to bodyB's origin
	 */
	public native void setLocalAnchorB(WYPoint a);
	
	/**
	 * The first ground anchor in world coordinates. This point never moves.
	 */
	public WYPoint getGroundAnchorA() {
		WYPoint a = WYPoint.makeZero();
		nativeGetGroundAnchorA(a);
		return a;
	}
	
	private native void nativeGetGroundAnchorA(WYPoint a);
	
	/**
	 * The second ground anchor in world coordinates. This point never moves.
	 */
	public WYPoint setGroundAnchorB() {
		WYPoint a = WYPoint.makeZero();
		nativeGetGroundAnchorB(a);
		return a;
	}
	
	private native void nativeGetGroundAnchorB(WYPoint a);
	
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
	 * The a reference length for the segment attached to bodyA.
	 */
	public native void setLengthA(float len);
	
	/**
	 * The a reference length for the segment attached to bodyA.
	 */
	public native float getLengthA();

	/**
	 * The a reference length for the segment attached to bodyB.
	 */
	public native void setLengthB(float len);
	
	/**
	 * The a reference length for the segment attached to bodyB.
	 */
	public native float getLengthB();

	/**
	 * The pulley ratio, used to simulate a block-and-tackle.
	 */
	public native void setRatio(float ratio);
	
	/**
	 * The pulley ratio, used to simulate a block-and-tackle.
	 */
	public native float getRatio();
}
