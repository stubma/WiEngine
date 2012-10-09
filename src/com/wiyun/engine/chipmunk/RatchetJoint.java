package com.wiyun.engine.chipmunk;

public class RatchetJoint extends Constraint {
	public static RatchetJoint make(Body b1, Body b2, float phase, float ratchet) {
		return new RatchetJoint(b1, b2, phase, ratchet);
	}
	
	protected RatchetJoint(Body b1, Body b2, float phase, float ratchet) {
		init(b1, b2, phase, ratchet);
	}

	public static RatchetJoint from(int pointer) {
		return pointer == 0 ? null : new RatchetJoint(pointer);
	}
	
	protected RatchetJoint(int pointer) {
		super(pointer);
	}
	
	private native void init(Body b1, Body b2, float phase, float ratchet);
	
	public native float getAngle();
	
	public native void setAngle(float a);
	
	public native float getPhase();
	
	public native void setPhase(float phase);
	
	public native float getRatchet();
	
	public native void setRatchet(float ratchet);
}
