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
#ifndef __wyClipIn_h__
#define __wyClipIn_h__

#include "wyIntervalAction.h"

/**
 * enlarge clip rect of node gradually to get an enter animation
 */
class WIENGINE_API wyClipIn : public wyIntervalAction {
public:
	/// Direction to which clip rect moves
	enum Direction {
		/// clip grows from left to right side
		LEFT_TO_RIGHT,

		/// clip grows from right to left side
		RIGHT_TO_LEFT,

		/// \if English
		TOP_TO_BOTTOM,

		/// clip grows from bottom to top side
		BOTTOM_TO_TOP
	};

private:
	/// clip grow direction
	Direction m_direction;

protected:
	/**
	 * Constructor
	 *
	 * @param duration action duration in seconds
	 * @param direction clip grow direction
	 */
	wyClipIn(float duration, Direction direction);

public:
	virtual ~wyClipIn();

	/**
	 * Create a clip in action
	 *
	 * @param duration action duration in seconds
	 * @param direction clip grow direction, default is \c BOTTOM_TO_TOP
	 * @return \link wyClipIn wyClipIn\endlink
	 */
	static wyClipIn* make(float duration, Direction direction = BOTTOM_TO_TOP);

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::stop
	virtual void stop();
};

#endif // __wyClipIn_h__
