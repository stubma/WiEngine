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
 * \if English
 * Manager of SpriteX 2011 file
 * \else
 * SpriteX 2011文件数据的管理类
 * \endif
 */
class WIENGINE_API wySPX3Manager : public wyObject {
private:
	/**
	 * \if English
	 * sprite file data list
	 * \else
	 * 动画数据列表
	 * \endif
	 */
	wyArray* m_spxFileDataList;

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

	wySPX3FileData* getSPX3FileData(int dataId);
	wySPX3FileData* getSPX3FileDataWithResId(int spxResId);
	wySPX3FileData* getSPX3FileDataWithName(const char* spxPath);

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

protected:
	wySPX3Manager();

public:
	virtual ~wySPX3Manager();
	static wySPX3Manager* getInstance();

	/**
	 * \if English
	 * Load SpriteX 2011 file and returns \link wySPX3FileData wySPX3FileData\endlink object.
	 * If this resource is already loaded, returns it directly.
	 *
	 * @param spxResId resource id of SpriteX 2011 file
	 * @return \link wySPX3FileData wySPX3FileData\endlink
	 * \else
	 * 解析一个SpriteX 2011文件，返回文件数据对象. 如果这个SpriteX 2011文件已经被载入过, 则会直接返回
	 * 解析过的数据对象
	 *
	 * @param spxResId SpriteX 2011文件的资源id
	 * @return \link wySPX3FileData wySPX3FileData\endlink
	 * \endif
	 */
	wySPX3FileData* load(int spxResId);

	/**
	 * \if English
	 * Load SpriteX 2011 from a path. If already loaded, returns it directly.
	 *
	 * @param spxPath path of SpriteX 2011 file
	 * @param isFile true means \c spxPath is an absolute path in file system,
	 * 		false means \c spxPath is relative path under assets
	 * @return \link wySPX3FileData wySPX3FileData\endlink
	 * \else
	 * 解析一个SpriteX 2011文件，返回文件数据对象. 如果这个SpriteX 2011文件已经被载入过, 则会直接返回
	 * 解析过的数据对象
	 *
	 * @param spxPath SpriteX 2011文件的路径
	 * @param isFile true表示\c spxPath是一个文件系统的绝对路径, false表示\c spxPath是一个assets
	 * 		下的相对路径
	 * @return \link wySPX3FileData wySPX3FileData\endlink
	 * \endif
	 */
	wySPX3FileData* load(const char* spxPath, bool isFile = false);

	/**
	 * \if English
	 * Load SpriteX 2011 from memory file. If already loaded, returns it directly
	 *
	 * @param mfsName name of memory file
	 * @return \link wySPX3FileData wySPX3FileData\endlink
	 * \else
	 * 解析一个SpriteX 2011内存文件，返回文件数据对象. 如果这个SpriteX 2011文件已经被载入过, 则会直接返回
	 * 解析过的数据对象
	 *
	 * @param mfsName 内存文件名称
	 * @return \link wySPX3FileData wySPX3FileData\endlink
	 * \endif
	 */
	wySPX3FileData* loadMemory(const char* mfsName);

	/**
	 * \if English
	 * Get \link wyAFCAnimation wyAFCAnimation\endlink data at specified index
	 *
	 * @param spx \link wySPX3FileData wySPX3FileData\endlink
	 * @param animIndex animation index
	 * @param mapping clip mapping rules, can be NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 * \else
	 * 在动画数据列表中根据索引得到某个动画数据对象
	 *
	 * @param spx \link wySPX3FileData wySPX3FileData\endlink
	 * @param animIndex 索引
	 * @param mapping 分片映射规则, 可以为NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 * \endif
	 */
	wyAFCAnimation* getAnimationData(wySPX3FileData* spx, int animIndex, wyAFCClipMapping* mapping);

	/**
	 * \if English
	 * release all animation file data
	 * \else
	 * 释放所有动画数据
	 * \endif
	 */
	void releaseAllAnimationFileData();
};

#endif // __wySPX3Manager_h__
