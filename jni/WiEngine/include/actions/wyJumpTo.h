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
#ifndef __wyJumpTo_h__
#define __wyJumpTo_h__

#include "wyIntervalAction.h"
#include "wyTypes.h"

/**
 * A node jumps from a position to elsewhere, the jumping can be adjusted by offset, height and times
 */
class WIENGINE_API wyJumpTo : public wyIntervalAction {
protected:
	/// start x position of jumping
	float m_startX;

	/// start y position of jumping
	float m_startY;

	/// end x position of jumping
	float m_endX;

	/// end y position of jumping
	float m_endY;

	/// offset between start x and end x
	float m_deltaX;

	/// offset between start y and end y
	float m_deltaY;

	/// height of jumping
	float m_height;

	/// times of jumping
	int m_jumps;

protected:
	/**
	 * Constructor
	 *
	 * @param duration duration time of jumping
	 * @param startX start x position of jumping
	 * @param startY start y position of jumping
	 * @param endX end x position of jumping
	 * @param endY end y position of jumping
	 * @param height height of jumping
	 * @param jumps times of jumping
	 */
	wyJumpTo(float duration, float startX, float startY, float endX, float endY, float height, int jumps);

public:
	/**
	 * static constructor
	 *
	 * @param duration duration time of jumping
	 * @param startX start x position of jumping
	 * @param startY start y position of jumping
	 * @param endX end x position of jumping
	 * @param endY end y position of jumping
	 * @param height height of jumping
	 * @param jumps times of jumping
	 * @return \link wyJumpTo wyJumpTo\endlink
	 */
	static wyJumpTo* make(float duration, float startX, float startY, float endX, float endY, float height, int jumps);

	virtual ~wyJumpTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyJumpTo_h__
