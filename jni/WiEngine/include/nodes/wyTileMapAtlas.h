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
#ifndef __wyTileMapAtlas_h__
#define __wyTileMapAtlas_h__

#include "wyAtlasNode.h"
#include <stdbool.h>

/**
 * @class wyTileMapAtlas
 * The base class of tiled map.
 * The tiled map is of 2-dimension. So its tile can be represented as (x, y), where x and y are both zero based,
 * and (0, 0) points to the left bottom.
 */
class WIENGINE_API wyTileMapAtlas : public wyAtlasNode {
protected:
	/**
	 * the index array of tiles, the entry value is the index of the tile in the atlas picture.
	 */
	int* m_atlasIndices;

	/**
	 * tile count
	 */
    int m_itemsToRender;

private:
    void calculateItemsToRender();
    void updateAtlas(wyPoint pos, int tileValue, int idx);
    void updateAtlasValues();

protected:
    /**
     * to do initialization
	 */
    void initTileValues();

    /**
     * to get the x coordinate of the tile's left edge in the atlas picture
     *
     * @param value identifier of the tile
     */
    float mapTileTexY(int value);

    /**
     * to get the y coordinate of the tile's up edge in the atlas picture
     *
     * @param value identifier of the tile
     */
    float mapTileTexX(int value);

public:
    /**
     * constructor
     *
     * @param tex \link wyTexture2D wyTexture2D\endlink
     * @param tileWidth width of the tile, in pixels
     * @param tileHeight height of the tile, in pixels
	 */
    wyTileMapAtlas(wyTexture2D* tex, int tileWidth, int tileHeight);

    /**
     * destructor
	 */
    virtual ~wyTileMapAtlas();

    /**
     * check whether there is a tile at (x, y)
     *
     * @param x x coordinate of the tile in the tiled map
     * @param y y coordinate of the tile in the tiled map
     * @return true means there is a tile at (x, y)
	 */
    virtual bool hasTileAt(int x, int y) = 0;

    /**
     * getter, to get the tile count on the x axis
	 */
    virtual int getHorizontalTileCount() = 0;

    /**
     * getter, to get the tile count on the y axis
	 */
    virtual int getVerticalTileCount() = 0;

    /**
     * getter, to get the original value of a tile
     *
     * @param x x coordinate of the tile in the tiled map
     * @param y y coordinate of the tile in the tiled map
	 */
    virtual int tileValueAt(int x, int y) = 0;

    /**
     * getter, to get a tile value
     *
     * @param x x coordinate of the tile in the tiled map
     * @param y y coordinate of the tile in the tiled map
	 */
	int getTile(int x, int y);

	/**
	 * setter, to set a tile value
	 *
	 * @param tileVale the new value
	 * @param x x coordinate of the tile in the tiled map
     * @param y y coordinate of the tile in the tiled map
	 */
	void setTile(int tileValue, int x, int y);
};

#endif // __wyTileMapAtlas_h__
