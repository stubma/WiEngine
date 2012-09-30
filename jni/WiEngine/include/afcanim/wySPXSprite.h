/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wySPXSprite_h__
#define __wySPXSprite_h__

#include "wyAFCSprite.h"
#include "wySPXFileData.h"

/**
 * @class wySPXSprite
 *
 * \if English
 * \par
 * SpriteX is a tool of animation, exported file has *.sprite name. The structure of sprite
 * file is similar with anu file but different terms used.
 *
 * \par
 * This class supports exported file of SpriteX 3.9.4. For SpriteX 2011, you need \link wySPX3Sprite wySPX3Sprite\endlink
 * because file format is totally changed. Remember SpriteX 3.9.4 is second generation not third, that's why SpriteX 2011 uses
 * SPX3 prefix. Maybe a little confusing so be careful.
 * \else
 * \par
 * SpriteX是一个和Motion Welder类似的
 * 动画编辑软件。 其动画的组织结构很像Motion Welder, 其导出的文件一般是*.sprite文件, 可以认为其对应于Motion Welder
 * 的*.anu文件. 但是SpriteX对一些术语的叫法和Motion Welder不同，不过基本只是名字不同， 其概念是类似的。比如：
 * 1. 动画， 在Motion Welder称为Animation, SpriteX中叫做Action
 * 2. 帧都是叫Frame
 * 3. Motion Welder中的Clip在SpriteX中叫做Tile
 * 4. 图片集在Motion Welder中就是Image, WiEngine一般称之为Atlas, SpriteX称之为Patch
 *
 * \par
 * 这个类用于支持SpriteX 3.9.4版本的导出文件， 对于SpriteX 2011版本， 需要使用\link wySPX3Sprite wySPX3Sprite\endlink，
 * 因为其格式完全变化了。SpriteX 2011在逻辑上对应的是第三代版本, 因此前缀是SPX3. SpriteX 3.9.4应该只算第二代， 所以稍微有点乱，
 * 不要搞错了。
 * \endif
 */
class WIENGINE_API wySPXSprite : public wyAFCSprite {
private:
	/**
	 * \if English
	 * SpriteX file data
	 * \else
	 * SpriteX文件数据
	 * \endif
	 */
	wySPXFileData* m_spx;

protected:
	wySPXSprite();

public:
	virtual ~wySPXSprite();

	/**
	 * \if English
	 * Create a \link wySPXSprite wySPXSprite\endlink from a SpriteX resource file
	 *
	 * @param spxResId resource id of sprite file
	 * @param tex related texture object
	 * @param actionIndex animation index
	 * @return \link wySPXSprite wySPXSprite\endlink
	 * \else
	 * 通过一个SPX文件的资源id创建一个\link wySPXSprite wySPXSprite\endlink对象
	 *
	 * @param spxResId sprite文件的资源id
	 * @param tex 相关贴图对象
	 * @param actionIndex 动画索引
	 * @return \link wySPXSprite wySPXSprite\endlink
	 * \endif
	 */
	static wySPXSprite* make(int spxResId, wyTexture2D* tex, int actionIndex);

	/**
	 * \if English
	 * Create a \link wySPXSprite wySPXSprite\endlink from a SpriteX file path
	 *
	 * @param spxPath path of sprite file
	 * @param isFile true means \c spxPath is an absolute path in file system, false if
	 * 		\c spxPath is relative path under assets
	 * @param tex related texture
	 * @param actionIndex animation index
	 * @return \link wySPXSprite wySPXSprite\endlink
	 * \else
	 * 通过一个SPX文件路径创建一个\link wySPXSprite wySPXSprite\endlink对象
	 *
	 * @param spxPath sprite文件的路径
	 * @param isFile true表示\c spxPath是一个文件系统的绝对路径， false表示\c spxPath是一个assets
	 * 		下的相对路径
	 * @param tex 相关贴图对象
	 * @param actionIndex 动画索引
	 * @return \link wySPXSprite wySPXSprite\endlink
	 * \endif
	 */
	static wySPXSprite* make(const char* spxPath, bool isFile, wyTexture2D* tex, int actionIndex);

	/// @see wyAFCSprite::getFileData
	virtual wyAFCFileData* getFileData() { return m_spx; }

	/// @see wyAFCSprite::getAnimationAt
	virtual wyAFCAnimation* getAnimationAt(int index, wyAFCClipMapping* mapping = NULL);

	/// @see wyAFCSprite::getAnimationCount
	virtual int getAnimationCount();

	/// @see wyAFCSprite::getImageCount
	virtual int getImageCount();
};

#endif // __wySPXSprite_h__
