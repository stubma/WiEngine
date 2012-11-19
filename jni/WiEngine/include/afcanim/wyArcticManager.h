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
#ifndef __wyArcticManager_h__
#define __wyArcticManager_h__

#include "wyObject.h"
#include "wyArray.h"
#include "wyArcticFileData.h"
#include "wyAFCAnimation.h"
#include "wyAFCClipMapping.h"

/**
 * @class wyArcticManager
 *
 * Manager of ASprite file
 */
class WIENGINE_API wyArcticManager : public wyObject {
private:
	/**
	 * sprite file data list
	 */
	wyArray* m_arcticFileDataList;

	/**
	 * scale of current file data
	 */
	float m_resScale;

private:
	static bool releaseData(wyArray* arr, void* ptr, int index, void* data);

	wyArcticFileData* getArcticFileData(int dataId);
	wyArcticFileData* getArcticFileDataWithResId(int asResId);
	wyArcticFileData* getArcticFileDataWithName(const char* asPath);

	/**
	 * resolve original value
	 *
	 * @param v original value in sprite file
	 * @return value scaled
	 */
	float resolve(short v);

	/**
	 * parse all modules in a frame, it may recursively called because frame module 
	 * may be a reference to other frame
	 * 
	 * @param afd \link wyArcticFileData wyArcticFileData\endlink
	 * @param arcticFrame \link wyArcticFrame wyArcticFrame\endlink
	 * @param afcFrame \link wyAFCFrame wyAFCFrame\endlink
	 * @param offsetX x offset, only used for hyper frame
	 * @param offsetY y offset, only used for hyper frame
	 * @param mapping clip mapping rules, can be NULL
	 */
	void parseFrameModules(wyArcticFileData* afd, wyArcticFrame* arcticFrame, wyAFCFrame* afcFrame, int offsetX, int offsetY, wyAFCClipMapping* mapping);
	
	/**
	 * parse arctic module and save info into afc clip
	 *
	 * @param arcticModule \link wyArcticModule wyArcticModule\endlink
	 * @param arcticFrameModule \link wyArcticFrameModule wyArcticFrameModule\endlink
	 * @param afcClip \link wyAFCClip wyAFCClip\endlink
	 * @param index clip index, or -1 if no index available
	 * @param offsetX x offset
	 * @param offsetY y offset
	 */
	void parseModule(wyArcticModule* arcticModule, wyArcticFrameModule* arcticFrameModule, wyAFCClip* afcClip, int index, int offsetX, int offsetY);

protected:
	wyArcticManager();

public:
	virtual ~wyArcticManager();
	static wyArcticManager* getInstance();

	/**
	 * Load ASprite file and returns \link wyArcticFileData wyArcticFileData\endlink object.
	 * If this resource is already loaded, returns it directly.
	 *
	 * @param asResId resource id of ASprite file
	 * @return \link wyArcticFileData wyArcticFileData\endlink
	 */
	wyArcticFileData* load(int asResId);

	/**
	 * Load ASprite from a path. If already loaded, returns it directly.
	 *
	 * @param asPath path of ASprite file
	 * @param isFile true means \c asPath is an absolute path in file system,
	 * 		false means \c asPath is relative path under assets
	 * @return \link wyArcticFileData wyArcticFileData\endlink
	 */
	wyArcticFileData* load(const char* asPath, bool isFile = false);

	/**
	 * Load ASprite from memory file. If already loaded, returns it directly
	 *
	 * @param mfsName name of memory file
	 * @return \link wyArcticFileData wyArcticFileData\endlink
	 */
	wyArcticFileData* loadMemory(const char* mfsName);

	/**
	 * Get \link wyAFCAnimation wyAFCAnimation\endlink data at specified index
	 *
	 * @param afd \link wyArcticFileData wyArcticFileData\endlink
	 * @param animIndex animation index
	 * @param mapping clip mapping rules, can be NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 */
	wyAFCAnimation* getAnimationData(wyArcticFileData* afd, int animIndex, wyAFCClipMapping* mapping);

	/**
	 * release all animation file data
	 */
	void releaseAllAnimationFileData();
};

#endif // __wyArcticManager_h__
