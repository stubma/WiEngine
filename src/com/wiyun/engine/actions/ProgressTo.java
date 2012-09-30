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
 * progress a node, this action can only impose to \link wyProgressTimer wyProgressTimer\endlink
 * \else
 * 使节点称为进度条显示的动作封装，根据指定变化到的百分比执行动作
 * \endif
 */
public class ProgressTo extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time in seconds
	 * @param from start percentage, from 0 to 100
	 * @param to end percentage from 0 to 100
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param from 节点起始显示百分比，取值0到100
	 * @param to 节点结束显示百分比，取值0到100
	 * \endif
	 */
	public static ProgressTo make(float duration, float from, float to) {
		return new ProgressTo(duration, from, to);
	}
	
	protected ProgressTo(float duration, float from, float to) {
		nativeInit(duration, from, to);
	}
	
    /**
     * 从底层指针获得一个ProgressTo的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ProgressTo}
     */
    public static ProgressTo from(int pointer) {
    	return pointer == 0 ? null : new ProgressTo(pointer);
    }

	protected ProgressTo(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(float duration, float from, float to);

	@Override
	public IntervalAction copy() {
		return new ProgressTo(nativeCopy());
	}

	@Override
	public IntervalAction reverse() {
		return new ProgressTo(nativeReverse());
	}
}
