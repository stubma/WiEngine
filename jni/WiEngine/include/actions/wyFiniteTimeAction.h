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
#ifndef __wyFiniteTimeAction_h__
#define __wyFiniteTimeAction_h__

#include "wyAction.h"

/**
 * @class wyFiniteTimeAction
 *
 * \if English
 * Base class for actions whose time is definite
 * \else
 * 用于表示在有限时间内可以完成的动作
 * \endif
 */
class WIENGINE_API wyFiniteTimeAction : public wyAction {
	friend class wyRepeat;
	friend class wyRepeatForever;

protected:
	/**
	 * \if English
	 * time already passed
	 * \else
	 * 动作已经持续的时间
	 * \endif
	 */
	float m_elapsed;

	/**
	 * \if English
	 * duration time of action
	 * \else
	 * 动作持续的时间
	 * \endif
	 */
	float m_duration;

	/**
	 * \if English
	 * true indicating it is the first time to update action, it is set to ensure action starts from beginning
	 * \else
	 * true表示是第一次更新, 用于设置初始状态，保证动作从初始状态开始执行
	 * \endif
	 */
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
	 * \if English
	 * Get duration time of action
	 *
	 * @return duration time of action
	 * \else
	 * 获得动作持续时间长度
	 *
	 * @return 动作持续时间长度
	 * \endif
	 */
	float getDuration();

	/**
	 * \if English
	 * Set duration time of action, no effect if action is started
	 *
	 * @param duration duration time of action
	 * \else
	 * 设置动作持续时间长度, 如果动作已经开始执行, 设置不会有效果
	 *
	 * @param duration 动作持续时间长度
	 * \endif
	 */
	void setDuration(float duration);

	/**
	 * \if English
	 * Get elapsed time of this action
	 *
	 * @return elapsed time in second
	 * \else
	 * 获得动作已经持续的时间
	 *
	 * @return 动作已经持续的时间
	 * \endif
	 */
	float getElapsed() { return m_elapsed; }

	/**
	 * \if English
	 * Set elapsed time of action, don't call it if you do not know what will happen. Mainly used by internal logic.
	 *
	 * @param e elapsed time
	 * \else
	 * 设置动作已经持续的时间，只应在一些特殊情况下调用该方法
	 *
	 * @param e 已经过去的时间
	 * \endif
	 */
	void setElapsed(float e) { m_elapsed = e; }
};

#endif // __wyFiniteTimeAction_h__
