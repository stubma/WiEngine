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
#ifndef __wyVerletPoint_h__
#define __wyVerletPoint_h__

#include "wyObject.h"
#include "WiEngine-Classes.h"

/**
 * @class wyVerletPoint
 *
 * A point in a verlet rope
 */
class WIENGINE_API wyVerletPoint : public wyObject {
	friend class wyVerletStick;
	friend class wyVerletRope;

private:
	/**
	 * current x value
	 */
	float m_x;

	/**
	 * current y value
	 */
	float m_y;

	/**
	 * previous x value
	 */
	float m_oldX;

	/**
	 * previous y value
	 */
	float m_oldY;

public:
	wyVerletPoint();
	virtual ~wyVerletPoint();

	/**
	 * Set position
	 *
	 * @param x x position
	 * @param y y position
	 */
	void setPosition(float x, float y);

	/**
	 * Update point
	 */
	void update();

	/**
	 * Apply gravity to this point
	 *
	 * @param dt delta time
	 */
	void applyGravity(float dt);

	/**
	 * Set x position
	 *
	 * @param x x position
	 */
	void setX(float x) { m_x = x; }

	/**
	 * Set y position
	 *
	 * @param y y position
	 */
	void setY(float y) { m_y = y; }

	/**
	 * Get x position
	 *
	 * @return x position
	 */
	float getX() { return m_x; }

	/**
	 * Get y position
	 *
	 * @return y position
	 */
	float getY() { return m_y; }

	/**
	 * Attenuate waving
	 *
	 * @param percent percent to be reduced
	 */
	void attenuate(float percent);

	/**
	 * Clone this point object
	 *
	 * @return \link wyVerletPoint wyVerletPoint\endlink
	 */
	wyVerletPoint* copy();
};

#endif // __wyVerletPoint_h__
