package com.wiyun.engine.types;

import static java.lang.Math.*;

public class WYPoint {
	private static final float FLT_EPSILON = 1.19209290e-07f;
	
	public float x, y;
	
	/**
	 * 生成一个全0的WYPoint
	 * 
	 * @return {@link WYPoint}
	 */
	public static WYPoint makeZero() {
		return new WYPoint(0, 0);
	}
	
	/**
	 * 生成一个WYPoint数组
	 * 
	 * @param size 数组大小
	 * @return {@link WYPoint}数组
	 */
	public static WYPoint[] makeArray(int size) {
		WYPoint[] p = new WYPoint[size];
		for(int i = 0; i < size; i++)
			p[i] = makeZero();
		return p;
	}
	
	/**
	 * 给定一个弧度，创建这个弧度上的单位向量
	 * 
	 * @param r 弧度
	 * @return {@link WYPoint}
	 */
	public static WYPoint makeByRadian(float r) {
		return make((float)cos(r), (float)sin(r));
	}

	protected WYPoint() {
		this(0, 0);
	}

	protected WYPoint(float x, float y) {
		this.x = x;
		this.y = y;
	}
	
	/**
	 * 给x，y加上指定的值
	 * 
	 * @param dx 要加的x值
	 * @param dy 要加的y值
	 */
	public void translate(float dx, float dy) {
		x += dx;
		y += dy;
	}

	@Override
	public String toString() {
		return "(" + x + ", " + y + ")";
	}

	public static boolean isEqual(WYPoint p1, WYPoint p2) {
		return p1.x == p2.x && p1.y == p2.y;
	}

	public WYPoint applyTransform(WYAffineTransform aTransform) {
		return aTransform.transform(this);
	}

	/**
	 * Helper macro that creates a WYPoint
	 *
	 * @return WYPoint
	 */
	public static WYPoint make(float x, float y) {
		return new WYPoint(x, y);
	}
	
	/**
	 * Returns opposite of point.
	 *
	 * @return WYPoint
	 */
	public static WYPoint negate(WYPoint v) {
		return make(-v.x, -v.y);
	}

	/**
	 * Calculates sum of two points.
	 *
	 * @return WYPoint
	 */
	public static WYPoint add(WYPoint v1, WYPoint v2) {
		return make(v1.x + v2.x, v1.y + v2.y);
	}

	/**
	 * Calculates difference of two points.
	 *
	 * @return WYPoint
	 */
	public static WYPoint sub(WYPoint v1, WYPoint v2) {
		return make(v1.x - v2.x, v1.y - v2.y);
	}

	/**
	 * Returns point multiplied by given factor.
	 *
	 * @return WYPoint
	 */
	public static WYPoint mul(WYPoint v, float s) {
		return make(v.x * s, v.y * s);
	}
	
	/**
	 * Returns point multiplied by given point.
	 *
	 * @return WYPoint
	 */
	public static WYPoint mul(WYPoint v, WYPoint v2) {
		return make(v.x * v2.x, v.y * v2.y);
	}

	/**
	 * Calculates midpoint between two points.
	 *
	 * @return WYPoint
	 */
	public static WYPoint midpoint(WYPoint v1, WYPoint v2) {
		return mul(add(v1, v2), 0.5f);
	}

	/**
	 * Calculates dot product of two points.
	 *
	 * @return float
	 */
	public static float dot(WYPoint v1, WYPoint v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}

	/**
	 * Calculates cross product of two points.
	 *
	 * @return float
	 */
	public static float cross(WYPoint v1, WYPoint v2) {
		return v1.x * v2.y - v1.y * v2.x;
	}
	
	public static WYPoint cross(float s, WYPoint v) {
		return WYPoint.make(-s * v.y, s * v.x);
	}

	/**
	 * Calculates perpendicular of v, rotated 90 degrees counter-clockwise -- cross(v, perp(v)) >= 0
	 *
	 * @return WYPoint
	 */
	public static WYPoint perp(WYPoint v) {
		return make(-v.y, v.x);
	}

	/**
	 * Calculates perpendicular of v, rotated 90 degrees clockwise -- cross(v, rperp(v)) <= 0
	 *
	 * @return WYPoint
	 */
	public static WYPoint rperp(WYPoint v) {
		return make(v.y, -v.x);
	}

	/**
	 * Calculates the projection of v1 over v2.
	 *
	 * @return WYPoint
	 */
	public static WYPoint project(WYPoint v1, WYPoint v2) {
		return mul(v2, dot(v1, v2) / dot(v2, v2));
	}

	/**
	 * Rotates two points.
	 *
	 * @return WYPoint
	 */
	public static WYPoint rotate(WYPoint v1, WYPoint v2) {
		return make(v1.x * v2.x - v1.y * v2.y, v1.x * v2.y + v1.y * v2.x);
	}
	
