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
#ifndef __wyAFCClipMapping_h__
#define __wyAFCClipMapping_h__

#include "wyObject.h"
#include "wyTypes.h"

class wySpriteBatchNode;
class wyTexture2D;

/**
 * @typedef wyAFCClipMappingRuleType
 *
 * \if English
 * Definition of all clip mapping rule supported by WiEngine AFC feature
 * \else
 * AFC动画支持的分片映射类型
 * \endif
 */
typedef enum {
	/**
	 * \if English
	 * map a clip to another clip which is in same file data
	 * \else
	 * 映射一个分片到相同文件数据中的另外一个分片
	 * \endif
	 */
	AFC_CMR_INTERNAL_CLIP,

	/**
	 * \if English
	 * map a clip to another clip which is not in same file data
	 * \else
	 * 映射一个分片到一个保存在其它文件数据中的分片
	 * \endif
	 */
	AFC_CMR_EXTERNAL_CLIP,

	/**
	 * \if English
	 * map a clip to an atlas sprite
	 * \else
	 * 映射一个分片到某个图片集贴图上
	 * \endif
	 */
	AFC_CMR_EXTERNAL_ATLAS
} wyAFCClipMappingRuleType;

/**
 * @struct wyAFCClipMappingRule
 *
 * \if English
 * mapping rule info structure
 * \else
 * 保存一条分片映射规则, 规则的映射方式分为多种类型:
 * \li 内部映射: 表示映射到同一个文件数据中的分片
 * \li 外部映射: 表示映射到外部文件数据中的分片
 * \li 图片集映射: 表示映射到外部的一个图片集贴图上
 * \endif
 */
typedef struct WIENGINE_API wyAFCClipMappingRule {
	/**
	 * \if English
	 * rule type
	 * \else
	 * 映射类型
	 * \endif
	 */
	wyAFCClipMappingRuleType type;

	/**
	 * \if English
	 * index of clip which need to be mapped
	 * \else
	 * 被映射的分片索引
	 * \endif
	 */
	int sourceClipIndex;

	union {
		/**
		 * \if English
		 * icr means internal clip rule
		 * \else
		 * 内部映射需要的信息
		 * \endif
		 */
		struct {
			/**
			 * \if English
			 * dest clip index
			 * \else
			 * 目标分片索引
			 * \endif
			 */
			int destClipIndex;
		} icr;

		/**
		 * \if English
		 * ecr means external clip rule
		 * \else
		 * 外部映射需要的信息
		 * \endif
		 */
		struct {
			/**
			 * \if English
			 * afc file data id
			 * \else
			 * external file data id
			 * \endif
			 */
			int dataId;

			/**
			 * \if English
			 * dest clip index in that file data
			 * \else
			 * 目标分片索引
			 * \endif
			 */
			int destClipIndex;

			/**
			 * \if English
			 * the atlas sheet where the dest clip resides in
			 * \else
			 * 目标分片所在的图片集
			 * \endif
			 */
			wySpriteBatchNode* sheet;
		} ecr;

		/**
		 * \if English
		 * ear means external atlas rule
		 * \else
		 * 外部图片集映射需要的信息
		 * \endif
		 */
		struct {
			/**
			 * \if English
			 * the atlas sheet for texture
			 * \else
			 * 外部图片集
			 * \endif
			 */
			wySpriteBatchNode* sheet;

			/**
			 * \if English
			 * texture rect
			 * \else
			 * 贴图在图片集中的矩形
			 * \endif
			 */
			wyRect texRect;

			/**
			 * \if English
			 * clip center position
			 * \else
			 * 分片中心相对于帧的位置
			 * \endif
			 */
			wyPoint pos;

			/**
			 * \if English
			 * is image flipped in x axis
			 * \else
			 * 是否翻转x轴
			 * \endif
			 */
			bool flipX;

			/**
			 * \if English
			 * rotation degree of image, positive value is clockwise
			 * \else
			 * 图片的旋转角度, 正值为顺时针
			 * \endif
			 */
			float rotation;
		} ear;
	};
} wyAFCClipMappingRule;

/**
 * @class wyAFCClipMapping
 *
 * \if English
 * Clip mapping defines a set of rules of replacing a clip to another clip. Then
 * you can use clip mapping to change animation easily and dynamically.
 * \else
 * 分片映射的含义是把一个分片替换成其它分片, 这样可以实现所谓的换装功能.
 * \endif
 */
class WIENGINE_API wyAFCClipMapping : public wyObject {
private:
	/**
	 * \if English
	 * tag for this mapping rule set
	 * \else
	 * 这套映射规则的tag
	 * \endif
	 */
	int m_tag;

	/**
	 * \if English
	 * how many mapping rules in buffer
	 * \else
	 * 这个映射总共包含了多少规则
	 * \endif
	 */
	int m_count;

	/**
	 * \if English
	 * capacity of buffer
	 * \else
	 * 缓冲区的容量
	 * \endif
	 */
	int m_capacity;

	/**
	 * \if English
	 * the clip mapping rules
	 * \else
	 * 映射规则缓冲区
	 * \endif
	 */
	wyAFCClipMappingRule* m_rules;

