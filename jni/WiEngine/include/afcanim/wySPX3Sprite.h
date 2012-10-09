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
#ifndef __wySPX3Sprite_h__
#define __wySPX3Sprite_h__

#include "wyAFCSprite.h"
#include "wySPX3FileData.h"

/**
 * @class wySPX3Sprite
 *
 * \if English
 * \par
 * SpriteX 2011 is a tool of animation, exported file has *.sprite name. The structure of sprite
 * file is similar with anu file but different terms used.
 *
 * \par
 * This class supports exported file of SpriteX 2011 2011. SpriteX 2011 uses an incompatible file format with
 * 3.9.4, so WiEngine creates \link wySPX3Sprite wySPX3Sprite\endlink.
 *
 * \note
 * \link wySPX3Sprite wySPX3Sprite\endlink doesn't support clip mapping
 * \else
 * \par
 * SpriteX 2011是一个和Motion Welder类似的
 * 动画编辑软件。 其动画的组织结构很像Motion Welder, 其导出的文件一般是*.sprite文件, 可以认为其对应于Motion Welder
 * 的*.anu文件. 但是SpriteX 2011对一些术语的叫法和Motion Welder不同，不过基本只是名字不同， 其概念是类似的。比如：
 * 1. 动画， 在Motion Welder称为Animation, SpriteX 2011中叫做Action
 * 2. 帧都是叫Frame
 * 3. Motion Welder中的Clip在SpriteX 2011中叫做Tile
 * 4. 图片集在Motion Welder中就是Image, WiEngine一般称之为Atlas, SpriteX 2011称之为Patch
 *
 * \par
 * 这个类用于支持SpriteX 2011版本的导出文件. SpriteX 2011的导出文件格式和3.9.4是不兼容的, 因此WiEngine新增了
 * \link wySPX3Sprite wySPX3Sprite\endlink来处理2011的动画. 但是2011仍然是一个AFC架构编辑器, 因此仍然是
 * \link wyAFCSprite wyAFCSprite\endlink的子类
 *
 * \note
 * \link wySPX3Sprite wySPX3Sprite\endlink不支持分片映射
 * \endif
 */
class WIENGINE_API wySPX3Sprite : public wyAFCSprite {
private:
	/**
	 * \if English
	 * SpriteX 2011 file data
	 * \else
	 * SpriteX 2011文件数据
	 * \endif
	 */
	wySPX3FileData* m_spx;

protected:
	wySPX3Sprite();

public:
	virtual ~wySPX3Sprite();

	/**
	 * \if English
	 * Create a \link wySPX3Sprite wySPX3Sprite\endlink from a SpriteX 2011 resource file
	 *
	 * @param spxResId resource id of sprite file
	 * @param actionIndex animation index
	 * @param tex related textures, if more than one, can follow this argument. Must ends
	 * 		with NULL.
	 * @return \link wySPX3Sprite wySPX3Sprite\endlink
	 * \else
	 * 通过一个SpriteX 2011文件的资源id创建一个\link wySPX3Sprite wySPX3Sprite\endlink对象
	 *
	 * @param spxResId sprite文件的资源id
	 * @param actionIndex 动画索引
	 * @param tex 相关联的\link wyTexture2D wyTexture2D\endlink, 后面可以跟可变参数, 方便指定
	 * 		更多关联的\link wyTexture2D wyTexture2D\endlink. 如果没有更多, 用NULL结尾.
	 * @return \link wySPX3Sprite wySPX3Sprite\endlink
	 * \endif
	 */
	static wySPX3Sprite* make(int spxResId, int actionIndex, wyTexture2D* tex, ...);

	/**
	 * \if English
	 * Create SpriteX 2011 sprite from resource id
	 *
	 * @param spxResId resource id of sprite file
	 * @param actionIndex animation index
	 * @param tex texture array
	 * @param count count of \c tex array
	 * \else
	 * 从一个SpriteX 2011资源文件中创建\link wySPX3Sprite wySPX3Sprite\endlink
	 *
	 * @param spxResId SpriteX 2011文件的资源id
	 * @param actionIndex 动画索引
	 * @param tex 包含所有相关贴图的二维指针
	 * @param count 贴图个数
	 * \endif
	 */
	static wySPX3Sprite* make(int spxResId, int actionIndex, wyTexture2D** tex, int count);

	/**
	 * \if English
	 * Create a \link wySPX3Sprite wySPX3Sprite\endlink from a SpriteX 2011 file path
	 *
	 * @param spxPath path of sprite file
	 * @param isFile true means \c spxPath is an absolute path in file system, false if
	 * 		\c spxPath is relative path under assets
	 * @param actionIndex animation index
	 * @param tex related textures, if more than one, can follow this argument. Must ends
	 * 		with NULL.
	 * @return \link wySPX3Sprite wySPX3Sprite\endlink
	 * \else
	 * 通过一个SpriteX 2011文件路径创建一个\link wySPX3Sprite wySPX3Sprite\endlink对象
	 *
	 * @param spxPath sprite文件的路径
	 * @param isFile true表示\c spxPath是一个文件系统的绝对路径， false表示\c spxPath是一个assets
	 * 		下的相对路径
	 * @param actionIndex 动画索引
	 * @param tex 相关联的\link wyTexture2D wyTexture2D\endlink, 后面可以跟可变参数, 方便指定
	 * 		更多关联的\link wyTexture2D wyTexture2D\endlink. 如果没有更多, 用NULL结尾.
	 * @return \link wySPX3Sprite wySPX3Sprite\endlink
	 * \endif
	 */
	static wySPX3Sprite* make(const char* spxPath, bool isFile, int actionIndex, wyTexture2D* tex, ...);

	/**
	 * \if English
	 * Create SpriteX 2011 sprite from path
	 *
	 * @param spxPath path of sprite file
	 * @param isFile true means \c spxPath is an absolute path in file system, false means \c spxPath
	 * 		is relative path under assets
	 * @param actionIndex animation index
	 * @param tex texture array
	 * @param count count of \c tex array
	 * \else
	 * 从一个asset文件或者文件系统中的文件创建\link wySPX3Sprite wySPX3Sprite\endlink
	 *
	 * @param spxPath SpriteX 2011文件的路径
	 * @param isFile true表示\c spxPath是一个文件系统路径, 而false表示\c spxPath是一个assets下的路径
	 * @param actionIndex 动画索引
	 * @param tex 包含所有相关贴图的二维指针
	 * @param count 贴图个数
	 * \endif
	 */
	static wySPX3Sprite* make(const char* spxPath, bool isFile, int actionIndex, wyTexture2D** tex, int count);

	/// @see wyAFCSprite::getFileData
	virtual wyAFCFileData* getFileData() { return m_spx; }

	/// @see wyAFCSprite::getAnimationAt
	virtual wyAFCAnimation* getAnimationAt(int index, wyAFCClipMapping* mapping = NULL);

	/// @see wyAFCSprite::getAnimationCount
	virtual int getAnimationCount();

	/// @see wyAFCSprite::getImageCount
	virtual int getImageCount();
};

#endif // __wySPX3Sprite_h__
