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
#ifndef __wyLens3D_h__
#define __wyLens3D_h__

#include "wyGrid3DAction.h"

/**
 * @class wyLens3D
 * \if English
 * The node performing this action looks like under a lens of magnifier.
 * \else
 * 透镜效果，使目标看起来好像在放大镜下
 * \endif
 */
class WIENGINE_API wyLens3D : public wyGrid3DAction {
protected:
	// last values
	float m_lastX;
	float m_lastY;
	float m_lastRadius;

	/**
	 * \if English
	 * x coordinate of center of the lens
	 * \else
	 * 透镜中心位置x坐标
	 * \endif
	 */
	float m_centerX;

	/**
	 * \if English
	 * y coordinate of center of the lens
	 * \else
	 * 透镜中心位置y坐标
	 * \endif
	 */
	float m_centerY;

	/**
	 * \if English
	 * distance the lens will move every frame refreshment on the x axis direction
	 * \else
	 * 透镜横向移动距离
	 * \endif
	 */
	float m_deltaX;

	/**
	 * \if English
	 * distance the lens will move every frame refreshment on the y axis direction
	 * \else
	 * 透镜纵向移动距离
	 * \endif
	 */
	float m_deltaY;

	/**
	 * \if English
	 * radius of the lens
	 * \else
	 * 透镜半径
	 * \endif
	 */
	float m_radius;

	/**
	 * \if English
	 * the tuning of radius
	 * \else
	 * 透镜半径变化量
	 * \endif
	 */
	float m_deltaRadius;

	/**
	 * \if English
	 * can be regarded as focus of the lens
	 * \else
	 * 透镜凹凸程度
	 * \endif
	 */
	float m_lensEffect;

public:
	/**
	 * \if English
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
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param centerX 透镜中心位置x坐标
	 * @param centerY 透镜中心位置y坐标
	 * @param deltaX 透镜横向移动距离
	 * @param deltaY 透镜纵向移动距离
	 * @param radius 透镜半径
	 * @param deltaRadius 透镜半径变化量
	 * @param lensEffect 透镜凹凸程度
	 * \endif
	 */
	static wyLens3D* make(float duration, int gridX, int gridY, float centerX, float centerY,
		float deltaX, float deltaY, float radius, float deltaRadius, float lensEffect);

	/**
	 * \if English
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
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param centerX 透镜中心位置x坐标
	 * @param centerY 透镜中心位置y坐标
	 * @param deltaX 透镜横向移动距离
	 * @param deltaY 透镜纵向移动距离
	 * @param radius 透镜半径
	 * @param deltaRadius 透镜半径变化量
	 * @param lensEffect 透镜凹凸程度
	 * \endif
	 */
	wyLens3D(float duration, int gridX, int gridY, float centerX, float centerY,
		float deltaX, float deltaY, float radius, float deltaRadius, float lensEffect);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyLens3D();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyLens3D_h__
