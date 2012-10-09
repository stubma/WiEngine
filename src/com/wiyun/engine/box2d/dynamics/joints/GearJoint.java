package com.wiyun.engine.box2d.dynamics.joints;

public class GearJoint extends Joint {
	public static GearJoint from(int pointer) {
		return pointer == 0 ? null : new GearJoint(pointer);
	}

	protected GearJoint() {
	}

	protected GearJoint(int pointer) {
		super(pointer);
	}
	
	/**
	 * The first revolute/prismatic joint attached to the gear joint.
	 */
	public native int getJoint1();

	/**
	 * The second revolute/prismatic joint attached to the gear joint.
	 */
	public native int getJoint2();
	
	/**
	 * Set/Get the gear ratio.
	 */
	public native void setRatio(float ratio);
	
	/**
	 * Set/Get the gear ratio.
	 */
	public native float getRatio();
}
