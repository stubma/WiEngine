package com.wiyun.engine.box2d.collision;

import com.wiyun.engine.box2d.dynamics.World;
import com.wiyun.engine.types.WYPoint;

public class EdgeShape extends Shape {
	public static EdgeShape from(int pointer) {
		return pointer == 0 ? null : new EdgeShape(pointer);
	}
	
	public static EdgeShape make() {
		return new EdgeShape();
	}
	
	protected EdgeShape() {
		nativeNew();
	}

	private native void nativeNew();

	protected EdgeShape(int pointer) {
		super(pointer);
	}
	
	public EdgeShape clone(World world) {
		return EdgeShape.from(super.copy(world));
	}
	
	/**
	 * 设置线形物体的端点
	 * 
	 * @param x1 端点1坐标x值
	 * @param y1 端点1坐标y值
	 * @param x2 端点2坐标x值
	 * @param y2 端点2坐标y值
	 */
	public native void setEndpoints(float x1, float y1, float x2, float y2);
	
	/**
	 * 获得端点1
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getEndpoint1() {
		WYPoint p = WYPoint.makeZero();
		nativeGetEndpoint1(p);
		return p;
	}
	
	private native void nativeGetEndpoint1(WYPoint p);
	
	/**
	 * 获得端点2
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getEndpoint2() {
		WYPoint p = WYPoint.makeZero();
		nativeGetEndpoint2(p);
		return p;
	}
	
	private native void nativeGetEndpoint2(WYPoint p);
	
	public native boolean hasAdjacentVertex1();
	
	public native boolean hasAdjacentVertex2();
	
	public WYPoint getAdjacentVertex1() {
		WYPoint p = WYPoint.makeZero();
		nativeGetAdjacentVertex1(p);
		return p;
	}
	
	private native void nativeGetAdjacentVertex1(WYPoint p);
	
	public WYPoint getAdjacentVertex2() {
		WYPoint p = WYPoint.makeZero();
		nativeGetAdjacentVertex2(p);
		return p;
	}
	
	private native void nativeGetAdjacentVertex2(WYPoint p);
}
