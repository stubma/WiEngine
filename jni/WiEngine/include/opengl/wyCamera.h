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
 * @class wyCamera
 *
 * 相机逻辑封装。通过修改镜头位置，可以产生不同的试图。
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
	 * \if English
	 * Restore camera to default position
	 * \else
	 * 回复到缺省的镜头设置
	 * \endif
	 */
	void restoreCamera();

	/**
	 * \if English
	 * Restore to default projection matrix
	 * \else
	 * 回复到缺省的投影矩阵
	 * \endif
	 */
	void restoreProjection();

	/**
	 * \if English
	 * Restore to default viewport range
	 * \else
	 * 回复到缺省的视口大小
	 * \endif
	 */
	void restoreViewport();

	/**
	 * \if English
	 * Get current view matrix
	 * \else
	 * 得到当前相机矩阵
	 * \endif
	 */
	kmMat4* getViewMatrix();

	/**
	 * \if English
	 * Get current projection matrix
	 * \else
	 * 得到当前投影矩阵
	 * \endif
	 */
	kmMat4* getProjectionMatrix();

	/**
	 * \if English
	 * Get viewport bound
	 *
	 * @return viewport rectangle
	 * \else
	 * 得到视口矩形
	 *
	 * @return 视口矩形
	 * \endif
	 */
	wyRect getViewportRect();

	/**
	 * \if English
	 * Set orthogonal projection
	 *
	 * @param l left bound of ortho
	 * @param r right bound of ortho
	 * @param b bottom bound of ortho
	 * @param t top bound of ortho
	 * @param near near end of cylinder
	 * @param far far end of cylinder
	 * \else
	 * 使用正交投影
	 *
	 * @param l 柱体作边界
	 * @param r 柱体右边界
	 * @param b 柱体下边界
	 * @param t 柱体上边界
	 * @param near 柱体近端
	 * @param far 柱体远端
	 * \endif
	 */
	void setOrtho(float l, float r, float b, float t, float near, float far);

	/**
	 * \if English
	 * Set perspective projection
	 *
	 * @param fovy the angle of the field of view in the x-z plane; its value must be in the range [0.0,180.0]
	 * @param widthRatio the relative width to viewport width
	 * @param heightRatio the relative height to viewport height
	 * @param near near distances between the viewpoint and the clipping planes, along the negative z-axis. it should always be positive
	 * @param far far distances between the viewpoint and the clipping planes, along the negative z-axis. it should always be positive
	 * \else
	 * 设置梯形投影参数
	 *
	 * @param fovy 视图范围和x-z平面的夹角, 必须在[0, 180]度范围内
	 * @param widthRatio 梯形宽相对于视口宽的比例
	 * @param heightRatio 梯形高相对于视口高的比例
	 * @param near 视点和最近的clip平面距离
	 * @param far 视点和最远的clip平面距离
	 * \endif
	 */
	void setPerspective(float fovy, float widthRatio, float heightRatio, float near, float far);

	/**
	 * \if English
	 * Get eye location
	 *
	 * @param e float array to hold returned eye location, length must be at least 3
	 * \else
	 * 得到相机位置
	 *
	 * @param e 返回相机位置的浮点数据, 长度至少要为3
	 * \endif
	 */
	void getEye(float* e);

	/**
	 * \if English
	 * Set position of camera location
	 *
	 * @param x position of camera x location
	 * @param y position of camera y location
	 * @param z position of camera z location
	 * \else
	 * 设置当前镜头位置
	 *
	 * @param x 当前镜头x位置
	 * @param y 当前镜头y位置
	 * @param z 当前镜头z位置
	 * \endif
	 */
	void setEye(float x, float y, float z);

	/**
	 * \if English
	 * Get camera center location
	 *
	 * @param e float array to hold returned camera center location, length must be at least 3
	 * \else
	 * 得到相机对准的中心位置
	 *
	 * @param c 返回相机对准的中心位置的浮点数据, 长度至少要为3
	 * \endif
	 */
	void getCenter(float* c);

	/**
	 * \if English
	 * Set position of camera center, it will multiply viewport size
	 * to get final position
	 *
	 * @param x position of camera x center
	 * @param y position of camera y center
	 * @param z position of camera z center
	 * \else
	 * 设置当前视线中心位置
	 *
	 * @param x 当前视线中心x位置
	 * @param y 当前视线中心y位置
	 * @param z 当前视线中心z位置
	 * \endif
	 */
	void setCenter(float x, float y, float z);

	/**
	 * \if English
	 * Get camera up location
	 *
	 * @param e float array to hold returned camera up location, length must be at least 3
	 * \else
	 * 得到相机正方向
	 *
	 * @param c 返回相机正方向, 长度至少要为3
	 * \endif
	 */
	void getUp(float* u);

	/**
	 * \if English
	 * Set camera positive vector
	 *
	 * @param x x value of up vector
	 * @param y y value of up vector
	 * @param z z value of up vector
	 * \else
	 * 设置当前正方向位置
	 *
	 * @param x 正方向位置的x值
	 * @param y 正方向位置的y值
	 * @param z 正方向位置的z值
	 * \endif
	 */
	void setUp(float x, float y, float z);

	/**
	 * \if English
	 * Set camera position and center are relative value of window
	 *
	 * @param flag true means camera position and center are relative value of window
	 * \else
	 * 设置摄像机的位置和中心是否是一个相对于窗口的相对值, 如果窗口宽400, 而center的x值是0.5, 则
	 * 实际的摄像机x位置是200
	 *
	 * @param true表示摄像机的位置和中心是一个相对于窗口的相对值
	 * \endif
	 */
	void setUseRelativeValue(bool flag);

	/**
	 * \if English
	 * Set viewport relative size
	 *
	 * @param x relative x value
	 * @param y relative y value
	 * @param w relative width
	 * @param h relative height
	 * \else
	 * 设置视口的相对于surface的大小
	 *
	 * @param x x相对位置
	 * @param y y相对位置
	 * @param w 相对宽度
	 * @param h 相对高度
	 * \endif
	 */
	void setViewport(float x, float y, float w, float h);

	/**
	 * \if English
	 * Force camera dirty
	 * \else
	 * 强制标记摄像头脏, 使得它更新视口矩阵
	 * \endif
	 */
	void setDirty(bool flag) { m_cameraDirty = flag; }
};

#endif // __wyCamera_h__
