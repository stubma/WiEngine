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
#ifndef __wyEaseInOut_h__
#define __wyEaseInOut_h__

#include "wyEaseRateAction.h"

/**
 * @class wyEaseInOut
 *
 * \if English
 * See demo EaseActions\\EaseInOut.
 * \else
 * 详细了解可见示例 EaseActions\\EaseInOut.
 * \endif
 */
class WIENGINE_API wyEaseInOut : public wyEaseRateAction {
public:
	/**
	 * \if English
	 * Static creator
	 *
	 * @param rate non-linear transform rate
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * @return \link wyEaseInOut wyEaseInOut\endlink
	 * \else
	 * 静态创建函数
	 *
	 * @param rate 控制非线性变换幅度的参数
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * @return \link wyEaseInOut wyEaseInOut\endlink
	 * \endif
	 */
	static wyEaseInOut* make(float rate, wyIntervalAction* wrapped = NULL);

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
	wyEaseInOut(float rate, wyIntervalAction* wrapped = NULL);

	virtual ~wyEaseInOut();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();
	
	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyEaseInOut_h__
