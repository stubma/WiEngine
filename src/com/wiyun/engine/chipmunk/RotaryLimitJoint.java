package com.wiyun.engine.chipmunk;

public class RotaryLimitJoint extends Constraint {
	public static RotaryLimitJoint make(Body b1, Body b2, float min, float max) {
		return new RotaryLimitJoint(b1, b2, min, max);
	}
	
	protected RotaryLimitJoint(Body b1, Body b2, float min, float max) {
		init(b1, b2, min, max);
	}

	public static RotaryLimitJoint from(int pointer) {
		return pointer == 0 ? null : new RotaryLimitJoint(pointer);
	}
	
	protected RotaryLimitJoint(int pointer) {
		super(pointer);
	}
	
	private native void init(Body b1, Body b2, float min, float max);
	
	public native float getMin();
	
	public native void setMin(float min);
	
	public native float getMax();
	
	public native void setMax(float max);
}
