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
#ifndef __wyTMXObject_h__
#define __wyTMXObject_h__

#include "wyObject.h"
#include "wyTypes.h"

class wyTMXLoader;

/**
 * @class wyTMXObject
 *
 * Object in TMX object group
 */
class WIENGINE_API wyTMXObject : public wyObject {
	friend class wyTMXLoader;

public:
	/**
	 * Object type
	 */
	enum Type {
		/**
		 * Normal object, just a collection of key-value pairs
		 */
		NORMAL,

		/**
		 * Polygon object, can get vertex points
		 */
		POLYGON,

		/**
		 * Polyline object, first and last point is not connected
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
	 * Get a property value by a key
	 *
	 * @param key key string
	 * @return value string, or NULL if not found. caller should NOT release it
	 */
	const char* getProperty(const char* key);

	/**
	 * Add a property
	 *
	 * @param key key string, it will be copied so you can release it after returns
	 * @param value value string, it will be copied so you can release it after returns
	 */
	void addProperty(const char* key, const char* value);

	/**
	 * A quick way to get object position
	 *
	 * @return position, in tmx map coordinates based on map type
	 */
	wyPoint getPosition();

	/**
	 * A quick way to get object size, but not all objects have a size
	 *
	 * @return size of object
	 */
	wySize getSize();

	/**
	 * Get object type
	 */
	Type getType() { return m_type; }

	/**
	 * Get point list, only used for POLYGON or POLYLINE object
	 *
	 * @return \link wyPointList wyPointList\endlink
	 */
	wyPointList& getPoints() { return m_points; }
};

#endif // __wyTMXObject_h__
