package com.wiyun.engine.box2d.controllers;

import com.wiyun.engine.types.WYPoint;

/**
 * 恒加速控制器, 可以让刚体保持恒定加速度.
 */
public class ConstantAccelController extends Controller {
	/**
	 * 创建一个{@link ConstantAccelController}实例
	 * 
	 * @return {@link ConstantAccelController}
	 */
	public static ConstantAccelController from(int pointer) {
		return pointer == 0 ? null : new ConstantAccelController(pointer);
	}
	
	protected ConstantAccelController() {
	    super();
    }

	protected ConstantAccelController(int pointer) {
	    super(pointer);
    }
	
	public native void setAcceleration(float x, float y);
	
	public WYPoint getAcceleration() {
		WYPoint f = WYPoint.makeZero();
		nativeGetAcceleration(f);
		return f;
	}
	
	private native void nativeGetAcceleration(WYPoint f);
}
