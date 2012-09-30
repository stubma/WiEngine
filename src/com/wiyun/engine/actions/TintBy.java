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
package com.wiyun.engine.actions;


/**
 * \if English
 * It changes color of node by a delta value
 * \else
 * 节点染色的动作封装,根据设置染色量进行移动
 * \endif
 */
public class TintBy extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action in seconds
	 * @param r delta value of red component
	 * @param g delta value of green component
	 * @param b delta value of blue component
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param r 红色值变化值
	 * @param g 绿色值变化值
	 * @param b 蓝色值变化值
	 * \endif
	 */
	public static TintBy make(float duration, int r, int g, int b) {
		return new TintBy(duration, r, g, b);
	}

	protected TintBy(float duration, int r, int g, int b) {
		nativeInit(duration, r, g, b);
	}
	
    public static TintBy from(int pointer) {
    	return pointer == 0 ? null : new TintBy(pointer);
    }
	
	protected TintBy(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int r, int g, int b);

	@Override
	public IntervalAction copy() {
		return new TintBy(nativeCopy());
	}

	@Override
	public IntervalAction reverse() {
		return new TintBy(nativeReverse());
	}
}
