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
#ifndef __wyGrid3DAction_h__
#define __wyGrid3DAction_h__

#include "wyGridAction.h"
#include "wyTypes.h"

/**
 * @class wyGrid3DAction
 * \if English
 * base class of classes which use grid of \link wyGrid3D wyGrid3D\endlink to implement a specific effect,
 * such as \link wyLens3D wyLens3D\endlink
 * \else
 * 3维网格动作的基类
 * \endif
 */
class WIENGINE_API wyGrid3DAction : public wyGridAction {
public:
	/**
	 * \if English
	 * constructor
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * \endif
	 */
	wyGrid3DAction(float duration, float gridX, float gridY);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyGrid3DAction();

	/// @see wyGridAction::makeGrid
	virtual wyBaseGrid* makeGrid();

	/// @see wyGridAction::getGridClass
	virtual bool isGridReusable(wyBaseGrid* grid);

	/**
	 * \if English
	 * get the vertex information of a target grid unit
	 *
	 * @param pos target grid unit's coordinates.
	 * \else
	 * 获取某位置的顶点坐标
	 *
	 * @param pos 点的行列坐标\link wyDimension wyDimension结构\endlink
	 * \endif
	 */
	wyVertex3D getVertex(wyDimension pos);

	/**
	 * \if English
	 * get the original vertex information of a target grid unit
	 *
	 * @param pos target grid unit's coordinates.
	 * \else
	 * 获取某位置的初始顶点坐标
	 *
	 * @param pos 点的行列坐标\link wyDimension wyDimension结构\endlink
	 * \endif
	 */
	wyVertex3D getOriginalVertex(wyDimension pos);

	/**
	 * \if English
	 * set the vertex of a target grid unit
	 * @param pos the target grid unit's coordinates
	 * @param vertex the new vertex of the target grid unit \link wyVertex3D wyVertex3D\endlink
	 * \else
	 * 设置某位置的顶点坐标
	 *
	 * @param pos 点的行列坐标\link wyDimension wyDimension结构\endlink
	 * @param vertex \link wyVertex3D wyVertex3D结构\endlink
	 * \endif
	 */
	void setVertex(wyDimension pos, wyVertex3D vertex);
};

#endif // __wyGrid3DAction_h__
