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
#ifndef __wySpawn_h__
#define __wySpawn_h__

#include "wyIntervalAction.h"

/**
 * @class wySpawn
 *
 * \if English
 * Execute two actions simultaneously. The duration time will be the longer-lived action's time
 * \else
 * 同时执行两个动作的封装
 * \endif
 */
class WIENGINE_API wySpawn : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * first action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction \endlink
	 * \else
	 * 要执行的动作\link wyFiniteTimeAction wyFiniteTimeAction \endlink对象指针
	 * \endif
	 */
	wyFiniteTimeAction* m_one;

	/**
	 * \if English
	 * second action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction \endlink
	 * \else
	 * 要执行的动作\link wyFiniteTimeAction wyFiniteTimeAction \endlink对象指针
	 * \endif
	 */
	wyFiniteTimeAction* m_two;

protected:
	/**
	 * constructor
	 *
	 * @param one first action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction \endlink
	 * @param two second action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction \endlink
	 */
	wySpawn(wyFiniteTimeAction* one, wyFiniteTimeAction* two);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param one first action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction \endlink
	 * @param two second action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction \endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param one 要执行的动作 \link wyFiniteTimeAction wyFiniteTimeAction \endlink对象指针
	 * @param two 要执行的动作 \link wyFiniteTimeAction wyFiniteTimeAction \endlink对象指针
	 * \endif
	 */
	static wySpawn* make(wyFiniteTimeAction* one, wyFiniteTimeAction* two);

	virtual ~wySpawn();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::stop
	virtual void stop();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wySpawn_h__
