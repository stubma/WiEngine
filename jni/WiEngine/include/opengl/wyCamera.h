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
#ifndef __wyCamera_h__
#define __wyCamera_h__

#include "wyGlobal.h"
#include <stdbool.h>
#include "wyObject.h"

/**
 * @class wyCamera
 *
 * 相机逻辑封装。通过修改镜头位置，可以产生不同的试图。
 */
class WIENGINE_API wyCamera : public wyObject {
private:
	/// 镜头位置x轴
	GLfloat m_eyeX;

	/// 镜头位置y轴
	GLfloat m_eyeY;

	/// 镜头位置z轴
	GLfloat m_eyeZ;

	///视线中心x位置
	GLfloat m_centerX;

	///视线中心y位置
	GLfloat m_centerY;

	///视线中心z位置
	GLfloat m_centerZ;

	/// 正方向x位置
	GLfloat m_upX;

	/// 正方向y位置
	GLfloat m_upY;

	/// 正方向z位置
	GLfloat m_upZ;

	/// 脏标志
	bool m_dirty;

protected:
	wyCamera();

public:
	/**
	 * 得到视点的z位置
	 *
	 * @return 视点的z位置
	 */
	static float getZEye();

	virtual ~wyCamera();
	static wyCamera* make();

	/**
	 * 回复到缺省的镜头设置
	 */
	void restore();

	/**
	 * 根据当前设置的各种参数放置镜头
	 */
	void locate();

	/**
	 * 设置当前镜头位置
	 *
	 * @param x 当前镜头x位置
	 * @param y 当前镜头y位置
	 * @param z 当前镜头z位置
	 */
	void setEye(float x, float y, float z);

	/**
	 * 设置当前视线中心位置
	 *
	 * @param x 当前视线中心x位置
	 * @param y 当前视线中心y位置
	 * @param z 当前视线中心z位置
	 */
	void setCenter(float x, float y, float z);

	/**
	 * 设置当前正方向位置
	 *
	 * @param x 正方向位置的x值
	 * @param y 正方向位置的y值
	 * @param z 正方向位置的z值
	 */
	void setUp(float x, float y, float z);

	/**
	 * 获得当前镜头位置
	 *
	 * @param eye 必须是一个长度为3的浮点数组
	 */
	void getEye(float* eye);

	/**
	 * 获得当前视线中心位置
	 *
	 * @param center 必须是一个长度为3的浮点数组
	 */
	void getCenter(float* center);

	/**
	 * 获得当前正方向位置
	 *
	 * @param up 必须是一个长度为3的浮点数组
	 */
	void getUp(float* up);

	/**
	 * 得到脏标志
	 *
	 * @return 得到当前的脏标志
	 */
	bool isDirty() { return m_dirty; }

	/**
	 * 设置脏标志
	 *
	 * @param dirty true表示镜头需要重新放置
	 */
	void setDirty(bool dirty) { m_dirty = dirty; }
};

#endif // __wyCamera_h__
