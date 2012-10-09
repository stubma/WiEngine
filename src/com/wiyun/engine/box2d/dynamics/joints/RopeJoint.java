package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.types.WYPoint;

public class RopeJoint extends Joint {
	public static RopeJoint from(int pointer) {
		return pointer == 0 ? null : new RopeJoint(pointer);
	}

	protected RopeJoint() {
	}

	protected RopeJoint(int pointer) {
		super(pointer);
	}
	
	/**
	 * 获得锚点a, 相对于第一个刚体的局部坐标
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getLocalAnchorA() {
		WYPoint a = WYPoint.makeZero();
		nativeGetLocalAnchorA(a);
		return a;
	}
	
	private native void nativeGetLocalAnchorA(WYPoint a);
	
	/**
	 * 获得锚点b, 相对于第二个刚体的局部坐标
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getLocalAnchorB() {
		WYPoint a = WYPoint.makeZero();
		nativeGetLocalAnchorB(a);
		return a;
	}
	
	private native void nativeGetLocalAnchorB(WYPoint a);
	
	/**
	 * 得到绳子最大长度
	 */
	public native float getMaxLength();
	
	/**
	 * 设置绳子最大长度
	 */
	public native void setMaxLength(float length);
	
	/**
	 * 得到当前长度
	 */
	public native float getLength();

	public native int getLimitState();
}
