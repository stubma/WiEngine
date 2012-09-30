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
package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;

/**
 * 点状页面指示节点, 最传统的一种页面指示节点. 创建这个节点时, 指定两个图片分别表示页面没选中和
 * 选中的状态.
 */
public class DotPageIndicator extends PageIndicator {
	/**
	 * 静态构造函数
	 *
	 * @param dot 页面没有被选中时的图片, 不能为NULL
	 * @param dotRect 如果dot是一个图片集, 则表示点图片在图片集中的位置
	 * @param selectedDot 页面被选中时的图片, 不能为NULL
	 * @param selectedDotRect 如果selectedDot是一个图片集, 则表示选中的点图片在图片集中的位置
	 * @return {@link DotPageIndicator}
	 */
	public static DotPageIndicator make(Texture2D dot, WYRect dotRect, Texture2D selectedDot, WYRect selectedDotRect) {
		return new DotPageIndicator(dot, dotRect, selectedDot, selectedDotRect);
	}
	
	/**
	 * 静态构造函数
	 *
	 * @param dot 页面没有被选中时的图片, 不能为NULL
	 * @param selectedDot 页面被选中时的图片, 不能为NULL
	 * @return {@link DotPageIndicator}
	 */
	public static DotPageIndicator make(Texture2D dot, Texture2D selectedDot) {
		return new DotPageIndicator(dot, 
				WYRect.make(0, 0, dot.getWidth(), dot.getHeight()),
				selectedDot, 
				WYRect.make(0, 0, selectedDot.getWidth(), selectedDot.getHeight()));
	}
	
	public static DotPageIndicator from(int pointer) {
		return pointer == 0 ? null : new DotPageIndicator(pointer);
	}
	
	protected DotPageIndicator() {
	}
	
	protected DotPageIndicator(Texture2D dot, WYRect dotRect, Texture2D selectedDot, WYRect selectedDotRect) {
		nativeInit(dot, dotRect, selectedDot, selectedDotRect);
	}
	
	protected DotPageIndicator(int pointer) {
		super(pointer); 
	}
	
	private native void nativeInit(Texture2D dot, WYRect dotRect, Texture2D selectedDot, WYRect selectedDotRect);
	
	public native void setDotSpacing(float spacing);
	
	public native float getDotSpacing();
}
