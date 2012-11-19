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
#ifndef __wyLens3D_h__
#define __wyLens3D_h__

#include "wyGrid3DAction.h"

/**
 * @class wyLens3D
 * The node performing this action looks like under a lens of magnifier.
 */
class WIENGINE_API wyLens3D : public wyGrid3DAction {
protected:
	// last values
	float m_lastX;
	float m_lastY;
	float m_lastRadius;

	/**
	 * x coordinate of center of the lens
	 */
	float m_centerX;

	/**
	 * y coordinate of center of the lens
	 */
	float m_centerY;

	/**
	 * distance the lens will move every frame refreshment on the x axis direction
	 */
	float m_deltaX;

	/**
	 * distance the lens will move every frame refreshment on the y axis direction
	 */
	float m_deltaY;

	/**
	 * radius of the lens
	 */
	float m_radius;

	/**
	 * the tuning of radius
	 */
	float m_deltaRadius;

	/**
	 * can be regarded as focus of the lens
	 */
	float m_lensEffect;

public:
	/**
	 * factory function, used to create a new instance with autoRelease enabled.
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @param centerX x coordinate of center of the lens
	 * @param centerY y coordinate of center of the lens
	 * @param deltaX distance the lens will move every frame refreshment on the x axis direction
	 * @param deltaY distance the lens will move every frame refreshment on the y axis direction
	 * @param radius radius of the lens
	 * @param deltaRadius tuning of radius
	 * @param lensEffect can be regarded as focus of the lens
	 */
	static wyLens3D* make(float duration, int gridX, int gridY, float centerX, float centerY,
		float deltaX, float deltaY, float radius, float deltaRadius, float lensEffect);

	/**
	 * constructor
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @param centerX x coordinate of center of the lens
	 * @param centerY y coordinate of center of the lens
	 * @param deltaX distance the lens will move every frame refreshment on the x axis direction
	 * @param deltaY distance the lens will move every frame refreshment on the y axis direction
	 * @param radius radius of the lens
	 * @param deltaRadius tuning of radius
	 * @param lensEffect can be regarded as focus of the lens
	 */
	wyLens3D(float duration, int gridX, int gridY, float centerX, float centerY,
		float deltaX, float deltaY, float radius, float deltaRadius, float lensEffect);

	/**
	 * destructor
	 */
	virtual ~wyLens3D();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyLens3D_h__
