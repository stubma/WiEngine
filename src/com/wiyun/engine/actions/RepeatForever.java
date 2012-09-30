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
 * repeat an action, you can control repeat times
 * \else
 * 根据设置重复次数，重复执行动作的封装
 * \endif
 */
public class RepeatForever extends Action {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param other action to be repeated
	 * @param times repeat times
	 * \else
	 * 静态构造函数
	 *
	 * @param other 具体要执行的\link FiniteTimeAction FiniteTimeAction\endlink指针
	 * @param times 动作重复的次数
	 * \endif
	 */
    public static RepeatForever make(FiniteTimeAction action) {
        return new RepeatForever(action);
    }

    protected RepeatForever(FiniteTimeAction action) {
    	nativeInit(action);
    }
    
    /**
     * 从底层指针获得一个RepeatForever的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link RepeatForever}
     */
    public static RepeatForever from(int pointer) {
    	return pointer == 0 ? null : new RepeatForever(pointer);
    }
    
    protected RepeatForever(int pointer) {
    	super(pointer);
    }

	private native void nativeInit(FiniteTimeAction action);
	
	@Override
	public Action copy() {
		return new RepeatForever(nativeCopy());
	}
	
	@Override
	public Action reverse() {
		return new RepeatForever(nativeReverse());
	}
}
