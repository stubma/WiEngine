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
#ifndef __wyAFCClip_h__
#define __wyAFCClip_h__

#include "wyObject.h"
#include "wyArray.h"
#include "wyTypes.h"
#include "wyAFCConstants.h"

class wySpriteBatchNode;

/**
 * @struct wyAFCClipData
 *
 * \if English
 * Additional data of clip
 * \else
 * 分片的相关数据定义
 * \endif
 */
typedef struct WIENGINE_API wyAFCClipData {
	/**
	 * \if English
	 * Clip center position in frame
	 * \else
	 * 分片的中心在帧中的位置
	 * \endif
	 */
	wyPoint clipPos;

	union {
		/**
		 * \if English
		 * info of image clip
		 * \else
		 * 图片类型分片的信息
		 * \endif
		 */
		struct {
			/**
			 * \if English
			 * the batch node related to this clip currently
			 * \else
			 * 和这个分片当前关联的图片集
			 * \endif
			 */
			wySpriteBatchNode* sheet;

			/**
			 * \if English
			 * Image index of clip, it is the original sheet texture related
			 * to this clip
			 * \else
			 * 分片所属的图片集索引, 它指向这个分片所属的原始图片集
			 * \endif
			 */
			int imageIndex;

			/**
			 * \if English
			 * image rect in atlas
			 * \else
			 * 图片在图片集中的矩形
			 * \endif
			 */
			wyRect rect;

			/**
			 * \if English
			 * is image flipped in x axis
			 * \else
			 * 图片是否x轴翻转
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
		} i;

		/**
		 * \if English
		 * info of ellipse clip
		 * \else
		 * 椭圆类型分片的信息
		 * \endif
		 */
		struct {
			/**
			 * \if English
			 * fill color in 0xaarrggbb format
			 * \else
			 * 椭圆的填充颜色
			 * \endif
			 */
			int color;

			/**
			 * \if English
			 * size of ellipse circumscribed rectangle
			 * \else
			 * 椭圆的外接矩形大小
			 * \endif
			 */
			wySize size;

			/**
			 * \if English
			 * start angle of ellipse
			 * \else
			 * 椭圆范围的起始角度
			 * \endif
			 */
			float startAngle;

			/**
			 * \if English
			 * end angle of ellipse
			 * \else
			 * 椭圆范围的结束角度
			 * \endif
			 */
			float endAngle;
		} e;

		/**
		 * \if English
		 * info of line clip
		 * \else
		 * 线段类型分片的信息
		 * \endif
		 */
		struct {
			/**
			 * \if English
			 * color in 0xaarrggbb format
			 * \else
			 * 线段的颜色
			 * \endif
			 */
			int color;

			/**
			 * \if English
			 * end point of line, the start point is \c m_clipPos of \link wyAFCClip wyAFCClip\endlink
			 * \else
			 * 线段的结束点, 起始点是\link wyAFCClip wyAFCClip\endlink中的\c m_clipPos成员
			 * \endif
			 */
			wyPoint endPoint;
		} l;

		/**
		 * \if English
		 * info of rect clip
		 * \else
		 * 矩形类型分片的信息
		 * \endif
		 */
		struct {
			/**
			 * \if English
			 * fill color in 0xaarrggbb format
			 * \else
			 * 矩形的填充颜色
			 * \endif
			 */
			int color;

			/**
			 * \if English
			 * size of rectangle
			 * \else
			 * 矩形大小
			 * \endif
			 */
			wySize size;
		} r;

		/**
		 * \if English
		 * info of roundrect clip
		 * \else
		 * 圆角矩形类型分片的信息
		 * \endif
		 */
		struct {
			/**
			 * \if English
			 * fill color in 0xaarrggbb format
			 * \else
			 * 圆角矩形的填充颜色
			 * \endif
			 */
			int color;

			/**
			 * \if English
			 * size of round rectangle
			 * \else
			 * 圆角矩形大小
			 * \endif
			 */
			wySize size;

			/**
			 * \if English
			 * width of round corner
			 * \else
			 * 圆角宽
			 * \endif
			 */
			float arcWidth;

			/**
			 * \if English
			 * height of round corner
			 * \else
			 * 圆角高
			 * \endif
			 */
			float arcHeight;
		} rr;

		/**
		 * \if English
		 * info of collision rect clip
		 * \else
		 * 碰撞矩形类型分片的信息
		 * \endif
		 */
		struct {
			/**
			 * \if English
			 * size of collision rectangle
			 * \else
			 * 碰撞矩形大小
			 * \endif
			 */
			wySize size;
		} cr;

		/**
		 * \if English
		 * info of collision triangle clip
		 * \else
		 * 三角形类型分片的信息
		 * \endif
		 */
		struct {
			/**
			 * \if English
			 * second point
			 * \else
			 * 第二个点
			 * \endif
			 */
			wyPoint pt2;

			/**
			 * \if English
			 * third point
			 * \else
			 * 第三个点
			 * \endif
			 */
			wyPoint pt3;
		} t;
	};
} wyAFCClipData;

/**
 * @class wyAFCClip
 *
 * \if English
 * A clip in a frame
 * \else
 * 代表了一个帧中的分片
 * \endif
 */
class WIENGINE_API wyAFCClip : public wyObject {
private:
	/**
	 * \if English
	 * clip type
	 * \else
	 * 分片的类型
	 * \endif
	 */
	wyAFCClipType m_type;

	/**
	 * Clip index in editor. However, some editor doesn't assign an index to
	 * clip, such as Motion Welder, SpriteX, etc., and the clip index is meaningless
	 * for those editors
	 */
	int m_index;

	/**
	 * \if English
	 * additional data of clip
	 * \else
	 * 分片的额外信息
	 * \endif
	 */
	wyAFCClipData m_data;

protected:
	wyAFCClip();

public:
	virtual ~wyAFCClip();
	static wyAFCClip* make();

	/**
	 * \if English
	 * Get type of clip
	 *
	 * @return type of clip
	 * \else
	 * 得到分片类型
	 *
	 * @return 分片类型
	 * \endif
	 * \see wyAFCClipType
	 */
	wyAFCClipType getType() { return m_type; }

	/**
	 * \if English
	 * Set type of clip
	 *
	 * @param type type of clip
	 * \else
	 * 设置分片类型
	 *
	 * @param type 分片类型
	 * \endif
	 * \see wyAFCClipType
	 */
	void setType(wyAFCClipType type) { m_type = type; }

	/**
	 * \if English
	 * Clip index in editor. However, some editor doesn't assign an index to
	 * clip, such as Motion Welder, SpriteX 3.9.4, etc., and the clip index is meaningless
	 * for those editors. Furthermore, if this clip is a mapped clip of external atlas,
	 * then index is also useless.
	 *
	 * \note
	 * If index is -1, then index field is useless for this clip
	 *
	 * @return clip index, returns -1 if index field is meaningless for this clip
	 * \else
	 * 分片在编辑器中的索引. 不过有些编辑器并不会对分片分配一个索引, 比如Motion Welder, SpriteX 3.9.4等,
	 * 那么对于这些编辑器, 这个字段没有意义. 此外, 如果这个分片是映射到了外部的图片集上, 那么索引字段
	 * 也无意义
	 *
	 * \note
	 * 也可能存在其它情况导致索引字段无意义, 总之如果返回的索引是-1, 则说明索引对该分片无意义
	 *
	 * @return 分片索引, 如果返回的是-1, 则说明索引字段对这个分片无意义
	 * \endif
	 */
	int getIndex() { return m_index; }

	/**
	 * \if English
	 * Set clip index
	 *
	 * @param i clip index
	 * \else
	 * 设置分片索引
	 *
	 * @param i 分片索引
	 * \endif
	 */
	void setIndex(int i) { m_index = i; }

	/**
	 * \if English
	 * Get clip data
	 *
	 * @return clip data
	 * \else
	 * 得到分片的额外信息
	 *
	 * @return 分片的额外信息
	 * \endif
	 */
	wyAFCClipData& getData() { return m_data; }
};

#endif // __wyAFCClip_h__
