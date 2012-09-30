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
package com.wiyun.engine.grid;

import com.wiyun.engine.types.WYGridSize;
import com.wiyun.engine.types.WYVertex3D;

/**
 * Grid3D是以点为操作单位的一种网格，比如说网格的大小设置成2行2列，那么从点的角度看应该是每行每列都有
 * 3个点，因此实际总共有9个点。而Grid3D的主要操作就针对这9个点来进行。因为操作是针对点进行的，因此
 * 产生的效果具有视觉上的连续性，虽然图象可能出现扭曲变形，但是并不会分裂开，这是和TileGrid3D的主要区别。
 */
public class Grid3D extends BaseGrid {
	/**
	 * \if English
	 * Create a 3d grid
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 * \else
	 * 创建一个3d网格
	 *
	 * @param w 网格总宽度
	 * @param h 网格总高度
	 * @param c 网格列数
	 * @param r 网格行数
	 * \endif
	 */
	public static Grid3D make(float w, float h, int c, int r) {
		return new Grid3D(w, h, c, r);
	}
	
	protected Grid3D(float w, float h, int c, int r) {
		nativeInit(w, h, c, r);
	}
	
	public Grid3D(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(float w, float h, int c, int r);

	/**
	 * 获取某位置的顶点坐标
	 * 
	 * @param pos 点的行列坐标
	 * @return {@link WYVertex3D}
	 */
	public WYVertex3D getVertex(WYGridSize pos) {
		WYVertex3D vertex = WYVertex3D.makeZero();
		getVertex(pos.x, pos.y, vertex);
		return vertex;
	}
	
	private native void getVertex(int x, int y, WYVertex3D vertex);

	/**
	 * 获取某位置的初始顶点坐标
	 * 
	 * @param pos 点的行列坐标
	 * @return {@link WYVertex3D}
	 */
	public WYVertex3D getOriginalVertex(WYGridSize pos) {
		WYVertex3D vertex = WYVertex3D.makeZero();
		getOriginalVertex(pos.x, pos.y, vertex);
		return vertex;
	}
	
	private native void getOriginalVertex(int x, int y, WYVertex3D vertex);

	/**
	 * 设置某位置的顶点坐标
	 * 
	 * @param pos 点的行列坐标
	 * @param vertex {@link WYVertex3D}
	 */
	public void setVertex(WYGridSize pos, WYVertex3D vertex) {
		setVertex(pos.x, pos.y, vertex.x, vertex.y, vertex.z);
	}
	
	private native void setVertex(int x, int y, float vx, float vy, float vz);
}
