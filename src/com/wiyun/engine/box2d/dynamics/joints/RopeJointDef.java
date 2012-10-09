package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.types.WYPoint;

public class RopeJointDef extends JointDef {
	public static RopeJointDef make() {
		return new RopeJointDef();
	}

	protected RopeJointDef() {
		nativeNew();
	}

	private native void nativeNew();

	protected RopeJointDef(int pointer) {
		super(pointer);
	}
	
	/**
	 * The local anchor point relative to bodyA's origin.
	 */
	public native void setLocalAnchorA(WYPoint a);

	/**
	 * The local anchor point relative to bodyB's origin.
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
	 * The maximum length of the rope.
	 * Warning: this must be larger than b2_linearSlop or
	 * the joint will have no effect.
	 */
	public native void setMaxLength(float maxLen);
	
	/**
	 * The maximum length of the rope.
	 * Warning: this must be larger than b2_linearSlop or
	 * the joint will have no effect.
	 */
	public native float getMaxLength();
}
