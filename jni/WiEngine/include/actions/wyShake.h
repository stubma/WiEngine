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
#ifndef __wyShake_h__
#define __wyShake_h__

#include "wyIntervalAction.h"

/**
 * @class wyShake
 *
 * \if English
 * node is moved randomly in a circle area fast, looks like shaking
 * \else
 * 节点在一个圆形区域范围内随机移动, 造成抖动的效果
 * \endif
 */
class WIENGINE_API wyShake : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * radius of shaking area
	 * \else
	 * 抖动半径
	 * \endif
	 */
	float m_radius;

	/**
	 * \if English
	 * original x position of node
	 * \else
	 * 原始的x位置
	 * \endif
	 */
	float m_originalX;

	/**
	 * \if English
	 * original y position of node
	 * \else
	 * 原始的y位置
	 * \endif
	 */
	float m_originalY;

protected:
	/**
	 * constructor
	 *
	 * @param duration duration time of action in seconds
	 * @param radius radius of shaking area
	 */
	wyShake(float duration, float radius);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action in seconds
	 * @param radius radius of shaking area
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param radius 抖动半径, 节点在不超过这个半径的圆内抖动
	 * \endif
	 */
	static wyShake* make(float duration, float radius);

	virtual ~wyShake();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);

	/// @see wyAction::start
	virtual void start(wyNode* target);
};

#endif // __wyShake_h__
