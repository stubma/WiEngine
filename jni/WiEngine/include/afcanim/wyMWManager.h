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
 * \if English
 * type constant of motion welder clip
 * \else
 * motion welder分片的类型
 * \endif
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
 * \if English
 * \par
 * Data pool of motion welder file data. It parses *.anu files and cache them.
 * This class is referenced by \link wyDirector wyDirector\endlink and it will be
 * destroyed by \link wyDirector wyDirector\endlink when game ends.
 *
 * \par
 * One anu file can contain more than one animation and one animation consists of
 * one or more frames. One Frame consists of one or more clips. So motion welder is
 * a three layer structure, that is the architecture we called AFC (Animation-Frame-Clip).
 * \else
 * \par
 * anu文件数据池, 这个类负责解析Motion Welder的文件, 缓存其定义的动画数据.
 * 一个Motion Welder文件中可能定义多个动画, 而每个动画可能有多个帧, 而每个帧
 * 可能有多个Clip, 因此可以理解Motion Welder文件定义的内容是一个三层结构.
 *
 * \par
 * Clip(分片)是Motion Welder灵活的地方, 它意味着一个帧可能由多个分片组成, 因此可以构成
 * 比较复杂的动画类型. 而且分片不一定是图片, 也可以是某种区域, 比如矩形, 圆角矩形, 线,
 * 点等, 这些类型的支持使得在播放Motion Welder动画的同时还可以获知某些位置信息, 添加附加
 * 效果.
 * \endif
 */
class WIENGINE_API wyMWManager : public wyObject {
private:
	/**
	 * \if English
	 * animation file data list
	 * \else
	 * 动画数据列表
	 * \endif
	 */
	wyArray* m_animationFileDataList;

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

	/**
	 * \if English
	 * Parse a motion welder clip and save info to afc clip
	 *
	 * @param animationFileData \link wyMWFileData wyMWFileData\endlink
	 * @param clipAdditionalDataIndex index of clip
	 * @param type clip type
	 * @param clipPosX x offset of clip
	 * @param clipPosY y offset of clip
	 * @param afcClip output afc clip
	 * \else
	 * 解析motion welder的分片, 把信息保存到afc的分片中
	 *
	 * @param animationFileData \link wyMWFileData wyMWFileData\endlink
	 * @param clipAdditionalDataIndex 分片索引
	 * @param type 分片类型
	 * @param clipPosX 分片x偏移
	 * @param clipPosY 分片y偏移
	 * @param afcClip afc分片对象
	 * \endif
	 */
	bool parseClip(wyMWFileData* animationFileData, int clipAdditionalDataIndex, wyMWClipType type, float clipPosX, float clipPosY, wyAFCClip* afcClip);

protected:
	wyMWManager();

	/**
	 * \if English
	 * resolve original value
	 *
	 * @param v original value in anu file
	 * @return value scaled
	 * \else
	 * 解析大小
	 *
	 * @param v 从anu文件中解析出来的原始值
	 * @return 解析后的大小
	 * \endif
	 */
	float resolve(short v);

public:
	virtual ~wyMWManager();

	/**
	 * \if English
	 * Get single instance
	 *
	 * @return shared \link wyMWManager wyMWManager\endlink instance
	 * \else
	 * 得到单一实例
	 *
	 * @return 共享的\link wyMWManager wyMWManager\endlink 实例
	 * \endif
	 */
	static wyMWManager* getInstance();

	/**
	 * \if English
	 * release all animation file data
	 * \else
	 * 释放所有动画数据
	 * \endif
	 */
	void releaseAllAnimationFileData();

	/**
	 * \if English
	 * Get list of all animation file data
	 *
	 * @return \link wyArray wyArray\endlink
	 * \else
	 * 得到动画数据列表
	 *
	 * @return \link wyArray wyArray\endlink
	 * \endif
	 */
	wyArray* getAnimationFileDataList() { return m_animationFileDataList; }

	/**
	 * \if English
	 * Load motion welder file data from resource id
	 *
	 * @param resId resource id of anu file
	 * @return \link wyMWFileData wyMWFileData\endlink
	 * \else
	 * 从某个资源文件中载入动画数据
	 *
	 * @param resId anu文件的资源id
	 * @return \link wyMWFileData wyMWFileData\endlink
	 * \endif
	 */
	wyMWFileData* load(int resId);

