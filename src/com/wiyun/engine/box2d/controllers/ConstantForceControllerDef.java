package com.wiyun.engine.box2d.controllers;

import com.wiyun.engine.types.WYPoint;

/**
 * 恒力控制器定义类
 */
public class ConstantForceControllerDef extends ControllerDef {
	/**
	 * 创建一个{@link ConstantForceControllerDef}实例
	 * 
	 * @return {@link ConstantForceControllerDef}
	 */
	public static ConstantForceControllerDef make() {
		return new ConstantForceControllerDef();
	}
	
	protected ConstantForceControllerDef() {
		nativeInit();
	}
	
	private native void nativeInit();
	
	public native void destroy();
	
	public native void setForce(float x, float y);
	
	public WYPoint getForce() {
		WYPoint f = WYPoint.makeZero();
		nativeGetForce(f);
		return f;
	}
	
	private native void nativeGetForce(WYPoint f);
}
