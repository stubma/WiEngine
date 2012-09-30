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
package com.wiyun.engine.afcanim;

import com.wiyun.engine.opengl.Texture2D;

/**
 * \if English
 * AuroraGT is designed by gameloft and it names exported file as BSprite format. Actually
 * AuroraGT is not only an animation designer, but also a map designer and game element manager.
 * \else
 * AuroraGT编辑器是gameloft设计的游戏编辑器， 其实它不仅限于动画编辑， 还能支持编辑地图和管理游戏元素.
 * 其使用的导出文件格式叫做BSprite
 * \endif
 */
public class AuroraSprite extends AFCSprite {
	/**
	 * \if English
	 * Create aurora sprite from resource id
	 *
	 * @param bsResId resource id of anu file
	 * @param animIndex animation index
	 * @param tex related textures, if more than one, can follow this argument
	 * \else
	 * 从一个anu资源文件中创建\link AuroraSprite AuroraSprite\endlink
	 *
	 * @param bsResId anu文件的资源id
	 * @param animIndex 动画索引
	 * @param tex 相关联的\link Texture2D Texture2D\endlink, 后面可以跟可变参数, 方便指定
	 * 		更多关联的\link Texture2D Texture2D\endlink. 
	 * \endif
	 */
	public static AuroraSprite make(int bsResId, int animIndex, Texture2D... tex) {
		return new AuroraSprite(bsResId, animIndex, tex);
	}
	
	/**
	 * \if English
	 * Create aurora sprite from path
	 *
	 * @param path path of anu file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 		is relative path under assets
	 * @param animIndex animation index
	 * @param tex related textures, if more than one, can follow this argument
	 * \else
	 * 从一个asset文件或者文件系统中的文件创建\link AuroraSprite AuroraSprite\endlink
	 *
	 * @param path anu文件的路径
	 * @param isFile true表示path是一个文件系统路径, 而false表示path是一个assets下的路径
	 * @param animIndex 动画索引
	 * @param tex 相关联的\link Texture2D Texture2D\endlink, 后面可以跟可变参数, 方便指定
	 * 		更多关联的\link Texture2D Texture2D\endlink.
	 * \endif
	 */
	public static AuroraSprite make(String path, boolean isFile, int animIndex, Texture2D... tex) {
		return new AuroraSprite(path, isFile, animIndex, tex);
	}
	
	public static AuroraSprite from(int pointer) {
		return pointer == 0 ? null : new AuroraSprite(pointer);
	}
	
	protected AuroraSprite(int bsResId, int animIndex, Texture2D[] tex) {
		nativeInit(bsResId, animIndex, tex);
	}
	
	protected AuroraSprite(String path, boolean isFile, int animIndex, Texture2D[] tex) {
		nativeInit(path, isFile, animIndex, tex);
	}
	
	protected AuroraSprite(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(int bsResId, int animIndex, Texture2D[] tex);
	
	private native void nativeInit(String path, boolean isFile, int animIndex, Texture2D[] tex);
}
