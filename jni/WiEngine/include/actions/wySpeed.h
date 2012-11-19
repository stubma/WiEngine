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
#ifndef __wySpeed_h__
#define __wySpeed_h__

#include "WiEngine-Classes.h"
#include "wyIntervalAction.h"
#include "wyTypes.h"

/**
 * @class wySpeed
 *
 * Accelerate or deaccelerate an action
 */
class WIENGINE_API wySpeed : public wyAction {
protected:
	/**
	 * the \link wyAction wyAction \endlink need to be speed up or down
	 */
	wyAction* m_other;

	/**
	 * the coefficient of speed up or down
	 */
	float m_speed;

protected:
	/**
	 * constructor
	 *
	 * @param other the \link wyAction wyAction \endlink need to be speed up or down
	 * @param speed the coefficient of speed up or down
	 */
	wySpeed(wyAction* other, float speed);

public:
	/**
	 * static factory method
	 *
	 * @param other the \link wyAction wyAction \endlink need to be speed up or down
	 * @param speed the coefficient of speed up or down
	 */
	static wySpeed* make(wyAction* other, float speed);

	virtual ~wySpeed();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::stop
	virtual void stop();

	/// @see wyAction::step
	virtual void step(float t);

	/// @see wyAction::update
	virtual void update(float t);

	/// @see wyAction::isDone
	virtual bool isDone();

	/**
	 * get coefficient of speed
	 *
	 * @return coefficient of speed
	 */
	float getSpeed() { return m_speed; }

	/**
	 * set coefficient of speed
	 *
	 * @param speed Coefficient of speed, if larger than 1 then it means acceleration.
	 * 		Can't set a negative value
	 */
	void setSpeed(float speed) { m_speed = MAX(0, speed); }
};

#endif // __wySpeed_h__
