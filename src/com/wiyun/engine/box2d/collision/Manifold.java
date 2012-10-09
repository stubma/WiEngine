package com.wiyun.engine.box2d.collision;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.types.WYPoint;

public class Manifold extends BaseObject {
	// manifold type
	public static final int TYPE_CIRCLES = 0;
	public static final int TYPE_FACE_A = 1;
	public static final int TYPE_FACE_B = 2;
	
	public static Manifold from(int pointer) {
		return pointer == 0 ? null : new Manifold(pointer);
	}
	
	protected Manifold() {
	}

	protected Manifold(int pointer) {
		super(pointer);
	}
	
	/**
	 * 获得Manifold中的接触点个数
	 * 
	 * @return 接触点个数
	 */
	public native int getPointCount();
	
	/**
	 * 销毁底层对象
	 */
	public native void destroy();
	
	/**
	 * 获得manifold类型
	 * 
	 * @return 类型
	 * @see #TYPE_CIRCLES
	 * @see #TYPE_FACE_A
	 * @see #TYPE_FACE_B
	 */
	public native int getType();
	
	/**
	 * 获得碰撞点的本地坐标，具体含义和类型相关
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getLocalPoint() {
		WYPoint p = WYPoint.makeZero();
		nativeGetLocalPoint(p);
		return p;
	}
	
	private native void nativeGetLocalPoint(WYPoint p);
	
	/**
	 * 获得碰撞点的法线，具体含义和类型相关
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getLocalNormal() {
		WYPoint p = WYPoint.makeZero();
		nativeGetLocalNormal(p);
		return p;
	}
	
	private native void nativeGetLocalNormal(WYPoint p);
	
	/**
	 * 得到碰撞点信息
	 * 
	 * @param index 索引
	 * @return {@link ManifoldPoint}
	 */
	public ManifoldPoint getManifoldPoint(int index) {
		ManifoldPoint mp = new ManifoldPoint();
		nativeGetManifoldPoint(index, mp);
		return mp;
	}
	
	private native void nativeGetManifoldPoint(int index, ManifoldPoint mp);
}
