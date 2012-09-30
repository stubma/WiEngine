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
 * TGA格式的瓦片地图。通过把图片中象素的R值映射到瓦片图片集中，形成地图。 
 */
public class TGATileMapAtlas extends TileMapAtlas {
    /**
     * 创建瓦片地图
     * 
     * @param texture {@link Texture2D}
     * @param mapResId TGA文件资源id
     * @param tileWidth 单个瓦片图片的象素宽度
     * @param tileHeight 单个瓦片图片的象素高度
     * @return 瓦片地图
     */
    public static TGATileMapAtlas make(Texture2D texture, int mapResId, int tileWidth, int tileHeight) {
    	return new TGATileMapAtlas(texture, mapResId, tileWidth, tileHeight);
    }
    
	/**
     * 构造函数
     * 
     * @param texture {@link Texture2D}
     * @param mapResId TGA文件资源id
     * @param tileWidth 单个瓦片图片的象素宽度
     * @param tileHeight 单个瓦片图片的象素高度
	 */
	protected TGATileMapAtlas(Texture2D texture, int mapResId, int tileWidth, int tileHeight) {
		nativeInit(texture, mapResId, tileWidth, tileHeight);
	}
	
    /**
     * 从底层指针获得一个TGATileMapAtlas的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link TGATileMapAtlas}
     */
    public static TGATileMapAtlas from(int pointer) {
    	return pointer == 0 ? null : new TGATileMapAtlas(pointer);
    }
    
	protected TGATileMapAtlas(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(Texture2D texture, int mapResId, int tileWidth, int tileHeight);
}
