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
#ifndef __wyGrid3D_h__
#define __wyGrid3D_h__

#include "wyBaseGrid.h"
#include "wyTypes.h"

/**
 * Grid3D是以点为操作单位的一种网格，比如说网格的大小设置成2行2列，那么从点的角度看应该是每行每列都有
 * 3个点，因此实际总共有9个点。而Grid3D的主要操作就针对这9个点来进行。因为操作是针对点进行的，因此
 * 产生的效果具有视觉上的连续性，虽然图象可能出现扭曲变形，但是并不会分裂开，这是和TileGrid3D的主要区别。
 */
class WIENGINE_API wyGrid3D : public wyBaseGrid {
private:
	/// backup buffer
	wyBuffer* m_backup;

private:
	void calculateVertexPoints();

protected:
	/**
	 * constructor
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 */
	wyGrid3D(float w, float h, int c, int r);

public:
	/**
	 * Create a 3d grid
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 */
	static wyGrid3D* make(float w, float h, int c, int r);

	virtual ~wyGrid3D();

	/// @see wyBaseGrid::reuse
	virtual void reuse();

	/// @see wyMesh::getElementCount
	virtual int getElementCount() { return m_buf->getElementCount(); }

	/**
	 * set vertex of a grid unit
	 *
	 * @param pos unit coordinates, \link wyDimension wyDimension\endlink
	 * @param vertex  the new vertex value of unit, \link wyVertex3D wyVertex3D \endlink
	 */
	void setVertex(wyDimension pos, wyVertex3D vertex);

	/**
	 * get vertex of a grid unit
	 *
	 * @param pos unit coordinates, \link wyDimension wyDimension\endlink
	 */
	wyVertex3D getVertex(wyDimension pos);

	/**
	 * get the initial vertex of a grid unit
	 *
	 * @param pos unit coordinates, \link wyDimension wyDimension\endlink
	 */
	wyVertex3D getOriginalVertex(wyDimension pos);
};

#endif // __wyGrid3D_h__
