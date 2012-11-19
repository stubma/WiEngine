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
 * Mesh object which contains a bunch of quadrangle
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

	/// put quad into buffer, also update color
	void putQuad(int index, const wyQuad2D& quadT, const wyQuad3D& quadV, wyColor4B c, bool update = false);

public:
	virtual ~wyQuadList();
	static wyQuadList* make();

	/// @see wyMesh::getElementCount()
	virtual int getElementCount() { return getTotalQuads(); }

	/// @see wyMesh::update
	virtual void update() {}

	/// @see wyMesh::updateColor4B
	virtual void updateColor4B(wyColor4B color);

	/**
	 * Append a quad to buffer end
	 *
	 * @param quadT \link wyQuad2D wyQuad2D\endlink
	 * @param quadV \link wyQuad3D wyQuad3D\endlink
	 * @param c quad color, default value is white
	 * @return index of this quad
	 */
	int appendQuad(wyQuad2D& quadT, wyQuad3D& quadV, wyColor4B c = wyc4bWhite);

	/**
	 * Insert a quad in specified index
	 *
	 * @param index index to be inserted at
	 * @param quadT \link wyQuad2D wyQuad2D\endlink
	 * @param quadV \link wyQuad3D wyQuad3D\endlink
	 * @param c quad color, default value is white
	 */
	void insertQuad(int index, wyQuad2D& quadT, wyQuad3D& quadV, wyColor4B c = wyc4bWhite);

	/**
	 * Update a quad texture and vertices
	 *
	 * @param index index to be updated at
	 * @param quadT \link wyQuad2D wyQuad2D\endlink
	 * @param quadV \link wyQuad3D wyQuad3D\endlink
	 */
	void updateQuad(int index, wyQuad2D& quadT, wyQuad3D& quadV);

	/**
	 * Only update quad vertices
	 *
	 * @param index index of quadrangle to be updated
	 * @param quadV \link wyQuad3D wyQuad3D\endlink
	 */
	void updateQuad(int index, wyQuad3D& quadV);

	/**
	 * Update a quad texture and vertices
	 *
	 * @param index index to be updated at
	 * @param quadT \link wyQuad2D wyQuad2D\endlink
	 * @param quadV \link wyQuad3D wyQuad3D\endlink
	 * @param c quad color
	 */
	void updateQuad(int index, wyQuad2D& quadT, wyQuad3D& quadV, wyColor4B c);

	/**
	 * Remove quad at specified index
	 *
	 * @param index index of quad
	 */
	void removeQuad(int index);

	/**
	 * Remove quad at specified range
	 *
	 * @param start start index of quad
	 * @param count how many quad to be deleted
	 */
	void removeQuads(int start, int count);

	/// Remove all quadrangles
	void removeAllQuads() { m_buf->clear(); }

	/// Get total number of quadrangle
	int getTotalQuads() { return m_buf->getElementCount() / 4; }

	/**
	 * Update a color of a quadrangle
	 *
	 * @param index index of quadrangle
	 * @param color \link wyColor4B wyColor4B\endlink
	 */
	void updateColor(int index, wyColor4B color);


	/**
	 * Translate position of every vertex in quad list
	 *
	 * @param x x delta added to vertex x
	 * @param y y delta added to vertex y
	 * @param z z delta added to vertex z
	 */
	void translate(float x, float y, float z);

	/**
	 * multiply position of every vertex with a factor
	 */
	void scale(float x, float y, float z);

	/**
	 * Subtract an alpha value for every vertex and remove quadrangles
	 * whose alpha is less than 0
	 *
	 * @param delta alpha value to be reduced
	 */
	void reduceAlpha(float delta);

	/**
	 * Replace all texture coordinate to given value
	 *
	 * @param t the texture coordinate used to fill all vertex
	 */
	void replaceTexCoord(wyQuad2D& t);
};

#endif // __wyQuadList_h__
