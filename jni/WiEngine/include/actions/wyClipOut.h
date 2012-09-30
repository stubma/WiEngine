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
#ifndef __wyClipOut_h__
#define __wyClipOut_h__

#include "wyIntervalAction.h"

/**
 * @class wyClipOut
 *
 * \if English
 * Dynamic change clip rect of node to get an exit animation
 * \else
 * 动态的改变节点的裁剪区域从而得到一个逐渐隐藏的效果, 类似于愤怒小鸟中的菜单隐藏效果
 * \endif
 */
class WIENGINE_API wyClipOut : public wyIntervalAction {
public:
	/**
	 * \if English
	 * Direction to which clip rect moves
	 * \else
	 * 裁剪区域渐变的方向
	 * \endif
	 */
	enum Direction {
		/**
		 * \if English
		 * clip shrinks from left to right side
		 * \else
		 * 从左边开始隐藏到右边
		 * \endif
		 */
		LEFT_TO_RIGHT,

		/**
		 * \if English
		 * clip shrinks from right to left side
		 * \else
		 * 从右边开始隐藏到左边
		 * \endif
		 */
		RIGHT_TO_LEFT,

		/**
		 * \if English
		 * clip shrinks from top to bottom side
		 * \else
		 * 从上边开始隐藏到下边
		 * \endif
		 */
		TOP_TO_BOTTOM,

		/**
		 * \if English
		 * clip shrinks from bottom to top side
		 * \else
		 * 从下边开始隐藏到上边
		 * \endif
		 */
		BOTTOM_TO_TOP
	};

private:
	/// clip shrink direction
	Direction m_direction;

protected:
	/**
	 * Constructor
	 *
	 * @param duration action duration in seconds
	 * @param direction clip shrink direction
	 */
	wyClipOut(float duration, Direction direction);

public:
	virtual ~wyClipOut();

	/**
	 * \if English
	 * Create a clip out action
	 *
	 * @param duration action duration in seconds
	 * @param direction clip shrink direction, default is \c TOP_TO_BOTTOM
	 * @return \link wyClipOut wyClipOut\endlink
	 * \else
	 * 创建一个clip out动作
	 *
	 * @param duration 动作支持时间, 单位秒
	 * @param direction 裁剪区域变化的方向, 缺省是从上到下
	 * @return \link wyClipOut wyClipOut\endlink
	 * \endif
	 */
	static wyClipOut* make(float duration, Direction direction = TOP_TO_BOTTOM);

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::stop
	virtual void stop();
};

#endif // __wyClipOut_h__
