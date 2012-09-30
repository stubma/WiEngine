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
 * Fade out a node, it changes alpha of node from 1 to 0
 * \else
 * 淡出动作。目标的alpha会渐渐变成0。目标对象必须实现Node.ITransparent接口。
 * \endif
 */
public class FadeOut extends IntervalAction {
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration duration time of action
	 * @return \link FadeOut FadeOut\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @return \link FadeOut FadeOut\endlink
	 * \endif
	 */
    public static FadeOut make(float duration) {
        return new FadeOut(duration, false);
    }
    
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration duration time of action
	 * @param includeChildren true indicating modify alpha value of child nodes recursively
	 * @return \link FadeOut FadeOut\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param includeChildren true表示同时修改所有子节点的alpha值, 缺省是false
	 * @return \link FadeOut FadeOut\endlink
	 * \endif
	 */
    public static FadeOut make(float duration, boolean includeChildren) {
    	return new FadeOut(duration, includeChildren);
    }

    protected FadeOut(float duration, boolean includeChildren) {
    	nativeInit(duration, includeChildren);
    }

    public static FadeOut from(int pointer) {
    	return pointer == 0 ? null : new FadeOut(pointer);
    }
    
    protected FadeOut(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(float duration, boolean includeChildren);
    
    @Override
    public IntervalAction copy() {
    	return new FadeOut(nativeCopy());
    }

    @Override
    public IntervalAction reverse() {
        return new FadeIn(nativeReverse());
    }
}
