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
#ifndef __wyPlace_h__
#define __wyPlace_h__

#include "wyInstantAction.h"
#include "wyTypes.h"

/**
 * @class wyPlace
 *
 * Move a node to specfied place. This action doesn't have reverse action and
 * execute instantly.
 */
class WIENGINE_API wyPlace : public wyInstantAction {
protected:
	/**
	 * offset to be moved
	 */
	wyPoint m_position;

protected:
	/**
	 * constructor
	 *
	 * @param x x offset to be added
	 * @param y y offset to be added
	 */
	wyPlace(float x, float y);

public:
	/**
	 * static factory method
	 *
	 * @param x x offset to be added
	 * @param y y offset to be added
	 */
	static wyPlace* make(float x, float y);

	virtual ~wyPlace();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/**
	 * This action doesn't have reverse action, so returns NULL always
	 *
	 * @return NULL
	 */
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);
};

#endif // __wyPlace_h__
