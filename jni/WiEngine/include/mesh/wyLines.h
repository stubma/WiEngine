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
	/**
	 * Create a bezier curve lines mesh
	 *
	 * @param c \link wyBezierConfig wyBezierConfig\endlink
	 * @param segments how many segments drawn for the bezier curve
	 * @return \link wyLines wyLines\endlink
	 */
	static wyLines* makeBezier(wyBezierConfig& c, int segments);

	/**
	 * Create a lagrange curve mesh
	 *
	 * @param c \link wyLagrangeConfig wyLagrangeConfig\endlink
	 * @param segments how many segments drawn for the lagrange curve
	 * @return \link wyLines wyLines\endlink
	 */
	static wyLines* makeLagrange(wyLagrangeConfig& c, int segments);

	/**
	 * Create a hypotrochoid curve mesh
	 *
	 * @param c \link wyHypotrochoidConfig wyHypotrochoidConfig\endlink
	 * @param segments how many segments drawn for the hypotrochoid curve
	 * @return \link wyLines wyLines\endlink
	 */
	static wyLines* makeHypotrochoid(wyHypotrochoidConfig& c, int segments);

	/**
	 * Create a mesh contains many connected lines
	 *
	 * @param points the point coordinates, in order (x, y, z), (x, y, z), ...
	 * @param length count of float in \c points buffer, should be point count * 3
	 * @return \link wyLines wyLines\endlink
	 */
	static wyLines* makePath(float* points, size_t length);

	virtual ~wyLines();

	/// @see wyMesh::getElementCount()
	virtual int getElementCount();

	/**
	 * Update color info
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 */
	void updateColor(wyColor4B color);
};

#endif // __wyLines_h__
