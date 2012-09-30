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
#ifndef __wyTMXLayer_h__
#define __wyTMXLayer_h__

#include "wySpriteBatchNode.h"
#include "wyMapInfo.h"
#include "wyLayerInfo.h"
#include "wyTileSetInfo.h"
#include "wyHashSet.h"
#include "wyTextureAtlas.h"

class wyTMXTileMap;
struct wyTileSetAtlasInfo;

/**
 * @class wyTMXLayer
 *
 * 代表了TMX地图中的一个层, 提供了获取层信息的各种方法. 层是可写的, 可以通过相应方法
 * 动态的修改瓦片. 层的坐标从左上角开始，x往右增长，y往下增长, 即(0, 0)代表的是左上角
 * 的瓦片。
 */
class WIENGINE_API wyTMXLayer : public wyNode {
	friend class wyTMXTileMap;

protected:
	/**
	 * 层的横向瓦片数
	 */
	int m_layerWidth;

	/**
	 * 层的纵向瓦片数
	 */
	int m_layerHeight;

	/**
	 * 瓦片的像素宽度
	 */
	float m_tileWidth;

	/**
	 * 瓦片的像素高度
	 */
	float m_tileHeight;

	/**
	 * 瓦片id数组
	 */
	int* m_tiles;

	/// color of tmx layer
	wyColor4B m_color;

	/**
	 * 最小的瓦片id
	 */
	int m_minGid;

	/**
	 * 最大的瓦片id
	 */
	int m_maxGid;
    
    /// map info
    wyMapInfo* m_mapInfo;

    /// layer info
    wyLayerInfo* m_layerInfo;

	/// info of atlas
	wyTileSetAtlasInfo* m_atlasInfos;
    
    /// sprite batch node array
    wySpriteBatchNode** m_batchNodes;

	/// vertex Z
	bool m_useAutomaticVertexZ;
	float m_vertexZAt;

	/// alpha func value
	float m_alphaFuncValue;

private:
	/**
	 * 遍历atlas索引数组, 对所有大于指定值的索引减1
	 *
     * @param tilesetIndex 图片集索引, 仅当相等时才执行减一操作
	 * @param index 指定的值, 大于这个值的索引都要减1
	 */
	void decreaseIndexIfMoreThan(int tilesetIndex, int index);

	/**
	 * 遍历atlas索引数组, 对所有大于等于指定值的索引加1
	 *
     * @param tilesetIndex 图片集索引, 仅当相等时才执行加一操作
	 * @param index 指定的值, 大于等于这个值的索引都要加1
	 */
	void increaseIndexIfEqualOrMoreThan(int tilesetIndex, int index);

protected:
	/**
	 * 得到正交型瓦片的左下角位置
	 *
	 * @param posX 瓦片坐标的列位置
	 * @param posY 瓦片坐标的行位置
	 * @return 瓦片的左下角像素位置, 相对于layer来说
	 */
	wyPoint getPositionForOrthoAt(int posX, int posY);

	/**
	 * 得到等角型瓦片的左下角位置
	 *
	 * @param posX 瓦片坐标的列位置
	 * @param posY 瓦片坐标的行位置
	 * @return 瓦片的左下角像素位置, 相对于layer来说
	 */
	wyPoint getPositionForIsoAt(int posX, int posY);

	/**
	 * 得到六边型瓦片的左下角位置
	 *
	 * @param posX 瓦片坐标的列位置
	 * @param posY 瓦片坐标的行位置
	 * @return 瓦片的左下角像素位置, 相对于layer来说
	 */
	wyPoint getPositionForHexAt(int posX, int posY);

	/**
	 * 得到瓦片的顶点z值
	 *
	 * @param x 瓦片坐标的列位置
	 * @param y 瓦片坐标的行位置
	 * @return 瓦片的顶点z值
	 */
	float getVertexZAt(int x, int y);

