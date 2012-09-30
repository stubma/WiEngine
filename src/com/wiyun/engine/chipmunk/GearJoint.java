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
 * 齿轮连接点
 */
public class GearJoint extends Constraint {
	/**
	 * 创建一个齿轮连接点
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param phase 连接点的位置，用弧度表示，访问从0到2pi，是相对于刚体1而言的。如果是正值，顺时针，负值是逆时针
	 * @param ratio 比率
	 * @return {@link GearJoint}
	 */
	public static GearJoint make(Body b1, Body b2, float phase, float ratio) {
		return new GearJoint(b1, b2, phase, ratio);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param phase 相位
	 * @param ratio 比率
	 */
	protected GearJoint(Body b1, Body b2, float phase, float ratio) {
		init(b1, b2, phase, ratio);
	}
	
	public static GearJoint from(int pointer) {
		return pointer == 0 ? null : new GearJoint(pointer);
	}
	
	protected GearJoint(int pointer) {
		super(pointer);
	}

	/**
	 * 创建一个齿轮连接点
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param phase 相位
	 * @param ratio 比率
	 */
	private native void init(Body b1, Body b2, float phase, float ratio);
	
	/**
	 * 得到比率
	 * 
	 * @return 比率
	 */
	public native float getRatio();
	
	/**
	 * 设置比率
	 * 
	 * @param ratio 比率
	 */
	public native void setRatio(float ratio);
	
	/**
	 * 得到相位
	 * 
	 * @return 相位
	 */
	public native float getPhase();
	
	/**
	 * 设置相位
	 * 
	 * @param phase 相位
	 */
	public native void setPhase(float phase);
}
