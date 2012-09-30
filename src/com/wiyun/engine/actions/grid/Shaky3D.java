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
package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 抖动效果 
 */
public class Shaky3D extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 抖动的幅度，越大越剧烈
	 * @param shakeZ 是否在z轴方向上抖动
	 * @return 动作实例
	 */
	public static Shaky3D make(float duration, WYGridSize gridSize, int range, boolean shakeZ) {
		return make(duration, gridSize, range, 0, shakeZ);
	}
	
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 抖动的幅度，越大越剧烈
	 * @param deltaRange 抖动的幅度变化值
	 * @param shakeZ 是否在z轴方向上抖动
	 * @return 动作实例
	 */
	public static Shaky3D make(float duration, WYGridSize gridSize, int range, int deltaRange, boolean shakeZ) {
		return new Shaky3D(duration, gridSize, range, deltaRange, shakeZ);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 抖动的幅度，越大越剧烈
	 * @param deltaRange 抖动的幅度变化值
	 * @param shakeZ 是否在z轴方向上抖动
	 */
	protected Shaky3D(float duration, WYGridSize gridSize, int range, int deltaRange, boolean shakeZ) {
		nativeInit(duration, gridSize.x, gridSize.y, range, deltaRange, shakeZ);
	}
	
    /**
     * 从底层指针获得一个Shaky3D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Shaky3D}
     */
    public static Shaky3D from(int pointer) {
    	return pointer == 0 ? null : new Shaky3D(pointer);
    }
	
	protected Shaky3D(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, int range, int deltaRange, boolean shakeZ);

	@Override
	public Grid3DAction copy() {
		return new Shaky3D(nativeCopy());
	}
}
