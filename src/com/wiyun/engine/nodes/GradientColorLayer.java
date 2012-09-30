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

import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYColor4B;

/**
 * 渐变色的层。它是{@link Layer}子类，支持设置背景色。
 */
public class GradientColorLayer extends Layer implements Node.ISizable {
	/**
	 * 创建层
	 * 
	 * @param fromColor
	 *            层背景色
	 * @param toColor
	 *            层背景色
	 * @param degree
	 *            渐变角度,0标识从左到右水平变化，大于0为顺时针
	 * @return 层实例
	 */
	public static GradientColorLayer make(WYColor4B fromColor,
			WYColor4B toColor, int degree) {
		return new GradientColorLayer(fromColor, toColor, degree);
	}

	/**
	 * 构造函数
	 * 
	 * @param fromColor
	 *            层背景色
	 * @param toColor
	 *            层背景色
	 * @param degree
	 *            渐变角度,0标识从左到右水平变化，大于0为顺时针
	 */
	protected GradientColorLayer(WYColor4B fromColor, WYColor4B toColor,
			int degree) {
		nativeInit(fromColor, toColor, degree);
	}

	/**
	 * 从底层指针获得一个ColorLayer的Java对象
	 * 
	 * @param pointer
	 *            底层指针
	 * @return {@link GradientColorLayer}
	 */
	public static GradientColorLayer from(int pointer) {
		return pointer == 0 ? null : new GradientColorLayer(pointer);
	}

	protected GradientColorLayer(int pointer) {
		super(pointer);
	}

	private native void nativeInit(WYColor4B fromColor, WYColor4B toColor,
			int degree);

	@Override
	protected void doNativeInit() {
	}

	public native int getDegree();

	public native void setDegree(int degree);

	public native void getFromColor(WYColor3B color);

	public native void setFromColor(int r, int g, int b);

	public native void getToColor(WYColor3B color);

	public native void setToColor(int r, int g, int b);

}