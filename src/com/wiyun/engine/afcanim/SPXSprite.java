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
 * \par
 * SpriteX is a tool of animation, exported file has *.sprite name. The structure of sprite
 * file is similar with anu file but different terms used.
 * \else
 * \par
 * SpriteX是一个和Motion Welder类似的
 * 动画编辑软件。 其动画的组织结构很像Motion Welder, 其导出的文件一般是*.sprite文件, 可以认为其对应于Motion Welder
 * 的*.anu文件. 但是SpriteX对一些术语的叫法和Motion Welder不同，不过基本只是名字不同， 其概念是类似的。比如：
 * 1. 动画， 在Motion Welder称为Animation, SpriteX中叫做Action
 * 2. 帧都是叫Frame
 * 3. Motion Welder中的Clip在SpriteX中叫做Tile
 * 4. 图片集在Motion Welder中就是Image, WiEngine一般称之为Atlas, SpriteX称之为Patch
 * \endif
 */
public class SPXSprite extends AFCSprite {
	public static SPXSprite from(int pointer) {
		return pointer == 0 ? null : new SPXSprite(pointer);
	}
	
	protected SPXSprite(int pointer) {
		super(pointer);
	}
	
	/**
	 * \if English
	 * Create a \link SPXSprite SPXSprite\endlink from a SpriteX resource file
	 *
	 * @param spxResId resource id of sprite file
	 * @param tex related texture object
	 * @param actionIndex animation index
	 * @return \link SPXSprite SPXSprite\endlink
	 * \else
	 * 通过一个SPX文件的资源id创建一个\link SPXSprite SPXSprite\endlink对象
	 *
	 * @param spxResId sprite文件的资源id
	 * @param tex 相关贴图对象
	 * @param actionIndex 动画索引
	 * @return \link SPXSprite SPXSprite\endlink
	 * \endif
	 */
	public static SPXSprite make(int spxResId, Texture2D tex, int actionIndex) {
		return new SPXSprite(spxResId, tex, actionIndex);
	}

	/**
	 * \if English
	 * Create a \link SPXSprite SPXSprite\endlink from a SpriteX file path
	 *
	 * @param spxPath path of sprite file
	 * @param isFile true means \c spxPath is an absolute path in file system, false if
	 * 		\c spxPath is relative path under assets
	 * @param tex related texture
	 * @param actionIndex animation index
	 * @return \link SPXSprite SPXSprite\endlink
	 * \else
	 * 通过一个SPX文件路径创建一个\link SPXSprite SPXSprite\endlink对象
	 *
	 * @param spxPath sprite文件的路径
	 * @param isFile true表示\c spxPath是一个文件系统的绝对路径， false表示\c spxPath是一个assets
	 * 		下的相对路径
	 * @param tex 相关贴图对象
	 * @param actionIndex 动画索引
	 * @return \link SPXSprite SPXSprite\endlink
	 * \endif
	 */
	public static SPXSprite make(String spxPath, boolean isFile, Texture2D tex, int actionIndex) {
		return new SPXSprite(spxPath, isFile, tex, actionIndex);
	}
	
	protected SPXSprite(int spxResId, Texture2D tex, int actionIndex) {
		nativeInit(spxResId, tex, actionIndex);
	}
	
	protected SPXSprite(String spxPath, boolean isFile, Texture2D tex, int actionIndex) {
		nativeInit(spxPath, isFile, tex, actionIndex);
	}
	
	private native void nativeInit(int spxResId, Texture2D tex, int actionIndex);
	private native void nativeInit(String spxPath, boolean isFile, Texture2D tex, int actionIndex);
}
