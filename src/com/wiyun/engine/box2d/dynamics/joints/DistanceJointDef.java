package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.types.WYPoint;

public class DistanceJointDef extends JointDef {
	public static DistanceJointDef make() {
		return new DistanceJointDef();
	}

	protected DistanceJointDef() {
		nativeNew();
	}

	private native void nativeNew();

	protected DistanceJointDef(int pointer) {
		super(pointer);
	}
	
	/**
	 * Initialize the bodies, anchors, and reference angle using a world
	 * anchor point.
	 */
	public native void initialize(Body bodyA, Body bodyB, float aX, float aY, float bX, float bY);
	
	/**
	 * The local anchor point relative to body1's origin.
	 */
	public native void setLocalAnchorA(float x, float y);

	/**
	 * The local anchor point relative to body2's origin.
	 */
	public native void setLocalAnchorB(float x, float y);
	
	/**
	 * The natural length between the anchor points.
	 */
	public native void setLength(float len);
	
	/**
	 * The natural length between the anchor points.
	 */
	public native float getLength();

	/**
	 * The mass-spring-damper frequency in Hertz.
	 */
	public native void setFrequencyHz(float f);
	
	/**
	 * The mass-spring-damper frequency in Hertz.
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
}
