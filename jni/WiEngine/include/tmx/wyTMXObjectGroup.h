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
#ifndef __wyTMXObjectGroup_h__
#define __wyTMXObjectGroup_h__

#include "wyHashSet.h"
#include "wyObject.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyTMXObject.h"

/**
 * @class wyTMXObjectGroup
 *
 * \if English
 * Object group in TMX map, also known as object layer
 * \else
 * TMX地图中的对象组, 或者叫对象层
 * \endif
 */
class WIENGINE_API wyTMXObjectGroup : public wyObject {
private:
	/**
	 * \if English
	 * name of object group
	 * \else
	 * 对象组的名称
	 * \endif
	 */
	const char* m_name;

	/**
	 * \if English
	 * x offset of object group
	 * \else
	 * 对象组在地图中的像素偏移x值
	 * \endif
	 */
	float m_offsetX;

	/**
	 * \if English
	 * y offset of object group
	 * \else
	 * 对象组在地图中的像素偏移y值
	 * \endif
	 */
	float m_offsetY;

	/**
	 * \if English
	 * object list, every object is a \link wyTMXObject wyTMXObject\endlink object
	 * \else
	 * 对象数组，每个对象是一个\link wyTMXObject wyTMXObject\endlink
	 * \endif
	 */
	vector<wyTMXObject*>* m_objects;

	/**
	 * \if English
	 * properties of object group
	 * \else
	 * 对象组自身的属性map
	 * \endif
	 */
	wyHashSet* m_properties;

	/**
	 * \if English
	 * color of object group
	 * \else
	 * 对象组的颜色属性, 格式是0xaarrggbb, 其中透明度字段总是ff
	 * \endif
	 */
	int m_color;

	/**
	 * \if English
	 * opacity of object group
	 * \else
	 * 透明度属性
	 * \endif
	 */
	float m_opacity;

protected:
	wyTMXObjectGroup();

public:
	virtual ~wyTMXObjectGroup();
	static wyTMXObjectGroup* make();

	/**
	 * \if English
	 * Add property to object group
	 *
	 * @param key property name
	 * @param value property value
	 * \else
	 * 添加ObectGroup属性，如属性已存在，则不操作。
	 *
	 * @param key 属性名
	 * @param value 属性值
	 * \endif
	 */
	void addProperty(const char* key, const char* value);

	/**
	 * \if English
	 * Query property of object group
	 *
	 * @param name property name
	 * @return property value, or NULL if not found
	 * \else
	 * 查询ObectGroup的属性值
	 *
	 * @param name 属性名
	 * @return 返回属性名name的值，如无此属性则返回NULL。
	 * \endif
	 */
	const char* getProperty(const char* name);

	/**
	 * \if English
	 * Create a new \link wyTMXObject wyTMXObject\endlink in object group
	 *
	 * @return \link wyTMXObject wyTMXObject\endlink
	 * \else
	 * 在ObectGroup中新建一个Object
	 *
	 * @return 返回新建对象的指针，对象类型为 \link wyTMXObject wyTMXObject \endlink。
	 * \endif
	 */
	wyTMXObject* newObject();

	/**
	 * \if English
	 * Get object by name
	 *
	 * @param name object name
	 * @return \link wyTMXObject wyTMXObject\endlink, or NULL if not found
	 * \else
	 * 根据名字获得ObectGroup的一个对象
	 *
	 * @param name 对象的名字
	 * @return 返回该对象，如没找到则返回NULL。
	 * \endif
	 */
	wyTMXObject* getObject(const char* name);

	/**
	 * \if English
	 * Get object at specified index. If an object doesn't have a name, we can get it
	 * by index. The index increases from zero and follow the order in TMX.
	 *
	 * @param index index of object
	 * @return \link wyTMXObject wyTMXObject\endlink, or NULL if index is invalid
	 * \else
	 * 根据索引获得对象, 如果一个对象没有名字, 可以用这个方式得到对象. 对象的索引按照它们
	 * 在tmx中出现的顺序从0开始
	 *
	 * @param index 对象索引
	 * @return 对象, 如果索引不合法则返回NULL
	 * \endif
	 */
	wyTMXObject* getObjectAt(int index);

