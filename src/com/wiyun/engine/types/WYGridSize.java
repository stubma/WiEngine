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
 * 二维网格尺寸。每个格子叫做Tile.
 */
public class WYGridSize {
	/**
	 * 横向有多少格
	 */
	public int x;
	
	/**
	 * 纵向有多少格 
	 */
	public int y;
	
	/**
	 * 创建网格尺寸对象，初始化成0行0列
	 * 
	 * @return {@link WYGridSize}实例
	 */
	public static WYGridSize makeZero() {
		return new WYGridSize(0, 0);
	}

	/**
	 * 创建网格尺寸对象
	 * 
	 * @param x 横向格子数
	 * @param y 纵向格子数
	 * @return {@link WYGridSize}实例
	 */
	public static WYGridSize make(final int x, final int y) {
		return new WYGridSize(x, y);
	}

	/**
	 * 构造函数
	 * 
	 * @param x 横向格子数
	 * @param y 纵向格子数
	 */
	protected WYGridSize(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	/**
	 * 重用当前实例，修改横向和纵向格子数
	 * 
	 * @param x 新的横向格子数
	 * @param y 新的纵向格子数
	 */
	public void reuse(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	@Override
    public String toString() {
        return "<" + x + ", " + y + ">";
    }
}
