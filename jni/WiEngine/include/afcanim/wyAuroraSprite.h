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
#ifndef __wyAuroraSprite_h__
#define __wyAuroraSprite_h__

#include "wyAFCSprite.h"
#include "wyAuroraFileData.h"

/**
 * @class wyAuroraSprite
 *
 * \if English
 * AuroraGT is designed by gameloft and it names exported file as BSprite format. Actually
 * AuroraGT is not only an animation designer, but also a map designer and game element manager.
 * \else
 * AuroraGT编辑器是gameloft设计的游戏编辑器， 其实它不仅限于动画编辑， 还能支持编辑地图和管理游戏元素.
 * 其使用的导出文件格式叫做BSprite
 * \endif
 */
class WIENGINE_API wyAuroraSprite : public wyAFCSprite {
private:
	/**
	 * \if English
	 * BSprite file data
	 * \else
	 * BSprite文件数据
	 * \endif
	 */
	wyAuroraFileData* m_aurora;

protected:
	wyAuroraSprite();

public:
	virtual ~wyAuroraSprite();

	/**
	 * \if English
	 * Create aurora sprite from resource id
	 *
	 * @param bsResId resource id of BSprite file
	 * @param animIndex animation index
	 * @param tex related textures, if more than one, can follow this argument. Must ends
	 * 		with NULL.
	 * \else
	 * 从一个BSprite资源文件中创建\link wyAuroraSprite wyAuroraSprite\endlink
	 *
	 * @param bsResId BSprite文件的资源id
	 * @param animIndex 动画索引
	 * @param tex 相关联的\link wyTexture2D wyTexture2D\endlink, 后面可以跟可变参数, 方便指定
	 * 		更多关联的\link wyTexture2D wyTexture2D\endlink. 如果没有更多, 用NULL结尾
	 * \endif
	 */
	static wyAuroraSprite* make(int bsResId, int animIndex, wyTexture2D* tex, ...);

	/**
	 * \if English
	 * Create aurora sprite from resource id
	 *
	 * @param bsResId resource id of BSprite file
	 * @param animIndex animation index
	 * @param tex texture array
	 * @param count count of \c tex array
	 * \else
	 * 从一个BSprite资源文件中创建\link wyAuroraSprite wyAuroraSprite\endlink
	 *
	 * @param bsResId BSprite文件的资源id
	 * @param animIndex 动画索引
	 * @param tex 包含所有相关贴图的二维指针
	 * @param count 贴图个数
	 * \endif
	 */
	static wyAuroraSprite* make(int bsResId, int animIndex, wyTexture2D** tex, int count);

	/**
	 * \if English
	 * Create aurora sprite from path
	 *
	 * @param path path of BSprite file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 		is relative path under assets
	 * @param animIndex animation index
	 * @param tex related textures, if more than one, can follow this argument. Must ends
	 * 		with NULL.
	 * \else
	 * 从一个asset文件或者文件系统中的文件创建\link wyAuroraSprite wyAuroraSprite\endlink
	 *
	 * @param path BSprite文件的路径
	 * @param isFile true表示path是一个文件系统路径, 而false表示path是一个assets下的路径
	 * @param animIndex 动画索引
	 * @param tex 相关联的\link wyTexture2D wyTexture2D\endlink, 后面可以跟可变参数, 方便指定
	 * 		更多关联的\link wyTexture2D wyTexture2D\endlink. 如果没有更多, 用NULL结尾
	 * \endif
	 */
	static wyAuroraSprite* make(const char* path, bool isFile, int animIndex, wyTexture2D* tex, ...);

	/**
	 * \if English
	 * Create aurora sprite from path
	 *
	 * @param path path of BSprite file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 		is relative path under assets
	 * @param animIndex animation index
	 * @param tex texture array
	 * @param count count of \c tex array
	 * \else
	 * 从一个asset文件或者文件系统中的文件创建\link wyAuroraSprite wyAuroraSprite\endlink
	 *
	 * @param path BSprite文件的路径
	 * @param isFile true表示path是一个文件系统路径, 而false表示path是一个assets下的路径
	 * @param animIndex 动画索引
	 * @param tex 包含所有相关贴图的二维指针
	 * @param count 贴图个数
	 * \endif
	 */
	static wyAuroraSprite* make(const char* path, bool isFile, int animIndex, wyTexture2D** tex, int count);

	/**
	 * \if English
	 * Create aurora sprite from memory file
	 *
	 * @param mfsName name of BSprite memory file
	 * @param animIndex animation index
	 * @param tex related textures, if more than one, can follow this argument. Must ends
	 * 		with NULL.
	 * \else
	 * 从一个BSprite内存文件创建\link wyAuroraSprite wyAuroraSprite\endlink
	 *
	 * @param mfsName BSprite内存文件名称
	 * @param animIndex 动画索引
	 * @param tex 相关联的\link wyTexture2D wyTexture2D\endlink, 后面可以跟可变参数, 方便指定
	 * 		更多关联的\link wyTexture2D wyTexture2D\endlink. 如果没有更多, 用NULL结尾
	 * \endif
	 */
	static wyAuroraSprite* make(const char* mfsName, int animIndex, wyTexture2D* tex, ...);

	/// @see wyAFCSprite::getFileData
	virtual wyAFCFileData* getFileData() { return m_aurora; }

	/// @see wyAFCSprite::getAnimationAt
	virtual wyAFCAnimation* getAnimationAt(int index, wyAFCClipMapping* mapping = NULL);

	/// @see wyAFCSprite::getAnimationCount
	virtual int getAnimationCount();

	/// @see wyAFCSprite::getImageCount
	virtual int getImageCount();
};

#endif // __wyAuroraSprite_h__
