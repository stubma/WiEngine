package com.wiyun.engine.box2d.controllers;

import com.wiyun.engine.box2d.common.Matrix22;


/**
 * 自定义阻尼控制器. 通过一个矩阵动态的计算刚体当前的阻尼, 可以想象一下可以做什么.
 * 比较有名的例子是俯视视角的汽车车轮, 汽车在转向时, 车轮与地面的摩擦力为汽车提供
 * 侧向加速度, 转向越剧烈车轮受到的侧向力越大, 如果汽车直线行驶, 则侧向力为0. 这种情况
 * 就可以用到阻尼矩阵, 它可以实现一种动态的阻尼计算.
 */
public class TensorDampingController extends Controller {
	/**
	 * 创建一个{@link TensorDampingController}实例
	 * 
	 * @return {@link TensorDampingController}
	 */
	public static TensorDampingController from(int pointer) {
		return pointer == 0 ? null : new TensorDampingController(pointer);
	}
	
	protected TensorDampingController() {
	    super();
    }

	protected TensorDampingController(int pointer) {
	    super(pointer);
    }
	
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
}
