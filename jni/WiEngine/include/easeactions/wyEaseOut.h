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
#ifndef __wyEaseOut_h__
#define __wyEaseOut_h__

#include "wyEaseRateAction.h"

/**
 * @class wyEaseOut
 *
 * \if English
 * See demo EaseActions\\EaseOut.
 * \else
 * 详细了解可见示例 EaseActions\\EaseOut.
 * \endif
 */
class WIENGINE_API wyEaseOut : public wyEaseRateAction {
public:
	/**
	 * \if English
	 * Static creator
	 *
	 * @param rate non-linear transform rate
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * @return \link wyEaseOut wyEaseOut\endlink
	 * \else
	 * 静态创建函数
	 *
	 * @param rate 控制非线性变换幅度的参数
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * @return \link wyEaseOut wyEaseOut\endlink
	 * \endif
	 */
    static wyEaseOut* make(float rate, wyIntervalAction* wrapped = NULL);

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
    wyEaseOut(float rate, wyIntervalAction* wrapped = NULL);

	virtual ~wyEaseOut();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyEaseOut_h__
