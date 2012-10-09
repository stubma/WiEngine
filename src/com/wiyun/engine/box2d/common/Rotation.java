package com.wiyun.engine.box2d.common;

import static java.lang.Math.*;

import com.wiyun.engine.types.WYPoint;

/**
 * Rotation
 */
public class Rotation {
	/// Sine
	public float s;
	
	/// cosine
	public float c;
	
	public static Rotation makeIdentity() {
		Rotation r = new Rotation();
		r.s = 0;
		r.c = 1;
		return r;
	}
	
	public static Rotation make(float angle) {
		Rotation r = new Rotation();
		r.s = (float)sin(angle);
		r.c = (float)cos(angle);
		return r;
	}
	
	protected Rotation() {
	}
	
	public void set(float angle) {
		s = (float)sin(angle);
		c = (float)cos(angle);
	}
	
	public void setIdentity() {
		s = 0;
		c = 1;
	}
	
	/**
	 * Get the angle in radians
	 */
	public float getAngle() {
		return (float)atan2(s, c);
	}

	/**
	 * Get the x-axis
	 */
	public WYPoint getXAxis() {
		return WYPoint.make(c, s);
	}

	/**
	 * Get the u-axis
	 */
	public WYPoint GetYAxis() {
		return WYPoint.make(-s, c);
	}
	
	public WYPoint mul(WYPoint v) {
		return WYPoint.make(c * v.x - s * v.y, s * v.x + c * v.y);
	}
}
