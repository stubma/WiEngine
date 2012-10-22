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
#ifndef __wyBaseGrid_h__
#define __wyBaseGrid_h__

#include "wyMesh.h"
#include "WiEngine-Classes.h"

/**
 * Grid mesh base class
 */
class WIENGINE_API wyBaseGrid : public wyMesh {
protected:
	/// vertex buffer
	wyBuffer* m_buf;

	/// indices buffer
	wyBuffer* m_indices;

	/// row count
	int m_gridX;

	/// column count
	int m_gridY;

	/// grid pixel width
	float m_width;

	/// grid pixel height
	float m_height;

	/// width of a single grid unit
	float m_stepWidth;

	/// height of a single grid unit
	float m_stepHeight;

protected:
	/**
	 * constructor
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 */
	wyBaseGrid(float w, float h, int c, int r);

public:
	virtual ~wyBaseGrid();

	/// reset grid mesh so it looks like a new grid and can be re-used
	virtual void reuse() = 0;

	/**
	 * get width of a single grid unit
	 *
	 * @return width of grid unit
	 */
	float getStepWidth() { return m_stepWidth; }

	/**
	 * get height of a single grid unit
	 *
	 * @return height of grid unit
	 */
	float getStepHeight() { return m_stepHeight; }

	/**
	 * get row count
	 *
	 * @return row count
	 */
	int getGridX() { return m_gridX; }

	/**
	 * get column count
	 *
	 * @return column count
	 */
	int getGridY() { return m_gridY; }

	/**
	 * set the width of the whole grid
	 *
	 * @param x the width of the whole grid, in pixels
	 */
	void setGridX(int x) { m_gridX = x; }

	/**
	 * set the height of the whole grid
	 *
	 * @param y the height of the whole grid, in pixels
	 */
	void setGridY(int y) { m_gridY = y; }
};

#endif // __wyBaseGrid_h__
