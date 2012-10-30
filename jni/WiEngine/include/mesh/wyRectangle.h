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
#ifndef __wyRectangle_h__
#define __wyRectangle_h__

#include "wyMesh.h"
#include "wyGlobal.h"

/**
 * Rectangle in 2D
 */
class WIENGINE_API wyRectangle : public wyMesh {
protected:
	wyRectangle();

public:
	/**
	 * Create a nothing rectangle mesh
	 *
	 * @return \link wyRectangle wyRectangle\endlink
	 */
	static wyRectangle* make();

	virtual ~wyRectangle();

	/// @see wyMesh::getElementCount
	virtual int getElementCount() { return 4; }

	/**
	 * Update mesh data base don texture size
	 *
	 * @param texPixelWidth opengl texture pixel width, should be a POT value
	 * @param texPixelHeight opengl texture pixel height, should be a POT value
	 * @param x render x position
	 * @param y render y position
	 * @param width render width
	 * @param height render height
	 * @param sourceWidth original width of image
	 * @param sourceHeight original height of image
	 * @param flipX true means need flip texture in x axis
	 * @param flipY true means need flip texture in y axis
	 * @param texRect the rect area in texture you want to draw, usually used for atlas texture rendering
	 * @param rotate90 true means texture need to be rotated 90 degrees, counter-clockwise
	 */
	void updateMesh(float texPixelWidth, float texPixelHeight, float x, float y, float width, float height,
			float sourceWidth, float sourceHeight, bool flipX, bool flipY, wyRect texRect, bool rotate90);

	/**
	 * Update mesh data directly from pre-calculated array
	 *
	 * @param vertices vertex data, must contain 12 float number
	 * @param texCoords texture coordinates, must contain 8 float number
	 */
	void updateMesh(float* vertices, float* texCoords);

	/**
	 * Update color info
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 */
	void updateColor(wyColor4B color);
};

#endif // __wyRectangle_h__
