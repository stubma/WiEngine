/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wySPX3Frame_h__
#define __wySPX3Frame_h__

#include "wyObject.h"
#include "wySPX3TileSet.h"

/**
 * @struct wySPX3Patch
 *
 * \if English
 * Clip in SpriteX 2011, it calls them patch. There is two types of patch:
 * image or shape.
 * \else
 * 分片信息, SpriteX 2011管这个叫Patch. Patch分为图片和形状两种
 * \endif
 */
typedef struct wySPX3Patch {
	/**
	 * \if English
	 * patch type
	 * \else
	 * 分片类型
	 * \endif
	 */
	wySPX3PatchType type;

	union {
		/**
		 * \if English
		 * for image type tile
		 * \else
		 * 图片类型的分片信息
		 * \endif
		 */
		struct {
			/**
			 * \if English
			 * index of tile set
			 * \else
			 * 分片集索引
			 * \endif
			 */
			short tileSetIndex;

			/**
			 * \if English
			 * index of tile
			 * \else
			 * 分片索引
			 * \endif
			 */
			short tileIndex;

			/**
			 * \if English
			 * tile x position in frame
			 * \else
			 * 分片在帧中的x位置
			 * \endif
			 */
			short x;

			/**
			 * \if English
			 * tile y position in frame
			 * \else
			 * 分片在帧中的y位置
			 * \endif
			 */
			short y;

			/**
			 * \if English
			 * transform of this tile
			 * \else
			 * 分片的转换方式
			 * \endif
			 */
			wySPXTransform transform;
		} tile;

		/**
		 * \if English
		 * for shape type tile
		 * \else
		 * 形状类型的分片信息
		 * \endif
		 */
		struct {
			/**
			 * \if English
			 * drawing mode, useless in WiEngine
			 * \else
			 * 渲染模式， WiEngine中无用
			 * \endif
			 */
			int mode;

			/**
			 * \if English
			 * shape type
			 * \else
			 * 形状类型
			 * \endif
			 */
			wySPX3ShapeType shape;

			/**
			 * \if English
			 * transform of this tile
			 * \else
			 * 分片的转换方式
			 * \endif
			 */
			wySPXTransform transform;

			/**
			 * \if English
			 * color of shape
			 * \else
			 * 渲染的颜色
			 * \endif
			 */
		    int color;

		    /**
		     * \if English
		     * vertex count of shape
		     * \else
		     * 这个形状相关的点个数
		     * \endif
		     */
		    short vertexCount;

		    /**
		     * \if English
		     * count of shape parameters, first is vertices, then followed by
		     * other parameters
		     * \else
		     * 形状的参数， 最开始的是点坐标， 之后根据具体的形状可能有其它参数
		     * \endif
		     */
		    short paramCount;

		    /**
		     * \if English
		     * buffer of parameters
		     * \else
		     * 参数
		     * \endif
		     */
		    short* params;
		} shape;
	};
} wySPX3Patch;

/**
 * @class wySPX3Frame
 *
 * \if English
 * frame in SpriteX 2011
 * \else
 * SpriteX 2011中的帧数据
 * \endif
 */
class WIENGINE_API wySPX3Frame : public wyObject {
public:
	/**
	 * \if English
	 * flag of frame
	 * \else
	 * 帧的标志位信息
	 * \endif
	 */
	int m_flags;

	/**
	 * \if English
	 * frame rect in animation
	 * \else
	 * 帧在动画中的位置
	 * \endif
	 */
	wySPX3Tile m_rect;

	/**
	 * \if English
	 * count of patch
	 * \else
	 * 帧内分片数
	 * \endif
	 */
	int m_patchCount;

	/**
	 * \if English
	 * data of all patch
	 * \else
	 * 所有分片的数据
	 * \endif
	 */
	wySPX3Patch* m_patches;

	/**
	 * \if English
	 * count of collision rectangle
	 * \else
	 * 帧内的碰撞矩形数
	 * \endif
	 */
	int m_collisionCount;

	/**
	 * \if English
	 * data of all collision rectangles
	 * \else
	 * 所有碰撞矩形的数据
	 * \endif
	 */
	wySPX3Tile* m_collisionRects;

protected:
	wySPX3Frame();

public:
    virtual ~wySPX3Frame();
    static wySPX3Frame* make();
};

#endif // __wySPX3Frame_h__
