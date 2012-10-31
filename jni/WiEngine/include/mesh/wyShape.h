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
#ifndef __wyShape_h__
#define __wyShape_h__

#include "wyMesh.h"
#include "WiEngine-Classes.h"

/**
 * @class wyShape
 *
 * A mesh represents a series of lines
 */
class WIENGINE_API wyShape : public wyMesh {
private:
	/// vertex buffer
	wyBuffer* m_buf;

protected:
	wyShape();

public:
	/// create a empty instance of wyShape, no vertex
	static wyShape* make();

	/// clear all vertices
	void clear();

	/**
	 * Fill mesh with one point
	 *
	 * @param x point x
	 * @param y point y
	 */
	void buildPoint(float x, float y);

	/**
	 * Fill mesh with points
	 *
	 * @param p points buffer, x1, y1, x2, y2, ...
	 * @param length count of float, should be point count * 2
	 */
	void buildPoints(float* p, size_t length);

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
	 * Fill mesh with one line
	 *
	 * @param x1 line start x
	 * @param y1 line start y
	 * @param x2 line end x
	 * @param y2 line end y
	 */
	void buildLine(float x1, float y1, float x2, float y2);

	/**
	 * Fill mesh with many connected lines
	 *
	 * @param points the point coordinates, in order (x, y), (x, y), ...
	 * @param length count of float in \c points buffer, should be point count * 2
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

	/**
	 * Fill mesh with many connected dash lines
	 *
	 * @param points the point coordinates, in order (x, y), (x, y), ...
	 * @param length count of float in \c points buffer, should be point count * 2
	 * @param dashLength length of dash line
	 */
	void buildDashPath(float* points, size_t length, float dashLength);

	/**
	 * Fill mesh with a rectangle
	 *
	 * @param p must contains 8 floats
	 */
	void buildRect(float* p);

	/**
	 * Fill mesh with a rectangle
	 *
	 * @param x left bottom corner x
	 * @param y left bottom corner y
	 * @param w rectangle width
	 * @param h rectangle height
	 */
	void buildRect(float x, float y, float w, float h);

	/**
	 * Fill mesh with a solid rectangle
	 *
	 * @param p must contains 8 floats
	 */
	void buildSolidRect(float* p);

	/**
	 * Fill mesh with a solid rectangle
	 *
	 * @param x left bottom corner x
	 * @param y left bottom corner y
	 * @param w rectangle width
	 * @param h rectangle height
	 */
	void buildSolidRect(float x, float y, float w, float h);

	/**
	 * Fill mesh with a solid rect with gradient color
	 *
	 * @param x left bottom corner x
	 * @param y left bottom corner y
	 * @param w rectangle width
	 * @param h rectangle height
	 * @param from from color
	 * @param to to color
	 * @param degree the direction of color changing, from 0 to 360. x axis is 0 degree and positive value means
	 * 		clockwise.
	 */
	void buildGradientRect(float x, float y, float w, float h, wyColor4B from, wyColor4B to, int degree);

	/**
	 * Fill mesh with a poly
	 *
	 * @param p poly vertex buff
	 * @param length length of float, should be vertex count * 2
	 * @param close true means need connect start and end point
	 */
	void buildPoly(float* p, size_t length, bool close);

	/**
	 * Fill mesh with a circle
	 *
	 * @param centerX circle center x
	 * @param centerY circle center y
	 * @param r radius
	 * @param radiusLineAngle angle between radius and x axis, positive value is counter-clockwise
	 * @param segments how many segments, the more it is, the best the circle looks
	 * @param drawLineToCenter true means draw a radius line
	 */
	void buildCircle(float centerX, float centerY, float r, float radiusLineAngle, int segments, bool drawLineToCenter);

	/**
	 * Fill mesh with a poly. The poly is auto closed
	 *
	 * @param p poly vertex buff
	 * @param length length of float, should be vertex count * 2
	 */
	void buildSolidPoly(float* p, size_t length);

	/*
	 * Fill mesh with a solid circle
	 *
	 * @param centerX circle center x
	 * @param centerY circle center y
	 * @param r radius
	 * @param segments segments, the more it is, the more accurate the circle is
	 */
	void buildSolidCircle(float centerX, float centerY, float r, int segments);

	/**
	 * Fill mesh with a custom shape and its vertices and texture coordinates is already populated
	 *
	 * @param vertices vertex array, every 2 elements is a vertex
	 * @param texCoords texture coordinate array
	 * @param vertexCount vertex count
	 * @param mode mesh mode
	 */
	void buildCustom2D(float* vertices, float* texCoords, int vertexCount, Mode mode);

	/**
	 * Only update vertices data. If vertex data in buffer exceeds current, extra part will not be updated
	 * into mesh
	 *
	 * @param vertices vertex data array, every 2 elements is a vertex
	 * @param vertexCount vertex count
	 * @param updateStart start index of first vertex
	 */
	void updateVertices(float* vertices, int vertexCount, int updateStart);

	virtual ~wyShape();

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

	/**
	 * Add a point
	 *
	 * @param x point x value
	 * @param y point y value
	 * @param z point z value
	 * @param c point color
	 */
	void addPoint(float x, float y, float z, wyColor4B c = wyc4bWhite);
};

#endif // __wyShape_h__
