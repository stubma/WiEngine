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
#ifndef __wyJumpTo_h__
#define __wyJumpTo_h__

#include "wyIntervalAction.h"
#include "wyTypes.h"

/**
 * @class wyJumpTo
 *
 * \if English
 * A node jumps from a position to elsewhere, the jumping can be adjusted by offset, height and times
 * \else
 * 节点跳跃的动作封装,根据设置起始点，结束点，高度，跳跃次数进行移动
 * \endif
 */
class WIENGINE_API wyJumpTo : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * start x position of jumping
	 * \else
	 * 起始点x轴坐标
	 * \endif
	 */
	float m_startX;

	/**
	 * \if English
	 * start y position of jumping
	 * \else
	 * 起始点y轴坐标
	 * \endif
	 */
	float m_startY;

	/**
	 * \if English
	 * end x position of jumping
	 * \else
	 * 结束点x轴坐标
	 * \endif
	 */
	float m_endX;

	/**
	 * \if English
	 * end y position of jumping
	 * \else
	 * 结束点y轴坐标
	 * \endif
	 */
	float m_endY;

	/**
	 * \if English
	 * offset between start x and end x
	 * \else
	 * 偏移x距离
	 * \endif
	 */
	float m_deltaX;

	/**
	 * \if English
	 * offset between start y and end y
	 * \else
	 * 偏移y距离
	 * \endif
	 */
	float m_deltaY;

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
	 * @param duration duration time of jumping
	 * @param startX start x position of jumping
	 * @param startY start y position of jumping
	 * @param endX end x position of jumping
	 * @param endY end y position of jumping
	 * @param height height of jumping
	 * @param jumps times of jumping
	 */
	wyJumpTo(float duration, float startX, float startY, float endX, float endY, float height, int jumps);

public:
	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration duration time of jumping
	 * @param startX start x position of jumping
	 * @param startY start y position of jumping
	 * @param endX end x position of jumping
	 * @param endY end y position of jumping
	 * @param height height of jumping
	 * @param jumps times of jumping
	 * @return \link wyJumpTo wyJumpTo\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startX 起始点x轴坐标
	 * @param startY 起始点y轴坐标
	 * @param endX 结束点y轴坐标
	 * @param endY 结束点y轴坐标
	 * @param height 节点跳跃的高度
	 * @param jumps 节点跳跃的次数
	 * @return \link wyJumpTo wyJumpTo\endlink
	 * \endif
	 */
	static wyJumpTo* make(float duration, float startX, float startY, float endX, float endY, float height, int jumps);

	virtual ~wyJumpTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyJumpTo_h__
