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
#ifndef __wyOrbitCamera_h__
#define __wyOrbitCamera_h__

#include "wyCameraAction.h"

/**
 * @class wyOrbitCamera
 *
 * Camera action, it does animation by changing camera position.
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
	 * static factory method
	 *
	 * @param duration action duration time in second
	 * @param r the initial distance between camera and screen center
	 * @param dr the delta of \c r
	 * @param z the initial angle between z axis and screen normal
	 * @param dz the delta of \c z
	 * @param x the initial angle of x axis
	 * @param dx the delta of \c x
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
