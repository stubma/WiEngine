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
 * 扭曲效果。
 */
public class Twirl extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param pos 中心点位置
	 * @param amplitude 幅度
	 * @param twirls 扭曲次数
	 * @return 动作实例
	 */
	public static Twirl make(float duration, WYGridSize gridSize, WYPoint pos, float amplitude, float twirls) {
		return make(duration, gridSize, pos.x, pos.y, amplitude, twirls);
	}
	
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param centerX 中心点位置x值
	 * @param centerY 中心点位置y值
	 * @param amplitude 幅度
	 * @param twirls 扭曲次数
	 * @return 动作实例
	 */
	public static Twirl make(float duration, WYGridSize gridSize, float centerX, float centerY, float amplitude, float twirls) {
		return make(duration, gridSize, centerX, centerY, 0, 0, amplitude, 0, twirls);
	}
	
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param centerX 中心点位置x值
	 * @param centerY 中心点位置y值
	 * @param deltaX 中心点位置横向变化
	 * @param deltaY 中心点位置纵向变化
	 * @param amplitude 幅度
	 * @param deltaAmplitude 幅度变化值
	 * @param twirls 扭曲次数
	 * @return 动作实例
	 */
	public static Twirl make(float duration, WYGridSize gridSize, float centerX, float centerY, float deltaX, float deltaY, float amplitude,
	        float deltaAmplitude, float twirls) {
		return new Twirl(duration, gridSize, centerX, centerY, deltaX, deltaY, amplitude, deltaAmplitude, twirls);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param centerX 中心点位置x值
	 * @param centerY 中心点位置y值
	 * @param deltaX 中心点位置横向变化
	 * @param deltaY 中心点位置纵向变化
	 * @param amplitude 幅度
	 * @param deltaAmplitude 幅度变化值
	 * @param twirls 扭曲次数
	 */
	protected Twirl(float duration, WYGridSize gridSize, float centerX, float centerY, float deltaX, float deltaY, float amplitude,
	        float deltaAmplitude, float twirls) {
		nativeInit(duration, gridSize.x, gridSize.y, centerX, centerY, deltaX, deltaY, amplitude, deltaAmplitude, twirls);
	}
	
    /**
     * 从底层指针获得一个Twirl的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Twirl}
     */
    public static Twirl from(int pointer) {
    	return pointer == 0 ? null : new Twirl(pointer);
    }
    
	protected Twirl(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, float centerX, float centerY, float deltaX, float deltaY, float amplitude,
        float deltaAmplitude, float twirls);
	
	@Override
	public Grid3DAction copy() {
		return new Twirl(nativeCopy());
	}
}
