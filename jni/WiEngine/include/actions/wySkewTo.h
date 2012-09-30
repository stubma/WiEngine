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
#ifndef __wySkewTo_h__
#define __wySkewTo_h__

#include "wyIntervalAction.h"

/**
 * @class wySkewTo
 *
 * \if English
 * Skew x/y axis
 * \else
 * 改变x/y轴倾斜度的动作
 * \endif
 */
class WIENGINE_API wySkewTo : public wyIntervalAction {
protected:
	/// start skew x
	float m_startSkewX;

	/// start skew y
	float m_startSkewY;

	/// end skew x
	float m_endSkewX;

	/// end skew y
	float m_endSkewY;

	/// delta skew x
	float m_deltaX;

	/// delta skew y
	float m_deltaY;

protected:
	/**
	 * constructor
	 *
	 * @param duration duration time in seconds
	 * @param startSkewX start x skew degree
	 * @param endSkewX end x skew degree
	 * @param startSkewY start y skew degree
	 * @param endSkewY end y skew degree
	 */
	wySkewTo(float duration, float startSkewX, float endSkewX, float startSkewY, float endSkewY);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time in seconds
	 * @param startSkewX start x skew degree
	 * @param endSkewX end x skew degree
	 * @param startSkewY start y skew degree
	 * @param endSkewY end y skew degree
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startSkewX 起始x倾斜角度
	 * @param endSkewX 结束x倾斜角度
	 * @param startSkewY 起始y倾斜角度
	 * @param endSkewY 结束y倾斜角度
	 * \endif
	 */
	static wySkewTo* make(float duration, float startSkewX, float endSkewX, float startSkewY, float endSkewY);

	virtual ~wySkewTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wySkewTo_h__
