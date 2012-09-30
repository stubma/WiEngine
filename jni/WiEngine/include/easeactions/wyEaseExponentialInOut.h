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
#ifndef __wyEaseExponentialInOut_h__
#define __wyEaseExponentialInOut_h__

#include "wyEaseAction.h"

/**
 * @class wyEaseExponentialInOut
 *
 * \if English
 * See demo EaseActions\\EaseExponentialInOut.
 * \else
 * 详细了解可见示例 EaseActions\\EaseExponentialInOut.
 * \endif
 */
class WIENGINE_API wyEaseExponentialInOut : public wyEaseAction {
public:
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * @return \link wyEaseExponentialInOut wyEaseExponentialInOut\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * @return \link wyEaseExponentialInOut wyEaseExponentialInOut\endlink
	 * \endif
	 */
	static wyEaseExponentialInOut* make(wyIntervalAction* wrapped = NULL);

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
	wyEaseExponentialInOut(wyIntervalAction* wrapped = NULL);

	virtual ~wyEaseExponentialInOut();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyEaseExponentialInOut_h__
