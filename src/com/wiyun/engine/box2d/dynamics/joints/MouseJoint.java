package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.types.WYPoint;

public class MouseJoint extends Joint {
	public static MouseJoint from(int pointer) {
		return pointer == 0 ? null : new MouseJoint(pointer);
	}
	
	protected MouseJoint() {
	}

	protected MouseJoint(int pointer) {
		super(pointer);
	}

	public native void setTarget(float x, float y);
	
	public void setTarget(WYPoint p) {
		setTarget(p.x, p.y);
	}
	
	public WYPoint getTarget() {
		WYPoint p = WYPoint.makeZero();
		nativeGetTarget(p);
		return p;
	}
	
	private native void nativeGetTarget(WYPoint p);

	/**
	 * Set/get the maximum force in Newtons.
	 */
	public native void setMaxForce(float force);
	
	/**
	 * Set/get the maximum force in Newtons.
	 */
	public native float getMaxForce();

	/**
	 * Set/get the frequency in Hertz.
	 */
	public native void setFrequency(float hz);
	
	/**
	 * Set/get the frequency in Hertz.
	 */
	public native float getFrequency();

	/**
	 * Set/get the damping ratio (dimensionless).
	 */
	public native void setDampingRatio(float ratio);
	
	/**
	 * Set/get the damping ratio (dimensionless).
	 */
	public native float getDampingRatio();
}
