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
 * \if English
 * Manager of BSprite file
 * \else
 * BSprite文件数据的管理类
 * \endif
 */
class WIENGINE_API wyAuroraManager : public wyObject {
private:
	/**
	 * \if English
	 * sprite file data list
	 * \else
	 * 动画数据列表
	 * \endif
	 */
	wyArray* m_auroraFileDataList;

	/**
	 * \if English
	 * scale of current file data
	 * \else
	 * 当前动画文件的缩放比例
	 * \endif
	 */
	float m_resScale;

private:
	static bool releaseData(wyArray* arr, void* ptr, int index, void* data);

	wyAuroraFileData* getAuroraFileData(int dataId);
	wyAuroraFileData* getAuroraFileDataWithResId(int asResId);
	wyAuroraFileData* getAuroraFileDataWithName(const char* asPath);

	/**
	 * \if English
	 * resolve original value
	 *
	 * @param v original value in sprite file
	 * @return value scaled
	 * \else
	 * 解析大小
	 *
	 * @param v 从sprite文件中解析出来的原始值
	 * @return 解析后的大小
	 * \endif
	 */
	float resolve(short v);
	
	/**
	 * \if English
	 * parse all modules in a frame, it may recursively called because frame module 
	 * may be a reference to other frame
	 * 
	 * @param afd \link wyAuroraFileData wyAuroraFileData\endlink
	 * @param auroraFrame \link wyAuroraFrame wyAuroraFrame\endlink
	 * @param afcFrame \link wyAFCFrame wyAFCFrame\endlink
	 * @param offsetX x offset, only used for hyper frame
	 * @param offsetY y offset, only used for hyper frame
	 * @param mapping clip mapping rules, can be NULL
	 * \else
	 * 解析所有的帧内分片, 这个方法可能递归因为分片可能引用其它帧
	 *
	 * @param afd \link wyAuroraFileData wyAuroraFileData\endlink
	 * @param auroraFrame \link wyAuroraFrame wyAuroraFrame\endlink
	 * @param afcFrame \link wyAFCFrame wyAFCFrame\endlink
	 * @param offsetX x偏移量, 仅对hyper frame有意义
	 * @param offsetY y偏移量, 仅对hyper frame有意义
	 * @param mapping 分片映射规则, 可能为NULL
	 * \endif
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
	 * \if English
	 * Load BSprite file and returns \link wyAuroraFileData wyAuroraFileData\endlink object.
	 * If this resource is already loaded, returns it directly.
	 *
	 * @param asResId resource id of BSprite file
	 * @return \link wyAuroraFileData wyAuroraFileData\endlink
	 * \else
	 * 解析一个BSprite文件，返回文件数据对象. 如果这个BSprite文件已经被载入过, 则会直接返回
	 * 解析过的数据对象
	 *
	 * @param asResId BSprite文件的资源id
	 * @return \link wyAuroraFileData wyAuroraFileData\endlink
	 * \endif
	 */
	wyAuroraFileData* load(int asResId);

	/**
	 * \if English
	 * Load BSprite from a path. If already loaded, returns it directly.
	 *
	 * @param asPath path of BSprite file
	 * @param isFile true means \c asPath is an absolute path in file system,
	 * 		false means \c asPath is relative path under assets
	 * @return \link wyAuroraFileData wyAuroraFileData\endlink
	 * \else
	 * 解析一个BSprite文件，返回文件数据对象. 如果这个BSprite文件已经被载入过, 则会直接返回
	 * 解析过的数据对象
	 *
	 * @param asPath BSprite文件的路径
	 * @param isFile true表示\c asPath是一个文件系统的绝对路径, false表示\c asPath是一个assets
	 * 		下的相对路径
	 * @return \link wyAuroraFileData wyAuroraFileData\endlink
	 * \endif
	 */
	wyAuroraFileData* load(const char* asPath, bool isFile = false);

	/**
	 * \if English
	 * Load BSprite from memory file. If already loaded, returns it directly
	 *
	 * @param mfsName name of memory file
	 * @return \link wyAuroraFileData wyAuroraFileData\endlink
	 * \else
	 * 解析一个BSprite内存文件，返回文件数据对象. 如果这个BSprite文件已经被载入过, 则会直接返回
	 * 解析过的数据对象
	 *
	 * @param mfsName 内存文件名称
	 * @return \link wyAuroraFileData wyAuroraFileData\endlink
	 * \endif
	 */
	wyAuroraFileData* loadMemory(const char* mfsName);

	/**
	 * \if English
	 * Get \link wyAFCAnimation wyAFCAnimation\endlink data at specified index
	 *
	 * @param afd \link wyAuroraFileData wyAuroraFileData\endlink
	 * @param animIndex animation index
	 * @param mapping clip mapping rules, can be NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 * \else
	 * 在动画数据列表中根据索引得到某个动画数据对象
	 *
	 * @param afd \link wyAuroraFileData wyAuroraFileData\endlink
	 * @param animIndex 索引
	 * @param mapping 分片映射规则, 可以为NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 * \endif
	 */
	wyAFCAnimation* getAnimationData(wyAuroraFileData* afd, int animIndex, wyAFCClipMapping* mapping);

	/**
	 * \if English
	 * release all animation file data
	 * \else
	 * 释放所有动画数据
	 * \endif
	 */
	void releaseAllAnimationFileData();
};

#endif // __wyAuroraManager_h__
