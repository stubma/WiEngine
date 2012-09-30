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
 * {@link TileMapAtlas}的子类，实现了一个通过整型数组生成瓦片地图的机制。
 * 如果一个图片集包含3x3个单幅图片，则整数4会映射到第二行第二列的图片。因为
 * 4 / 3 = 1, 4 % 3 = 1。
 */
public class ArrayTileMapAtlas extends TileMapAtlas {
	/**
	 * 创建数组式瓦片地图
	 * 
	 * @param texture {@link Texture2D}
	 * @param tileWidth 单个瓦片图片的宽度
	 * @param tileHeight 单个瓦片图片的高度
	 * @param xTiles x方向瓦片个数
	 * @param yTiles y方向瓦片个数
	 * @return 瓦片地图实例
	 */
	public static ArrayTileMapAtlas make(Texture2D texture, int tileWidth, int tileHeight, int xTiles, int yTiles) {
		return new ArrayTileMapAtlas(texture, tileWidth, tileHeight, xTiles, yTiles);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param texture {@link Texture2D}
	 * @param tileWidth 单个瓦片图片的宽度
	 * @param tileHeight 单个瓦片图片的高度
	 * @param xTiles x方向瓦片个数
	 * @param yTiles y方向瓦片个数
	 */
	protected ArrayTileMapAtlas(Texture2D texture, int tileWidth, int tileHeight, int xTiles, int yTiles) {
		nativeInit(texture, tileWidth, tileHeight, xTiles, yTiles);
    }
	
    /**
     * 从底层指针获得一个ArrayTileMapAtlas的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ArrayTileMapAtlas}
     */
    public static ArrayTileMapAtlas from(int pointer) {
    	return pointer == 0 ? null : new ArrayTileMapAtlas(pointer);
    }
    
	protected ArrayTileMapAtlas(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(Texture2D texture, int tileWidth, int tileHeight, int xTiles, int yTiles);
	
	public native void setTiles(int[][] tiles);
}
