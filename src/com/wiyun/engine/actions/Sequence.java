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
 * execute actions one by one
 * \else
 * 按顺序执行一组动作的封装
 * \endif
 */
public class Sequence extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param action1 first action, must be subclass of \link FiniteTimeAction FiniteTimeAction\endlink
	 * @param actions second action, must be subclass of \link FiniteTimeAction FiniteTimeAction\endlink, you can append more
	 * 		actions after this one
	 * @return \link Sequence Sequence\endlink
	 * \else
	 * 构造\link Sequence Sequence\endlink对象指针
	 *
	 * @param action1 要执行的动作\link FiniteTimeAction FiniteTimeAction \endlink对象
	 * @param actions 要执行的动作其它\link FiniteTimeAction FiniteTimeAction \endlink对象,
	 * 		后面还可以添加多个\link FiniteTimeAction FiniteTimeAction \endlink对象
	 * @return \link Sequence Sequence\endlink对象指针
	 * \endif
	 */
    public static Sequence make(FiniteTimeAction action1, FiniteTimeAction... actions) {
        FiniteTimeAction prev = action1;
        for (FiniteTimeAction now : actions) {
        	// need auto release it, but we don't release last one so place auto release before new
        	if(prev instanceof Sequence)
        		prev.autoRelease();
            prev = new Sequence(prev, now);
        }
        return (Sequence) prev;
    }

    protected Sequence(FiniteTimeAction one, FiniteTimeAction two) {
    	nativeInit(one, two);
    }
   
    public static Sequence from(int pointer) {
    	return pointer == 0 ? null : new Sequence(pointer);
    }
    
    protected Sequence(int pointer) {
    	super(pointer);
    }

	private native void nativeInit(FiniteTimeAction one, FiniteTimeAction two);
	
	@Override
	public IntervalAction copy() {
		return new Sequence(nativeCopy());
	}
	
	@Override
	public IntervalAction reverse() {
		return new Sequence(nativeReverse());
	}
}
