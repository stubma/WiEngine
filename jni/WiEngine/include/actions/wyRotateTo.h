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
#ifndef __wyRotateTo_h__
#define __wyRotateTo_h__

#include "wyIntervalAction.h"

/**
 * @class wyRotateTo
 *
 * \if English
 * Rotate a node. For a node, position value means clockwise and negative value means
 * counter-clockwise.
 * \else
 * 节点旋转的动作封装,根据设置旋转起始度数进行节点旋转
 * \endif
 */
class WIENGINE_API wyRotateTo : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * delta angle in degree, computed from start and end angle
	 * \else
	 * 节点在动作内要旋转的角度
	 * \endif
	 */
	float m_delta;

	/**
	 * \if English
	 * start angle of node, in degree
	 * \else
	 * 节点初始的角度
	 * \endif
	 */
	float m_startAngle;

	/**
	 * \if English
	 * end angle of node, in degree
	 * \else
	 * 节点目标的角度
	 * \endif
	 */
	float m_endAngle;

protected:
	/**
	 * constructor
	 *
	 * @param duration duration time in seconds
	 * @param startAngle start angle in degree
	 * @param endAngle end angle in degree
	 */
	wyRotateTo(float duration, float startAngle, float endAngle);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time in seconds
	 * @param startAngle start angle in degree
	 * @param endAngle end angle in degree
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startAngle 节点初始的角度
	 * @param endAngle 节点目标的角度
	 * \endif
	 */
	static wyRotateTo* make(float duration, float startAngle, float endAngle);

	virtual ~wyRotateTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyRotateTo_h__
