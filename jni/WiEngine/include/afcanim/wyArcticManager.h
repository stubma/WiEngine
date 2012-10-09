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
 * \if English
 * Manager of ASprite file
 * \else
 * ASprite文件数据的管理类
 * \endif
 */
class WIENGINE_API wyArcticManager : public wyObject {
private:
	/**
	 * \if English
	 * sprite file data list
	 * \else
	 * 动画数据列表
	 * \endif
	 */
	wyArray* m_arcticFileDataList;

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

	wyArcticFileData* getArcticFileData(int dataId);
	wyArcticFileData* getArcticFileDataWithResId(int asResId);
	wyArcticFileData* getArcticFileDataWithName(const char* asPath);

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
	 * @param afd \link wyArcticFileData wyArcticFileData\endlink
	 * @param arcticFrame \link wyArcticFrame wyArcticFrame\endlink
	 * @param afcFrame \link wyAFCFrame wyAFCFrame\endlink
	 * @param offsetX x offset, only used for hyper frame
	 * @param offsetY y offset, only used for hyper frame
	 * @param mapping clip mapping rules, can be NULL
	 * \else
	 * 解析所有的帧内分片, 这个方法可能递归因为分片可能引用其它帧
	 *
	 * @param afd \link wyArcticFileData wyArcticFileData\endlink
	 * @param arcticFrame \link wyArcticFrame wyArcticFrame\endlink
	 * @param afcFrame \link wyAFCFrame wyAFCFrame\endlink
	 * @param offsetX x偏移量, 仅对hyper frame有意义
	 * @param offsetY y偏移量, 仅对hyper frame有意义
	 * @param mapping 分片映射规则, 可能为NULL
	 * \endif
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
	 * \if English
	 * Load ASprite file and returns \link wyArcticFileData wyArcticFileData\endlink object.
	 * If this resource is already loaded, returns it directly.
	 *
	 * @param asResId resource id of ASprite file
	 * @return \link wyArcticFileData wyArcticFileData\endlink
	 * \else
	 * 解析一个ASprite文件，返回文件数据对象. 如果这个ASprite文件已经被载入过, 则会直接返回
	 * 解析过的数据对象
	 *
	 * @param asResId ASprite文件的资源id
	 * @return \link wyArcticFileData wyArcticFileData\endlink
	 * \endif
	 */
	wyArcticFileData* load(int asResId);

	/**
	 * \if English
	 * Load ASprite from a path. If already loaded, returns it directly.
	 *
	 * @param asPath path of ASprite file
	 * @param isFile true means \c asPath is an absolute path in file system,
	 * 		false means \c asPath is relative path under assets
	 * @return \link wyArcticFileData wyArcticFileData\endlink
	 * \else
	 * 解析一个ASprite文件，返回文件数据对象. 如果这个ASprite文件已经被载入过, 则会直接返回
	 * 解析过的数据对象
	 *
	 * @param asPath ASprite文件的路径
	 * @param isFile true表示\c asPath是一个文件系统的绝对路径, false表示\c asPath是一个assets
	 * 		下的相对路径
	 * @return \link wyArcticFileData wyArcticFileData\endlink
	 * \endif
	 */
	wyArcticFileData* load(const char* asPath, bool isFile = false);

	/**
	 * \if English
	 * Load ASprite from memory file. If already loaded, returns it directly
	 *
	 * @param mfsName name of memory file
	 * @return \link wyArcticFileData wyArcticFileData\endlink
	 * \else
	 * 解析一个ASprite内存文件，返回文件数据对象. 如果这个ASprite文件已经被载入过, 则会直接返回
	 * 解析过的数据对象
	 *
	 * @param mfsName 内存文件名称
	 * @return \link wyArcticFileData wyArcticFileData\endlink
	 * \endif
	 */
	wyArcticFileData* loadMemory(const char* mfsName);

	/**
	 * \if English
	 * Get \link wyAFCAnimation wyAFCAnimation\endlink data at specified index
	 *
	 * @param afd \link wyArcticFileData wyArcticFileData\endlink
	 * @param animIndex animation index
	 * @param mapping clip mapping rules, can be NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 * \else
	 * 在动画数据列表中根据索引得到某个动画数据对象
	 *
	 * @param afd \link wyArcticFileData wyArcticFileData\endlink
	 * @param animIndex 索引
	 * @param mapping 分片映射规则, 可以为NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 * \endif
	 */
	wyAFCAnimation* getAnimationData(wyArcticFileData* afd, int animIndex, wyAFCClipMapping* mapping);

	/**
	 * \if English
	 * release all animation file data
	 * \else
	 * 释放所有动画数据
	 * \endif
	 */
	void releaseAllAnimationFileData();
};

#endif // __wyArcticManager_h__
