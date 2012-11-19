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
 */
class WIENGINE_API wySPX3Sprite : public wyAFCSprite {
private:
	/**
	 * SpriteX 2011 file data
	 */
	wySPX3FileData* m_spx;

protected:
	wySPX3Sprite();

public:
	virtual ~wySPX3Sprite();

	/**
	 * Create a \link wySPX3Sprite wySPX3Sprite\endlink from a SpriteX 2011 resource file
	 *
	 * @param spxResId resource id of sprite file
	 * @param actionIndex animation index
	 * @param tex related textures, if more than one, can follow this argument. Must ends
	 * 		with NULL.
	 * @return \link wySPX3Sprite wySPX3Sprite\endlink
	 */
	static wySPX3Sprite* make(int spxResId, int actionIndex, wyTexture2D* tex, ...);

	/**
	 * Create SpriteX 2011 sprite from resource id
	 *
	 * @param spxResId resource id of sprite file
	 * @param actionIndex animation index
	 * @param tex texture array
	 * @param count count of \c tex array
	 */
	static wySPX3Sprite* make(int spxResId, int actionIndex, wyTexture2D** tex, int count);

	/**
	 * Create a \link wySPX3Sprite wySPX3Sprite\endlink from a SpriteX 2011 file path
	 *
	 * @param spxPath path of sprite file
	 * @param isFile true means \c spxPath is an absolute path in file system, false if
	 * 		\c spxPath is relative path under assets
	 * @param actionIndex animation index
	 * @param tex related textures, if more than one, can follow this argument. Must ends
	 * 		with NULL.
	 * @return \link wySPX3Sprite wySPX3Sprite\endlink
	 */
	static wySPX3Sprite* make(const char* spxPath, bool isFile, int actionIndex, wyTexture2D* tex, ...);

	/**
	 * Create SpriteX 2011 sprite from path
	 *
	 * @param spxPath path of sprite file
	 * @param isFile true means \c spxPath is an absolute path in file system, false means \c spxPath
	 * 		is relative path under assets
	 * @param actionIndex animation index
	 * @param tex texture array
	 * @param count count of \c tex array
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
