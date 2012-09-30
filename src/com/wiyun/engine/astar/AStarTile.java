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

import java.util.ArrayList;

import com.wiyun.engine.BaseWYObject;

/**
 * A*地图状况tile封装
 */
public class AStarTile extends BaseWYObject {
	public static final int TILE_BLOCK = 1;
	public static final int TILE_FREE = 0;
	
	public static AStarTile make(int type, int x, int y) {
		return new AStarTile(type, x, y);
	}

	protected AStarTile(int type, int x, int y) {
		doNativeInit(type, x, y);
	}
	
	public static AStarTile from(int pointer) {
		return pointer == 0 ? null : new AStarTile(pointer);
	}
	
	protected AStarTile(int pointer) {
		super(pointer);
	}
	
	protected void doNativeInit(int type, int x, int y) {
		nativeInit(type, x, y);
	}
	
	private native void nativeInit(int type, int x, int y);
	
	/**
	 * 返回g值得影响值
	 *
	 * @return g值得影响值
	 */
	public native final float getGRate();

	/**
	 * 设置g值得影响值
	 *
	 * @param gRate g值得影响值
	 */
	public native final void setGRate(float gRate);

	/**
	 * 返回tile x值
	 *
	 * @return tile x值
	 */
	public native final int getX();

	/**
	 * 返回tile y值
	 *
	 * @return tile y值
	 */
	public native final int getY();

	/**
	 * 返回tile状态, free或者block
	 *
	 * @return tile状态, free或者block
	 */
	public native final int getType();

	/**
	 * 设置tile状态, free或者block
	 *
	 * @param type tile状态
	 */
	public native final void setType(int type);

	/**
	 * 判断是否为block状态
	 *
	 * @return true为block状态
	 */
	public native final boolean isBlocked();

	/**
	 * 判断是否为free状态
	 *
	 * @return true为free状态
	 */
	public native final boolean isFree();

	/**
	 * 增加子节点
	 *
	 * @param tile 子节点
	 */
	public native final void pushChild(AStarTile tile);

	/**
	 * 返回子节点集合
	 *
	 * @return 子节点集合
	 */
	public ArrayList<AStarTile> getChildren() {
		ArrayList<AStarTile> children = new ArrayList<AStarTile>();
		int[] pointers = new int[getChildCount()];
		nativeGetChildren(pointers);
		for(int pointer : pointers)
			children.add(new AStarTile(pointer));
		return children;
	}

	public native int getChildCount();
	
	private native void nativeGetChildren(int[] children);
}
