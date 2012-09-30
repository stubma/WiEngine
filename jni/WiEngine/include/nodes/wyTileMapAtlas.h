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
#ifndef __wyTileMapAtlas_h__
#define __wyTileMapAtlas_h__

#include "wyAtlasNode.h"
#include <stdbool.h>

/**
 * @class wyTileMapAtlas
 * \if English
 * The base class of tiled map.
 * The tiled map is of 2-dimension. So its tile can be represented as (x, y), where x and y are both zero based,
 * and (0, 0) points to the left bottom.
 * \else
 * 瓦片地图抽象基类. 其瓦片的坐标用(x, y)表示，每个瓦片都有一个值，这个值会映射到一个
 * 图片集中的图片。瓦片的坐标采用OpenGL坐标系，即(0, 0)表示的是左下角。
 * \endif
 */
class WIENGINE_API wyTileMapAtlas : public wyAtlasNode {
protected:
	/**
	 * \if English
	 * the index array of tiles, the entry value is the index of the tile in the atlas picture.
	 * \else
	 * 瓦片在atlas中的索引数组
	 * \endif
	 */
	int* m_atlasIndices;

	/**
	 * \if English
	 * tile count
	 * \else
	 * 瓦片数量
	 * \endif
	 */
    int m_itemsToRender;

private:
    void calculateItemsToRender();
    void updateAtlas(wyPoint pos, int tileValue, int idx);
    void updateAtlasValues();

protected:
    /**
     * \if English
     * to do initialization
     * \else
	 * 初始化
	 * \endif
	 */
    void initTileValues();

    /**
     * \if English
     * to get the x coordinate of the tile's left edge in the atlas picture
     *
     * @param value identifier of the tile
     * \else
     * 通过瓦片值找到瓦片图片的x贴图坐标. 这个坐标代表了瓦片的左边缘。
     *
     * @param value 瓦片id
     * \endif
     */
    float mapTileTexY(int value);

    /**
     * \if English
     * to get the y coordinate of the tile's up edge in the atlas picture
     *
     * @param value identifier of the tile
     * \else
     * 通过瓦片值找到瓦片图片的y贴图坐标. 这个坐标代表了瓦片的上边缘。
     *
     * @param value 瓦片id
     * \endif
     */
    float mapTileTexX(int value);

public:
    /**
     * \if English
     * constructor
     *
     * @param tex \link wyTexture2D wyTexture2D\endlink
     * @param tileWidth width of the tile, in pixels
     * @param tileHeight height of the tile, in pixels
     * \else
	 * 构造函数
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param tileWidth 单个瓦片的象素宽度
	 * @param tileHeight 单个瓦片的象素高度
	 * \endif
	 */
    wyTileMapAtlas(wyTexture2D* tex, int tileWidth, int tileHeight);

    /**
     * \if English
     * destructor
     * \else
	 * 析构函数
	 * \endif
	 */
    virtual ~wyTileMapAtlas();

    /**
     * \if English
     * check whether there is a tile at (x, y)
     *
     * @param x x coordinate of the tile in the tiled map
     * @param y y coordinate of the tile in the tiled map
     * @return true means there is a tile at (x, y)
     * \else
	 * 检查在指定行列位置是否有瓦片
	 *
	 * @param x 行位置
	 * @param y 列位置
	 * @return true表示有，false表示该位置没有映射到任何瓦片图片上
	 * \endif
	 */
    virtual bool hasTileAt(int x, int y) = 0;

    /**
     * \if English
     * getter, to get the tile count on the x axis
     * \else
	 * 得到水平方向上的瓦片数
	 *
	 * @return 水平方向上的瓦片数
	 * \endif
	 */
    virtual int getHorizontalTileCount() = 0;

    /**
     * \if English
     * getter, to get the tile count on the y axis
     * \else
	 * 得到垂直方向上的瓦片数
	 *
	 * @return 垂直方向上的瓦片数
	 * \endif
	 */
    virtual int getVerticalTileCount() = 0;

    /**
     * \if English
     * getter, to get the original value of a tile
     *
     * @param x x coordinate of the tile in the tiled map
     * @param y y coordinate of the tile in the tiled map
     * \else
	 * 得到某个行列坐标上的原始瓦片值，瓦片值如何映射到瓦片图片由子类实现决定
	 *
	 * @param x 行位置
	 * @param y 列位置
	 * @return 瓦片原始值
	 * \endif
	 */
    virtual int tileValueAt(int x, int y) = 0;

    /**
     * \if English
     * getter, to get a tile value
     *
     * @param x x coordinate of the tile in the tiled map
     * @param y y coordinate of the tile in the tiled map
     * \else
	 * 得到某个行列位置的瓦片值
	 *
	 * @param x x坐标
	 * @param y y坐标
	 * @return 原始瓦片值，瓦片值如何映射到瓦片图片由子类实现决定
	 * \endif
	 */
	int getTile(int x, int y);

	/**
	 * \if English
	 * setter, to set a tile value
	 *
	 * @param tileVale the new value
	 * @param x x coordinate of the tile in the tiled map
     * @param y y coordinate of the tile in the tiled map
     * \else
	 * 设置某个行列位置的瓦片值
	 *
	 * @param tileValue 原始瓦片值，瓦片值如何映射到瓦片图片由子类实现决定
	 * @param x x坐标
	 * @param y y坐标
	 * \endif
	 */
	void setTile(int tileValue, int x, int y);
};

#endif // __wyTileMapAtlas_h__
