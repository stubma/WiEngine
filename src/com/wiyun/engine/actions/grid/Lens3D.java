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
 * 透镜效果。 使目标看起来好像在放大镜下。 
 */
public class Lens3D extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param pos 透镜中心位置
	 * @param radius 透镜半径
	 * @param lensEffect 透镜凹凸程度
	 * @return 动作实例
	 */
	public static Lens3D make(float duration, WYGridSize gridSize, WYPoint pos, float radius, float lensEffect) {
		return make(duration, gridSize, pos.x, pos.y, radius, lensEffect);
	}
	
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param centerX 透镜中心位置x坐标
	 * @param centerY 透镜中心位置y坐标 
	 * @param radius 透镜半径
	 * @param lensEffect 透镜凹凸程度
	 * @return 动作实例
	 */
	public static Lens3D make(float duration, WYGridSize gridSize, float centerX, float centerY, float radius, float lensEffect) {
		return make(duration, gridSize, centerX, centerY, 0, 0, radius, 0, lensEffect);
	}
	
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param centerX 透镜中心位置x坐标
	 * @param centerY 透镜中心位置y坐标 
	 * @param deltaX 透镜横向移动距离
	 * @param deltaY 透镜纵向移动距离
	 * @param radius 透镜半径
	 * @param deltaRadius 透镜半径变化量
	 * @param lensEffect 透镜凹凸程度
	 * @return 动作实例
	 */
	public static Lens3D make(float duration, WYGridSize gridSize, float centerX, float centerY, 
			float deltaX, float deltaY, float radius, float deltaRadius, float lensEffect) {
		return new Lens3D(duration, gridSize, centerX, centerY, deltaX, deltaY, radius, deltaRadius, lensEffect);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param centerX 透镜中心位置x坐标
	 * @param centerY 透镜中心位置y坐标 
	 * @param deltaX 透镜横向移动距离
	 * @param deltaY 透镜纵向移动距离
	 * @param radius 透镜半径
	 * @param deltaRadius 透镜半径变化量
	 * @param lensEffect 透镜凹凸程度
	 */
	protected Lens3D(float duration, WYGridSize gridSize, float centerX, float centerY, 
			float deltaX, float deltaY, float radius, float deltaRadius, float lensEffect) {
		nativeInit(duration, gridSize.x, gridSize.y, centerX, centerY, deltaX, deltaY, radius, deltaRadius, lensEffect);
	}
	
    /**
     * 从底层指针获得一个Lens3D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Lens3D}
     */
    public static Lens3D from(int pointer) {
    	return pointer == 0 ? null : new Lens3D(pointer);
    }
	
	protected Lens3D(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, float centerX, float centerY,
		float deltaX, float deltaY, float radius, float deltaRadius, float lensEffect);

	@Override
	public Grid3DAction copy() {
		return new Lens3D(nativeCopy());
	}
}
