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
#ifndef __wySPXSprite_h__
#define __wySPXSprite_h__

#include "wyAFCSprite.h"
#include "wySPXFileData.h"

/**
 * @class wySPXSprite
 *
 * \par
 * SpriteX is a tool of animation, exported file has *.sprite name. The structure of sprite
 * file is similar with anu file but different terms used.
 *
 * \par
 * This class supports exported file of SpriteX 3.9.4. For SpriteX 2011, you need \link wySPX3Sprite wySPX3Sprite\endlink
 * because file format is totally changed. Remember SpriteX 3.9.4 is second generation not third, that's why SpriteX 2011 uses
 * SPX3 prefix. Maybe a little confusing so be careful.
 */
class WIENGINE_API wySPXSprite : public wyAFCSprite {
private:
	/**
	 * SpriteX file data
	 */
	wySPXFileData* m_spx;

protected:
	wySPXSprite();

public:
	virtual ~wySPXSprite();

	/**
	 * Create a \link wySPXSprite wySPXSprite\endlink from a SpriteX resource file
	 *
	 * @param spxResId resource id of sprite file
	 * @param tex related texture object
	 * @param actionIndex animation index
	 * @return \link wySPXSprite wySPXSprite\endlink
	 */
	static wySPXSprite* make(int spxResId, wyTexture2D* tex, int actionIndex);

	/**
	 * Create a \link wySPXSprite wySPXSprite\endlink from a SpriteX file path
	 *
	 * @param spxPath path of sprite file
	 * @param isFile true means \c spxPath is an absolute path in file system, false if
	 * 		\c spxPath is relative path under assets
	 * @param tex related texture
	 * @param actionIndex animation index
	 * @return \link wySPXSprite wySPXSprite\endlink
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
