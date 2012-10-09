package com.wiyun.engine.box2d.controllers;

import com.wiyun.engine.types.WYPoint;

/**
 * 恒力控制器, 让刚体上保持一个恒定的外力
 */
public class ConstantForceController extends Controller {
	/**
	 * 创建一个{@link ConstantForceController}实例
	 * 
	 * @return {@link ConstantForceController}
	 */
	public static ConstantForceController from(int pointer) {
		return pointer == 0 ? null : new ConstantForceController(pointer);
	}
	
	protected ConstantForceController() {
	    super();
    }

	protected ConstantForceController(int pointer) {
	    super(pointer);
    }
	
	public native void setForce(float x, float y);
	
	public WYPoint getForce() {
		WYPoint f = WYPoint.makeZero();
		nativeGetForce(f);
		return f;
	}
	
	private native void nativeGetForce(WYPoint f);
}
