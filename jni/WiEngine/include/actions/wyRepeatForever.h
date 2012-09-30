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
#ifndef __wyRepeatForever_h__
#define __wyRepeatForever_h__

#include "wyIntervalAction.h"

/**
 * @class wyRepeatForever
 *
 * \if English
 * repeat an action forever
 * \else
 * 不断重复执行某个动作的封装
 * \endif
 */
class WIENGINE_API wyRepeatForever : public wyAction {
protected:
	/**
	 * \if English
	 * action to be repeated
	 * \else
	 * 具体要执行的\link wyIntervalAction wyIntervalAction对象 \endlink指针
	 * \endif
	 */
	wyIntervalAction* m_other;

protected:
	/**
	 * \if English
	 * constructor
	 *
	 * @param other action to be repeated
	 * \else
	 * 构造函数
	 *
	 * @param other 具体执行的 \link wyIntervalAction wyIntervalAction对象 \endlink指针
	 * \endif
	 */
	wyRepeatForever(wyIntervalAction* other);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param other action to be repeated
	 * \else
	 * 静态构造方法
	 *
	 * @param other 具体执行的 \link wyIntervalAction wyIntervalAction对象 \endlink指针
	 * \endif
	 */
	static wyRepeatForever* make(wyIntervalAction* other);

	virtual ~wyRepeatForever();

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
};

#endif // __wyRepeatForever_h__
