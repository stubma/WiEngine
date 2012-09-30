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
#ifndef __wyTintTo_h__
#define __wyTintTo_h__

#include "wyIntervalAction.h"

/**
 * @class wyTintTo
 *
 * \if English
 * It changes color between start color and end color
 * \else
 * 节点染色的动作封装,根据设置起始染色量进行移动
 * \endif
 */
class WIENGINE_API wyTintTo : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * red component of end color, from 0 to 255
	 * \else
	 * 目标红色值, 0到255
	 * \endif
	 */
	int m_toR;

	/**
	 * \if English
	 * green component of end color, from 0 to 255
	 * \else
	 * 目标绿色值, 0到255
	 * \endif
	 */
	int m_toG;

	/**
	 * \if English
	 * blue component of end color, from 0 to 255
	 * \else
	 * 目标蓝色值, 0到255
	 * \endif
	 */
	int m_toB;

	/**
	 * \if English
	 * delta value of red component
	 * \else
	 * 红色值变化值
	 * \endif
	 */
	int m_deltaR;

	/**
	 * \if English
	 * delta value of green component
	 * \else
	 * 绿色值变化值
	 * \endif
	 */
	int m_deltaG;

	/**
	 * \if English
	 * delta value of blue component
	 * \else
	 * 蓝色值变化值
	 * \endif
	 */
	int m_deltaB;

	/**
	 * \if English
	 * red component of start color, from 0 to 255
	 * \else
	 * 初始红色值, 0到255
	 * \endif
	 */
	int m_fromR;

	/**
	 * \if English
	 * green component of start color, from 0 to 255
	 * \else
	 * 初始绿色值, 0到255
	 * \endif
	 */
	int m_fromG;

	/**
	 * \if English
	 * blue component of start color, from 0 to 255
	 * \else
	 * 初始蓝色值, 0到255
	 * \endif
	 */
	int m_fromB;

protected:
	/**
	 * constructor
	 *
	 * @param duration duration time of action in seconds
	 * @param fromR red component of start color, from 0 to 255
	 * @param fromG green component of start color, from 0 to 255
	 * @param fromB blue component of start color, from 0 to 255
	 * @param toR red component of end color, from 0 to 255
	 * @param toG green component of end color, from 0 to 255
	 * @param toB blue component of end color, from 0 to 255
	 */
	wyTintTo(float duration, int fromR, int fromG, int fromB, int toR, int toG, int toB);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action in seconds
	 * @param fromR red component of start color, from 0 to 255
	 * @param fromG green component of start color, from 0 to 255
	 * @param fromB blue component of start color, from 0 to 255
	 * @param toR red component of end color, from 0 to 255
	 * @param toG green component of end color, from 0 to 255
	 * @param toB blue component of end color, from 0 to 255
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param fromR 初始红色值, 0到255
	 * @param fromG 初始绿色值, 0到255
	 * @param fromB 初始蓝色值, 0到255
	 * @param toR 目标红色值, 0到255
	 * @param toG 目标绿色值, 0到255
	 * @param toB 目标蓝色值, 0到255
	 * \endif
	 */
	static wyTintTo* make(float duration, int fromR, int fromG, int fromB, int toR, int toG, int toB);

	virtual ~wyTintTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyTintTo_h__
