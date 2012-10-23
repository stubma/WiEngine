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
#include <stdlib.h>
#include "wyTypes.h"
#include "wyLog.h"
#include "wyGlobal.h"

wyCamera::wyCamera() :
		m_useOrtho(false) {
	restoreCamera();
	restoreProjection();
	restoreViewport();
}

wyCamera::~wyCamera() {
}

wyCamera* wyCamera::make() {
	wyCamera* c = WYNEW wyCamera();
	return (wyCamera*)c->autoRelease();
}

void wyCamera::setOrtho(float l, float r, float b, float t, float near, float far) {
	m_orthoParams.leftRatio = l;
	m_orthoParams.rightRatio = r;
	m_orthoParams.bottomRatio = b;
	m_orthoParams.topRatio = t;
	m_orthoParams.fnear = near;
	m_orthoParams.ffar = far;
	m_useOrtho = true;
	m_identityProjection = false;
	m_projectionDirty = true;
}

void wyCamera::setPerspective(float fovy, float widthRatio, float heightRatio, float near, float far) {
	m_perspectiveParams.fovy = fovy;
	m_perspectiveParams.widthRatio = widthRatio;
	m_perspectiveParams.heightRatio = heightRatio;
	m_perspectiveParams.fnear = near;
	m_perspectiveParams.ffar = far;
	m_useOrtho = false;
	m_identityProjection = false;
	m_projectionDirty = true;
}

void wyCamera::setViewport(bool relative, float x, float y, float w, float h) {
	m_viewportParams.xRatio = x;
	m_viewportParams.yRatio = y;
	m_viewportParams.wRatio = w;
	m_viewportParams.hRatio = h;
	m_viewportParams.relative = relative;
	m_viewportDirty = true;
}

void wyCamera::restoreCamera() {
	// use identity
	kmVec3Fill(&m_cameraParams.eye, 0, 0, getZEye());
	kmVec3Fill(&m_cameraParams.center, 0, 0, 0);
	kmVec3Fill(&m_cameraParams.up, 0, 1, 0);
	m_cameraParams.relative = false;

	// set dirty flag because matrix need to be updated
	m_cameraDirty = true;
}

void wyCamera::restoreProjection() {
	m_identityProjection = true;
}

void wyCamera::restoreViewport() {
	setViewport(true, 0, 0, 1, 1);
}

kmMat4* wyCamera::getViewMatrix() {
	if(m_cameraDirty) {
		if(m_cameraParams.relative) {
			// get real eye
			kmVec3 eye = m_cameraParams.eye;
			eye.x *= wyDevice::winWidth;
			eye.y *= wyDevice::winHeight;
			eye.z *= wyDevice::winHeight;

			// get real center
			kmVec3 center = m_cameraParams.center;
			center.x *= wyDevice::winWidth;
			center.y *= wyDevice::winHeight;

			// populate matrix
			kmMat4LookAt(&m_viewMatrix, &eye, &center, &m_cameraParams.up);
		} else {
			// populate matrix
			kmMat4LookAt(&m_viewMatrix, &m_cameraParams.eye, &m_cameraParams.center, &m_cameraParams.up);
		}

		// clear dirty flag
		m_cameraDirty = false;
	}

	return &m_viewMatrix;
}

kmMat4* wyCamera::getProjectionMatrix() {
	if(m_projectionDirty) {
		if(m_identityProjection) {
			kmMat4Identity(&m_projectionMatrix);
		} else {
			if(m_useOrtho) {
				kmMat4OrthographicProjection(&m_projectionMatrix,
						m_orthoParams.leftRatio * wyDevice::winWidth,
						m_orthoParams.rightRatio * wyDevice::winWidth,
						m_orthoParams.bottomRatio * wyDevice::winHeight,
						m_orthoParams.topRatio * wyDevice::winHeight,
						m_orthoParams.fnear,
						m_orthoParams.ffar);
			} else {
				// calculate frustum bound
				float aspect = wyDevice::winWidth * m_perspectiveParams.widthRatio / (wyDevice::winHeight * m_perspectiveParams.heightRatio);
				m_frustumTop = m_perspectiveParams.fnear * (float) tan(m_perspectiveParams.fovy * M_PI / 360);
				m_frustumBottom = -m_frustumTop;
				m_frustumLeft = m_frustumBottom * aspect;
				m_frustumRight = m_frustumTop * aspect;
				m_frustumNear = m_perspectiveParams.fnear;
				m_frustumFar = m_perspectiveParams.ffar;

				// populate matrix
				kmMat4PerspectiveProjection(&m_projectionMatrix,
						m_perspectiveParams.fovy,
						aspect,
						m_perspectiveParams.fnear,
						m_perspectiveParams.ffar);
			}
		}

		// clear dirty flag
		m_projectionDirty = false;
	}

	return &m_projectionMatrix;
}

wyRect wyCamera::getViewportRect() {
	if(m_viewportDirty) {
		if(m_viewportParams.relative) {
			m_viewportRect.x = m_viewportParams.xRatio * wyDevice::realWidth;
			m_viewportRect.y = m_viewportParams.yRatio * wyDevice::realHeight;
			m_viewportRect.width = m_viewportParams.wRatio * wyDevice::realWidth;
			m_viewportRect.height = m_viewportParams.hRatio * wyDevice::realHeight;
		} else {
			m_viewportRect.x = m_viewportParams.xRatio;
			m_viewportRect.y = m_viewportParams.yRatio;
			m_viewportRect.width = m_viewportParams.wRatio;
			m_viewportRect.height = m_viewportParams.hRatio;
		}
		m_viewportDirty = false;
	}

	return m_viewportRect;
}

void wyCamera::setEye(float x, float y, float z) {
	kmVec3Fill(&m_cameraParams.eye, x, y, z);
	m_cameraDirty = true;
}

void wyCamera::getEye(float* e) {
	e[0] = m_cameraParams.eye.x;
	e[1] = m_cameraParams.eye.y;
	e[2] = m_cameraParams.eye.z;
}

void wyCamera::setCenter(float x, float y, float z) {
	kmVec3Fill(&m_cameraParams.center, x, y, z);
	m_cameraDirty = true;
}

void wyCamera::getCenter(float* c) {
	c[0] = m_cameraParams.center.x;
	c[1] = m_cameraParams.center.y;
	c[2] = m_cameraParams.center.z;
}

void wyCamera::setUp(float x, float y, float z) {
	kmVec3Fill(&m_cameraParams.up, x, y, z);
	m_cameraDirty = true;
}

void wyCamera::getUp(float* u) {
	u[0] = m_cameraParams.up.x;
	u[1] = m_cameraParams.up.y;
	u[2] = m_cameraParams.up.z;
}

void wyCamera::setUseRelativeValue(bool flag) {
	m_cameraParams.relative = flag;
	m_cameraDirty = true;
}
