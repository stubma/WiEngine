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
 * Dynamic change clip rect of node to get an exit animation
 * \else
 * 动态的改变节点的裁剪区域从而得到一个逐渐隐藏的效果, 类似于愤怒小鸟中的菜单隐藏效果
 * \endif
 */
public class ClipOut extends IntervalAction {
	/**
	 * \if English
	 * clip shrinks from left to right side
	 * \else
	 * 从左边开始隐藏到右边
	 * \endif
	 */
	public static final int LEFT_TO_RIGHT = 0;

	/**
	 * \if English
	 * clip shrinks from right to left side
	 * \else
	 * 从右边开始隐藏到左边
	 * \endif
	 */
	public static final int RIGHT_TO_LEFT = 1;

	/**
	 * \if English
	 * clip shrinks from top to bottom side
	 * \else
	 * 从上边开始隐藏到下边
	 * \endif
	 */
	public static final int TOP_TO_BOTTOM = 2;

	/**
	 * \if English
	 * clip shrinks from bottom to top side
	 * \else
	 * 从下边开始隐藏到上边
	 * \endif
	 */
	public static final int BOTTOM_TO_TOP = 3;
	
	/**
	 * \if English
	 * Create a clip in action
	 *
	 * @param duration action duration in seconds
	 * @param direction clip grow direction, default is \c BOTTOM_TO_TOP
	 * @return \link ClipOut ClipOut\endlink
	 * \else
	 * 创建一个clip in动作
	 *
	 * @param duration 动作支持时间, 单位秒
	 * @param direction 裁剪区域变化的方向, 缺省是从下到上
	 * @return \link ClipOut ClipOut\endlink
	 * \endif
	 */
    public static ClipOut make(float duration, int direction) {
        return new ClipOut(duration, direction);
    }

    protected ClipOut(float duration, int direction) {
    	nativeInit(duration, direction);
    }

    public static ClipOut from(int pointer) {
    	return pointer == 0 ? null : new ClipOut(pointer);
    }
    
	protected ClipOut(int pointer) {
		super(pointer);
	}
	
    private native void nativeInit(float duration, int pointer);
    
    @Override
    public IntervalAction copy() {
    	return new ClipOut(nativeCopy());
    }
    
    @Override
    public IntervalAction reverse() {
    	return new ClipOut(nativeReverse());
    }
}
