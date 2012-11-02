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
#ifndef __wyLineRibbon_h__
#define __wyLineRibbon_h__

#include "wyRibbon.h"
#include "WiEngine-Classes.h"

/**
 * Ribbon in same width, and endpoint is round.
 * If the line width is not explicitly specified, the width of the texture will be used.
 */
class WIENGINE_API wyLineRibbon : public wyRibbon {
private:
	/// line material
	wyMaterial* m_lineMat;

	/// to store the lines
    wyArray* m_lines;

    /// the line width, in pixels
    float m_lineWidth;

private:
    static bool releaseLine(wyArray* arr, void* ptr, int index, void* data);

protected:
    /**
     * constructor
     *
     * @param tex \link wyTexture2D wyTexture2D\endlink
     * @param color \link wyColor4B wyColor4B\endlink
	 */
    wyLineRibbon(wyTexture2D* tex, wyColor4B color);

public:
    /**
     * factory function, used to create a new instance with autoRelease enabled
     *
     * @param tex \link wyTexture2D wyTexture2D\endlink
     * @param color \link wyColor4B wyColor4B\endlink
	 */
    static wyLineRibbon* make(wyTexture2D* tex, wyColor4B color);

    virtual ~wyLineRibbon();

    /// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex, int index = 0);

	/// @see wyNode::updateMesh
	virtual void updateMesh();

    /// @see wyRibbon::update
	virtual void update(float delta);

	/// @see wyRibbon::addPoint
	virtual void addPoint(wyPoint location);

	/// @see wyRibbon::reset
	virtual void reset();

	/**
	 * set line width. If not set, it uses texture height
	 *
	 * @param width the line width, in pixels
	 */
	void setLineWidth(float width);

	/**
	 * get the width of a specified line
	 *
	 * @param index index of the line
	 * @return width of the line, in pixels. 0 returned if index is invalid.
	 */
	float getLineWidth(int index);

	/**
	 * get the color of a specified line
	 *
	 * @param index index of the line
	 * @return \link wyColor4B wyColor4B\endlink
	 */
	wyColor4B getLineColor(int index);

	/**
	 * get the line count
	 */
	int getLineCount() { return m_lines->num; }

	/**
	 * get the point count of a specified line
	 *
	 * @param index index of the line
	 * @return the count, 0 if index is invalid.
	 */
	int getLinePointCount(int index);

	/**
	 * get the array of points of a specified line.
	 *
	 * @param index index of the line
	 * @return array of \link wyPoint wyPoint\endlink, NULL if index is invalid.
	 */
	wyPoint* getLinePointList(int index);
};

#endif // __wyLineRibbon_h__
