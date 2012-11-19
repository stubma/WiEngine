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
#ifndef __wySPX3Manager_h__
#define __wySPX3Manager_h__

#include "wyObject.h"
#include "wyArray.h"
#include "wySPX3FileData.h"
#include "wyAFCAnimation.h"
#include "wyAFCClipMapping.h"

/**
 * @class wySPX3Manager
 *
 * Manager of SpriteX 2011 file
 */
class WIENGINE_API wySPX3Manager : public wyObject {
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

	wySPX3FileData* getSPX3FileData(int dataId);
	wySPX3FileData* getSPX3FileDataWithResId(int spxResId);
	wySPX3FileData* getSPX3FileDataWithName(const char* spxPath);

	/**
	 * resolve original value
	 *
	 * @param v original value in sprite file
	 * @return value scaled
	 */
	float resolve(short v);

protected:
	wySPX3Manager();

public:
	virtual ~wySPX3Manager();
	static wySPX3Manager* getInstance();

	/**
	 * Load SpriteX 2011 file and returns \link wySPX3FileData wySPX3FileData\endlink object.
	 * If this resource is already loaded, returns it directly.
	 *
	 * @param spxResId resource id of SpriteX 2011 file
	 * @return \link wySPX3FileData wySPX3FileData\endlink
	 */
	wySPX3FileData* load(int spxResId);

	/**
	 * Load SpriteX 2011 from a path. If already loaded, returns it directly.
	 *
	 * @param spxPath path of SpriteX 2011 file
	 * @param isFile true means \c spxPath is an absolute path in file system,
	 * 		false means \c spxPath is relative path under assets
	 * @return \link wySPX3FileData wySPX3FileData\endlink
	 */
	wySPX3FileData* load(const char* spxPath, bool isFile = false);

	/**
	 * Load SpriteX 2011 from memory file. If already loaded, returns it directly
	 *
	 * @param mfsName name of memory file
	 * @return \link wySPX3FileData wySPX3FileData\endlink
	 */
	wySPX3FileData* loadMemory(const char* mfsName);

	/**
	 * Get \link wyAFCAnimation wyAFCAnimation\endlink data at specified index
	 *
	 * @param spx \link wySPX3FileData wySPX3FileData\endlink
	 * @param animIndex animation index
	 * @param mapping clip mapping rules, can be NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 */
	wyAFCAnimation* getAnimationData(wySPX3FileData* spx, int animIndex, wyAFCClipMapping* mapping);

	/**
	 * release all animation file data
	 */
	void releaseAllAnimationFileData();
};

#endif // __wySPX3Manager_h__
