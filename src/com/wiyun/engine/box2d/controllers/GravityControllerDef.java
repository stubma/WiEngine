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
