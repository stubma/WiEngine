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
package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

/**
 * 非线性动作的封装, 是所有非线性动作的基类，负责把线性动作转换成非线性动作
 */
public abstract class EaseAction extends IntervalAction {
	protected EaseAction() {
	}
	
	protected EaseAction(IntervalAction action) {
	}
	
	protected EaseAction(int pointer) {
		super(pointer);
	}
	
	@Override
	public abstract EaseAction copy();

	@Override
	public abstract EaseAction reverse();
	
	/**
	 * 设置该EaseAction所包含的动作. 如果当前EaseAction正在运行, 则调用此方法无效. 在包含动作
	 * 被设置之前, 调用copy和reverse方法都是危险的.
	 *
	 * @param wrapped \link IntervalAction IntervalAction\endlink
	 */
	public native void setWrappedAction(IntervalAction wrapped);
}
