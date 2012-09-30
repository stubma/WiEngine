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
#ifndef __wyLagrange_h__
#define __wyLagrange_h__

#include "wyIntervalAction.h"
#include "wyTypes.h"

/**
 * @class wyLagrange
 *
 * \if English
 * Move a \link wyNode wyNode\endlink in track of Lagrange curve
 * \else
 * 节点按照拉格朗日曲线轨迹运动的动作封装
 * \endif
 */
class WIENGINE_API wyLagrange : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * description of lagrange curve
	 * \else
	 * 拉格朗日曲线的描述结构
	 * \endif
	 */
	wyLagrangeConfig m_config;

	/**
	 * \if English
	 * true means enable auto rotate, it means the node move by lagrange path will be aligned
	 * with path direction.
	 * \else
	 * true表示打开自动旋转，打开自动旋转表示移动的节点会自动保持和路径方向一致.
	 * \endif
	 */
	bool m_autoRotate;
	
	/**
	 * \if English
	 * the delta to be added to path direction. Position value means
	 * clockwise, negative value means counter-clockwise
	 * \else
	 * 预设的角度，假如是-90，而当前路径的朝向是180度，那么最终节点将被设置为90度.
	 * 这里正值表示顺时针旋转，负值表示逆时针旋转
	 * \endif
	 */
	float m_angleDelta;
	
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
	 * @param duration duration time in second
	 * @param config \link wyLagrangeConfig wyLagrangeConfig\endlink structure to describe lagrange curve
	 */
	wyLagrange(float duration, wyLagrangeConfig config);

public:
	/**
	 * \if English
	 * Static factory method
	 *
	 * @param duration duration time in second
	 * @param config \link wyLagrangeConfig wyLagrangeConfig\endlink structure to describe lagrange curve
	 * @return \link wyLagrange wyLagrange\endlink
	 * \else
	 * 静态构造方法
	 *
	 * @param duration 动作持续的时间
	 * @param config 拉格朗日曲线的描述结构, \link wyLagrangeConfig wyLagrangeConfig\endlink
	 * @return \link wyLagrange wyLagrange\endlink
	 * \endif
	 */
	static wyLagrange* make(float duration, wyLagrangeConfig config);

	virtual ~wyLagrange();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
	
	/**
	 * \if English
	 * Enable auto rotate, it means the node move by lagrange path will be aligned
	 * with path direction.
	 *
	 * @param flag true means enable auto rotate
	 * @param angleDelta the delta to be added to path direction. Position value means
	 * 		clockwise, negative value means counter-clockwise
	 * \else
	 * 是否打开自动旋转，打开自动旋转表示移动的节点会自动保持和路径方向一致.
	 *
	 * @param flag true表示打开自动旋转
	 * @param angleDelta 预设的角度，假如是-90，而当前路径的朝向是180度，那么最终节点将被设置为90度.
	 * 		这里正值表示顺时针旋转，负值表示逆时针旋转
	 * \endif
	 */
	void setAutoRotate(bool flag, float angleDelta);

	/**
	 * \if English
	 * set pin point, only available when auto rotate flag is false
	 *
	 * @param p global coordinate of pin point
	 * \else
	 * 设置pin point, pin point仅当auto rotate为false时才有效
	 *
	 * @param p pin point的全局坐标
	 * \endif
	 */
	void setPinPoint(wyPoint p) { m_pinPoint = p; }

	/**
	 * \if English
	 * set pin point, only available when auto rotate flag is false
	 *
	 * @param x global x location of pin point
	 * @param y global y location of pin point
	 * \else
	 * 设置pin point, pin point仅当auto rotate为false时才有效
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

#endif // __wyLagrange_h__
