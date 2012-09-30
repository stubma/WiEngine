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
#ifndef __wyOrbitCamera_h__
#define __wyOrbitCamera_h__

#include "wyCameraAction.h"

/**
 * @class wyOrbitCamera
 *
 * \if English
 * Camera action, it does animation by changing camera position.
 * \else
 * 轨道镜头动作。可以让视点沿着某条轨迹移动
 * \endif
 */
class WIENGINE_API wyOrbitCamera : public wyCameraAction {
protected:
	float m_radius;
	float m_deltaRadius;
	float m_angleZ;
	float m_deltaAngleZ;
	float m_angleX;
	float m_deltaAngleX;

	float m_radianZ;
	float m_deltaRadianZ;
	float m_radianX;
	float m_deltaRadianX;

protected:
	/**
	 * constructor
	 *
	 * @param duration action duration time in second
	 * @param r the initial distance between camera and screen center
	 * @param dr the delta of \c r
	 * @param z the initial angle between z axis and screen normal
	 * @param dz the delta of \c z
	 * @param x the initial angle of x axis
	 * @param dx the delta of \c x
	 */
	wyOrbitCamera(float duration, float r, float dr, float z, float dz, float x, float dx);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration action duration time in second
	 * @param r the initial distance between camera and screen center
	 * @param dr the delta of \c r
	 * @param z the initial angle between z axis and screen normal
	 * @param dz the delta of \c z
	 * @param x the initial angle of x axis
	 * @param dx the delta of \c x
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间
	 * @param r 镜头距离图象中心的距离，称为半径
	 * @param dr 半径在持续时间内变化总量
	 * @param z 动作开始时，镜头到图象中心的连线与z轴的夹角
	 * @param dz z角度的变化总量
	 * @param x x轴的初始倾斜角度
	 * @param dx x轴的总变化角度
	 * \endif
	 */
	static wyOrbitCamera* make(float duration, float r, float dr, float z, float dz, float x, float dx);

	virtual ~wyOrbitCamera();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyOrbitCamera_h__
