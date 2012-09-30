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
package com.wiyun.engine.astar;

import com.wiyun.engine.BaseWYObject;

/**
 * A*查找路径返回的节点封装
 */
public class AStarStep extends BaseWYObject {
	/**
	 * 构造函数
	 *
	 * @param x tile x值
	 * @param y tile y值
	 */
	public static AStarStep make(int x, int y) {
		return new AStarStep(x, y);
	}
	
	protected AStarStep(int x, int y) {
		doNativeInit(x, y);
	}

	public static AStarStep from(int pointer) {
		return pointer == 0 ? null : new AStarStep(pointer);
	}

	protected AStarStep(int pointer) {
		super(pointer);
	}

	protected void doNativeInit(int x, int y) {
		nativeInit(x, y);
	}

	private native void nativeInit(int x, int y);
	
	/**
	 * 设置tile x值
	 *
	 * @param x tile x值
	 */
	public native final void setX(int x);

	/**
	 * 返回tile x值
	 *
	 * @return tile x值
	 */
	public native final int getX();

	/**
	 * 设置tile y值
	 *
	 * @param y tile y值
	 */
	public native final void setY(int y);

	/**
	 * 返回tile y值
	 *
	 * @return tile y值
	 */
	public native final int getY();

	/**
	 * 设置节点f值
	 *
	 * @param f 节点f值
	 */
	public native final void setF(float f);

	/**
	 * 返回节点f值
	 *
	 * @return 节点f值
	 */
	public native final float getF();

	/**
	 * 设置节点 h值
	 *
	 * @param h 节点h值
	 */
	public native final void setH(float h);

	/**
	 * 返回节点h值
	 *
	 * @return 节点h值
	 */
	public native final float getH();

	/**
	 * 设置节点 g值
	 *
	 * @param g 节点g值
	 */
	public native final void setG(float g);

	/**
	 * 返回节点h值
	 *
	 * @return 节点g值
	 */
	public native final float getG();
}
