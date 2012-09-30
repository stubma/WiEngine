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

import com.wiyun.engine.utils.TargetSelector;

/**
 * \if English
 * Call a function specified by \link TargetSelector TargetSelector\endlink, this
 * action is an instant action so it is done immediately. Method pointed by \link TargetSelector TargetSelector\endlink
 * must have no arguments and in public domain
 * \else
 * 节点调用\link TargetSelector TargetSelector\endlink的动作封装, \link TargetSelector TargetSelector\endlink指向的
 * 方法不能有参数, 且必须是公有方法
 * \endif
 */
public class CallFunc extends InstantAction {
    /**
     * \if English
     * Create a call function action
     * 
     * @param target target object
     * @param selector selector of method, must be a public method and no arguments
     * @return {@link CallFunc}
     * \else
     * 创建一个调用动作实例
     * 
     * @param target 方法所属对象
     * @param selector 方法的选择子，类似于Objective C中selector的概念，为方法的字符串形式名称。指定的方法必须为public，且无参数
     * @return {@link CallFunc}
     * \endif
     */
    public static CallFunc make(Object target, String selector) {
        return new CallFunc(new TargetSelector(target, selector, null));
    }
    
    /**
     * \if English
     * Make a call function action
     * 
     * @param selector {@link TargetSelector}, the method pointed by {@link TargetSelector} must have
     * 		no arguments and must be public
     * @return {@link CallFunc}
     * \else
     * 创建一个调用动作实例
     * 
     * @param selector {@link TargetSelector}, 被指向的方法不能有参数, 且必须是public
     * @return {@link CallFunc}
     * \endif
     */
    public static CallFunc make(TargetSelector selector) {
    	return new CallFunc(selector);
    }

    protected CallFunc(TargetSelector selector) {
       nativeInit(selector);
    }
    
    private native void nativeInit(TargetSelector selector);
    
    public static CallFunc from(int pointer) {
    	return pointer == 0 ? null : new CallFunc(pointer);
    }
    
    protected CallFunc(int pointer) {
    	super(pointer);
    }

    @Override
	public CallFunc copy() {
        return new CallFunc(nativeCopy());
    }
    
	/**
	 * \if English
	 * CallFunc doesn't have reverse action
	 * \else
	 * CallFunc不支持逆向动作
	 * \endif
	 */
    @Override
    public InstantAction reverse() {
    	throw new UnsupportedOperationException("CallFunc doesn't have reverse action");
    }
}
