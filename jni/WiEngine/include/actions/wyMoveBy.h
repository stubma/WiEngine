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
#ifndef __wyMoveBy_h__
#define __wyMoveBy_h__

#include "wyIntervalAction.h"
#include "wyTypes.h"

/**
 * Move a node
 */
class WIENGINE_API wyMoveBy : public wyIntervalAction {
protected:
	/// start x position
	float m_startPositionX;

    /// start y position
	float m_startPositionY;

	/// offset in x axis
	float m_deltaX;

	/// offset in y axis
	float m_deltaY;

	/**
	 * Pin point. When moving, node's rotation will be set to angle of line
	 * between node anchor and pin point
	 */
	wyPoint m_pinPoint;

	/// angle delta added to node rotation when pin point is set
	float m_pinDelta;

protected:
	/**
	 * Constructor
	 *
	 * @param duration duration time of action
	 * @param x offset in x axis
	 * @param y offset in y axis
	 */
	wyMoveBy(float duration, float x, float y);

public:
	/**
	 * Static constructor
	 *
	 * @param duration duration time of action
	 * @param x offset in x axis
	 * @param y offset in y axis
	 * @return \link wyMoveBy wyMoveBy\endlink
	 */
	static wyMoveBy* make(float duration, float x, float y);

	virtual ~wyMoveBy();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);

	/**
	 * set pin point
	 *
	 * @param p global coordinate of pin point
	 */
	void setPinPoint(wyPoint p) { m_pinPoint = p; }

	/**
	 * set pin point
	 *
	 * @param x global x location of pin point
	 * @param y global y location of pin point
	 */
	void setPinPoint(float x, float y) { m_pinPoint = wyp(x, y); }

	/**
	 * get pin point
	 *
	 * @return global coordinate of pin point
	 */
	wyPoint getPinPoint() { return m_pinPoint; }

	/**
	 * clear pin point
	 */
	void clearPinPoint() { m_pinPoint = wyp(MAX_FLOAT, MAX_FLOAT); }

	/**
	 * set angle delta of pin point rotation
	 *
	 * @param angle to be added to node rotation
	 */
	void setPinAngleDelta(float delta) { m_pinDelta = delta; }

	/**
	 * get angle delta
	 *
	 * @return angle delta
	 */
	float getPinAngleDelta() { return m_pinDelta; }
};

#endif // __wyMoveBy_h__