	/**
	 * 追加一个瓦片
	 *
     * @param tilesetIndex 这个瓦片所在的图片集索引
	 * @param gid 瓦片id
	 * @param x 瓦片列位置
	 * @param y 瓦片行位置
	 */
	void appendTileForGid(int tilesetIndex, int gid, int x, int y);
    
    /**
     * Set a tile, internal called
     * 
     * @param tilesetIndex index of tileset
     * @param gid tile id
     * @param x tile x position
     * @param y tile y position
     * @param z atlas info position
     */
    void setTileAt(int tilesetIndex, int gid, int x, int y, int z);

	/**
	 * 解析TMX文件中的一些内部属性
	 */
	void parseInternalProperties();

	/**
	 * 计算层相对于地图节点的实际像素偏移
	 *
	 * @param x TMX描述文件中的x偏移
	 * @param y TMX描述文件中的y偏移
	 */
	wyPoint calculateLayerOffset(float x, float y);

	/**
	 * 初始化瓦片id数组
	 */
	void setupTiles();

	/**
	 * update color of tmx layer
	 */
	void updateColor();

protected:
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param layerIndex index of layer, start from zero
	 * @param mapInfo info of whole map
	 * \else
	 * 构造函数
	 *
	 * @param layerIndex 层的序号, 从0开始
	 * @param mapInfo 地图信息对象, \link wyMapInfo wyMapInfo\endlink
	 * \endif
	 */
	wyTMXLayer(int layerIndex, wyMapInfo* mapInfo);

public:
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param layerIndex index of layer, start from zero
	 * @param mapInfo info of whole map
	 * @return \link wyTMXLayer wyTMXLayer\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param layerIndex 层的序号, 从0开始
	 * @param mapInfo 地图信息对象, \link wyMapInfo wyMapInfo\endlink
	 * @return \link wyTMXLayer wyTMXLayer\endlink
	 * \endif
	 */
	static wyTMXLayer* make(int layerIndex, wyMapInfo* mapInfo);

	/// 析构函数
	virtual ~wyTMXLayer();

