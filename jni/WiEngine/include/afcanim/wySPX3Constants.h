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
#ifndef __wySPX3Constants_h__
#define __wySPX3Constants_h__

#include "wySPXConstants.h"

/**
 * @typedef wySPX3ActionMode
 *
 * \if English
 * Mode of action
 * \else
 * SPX3动画中的模式字节
 * \endif
 */
typedef enum {
	/**
	 * \if English
	 * animation uses time to define frame duration
	 * \else
	 * 动画使用时间来定义帧持续时间
	 * \endif
	 */
	SPX_DELAY = 1,

	/**
	 * \if English
	 * all frames in animation are displayed for one frame time
	 * \else
	 * 动画内的所有帧都只显示一帧的时间, 这个模式下， 动画信息中不包含每帧的
	 * 持续时间
	 * \endif
	 */
	SPX_NODELAY
} wySPX3ActionMode;

/**
 * \if English
 * mode of tile sets
 * \else
 * SPX3中的分片集中的数据模式
 * \endif
 */
typedef enum {
	/**
	 * \if English
	 * every tile has same size, so it only saves tile size and rows/columns in atlas.
	 * That means the file size can be smaller
	 * \else
	 * 每个分片的大小都是相同的， 而且是规律的网格状分布， 这样就只需要保存分片的大小和行列数即可，
	 * 相对于索引模式可以减少文件尺寸
	 * \endif
	 */
	SPX_TILE_INDEX = 1,

	/**
	 * \if English
	 * every tile is defined by position and size
	 * \else
	 * 每个分片都由一个位置和大小来进行定义
	 * \endif
	 */
	SPX_TILE_CLIP
} wySPX3TileSetMode;

/**
 * @typedef wySPX3PatchType
 *
 * \if English
 * Type of patch, patch here is just equal with tile
 *
 * \note
 * Collision rectangle is not a tile in SpriteX 2011 and SpriteX 2011 processes
 * collision rectangle alone
 * \else
 * 分片的类型。SpriteX 2011把分片做了两级分类， 第一级只有tile和shape两种， 它这里用的
 * patch， 其意思其实相当于tile. 可以认为Patch和Tile是两个可以在SpriteX中等同的术语。
 *
 * \note
 * 碰撞矩形在SpriteX 2011中不被当成一种分片， 因此没有分片类型， 是单独处理的一种元素
 * \endif
 */
typedef enum {
	/**
	 * \if English
	 * patch is a tile, i.e., at image in atlas
	 * \else
	 * 分片是一个图片集中的图片
	 * \endif
	 */
	SPX_PATCH_TILE = 1,

	/**
	 * \if English
	 * patch is a shape
	 * \else
	 * 分片是一个形状.
	 * \endif
	 */
	SPX_PATCH_SHAPE
} wySPX3PatchType;

/**
 * @typedef wySPX3ShapeType
 *
 * \if English
 * type of shape
 * \else
 * 分片如果是个形状， 这些常量定义了矩形是什么形状
 * \endif
 */
typedef enum {
	SPX_POINT = 0x01,
	SPX_LINE = 0x02,
	SPX_RECT = 0x03,
	SPX_TRIANGLE = 0x04,
	SPX_POLYGON = 0x05,
	SPX_ELLIPSE = 0x06,
	SPX_ROUNDRECT = 0x08,
	SPX_ARC = 0x09,
	SPX_PIE = 0x0A
} wySPX3ShapeType;

#endif // __wySPX3Constants_h__
