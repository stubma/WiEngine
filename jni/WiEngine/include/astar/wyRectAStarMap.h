/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: mike(mike.weib@gmail.com)
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
#ifndef __wyRectAStarMap_h__
#define __wyRectAStarMap_h__

#include "wyAStarMap.h"
#include "wyAStarTile.h"

/**
 * @class wyRectAStarMap
 *
 * A*矩形地图状况tile封装
 */
class WIENGINE_API wyRectAStarMap : public wyAStarMap {
private:
	/// 横向tile数量
	int m_width;

	/// 纵向tile数量
	int m_height;

	/// true indicating diagonal path will be searched
	bool m_isAllowDiagonal;

public:
	/**
	 * 构造函数
	 *
	 * @param width 横向tile数量
	 * @param height 纵向tile数量
	 * @param isAllowDiagonal 是否允许斜线查找, true为允许
	 */
	wyRectAStarMap(int width, int height, bool isAllowDiagonal);

	/**
	 * 析构函数
	 */
	virtual ~wyRectAStarMap();

	/// @see wyAStarMap::validTile
	virtual bool isValidTile(int x, int y);

	/// @see wyAStarMap::getStepG
	virtual float getStepG(wyAStarTile* t1, wyAStarTile* t2);
};

#endif // __wyRectAStarMap_h__
