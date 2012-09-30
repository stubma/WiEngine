/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
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
