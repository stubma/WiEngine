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
#ifndef __wyRotateTo_h__
#define __wyRotateTo_h__

#include "wyIntervalAction.h"

/**
 * @class wyRotateTo
 *
 * Rotate a node. For a node, position value means clockwise and negative value means
 * counter-clockwise.
 */
class WIENGINE_API wyRotateTo : public wyIntervalAction {
protected:
	/**
	 * delta angle in degree, computed from start and end angle
	 */
	float m_delta;

	/**
	 * start angle of node, in degree
	 */
	float m_startAngle;

	/**
	 * end angle of node, in degree
	 */
	float m_endAngle;

protected:
	/**
	 * constructor
	 *
	 * @param duration duration time in seconds
	 * @param startAngle start angle in degree
	 * @param endAngle end angle in degree
	 */
	wyRotateTo(float duration, float startAngle, float endAngle);

public:
	/**
	 * static factory method
	 *
	 * @param duration duration time in seconds
	 * @param startAngle start angle in degree
	 * @param endAngle end angle in degree
	 */
	static wyRotateTo* make(float duration, float startAngle, float endAngle);

	virtual ~wyRotateTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyRotateTo_h__
