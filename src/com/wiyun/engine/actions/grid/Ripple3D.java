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
import com.wiyun.engine.types.WYPoint;

/**
 * 波纹动作。目标会呈现类似于水面被投入石子的效果。 
 */
public class Ripple3D extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param pos 波动中心位置
	 * @param radius 波动波及范围的半径
	 * @param amplitude 幅度
	 * @param waves 波数
	 * @return 动作实例
	 */
	public static Ripple3D make(float duration, WYGridSize gridSize, WYPoint pos, float radius, float amplitude, float waves) {
		return make(duration, gridSize, pos.x, pos.y, radius, amplitude, waves);
	}
	
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param centerX 波动中心位置x值
	 * @param centerY 波动中心位置值
	 * @param radius 波动波及范围的半径
	 * @param amplitude 幅度
	 * @param waves 波数
	 * @return 动作实例
	 */
	public static Ripple3D make(float duration, WYGridSize gridSize, float centerX, float centerY, float radius, float amplitude, float waves) {
		return new Ripple3D(duration, gridSize, centerX, centerY, 0, 0, radius, 0, amplitude, 0, waves);
    }

	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param centerX 波动中心位置x值
	 * @param centerY 波动中心位置值
	 * @param deltaX 波动中心横向变化值
	 * @param deltaY 波动中心中心变化值
	 * @param radius 波动波及范围的半径
	 * @param deltaRadius 波动波及范围的半径变化值
	 * @param amplitude 幅度 
	 * @param deltaAmplitude 幅度变化值
	 * @param waves 波数
	 * @return 动作实例
	 */
	public static Ripple3D make(float duration, WYGridSize gridSize, float centerX, float centerY, 
			float deltaX, float deltaY, float radius, float deltaRadius, 
			float amplitude, float deltaAmplitude, float waves) {
		return new Ripple3D(duration, gridSize, centerX, centerY, deltaX, deltaY, radius, deltaRadius, amplitude, deltaAmplitude, waves);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param centerX 波动中心位置x值
	 * @param centerY 波动中心位置值
	 * @param deltaX 波动中心横向变化值
	 * @param deltaY 波动中心中心变化值
	 * @param radius 波动波及范围的半径
	 * @param deltaRadius 波动波及范围的半径变化值
	 * @param amplitude 幅度 
	 * @param deltaAmplitude 幅度变化值
	 * @param waves 波数
	 */
	protected Ripple3D(float duration, WYGridSize gridSize, float centerX, float centerY, 
			float deltaX, float deltaY, float radius, float deltaRadius, 
			float amplitude, float deltaAmplitude, float waves) {
		nativeInit(duration, gridSize.x, gridSize.y, centerX, centerY, deltaX, deltaY, radius, deltaRadius, amplitude, deltaAmplitude, waves);
	}
	
    /**
     * 从底层指针获得一个Ripple3D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Ripple3D}
     */
    public static Ripple3D from(int pointer) {
    	return pointer == 0 ? null : new Ripple3D(pointer);
    }
	
	protected Ripple3D(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, float centerX, float centerY,
		float deltaX, float deltaY, float radius, float deltaRadius, float amplitude, float deltaAmplitude, float waves);

	@Override
	public Grid3DAction copy() {
		return new Ripple3D(nativeCopy());
	}
}
