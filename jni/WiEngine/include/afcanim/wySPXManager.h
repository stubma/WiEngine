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
#ifndef __wySPXManager_h__
#define __wySPXManager_h__

#include "wyObject.h"
#include "wyArray.h"
#include "wySPXFileData.h"
#include "wyAFCAnimation.h"
#include "wyAFCClipMapping.h"

/**
 * @class wySPXManager
 *
 * Manager of SpriteX file
 */
class WIENGINE_API wySPXManager : public wyObject {
private:
	/**
	 * sprite file data list
	 */
	wyArray* m_spxFileDataList;

	/**
	 * scale of current file data
	 */
	float m_resScale;

private:
	static bool releaseData(wyArray* arr, void* ptr, int index, void* data);

	wySPXFileData* getSPXFileData(int dataId);
	wySPXFileData* getSPXFileDataWithResId(int spxResId);
	wySPXFileData* getSPXFileDataWithName(const char* spxPath);

	/**
	 * resolve original value
	 *
	 * @param v original value in sprite file
	 * @return value scaled
	 */
	float resolve(short v);

	/**
	 * Resolve a tile info
	 *
	 * @param spxTile tile data of SpriteX
	 * @param spxFrameTile frame tile data of SpriteX
	 * @param afcClip clip of SpriteX
	 * @param index clip index
	 */
	void parseTile(wySPXTile* spxTile, wySPXFrameTile* spxFrameTile, wyAFCClip* afcClip, int index);

protected:
	wySPXManager();

public:
	virtual ~wySPXManager();
	static wySPXManager* getInstance();

	/**
	 * Load SpriteX file and returns \link wySPXFileData wySPXFileData\endlink object.
	 * If this resource is already loaded, returns it directly.
	 *
	 * @param spxResId resource id of SpriteX file
	 * @return \link wySPXFileData wySPXFileData\endlink
	 */
	wySPXFileData* load(int spxResId);

	/**
	 * Load SpriteX from a path. If already loaded, returns it directly.
	 *
	 * @param spxPath path of SpriteX file
	 * @param isFile true means \c spxPath is an absolute path in file system,
	 * 		false means \c spxPath is relative path under assets
	 * @return \link wySPXFileData wySPXFileData\endlink
	 */
	wySPXFileData* load(const char* spxPath, bool isFile = false);

	/**
	 * Load SpriteX from memory file. If already loaded, returns it directly
	 *
	 * @param mfsName name of memory file
	 * @return \link wySPXFileData wySPXFileData\endlink
	 */
	wySPXFileData* loadMemory(const char* mfsName);

	/**
	 * Get \link wyAFCAnimation wyAFCAnimation\endlink data at specified index
	 *
	 * @param spx \link wySPXFileData wySPXFileData\endlink
	 * @param animIndex animation index
	 * @param mapping clip mapping rules, can be NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 */
	wyAFCAnimation* getAnimationData(wySPXFileData* spx, int animIndex, wyAFCClipMapping* mapping);

	/**
	 * release all animation file data
	 */
	void releaseAllAnimationFileData();
};

#endif // __wySPXManager_h__
