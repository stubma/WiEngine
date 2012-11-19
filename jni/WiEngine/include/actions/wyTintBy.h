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
#ifndef __wyTintBy_h__
#define __wyTintBy_h__

#include "wyIntervalAction.h"

/**
 * @class wyTintBy
 *
 * It changes color of node by a delta value
 */
class WIENGINE_API wyTintBy : public wyIntervalAction {
protected:
	/**
	 * delta value of red component
	 */
	int m_deltaR;

	/**
	 * delta value of green component
	 */
	int m_deltaG;

	/**
	 * delta value of blue component
	 */
	int m_deltaB;

	/**
	 * red component of start color, from 0 to 255
	 */
	int m_fromR;

	/**
	 * green component of start color, from 0 to 255
	 */
	int m_fromG;

	/**
	 * blue component of start color, from 0 to 255
	 */
	int m_fromB;

protected:
	/**
	 * constructor
	 *
	 * @param duration duration time of action in seconds
	 * @param r delta value of red component
	 * @param g delta value of green component
	 * @param b delta value of blue component
	 */
	wyTintBy(float duration, int r, int g, int b);

public:
	/**
	 * static factory method
	 *
	 * @param duration duration time of action in seconds
	 * @param r delta value of red component
	 * @param g delta value of green component
	 * @param b delta value of blue component
	 */
	static wyTintBy* make(float duration, int r, int g, int b);

	virtual ~wyTintBy();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyTintBy_h__
