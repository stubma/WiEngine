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
 * \if English
 * Suck effect, just like the effect when deleting notes in iPhone
 * \else
 * 吸入效果, 指定一个吸入点, 界面中的所有元素都从这个点被吸走, 类似于iPhone中删除备忘录
 * 中的那种效果
 * \endif
 */
public class Suck extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 * @param suckPos 吸入点位置
	 * @return 动作实例
	 */
	public static Suck make(float duration, WYGridSize gSize, WYPoint suckPos) {
		return new Suck(duration, gSize, suckPos);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 * @param suckPos 吸入点位置
	 */
	protected Suck(float duration, WYGridSize gSize, WYPoint suckPos) {
		nativeInit(duration, gSize.x, gSize.y, suckPos.x, suckPos.y);
	}
	
    /**
     * 从底层指针获得一个Suck的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Suck}
     */
    public static Suck from(int pointer) {
    	return pointer == 0 ? null : new Suck(pointer);
    }
	
	protected Suck(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, float suckX, float suckY);
	
	@Override
	public Grid3DAction copy() {
		return new Suck(nativeCopy());
	}
}
