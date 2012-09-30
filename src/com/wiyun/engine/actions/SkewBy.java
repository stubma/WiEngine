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
 * Skew x/y axis
 * \else
 * 改变x/y轴倾斜度的动作
 * \endif
 */
public class SkewBy extends IntervalAction {
	/**
	 * \if English
	 * Static creator
	 *
	 * @param duration action duration time in seconds
	 * @param skewX the angle between y axis and node left border, positive value means
	 * 		clockwise
	 * @param skewY the angle between x axis and node bottom border, positive value means
	 * 		clockwise
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间, 秒
	 * @param skewX x方向变化的倾斜度, 表示y轴和节点左边界的夹角, 正值表示顺时针
	 * @param skewY y方向变化的倾斜度, 表示x轴和节点下边界的夹角, 正式表示顺时针
	 * \endif
	 */
    public static SkewBy make(float duration, float skewX, float skewY) {
        return new SkewBy(duration, skewX, skewY);
    }

    protected SkewBy(float duration, float skewX, float skewY) {
    	nativeInit(duration, skewX, skewY);
    }
    
    private native void nativeInit(float duration, float skewX, float skewY);

    public static SkewBy from(int pointer) {
    	return pointer == 0 ? null : new SkewBy(pointer);
    }
    
    protected SkewBy(int pointer) {
    	super(pointer);
	}

	@Override
    public IntervalAction copy() {
        return new SkewBy(nativeCopy());
    }

    @Override
    public IntervalAction reverse() {
        return new SkewBy(nativeReverse());
    }
}
