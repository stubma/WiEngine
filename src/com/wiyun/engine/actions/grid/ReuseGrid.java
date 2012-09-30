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

import com.wiyun.engine.actions.InstantAction;
import com.wiyun.engine.grid.BaseGrid;

/**
 * 复用网格。{@link BaseGrid}对象可以重复利用，可以节省时间。如果两个效果需要使用网格完成，而网格的大小
 * 没有变化，一般可以复用网格。网格内部有复用次数的计数，这个动作就是增加它的复用次数计数。 
 */
public class ReuseGrid extends InstantAction {
	/**
	 * 创建动作实例
	 * 
	 * @param times 复用次数
	 * @return 动作实例
	 */
	public static ReuseGrid make(int times) {
		return new ReuseGrid(times);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param times 复用次数
	 */
	protected ReuseGrid(int times) {
		nativeInit(times);
	}
	
    /**
     * 从底层指针获得一个ReuseGrid的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ReuseGrid}
     */
    public static ReuseGrid from(int pointer) {
    	return pointer == 0 ? null : new ReuseGrid(0, pointer);
    }
    
	protected ReuseGrid(int dummy, int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(int times);
	
	@Override
	public InstantAction copy() {
		return new ReuseGrid(0, nativeCopy());
	}
	
	@Override
	public InstantAction reverse() {
		return new ReuseGrid(0, nativeReverse());
	}
}
