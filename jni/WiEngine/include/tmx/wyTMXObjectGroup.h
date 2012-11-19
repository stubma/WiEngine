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
 * Object group in TMX map, also known as object layer
 */
class WIENGINE_API wyTMXObjectGroup : public wyObject {
private:
	/**
	 * name of object group
	 */
	const char* m_name;

	/**
	 * x offset of object group
	 */
	float m_offsetX;

	/**
	 * y offset of object group
	 */
	float m_offsetY;

	/**
	 * object list, every object is a \link wyTMXObject wyTMXObject\endlink object
	 */
	vector<wyTMXObject*>* m_objects;

	/**
	 * properties of object group
	 */
	wyHashSet* m_properties;

	/**
	 * color of object group
	 */
	int m_color;

	/**
	 * opacity of object group
	 */
	float m_opacity;

protected:
	wyTMXObjectGroup();

public:
	virtual ~wyTMXObjectGroup();
	static wyTMXObjectGroup* make();

	/**
	 * Add property to object group
	 *
	 * @param key property name
	 * @param value property value
	 */
	void addProperty(const char* key, const char* value);

	/**
	 * Query property of object group
	 *
	 * @param name property name
	 * @return property value, or NULL if not found
	 */
	const char* getProperty(const char* name);

	/**
	 * Create a new \link wyTMXObject wyTMXObject\endlink in object group
	 *
	 * @return \link wyTMXObject wyTMXObject\endlink
	 */
	wyTMXObject* newObject();

	/**
	 * Get object by name
	 *
	 * @param name object name
	 * @return \link wyTMXObject wyTMXObject\endlink, or NULL if not found
	 */
	wyTMXObject* getObject(const char* name);

	/**
	 * Get object at specified index. If an object doesn't have a name, we can get it
	 * by index. The index increases from zero and follow the order in TMX.
	 *
	 * @param index index of object
	 * @return \link wyTMXObject wyTMXObject\endlink, or NULL if index is invalid
	 */
	wyTMXObject* getObjectAt(int index);

	/**
	 * Get object count in object group
	 *
	 * @return object count
	 */
	int getObjectCount() { return m_objects->size(); }

	/**
	 * Add property to object
	 *
	 * @param object \link wyTMXObject wyTMXObject\endlink
	 * @param key property key
	 * @param value property value
	 */
	void addObjectProperty(wyTMXObject* object, const char* key, const char* value);

	/**
	 * Query property of object
	 *
	 * @param object \link wyTMXObject wyTMXObject\endlink
	 * @param key property key
	 * @return property value, or NULL if not found
	 */
	const char* getObjectProperty(wyTMXObject* object, const char* key);

	/**
	 * Set object group name
	 *
	 * @param name name string, the string will be copied so it is safe to release it after method returns
	 */
	void setName(const char* name);

	/**
	 * Get object group name
	 *
	 * @return name, caller should not release it
	 */
	const char* getName() { return m_name; }

	/**
	 * Set offset x
	 *
	 * @param x x offset
	 */
	void setOffsetX(float x) { m_offsetX = x; }

	/**
	 * Get offset x
	 *
	 * @return x offset
	 */
	float getOffsetX() { return m_offsetX; }

	/**
	 * Set offset y
	 *
	 * @param y y offset
	 */
	void setOffsetY(float y) { m_offsetY = y; }

	/**
	 * Get offset y
	 *
	 * @return y offset
	 */
	float getOffsetY() { return m_offsetY; }

	/**
	 * Set color
	 *
	 * @param color color, format is 0xaarrggbb
	 */
	void setColor(int color) { m_color = color; }

	/**
	 * Get color
	 *
	 * @return color in 0xaarrggbb format
	 */
	int getColor() { return m_color; }

	/**
	 * Get opacity
	 *
	 * @return opacity property of object group, from 0 to 1
	 */
	float getOpacity() { return m_opacity; }

	/**
	 * Set opacity
	 *
	 * @param opacity opacity property, from 0 to 1
	 */
	void setOpacity(float opacity) { m_opacity = MIN(1, MAX(0, opacity)); }
};

#endif // __wyTMXObjectGroup_h__
