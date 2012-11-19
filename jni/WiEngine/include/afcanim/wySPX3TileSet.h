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
#ifndef __wySPX3TileSet_h__
#define __wySPX3TileSet_h__

#include "wyObject.h"
#include "wySPX3Constants.h"
#include "wyTypes.h"
#include "wyMath.h"

/**
 * @typedef wySPX3Tile
 *
 * tile size info in SpriteX 2011
 */
typedef struct wySPX3Tile {
	/**
	 * x position of first corner
	 */
	short x1;

	/**
	 * y position of first corner
	 */
	short y1;

	/**
	 * x position of another corner
	 */
	short x2;

	/**
	 * y position of another corner
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
 * tile set info
 */
class WIENGINE_API wySPX3TileSet : public wyObject {
public:
	/**
	 * mode of this tileset
	 */
	wySPX3TileSetMode m_mode;

	/**
	 * image index
	 */
	int m_imageIndex;

	/**
	 * width of a tile, only used in index mode
	 */
    int m_tileWidth;

	/**
	 * height of a tile, only used in index mode
	 */
    int m_tileHeight;

	/**
	 * tile columns, only used in index mode
	 */
    int m_tileColumns;

	/**
	 * tile rows, only used in index mode
	 */
    int m_tileRows;

    /**
     * total number of tiles, only used in clip mode
     */
    int m_tileCount;

    /**
     * data of all tile, only used in clip mode
     */
    wySPX3Tile* m_tiles;

protected:
    wySPX3TileSet();

public:
    virtual ~wySPX3TileSet();
    static wySPX3TileSet* make();
};

#endif // __wySPX3TileSet_h__
