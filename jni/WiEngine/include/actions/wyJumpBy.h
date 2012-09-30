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
#ifndef __wyJumpBy_h__
#define __wyJumpBy_h__

#include "wyIntervalAction.h"
#include "wyTypes.h"

/**S
 * @class wyJumpBy
 *
 * \if English
 * A node jumps from current position to elsewhere, the jumping can be adjusted by offset, height and times
 * \else
 * 节点跳跃的动作封装,根据设置偏移量，高度，跳跃次数进行移动
 * \endif
 */
class WIENGINE_API wyJumpBy : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * start position
	 * \else
	 * 节点的起始位置 \link wyPoint wyPoint对象 \endlink
	 * \endif
	 */
	wyPoint m_startPosition;

	/**
	 * \if English
	 * jump offset in two directions
	 * \else
	 * 节点偏移位置 \link wyPoint wyPoint对象 \endlink
	 * \endif
	 */
	wyPoint m_delta;

	/**
	 * \if English
	 * height of jumping
	 * \else
	 * 节点跳跃的高度
	 * \endif
	 */
	float m_height;

	/**
	 * \if English
	 * times of jumping
	 * \else
	 * 节点跳跃的次数
	 * \endif
	 */
	int m_jumps;

protected:
	/**
	 * Constructor
	 *
	 * @param duration duration time of action
	 * @param x jump offset in x axis
	 * @param y jump offset in y axis
	 * @param height height of jumping
	 * @param jumps times of jumping
	 */
	wyJumpBy(float duration, float x, float y, float height, int jumps);

public:
	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration duration time of action
	 * @param x jump offset in x axis
	 * @param y jump offset in y axis
	 * @param height height of jumping
	 * @param jumps times of jumping
	 * @return \link wyJumpBy wyJumpBy\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param x 节点偏移x轴距离
	 * @param y 节点偏移y轴距离
	 * @param height 节点跳跃的高度
	 * @param jumps 节点跳跃的次数
	 * @return \link wyJumpBy wyJumpBy\endlink
	 * \endif
	 */
	static wyJumpBy* make(float duration, float x, float y, float height, int jumps);

	virtual ~wyJumpBy();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyJumpBy_h__
