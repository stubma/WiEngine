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
#ifndef __wyEaseElastic_h__
#define __wyEaseElastic_h__

#include "wyEaseAction.h"

/**
 * @class wyEaseElastic
 *
 * \if English
 * Elastic vibration wrap for linear action
 * \else
 * 基类，开发者可继承此类，实现自己的 EaseElastic action。SDK中提供了基于此基类的3个具体实现，
 * \link wyEaseElasticIn wyEaseElasticIn \endlink, \link wyEaseElasticOut wyEaseElasticOut \endlink，\link wyEaseElasticInOut wyEaseElasticInOut \endlink
 * \endif
 */
class WIENGINE_API wyEaseElastic : public wyEaseAction {
protected:
	/// vibration period
	float m_period;

public:
 	/**
 	 * \if English
 	 * Constructor
 	 *
 	 * @param period elastic vibration period, the smaller the value is, the faster it shakes
 	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
 	 * \else
	 * 构造函数
	 *
	 * @param period Elastic的波动周期，值越小，波动越快
	 * @param wrapped \link wyIntervalAction wyIntervalAction\endlink
	 * \endif
	 */
	wyEaseElastic(float period, wyIntervalAction* wrapped = NULL);

	virtual ~wyEaseElastic();
};

#endif // __wyEaseElastic_h__
