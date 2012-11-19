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
#ifndef __wyFiniteTimeAction_h__
#define __wyFiniteTimeAction_h__

#include "wyAction.h"

/**
 * Base class for actions whose time is definite
 */
class WIENGINE_API wyFiniteTimeAction : public wyAction {
	friend class wyRepeat;
	friend class wyRepeatForever;

protected:
	/// time already passed
	float m_elapsed;

	/// duration time of action
	float m_duration;

	/// true indicating it is the first time to update action, it is set to ensure action starts from beginning
	bool m_firstTick;

protected:
	/**
	 * Constructor
	 *
	 * @param duration duration time of action
	 */
	wyFiniteTimeAction(float duration);

public:
	virtual ~wyFiniteTimeAction();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/**
	 * Get duration time of action
	 *
	 * @return duration time of action
	 */
	float getDuration();

	/**
	 * Set duration time of action, no effect if action is started
	 *
	 * @param duration duration time of action
	 */
	void setDuration(float duration);

	/**
	 * Get elapsed time of this action
	 *
	 * @return elapsed time in second
	 */
	float getElapsed() { return m_elapsed; }

	/**
	 * Set elapsed time of action, don't call it if you do not know what will happen. Mainly used by internal logic.
	 *
	 * @param e elapsed time
	 */
	void setElapsed(float e) { m_elapsed = e; }
};

#endif // __wyFiniteTimeAction_h__
