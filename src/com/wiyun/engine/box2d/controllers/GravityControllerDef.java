package com.wiyun.engine.box2d.controllers;


/**
 * 万有引力控制器定义类
 */
public class GravityControllerDef extends ControllerDef {
	/**
	 * 创建一个{@link GravityControllerDef}实例
	 * 
	 * @return {@link GravityControllerDef}
	 */
	public static GravityControllerDef make() {
		return new GravityControllerDef();
	}
	
	protected GravityControllerDef() {
		nativeInit();
	}
	
	private native void nativeInit();
	
	public native void destroy();

	/**
	 * 设置引力常量
	 * 
	 * @param gc 引力常量
	 */
	public native void setGravitationalConstant(float gc);

	/**
	 * 获得引力常量
	 * 
	 * @return 引力常量
	 */
	public native float getGravitationalConstant();

	/**
	 * 设置引力是否和半径的倒数成正比, 按照万有引力公式, 引力是和半径平方的倒数成
	 * 正比的, 但是可以设置这个标志为true使计算时与半径倒数成正比
	 * 
	 * @param flag 引力是否和半径的倒数成正比
	 */
	public native void setProportionalToInvRadius(boolean flag);
	
	/**
	 * 引力是否和半径的倒数成正比, 缺省是false
	 * 
	 * @return true表示引力是否和半径的倒数成正比, false表示引力是否和半径平方的倒数成正比
	 */
	public native boolean isProportionalToInvRadius();
}
