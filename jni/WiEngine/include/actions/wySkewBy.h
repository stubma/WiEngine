/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __wySkewBy_h__
#define __wySkewBy_h__

#include "wyIntervalAction.h"

/**
 * @class wySkewBy
 *
 * \if English
 * Skew x/y axis
 * \else
 * 改变x/y轴倾斜度的动作
 * \endif
 */
class WIENGINE_API wySkewBy : public wyIntervalAction {
private:
	/// skew x angle
	float m_skewX;

	/// skew y angle
	float m_skewY;

	/// start skew x
	float m_startSkewX;

	/// start skew y
	float m_startSkewY;

protected:
	/**
	 * Constructor
	 *
	 * @param duration action duration time in seconds
	 * @param skewX the angle between y axis and node left border, positive value means
	 * 		clockwise
	 * @param skewY the angle between x axis and node bottom border, positive value means
	 * 		clockwise
	 */
	wySkewBy(float duration, float skewX, float skewY);

public:
	/**
	 * \if English
	 * Static creator
	 *
	 * @param duration action duration time in seconds
	 * @param skewX the angle between y axis and node left border, positive value means
	 * 		clockwise
	 * @param skewY the angle between x axis and node bottom border, positive value means
	 * 		clockwise
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间, 秒
	 * @param skewX x方向变化的倾斜度, 表示y轴和节点左边界的夹角, 正值表示顺时针
	 * @param skewY y方向变化的倾斜度, 表示x轴和节点下边界的夹角, 正式表示顺时针
	 * \endif
	 */
	static wySkewBy* make(float duration, float skewX, float skewY);

	virtual ~wySkewBy();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wySkewBy_h__
