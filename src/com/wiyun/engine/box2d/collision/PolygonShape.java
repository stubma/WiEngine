package com.wiyun.engine.box2d.collision;

import com.wiyun.engine.box2d.dynamics.World;
import com.wiyun.engine.types.WYPoint;

public class PolygonShape extends Shape {
	public static PolygonShape from(int pointer) {
		return pointer == 0 ? null : new PolygonShape(pointer);
	}
	
	public static PolygonShape make() {
		return new PolygonShape();
	}

	protected PolygonShape() {
		nativeNew();
	}

	private native void nativeNew();

	protected PolygonShape(int pointer) {
		super(pointer);
	}
	
	public PolygonShape clone(World world) {
		return PolygonShape.from(super.copy(world));
	}
	
	/**
	 * 设置顶点
	 * 
	 * @param vertices 顶点数组
	 */
	public native void setVertices(WYPoint[] vertices);
	
	/**
	 * 设置为一个矩形
	 * 
	 * @param x 宽的一半
	 * @param y 高的一半
	 */
	public native void setAsBox(float x, float y);
	
	/**
	 * 设置为一个矩形
	 * 
	 * @param x 宽的一半
	 * @param y 高的一半
	 * @param centerX 矩形中心x
	 * @param centerY 矩形中心y
	 * @param angle 矩形的自身旋转角度, 以弧度为单位
	 */
	public native void setAsBox(float x, float y, float centerX, float centerY, float angle);
	
	/**
	 * 得到多边形的顶点个数
	 * 
	 * @return 多边形的顶点个数
	 */
	public native int getVertexCount();
	
	/**
	 * 得到某个顶点
	 * 
	 * @param index 顶点的索引
	 */
	public WYPoint getVertex(int index) {
		WYPoint p = WYPoint.makeZero();
		nativeGetVertex(p, index);
		return p;
	}
	
	private native void nativeGetVertex(WYPoint p, int index);
	
	/**
	 * 得到重心位置
	 * 
	 * @return 重心位置
	 */
	public WYPoint getCentroid() {
		WYPoint p = WYPoint.makeZero();
		nativeGetCentroid(p);
		return p;
	}
	
	private native void nativeGetCentroid(WYPoint p);
	
	/**
	 * Validate convexity. This is a very time consuming operation.
	 * 
	 * @returns true if valid
	 */
	public native boolean validate();
}
