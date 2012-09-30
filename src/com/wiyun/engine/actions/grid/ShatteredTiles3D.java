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
 * 网格混乱效果。它和抖动效果起始本质上相同，只不过它只做一次，所以它没有动画效果。
 */
public class ShatteredTiles3D extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 网格混乱程度
	 * @param shatterZ 是否在z轴方向上混淆
	 * @return 动作实例
	 */
	public static ShatteredTiles3D make(float duration, WYGridSize gridSize, int range, boolean shatterZ) {
		return new ShatteredTiles3D(duration, gridSize, range, shatterZ);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 网格混乱程度
	 * @param shatterZ 是否在z轴方向上混淆
	 */
	protected ShatteredTiles3D(float duration, WYGridSize gridSize, int range, boolean shatterZ) {
		nativeInit(duration, gridSize.x, gridSize.y, range, shatterZ);
	}
	
    /**
     * 从底层指针获得一个ShatteredTiles3D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ShatteredTiles3D}
     */
    public static ShatteredTiles3D from(int pointer) {
    	return pointer == 0 ? null : new ShatteredTiles3D(pointer);
    }
	
	protected ShatteredTiles3D(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, int range, boolean shatterZ);

	@Override
	public TiledGrid3DAction copy() {
		return new ShatteredTiles3D(nativeCopy());
	}
}
