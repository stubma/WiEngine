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
#ifndef __wyTMXTileMap_h__
#define __wyTMXTileMap_h__

#include "wyNode.h"
#include "wyMapInfo.h"
#include "wyHashSet.h"
#include "wyArray.h"
#include "wyTMXLayer.h"
#include "wyTMXObjectGroup.h"

/**
 * @class wyTMXTileMap
 *
 * \if English
 * TMX tile map class. Every layer in TMX map is a \link wyTMXLayer wyTMXLayer\endlink class and
 * also child node of it.
 * \else
 * 这是TMX地图的顶层类, TMX地图中的每一层都是一个\link wyTMXLayer wyTMXLayer\endlink类, 也是它的子节点
 * \endif
 */
class WIENGINE_API wyTMXTileMap : public wyNode {
protected:
	/// map width in tiles
	int m_mapWidth;
    
    /// map height in tiles
	int m_mapHeight;

	/// tiles width in pixels
	float m_tileWidth;
    
    /// tile height in pixels
	float m_tileHeight;
    
    /// map info
    wyMapInfo* m_mapInfo;

    /// true means debug draw object outline
    bool m_debugDrawObjects;

    /// color of tmx map
	wyColor4B m_color;

protected:
	/**
	 * 初始化
	 *
	 * @param map \link wyMapInfo wyMapInfo\endlink
	 * @param textures tileset的贴图列表, 按照tileset在tmx中出现的顺序排列
	 */
	void init(wyMapInfo* map, wyArray* textures);

	/**
	 * update color of tmx rendering
	 */
	void updateColor();

protected:
	wyTMXTileMap();

public:
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param resId tmx file resource id
	 * @param tex1 texture of first tileset, if more than one tileset, append other texture after this and
	 * 		end with NULL
	 * @return \link wyTMXTileMap wyTMXTileMap\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param resId .tmx文件的资源ID
	 * @param tex1 第一个tileset的贴图, 如果有其它tileset, 依次追加贴图对象, 必须按照tileset出
	 * 		现在tmx中的顺序依次出现, 以NULL结尾
	 * @return \link wyTMXTileMap wyTMXTileMap\endlink
	 * \endif
	 */
	static wyTMXTileMap* make(int resId, wyTexture2D* tex1, ...);

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param resId tmx file resource id
	 * @param tex texture list of tileset
	 * @param texCount number of textures
	 * @return \link wyTMXTileMap wyTMXTileMap\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param resId .tmx文件的资源ID
	 * @param tex tileset的贴图列表, 必须按照tileset出现在tmx中的顺序依次出现
	 * @param texCount 贴图个数
	 * @return \link wyTMXTileMap wyTMXTileMap\endlink
	 * \endif
	 */
	static wyTMXTileMap* make(int resId, wyTexture2D** tex, int texCount);

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param path tmx file path
	 * @param isFile true means \c path is an absolute path in file system, or false if \c path
	 * 		is a relative path under assets
	 * @param tex1 texture of first tileset, if more than one tileset, append other texture after this and
	 * 		end with NULL
	 * @return \link wyTMXTileMap wyTMXTileMap\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param path tmx文件的路径
	 * @param isFile true表示path是一个文件系统路径, false表示这是一个assets下的相对路径
	 * @param tex1 第一个tileset的贴图, 如果有其它tileset, 依次追加贴图对象, 以NULL结尾
	 * @return \link wyTMXTileMap wyTMXTileMap\endlink
	 * \endif
	 */
	static wyTMXTileMap* make(const char* path, bool isFile, wyTexture2D* tex1, ...);

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param path tmx file path
	 * @param isFile true means \c path is an absolute path in file system, or false if \c path
	 * 		is a relative path under assets
	 * @param tex texture list of tileset
	 * @param texCount number of textures
	 * @return \link wyTMXTileMap wyTMXTileMap\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param path tmx文件的路径
	 * @param isFile true表示path是一个文件系统路径, false表示这是一个assets下的相对路径
	 * @param tex tileset的贴图列表, 必须按照tileset出现在tmx中的顺序依次出现
	 * @param texCount 贴图个数
	 * @return \link wyTMXTileMap wyTMXTileMap\endlink
	 * \endif
	 */
	static wyTMXTileMap* make(const char* path, bool isFile, wyTexture2D** tex, int texCount);

