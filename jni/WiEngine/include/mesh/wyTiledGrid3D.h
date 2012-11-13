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
#ifndef __wyTiledGrid3D_h__
#define __wyTiledGrid3D_h__

#include "wyBaseGrid.h"
#include "wyTypes.h"

/**
 * 平铺式网格。操作单位是矩形块。假如一个网格的行列是2x2，那么这个网格
 * 就有4个矩形块(也叫做Tile)。由于操作单位是块而不是点，所以做特效时，
 * 可能会产生破碎的感觉，图象之间不再是严丝合缝，而是可能分裂开来，这是和wyGrid3D的不同之处
 */
class WIENGINE_API wyTiledGrid3D : public wyBaseGrid {
private:
	/// backup buffer
	wyBuffer* m_backup;

protected:
	/**
	 * constructor
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 */
	wyTiledGrid3D(float w, float h, int c, int r);

public:
	/**
	 * Create a tiled 3d grid
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 */
	static wyTiledGrid3D* make(float w, float h, int c, int r);

	virtual ~wyTiledGrid3D();

	/// @see wyBaseGrid::reuse
	virtual void reuse();

	/// @see wyMesh::getElementCount
	virtual int getElementCount() { return m_buf->getElementCount(); }

	/// @see wyMesh::update
	virtual void update();

	/// @see wyMesh::updateColor4B
	virtual void updateColor4B(wyColor4B color);

	/**
	 * set tile coordinates of a grid unit
	 *
	 * @param pos specify which unit is to be operated. \link wyDimension wyDimension\endlink
	 * @param coords the new tile coordinates. \link wyQuad3D wyQuad3D\endlink
	 */
	void setTile(wyDimension pos, wyQuad3D coords);

	/**
	 * get tile coordinates of a grid unit
	 *
	 * @param pos specify which unit is to be operated.
	 * @return the tile coordinates
	 */
	wyQuad3D getTile(wyDimension pos);

	/**
	 * get the initial tile coordinates of a grid unit
	 *
	 * @param pos specify which unit is to be operated.
	 * @return the tile coordinates
	 */
	wyQuad3D getOriginalTile(wyDimension pos);
};

#endif // __wyTiledGrid3D_h__
