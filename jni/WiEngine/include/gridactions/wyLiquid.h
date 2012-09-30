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
#ifndef __wyLiquid_h__
#define __wyLiquid_h__

#include "wyGrid3DAction.h"

/**
 * @class wyLiquid
 * \if English
 * The node performing this action will produce an effect of liquid.
 * \else
 * 液体效果,使目标对象呈现流动的效果
 * \endif
 */
class WIENGINE_API wyLiquid : public wyGrid3DAction {
protected:
	/**
	 * \if English
	 * wave count
	 * \else
	 * 波数
	 * \endif
	 */
	float m_waves;

	/**
	 * \if English
	 * tuning of amplitude
	 * \else
	 * 幅度变化量
	 * \endif
	 */
	float m_deltaAmplitude;

	// last values
	float m_lastAmplitude;

public:
	/**
	 * \if English
	 * factory funciton, used to create a new instance with autoRelease enabled
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @param amplitude amplitude
	 * @param deltaAmplitude tuning of amplitude
	 * @param waves wave count
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param amplitude 幅度
	 * @param deltaAmplitude 幅度变化量
	 * @param waves 波数
	 * \endif
	 */
	static wyLiquid* make(float duration, int gridX, int gridY, float amplitude, float deltaAmplitude, float waves);

	/**
	 * \if English
	 * constructor
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @param amplitude amplitude
	 * @param deltaAmplitude tuning of amplitude
	 * @param waves wave count
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param amplitude 幅度
	 * @param deltaAmplitude 幅度变化量
	 * @param waves 波数
	 * \endif
	 */
	wyLiquid(float duration, int gridX, int gridY, float amplitude, float deltaAmplitude, float waves);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyLiquid();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyLiquid_h__
