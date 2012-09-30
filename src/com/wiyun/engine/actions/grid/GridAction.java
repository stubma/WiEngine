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

import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.ReverseTime;
import com.wiyun.engine.grid.BaseGrid;
import com.wiyun.engine.types.WYGridSize;

/**
 * 抽象基类，用于表示所有基于网格的动作。网格类动作需要Android 2.2以上支持。 
 */
public abstract class GridAction extends IntervalAction {
	/**
	 * 获得动作幅度
	 * 
	 * @return 动作幅度大小 
	 */
	public native float getAmplitude();

	/**
	 * 设置动作幅度。有些动作可以设置相应幅度，幅度会影响动作的剧烈程度。
	 * 
	 * @param amplitude 动作幅度大小 
	 */
	public native void setAmplitude(float amplitude);
	
	/**
	 * 得到动作幅度比率
	 * 
	 * @return 动作幅度比率
	 */
	public native float getAmplitudeRate();

	/**
	 * 设置动作幅度比率。动作幅度比率可以起到放大的作用。
	 * 
	 * @param amplitudeRate 动作幅度比率
	 */
	public native void setAmplitudeRate(float amplitudeRate);
	
	protected GridAction() {
	}
	
	protected GridAction(int pointer) {
		super(pointer);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 */
	protected GridAction(float duration, WYGridSize gSize) {
	}
	
	protected WYGridSize getGridSize() {
		return WYGridSize.make(getGridWidth(), getGridHeight());
	}
	
	protected native int getGridWidth();
	protected native int getGridHeight();

	/**
	 * 子类需要实现这个方法，返回一个网格对象
	 * 
	 * @return {@link BaseGrid}对象
	 */
	public native BaseGrid makeGrid();

	@Override
	public IntervalAction reverse() {
		return new ReverseTime(nativeReverse());
	}
}
