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
#ifndef __wyBox2DMeshBuilder_h__
#define __wyBox2DMeshBuilder_h__

#include <Box2D/Box2D.h>
#include "WiEngine-Classes.h"

/**
 * A helper class which can create mesh object from a box2d fixture
 */
class BOX2D_API wyBox2DMeshBuilder {
private:
	/**
	 * Create a mesh object from a fixture
	 *
	 * @param mesh mesh to be updated
	 * @param box2d related box2d node
	 * @param f box2d fixture object, the fixture must has edge shape
	 * @param texPixelWidth related texture pixel width, it should be a POT size
	 * @param texPixelHeight related texture pixel height, it should be a POT size
	 * @param texRect rect area in texture, for non-altas texture, it should be same as texture effect size.
	 */
	static void updateEdgeMesh(wyRectangle* mesh, wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect& texRect);

	/**
	 * Create a mesh object from a fixture
	 *
	 * @param mesh mesh to be updated
	 * @param box2d related box2d node
	 * @param f box2d fixture object, the fixture must has chain shape
	 * @param texPixelWidth related texture pixel width, it should be a POT size
	 * @param texPixelHeight related texture pixel height, it should be a POT size
	 * @param texRect rect area in texture, for non-altas texture, it should be same as texture effect size.
	 */
	static void updateChainMesh(wyQuadList* mesh, wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect& texRect);

	/**
	 * Create a mesh object from a fixture
	 *
	 * @param mesh mesh to be updated
	 * @param box2d related box2d node
	 * @param f box2d fixture object, the fixture must has polygon shape
	 * @param texPixelWidth related texture pixel width, it should be a POT size
	 * @param texPixelHeight related texture pixel height, it should be a POT size
	 * @param texRect rect area in texture, for non-altas texture, it should be same as texture effect size.
	 */
	static void updatePolygonMesh(wyShape* mesh, wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect& texRect);

	/**
	 * Create a mesh object from a fixture
	 *
	 * @param mesh mesh to be updated
	 * @param box2d related box2d node
	 * @param f box2d fixture object, the fixture must has circle shape
	 * @param texPixelWidth related texture pixel width, it should be a POT size
	 * @param texPixelHeight related texture pixel height, it should be a POT size
	 * @param texRect rect area in texture, for non-altas texture, it should be same as texture effect size.
	 */
	static void updateCircleMesh(wyShape* mesh, wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect& texRect);

public:
	/**
	 * Create a mesh object from a fixture
	 *
	 * @param box2d related box2d node
	 * @param f box2d fixture object
	 * @param texPixelWidth related texture pixel width, it should be a POT size
	 * @param texPixelHeight related texture pixel height, it should be a POT size
	 * @param texRect rect area in texture, for non-altas texture, it should be same as texture effect size.
	 * @return \link wyMesh wyMesh\endlink
	 */
	static wyMesh* createMesh(wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect texRect);

	/**
	 * Update a mesh object which is created by \c createMesh before
	 *
	 * @param mesh the mesh need to be updated. \c updateMesh will cast it to subclass type but it won't check type.
	 * 		So you should ensure the mesh has right type
	 * @param box2d related box2d node
	 * @param f box2d fixture object
	 * @param texPixelWidth related texture pixel width, it should be a POT size
	 * @param texPixelHeight related texture pixel height, it should be a POT size
	 * @param texRect rect area in texture, for non-altas texture, it should be same as texture effect size.
	 */
	static void updateMesh(wyMesh* mesh, wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect texRect);
};

#endif // __wyBox2DMeshBuilder_h__
