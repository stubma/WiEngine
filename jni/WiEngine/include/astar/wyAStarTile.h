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
#ifndef __wyAStarTile_h__
#define __wyAStarTile_h__

#include "wyArray.h"
#include "wyObject.h"

#define TILE_FREE 0
#define TILE_BLOCKED 1

/**
 * @class wyAStarTile
 *
 * A*地图状况tile封装
 */
class WIENGINE_API wyAStarTile : public wyObject {
private:
	/// tile状态, free或者block
	int m_type;

	/// g值得影响值, 默认为１
	float m_gRate;

	/// tile x value
	int m_x;

	/// tile y value
	int m_y;

	/// 子节点\link wyArray wyArray\endlink对象指针, 封装\link wyAStarTile wyAStarTile\endlink对象指针
	wyArray* m_childs;

public:
	/**
	 * 构造函数
	 *
	 * @param type tile状态, free或者block
	 * @param x tile x值
	 * @param y tile y值
	 */
	wyAStarTile(int type, int x, int y);

	/**
	 * 析构函数
	 */
	virtual ~wyAStarTile();

	/**
	 * 返回g值得影响值
	 *
	 * @return g值得影响值
	 */
	float getGRate() { return m_gRate; }

	/**
	 * 设置g值得影响值
	 *
	 * @param gRate g值得影响值
	 */
	void setGRate(float gRate) { m_gRate = gRate; }

	/**
	 * 返回tile x值
	 *
	 * @return tile x值
	 */
	int getX() { return m_x; }

	/**
	 * 返回tile y值
	 *
	 * @return tile y值
	 */
	int getY() { return m_y; }

	/**
	 * 返回tile状态, free或者block
	 *
	 * @return tile状态, free或者block
	 */
	int getType() { return m_type; }

	/**
	 * 设置tile状态, free或者block
	 *
	 * @param type tile状态
	 */
	void setType(int type) { m_type = type; }

	/**
	 * 判断是否为block状态
	 *
	 * @return true为block状态
	 */
	bool isBlocked() { return m_type == TILE_BLOCKED; }

	/**
	 * 判断是否为free状态
	 *
	 * @return true为free状态
	 */
	bool isFree() { return m_type == TILE_FREE; }

	/**
	 * 增加子节点\link wyAStarTile wyAStarTile\endlink对象指针
	 *
	 * @param tile 子节点\link wyAStarTile wyAStarTile\endlink对象指针
	 */
	void pushChild(wyAStarTile* tile);

	/**
	 * 返回子节点\link wyArray wyArray\endlink对象指针
	 *
	 * @return 子节点\link wyArray wyArray\endlink对象指针
	 */
	wyArray* getChilds() { return m_childs; }
};

#endif // __wyAStarTile_h__
