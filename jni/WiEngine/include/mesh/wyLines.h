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
#ifndef __wyLines_h__
#define __wyLines_h__

#include "wyMesh.h"
#include "WiEngine-Classes.h"

/**
 * @class wyLines
 *
 * A mesh represents a series of lines
 */
class WIENGINE_API wyLines : public wyMesh {
private:
	/// vertex buffer
	wyBuffer* m_buf;

protected:
	wyLines();

public:
	/// create a empty instance of wyLines, no vertex
	static wyLines* make();

	/**
	 * Fill mesh with a bezier curve
	 *
	 * @param c \link wyBezierConfig wyBezierConfig\endlink
	 * @param segments how many segments drawn for the bezier curve
	 */
	void buildBezier(wyBezierConfig& c, int segments);

	/**
	 * Fill mesh with a lagrange curve
	 *
	 * @param c \link wyLagrangeConfig wyLagrangeConfig\endlink
	 * @param segments how many segments drawn for the lagrange curve
	 */
	void buildLagrange(wyLagrangeConfig& c, int segments);

	/**
	 * Fill mesh with a hypotrochoid curve
	 *
	 * @param c \link wyHypotrochoidConfig wyHypotrochoidConfig\endlink
	 * @param segments how many segments drawn for the hypotrochoid curve
	 */
	void buildHypotrochoid(wyHypotrochoidConfig& c, int segments);

	/**
	 * Fill mesh with many connected lines
	 *
	 * @param points the point coordinates, in order (x, y, z), (x, y, z), ...
	 * @param length count of float in \c points buffer, should be point count * 3
	 */
	void buildPath(float* points, size_t length);

	/**
	 * Fill mesh with dash lines
	 *
	 * @param x1 start x
	 * @param y1 start y
	 * @param x2 end x
	 * @param y2 end y
	 * @param dashLength dash length
	 */
	void buildDashLine(float x1, float y1, float x2, float y2, float dashLength);

	virtual ~wyLines();

	/// @see wyMesh::getElementCount()
	virtual int getElementCount();

	/**
	 * Update color info
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 */
	void updateColor(wyColor4B color);

	/**
	 * Update one vertex
	 *
	 * @param index index of vertex, if index is invalid, do nothing
	 * @param x new x coordinate
	 * @param y new y coordinate
	 * @param z new z coordinate
	 */
	void updateVertex(int index, float x, float y, float z);
};

#endif // __wyLines_h__
