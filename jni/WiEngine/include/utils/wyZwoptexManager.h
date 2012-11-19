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
#ifndef __wyZwoptexManager_h__
#define __wyZwoptexManager_h__

#include "wyObject.h"
#include "wyZwoptex.h"
#include "wySprite.h"
#include "wySpriteEx.h"
#include "wyButton.h"

// for code simplify
#define WY_ZWOPTEX_MAP map<const char*, wyZwoptex*, wyStrPredicate>
#define WY_ZWOPTEX_ITER WY_ZWOPTEX_MAP::iterator

/**
 * @class wyZwoptexManager
 *
 * Atlas manager, it maintains a cache for every atlas image. So when you don't want some atlas, you
 * must remove it from this manager
 */
class WIENGINE_API wyZwoptexManager : public wyObject {
private:
	WY_ZWOPTEX_MAP* m_cache;

private:
	wyZwoptexManager();

	/// find sprite frame by frame name, it searches all zwoptex
	wySpriteFrame* findSpriteFrame(const char* frameName);

	/// find zwoptex frame by frame name, it searches all zwoptex
	/// also it can returned matched zwoptex
	wyZwoptexFrame* findFrame(const char* frameName, wyZwoptex** outZwoptex = NULL, char** outName = NULL);

public:
	static wyZwoptexManager* getInstance();
	virtual ~wyZwoptexManager();

	/**
	 * Add a zwoptex to cache, its name is the key
	 *
	 * @param name name of zwoptex
	 * @param resId resource id of zwoptex plist file
	 * @param tex related texture of zwoptex atlas image. It can be NULL but you must
	 * 		set it before use it
	 */
	void addZwoptex(const char* name, int resId, wyTexture2D* tex = NULL);

	/**
	 * Add a zwoptex by name
	 *
	 * @param name name of zwoptex
	 * @param path path of zwoptex plist file
	 * @param isFile true means \c path is an absolute path in file system, false
	 * 		means \c path is a relative path under assets
	 * @param tex related texture of zwoptex atlas image, it can be NULL but must be
	 * 		set before using
	 * @param inDensity input density of zwoptex, default is zero and it means use current
	 * 		defaultInDensity
	 */
	void addZwoptex(const char* name, const char* path, bool isFile = false, wyTexture2D* tex = NULL, float inDensity = 0);

	/**
	 * Get a cached zwoptex object by name
	 *
	 * @param name name of zwoptex
	 * @return cache
	 */
	wyZwoptex* getZwoptex(const char* name);

	/**
	 * Remove a cached zwoptex object by name. But for the texture object, you must
	 * use \link wyTextureManager wyTextureManager\endlink to delete it.
	 *
	 * @param name name of zwoptex
	 */
	void removeZwoptex(const char* name);

	/**
	 * Remove all zwoptex. But for texture, you must remove it by \link wyTextureManager wyTextureManager\endlink
	 */
	void removeAllZwoptex();

	/**
	 * Check if a zwoptex object with given name exists
	 *
	 * @param name name of zwoptex
	 * @return true means this zwoptex is already loaded
	 */
	bool hasZwoptex(const char* name);

	/**
	 * Get names of all frames in zwoptex
	 *
	 * @param name name of zwoptex
	 * @param count how many frames in this zwoptex
	 * @return name list of all frames
	 */
	const char** getFrameNames(const char* name, size_t* count);

	/**
	 * Get frame count in a zwoptex
	 *
	 * @param zwoptexName zwoptex name
	 * @return frame count in this zwoptex, or zero if zwoptex not found
	 */
	int getFrameCount(const char* zwoptexName);

	/**
	 * Get a frame rect by name. The frame rect returned is effective area of frame image and
	 * it should be smaller than original size if image has transparent border
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @return \link wyRect wyRect\endlink, or zero rectangle if not found
	 */
	wyRect getFrameRect(const char* zwoptexName, const char* frameName);

	/**
	 * Get a frame rect by frame name. This method doesn't require zwoptex name so
	 * it will search all zwoptexes. You can use this method if you already know there
	 * is no frame has same name
	 *
	 * @param frameName name of frame
	 * @return \link wyRect wyRect\endlink, or zero rectangle if not found
	 */
	wyRect getFrameRect(const char* frameName);

