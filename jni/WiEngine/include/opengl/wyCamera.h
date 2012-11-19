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
#ifndef __wyCamera_h__
#define __wyCamera_h__

#include <stdbool.h>
#include "wyObject.h"
#include "wyTypes.h"

/**
 * Camera object
 */
class WIENGINE_API wyCamera : public wyObject {
private:
	/// parameters of camera
	struct {
		/// camera location
		kmVec3 eye;

		/// camera center
		kmVec3 center;

		/// camera up direction
		kmVec3 up;

		/// true means eye and center are relative value to window
		bool relative;
	} m_cameraParams;

	/// parameters of perspective projection
	struct {
		/// fovy
		float fovy;

		/// width ratio
		float widthRatio;

		/// height ratio
		float heightRatio;

		/// near
		float fnear;

		/// far
		float ffar;
	} m_perspectiveParams;

	/// parameters of orthogonal projection
	struct {
		/// left, relative value to surface size
		float leftRatio;

		/// right, relative value to surface size
		float rightRatio;

		/// bottom, relative value to surface size
		float bottomRatio;

		/// top, relative value to surface size
		float topRatio;

		/// near
		float fnear;

		/// far
		float ffar;
	} m_orthoParams;

	/// use ortho or perspective
	bool m_useOrtho;

	/// true means use identity matrix for projection
	bool m_identityProjection;

	/// viewport parameters
	struct {
		/// viewport x, relative value to surface size
		float xRatio;

		/// viewport y, relative value to surface size
		float yRatio;

		/// viewport width, relative value to surface size
		float wRatio;

		/// viewport height, relative value to surface size
		float hRatio;

		/// use relative value
		bool relative;
	} m_viewportParams;

	/// dirty flag of camera position
	bool m_cameraDirty;

	/// dirty flag of projection matrix
	bool m_projectionDirty;

	/// dirty flag of viewport
	bool m_viewportDirty;

	/// view matrix
	kmMat4 m_viewMatrix;

	/// project matrix
	kmMat4 m_projectionMatrix;

	/// frustum left bound
	float m_frustumLeft;

	/// frustum right bound
	float m_frustumRight;

	/// frustum top bound
	float m_frustumTop;

	/// frustum bottom bound
	float m_frustumBottom;

	/// frustum near clip plane
	float m_frustumNear;

	/// frustum far clip plane
	float m_frustumFar;

	/// viewport rectangle
	wyRect m_viewportRect;

protected:
	wyCamera();

public:
	virtual ~wyCamera();
	static wyCamera* make();

	/**
	 * Get default z location of eye
	 */
	static float getZEye() { return FLT_EPSILON; }

	/**
	 * Restore camera to default position
	 */
	void restoreCamera();

	/**
	 * Restore to default projection matrix
	 */
	void restoreProjection();

	/**
	 * Restore to default viewport range
	 */
	void restoreViewport();

	/**
	 * Get current view matrix
	 */
	kmMat4* getViewMatrix();

	/**
	 * Get current projection matrix
	 */
	kmMat4* getProjectionMatrix();

	/**
	 * Get viewport bound
	 *
	 * @return viewport rectangle
	 */
	wyRect getViewportRect();

	/**
	 * Set orthogonal projection
	 *
	 * @param l left bound of ortho
	 * @param r right bound of ortho
	 * @param b bottom bound of ortho
	 * @param t top bound of ortho
	 * @param near near end of cylinder
	 * @param far far end of cylinder
	 */
	void setOrtho(float l, float r, float b, float t, float near, float far);

	/**
	 * Set perspective projection
	 *
	 * @param fovy the angle of the field of view in the x-z plane; its value must be in the range [0.0,180.0]
	 * @param widthRatio the relative width to viewport width
	 * @param heightRatio the relative height to viewport height
	 * @param near near distances between the viewpoint and the clipping planes, along the negative z-axis. it should always be positive
	 * @param far far distances between the viewpoint and the clipping planes, along the negative z-axis. it should always be positive
	 */
	void setPerspective(float fovy, float widthRatio, float heightRatio, float near, float far);

	/**
	 * Get eye location
	 *
	 * @param e float array to hold returned eye location, length must be at least 3
	 */
	void getEye(float* e);

	/**
	 * Set position of camera location
	 *
	 * @param x position of camera x location
	 * @param y position of camera y location
	 * @param z position of camera z location
	 */
	void setEye(float x, float y, float z);

	/**
	 * Get camera center location
	 *
	 * @param c float array to hold returned camera center location, length must be at least 3
	 */
	void getCenter(float* c);

	/**
	 * Set position of camera center, it will multiply viewport size
	 * to get final position
	 *
	 * @param x position of camera x center
	 * @param y position of camera y center
	 * @param z position of camera z center
	 */
	void setCenter(float x, float y, float z);

	/**
	 * Get camera up location
	 *
	 * @param u float array to hold returned camera up location, length must be at least 3
	 */
	void getUp(float* u);

	/**
	 * Set camera positive vector
	 *
	 * @param x x value of up vector
	 * @param y y value of up vector
	 * @param z z value of up vector
	 */
	void setUp(float x, float y, float z);

	/**
	 * Set camera position and center are relative value of window
	 *
	 * @param flag true means camera position and center are relative value of window
	 */
	void setUseRelativeValue(bool flag);

	/**
	 * Set viewport relative size
	 *
	 * @param relative true means the size is a relative value to real screen size, 0.5 means half size
	 * @param x relative x value
	 * @param y relative y value
	 * @param w relative width
	 * @param h relative height
	 */
	void setViewport(bool relative, float x, float y, float w, float h);

	/**
	 * Flag camera dirty, and it will update view matrix
	 */
	void setDirty(bool flag) { m_cameraDirty = flag; }
};

#endif // __wyCamera_h__
