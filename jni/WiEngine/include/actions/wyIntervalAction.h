/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyIntervalAction_h__
#define __wyIntervalAction_h__

#include "wyFiniteTimeAction.h"
#include <stdbool.h>

/**
 * @class wyIntervalAction
 *
 * \if English
 * Opposite to instant action, it is the base class of actions who will last for some while.
 * \else
 * 是所有非瞬间动作的基类, 用来表示一定时间内完成且在完成时间内持续更新的动作
 * \endif
 */
class WIENGINE_API wyIntervalAction : public wyFiniteTimeAction {
protected:
	/**
	 * Constructor
	 *
	 * @param duration duration time of action
	 */
	wyIntervalAction(float duration);

public:
	virtual ~wyIntervalAction();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::step
	virtual void step(float t);

	/// @see wyAction::isDone
	virtual bool isDone();
};

#endif // __wyIntervalAction_h__
