package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.types.WYPoint;

public class PulleyJoint extends Joint {
	public static PulleyJoint from(int pointer) {
		return pointer == 0 ? null : new PulleyJoint(pointer);
	}
	
	protected PulleyJoint() {
	}

	protected PulleyJoint(int pointer) {
		super(pointer);
	}
	
	/**
	 * Get the first ground anchor.
	 */
	public WYPoint getGroundAnchorA() {
		WYPoint a = WYPoint.makeZero();
		nativeGetGroundAnchorA(a);
		return a;
	}
	
	private native void nativeGetGroundAnchorA(WYPoint p);

	/**
	 * Get the second ground anchor.
	 */
	public WYPoint getGroundAnchorB() {
		WYPoint a = WYPoint.makeZero();
		nativeGetGroundAnchorB(a);
		return a;
	}
	
	private native void nativeGetGroundAnchorB(WYPoint p);

	/**
	 * Get the current length of the segment attached to body1.
	 */
	public native float getLengthA();

	/**
	 * Get the current length of the segment attached to body2.
	 */
	public native float getLengthB();

	/**
	 * Get the pulley ratio.
	 */
	public native float getRatio();
}
