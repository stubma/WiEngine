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
package com.wiyun.engine.afcanim;

import com.wiyun.engine.BaseWYObject;

/**
 * \if English
 * This class represents an animation in AFC architecture
 * \else
 * 这个类只代表一个动画，包含了这个动画的所有帧信息.
 * \endif
 */
public class AFCAnimation extends BaseWYObject {
	public static AFCAnimation from(int pointer) {
		return pointer == 0 ? null : new AFCAnimation(pointer);
	}
	
	protected AFCAnimation(int pointer) {
		super(pointer);
	}
	
	/**
	 * \if English
	 * Get frame count in this animation
	 *
	 * @return frame count
	 * \else
	 * 得到动画中的帧数
	 *
	 * @return 帧数
	 * \endif
	 */
	public native int getFrameCount();

	/**
	 * \if English
	 * Get frame at specified index
	 *
	 * @param index index, starts from 0
	 * @return \link AFCFrame AFCFrame\endlink object, or NULL if index is invalid
	 * \else
	 * 得到某个位置处的帧
	 *
	 * @param index 帧索引
	 * @return \link AFCFrame AFCFrame\endlink对象, 如果索引非法, 返回NULL
	 * \endif
	 */
	public AFCFrame getFrameAt(int index) {
		return AFCFrame.from(nativeGetFrameAt(index));
	}
	
	private native int nativeGetFrameAt(int index);
}
