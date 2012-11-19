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
#ifndef __wyMWSprite_h__
#define __wyMWSprite_h__

#include "wyAFCSprite.h"
#include "wyMWFileData.h"

/**
 * @class wyMWSprite
 *
 * Motion welder sprite, most logic is encapsulated in parent class and
 * it just provides some methods proprietary to motion welder
 *
 * \note
 * \link wyMWSprite wyMWSprite\endlink doesn't support clip mapping
 */
class WIENGINE_API wyMWSprite : public wyAFCSprite {
private:
	/**
	 * Animation data loaded from motion welder file
	 */
	wyMWFileData* m_mw;

protected:
	wyMWSprite();

public:
	/**
	 * Create motion welder sprite from resource id
	 *
	 * @param mwResId resource id of anu file
	 * @param animIndex animation index
	 * @param tex related textures, if more than one, can follow this argument. Must ends
	 * 		with NULL.
	 */
	static wyMWSprite* make(int mwResId, int animIndex, wyTexture2D* tex, ...);

	/**
	 * Create motion welder sprite from resource id
	 *
	 * @param mwResId resource id of anu file
	 * @param animIndex animation index
	 * @param tex texture array
	 * @param count count of \c tex array
	 */
	static wyMWSprite* make(int mwResId, int animIndex, wyTexture2D** tex, int count);

	/**
	 * Create motion welder sprite from path
	 *
	 * @param path path of anu file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 		is relative path under assets
	 * @param animIndex animation index
	 * @param tex related textures, if more than one, can follow this argument. Must ends
	 * 		with NULL.
	 */
	static wyMWSprite* make(const char* path, bool isFile, int animIndex, wyTexture2D* tex, ...);

	/**
	 * Create motion welder sprite from path
	 *
	 * @param path path of anu file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 		is relative path under assets
	 * @param animIndex animation index
	 * @param tex texture array
	 * @param count count of \c tex array
	 */
	static wyMWSprite* make(const char* path, bool isFile, int animIndex, wyTexture2D** tex, int count);

	/**
	 * Create motion welder sprite from memory file
	 *
	 * @param mfsName name of anu memory file
	 * @param animIndex animation index
	 * @param tex related textures, if more than one, can follow this argument. Must ends
	 * 		with NULL.
	 */
	static wyMWSprite* make(const char* mfsName, int animIndex, wyTexture2D* tex, ...);

	virtual ~wyMWSprite();

	/// @see wyAFCSprite::getFileData
	virtual wyAFCFileData* getFileData() { return m_mw; }

	/// @see wyAFCSprite::getAnimationAt
	virtual wyAFCAnimation* getAnimationAt(int index, wyAFCClipMapping* mapping = NULL);

	/// @see wyAFCSprite::getAnimationCount
	virtual int getAnimationCount();

	/// @see wyAFCSprite::getImageCount
	virtual int getImageCount();
};

#endif // __wyMWSprite_h__
