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
#ifndef __wyTMXObject_h__
#define __wyTMXObject_h__

#include "wyObject.h"
#include "wyTypes.h"

class wyTMXLoader;

/**
 * @class wyTMXObject
 *
 * \if English
 * Object in TMX object group
 * \else
 * TMX地图中定义的对象
 * \endif
 */
class WIENGINE_API wyTMXObject : public wyObject {
	friend class wyTMXLoader;

public:
	/**
	 * \if English
	 * Object type
	 * \else
	 * 对象类型
	 * \endif
	 */
	enum Type {
		/**
		 * \if English
		 * Normal object, just a collection of key-value pairs
		 * \else
		 * 普通对象, 只有一些键值对属性
		 * \endif
		 */
		NORMAL,

		/**
		 * \if English
		 * Polygon object, can get vertex points
		 * \else
		 * 多边形对象, 由一系列点描述
		 * \endif
		 */
		POLYGON,

		/**
		 * \if English
		 * Polyline object, first and last point is not connected
		 * \else
		 * 非闭合多边形, 由一系列点描述
		 * \endif
		 */
		POLYLINE
	};

protected:
	/// type
	Type m_type;

	/// key-value properties of object
	map<const char*, const char*, wyStrPredicate>* m_pairs;

	/// point list
	wyPointList m_points;

protected:
	wyTMXObject();

	/// set object type, called by tmx loader
	void setType(Type t) { m_type = t; }

public:
	virtual ~wyTMXObject();
	static wyTMXObject* make();

	/**
	 * \if English
	 * Get a property value by a key
	 *
	 * @param key key string
	 * @return value string, or NULL if not found. caller should NOT release it
	 * \else
	 * 根据键查询对象属性
	 *
	 * @param key 键
	 * @return 属性字符串, NULL表示没找到. 调用者不需要负责释放指针
	 * \endif
	 */
	const char* getProperty(const char* key);

	/**
	 * \if English
	 * Add a property
	 *
	 * @param key key string, it will be copied so you can release it after returns
	 * @param value value string, it will be copied so you can release it after returns
	 * \else
	 * 添加一个属性
	 *
	 * @param key 键, 内容会被拷贝, 所以方法返回后可以释放
	 * @param value 值, 内容会被拷贝, 所以方法返回后可以释放
	 * \endif
	 */
	void addProperty(const char* key, const char* value);

	/**
	 * \if English
	 * A quick way to get object position
	 *
	 * @return position, in tmx map coordinates based on map type
	 * \else
	 * 一个快速得到对象位置的方法
	 *
	 * @return 对象位置, 坐标是相对于tmx地图的, 跟tmx地图类型有关, 比如正交和六角都是以左上角
	 * 		为原点. 而对角是以最上面的菱形的顶点为原点, 且x, y轴都是斜向的.
	 * \endif
	 */
	wyPoint getPosition();

	/**
	 * \if English
	 * A quick way to get object size, but not all objects have a size
	 *
	 * @return size of object
	 * \else
	 * 一个快速得到对象大小的方法, 但不是所有对象都有大小
	 *
	 * @return 对象大小
	 * \endif
	 */
	wySize getSize();

	/**
	 * \if English
	 * Get object type
	 * \else
	 * 得到对象类型
	 * \endif
	 */
	Type getType() { return m_type; }

	/**
	 * \if English
	 * Get point list, only used for POLYGON or POLYLINE object
	 *
	 * @return \link wyPointList wyPointList\endlink
	 * \else
	 * 得到点列表, 如果对象不是POLYGON或POLYLINE则无意义
	 *
	 * @return \link wyPointList wyPointList\endlink
	 * \endif
	 */
	wyPointList& getPoints() { return m_points; }
};

#endif // __wyTMXObject_h__
