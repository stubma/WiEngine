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
 * A node jumps from a position to elsewhere, the jumping can be adjusted by offset, height and times
 * \else
 * 节点跳跃的动作封装,根据设置起始点，结束点，高度，跳跃次数进行移动
 * \endif
 */
public class JumpTo extends IntervalAction {
	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration duration time of jumping
	 * @param startX start x position of jumping
	 * @param startY start y position of jumping
	 * @param endX end x position of jumping
	 * @param endY end y position of jumping
	 * @param height height of jumping
	 * @param jumps times of jumping
	 * @return \link JumpTo JumpTo\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startX 起始点x轴坐标
	 * @param startY 起始点y轴坐标
	 * @param endX 结束点y轴坐标
	 * @param endY 结束点y轴坐标
	 * @param height 节点跳跃的高度
	 * @param jumps 节点跳跃的次数
	 * @return \link JumpTo JumpTo\endlink
	 * \endif
	 */
    public static JumpTo make(float duration, float startX, float startY, float endX, float endY, float height, int jumps) {
        return new JumpTo(duration, startX, startY, endX, endY, height, jumps);
    }
  
    protected JumpTo(float duration, float startX, float startY, float endX, float endY, float height, int jumps) {
    	nativeInit(duration, startX, startY, endX, endY, height, jumps);
    }
    
    /**
     * 从底层指针获得一个JumpTo的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link JumpTo}
     */
    public static JumpTo from(int pointer) {
    	return pointer == 0 ? null : new JumpTo(pointer);
    }
    
    protected JumpTo(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(float duration, float startX, float startY, float endX, float endY, float height, int jumps);

    @Override
    public IntervalAction copy() {
        return new JumpTo(nativeCopy());
    }
    
    @Override
    public IntervalAction reverse() {
    	return new JumpTo(nativeReverse());
    }
}
