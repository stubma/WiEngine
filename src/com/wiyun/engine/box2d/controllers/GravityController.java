package com.wiyun.engine.box2d.controllers;


/**
 * 万有引力控制器, 在刚体之间模拟万有引力关系. 引力常量可以自由设置以修改引力大小效果.
 */
public class GravityController extends Controller {
	/**
	 * 创建一个{@link GravityController}实例
	 * 
	 * @return {@link GravityController}
	 */
	public static GravityController from(int pointer) {
		return pointer == 0 ? null : new GravityController(pointer);
	}
	
	protected GravityController() {
	    super();
    }

	protected GravityController(int pointer) {
	    super(pointer);
    }

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
