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
#ifndef __wySPXFrame_h__
#define __wySPXFrame_h__

#include "wyObject.h"
#include "wySPXConstants.h"

class wySPXLoader;

/**
 * @typedef wySPXFrameTile
 *
 * \if English
 * tile info in a frame
 * \else
 * 一帧中的tile信息
 * \endif
 */
typedef struct wySPXFrameTile {
	/**
	 * \if English
	 * index of tile
	 * \else
	 * tile的索引
	 * \endif
	 */
	int index;

	/**
	 * \if English
	 * tile x position in frame
	 * \else
	 * tile在帧中的x位置
	 * \endif
	 */
	int x;

	/**
	 * \if English
	 * tile y position in frame
	 * \else
	 * tile在帧中的y位置
	 * \endif
	 */
	int y;

	/**
	 * \if English
	 * transform of this tile
	 * \else
	 * tile的转换标志
	 * \endif
	 */
	wySPXTransform transform;
} wySPXFrameTile;

/**
 * @typedef wySPXCollision
 *
 * \if English
 * collision region
 * \else
 * 碰撞区域定义
 * \endif
 */
typedef struct wySPXCollision {
	/**
	 * \if English
	 * x position of collision region
	 * \else
	 * 碰撞区域的x位置
	 * \endif
	 */
	int x;

	/**
	 * \if English
	 * y position of collision region
	 * \else
	 * 碰撞区域的y位置
	 * \endif
	 */
	int y;

	/**
	 * \if English
	 * width of collision region
	 * \else
	 * 碰撞区域的宽度
	 * \endif
	 */
	int width;

	/**
	 * \if English
	 * height of collision region
	 * \else
	 * 碰撞区域的高度
	 * \endif
	 */
	int height;
} wySPXCollision;

/**
 * @typedef wySPXReferencePoint
 *
 * \if English
 * reference point
 * \else
 * 参考点
 * \endif
 */
typedef struct wySPXReferencePoint {
	/**
	 * \if English
	 * x location of reference point
	 * \else
	 * 参考点的x坐标
	 * \endif
	 */
	int x;

	/**
	 * \if English
	 * y location of reference point
	 * \else
	 * 参考点的y坐标
	 * \endif
	 */
	int y;
} wySPXReferencePoint;

/**
 * \if English
 * frame of SpriteX animation
 * \else
 * SpriteX动画中的帧
 * \endif
 */
class WIENGINE_API wySPXFrame : public wyObject {
	friend class wySPXLoader;

public:
	/**
	 * \if English
	 * width of frame
	 * \else
	 * 帧的像素宽度
	 * \endif
	 */
	int m_width;

	/**
	 * \if English
	 * height of frame
	 * \else
	 * 帧的像素高度
	 * \endif
	 */
	int m_height;

	/**
	 * \if English
	 * tile count in frame
	 * \else
	 * 帧内tile个数
	 * \endif
	 */
	int m_frameTileCount;

	/**
	 * \if English
	 * collision rect count in frame
	 * \else
	 * 碰撞区域个数
	 * \endif
	 */
	int m_collisionCount;

	/**
	 * \if English
	 * reference point count in frame
	 * \else
	 * 参考点个数
	 * \endif
	 */
	int m_referencePointCount;

	/**
	 * \if English
	 * tile count in frame
	 * \else
	 * 帧内的tile信息
	 * \endif
	 */
	wySPXFrameTile* m_tiles;

	/**
	 * \if English
	 * collision rect info in frame
	 * \else
	 * 帧内的碰撞区域
	 * \endif
	 */
	wySPXCollision* m_collisions;

	/**
	 * \if English
	 * reference point in frame
	 * \else
	 * 帧内的参考点
	 * \endif
	 */
	wySPXReferencePoint* m_refPoints;

private:
	wySPXFrame();

public:
	virtual ~wySPXFrame();
};

#endif // __wySPXFrame_h__
