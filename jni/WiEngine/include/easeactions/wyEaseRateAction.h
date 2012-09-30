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
#ifndef __wyEaseRateAction_h__
#define __wyEaseRateAction_h__

#include "wyEaseAction.h"

/**
 * @class wyEaseRateAction
 *
 * \if English
 * base class of rate actions
 * \else
 * 基类，开发者可继承此类，实现自己的 EaseRate action。SDK中提供了基于此基类的3个具体实现，
 * \link wyEaseIn wyEaseIn\endlink, \link wyEaseOut wyEaseOut\endlink，\link wyEaseInOut wyEaseInOut\endlink
 * \endif
 */
class WIENGINE_API wyEaseRateAction : public wyEaseAction {
protected:
	/// non-linear transform rate
	float m_rate;

public:
	/**
	 * \if English
	 * Constructor
	 *
	 * @param rate non-linear transform rate
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * \else
	 * 构造函数
	 *
	 * @param rate 控制非线性变换幅度的参数
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * \endif
	 */
	wyEaseRateAction(float rate, wyIntervalAction* wrapped = NULL);

	virtual ~wyEaseRateAction();
};

#endif // __wyEaseRateAction_h__
