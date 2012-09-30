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
#ifndef __wyEaseBounceInOut_h__
#define __wyEaseBounceInOut_h__

#include "wyEaseBounce.h"

/**
 * @class wyEaseBounceInOut
 *
 * \if English
 * See demo EaseActions\\EaseBounceInOut.
 * \else
 * 详细了解可见示例 EaseActions\\EaseBounceInOut.
 * \endif
 */
class WIENGINE_API wyEaseBounceInOut : public wyEaseBounce {
public:
	/**
	 * \if English
	 * Static creator
	 *
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * \else
	 * 静态创建函数
	 *
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * \endif
	 */
	static wyEaseBounceInOut* make(wyIntervalAction* wrapped = NULL);

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
	wyEaseBounceInOut(wyIntervalAction* wrapped = NULL);

	virtual ~wyEaseBounceInOut();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyEaseBounceInOut_h__
