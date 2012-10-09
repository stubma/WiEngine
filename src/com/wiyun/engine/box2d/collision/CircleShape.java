package com.wiyun.engine.box2d.collision;

import com.wiyun.engine.box2d.dynamics.World;
import com.wiyun.engine.types.WYPoint;

public class CircleShape extends Shape {
	public static CircleShape from(int pointer) {
		return pointer == 0 ? null : new CircleShape(pointer);
	}
	
	public static CircleShape make() {
		return new CircleShape();
	}

	protected CircleShape() {
		nativeNew();
	}

	private native void nativeNew();

	protected CircleShape(int pointer) {
		super(pointer);
	}
	
	public CircleShape clone(World world) {
		return CircleShape.from(super.copy(world));
	}
	
	/**
	 * 设置圆心位置
	 * 
	 * @param x x位置
	 * @param y y位置
	 */
	public native void setPosition(float x, float y);

	/**
	 * 获得圆心位置
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getPosition() {
		WYPoint p = WYPoint.makeZero();
		nativeGetPosition(p);
		return p;
    }
	
	private native void nativeGetPosition(WYPoint p);
	
	/**
	 * Get the supporting vertex index in the given direction.
	 */
	public int getSupport(WYPoint d) {
		return getSupport(d.x, d.y);
	}
	
	/**
	 * Get the supporting vertex index in the given direction.
	 */
	public native int getSupport(float x, float y);
	
	/**
	 * Get the supporting vertex in the given direction.
	 */
	public WYPoint getSupportVertex(WYPoint d) {
		return getSupportVertex(d.x, d.y);
	}
	
	/**
	 * Get the supporting vertex in the given direction.
	 */
	public WYPoint getSupportVertex(float x, float y) {
		WYPoint p = WYPoint.makeZero();
		nativeGetSupportVertex(p, x, y);
		return p;
	}
	
	private native void nativeGetSupportVertex(WYPoint p, float x, float y);
	
	/**
	 * Get the vertex count.
	 */
	public native int getVertexCount();
	
	/**
	 * Get a vertex by index. Used by b2Distance.
	 */
	public WYPoint getVertex(int index) {
		WYPoint p = WYPoint.makeZero();
		nativeGetVertex(p, index);
		return p;
	}
	
	private native void nativeGetVertex(WYPoint p, int index);
}
