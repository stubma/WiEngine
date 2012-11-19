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
#ifndef __wyRotateBy_h__
#define __wyRotateBy_h__

#include "wyIntervalAction.h"

/**
 * @class wyRotateBy
 *
 * rotate a node by specified angle, in degree
 */
class WIENGINE_API wyRotateBy : public wyIntervalAction {
protected:
	/**
	 * Angle of rotation, in degree
	 */
	float m_angle;

	/**
	 * start angle in degree
	 */
	float m_startAngle;

protected:
	/**
	 * constructor
	 *
	 * @param duration duration time of action, in seconds
	 * @param angle angle in degree to be rotated
	 */
	wyRotateBy(float duration, float angle);

public:
	/**
	 * static factory method
	 *
	 * @param duration duration time of action, in seconds
	 * @param angle angle in degree to be rotated
	 */
	static wyRotateBy* make(float duration, float angle);

	virtual ~wyRotateBy();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyRotateBy_h__
