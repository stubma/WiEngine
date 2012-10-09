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