	/**
	 * \if English
	 * indices buffer of source clips
	 * \else
	 * 被映射的分片索引
	 * \endif
	 */
	int* m_sourceClipIndices;

private:
	/**
	 * ensure buffer capacity is ok
	 */
	void ensureCapacity();

protected:
	wyAFCClipMapping(int tag);

	/**
	 * \if English
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @param data raw data of AuroraGT module mapping file
	 * @param length byte length of \c data
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param tag 该映射规则对象的tag
	 * @param data AuroraGT分片映射文件的数据
	 * @param length \c data中的字节数
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \endif
	 */
	static wyAFCClipMapping* makeAurora(int tag, const char* data, size_t length);

public:
	virtual ~wyAFCClipMapping();

	/**
	 * \if English
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param tag 该映射规则对象的tag
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \endif
	 */
	static wyAFCClipMapping* make(int tag);

	/**
	 * \if English
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @param ammId resource id of aurora module mapping file
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param tag 该映射规则对象的tag
	 * @param ammId AuroraGT导出的module mapping文件的资源id
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \endif
	 */
	static wyAFCClipMapping* makeAurora(int tag, int ammId);

	/**
	 * \if English
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @param ammPath path of aurora module mapping file
	 * @param isFile true means \c ammPath is an absolute path in file system, or false means
	 * 		\c ammPath is a relative path under assets
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param tag 该映射规则对象的tag
	 * @param ammPath AuroraGT导出的module mapping文件的路径
	 * @param isFile true表示\c ammPath是一个文件系统上的绝对路径, false表示\c ammPath是相对于assets的相对路径
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \endif
	 */
	static wyAFCClipMapping* makeAurora(int tag, const char* ammPath, bool isFile = false);

	/**
	 * \if English
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @param mfsName memory file name of aurora module mapping file
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param tag 该映射规则对象的tag
	 * @param mfsName AuroraGT导出的module mapping的内存文件名
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \endif
	 */
	static wyAFCClipMapping* makeMemoryAurora(int tag, const char* mfsName);

	/**
	 * \if English
	 * Map a clip to another clip. Source and dest clip are all in same sheet
	 *
	 * @param fromClipIndex source clip index
	 * @param toClipIndex dest clip index
	 * \else
	 * 映射分片到另一个分片, 两个分片必须是属于同一个图片集的
	 *
	 * @param fromClipIndex 被映射的分片索引
	 * @param toClipIndex 映射到的分片索引
	 * \endif
	 */
	void mapClip(int fromClipIndex, int toClipIndex);

	/**
	 * \if English
	 * Map a clip to another clip. Source and dest clip are all in different file data
	 *
	 * @param fromClipIndex source clip index
	 * @param externalFileDataId data id of dest clip file data
	 * @param toClipIndex dest clip index
	 * \else
	 * 映射分片到另一个分片, 两个分片不属于同一个文件数据
	 *
	 * @param fromClipIndex 被映射的分片索引
	 * @param externalFileDataId 包含目标分片的文件数据id
	 * @param toClipIndex 映射到的分片索引
	 * \endif
	 */
	void mapClip(int fromClipIndex, int externalFileDataId, int toClipIndex);

	/**
	 * \if English
	 * Map a clip to external atlas texture
	 *
	 * @param fromClipIndex source clip index
	 * @param tex external texture
	 * @param pos clip center position, default is zero
	 * @param texRect texture rect in atlas, default is zero which means use whole texture
	 * @param flipX flip clip in x axis or not
	 * @param rotation is clip rotated, positive value means clockwise
	 * \else
	 * 映射一个分片到外部的图片集上
	 *
	 * @param fromClipIndex 被映射的分片索引
	 * @param tex 图片集的贴图对象
	 * @param pos 分片中心位置, 缺省是0
	 * @param texRect 图片集中的贴图矩形, 缺省是全0, 表示映射到整个贴图范围内
	 * @param flipX 是否让分片在x轴翻转
	 * @param rotation 分片是否有旋转, 正值为顺时针
	 * \endif
	 */
	void mapClip(int fromClipIndex, wyTexture2D* tex, wyPoint pos = wypZero, wyRect texRect = wyrZero, bool flipX = false, float rotation = 0);

	/**
	 * \if English
	 * Get tag
	 *
	 * @return tag
	 * \else
	 * 得到tag
	 *
	 * @return 标签
	 * \endif
	 */
	int getTag() { return m_tag; }

	/**
	 * \if English
	 * Search mapping rule set, and return a matched rule if found
	 *
	 * @param sourceClipIndex index of clip
	 * @return \link wyAFCClipMappingRule wyAFCClipMappingRule\endlink, or NULL if not found
	 * \else
	 * 根据源分片索引搜索是否存在匹配的映射规则
	 *
	 * @param sourceClipIndex 源分片索引
	 * @return \link wyAFCClipMappingRule wyAFCClipMappingRule\endlink, 如果没有找到, 返回NULL
	 * \endif
	 */
	wyAFCClipMappingRule* findRule(int sourceClipIndex);
};

#endif // __wyAFCClipMapping_h__
