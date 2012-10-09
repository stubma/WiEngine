package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.types.WYPoint;

public class WeldJoint extends Joint {
	public static WeldJoint from(int pointer) {
		return pointer == 0 ? null : new WeldJoint(pointer);
	}

	protected WeldJoint() {
	}

	protected WeldJoint(int pointer) {
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
	 * The body2 angle minus body1 angle in the reference state (radians).
	 */
	public native float getReferenceAngle();
	
	/// set frequency in Hz.
	public native void setFrequency(float hz);
	
	/// get frequency in Hz.
	public native float getFrequency();

	/// set damping ratio.
	public native void setDampingRatio(float ratio);
	
	/// get damping ratio.
	public native float getDampingRatio();
}
