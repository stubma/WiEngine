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

import com.wiyun.engine.opengl.Texture2D;

/**
 * 进度条节点对象，可以包装任意图片对象，实现只显示百分之0到100的效果。
 * 进度条的样式可以为条型或者扇形。
 */
public class ProgressTimer extends Node {
	/**
	 * 扇形，逆时针
	 */
	public static final int RADIAL_CCW = 1;

		/**
		 * 扇形，顺时针
		 */
	public static final int RADIAL_CW = 2;

		/**
		 * 水平条形，从左到右
		 */
	public static final int HORIZONTAL_BAR_LR = 3;

		/**
		 * 水平条形，从右到左
		 */
	public static final int HORIZONTAL_BAR_RL = 4;

		/**
		 * 垂直条形，从下到上
		 */
	public static final int VERTICAL_BAR_BT = 5;

		/**
		 * 垂直条形，从上到下
		 */
	public static final int VERTICAL_BAR_TB = 6;
	
	/**
	 * 创建进度条对象, 通过这种方式构造的进度条将使用这个贴图的完整大小.
	 * 
	 * @param resId 图象资源id
	 * @return 进度条对象
	 */
	public static ProgressTimer make(int resId) {
		return new ProgressTimer(resId);
	}

	/**
	 * 通过一个{@link Texture2D}对象构造一个
	 * 进度条，通过这种方式构造的进度条将使用这个贴图的完整大小.
	 *
	 * @param texture {@link Texture2D}
	 * @return 进度条对象
	 */
	public static ProgressTimer make(Texture2D texture) {
		return new ProgressTimer(texture);
	}
	
	/**
	 * 通过一个{@link Sprite}构造一个进度条.
	 * 进度条可能只使用相关贴图的一部分，因为sprite也许是个图片集贴图。
	 *
	 * @param sprite {@link Sprite}
	 * @return 进度条对象
	 */
	public static ProgressTimer make(Sprite sprite) {
		return new ProgressTimer(sprite);
	}

	/**
	 * 构造函数
	 * 
	 * @param resId 图象资源id
	 */
	protected ProgressTimer(int resId) {
		this((Texture2D)Texture2D.makePNG(resId).autoRelease());
	}

	/**
	 * 构造函数, 通过一个{@link Texture2D}对象构造一个
	 * 进度条，通过这种方式构造的进度条将使用这个贴图的完整大小.
	 *
	 * @param texture {@link Texture2D}
	 */
	protected ProgressTimer(Texture2D texture) {
		nativeInit(texture);
	}
	
	/**
	 * 构造函数, 通过一个{@link Sprite}构造一个进度条.
	 * 进度条可能只使用相关贴图的一部分，因为sprite也许是个图片集贴图。
	 *
	 * @param sprite {@link Sprite}
	 */
	protected ProgressTimer(Sprite sprite) {
		nativeInit(sprite);
	}
	
    private native void nativeInit(Sprite sprite);

	/**
     * 从底层指针获得一个ProgressTimer的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ProgressTimer}
     */
    public static ProgressTimer from(int pointer) {
    	return pointer == 0 ? null : new ProgressTimer(0, pointer);
    }
    
    protected ProgressTimer(int dummy, int pointer) {
    	super(pointer);
    }

	private native void nativeInit(Texture2D texture);
	
	@Override
	protected void doNativeInit() {
	}

	/**
	 * 设置进度，从0到100
	 * 
	 * @param percentage 进度
	 */
	public native void setPercentage(float percentage);
	
	/**
	 * 得到当前进度
	 * 
	 * @return 进度
	 */
	public native float getPercentage();

	/**
	 * 修改进度条的图片
	 * 
	 * @param newSprite 新图片对象
	 */
	public native void setSprite(Sprite newSprite);

	/**
	 * 设置进度条类型
	 * 
	 * @param newStyle 类型
	 */
	public native void setStyle(int newStyle);
}
