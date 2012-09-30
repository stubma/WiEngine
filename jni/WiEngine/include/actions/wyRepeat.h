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
#ifndef __wyRepeat_h__
#define __wyRepeat_h__

#include "wyIntervalAction.h"

/**
 * @class wyRepeat
 *
 * \if English
 * repeat an action, you can control repeat times
 * \else
 * 根据设置重复次数，重复执行动作的封装
 * \endif
 */
class WIENGINE_API wyRepeat : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * repeat times, must be larger than zero
	 * \else
	 * 动作重复的次数
	 * \endif
	 */
	int m_times;

	/**
	 * \if English
	 * times of already executed
	 * \else
	 * 已经执行的次数
	 * \endif
	 */
	int m_total;

	/**
	 * \if English
	 * action to be repeated
	 * \else
	 * 具体要执行的\link wyFiniteTimeAction wyFiniteTimeAction对象 \endlink指针
	 * \endif
	 */
	wyFiniteTimeAction* m_other;

protected:
	/**
	 * \if English
	 * constructor
	 *
	 * @param other action to be repeated
	 * @param times repeat times
	 * \else
	 * 构造函数
	 *
	 * @param other 具体要执行的\link wyFiniteTimeAction wyFiniteTimeAction对象 \endlink指针
	 * @param times 动作重复的次数
	 * \endif
	 */
	wyRepeat(wyFiniteTimeAction* other, int times);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param other action to be repeated
	 * @param times repeat times
	 * \else
	 * 静态构造函数
	 *
	 * @param other 具体要执行的\link wyFiniteTimeAction wyFiniteTimeAction\endlink指针
	 * @param times 动作重复的次数
	 * \endif
	 */
	static wyRepeat* make(wyFiniteTimeAction* other, int times);

	virtual ~wyRepeat();

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

	/// @see wyAction::isDone
	virtual bool isDone();
};

#endif // __wyRepeat_h__
