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
package com.wiyun.engine.chipmunk;


/**
 * 物体之间的关联，基类 
 */
public class Constraint {
	// underlying struct pointer
	int mPointer;
	
	/**
	 * 从底层指针生成java对象
	 * 
	 * @param pointer 底层java对象
	 * @return {@link Constraint}
	 */
	public static Constraint from(int pointer) {
		return pointer == 0 ? null : new Constraint(pointer);
	}
	
	public Constraint() {
	}
	
	protected Constraint(int pointer) {
		mPointer = pointer;
	}
	
	public void setPointer(int pointer) {
		mPointer = pointer;
	}
	
	@Override
	public boolean equals(Object o) {
		if(o instanceof Constraint)
			return ((Constraint)o).mPointer == mPointer;
		else
			return false;
	}
	
	@Override
	public int hashCode() {
		return mPointer;
	}
	
	/**
	 * 销毁底层资源
	 */
	public native void destroy();
	
	/**
	 * 设置连接点能承受的最大力量
	 * 
	 * @param maxForce 连接点能承受的最大力量
	 */
	public native void setMaxForce(float maxForce);
	
	/**
	 * 得到连接点能承受的最大力量
	 * 
	 * @return 连接点能承受的最大力量
	 */
	public native float getMaxForce();
	
	/**
	 * 设置偏差系数
	 * 
	 * @param bias 偏差系数
	 */
	public native void setBias(float bias);
	
	/**
	 * 得到偏差系数
	 * 
	 * @return 偏差系数
	 */
	public native float getBias();
	
	/**
	 * 设置最大偏差系数
	 * 
	 * @param max 最大偏差系数
	 */
	public native void setMaxBias(float max);
	
	/**
	 * 得到最大偏差系数
	 * 
	 * @return 最大偏差系数
	 */
	public native float getMaxBias();
}
