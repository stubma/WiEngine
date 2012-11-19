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
#ifndef __wyArrayTileMapAtlas_h__
#define __wyArrayTileMapAtlas_h__

#include "wyTileMapAtlas.h"

/**
 * @class wyArrayTileMapAtlas
 * to use one dimension array to represent a tiled map, zero based.
 */
class WIENGINE_API wyArrayTileMapAtlas : public wyTileMapAtlas {
protected:
	/**
	 * points to the original tiles
	 */
	int* m_tiles;

	/**
	 * the tile count on the x axis
	 */
	int m_xTiles;

	/**
	 * the tile count on the y axis
	 */
	int m_yTiles;

public:
	/**
	 * factory function, used to create an new instance with autoRelease enabled
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param tileWidth width of a single tile, in pixels
	 * @param tileHeight height of a single tile, in pixels
	 * @param xTiles tile count on the x axis
	 * @param yTiles tile count on the y axis
	 * @param tiles pointer of the original array of tiles, this array will be copied, so it can be released after this function call.
	 *
	 */
	static wyArrayTileMapAtlas* make(wyTexture2D* tex, int tileWidth, int tileHeight, int xTiles, int yTiles, int* tiles);

	/**
	 * constructor
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param tileWidth width of a single tile, in pixels
	 * @param tileHeight height of a single tile, in pixels
	 * @param xTiles tile count on the x axis
	 * @param yTiles tile count on the y axis
	 * @param tiles pointer of the original array of tiles, this array will be copied, so it can be released after this function call.
	 */
	wyArrayTileMapAtlas(wyTexture2D* tex, int tileWidth, int tileHeight, int xTiles, int yTiles, int* tiles);

	/**
	 * destructor
	 */
	virtual ~wyArrayTileMapAtlas();

	/**
	 * to refresh tiles
	 */
	void refreshTileValues();

	/// @see wyTileMapAtlas::hasTileAt
    virtual bool hasTileAt(int x, int y);

    /// @see wyTileMapAtlas::getHorizontalTileCount
    virtual int getHorizontalTileCount() { return m_xTiles; }

    /// @see wyTileMapAtlas::getVerticalTileCount
    virtual int getVerticalTileCount() { return m_yTiles; }

    /// @see wyTileMapAtlas::tileValueAt
    virtual int tileValueAt(int x, int y);

    /**
     * to get the original tiles array
	 */
    int* getTiles() { return m_tiles; }
};


#endif // __wyArrayTileMapAtlas_h__
