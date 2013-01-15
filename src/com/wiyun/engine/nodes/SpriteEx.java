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
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.utils.ZwoptexFrame;

/**
 * 图片对象，有两种模式，批渲染模式和单独渲染模式。
 * 要启用批渲染模式，需要将节点作为子节点插入一个 \link SpriteBatchNode SpriteBatchNode \endlink 节点.
 * 在批渲染模式下，所使用的贴图为父SpriteBatchNode贴图。
 */
public class SpriteEx extends TextureNode {
	protected SpriteEx(int pointer) {
		super(pointer);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param tex 贴图
	 */	
	protected SpriteEx(Texture2D tex) {
		nativeInit(tex);
	}

	/**
	 * 构造函数
	 * 
	 * @param tex 贴图
	 * @param rect 指定使用的贴图区域，单位为像素
	 */	
	protected SpriteEx(Texture2D tex, WYRect rect) {
		nativeInit(tex, rect);
	}

	/**
	 * 构造函数
	 * 
	 * @param batchnode 父节点
	 * @param rect 指定使用的贴图区域，单位为像素
	 * @param zOrder sprite在batchnode中的z order
	 */	
	protected SpriteEx(SpriteBatchNode batchnode, WYRect rect, int zOrder) {
		nativeInit(batchnode, rect, zOrder);
	}
	
	protected SpriteEx(SpriteBatchNode batchnode, ZwoptexFrame f) {
		nativeInit(batchnode, f);
	}

	/**
	 * 创建一个图像节点，所用贴图区域为整个贴图
	 *
	 * @param resId 图片的资源Id,要求为png格式
	 */	
    public static SpriteEx make(int resId) {
    	return new SpriteEx((Texture2D)Texture2D.make(resId).autoRelease());
    }

	/**
	 * 创建一个图像节点，所用贴图区域为整个贴图
	 *
	 * @param tex 贴图
	 * @return {@link SpriteEx}
	 */
	public static SpriteEx make(Texture2D tex) {
		return new SpriteEx(tex);
	}
	
	/**
	 * 创建一个图像节点
	 *
	 * @param tex 贴图
	 * @param rect 指定使用的贴图区域，单位为像素
	 * @return {@link SpriteEx}
	 */	
	public static SpriteEx make(Texture2D tex, WYRect rect) {
		return new SpriteEx(tex, rect);
	}

	/**
	 * 创建一个图像节点, 启动批渲染模式
	 *
	 * @param batchnode 父节点
	 * @param rect 指定使用的贴图区域，单位为像素
	 * @return {@link SpriteEx}
	 */	
	public static SpriteEx make(SpriteBatchNode batchnode, WYRect rect) {
		return new SpriteEx(batchnode, rect, 0);
	}
	
	public static SpriteEx make(SpriteBatchNode batchnode, ZwoptexFrame f) {
		return new SpriteEx(batchnode, f);
	}
	
	/**
	 * 创建一个图像节点, 启动批渲染模式
	 *
	 * @param batchnode 父节点
	 * @param rect 指定使用的贴图区域，单位为像素
	 * @param zOrder sprite在batchnode中的z order
	 * @return {@link SpriteEx}
	 */	
	public static SpriteEx make(SpriteBatchNode batchnode, WYRect rect, int zOrder) {
		return new SpriteEx(batchnode, rect, zOrder);
	}
	
	public static SpriteEx from(int pointer) {
		return pointer == 0 ? null : new SpriteEx(pointer);
	}
	
	@Override
	protected void doNativeInit() {
	}
	
	// native methods declare
	private native void nativeInit(Texture2D tex);
	private native void nativeInit(Texture2D tex, WYRect rect);
	private native void nativeInit(SpriteBatchNode batchnode, WYRect rect, int zOrder);	
	private native void nativeInit(SpriteBatchNode batchnode, ZwoptexFrame f);	
}