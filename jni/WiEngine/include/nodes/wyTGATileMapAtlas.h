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
#ifndef __wyTGATileMapAtlas_h__
#define __wyTGATileMapAtlas_h__

#include "wyTileMapAtlas.h"
#include "wyTGALoader.h"

/**
 * @class wyTGATileMapAtlas
 *
 * TGA格式的瓦片地图。通过把图片中象素的R值映射到瓦片图片集中，形成地图
 */
class WIENGINE_API wyTGATileMapAtlas : public wyTileMapAtlas {
protected:
	/// \link wyTGA wyTGA结构\endlink
	wyTGA* m_tga;

	/// TGA图片一行的字节数
	int m_rowBytes;

public:
	/**
	 * 静态构造函数
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param mapResId TGA资源id
	 * @param tileWidth 单个瓦片图片的象素宽度
	 * @param tileHeight 单个瓦片图片的象素高度
	 */
	static wyTGATileMapAtlas* make(wyTexture2D* tex, int mapResId, int tileWidth, int tileHeight);

	/**
	 * 构造函数
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param mapResId TGA资源id
	 * @param tileWidth 单个瓦片图片的象素宽度
	 * @param tileHeight 单个瓦片图片的象素高度
	 */
	wyTGATileMapAtlas(wyTexture2D* tex, int mapResId, int tileWidth, int tileHeight);

	/**
	 * 析构函数
	 */
	virtual ~wyTGATileMapAtlas();

	/// @see wyTileMapAtlas::hasTileAt
    virtual bool hasTileAt(int x, int y);

    /// @see wyTileMapAtlas::getHorizontalTileCount
    virtual int getHorizontalTileCount() { return m_tga->width; }

    /// @see wyTileMapAtlas::getVerticalTileCount
    virtual int getVerticalTileCount() { return m_tga->height; }

    /// @see wyTileMapAtlas::tileValueAt
    virtual int tileValueAt(int x, int y);
};

#endif // __wyTGATileMapAtlas_h__
