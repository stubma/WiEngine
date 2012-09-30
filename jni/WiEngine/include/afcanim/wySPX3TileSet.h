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
#ifndef __wySPX3TileSet_h__
#define __wySPX3TileSet_h__

#include "wyObject.h"
#include "wySPX3Constants.h"
#include "wyTypes.h"
#include "wyMath.h"

/**
 * @typedef wySPX3Tile
 *
 * \if English
 * tile size info in SpriteX 2011
 * \else
 * 一个SpriteX 2011中的tile
 * \endif
 */
typedef struct wySPX3Tile {
	/**
	 * \if English
	 * x position of first corner
	 * \else
	 * 分片图片在图片集中的矩形的第一个角的x坐标
	 * \endif
	 */
	short x1;

	/**
	 * \if English
	 * y position of first corner
	 * \else
	 * 分片图片在图片集中的矩形的第一个角的y坐标
	 * \endif
	 */
	short y1;

	/**
	 * \if English
	 * x position of another corner
	 * \else
	 * 分片图片在图片集中的矩形的对角的x坐标
	 * \endif
	 */
	short x2;

	/**
	 * \if English
	 * y position of another corner
	 * \else
	 * 分片图片在图片集中的矩形的对角的y坐标
	 * \endif
	 */
	short y2;

	short left() {
		return MIN(x1, x2);
	}

	short bottom() {
		// positive of y axis in SpriteX is down direction
		return MAX(y1, y2);
	}

	short right() {
		return MAX(x1, x2);
	}

	short top() {
		// positive of y axis in SpriteX is down direction
		return MIN(y1, y2);
	}

	short width() {
		return abs(x1 - x2);
	}

	short height() {
		return abs(y1 - y2);
	}
} wySPX3Tile;

/**
 * @class wySPX3TileSet
 *
 * \if English
 * tile set info
 * \else
 * 分片集信息
 * \endif
 */
class WIENGINE_API wySPX3TileSet : public wyObject {
public:
	/**
	 * \if English
	 * mode of this tileset
	 * \else
	 * 分片集数据模式
	 * \endif
	 */
	wySPX3TileSetMode m_mode;

	/**
	 * \if English
	 * image index
	 * \else
	 * 图片集索引
	 * \endif
	 */
	int m_imageIndex;

	/**
	 * \if English
	 * width of a tile, only used in index mode
	 * \else
	 * 分片宽度， 用于索引数据模式
	 * \endif
	 */
    int m_tileWidth;

	/**
	 * \if English
	 * height of a tile, only used in index mode
	 * \else
	 * 分片高度， 用于索引数据模式
	 * \endif
	 */
    int m_tileHeight;

	/**
	 * \if English
	 * tile columns, only used in index mode
	 * \else
	 * 图片集中包含多少列分片， 用于索引数据模式
	 * \endif
	 */
    int m_tileColumns;

	/**
	 * \if English
	 * tile rows, only used in index mode
	 * \else
	 * 图片集中包含多少行分片， 用于索引数据模式
	 * \endif
	 */
    int m_tileRows;

    /**
     * \if English
     * total number of tiles, only used in clip mode
     * \else
     * 分片数, 只用于分片模式
     * \endif
     */
    int m_tileCount;

    /**
     * \if English
     * data of all tile, only used in clip mode
     * \else
     * 所有分片的数据， 只用于分片模式
     * \endif
     */
    wySPX3Tile* m_tiles;

protected:
    wySPX3TileSet();

public:
    virtual ~wySPX3TileSet();
    static wySPX3TileSet* make();
};

#endif // __wySPX3TileSet_h__
