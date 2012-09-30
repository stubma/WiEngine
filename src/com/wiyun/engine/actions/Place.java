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
 * Move a node to specfied place. This action doesn't have reverse action and
 * execute instantly.
 * \else
 * 放置动作. 目标会被置于某个位置. 这是一个瞬发动作, 且无反向动作.
 * 调用reverse方法会抛出{@link UnsupportedOperationException}异常
 * \endif
 */
public class Place extends InstantAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param x x offset to be added
	 * @param y y offset to be added
	 * \else
	 * 静态构造函数
	 *
	 * @param x 目标位置x轴偏移量
	 * @param y 目标位置y轴偏移量
	 * \endif
	 */
    public static Place make(float x, float y) {
        return new Place(x, y);
    }

    protected Place(float x, float y) {
    	nativeInit(x, y);
    }
    
    /**
     * 从底层指针获得一个Place的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Place}
     */
    public static Place from(int pointer) {
    	return pointer == 0 ? null : new Place(pointer);
    }
    
    protected Place(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(float x, float y);

    @Override
    public Place copy() {
        return new Place(nativeCopy());
    }
    
    @Override
    public InstantAction reverse() {
    	throw new UnsupportedOperationException("Place doesn't have reverse action");
    }
}
