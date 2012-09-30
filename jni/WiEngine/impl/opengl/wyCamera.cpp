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
#include "wyCamera.h"
#include "glu.h"
#include <stdlib.h>
#include "wyTypes.h"
#include "wyLog.h"
#include "wyGlobal.h"

wyCamera::wyCamera() {
	restore();
}

wyCamera::~wyCamera() {
}

wyCamera* wyCamera::make() {
	wyCamera* c = WYNEW wyCamera();
	return (wyCamera*)c->autoRelease();
}

float wyCamera::getZEye() {
	return FLT_EPSILON;
}

void wyCamera::restore() {
	m_eyeX = 0;
	m_eyeY = 0;
	m_eyeZ = wyCamera::getZEye();

	m_centerX = 0;
	m_centerY = 0;
	m_centerZ = 0.0f;

	m_upX = 0.0f;
	m_upY = 1.0f;
	m_upZ = 0.0f;

	m_dirty = false;
}

void wyCamera::locate() {
	if(m_dirty) {
		gluLookAt(m_eyeX, m_eyeY, m_eyeZ, m_centerX, m_centerY, m_centerZ, m_upX, m_upY, m_upZ);
	}
}

void wyCamera::setEye(float x, float y, float z) {
	m_eyeX = x;
	m_eyeY = y;
	m_eyeZ = z;
	m_dirty = true;
}

void wyCamera::setCenter(float x, float y, float z) {
	m_centerX = x;
	m_centerY = y;
	m_centerZ = z;
	m_dirty = true;
}

void wyCamera::setUp(float x, float y, float z) {
	m_upX = x;
	m_upY = y;
	m_upZ = z;
	m_dirty = true;
}

void wyCamera::getEye(float* eye) {
	eye[0] = m_eyeX;
	eye[1] = m_eyeY;
	eye[2] = m_eyeZ;
}

void wyCamera::getCenter(float* center) {
	center[0] = m_centerX;
	center[1] = m_centerY;
	center[2] = m_centerZ;
}

void wyCamera::getUp(float* up) {
	up[0] = m_upX;
	up[1] = m_upY;
	up[2] = m_upZ;
}