	/**
	 * Get all frame rects in a zwoptex
	 *
	 * @param zwoptexName name of zwoptex
	 * @param count it returns the count of rect
	 * @return rect list pointer, caller should release it
	 */
	wyRect* getFrameRects(const char* zwoptexName, size_t* count);

	/**
	 * Get a zwoptex frame by name
	 *
	 * @param frameName name of frame
	 * @return \link wyZwoptexFrame wyZwoptexFrame\endlink, or NULL if not found
	 */
	wyZwoptexFrame* getZwoptexFrame(const char* frameName);

	/**
	 * Get a zwoptex frame by name
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @return \link wyZwoptexFrame wyZwoptexFrame\endlink, or NULL if not found
	 */
	wyZwoptexFrame* getZwoptexFrame(const char* zwoptexName, const char* frameName);

	/**
	 * Get a sprite frame by name
	 *
	 * @param frameName name of frame
	 * @return \link wySpriteFrame wySpriteFrame\endlink, or NULL if not found
	 */
	wySpriteFrame* getSpriteFrame(const char* frameName);

	/**
	 * Get a sprite frame by name
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @return \link wySpriteFrame wySpriteFrame\endlink, or NULL if not found
	 */
	wySpriteFrame* getSpriteFrame(const char* zwoptexName, const char* frameName);

	/**
	 * Create a \link wySprite wySprite\endlink from a frame
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @return tex \link wyTexture2D wyTexture2D\endlink. It can be NULL and NULL means using
	 * 		zwoptex texture
	 * @return \link wySprite wySprite\endlink, or NULL if frame is not found
	 */
	wySprite* makeSprite(const char* zwoptexName, const char* frameName, wyTexture2D* tex = NULL);

	/**
	 * Create a \link wySprite wySprite\endlink. This method doesn't require zwoptex name so it
	 * will search all zwoptex. You can use it if you already know there is no duplicate frame
	 * name
	 *
	 * @param frameName name of frame
	 * @return \link wySprite wySprite\endlink, or NULL if frame is not found
	 */
	wySprite* makeSprite(const char* frameName);

	/**
	 * Create a \link wyButton wyButton\endlink from a frame
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @param ts target selector of this button
	 * @return tex \link wyTexture2D wyTexture2D\endlink. It can be NULL and NULL means using
	 * 		zwoptex texture
	 * @return \link wyButton wyButton\endlink, or NULL if frame is not found
	 */
	wyButton* makeButton(const char* zwoptexName, const char* frameName, wyTargetSelector* ts, wyTexture2D* tex = NULL);

	/**
	 * Create a \link wyButton wyButton\endlink. This method doesn't require zwoptex name so it
	 * will search all zwoptex. You can use it if you already know there is no duplicate frame
	 * name
	 *
	 * @param frameName name of frame
	 * @param ts target selector of this button
	 * @return \link wyButton wyButton\endlink, or NULL if frame is not found
	 */
	wyButton* makeButton(const char* frameName, wyTargetSelector* ts);

	/**
	 * Create a \link wySpriteEx wySpriteEx\endlink object from a frame
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @param tex \link wyTexture2D wyTexture2D\endlink, it can be NULL and NULL means using
	 * 		zwoptex texture
	 * @return \link wySpriteEx wySpriteEx\endlink, or NULL if frame is not found
	 */
	wySpriteEx* makeSpriteEx(const char* zwoptexName, const char* frameName, wyTexture2D* tex = NULL);

	/**
	 * Create a \link wySpriteEx wySpriteEx\endlink. This method doesn't require zwoptex name so it
	 * will search all zwoptex. You can use it if you already know there is no duplicate frame
	 * name
	 *
	 * @param frameName name of frame
	 * @return \link wySpriteEx wySpriteEx\endlink, or NULL if frame is not found
	 */
	wySpriteEx* makeSpriteEx(const char* frameName);
};

#endif // __wyZwoptexManager_h__
