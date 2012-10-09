package com.wiyun.engine.box2d.common;

import com.wiyun.engine.types.WYPoint;

/**
 * A transform contains translation and rotation. It is used to represent
 * the position and orientation of rigid frames.
 */
public class Transform {
	public Rotation q;
	public WYPoint p;
	
	public static Transform make() {
		return new Transform();
	}
	
	protected Transform() {
		q = Rotation.makeIdentity();
		p = WYPoint.makeZero();
	}
	
	public void setIdentity() {
		q = Rotation.makeIdentity();
		p = WYPoint.makeZero();
	}
	
	public void set(float x, float y, float angle) {
		p.x = x;
		p.y = y;
		q.set(angle);
	}
	
	public void set(WYPoint position, float angle) {
		p.x = position.x;
		p.y = position.y;
		q.set(angle);
	}
	
	public WYPoint mul(WYPoint v) {
		float x = (q.c * v.x - q.s * v.y) + p.x;
		float y = (q.s * v.x + q.c * v.y) + p.y;

		return WYPoint.make(x, y);
	}
}
