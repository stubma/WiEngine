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
#ifndef __wySequence_h__
#define __wySequence_h__

#include "wyIntervalAction.h"
#include "wyArray.h"

/**
 * @class wySequence
 *
 * \if English
 * execute actions one by one
 * \else
 * 按顺序执行一组动作的封装
 * \endif
 */
class WIENGINE_API wySequence : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * action array
	 * \else
	 * 所有动作的\link wyArray wyArray \endlink对象指针
	 * \endif
	 */
	wyArray* m_actions;

	/**
	 * \if English
	 * the time split of two actions
	 * \else
	 * 两个动作的时间区分点
	 * \endif
	 */
	float m_split;

	/**
	 * \if English
	 * current action index, 0 for first, 1 for second
	 * \else
	 * 当前执行的动作index
	 * \endif
	 */
	int m_last;

private:
	static bool releaseAction(wyArray* arr, void* ptr, int index, void* data);
	static bool stopAction(wyArray* arr, void* ptr, int index, void* data);

protected:
	/**
	 * constructor
	 *
	 * @param action1 first action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction\endlink
	 * @param action2 second action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction\endlink
	 */
	wySequence(wyFiniteTimeAction* action1, wyFiniteTimeAction* action2);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param action1 first action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction\endlink
	 * @param action2 second action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction\endlink, you can append more
	 * 		actions after this one and end with a NULL
	 * @return \link wySequence wySequence\endlink
	 * \else
	 * 构造\link wySequence wySequence \endlink对象指针
	 *
	 * @param action1 要执行的动作\link wyFiniteTimeAction wyFiniteTimeAction \endlink对象指针
	 * @param action2 要执行的动作\link wyFiniteTimeAction wyFiniteTimeAction \endlink对象指针，
	 * 后面还可以添加多个\link wyFiniteTimeAction wyFiniteTimeAction \endlink对象指针，参数以NULL结束
	 * @return \link wySequence wySequence \endlink对象指针
	 * \endif
	 */
	static wySequence* make(wyFiniteTimeAction* action1, wyFiniteTimeAction* action2, ...);

	virtual ~wySequence();

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

#endif // __wySequence_h__
