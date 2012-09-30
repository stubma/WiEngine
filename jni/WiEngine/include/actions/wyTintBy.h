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
#ifndef __wyTintBy_h__
#define __wyTintBy_h__

#include "wyIntervalAction.h"

/**
 * @class wyTintBy
 *
 * \if English
 * It changes color of node by a delta value
 * \else
 * 节点染色的动作封装,根据设置染色量进行移动
 * \endif
 */
class WIENGINE_API wyTintBy : public wyIntervalAction {
protected:
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
	 * @param r delta value of red component
	 * @param g delta value of green component
	 * @param b delta value of blue component
	 */
	wyTintBy(float duration, int r, int g, int b);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action in seconds
	 * @param r delta value of red component
	 * @param g delta value of green component
	 * @param b delta value of blue component
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param r 红色值变化值
	 * @param g 绿色值变化值
	 * @param b 蓝色值变化值
	 * \endif
	 */
	static wyTintBy* make(float duration, int r, int g, int b);

	virtual ~wyTintBy();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyTintBy_h__
