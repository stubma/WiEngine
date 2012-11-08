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
#ifndef __wyGradientColorLayer_h__
#define __wyGradientColorLayer_h__

#include "wyLayer.h"
#include "wyGlobal.h"

/**
 * gradient color layer
 */
class WIENGINE_API wyGradientColorLayer : public wyLayer {
protected:
	/// the start color, \link wyColor4B wyColor4B\endlink
	wyColor4B m_fromColor;

	/// the end color, \link wyColor4B wyColor4B\endlink
	wyColor4B m_toColor;

	/**
	 * the radiant angle, in degrees from 0 to 360. X axis is degree 0 and positive value
	 * means clockwise
	 */
	int m_degree;

public:
	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param fromColor the start color, \link wyColor4B wyColor4B\endlink
	 * @param toColor the end color, \link wyColor4B wyColor4B\endlink
	 * @param degree the radian angle, in degrees from 0 to 360. X axis is degree 0 and positive value
	 * 		means clockwise
	 */
	static wyGradientColorLayer* make(wyColor4B fromColor, wyColor4B toColor, int degree);

	virtual ~wyGradientColorLayer();

	/// @see wyNode::updateMesh
	virtual void updateMesh();

	/**
	 * constructor
	 *
	 * @param fromColor the start color, \link wyColor4B wyColor4B\endlink
	 * @param toColor the end color, \link wyColor4B wyColor4B\endlink
	 * @param degree the radian angle, in degrees from 0 to 360. X axis is degree 0 and positive value
	 * 		means clockwise
	 */
	wyGradientColorLayer(wyColor4B fromColor, wyColor4B toColor, int degree);

	/// set gradient degree
	void setDegree(int degree);

	/// Get gradient degree
	int getDegree();

	/// set start color
	void setFromColor(wyColor3B color);

	/// get start color
	wyColor3B getFromColor();

	/// set end color
	void setToColor(wyColor3B color);

	/// get end color
	wyColor3B getToColor();
};

#endif // __wyGradientColorLayer_h__
