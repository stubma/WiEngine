package com.wiyun.engine.box2d.controllers;

import com.wiyun.engine.box2d.common.Matrix22;


/**
 * 自定义阻尼控制器定义类
 */
public class TensorDampingControllerDef extends ControllerDef {
	/**
	 * 创建一个{@link TensorDampingControllerDef}实例
	 * 
	 * @return {@link TensorDampingControllerDef}
	 */
	public static TensorDampingControllerDef make() {
		return new TensorDampingControllerDef();
	}
	
	protected TensorDampingControllerDef() {
		nativeInit();
	}
	
	private native void nativeInit();
	
	public native void destroy();

	/**
	 * 设置阻尼矩阵
	 * 
	 * @param t {@link Matrix22}
	 */
	public native void setMatrix(Matrix22 t);
	
	/**
	 * 得到阻尼矩阵
	 * 
	 * @return {@link Matrix22}
	 */
	public Matrix22 getMatrix() {
		Matrix22 t = Matrix22.makeZero();
		nativeGetMatrix(t);
		return t;
	}
	
	private native void nativeGetMatrix(Matrix22 t);

	/**
	 * 设置施加阻尼的最大时间范围
	 * 
	 * @param maxTimeStep 施加阻尼的最大时间范围
	 */
	public native void setMaxTimeStep(float maxTimeStep);
	
	/**
	 * 得到施加阻尼的最大时间范围
	 * 
	 * @return 施加阻尼的最大时间范围
	 */
	public native float getMaxTimeStep();
	
	/**
	 * 根据x和y方向设置阻尼, 底层根据设置的值产生阻尼矩阵
	 * 
	 * @param xDamping x方向阻尼
	 * @param yDamping y方向阻尼
	 */
	public native void setAxisAligned(float xDamping, float yDamping);
}
