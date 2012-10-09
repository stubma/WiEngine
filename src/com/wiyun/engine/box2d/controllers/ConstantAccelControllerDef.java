package com.wiyun.engine.box2d.controllers;

import com.wiyun.engine.types.WYPoint;

/**
 * 恒加速控制器定义类
 */
public class ConstantAccelControllerDef extends ControllerDef {
	/**
	 * 创建一个{@link ConstantAccelControllerDef}实例
	 * 
	 * @return {@link ConstantAccelControllerDef}
	 */
	public static ConstantAccelControllerDef make() {
		return new ConstantAccelControllerDef();
	}
	
	protected ConstantAccelControllerDef() {
		nativeInit();
	}
	
	private native void nativeInit();
	
	public native void destroy();
	
	public native void setAcceleration(float x, float y);
	
	public WYPoint getAcceleration() {
		WYPoint f = WYPoint.makeZero();
		nativeGetAcceleration(f);
		return f;
	}
	
	private native void nativeGetAcceleration(WYPoint f);
}