	/**
	 * Rotate a point
	 * 
	 * @param v point to rotate
	 * @param pivot pivot point
	 * @param angle rotate angle, in radians
	 * @return rotated point
	 */
	public static WYPoint rotateByAngle(WYPoint v, WYPoint pivot, float angle) {
		WYPoint r = sub(v, pivot);
		float t = r.x;
		float cosa = (float)cos(angle), sina = (float)sin(angle);
		r.x = t * cosa - r.y * sina;
		r.y = t * sina + r.y * cosa;
		r = add(r, pivot);
		return r;
	}

	/**
	 * Unrotate two points.
	 *
	 * @return WYPoint
	 */
	public static WYPoint unrotate(WYPoint v1, WYPoint v2) {
		return make(v1.x * v2.x + v1.y * v2.y, v1.y * v2.x - v1.x * v2.y);
	}
	
	public static WYPoint lerp(WYPoint a, WYPoint b, float alpha) {
		return add(mul(a, 1.f - alpha), mul(b, alpha));
	}
	
	public static WYPoint slerp(WYPoint a, WYPoint b, float t) {
		float omega = (float)acos(dot(a, b));

		if(omega != 0f) {
			float denom = 1.0f / (float)sin(omega);
			return add(mul(a, (float)sin((1.0f - t) * omega) * denom), mul(b, (float)sin(t * omega) * denom));
		} else {
			return a;
		}
	}
	 
	public static boolean fuzzyEqual(WYPoint a, WYPoint b, float var) {
		if(a.x - var <= b.x && b.x <= a.x + var)
			if(a.y - var <= b.y && b.y <= a.y + var)
				return true;
		return false;
	}

	public static boolean lineIntersect(WYPoint p1, WYPoint p2, WYPoint p3, WYPoint p4, float[] st) {
		WYPoint p13, p43, p21;
		float d1343, d4321, d1321, d4343, d2121;
		float numer, denom;

		p13 = sub(p1, p3);
		p43 = sub(p4, p3);

		//Roughly equal to zero but with an epsilon deviation for float 
		//correction
		WYPoint zero = WYPoint.makeZero();
		if(fuzzyEqual(p43, zero, FLT_EPSILON))
			return false;

		p21 = sub(p2, p1);

		//Roughly equal to zero
		if(fuzzyEqual(p21, zero, FLT_EPSILON))
			return false;

		d1343 = dot(p13, p43);
		d4321 = dot(p43, p21);
		d1321 = dot(p13, p21);
		d4343 = dot(p43, p43);
		d2121 = dot(p21, p21);

		denom = d2121 * d4343 - d4321 * d4321;
		if(abs(denom) < FLT_EPSILON)
			return false;
		numer = d1343 * d4321 - d1321 * d4343;

		st[0] = numer / denom;
		st[1] = (d1343 + d4321 * (st[0])) / d4343;

		return true;
	}

	/**
	 * Calculates distance between point an origin
	 *
	 * @return float
	 */
	public static float length(WYPoint v) {
		return (float)Math.sqrt(dot(v, v));
	}
	
	public static float lengthsq(WYPoint v) {
		return dot(v, v);
	}

	/**
	 * Calculates the distance between two points
	 *
	 * @return float
	 */
	public static float distance(WYPoint v1, WYPoint v2) {
		return length(sub(v1, v2));
	}
	
	/**
	 * 得到两个点之间的距离的平方
	 * 
	 * @param v1 点1
	 * @param v2 点2
	 * @return 距离的平方
	 */
	public static float distancesq(WYPoint v1, WYPoint v2) {
		return lengthsq(sub(v1, v2));
	}
	
	/**
	 * 判断两个点之间的距离是否小于<code>distance</code>
	 * 
	 * @param v1 点1
	 * @param v2 点2
	 * @param distance 距离
	 * @return true表示两个点之间的距离小于<code>distance</code>
	 */
	public static boolean near(WYPoint v1, WYPoint v2, float distance) {
		return distancesq(v1, v2) < distance * distance;
	}

	/**
	 * Returns point multiplied to a length of 1.
	 *
	 * @return WYPoint
	 */
	public static WYPoint normalize(WYPoint v) {
		return mul(v, 1.0f / length(v));
	}

	/**
	 * Converts radians to a normalized vector.
	 *
	 * @return WYPoint
	 */
	public static WYPoint toAngle(float a) {
		return make((float)Math.cos(a), (float)Math.sin(a));
	}

	/**
	 * Converts a vector to radians.
	 *
	 * @return float
	 */
	public static float toRadian(WYPoint v) {
		return (float)Math.atan2(v.y, v.x);
	}
}
