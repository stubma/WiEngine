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
#ifndef __wyArrayTileMapAtlas_h__
#define __wyArrayTileMapAtlas_h__

#include "wyTileMapAtlas.h"

/**
 * @class wyArrayTileMapAtlas
 * \if English
 * to use one dimension array to represent a tiled map, zero based.
 * \else
 * 实现了一个通过整型数组生成瓦片地图的机制。
 * 如果一个图片集包含3x3个单幅图片，则整数4会映射到第二行第二列的图片,因为 4 / 3 = 1, 4 % 3 = 1
 * \endif
 */
class WIENGINE_API wyArrayTileMapAtlas : public wyTileMapAtlas {
protected:
	/**
	 * \if English
	 * points to the original tiles
	 * \else
	 * 原始瓦片值
	 * \endif
	 */
	int* m_tiles;

	/**
	 * \if English
	 * the tile count on the x axis
	 * \else
	 * x方向瓦片个数
	 * \endif
	 */
	int m_xTiles;

	/**
	 * \if English
	 * the tile count on the y axis
	 * \else
	 * y方向瓦片个数
	 * \endif
	 */
	int m_yTiles;

public:
	/**
	 * \if English
	 * factory function, used to create an new instance with autoRelease enabled
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param tileWidth width of a single tile, in pixels
	 * @param tileHeight height of a single tile, in pixels
	 * @param xTiles tile count on the x axis
	 * @param yTiles tile count on the y axis
	 * @param tiles pointer of the original array of tiles, this array will be copied, so it can be released after this function call.
	 *
	 * \else
	 * 静态构造函数
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param tileWidth 单个瓦片图片的宽度
	 * @param tileHeight 单个瓦片图片的高度
	 * @param xTiles x方向瓦片个数
	 * @param yTiles y方向瓦片个数
	 * @param tiles 原始瓦片值, 该数组会被复制，因此在构造完成后可以释放
	 * \endif
	 */
	static wyArrayTileMapAtlas* make(wyTexture2D* tex, int tileWidth, int tileHeight, int xTiles, int yTiles, int* tiles);

	/**
	 * \if English
	 * constructor
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param tileWidth width of a single tile, in pixels
	 * @param tileHeight height of a single tile, in pixels
	 * @param xTiles tile count on the x axis
	 * @param yTiles tile count on the y axis
	 * @param tiles pointer of the original array of tiles, this array will be copied, so it can be released after this function call.
	 * \else
	 * 构造函数
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param tileWidth 单个瓦片图片的宽度
	 * @param tileHeight 单个瓦片图片的高度
	 * @param xTiles x方向瓦片个数
	 * @param yTiles y方向瓦片个数
	 * @param tiles 原始瓦片值, 该数组会被复制，因此在构造完成后可以释放
	 * \endif
	 */
	wyArrayTileMapAtlas(wyTexture2D* tex, int tileWidth, int tileHeight, int xTiles, int yTiles, int* tiles);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyArrayTileMapAtlas();

	/**
	 * \if English
	 * to refresh tiles
	 * \else
	 * 刷新瓦片值
	 * \endif
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
     * \if English
     * to get the original tiles array
     * \else
	 * 得到原始瓦片值
	 *
	 * @return 原始瓦片值
	 * \endif
	 */
    int* getTiles() { return m_tiles; }
};


#endif // __wyArrayTileMapAtlas_h__