	/**
	 * \if English
	 * Get object count in object group
	 *
	 * @return object count
	 * \else
	 * 得到对象的个数
	 *
	 * @return 对象个数
	 * \endif
	 */
	int getObjectCount() { return m_objects->size(); }

	/**
	 * \if English
	 * Add property to object
	 *
	 * @param object \link wyTMXObject wyTMXObject\endlink
	 * @param key property key
	 * @param value property value
	 * \else
	 * 添加Object属性
	 *
	 * @param object  要操作的object指针
	 * @param key 属性键值
	 * @param value 属性值
	 * \endif
	 */
	void addObjectProperty(wyTMXObject* object, const char* key, const char* value);

	/**
	 * \if English
	 * Query property of object
	 *
	 * @param object \link wyTMXObject wyTMXObject\endlink
	 * @param key property key
	 * @return property value, or NULL if not found
	 * \else
	 * 查询object属性值
	 *
	 * @param object  指针，指定朝哪个Object添加
	 * @param key 属性名
	 * @return 返回属性值，如没找到则返回NULL
	 * \endif
	 */
	const char* getObjectProperty(wyTMXObject* object, const char* key);

	/**
	 * \if English
	 * Set object group name
	 *
	 * @param name name string, the string will be copied so it is safe to release it after method returns
	 * \else
	 * 设置对象组名称
	 *
	 * @param name 名称, 其内容会被拷贝, 因此setName返回后可以释放该指针
	 * \endif
	 */
	void setName(const char* name);

	/**
	 * \if English
	 * Get object group name
	 *
	 * @return name, caller should not release it
	 * \else
	 * 得到对象组名称
	 *
	 * @return 名称字符串, 调用者不需要释放
	 * \endif
	 */
	const char* getName() { return m_name; }

	/**
	 * \if English
	 * Set offset x
	 *
	 * @param x x offset
	 * \else
	 * 设置对象组在地图中的像素偏移x值
	 *
	 * @param x x偏移值
	 * \endif
	 */
	void setOffsetX(float x) { m_offsetX = x; }

	/**
	 * \if English
	 * Get offset x
	 *
	 * @return x offset
	 * \else
	 * 得到对象组在地图中的像素偏移x值
	 *
	 * @return x便宜值
	 * \endif
	 */
	float getOffsetX() { return m_offsetX; }

	/**
	 * \if English
	 * Set offset y
	 *
	 * @param y y offset
	 * \else
	 * 设置对象组在地图中的像素偏移y值
	 *
	 * @param y y偏移值
	 * \endif
	 */
	void setOffsetY(float y) { m_offsetY = y; }

	/**
	 * \if English
	 * Get offset y
	 *
	 * @return y offset
	 * \else
	 * 得到对象组在地图中的像素偏移y值
	 *
	 * @return y便宜值
	 * \endif
	 */
	float getOffsetY() { return m_offsetY; }

	/**
	 * \if English
	 * Set color
	 *
	 * @param color color, format is 0xaarrggbb
	 * \else
	 * 设置颜色
	 *
	 * @param color 颜色值, 格式0xaarrggbb
	 * \endif
	 */
	void setColor(int color) { m_color = color; }

	/**
	 * \if English
	 * Get color
	 *
	 * @return color in 0xaarrggbb format
	 * \else
	 * 得到颜色属性
	 *
	 * @return 颜色
	 * \endif
	 */
	int getColor() { return m_color; }

	/**
	 * \if English
	 * Get opacity
	 *
	 * @return opacity property of object group, from 0 to 1
	 * \else
	 * 得到透明度属性
	 *
	 * @return 透明度属性, 从0到1
	 * \endif
	 */
	float getOpacity() { return m_opacity; }

	/**
	 * \if English
	 * Set opacity
	 *
	 * @param opacity opacity property, from 0 to 1
	 * \else
	 * 设置透明度属性
	 *
	 * @param opacity 透明度, 从0到1
	 * \endif
	 */
	void setOpacity(float opacity) { m_opacity = MIN(1, MAX(0, opacity)); }
};

#endif // __wyTMXObjectGroup_h__