	/**
	 * \if English
	 * Load motion welder file data from path
	 *
	 * @param path file path
	 * @param isFile true means \c path is an absolute path in file system, false means
	 * 		\c path is relative path under assets
	 * @return \link wyMWFileData wyMWFileData\endlink
	 * \else
	 * 从某个文件中载入动画数据
	 *
	 * @param path 文件的路径
	 * @param isFile true表示path是一个文件系统路径，false表示path是assets目录下的路径
	 * @return \link wyMWFileData wyMWFileData\endlink
	 * \endif
	 */
	wyMWFileData* load(const char* path, bool isFile = false);

	/**
	 * \if English
	 * Load motion welder file data from memory file
	 *
	 * @return mfsName name of anu memory file
	 * @return \link wyMWFileData wyMWFileData\endlink
	 * \else
	 * 从内存文件中载入动画数据
	 *
	 * @param mfsName anu内存文件名称
	 * @return \link wyMWFileData wyMWFileData\endlink
	 * \endif
	 */
	wyMWFileData* loadMemory(const char* mfsName);

	/**
	 * \if English
	 * Get \link wyMWFileData wyMWFileData\endlink from a path. If this file data is
	 * already loaded, then returns it directly. If not, returns NULL.
	 *
	 * @param path anu file path in file system or assets
	 * @return \link wyMWFileData wyMWFileData\endlink pointer or NULL if not found
	 * \else
	 * 根据一个文件系统路径或者asset路径查找\link wyMWFileData wyMWFileData\endlink
	 *
	 * @param path 文件系统路径或者assets下的路径
	 * @return 找到的\link wyMWFileData wyMWFileData\endlink 结构指针，如果没找到，返回NULL
	 * \endif
	 */
	wyMWFileData* getAnimationFileDataWithPath(const char* path);

	/**
	 * \if English
	 * Get \link wyMWFileData wyMWFileData\endlink from a resource id
	 *
	 * @param resId resource id of anu file
	 * @return \link wyMWFileData wyMWFileData\endlink pointer or NULL if not found
	 * \else
	 * 根据一个资源id查找\link wyMWFileData wyMWFileData\endlink
	 *
	 * @param resId anu文件资源id
	 * @return 找到的\link wyMWFileData wyMWFileData\endlink 结构指针，如果没找到，返回NULL
	 * \endif
	 */
	wyMWFileData* getAnimationFileDataWithResId(int resId);

	/**
	 * \if English
	 * Get \link wyMWFileData wyMWFileData\endlink from a memory file name
	 *
	 * @param mfsName memory file name
	 * @return \link wyMWFileData wyMWFileData\endlink pointer or NULL if not found
	 * \else
	 * 根据一个内存文件名称查找\link wyMWFileData wyMWFileData\endlink
	 *
	 * @param mfsName 内存文件名称
	 * @return 找到的\link wyMWFileData wyMWFileData\endlink 结构指针，如果没找到，返回NULL
	 * \endif
	 */
	wyMWFileData* getAnimationFileDataWithName(const char* mfsName);

	/**
	 * \if English
	 * Get animation file data by data id. A data id may be resource id, or
	 * hash of path, name, etc.
	 *
	 * @param dataId data id of motion welder file data
	 * @return \link wyMWFileData wyMWFileData\endlink
	 * \else
	 * 通过数据id得到动画文件数据, 数据id可能是资源id, 或者路径, 名称等的哈希值
	 *
	 * @param dataId motion welder文件数据的id
	 * @return \link wyMWFileData wyMWFileData\endlink
	 * \endif
	 */
	wyMWFileData* getAnimationFileData(int dataId);

	/**
	 * \if English
	 * Get \link wyAFCAnimation wyAFCAnimation\endlink data at specified index
	 *
	 * @param fileData \link wyMWFileData wyMWFileData\endlink
	 * @param animIndex animation index
	 * @param mapping clip mapping rules, can be NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 * \else
	 * 在动画数据列表中根据索引得到某个动画数据对象
	 *
	 * @param fileData \link wyMWFileData wyMWFileData\endlink
	 * @param animIndex 索引
	 * @param mapping 分片映射规则, 可以为NULL
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 * \endif
	 */
	wyAFCAnimation* getAnimationData(wyMWFileData* fileData, int animIndex, wyAFCClipMapping* mapping);
};

#endif // __wyMWManager_h__
