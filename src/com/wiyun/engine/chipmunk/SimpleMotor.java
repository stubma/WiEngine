package com.wiyun.engine.chipmunk;

/**
 * 引擎传动点 
 */
public class SimpleMotor extends Constraint {
	/**
	 * 创建一个引擎传动点
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param rate 
	 * @return {@link SimpleMotor}
	 */
	public static SimpleMotor make(Body b1, Body b2, float rate) {
		return new SimpleMotor(b1, b2, rate);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param rate 
	 */
	protected SimpleMotor(Body b1, Body b2, float rate) {
		init(b1, b2, rate);
	}
	
	public static SimpleMotor from(int pointer) {
		return pointer == 0 ? null : new SimpleMotor(pointer);
	}
	
	protected SimpleMotor(int pointer) {
		super(pointer);
	}

	/**
	 * 初始化一个引擎传动点
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param rate 
	 */
	private native void init(Body b1, Body b2, float rate);
	
	/**
	 * Set rate
	 * 
	 * @param rate rate
	 */
	public native void setRate(float rate);
	
	/**
	 * Get rate
	 * 
	 * @return rete
	 */
	public native float getRate();
}
