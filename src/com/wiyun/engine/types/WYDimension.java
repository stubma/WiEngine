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
package com.wiyun.engine.types;


/**
 * 用来表示坐标的类, 和{@link WYPoint}的区别是成员是整数类型.
 */
public class WYDimension {
	public int x, y;
	
	/**
	 * 生成一个全0的WYDimension
	 * 
	 * @return {@link WYDimension}
	 */
	public static WYDimension makeZero() {
		return new WYDimension(0, 0);
	}
	
	/**
	 * 生成一个WYDimension数组
	 * 
	 * @param size 数组大小
	 * @return {@link WYDimension}数组
	 */
	public static WYDimension[] makeArray(int size) {
		WYDimension[] p = new WYDimension[size];
		for(int i = 0; i < size; i++)
			p[i] = makeZero();
		return p;
	}
	
	protected WYDimension() {
		this(0, 0);
	}

	protected WYDimension(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public String toString() {
		return "(" + x + ", " + y + ")";
	}

	public static boolean isEqual(WYDimension p1, WYDimension p2) {
		return p1.x == p2.x && p1.y == p2.y;
	}

	/**
	 * Helper macro that creates a WYPoint
	 *
	 * @return WYPoint
	 */
	public static WYDimension make(int x, int y) {
		return new WYDimension(x, y);
	}
}
