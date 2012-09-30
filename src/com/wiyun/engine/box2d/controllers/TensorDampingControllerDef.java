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
