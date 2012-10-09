package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.types.WYPoint;


public class DistanceJoint extends Joint {
	public static DistanceJoint from(int pointer) {
		return pointer == 0 ? null : new DistanceJoint(pointer);
	}

	protected DistanceJoint() {
	}

	protected DistanceJoint(int pointer) {
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
	 * Set/get the natural length.
	 * Manipulating the length can lead to non-physical behavior when the frequency is zero.
	 */
	public native void setLength(float length);
	
	/**
	 * Set/get the natural length.
	 * Manipulating the length can lead to non-physical behavior when the frequency is zero.
	 */
	public native float getLength();

	/**
	 * Set/get frequency in Hz.
	 */
	public native void setFrequency(float hz);
	
	/**
	 * Set/get frequency in Hz.
	 */
	public native float getFrequency();

	/**
	 * Set/get damping ratio.
	 */
	public native void setDampingRatio(float ratio);
	
	/**
	 * Set/get damping ratio.
	 */
	public native float getDampingRatio();
}
