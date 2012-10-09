package com.wiyun.engine.box2d.dynamics.joints;

public class GearJointDef extends JointDef {
	public static GearJointDef make() {
		return new GearJointDef();
	}

	protected GearJointDef() {
		nativeNew();
	}

	private native void nativeNew();

	protected GearJointDef(int pointer) {
		super(pointer);
	}
	
	/**
	 * The first revolute/prismatic joint attached to the gear joint.
	 */
	public native void setJoint1(Joint joint);
	
	/**
	 * The first revolute/prismatic joint attached to the gear joint.
	 */
	public native int getJoint1();

	/**
	 * The second revolute/prismatic joint attached to the gear joint.
	 */
	public native void setJoint2(Joint joint);
	
	/**
	 * The second revolute/prismatic joint attached to the gear joint.
	 */
	public native int getJoint2();

	/**
	 * The gear ratio.
	 */
	public native void setRatio(float ratio);
	
	/**
	 * The gear ratio.
	 */
	public native float getRatio();
}
