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

import com.wiyun.engine.types.WYColor3B;

/**
 * \if English
 * It changes color between start color and end color
 * \else
 * 节点染色的动作封装,根据设置起始染色量进行移动
 * \endif
 */
public class TintTo extends IntervalAction {
	/**
	 * \if English
	 * Static factory
	 * 
	 * @param duration action duration time in seconds
	 * @param from start color
	 * @param to end color
	 * \else
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param from 起始颜色
	 * @param to 结束颜色
	 * \endif
	 */
	public static TintTo make(float duration, WYColor3B from, WYColor3B to) {
		return new TintTo(duration, from.r, from.g, from.b, to.r, to.g, to.b);
	}
	
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action in seconds
	 * @param fromR red component of start color, from 0 to 255
	 * @param fromG green component of start color, from 0 to 255
	 * @param fromB blue component of start color, from 0 to 255
	 * @param to end color
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param fromR 初始红色值, 0到255
	 * @param fromG 初始绿色值, 0到255
	 * @param fromB 初始蓝色值, 0到255
	 * @param to 目标颜色
	 * \endif
	 */
	public static TintTo make(float duration, int fromR, int fromG, int fromB, WYColor3B to) {
		return new TintTo(duration, fromR, fromG, fromB, to.r, to.g, to.b);
	}
	
	/**
	 * \if English
	 * Static factory
	 * 
	 * @param duration action duration time in seconds
	 * @param from start color
	 * @param toR red component of end color, from 0 to 255
	 * @param toG green component of end color, from 0 to 255
	 * @param toB blue component of end color, from 0 to 255
	 * \else
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param from 起始颜色
	 * @param toR 结束颜色的r值
	 * @param toG 结束颜色的g值
	 * @param toB 结束颜色的b值
	 * @return {@link TintTo}
	 * \endif
	 */
	public static TintTo make(float duration, WYColor3B from, int toR, int toG, int toB) {
		return new TintTo(duration, from.r, from.g, from.b, toR, toG, toB);
	}
	
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action in seconds
	 * @param fromR red component of start color, from 0 to 255
	 * @param fromG green component of start color, from 0 to 255
	 * @param fromB blue component of start color, from 0 to 255
	 * @param toR red component of end color, from 0 to 255
	 * @param toG green component of end color, from 0 to 255
	 * @param toB blue component of end color, from 0 to 255
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param fromR 初始红色值, 0到255
	 * @param fromG 初始绿色值, 0到255
	 * @param fromB 初始蓝色值, 0到255
	 * @param toR 目标红色值, 0到255
	 * @param toG 目标绿色值, 0到255
	 * @param toB 目标蓝色值, 0到255
	 * \endif
	 */
	public static TintTo make(float duration, int fromR, int fromG, int fromB, int toR, int toG, int toB) {
		return new TintTo(duration, fromR, fromG, fromB, toR, toG, toB);
	}

	protected TintTo(float duration, int fromR, int fromG, int fromB, int toR, int toG, int toB) {
		nativeInit(duration, fromR, fromG, fromB, toR, toG, toB);
	}
	
    public static TintTo from(int pointer) {
    	return pointer == 0 ? null : new TintTo(pointer);
    }
	
	protected TintTo(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int fromR, int fromG, int fromB, int toR, int toG, int toB);

	@Override
	public IntervalAction copy() {
		return new TintTo(nativeCopy());
	}

	@Override
	public IntervalAction reverse() {
		return new TintTo(nativeReverse());
	}
}