	/// @see wyNode::getAlpha
	virtual int getAlpha() { return m_color.a; }

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha);

	/// @see wyNode::getColor
	virtual wyColor3B getColor();

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::setColor
	virtual void setColor(wyColor4B color);

	/**
	 * 获得层属性
	 *
	 * @param key 属性关键字
	 * @return 属性值
	 */
	char* getProperty(const char* key);

	/**
	 * 得到层水平方向上的瓦片个数
	 *
	 * @return 层水平方向上的瓦片个数
	 */
	int getLayerWidth() { return m_layerWidth; }

	/**
	 * 得到层垂直方向上的瓦片个数
	 *
	 * @return 层垂直方向上的瓦片个数
	 */
	int getLayerHeight() { return m_layerHeight; }

	/**
	 * 得到瓦片的像素宽度
	 *
	 * @return 瓦片的像素宽度
	 */
	int getTileWidth() { return m_tileWidth; }

	/**
	 * 得到瓦片的像素高度
	 *
	 * @return 瓦片的像素高度
	 */
	int getTileHeight() { return m_tileHeight; }

	/**
	 * 根据一个相对于节点自身的坐标, 找到对应的瓦片坐标
	 *
	 * @param x x坐标, 以TMX layer的左下角为原点
	 * @param y y坐标, 以TMX layer的左下角为原点
	 * @return 瓦片坐标, 以一个\link wyDimension wyDimension\endlink 的形式返回, 如果点击位置处没有对应的瓦片,
	 * 		则会返回(-1, -1)
	 */
	wyDimension getTileCoordinateAt(float x, float y);

	/**
	 * \if English
	 * returns the tile (wySpriteEx) at a given a tile coordinate.
	 * The returned wySpriteEx will be already added to the wyTMXLayer. Don't add it again.
	 * The wySpriteEx can be treated like any other wySpriteEx: rotated, scaled, translated, opacity, color, etc.
	 * You can remove either by calling:
	 * 		layer->removeChild(sprite, true);
	 * 	 or layer->removeTileAt(x, y);
	 *
	 * Tag of returned sprite is set to x + y * layerWidth, don't modify it.
	 *
	 * @param x x coordinate of tile
	 * @param y y coordinate of tile
	 * @return \link wySpriteEx wySpriteEx\endlink object, or NULL if no tile at location
	 * \else
	 * 得到某个瓦片位置的wySpriteEx对象, 并且被加到了wyTMXLayer中. 返回的对象可以进行普通的旋转, 放缩, 移动,
	 * 透明度和颜色等操作. 你可以通过removeTileAt或者removeChild方法删除掉它. 返回的sprite的tag被设置成了
	 * x + y * layerWidth, 不要修改这个tag否则可能造成程序逻辑混乱.
	 *
	 * 对于比较大的地图, 比如100x100, 如果预先创建这些sprite, 则最多可能有10000个, 这在资源上也是不太好的. 因此
	 * 返回的sprite实际上是即时创建的, 如果不需要使用的时候可以考虑删除掉. 删掉sprite的时候可以选择是否保留瓦片.
	 *
	 * @param x 行位置，从左往右数
	 * @param y 列位置，从上往下数
	 * @return \link wySpriteEx wySpriteEx\endlink 对象, 如果瓦片坐标处没有瓦片图片, 则返回NULL
	 * \endif
	 */
	wySpriteEx* tileAt(int x, int y);

	/**
	 * \if English
	 * Remove a tile from a sprite which is got from \c tileAt method. If the sprite
	 * is not a tile sprite, do nothing
	 *
	 * @param sprite sprite which is got from \c tileAt
	 * \else
	 * 通过\link wySpriteEx wySpriteEx\endlink对象删除一个瓦片, 这个sprite对象必须是
	 * 通过\c tileAt方法得到的, 如果不是, 则这个方法不做任何事
	 *
	 * @param sprite 从\c tileAt方法得到的瓦片精灵对象
	 * \endif
	 */
	void removeTile(wySpriteEx* sprite);

	/**
	 * 获得指定行列的瓦片id
	 *
	 * @param x 行位置，从左往右数
	 * @param y 列位置，从上往下数
	 * @return 瓦片id
	 */
	int getGidAt(int x, int y);

	/**
	 * 得到该层所有的瓦片id数组
	 *
	 * @param copy 可选参数, true表示返回一份瓦片id数组的拷贝, 缺省为false
	 * @return 瓦片id数组, 数组的长度是layerWidth * layerHeight.
	 * 		如果想得到某行列的瓦片id, 位置的计算方式是: pos = x + layerWidth * y.
	 * 		如果copy是true, 则调用者要负责释放数组.
	 */
	int* getGids(bool copy = false);

	/**
	 * 删除指定行列的瓦片
	 *
	 * @param x 行位置，从左往右数
	 * @param y 列位置，从上往下数
	 */
	void removeTileAt(int x, int y);

	/**
	 * 在指定行列位置设置瓦片id, 如果指定位置上已经存在瓦片, 则这个方法
	 * 和updateTileAt的功能相同
	 *
	 * @param gid 瓦片id
	 * @param x 行位置，从左往右数
	 * @param y 列位置，从上往下数
	 */
	void setTileAt(int gid, int x, int y);

	/**
	 * 更新某行列位置的瓦片
	 *
	 * @param gid 瓦片id
	 * @param x 行位置，从左往右数
	 * @param y 列位置，从上往下数
	 */
	void updateTileAt(int gid, int x, int y);

	/**
	 * 根据瓦片坐标, 得到这个瓦片的左下角像素坐标, 该坐标是以layer左下角为原点的
	 *
	 * @param x 行位置，从左往右数
	 * @param y 列位置，从上往下数
	 * @return 瓦片相对于layer左下角的左下角像素坐标
	 */
	wyPoint getPositionAt(int x, int y);
};

#endif // __wyTMXLayer_h__
