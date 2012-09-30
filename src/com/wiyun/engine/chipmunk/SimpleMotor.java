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
