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
package com.wiyun.engine.utils;

import com.wiyun.engine.BaseWYObject;

/**
 * \if English
 * Segment of between two \link VerletPoint VerletPoint\endlink
 * \else
 * 封装两个\link VerletPoint VerletPoint\endlink, 代表了链接这两个点
 * 的一个线段
 * \endif
 */
public class VerletStick extends BaseWYObject {
	public static VerletStick make(VerletPoint a, VerletPoint b) {
		return new VerletStick(a, b);
	}
	
	public static VerletStick from(int pointer) {
		return pointer == 0 ? null : new VerletStick(pointer);
	}
	
	protected VerletStick(VerletPoint a, VerletPoint b) {
		nativeInit(a, b);
	}
	
	protected VerletStick(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(VerletPoint a, VerletPoint b);
	
	/**
	 * \if English
	 * Contract this segment to approach original length. It is not done
	 * immediately but repeatly.
	 *
	 * @param reverse true means treat a point as b, treat b as a
	 * \else
	 * 收缩线段，使得两点距离逐渐回复到原始距离。这个收缩过程不是一下子
	 * 完成的，这使得绳子看起来有一定的弹性。
	 *
	 * @param reverse true表示把a点当成b点, b点当成a点
	 * \endif
	 */
	public native void contract(boolean reverse);

	/**
	 * \if English
	 * Get point a
	 *
	 * @return \link VerletPoint VerletPoint\endlink
	 * \else
	 * 得到点A
	 *
	 * @return \link VerletPoint VerletPoint\endlink
	 * \endif
	 */
	public VerletPoint getPointA() {
		return VerletPoint.from(nativeGetPointA());
	}
	
	private native int nativeGetPointA();

	/**
	 * \if English
	 * Get point b
	 *
	 * @return \link VerletPoint VerletPoint\endlink
	 * \else
	 * 得到点b
	 *
	 * @return \link VerletPoint VerletPoint\endlink
	 * \endif
	 */
	public VerletPoint getPointB() {
		return VerletPoint.from(nativeGetPointB());
	}
	
	private native int nativeGetPointB();

	/**
	 * \if English
	 * Get original length
	 *
	 * @return original length
	 * \else
	 * 得到原始长度
	 *
	 * @return 原始长度
	 * \endif
	 */
	public native float getLength();

	/**
	 * \if English
	 * Get current length
	 *
	 * @return current length
	 * \else
	 * 得到当前长度
	 *
	 * @return 当前长度
	 * \endif
	 */
	public native float getCurrentLength();
}
