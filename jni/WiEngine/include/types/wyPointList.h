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
#ifndef __wyPointList_h__
#define __wyPointList_h__

/**
 * @struct wyPointList
 *
 * Maintain a buffer of points
 */
class WIENGINE_API wyPointList {
private:
	/**
	 * point buffer
	 */
	wyPoint* m_buffer;

	/**
	 * point count
	 */
	int m_count;

	/**
	 * capacity of buffer, in point, not bytes
	 */
	int m_capacity;

public:
	wyPointList();
	virtual ~wyPointList();

	/**
	 * Add a point
	 */
	void addPoint(float x, float y);

	/**
	 * Add a point
	 */
	void addPoint(wyPoint p) { addPoint(p.x, p.y); }

	/**
	 * Add all points from another point list
	 *
	 * @param plist point list to be copied from
	 */
	void addPoints(wyPointList& plist);

	/**
	 * delete point at given index
	 */
	void deletePointAt(int index);

	/**
	 * Get point buffer
	 */
	wyPoint* getBuffer() { return m_buffer; }

	/**
	 * Get point count
	 */
	int getCount() { return m_count; }

	/**
	 * Clear all points
	 */
	void clear();

	/**
	 * Get point at given index
	 *
	 * @param index point index
	 * @return \link wyPoint wyPoint\endlink
	 */
	wyPoint getPointAt(int index);
};

#endif // __wyPointList_h__
