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
#ifndef __wyEaseBackOut_h__
#define __wyEaseBackOut_h__

#include "wyEaseAction.h"

/**
 * @class wyEaseBackOut
 *
 * \if English
 * See demo EaseActions\\EaseBackOut.
 * \else
 * 详细了解可见示例 EaseActions\\EaseBackOut
 * \endif
 */
class WIENGINE_API wyEaseBackOut : public wyEaseAction {
public:
	/**
	 * \if English
	 * Create a ease back in instance
	 *
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * @return \link wyEaseBackOut wyEaseBackOut\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param wrapped 线性动作的\link wyIntervalAction wyIntervalAction\endlink的指针
	 * @return \link wyEaseBackOut wyEaseBackOut\endlink
	 * \endif
	 */
	static wyEaseBackOut* make(wyIntervalAction* wrapped = NULL);

	/**
	 * \if English
	 * Constructor
	 *
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * \else
	 * 构造函数
	 *
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * \endif
	 */
	wyEaseBackOut(wyIntervalAction* wrapped = NULL);
		 
	virtual ~wyEaseBackOut();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyEaseBackOut_h__
