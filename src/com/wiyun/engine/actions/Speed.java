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
 * Accelerate or deaccelerate an action
 * \else
 * 加减速动作。相当于快镜头慢镜头，可以指定一个速度因子，比如2，则目标动作将会加快2倍。
 * \endif
 */
public class Speed extends Action {
	protected Action mOther;
	protected float mSpeed;

	/**
	 * \if English
	 * get coefficient of speed
	 *
	 * @return coefficient of speed
	 * \else
	 * 获得加速或减速的速率
	 *
	 * @return 加速或减速的速率
	 * \endif
	 */
	public native float getSpeed();

	/**
	 * \if English
	 * set coefficient of speed
	 *
	 * @param speed Coefficient of speed, if larger than 1 then it means acceleration.
	 * 		Can't set a negative value
	 * \else
	 * 设置加速或减速的速率
	 *
	 * @param speed 加速或减速的速率，大于1为加速
	 * \endif
	 */
	public native void setSpeed(float speed);

	/**
	 * \if English
	 * static factory method
	 *
	 * @param action the \link Action Action\endlink need to be speed up or down
	 * @param speed the coefficient of speed up or down
	 * \else
	 * 静态构造函数
	 *
	 * @param action 具体执行的 \link Action Action\endlink对象指针
	 * @param speed 加速或减速的速率，大于1为加速，取值必须大于0
	 * \endif
	 */
	public static Speed make(Action action, float speed) {
		return new Speed(action, speed);
	}

	/**
	 * 构造函数
	 * 
	 * @param action 要加速或者减速的动作
	 * @param speed 速度因子
	 */
	protected Speed(Action action, float speed) {
		nativeInit(action, speed);
	}

	public static Speed from(int pointer) {
    	return pointer == 0 ? null : new Speed(pointer);
    }
	
	protected Speed(int pointer) {
		super(pointer);
	}

	private native void nativeInit(Action action, float speed);

	@Override
	public Speed copy() {
		return new Speed(nativeCopy());
	}
	
	@Override
	public Action reverse() {
		return new Speed(nativeReverse());
	}
}
