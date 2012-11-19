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
#ifndef __wyGridController_h__
#define __wyGridController_h__

#include <stdbool.h>
#include "wyGlobal.h"
#include "wyBaseGrid.h"
#include "WiEngine-Classes.h"

/**
 * @class wyGridController
 *
 * Grid controller which manages grid render process
 */
class WIENGINE_API wyGridController : public wyObject {
protected:
	/// flag indicating whether the grid is active
	bool m_active;

	/// flag indicating whether the grid can be reused
	int m_reuseGrid;

	/// used to capture the current screenshot to a texture, see \link wyFrameBuffer wyFrameBuffer\endlink
	wyFrameBuffer* m_fb;

	/// grid mesh
	wyBaseGrid* m_mesh;

protected:
	/**
	 * Constructor
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 */
	wyGridController(float w, float h, int c, int r);

public:
	/**
	 * Create a controller with a 3D grid mesh
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 * @return \link wyGridController wyGridController\endlink
	 */
	static wyGridController* make3D(float w, float h, int c, int r);

	/**
	 * Create a controller with a tiled 3D grid mesh
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 * @return \link wyGridController wyGridController\endlink
	 */
	static wyGridController* makeTiled3D(float w, float h, int c, int r);

	virtual ~wyGridController();

	/// reuse this grid, a common scenario is recover this grid to its initial status
	void reuse();

	/// this function is called before node's draw function is called
	void beforeDraw();

	/**
	 * this function is called after node is rendered
	 *
	 * @param node the target node object which the current grid is applied on, \link wyNode wyNode\endlink
	 */
	void afterDraw(wyNode* node);

	/**
	 * add the count how much times the grid can be reused
	 *
	 * @param add the count to be added
	 */
	void addReuseCount(int add) { m_reuseGrid += add; }

	/**
	 * check whether the grid can be reused
	 *
	 * @return true means grid can be reused
	 */
	bool isReuseGrid() { return m_reuseGrid > 0; }

	/**
	 * acitvate or deactivate the grid
	 */
	void setActive(bool flag);

	/**
	 * get whether the grid is active
	 *
	 * @return true means active
	 */
	bool isActive() { return m_active; }

	/**
	 * get width of a single grid unit
	 *
	 * @return width of grid unit
	 */
	float getStepWidth() { return m_mesh->getStepWidth(); }

	/**
	 * get height of a single grid unit
	 *
	 * @return height of grid unit
	 */
	float getStepHeight() { return m_mesh->getStepHeight(); }

	/**
	 * get row count
	 *
	 * @return row count
	 */
	int getGridX() { return m_mesh->getGridX(); }

	/**
	 * get column count
	 *
	 * @return column count
	 */
	int getGridY() { return m_mesh->getGridY(); }

	/**
	 * set the width of the whole grid
	 *
	 * @param x the width of the whole grid, in pixels
	 */
	void setGridX(int x) { m_mesh->setGridX(x); }

	/**
	 * set the height of the whole grid
	 *
	 * @param y the height of the whole grid, in pixels
	 */
	void setGridY(int y) { m_mesh->setGridY(y); }

	/// get grid mesh
	wyBaseGrid* getMesh() { return m_mesh; }
};

#endif // __wyGridController_h__
