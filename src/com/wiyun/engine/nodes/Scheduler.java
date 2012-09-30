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
package com.wiyun.engine.nodes;

import com.wiyun.engine.BaseWYObject;

/**
 * 定时调度器。 使用类似于Objective C的selector机制，用反射调用指定对象的某个方法。
 */
public class Scheduler extends BaseWYObject {
	/**
	 * 得到时间缩放比例
	 * 
	 * @return 时间缩放比例
	 */
	public native float getTimeScale();

	/**
	 * 设置时间缩放比例，假如原本是2秒后执行的操作，时间缩放比例为2时，会在1秒后
	 * 就执行
	 * 
	 * @param timeScale 时间缩放比例
	 */
	public native void setTimeScale(float timeScale);

	private static Scheduler sInstance = null;

	/**
	 * 获得调度器的单实例
	 * 
	 * @return {@link Scheduler}
	 */
	public static Scheduler getInstance() {
		synchronized(Scheduler.class) {
			if(sInstance == null) {
				sInstance = new Scheduler();
			} else {
				sInstance.setPointer(nativeGetInstance());
			}
			return sInstance;
		}
	}

	private Scheduler() {
		nativeInit();
	}
	
	private native static int nativeGetInstance();
	
	private native void nativeInit();

	/**
	 * 对一个Timer进行调度
	 * 
	 * @param t {@link Timer}
	 */
	public native void schedule(Timer t);

	/**
	 * 去掉对某个timer的调用
	 * 
	 * param t {@link Timer}
	 */
	public native void unschedule(Timer t);
}