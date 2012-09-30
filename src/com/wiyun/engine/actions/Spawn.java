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
 * Execute two actions simultaneously. The duration time will be the longer-lived action's time
 * \else
 * 同时执行两个动作的封装
 * \endif
 */
public class Spawn extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param action1 first action, must be subclass of \link FiniteTimeAction FiniteTimeAction\endlink
	 * @param params other actions, must be subclass of \link FiniteTimeAction FiniteTimeAction\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param action1 要执行的动作 \link FiniteTimeAction FiniteTimeAction\endlink对象指针
	 * @param params 其它要执行的动作 \link FiniteTimeAction FiniteTimeAction\endlink对象指针
	 * \endif
	 */
	public static IntervalAction make(FiniteTimeAction action1, FiniteTimeAction... params) {
		FiniteTimeAction prev = action1;

		if(action1 != null) {
			for(FiniteTimeAction now : params) {
				if(prev instanceof Spawn) 
					prev.autoRelease();
				prev = new Spawn(prev, now);
			}
		}
		return (IntervalAction)prev;
	}
	
	/**
	 * \if English
	 * static factory method
	 *
	 * @param one first action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction \endlink
	 * @param two second action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction \endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param one 要执行的动作 \link wyFiniteTimeAction wyFiniteTimeAction \endlink对象指针
	 * @param two 要执行的动作 \link wyFiniteTimeAction wyFiniteTimeAction \endlink对象指针
	 * \endif
	 */
	public static Spawn make(FiniteTimeAction one, FiniteTimeAction two) {
		return new Spawn(one, two);
	}

	protected Spawn(FiniteTimeAction one, FiniteTimeAction two) {
		nativeInit(one, two);
	}

	public static Spawn from(int pointer) {
    	return pointer == 0 ? null : new Spawn(pointer);
    }
    
	protected Spawn(int pointer) {
		super(pointer);
	}

	private native void nativeInit(FiniteTimeAction one, FiniteTimeAction two);

	@Override
	public IntervalAction copy() {
		return new Spawn(nativeCopy());
	}

	@Override
	public IntervalAction reverse() {
		return new Spawn(nativeReverse());
	}
}
