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

import com.wiyun.engine.nodes.Animation;

/**
 * \if English
 * Encapsulate animation action, it requires a \link Animation Animation\endlink object which
 * provides frame info
 * \else
 * 动画播放动作的封装
 * \endif
 */
public class Animate extends IntervalAction {
	/**
	 * \if English
	 * Static factory method
	 *
	 * @param anim \link Animation Animation\endlink pointer
	 * \else
	 * 静态构造函数
	 *
	 * @param anim 动画\link Animation Animation\endlink 对象指针
	 * \endif
	 */
	public static Animate make(Animation anim) {
		if(anim == null) {
			throw new IllegalArgumentException("Animate: argument Animation must be non-null");
		}
		return new Animate(anim, false);
	}

	/**
	 * \if English
	 * Static factory method
	 *
	 * @param anim \link Animation Animation\endlink pointer
	 * @param fillAfter false indicating restore to original frame when animation ends, or true
	 * 		indicating keep last frame, default is false
	 * \else
	 * 静态构造函数
	 *
	 * @param anim 动画\link Animation Animation\endlink 对象指针
	 * @param fillAfter 动作停止后是否回到sprite的原始图片，true为不回到，false表示回到原来的图片. 缺省是false
	 * \endif
	 */
	public static Animate make(Animation anim, boolean fillAfter) {
		if(anim == null) {
			throw new IllegalArgumentException("Animate: argument Animation must be non-null");
		}
		return new Animate(anim, fillAfter);
	}

	protected Animate(Animation anim, boolean fillAfter) {
		nativeInit(anim, fillAfter);
	}
	
	private native void nativeInit(Animation anim, boolean fillAfter);

    public static Animate from(int pointer) {
    	return pointer == 0 ? null : new Animate(pointer);
    }
    
	protected Animate(int pointer) {
		super(pointer);
	}
	
	@Override
	public IntervalAction copy() {
		return new Animate(nativeCopy());
	}
	
	@Override
	public IntervalAction reverse() {
		return new Animate(nativeReverse());
	}
}
