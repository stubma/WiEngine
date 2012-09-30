/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

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
 * @class wyTiledGrid3D
 *
 * \if English
 * A type of grid which is operated in tiles. Take a grid of 2x2 for example, this grid consists of
 * 4 rectangles(also named tiles). Not like wyGrid3D, its effects is not consistent, the images looks
 * composed of many fragments.
 * \else
 * 平铺式网格。操作单位是矩形块。假如一个网格的行列是2x2，那么这个网格
 * 就有4个矩形块(也叫做Tile)。由于操作单位是块而不是点，所以做特效时，
 * 可能会产生破碎的感觉，图象之间不再是严丝合缝，而是可能分裂开来，这是和wyGrid3D的不同之处
 * \endif
 */
class WIENGINE_API wyTiledGrid3D : public wyBaseGrid {
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
	wyTiledGrid3D(float w, float h, int c, int r);

public:
	/**
	 * \if English
	 * Create a tiled 3d grid
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 * \else
	 * 创建一个平铺型3d网格
	 *
	 * @param w 网格总宽度
	 * @param h 网格总高度
	 * @param c 网格列数
	 * @param r 网格行数
	 * \endif
	 */
	static wyTiledGrid3D* make(float w, float h, int c, int r);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyTiledGrid3D();

	/// @see wyBaseGrid::blit
	virtual void blit();

	/// @see wyBaseGrid::reuse
	virtual void reuse();

	/**
	 * \if English
	 * set tile coordinates of a grid unit
	 *
	 * @param pos specify which unit is to be operated. \link wyDimension wyDimension\endlink
	 * @param coords the new tile coordinates. \link wyQuad3D wyQuad3D\endlink
	 * \else
	 * 设置某位置的矩形块坐标，因为矩形由4个点决定，所以使用的是 \link wyQuad3D wyQuad3D结构\endlink
	 *
	 * @param pos 矩形块的行列坐标\link wyDimension wyDimension结构\endlink
	 * @param coords \link wyQuad3D wyQuad3D结构\endlink
	 * \endif
	 */
	void setTile(wyDimension pos, wyQuad3D coords);

	/**
	 * \if English
	 * get tile coordinates of a grid unit
	 *
	 * @param pos specify which unit is to be operated.
	 * @return the tile coordinates
	 * \else
	 * 得到某个位置的矩形块坐标
	 *
	 * @param pos 矩形块的行列坐标
	 * @return \link wyQuad3D wyQuad3D结构\endlink
	 * \endif
	 */
	wyQuad3D getTile(wyDimension pos);

	/**
	 * \if English
	 * get the initial tile coordinates of a grid unit
	 *
	 * @param pos specify which unit is to be operated.
	 * @return the tile coordinates
	 * \else
	 * 得到某个位置的矩形块原始坐标
	 *
	 * @param pos 矩形块的行列坐标\link wyDimension wyDimension结构\endlink
	 * @return \link wyQuad3D wyQuad3D结构\endlink
	 * \endif
	 */
	wyQuad3D getOriginalTile(wyDimension pos);
};

#endif // __wyTiledGrid3D_h__
