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
#ifndef __wyGrid3D_h__
#define __wyGrid3D_h__

#include "wyBaseGrid.h"
#include "wyTypes.h"

/**
 * @class wyBaseGrid
 * \if English
 * Grid3D is a type of grid which is operated in pixels. For example, the grid size is 2x2,
 * the total pixels would be 9 with 3 per row(column). Visually, the effect of this type of
 * grid is consistent, quit different from TileGrid3D whose effect is not consistent.
 * \else
 * Grid3D是以点为操作单位的一种网格，比如说网格的大小设置成2行2列，那么从点的角度看应该是每行每列都有
 * 3个点，因此实际总共有9个点。而Grid3D的主要操作就针对这9个点来进行。因为操作是针对点进行的，因此
 * 产生的效果具有视觉上的连续性，虽然图象可能出现扭曲变形，但是并不会分裂开，这是和TileGrid3D的主要区别。
 * \endif
 */
class WIENGINE_API wyGrid3D : public wyBaseGrid {
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
	 * \if English
	 * Create a 3d grid
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 * \else
	 * 创建一个3d网格
	 *
	 * @param w 网格总宽度
	 * @param h 网格总高度
	 * @param c 网格列数
	 * @param r 网格行数
	 * \endif
	 */
	static wyGrid3D* make(float w, float h, int c, int r);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyGrid3D();

	/// @see wyBaseGrid::blit
	virtual void blit();

	/// @see wyBaseGrid::reuse
	virtual void reuse();

	/**
	 * \if English
	 * set vertex of a grid unit
	 *
	 * @param pos unit coordinates, \link wyDimension wyDimension\endlink
	 * @param vertex  the new vertex value of unit, \link wyVertex3D wyVertex3D \endlink
	 * \else
	 * 设置某位置的顶点坐标
	 *
	 * @param pos 点的行列坐标\link wyDimension wyDimension结构\endlink
	 * @param vertex \link wyVertex3D wyVertex3D结构\endlink
	 * \endif
	 */
	void setVertex(wyDimension pos, wyVertex3D vertex);

	/**
	 * \if English
	 * get vertex of a grid unit
	 *
	 * @param pos unit coordinates, \link wyDimension wyDimension\endlink
	 * \else
	 * 获取某位置的顶点坐标
	 *
	 * @param pos 点的行列坐标\link wyDimension wyDimension结构\endlink
	 * \endif
	 */
	wyVertex3D getVertex(wyDimension pos);

	/**
	 * \if English
	 * get the initial vertex of a grid unit
	 *
	 * @param pos unit coordinates, \link wyDimension wyDimension\endlink
	 * \else
	 * 获取某位置的初始顶点坐标
	 *
	 * @param pos 点的行列坐标\link wyDimension wyDimension结构\endlink
	 * \endif
	 */
	wyVertex3D getOriginalVertex(wyDimension pos);
};


#endif // __wyGrid3D_h__
