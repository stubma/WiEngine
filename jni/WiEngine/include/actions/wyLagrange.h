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
#ifndef __wyLagrange_h__
#define __wyLagrange_h__

#include "wyIntervalAction.h"
#include "wyTypes.h"

/**
 * Move a \link wyNode wyNode\endlink in track of Lagrange curve
 */
class WIENGINE_API wyLagrange : public wyIntervalAction {
protected:
	/// description of lagrange curve
	wyLagrangeConfig m_config;

	/**
	 * true means enable auto rotate, it means the node move by lagrange path will be aligned
	 * with path direction.
	 */
	bool m_autoRotate;
	
	/**
	 * the delta to be added to path direction. Position value means
	 * clockwise, negative value means counter-clockwise
	 */
	float m_angleDelta;
	
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
	 * @param duration duration time in second
	 * @param config \link wyLagrangeConfig wyLagrangeConfig\endlink structure to describe lagrange curve
	 */
	wyLagrange(float duration, wyLagrangeConfig config);

public:
	/**
	 * Static factory method
	 *
	 * @param duration duration time in second
	 * @param config \link wyLagrangeConfig wyLagrangeConfig\endlink structure to describe lagrange curve
	 * @return \link wyLagrange wyLagrange\endlink
	 */
	static wyLagrange* make(float duration, wyLagrangeConfig config);

	virtual ~wyLagrange();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
	
	/**
	 * Enable auto rotate, it means the node move by lagrange path will be aligned
	 * with path direction.
	 *
	 * @param flag true means enable auto rotate
	 * @param angleDelta the delta to be added to path direction. Position value means
	 * 		clockwise, negative value means counter-clockwise
	 */
	void setAutoRotate(bool flag, float angleDelta);

	/**
	 * set pin point, only available when auto rotate flag is false
	 *
	 * @param p global coordinate of pin point
	 */
	void setPinPoint(wyPoint p) { m_pinPoint = p; }

	/**
	 * set pin point, only available when auto rotate flag is false
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

#endif // __wyLagrange_h__
