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
#ifndef __wyVerletPoint_h__
#define __wyVerletPoint_h__

#include "wyObject.h"
#include "WiEngine-Classes.h"

/**
 * @class wyVerletPoint
 *
 * \if English
 * A point in a verlet rope
 * \else
 * 封装绳子中的一点，这个点跟踪其之前的某个位置状态, 从而可以计算变化幅度
 * \endif
 */
class WIENGINE_API wyVerletPoint : public wyObject {
	friend class wyVerletStick;
	friend class wyVerletRope;

private:
	/**
	 * \if English
	 * current x value
	 * \else
	 * 当前x值
	 * \endif
	 */
	float m_x;

	/**
	 * \if English
	 * current y value
	 * \else
	 * 当前y值
	 * \endif
	 */
	float m_y;

	/**
	 * \if English
	 * previous x value
	 * \else
	 * 上一次的x值
	 * \endif
	 */
	float m_oldX;

	/**
	 * \if English
	 * previous y value
	 * \else
	 * 上一次的y值
	 * \endif
	 */
	float m_oldY;

public:
	wyVerletPoint();
	virtual ~wyVerletPoint();

	/**
	 * \if English
	 * Set position
	 *
	 * @param x x position
	 * @param y y position
	 * \else
	 * 设置位置
	 *
	 * @param x x位置
	 * @param y y位置
	 * \endif
	 */
	void setPosition(float x, float y);

	/**
	 * \if English
	 * Update point
	 * \else
	 * 让原始值变成当前值，当前值加上和原来原始值的差值
	 * \endif
	 */
	void update();

	/**
	 * \if English
	 * Apply gravity to this point
	 *
	 * @param dt delta time
	 * \else
	 * 应用重力
	 *
	 * @param dt delta时间
	 * \endif
	 */
	void applyGravity(float dt);

	/**
	 * \if English
	 * Set x position
	 *
	 * @param x x position
	 * \else
	 * 设置x位置
	 *
	 * @param x x位置
	 * \endif
	 */
	void setX(float x) { m_x = x; }

	/**
	 * \if English
	 * Set y position
	 *
	 * @param y y position
	 * \else
	 * 设置y位置
	 *
	 * @param y y位置
	 * \endif
	 */
	void setY(float y) { m_y = y; }

	/**
	 * \if English
	 * Get x position
	 *
	 * @return x position
	 * \else
	 * 得到x值
	 *
	 * @return x值
	 * \endif
	 */
	float getX() { return m_x; }

	/**
	 * \if English
	 * Get y position
	 *
	 * @return y position
	 * \else
	 * 得到y值
	 *
	 * @return y值
	 * \endif
	 */
	float getY() { return m_y; }

	/**
	 * \if English
	 * Attenuate waving
	 *
	 * @param percent percent to be reduced
	 * \else
	 * 衰减，用于控制振荡幅度
	 *
	 * @param percent 衰减幅度
	 * \endif
	 */
	void attenuate(float percent);

	/**
	 * \if English
	 * Clone this point object
	 *
	 * @return \link wyVerletPoint wyVerletPoint\endlink
	 * \else
	 * 复制一份verlet point对象，返回的对象已经被autorelease
	 *
	 * @return \link wyVerletPoint wyVerletPoint\endlink
	 * \endif
	 */
	wyVerletPoint* copy();
};

#endif // __wyVerletPoint_h__
