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
#ifndef __wySpeed_h__
#define __wySpeed_h__

#include "wyIntervalAction.h"
#include "wyTypes.h"
#include "wyUtils.h"

/**
 * @class wySpeed
 *
 * \if English
 * Accelerate or deaccelerate an action
 * \else
 * 加减速动作。相当于快镜头慢镜头，可以指定一个速度因子，比如2，则目标动作将会加快2倍。
 * \endif
 */
class WIENGINE_API wySpeed : public wyAction {
protected:
	/**
	 * \if English
	 * the \link wyAction wyAction \endlink need to be speed up or down
	 * \else
	 * 具体执行的\link wyAction wyAction \endlink对象指针
	 * \endif
	 */
	wyAction* m_other;

	/**
	 * \if English
	 * the coefficient of speed up or down
	 * \else
	 * 加速或减速的速率，大于1为加速，取值必须大于0
	 * \endif
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
	 * \if English
	 * static factory method
	 *
	 * @param other the \link wyAction wyAction \endlink need to be speed up or down
	 * @param speed the coefficient of speed up or down
	 * \else
	 * 静态构造函数
	 *
	 * @param other 具体执行的 \link wyAction wyAction \endlink对象指针
	 * @param speed 加速或减速的速率，大于1为加速，取值必须大于0
	 * \endif
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
	 * \if English
	 * get coefficient of speed
	 *
	 * @return coefficient of speed
	 * \else
	 * 获得加速或减速的速率
	 *
	 * @return 加速或减速的速率
	 * \endif
	 */
	float getSpeed() { return m_speed; }

	/**
	 * \if English
	 * set coefficient of speed
	 *
	 * @param speed Coefficient of speed, if larger than 1 then it means acceleration.
	 * 		Can't set a negative value
	 * \else
	 * 设置加速或减速的速率
	 *
	 * @param speed 加速或减速的速率，大于1为加速
	 * \endif
	 */
	void setSpeed(float speed) { m_speed = MAX(0, speed); }
};

#endif // __wySpeed_h__
