package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.types.WYPoint;

public class WeldJointDef extends JointDef {
	public static WeldJointDef make() {
		return new WeldJointDef();
	}

	protected WeldJointDef() {
		nativeNew();
	}

	private native void nativeNew();

	protected WeldJointDef(int pointer) {
		super(pointer);
	}

	public native void initialize(Body body1, Body body2, float anchorX, float anchorY);
	
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
	 * The body2 angle minus body1 angle in the reference state (radians).
	 */
	public native void setReferenceAngle(float angle);
	
	/**
	 * The body2 angle minus body1 angle in the reference state (radians).
	 */
	public native float getReferenceAngle();
}
