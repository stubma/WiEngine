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
 * Base class for actions whose time is definite
 * \else
 * 用于表示在有限时间内可以完成的动作
 * \endif
 */
public abstract class FiniteTimeAction extends Action {
	protected FiniteTimeAction() {
	}
    
    protected FiniteTimeAction(float duration) {
    }
    
    protected FiniteTimeAction(int pointer) {
    	super(pointer);
    }
    
	/**
	 * \if English
	 * Get elapsed time of this action
	 *
	 * @return elapsed time in second
	 * \else
	 * 获得动作已经持续的时间
	 *
	 * @return 动作已经持续的时间
	 * \endif
	 */
	public native float getElapsed();
    
	/**
	 * \if English
	 * Get duration time of action
	 *
	 * @return duration time of action
	 * \else
	 * 获得动作持续时间长度
	 *
	 * @return 动作持续时间长度
	 * \endif
	 */
    public native float getDuration();

	/**
	 * \if English
	 * Set duration time of action, no effect if action is started
	 *
	 * @param duration duration time of action
	 * \else
	 * 设置动作持续时间长度, 如果动作已经开始执行, 设置不会有效果
	 *
	 * @param duration 动作持续时间长度
	 * \endif
	 */
    public native void setDuration(float duration);
}
