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
#ifndef __wyTwirl_h__
#define __wyTwirl_h__

#include "wyGrid3DAction.h"

/**
 * @class wyTwirl
 * \if English
 * Node performing this effect will produce a twirled effect
 * \else
 * 扭曲效果
 * \endif
 */
class WIENGINE_API wyTwirl : public wyGrid3DAction {
protected:
	/**
	 * \if English
	 * x coordinate of the center position
	 * \else
	 * 中心点位置x值
	 * \endif
	 */
	float m_centerX;

	/**
	 * \if English
	 * y coordinate of the center position
	 * \else
	 * 中心点位置y值
	 * \endif
	 */
	float m_centerY;

	/**
	 * \if English
	 * tuning of center position on the x direction
	 * \else
	 * 中心点位置横向变化
	 * \endif
	 */
	float m_deltaX;

	/**
	 * \if English
	 * tuning of center position on the y direction
	 * \else
	 * 中心点位置纵向变化
	 * \endif
	 */
	float m_deltaY;

	/**
	 * \if English
	 * specify how many times the node will be twirled
	 * \else
	 * 扭曲次数
	 * \endif
	 */
	float m_twirls;

	/**
	 * \if English
	 * tuning of the amplitude
	 * \else
	 * 幅度变化值
	 * \endif
	 */
	float m_deltaAmplitude;

	// last values
	float m_lastX;
	float m_lastY;
	float m_lastAmplitude;

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @param centerX x coordinate of the center position
	 * @param centerY y coordinate of the center position
	 * @param deltaX tuning of center position on the x direction
	 * @param deltaY tuning of center position on the y direction
	 * @param amplitude amplitude
	 * @param deltaAmplitude tuning of the amplitude
	 * @param twirls specify how many times the node will be twirled
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param centerX 中心点位置x值
	 * @param centerY 中心点位置y值
	 * @param deltaX 中心点位置横向变化
	 * @param deltaY 中心点位置纵向变化
	 * @param amplitude 幅度
	 * @param deltaAmplitude 幅度变化值
	 * @param twirls 扭曲次数
	 * \endif
	 */
	static wyTwirl* make(float duration, int gridX, int gridY, float centerX, float centerY, float deltaX, float deltaY, float amplitude,
	        float deltaAmplitude, float twirls);

	/**
	 * \if English
	 * constructor
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @param centerX x coordinate of the center position
	 * @param centerY y coordinate of the center position
	 * @param deltaX tuning of center position on the x direction
	 * @param deltaY tuning of center position on the y direction
	 * @param amplitude amplitude
	 * @param deltaAmplitude tuning of the amplitude
	 * @param twirls specify how many times the node will be twirled
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param centerX 中心点位置x值
	 * @param centerY 中心点位置y值
	 * @param deltaX 中心点位置横向变化
	 * @param deltaY 中心点位置纵向变化
	 * @param amplitude 幅度
	 * @param deltaAmplitude 幅度变化值
	 * @param twirls 扭曲次数
	 * \endif
	 */
	wyTwirl(float duration, int gridX, int gridY, float centerX, float centerY, float deltaX, float deltaY, float amplitude,
	        float deltaAmplitude, float twirls);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyTwirl();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyTwirl_h__
