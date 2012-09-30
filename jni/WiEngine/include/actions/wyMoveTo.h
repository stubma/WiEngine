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
#ifndef __wyMoveTo_h__
#define __wyMoveTo_h__

#include "wyIntervalAction.h"
#include "wyTypes.h"

/**
 * @class wyMoveTo
 *
 * \if English
 * Move a node from a place to other place. You should set start and end position
 * for node.
 * \else
 * 节点移动的动作封装,根据设置起始点，结束点进行移动
 * \endif
 */
class WIENGINE_API wyMoveTo : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * start x position
	 * \else
	 * 起始点x轴坐标
	 * \endif
	 */
	float m_startX;

	/**
	 * \if English
	 * start y position
	 * \else
	 * 起始点y轴坐标
	 * \endif
	 */
	float m_startY;

	/**
	 * \if English
	 * end x position
	 * \else
	 * 结束点x轴坐标
	 * \endif
	 */
	float m_endX;

	/**
	 * \if English
	 * end y position
	 * \else
	 * 结束点y轴坐标
	 * \endif
	 */
	float m_endY;

	/**
	 * \if English
	 * offset between start x and end x position
	 * \else
	 * 偏移x距离
	 * \endif
	 */
	float m_deltaX;

	/**
	 * \if English
	 * offset between start y and end y position
	 * \else
	 * 偏移y距离
	 * \endif
	 */
	float m_deltaY;

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
	 * constructor
	 *
	 * @param duration duration time of this action, in second
	 * @param startX start x position
	 * @param startY start y position
	 * @param endX end x position
	 * @param endY end y position
	 */
	wyMoveTo(float duration, float startX, float startY, float endX, float endY);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of this action, in second
	 * @param startX start x position
	 * @param startY start y position
	 * @param endX end x position
	 * @param endY end y position
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startX 起始点x轴坐标
	 * @param startY 起始点y轴坐标
	 * @param endX 结束点y轴坐标
	 * @param endY 结束点y轴坐标
	 * \endif
	 */
	static wyMoveTo* make(float duration, float startX, float startY, float endX, float endY);

	virtual ~wyMoveTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

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

#endif // __wyMoveTo_h__
