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
#ifndef __wyScaleBy_h__
#define __wyScaleBy_h__

#include "wyIntervalAction.h"

/**
 * @class wyScaleBy
 *
 * scale a node
 */
class WIENGINE_API wyScaleBy : public wyIntervalAction {
protected:
	/**
	 * original x scale
	 */
	float m_startScaleX;

	/**
	 * original y scale
	 */
	float m_startScaleY;

	/**
	 * end x scale
	 */
	float m_endScaleX;

	/**
	 * end y scale
	 */
	float m_endScaleY;

	/**
	 * delta x scale
	 */
	float m_deltaX;

	/**
	 * delta y scale
	 */
	float m_deltaY;

protected:
	/**
	 * constructor
	 *
	 * @param duration duration of action in second
	 * @param scaleX delta x scale
	 * @param scaleY delta y scale
	 */
	wyScaleBy(float duration, float scaleX, float scaleY);

	/**
	 * constructor
	 *
	 * @param duration duration of action in second
	 * @param scale delta scale
	 */
	wyScaleBy(float duration, float scale);

public:
	/**
	 * static factory method
	 *
	 * @param duration duration of action in second
	 * @param scaleX delta x scale
	 * @param scaleY delta y scale
	 * @return \link wyScaleBy wyScaleBy\endlink
	 */
	static wyScaleBy* make(float duration, float scaleX, float scaleY);

	/**
	 * static factory method
	 *
	 * @param duration duration of action in second
	 * @param scale delta scale
	 * @return \link wyScaleBy wyScaleBy\endlink
	 */
	static wyScaleBy* make(float duration, float scale);

	virtual ~wyScaleBy();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyScaleBy_h__
