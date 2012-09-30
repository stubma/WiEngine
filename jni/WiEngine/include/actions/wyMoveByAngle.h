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
#ifndef __wyMoveByAngle_h__
#define __wyMoveByAngle_h__

#include "wyIntervalAction.h"
#include "wyTypes.h"

/**
 * @class wyMoveByAngle
 *
 * \if English
 * Move a node by set a direction in angle and a velocity
 * \else
 * 根据角度和速度移动的动作封装
 * \endif
 */
class WIENGINE_API wyMoveByAngle : public wyIntervalAction {
private:
	/**
	 * \if English
	 * start x position
	 * \else
	 * 起始x坐标
	 * \endif
	 */
	float m_startX;

	/**
	 * \if English
	 * start y position
	 * \else
	 * 起始y坐标
	 * \endif
	 */
	float m_startY;

	/**
	 * \if English
	 * node velocity
	 * \else
	 * 速度
	 * \endif
	 */
	int m_velocity;

	/**
	 * \if English
	 * direction in angel, 0 degree means follows the x axis. positive value
	 * means clockwise direction.
	 * \else
	 * 移动的角度, 正直表示顺时针方向, 负值表示逆时针方向
	 * \endif
	 */
	int m_degree;

	/**
	 * \if English
	 * direction in radian
	 * \else
	 * 移动的弧度, 通过(degree * M_PI / 180)计算获得
	 * \endif
	 */
	float m_radian;

	/**
	 * \if English
	 * cos value of move direction
	 * \else
	 * cos(m_radian)值
	 * \endif
	 */
	float m_cosRadian;

	/**
	 * \if English
	 * sin value of move direction
	 * \else
	 * -sin(m_radian)值
	 * \endif
	 */
	float m_sinRadian;

	/**
	 * \if English
	 * Pin point. When moving, node's rotation will be set to angle of line
	 * between node anchor and pin point
	 * \else
	 * 一个固定点, 用全局坐标指定, 当物体移动时, 物体的旋转角度将根据物体锚点
	 * 和这个固定点之间连线的角度确定. 这个固定点可以动态的修改, 因此可以实现
	 * 移动节点对固定或者移动物体的跟踪功能.
	 * \endif
	 */
	wyPoint m_pinPoint;

	/**
	 * \if English
	 * angle delta added to node rotation when pin point is set
	 * \else
	 * 在根据pin point设置节点的旋转角度时, 可以设置一个附加角度偏移量
	 * \endif
	 */
	float m_pinDelta;

protected:
	/**
	 * Constructor
	 *
	 * @param duration duration time of action
	 * @param degree move direction in angle
	 * @param velocity move velocity
	 */
	wyMoveByAngle(float duration, int degree, int velocity);

public:
	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration duration time of action
	 * @param degree move direction in angle
	 * @param velocity move velocity
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param degree 节点移动的角度
	 * @param velocity 节点移动的速度
	 * \endif
	 */
	static wyMoveByAngle* make(float duration, int degree, int velocity);

	virtual ~wyMoveByAngle();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);

	/**
	 * \if English
	 * set pin point
	 *
	 * @param p global coordinate of pin point
	 * \else
	 * 设置pin point
	 *
	 * @param p pin point的全局坐标
	 * \endif
	 */
	void setPinPoint(wyPoint p) { m_pinPoint = p; }

	/**
	 * \if English
	 * set pin point
	 *
	 * @param x global x location of pin point
	 * @param y global y location of pin point
	 * \else
	 * 设置pin point
	 *
	 * @param x pin point的全局x位置
	 * @param y pin point的全局y位置
	 * \endif
	 */
	void setPinPoint(float x, float y) { m_pinPoint = wyp(x, y); }

	/**
	 * \if English
	 * get pin point
	 *
	 * @return global coordinate of pin point
	 * \else
	 * 得到pin point
	 *
	 * @return pin point的全局坐标
	 * \endif
	 */
	wyPoint getPinPoint() { return m_pinPoint; }

	/**
	 * \if English
	 * clear pin point
	 * \else
	 * 清除掉pin point, 这样节点移动时将不再自动对准pin point
	 * \endif
	 */
	void clearPinPoint() { m_pinPoint = wyp(MAX_FLOAT, MAX_FLOAT); }

	/**
	 * \if English
	 * set angle delta of pin point rotation
	 *
	 * @param angle to be added to node rotation
	 * \else
	 * 设置附加角度, 仅当pin point被设置时有效
	 *
	 * @param delta 附加角度
	 * \endif
	 */
	void setPinAngleDelta(float delta) { m_pinDelta = delta; }

	/**
	 * \if English
	 * get angle delta
	 *
	 * @return angle delta
	 * \else
	 * 得到附加角度
	 *
	 * @return 附加角度
	 * \endif
	 */
	float getPinAngleDelta() { return m_pinDelta; }
};

#endif // __wyMoveByAngle_h__
