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
#ifndef __wyScaleTo_h__
#define __wyScaleTo_h__

#include "wyIntervalAction.h"

/**
 * @class wyScaleBy
 *
 * scale node
 */
class WIENGINE_API wyScaleTo : public wyIntervalAction {
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

private:
	/**
	 * initialize action
	 *
	 * @param startScaleX initial x scale
	 * @param startScaleY initial y scale
	 * @param endScaleX end x scale
	 * @param endScaleY end y scale
	 */
	void init(float startScaleX, float startScaleY, float endScaleX, float endScaleY);

protected:
	/**
	 * constructor
	 *
	 * @param duration duration time of action in second
	 * @param startScaleX initial x scale
	 * @param startScaleY initial y scale
	 * @param endScaleX end x scale
	 * @param endScaleY end y scale
	 */
	wyScaleTo(float duration, float startScaleX, float startScaleY, float endScaleX, float endScaleY);

	/**
	 * constructor
	 *
	 * @param duration duration time of action in second
	 * @param startScale initial scale
	 * @param endScale end scale
	 */
	wyScaleTo(float duration, float startScale, float endScale);

public:
	/**
	 * static factory method
	 *
	 * @param duration duration time of action in second
	 * @param startScaleX initial x scale
	 * @param startScaleY initial y scale
	 * @param endScaleX end x scale
	 * @param endScaleY end y scale
	 */
	static wyScaleTo* make(float duration, float startScaleX, float startScaleY, float endScaleX, float endScaleY);

	/**
	 * static factory method
	 *
	 * @param duration duration time of action in second
	 * @param startScale initial scale
	 * @param endScale end scale
	 */
	static wyScaleTo* make(float duration, float startScale, float endScale);

	virtual ~wyScaleTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyScaleTo_h__
