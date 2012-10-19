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
#include "wyOrbitCamera.h"
#include <math.h>
#include "wyNode.h"
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyTypes.h"
#include "wyCamera.h"

wyOrbitCamera::~wyOrbitCamera() {
}

wyOrbitCamera::wyOrbitCamera(float duration, float r, float dr, float z, float dz, float x, float dx) :
		wyCameraAction(duration),
		m_radius(r),
		m_deltaRadius(dr),
		m_angleZ(z),
		m_deltaAngleZ(dz),
		m_angleX(x),
		m_deltaAngleX(dx),
		m_radianZ(0),
		m_deltaRadianZ(wyMath::d2r(dz)),
		m_radianX(0),
		m_deltaRadianX(wyMath::d2r(dx)) {
}

wyOrbitCamera* wyOrbitCamera::make(float duration, float r, float dr, float z, float dz, float x, float dx) {
	wyOrbitCamera* a = WYNEW wyOrbitCamera(duration, r, dr, z, dz, x, dx);
	return (wyOrbitCamera*)a->autoRelease();
}

wyAction* wyOrbitCamera::copy() {
	return wyOrbitCamera::make(m_duration, m_radius, m_deltaRadius, m_angleZ, m_deltaAngleZ, m_angleX, m_deltaAngleX);
}

void wyOrbitCamera::start(wyNode* target) {
    wyCameraAction::start(target);

    m_radianZ = wyMath::d2r(m_angleZ);
    m_radianX = wyMath::d2r(m_angleX);
}

void wyOrbitCamera::update(float t) {
    float r = (m_radius + m_deltaRadius * t) * wyCamera::getZEye();
    float za = m_radianZ + m_deltaRadianZ * t;
    float xa = m_radianX + m_deltaRadianX * t;

    float i = wyMath::sin(za) * wyMath::cos(xa) * r + m_centerX;
    float j = wyMath::sin(za) * wyMath::sin(xa) * r + m_centerY;
    float k = wyMath::cos(za) * r + m_centerZ;

    m_target->getCamera()->setEye(i, j, k);

	// super only call callback
	wyCameraAction::update(t);
}
