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
#ifndef __wyQuadList_h__
#define __wyQuadList_h__

#include "wyMesh.h"
#include "WiEngine-Classes.h"

/**
 * \if English
 * Mesh object which contains a bunch of quadrangle
 * \else
 * 这个mesh包含了一系列的四边形对象
 * \endif
 */
class WIENGINE_API wyQuadList : public wyMesh {
private:
	/// vertex buffer
	wyBuffer* m_buf;

	/// indices buffer
	wyBuffer* m_indices;

	/// default color
	wyColor4B m_color;

protected:
	wyQuadList();

	/// initialize indices buffer
	void initIndices();

	/// ensure indices capacity is ok
	void ensureIndicesCapacity();

	/// put quad into buffer
	void putQuad(int index, const wyQuad2D& quadT, const wyQuad3D& quadV, bool update = false);

public:
	virtual ~wyQuadList();
	static wyQuadList* make();

	/// @see wyMesh::getElementCount()
	virtual int getElementCount();

	/**
	 * \if English
	 * Append a quad to buffer end
	 *
	 * @param quadT \link wyQuad2D wyQuad2D\endlink
	 * @param quadV \link wyQuad3D wyQuad3D\endlink
	 * @return index of this quad
	 * \else
	 * 在缓存中添加顶点和纹理,放到队列中最后
	 *
	 * @param quadT 纹理\link wyQuad2D wyQuad2D结构\endlink
	 * @param quadV 顶点\link wyQuad3D wyQuad3D结构\endlink
	 * @return 新添加的四边形在atlas中的索引
	 * \endif
	 */
	int appendQuad(wyQuad2D& quadT, wyQuad3D& quadV);

	/**
	 * \if English
	 * Insert a quad in specified index
	 *
	 * @param quadT \link wyQuad2D wyQuad2D\endlink
	 * @param quadV \link wyQuad3D wyQuad3D\endlink
	 * @param index index to be inserted at
	 * \else
	 * 在缓存指定索引中添加顶点和纹理, 如果插入在最后，则不需要额外操作，
	 * 如果插入在中间，则会把插入位置处的Quad移动到最后一个
	 *
	 * @param quadT 纹理\link wyQuad2D wyQuad2D结构\endlink
	 * @param quadV 顶点\link wyQuad3D wyQuad3D结构\endlink
	 * @param index 缓存索引
	 * \endif
	 */
	void insertQuad(wyQuad2D& quadT, wyQuad3D& quadV, int index);

	/**
	 * \if English
	 * Update a quad texture and vertices
	 *
	 * @param quadT \link wyQuad2D wyQuad2D\endlink
	 * @param quadV \link wyQuad3D wyQuad3D\endlink
	 * @param index index to be updated at
	 * \else
	 * 更新缓存中的顶点和纹理
	 *
	 * @param quadT 纹理\link wyQuad2D wyQuad2D结构\endlink
	 * @param quadV 顶点\link wyQuad3D wyQuad3D结构\endlink
	 * @param index 缓存中的索引
	 * \endif
	 */
	void updateQuad(wyQuad2D& quadT, wyQuad3D& quadV, int index);

	/**
	 * \if English
	 * Remove quad at specified index
	 *
	 * @param index index of quad
	 * \else
	 * 删除指定位置的Quad, 如果删除的是最后一个，则不需要额外操作，
	 * 如果删除的是中间的，则最后一个Quad会被移动到被删除的位置
	 *
	 * @param index 缓存索引
	 * \endif
	 */
	void removeQuad(int index);

	/**
	 * \if English
	 * Remove quad at specified range
	 *
	 * @param start start index of quad
	 * @param count how many quad to be deleted
	 * \else
	 * 删除一定范围内的四边形
	 *
	 * @param start 删除的起始索引
	 * @param count 删除的四边形个数
	 * \endif
	 */
	void removeQuads(int start, int count);

	/**
	 * \if English
	 * Remove all quadrangles
	 * \else
	 * 删除所有矩形
	 * \endif
	 */
	void removeAllQuads() { m_buf->clear(); }

	/**
	 * \if English
	 * Get total number of quadrangle
	 * \else
	 * 获得缓存中使用的总数
	 * \endif
	 */
	int getTotalQuads() { return m_buf->getElementCount() / 4; }

	/**
	 * \if English
	 * Update a color of a quadrangle
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 * @param index index of quadrangle
	 * \else
	 * 更新缓存中的颜色
	 *
	 * @param color 颜色\link wyColor4B wyColor4B结构\endlink
	 * @param index 缓存中的索引
	 * \endif
	 */
	void updateColor(wyColor4B color, int index);

	/**
	 * \if English
	 * Update color for all quads
	 *
	 * @param color color to be set
	 * \else
	 * 统一设置所有的四边形为某一颜色
	 *
	 * @param color 要设置的颜色
	 * \endif
	 */
	void updateColor(wyColor4B color);

	/**
	 * \if English
	 * Translate position of every vertex in quad list
	 * \else
	 * 对每个顶点做一个偏移
	 * \endif
	 */
	void translate(float x, float y, float z);

	/**
	 * \if English
	 * multiply position of every vertex with a factor
	 * \else
	 * 对顶点的位置乘以某个数值
	 * \endif
	 */
	void scale(float x, float y, float z);

	/**
	 * \if English
	 * Subtract an alpha value for every vertex and remove quadrangles
	 * whose alpha is less than 0.
	 *
	 * @param delta alpha value to be reduced
	 * \else
	 * 所有顶点的alpha都减去一个指定值, 该方法仅当颜色数组启用时有效. alpha
	 * 小于等于0的四边形将被删除
	 *
	 * @param delta 需要减去的alpha值
	 * \endif
	 */
	void reduceAlpha(float delta);
};

#endif // __wyQuadList_h__
