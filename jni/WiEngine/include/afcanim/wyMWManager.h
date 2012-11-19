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
#ifndef __wyMWManager_h__
#define __wyMWManager_h__

#include "wyObject.h"
#include "wyArray.h"
#include "wyTypes.h"
#include "wyMWFileData.h"
#include "wyAFCAnimation.h"
#include "wyAFCClipMapping.h"

/**
 * @typedef wyMWClipType
 *
 * type constant of motion welder clip
 */
typedef enum {
	ClipType_ImageNormal = 0x0000,
	ClipType_ImageFlipX = 0x0002,
	ClipType_ImageFlipY = 0x0004,
	ClipType_ImageFlipXY = 0x0006,
	ClipType_Ecllipse = 0x0001,
	ClipType_Ecllipse_Filled = 0x0003,
	ClipType_Line = 0x0005,
	ClipType_Rect = 0x0007,
	ClipType_Rect_Filled = 0x0009,
	ClipType_RoundRect = 0x000b,
	ClipType_RoundRect_Filled = 0x000d,
	ClipType_CollisionRect = 0x000f
} wyMWClipType;

/**
 * @class wyMWManager
 *
 * \par
 * Data pool of motion welder file data. It parses *.anu files and cache them.
 * This class is referenced by \link wyDirector wyDirector\endlink and it will be
 * destroyed by \link wyDirector wyDirector\endlink when game ends.
 *
 * \par
 * One anu file can contain more than one animation and one animation consists of
 * one or more frames. One Frame consists of one or more clips. So motion welder is
 * a three layer structure, that is the architecture we called AFC (Animation-Frame-Clip).
 */
class WIENGINE_API wyMWManager : public wyObject {
private:
	/**
	 * animation file data list
	 */
	wyArray* m_animationFileDataList;

	/**
	 * scale of current file data
	 */
	float m_resScale;

private:
	static bool releaseData(wyArray* arr, void* ptr, int index, void* data);

	/**
	 * Parse a motion welder clip and save info to afc clip
	 *
	 * @param animationFileData \link wyMWFileData wyMWFileData\endlink
	 * @param clipAdditionalDataIndex index of clip
	 * @param type clip type
	 * @param clipPosX x offset of clip
	 * @param clipPosY y offset of clip
	 * @param afcClip output afc clip
	 */
	bool parseClip(wyMWFileData* animationFileData, int clipAdditionalDataIndex, wyMWClipType type, float clipPosX, float clipPosY, wyAFCClip* afcClip);

protected:
	wyMWManager();

	/**
	 * resolve original value
	 *
	 * @param v original value in anu file
	 * @return value scaled
	 */
	float resolve(short v);

public:
	virtual ~wyMWManager();

	/**
	 * Get single instance
	 *
	 * @return shared \link wyMWManager wyMWManager\endlink instance
	 */
	static wyMWManager* getInstance();

	/**
	 * release all animation file data
	 */
	void releaseAllAnimationFileData();

	/**
	 * Get list of all animation file data
	 *
	 * @return \link wyArray wyArray\endlink
	 */
	wyArray* getAnimationFileDataList() { return m_animationFileDataList; }

	/**
	 * Load motion welder file data from resource id
	 *
	 * @param resId resource id of anu file
	 * @return \link wyMWFileData wyMWFileData\endlink
	 */
	wyMWFileData* load(int resId);

	/**
	 * Load motion welder file data from path
	 *
	 * @param path file path
	 * @param isFile true means \c path is an absolute path in file system, false means
	 * 		\c path is relative path under assets
	 * @return \link wyMWFileData wyMWFileData\endlink
	 */
	wyMWFileData* load(const char* path, bool isFile = false);

	/**
	 * Load motion welder file data from memory file
	 *
	 * @return mfsName name of anu memory file
	 * @return \link wyMWFileData wyMWFileData\endlink
	 */
	wyMWFileData* loadMemory(const char* mfsName);

	/**
	 * Get \link wyMWFileData wyMWFileData\endlink from a path. If this file data is
	 * already loaded, then returns it directly. If not, returns NULL.
	 *
	 * @param path anu file path in file system or assets
	 * @return \link wyMWFileData wyMWFileData\endlink pointer or NULL if not found
	 */
	wyMWFileData* getAnimationFileDataWithPath(const char* path);

	/**
	 * Get \link wyMWFileData wyMWFileData\endlink from a resource id
	 *
	 * @param resId resource id of anu file
	 * @return \link wyMWFileData wyMWFileData\endlink pointer or NULL if not found
	 */
	wyMWFileData* getAnimationFileDataWithResId(int resId);

	/**
	 * Get \link wyMWFileData wyMWFileData\endlink from a memory file name
	 *
	 * @param mfsName memory file name
	 * @return \link wyMWFileData wyMWFileData\endlink pointer or NULL if not found
	 */
	wyMWFileData* getAnimationFileDataWithName(const char* mfsName);

	/**
	 * Get animation file data by data id. A data id may be resource id, or
	 * hash of path, name, etc.
	 *
	 * @param dataId data id of motion welder file data
	 * @return \link wyMWFileData wyMWFileData\endlink
	 */
	wyMWFileData* getAnimationFileData(int dataId);

	/**
	 * Get \link wyAFCAnimation wyAFCAnimation\endlink data at specified index
	 *
	 * @param fileData \link wyMWFileData wyMWFileData\endlink
	 * @param animIndex animation index
	 * @param mapping clip mapping rules, can be NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 */
	wyAFCAnimation* getAnimationData(wyMWFileData* fileData, int animIndex, wyAFCClipMapping* mapping);
};

#endif // __wyMWManager_h__