	/**
	 * 析构函数
	 */	
	virtual ~wyTMXTileMap();

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
	 * \if English
	 * Get map info struct
	 * \else
	 * 得到地图信息数据结构
	 * \endif
	 */
	wyMapInfo* getMapInfo() { return m_mapInfo; }

	/**
	 * 根据名字获得一个layer
	 *
	 * @param[in] name layer的名字 
	 * @return 返回layer的指针, 如没找到返回NULL
	 */
	wyTMXLayer* getLayer(const char* name);
	
	/**
	 * 根据索引得到\link wyTMXLayer wyTMXLayer\endlink
	 *
	 * @param index layer的索引, 从0开始
	 * @return \link wyTMXLayer wyTMXLayer\endlink, 如果索引范围不合法, 返回NULL
	 */
	wyTMXLayer* getLayerAt(int index);

	/**
	 * 根据名字获得一个对象组
	 *
	 * @param[in] name 对象组的名字
	 * @return 返回指向该对象组的指针, 如没找到返回NULL
	 */	
	wyTMXObjectGroup* getObjectGroup(const char* name);

	/**
	 * 获得属性值
	 *
	 * @param[in] name 属性名 
	 * @return 该属性的值, 如没找到返回NULL
	 */
	char* getProperty(const char* name);
	
	/**
	 * 获得瓦片的属性
	 *
	 * @param[in] gid 瓦片ID	 
	 * @param[in] name 属性名 
	 * @return 返回属性值, 如没找到返回NULL
	 */	
	char* getTileProperty(int gid, const char* name);

	/**
	 * 获得地图宽度
	 *
	 * @return X方向上的瓦片个数
	 */
	int getMapWidth() { return m_mapWidth; }
	
	/**
	 * 获得地图高度
	 *
	 * @return Y方向上的瓦片个数
	 */	
	int getMapHeight() { return m_mapHeight; }
	
	/**
	 * 获得瓦片宽度
	 *
	 * @return 瓦片宽, 单位为像素
	 */	
	float getTileWidth() { return m_tileWidth; }
	
	/**
	 * 获得瓦片高度
	 *
	 * @return 瓦片高, 单位为像素
	 */	
	float getTileHeight() { return m_tileHeight; }
	
	/**
	 * 获得地图方向
	 *
	 * @return 方向
	 */	
	wyTMXOrientation getOrientation() { return m_mapInfo->orientation; }

	/**
	 * \if English
	 * Set to true if you want to render objects outline, for debug purpose.
	 * By default it is false
	 * \else
	 * 设置是否渲染自定义对象的轮廓, 仅用于调试目的. 缺省是false
	 * \endif
	 */
	void setDebugDrawObjects(bool flag);

	/**
	 * \if English
	 * Convert a point from node to TMX coordinate space
	 *
	 * @param p point in node space
	 * @return point in TMX space
	 * \else
	 * 把一个点的坐标从节点空间转换到TMX空间
	 *
	 * @param p 要转换的点
	 * @return 转换到TMX空间后的点
	 * \endif
	 */
	wyPoint nodeToTMXSpace(wyPoint p);

	/**
	 * \if English
	 * Convert a point from TMX to node coordinate space
	 *
	 * @param p point in TMX space
	 * @return point in node space
	 * \else
	 * 把一个点的坐标从TMX空间转换到节点空间
	 *
	 * @param p 要转换的点
	 * @return 转换到节点空间后的点
	 * \endif
	 */
	wyPoint tmxToNodeSpace(wyPoint p);
};

#endif // __wyTMXTileMap_h__
