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
#ifndef __wyAuroraManager_h__
#define __wyAuroraManager_h__

#include "wyObject.h"
#include "wyArray.h"
#include "wyAuroraFileData.h"
#include "wyAFCAnimation.h"
#include "wyAFCClipMapping.h"

/**
 * @class wyAuroraManager
 *
 * Manager of BSprite file
 */
class WIENGINE_API wyAuroraManager : public wyObject {
private:
	/**
	 * sprite file data list
	 */
	wyArray* m_auroraFileDataList;

	/**
	 * scale of current file data
	 */
	float m_resScale;

private:
	static bool releaseData(wyArray* arr, void* ptr, int index, void* data);

	wyAuroraFileData* getAuroraFileData(int dataId);
	wyAuroraFileData* getAuroraFileDataWithResId(int asResId);
	wyAuroraFileData* getAuroraFileDataWithName(const char* asPath);

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
	 * @param afd \link wyAuroraFileData wyAuroraFileData\endlink
	 * @param auroraFrame \link wyAuroraFrame wyAuroraFrame\endlink
	 * @param afcFrame \link wyAFCFrame wyAFCFrame\endlink
	 * @param offsetX x offset, only used for hyper frame
	 * @param offsetY y offset, only used for hyper frame
	 * @param mapping clip mapping rules, can be NULL
	 */
	void parseFrameModules(wyAuroraFileData* afd, wyAuroraFrame* auroraFrame, wyAFCFrame* afcFrame, int offsetX, int offsetY, wyAFCClipMapping* mapping);

	/**
	 * parse aurora module and save info into afc clip
	 *
	 * @param auroraModule \link wyAuroraModule wyAuroraModule\endlink
	 * @param auroraFrameModule \link wyAuroraFrameModule wyAuroraFrameModule\endlink
	 * @param afcClip \link wyAFCClip wyAFCClip\endlink
	 * @param index clip index
	 * @param offsetX x offset
	 * @param offsetY y offset
	 */
	void parseModule(wyAuroraModule* auroraModule, wyAuroraFrameModule* auroraFrameModule, wyAFCClip* afcClip, int index, int offsetX, int offsetY);

protected:
	wyAuroraManager();

public:
	virtual ~wyAuroraManager();
	static wyAuroraManager* getInstance();

	/**
	 * Load BSprite file and returns \link wyAuroraFileData wyAuroraFileData\endlink object.
	 * If this resource is already loaded, returns it directly.
	 *
	 * @param asResId resource id of BSprite file
	 * @return \link wyAuroraFileData wyAuroraFileData\endlink
	 */
	wyAuroraFileData* load(int asResId);

	/**
	 * Load BSprite from a path. If already loaded, returns it directly.
	 *
	 * @param asPath path of BSprite file
	 * @param isFile true means \c asPath is an absolute path in file system,
	 * 		false means \c asPath is relative path under assets
	 * @return \link wyAuroraFileData wyAuroraFileData\endlink
	 */
	wyAuroraFileData* load(const char* asPath, bool isFile = false);

	/**
	 * Load BSprite from memory file. If already loaded, returns it directly
	 *
	 * @param mfsName name of memory file
	 * @return \link wyAuroraFileData wyAuroraFileData\endlink
	 */
	wyAuroraFileData* loadMemory(const char* mfsName);

	/**
	 * Get \link wyAFCAnimation wyAFCAnimation\endlink data at specified index
	 *
	 * @param afd \link wyAuroraFileData wyAuroraFileData\endlink
	 * @param animIndex animation index
	 * @param mapping clip mapping rules, can be NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 */
	wyAFCAnimation* getAnimationData(wyAuroraFileData* afd, int animIndex, wyAFCClipMapping* mapping);

	/**
	 * release all animation file data
	 */
	void releaseAllAnimationFileData();
};

#endif // __wyAuroraManager_h__
