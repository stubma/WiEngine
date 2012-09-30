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
#ifndef __wyWaves_h__
#define __wyWaves_h__

#include "wyGrid3DAction.h"

/**
 * @class wyWaves
 * \if English
 * Node performing this effect will produce an effect of waves
 * \else
 * 波浪效果
 * \endif
 */
class WIENGINE_API wyWaves : public wyGrid3DAction {
protected:
	/**
	 * \if English
	 * wave count
	 * \else
	 * 波浪数
	 * \endif
	 */
	int m_waves;

	/**
	 * \if English
	 * specify whether the effect applies on the vertical direction
	 * \else
	 * 是否垂直方向有波浪效果
	 * \endif
	 */
	bool m_vertical;

	/**
	 * \if English
	 * specify whether the effect applies on the horizontal direction
	 * \else
	 * 是否水平方向有波浪效果
	 * \endif
	 */
	bool m_horizontal;

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @param amplitude amplitude
	 * @param waves wave count
	 * @param vertical specify whether the effect applies on the vertical direction
	 * @param horizontal specify whether the effect applies on the horizontal direction
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param amplitude 幅度
	 * @param waves 波浪数
	 * @param vertical 是否垂直方向有波浪效果
	 * @param horizontal 是否水平方向有波浪效果
	 * \endif
	 */
	static wyWaves* make(float duration, int gridX, int gridY, float amplitude, int waves, bool vertical, bool horizontal);

	/**
	 * \if English
	 * constructor
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @param amplitude amplitude
	 * @param waves wave count
	 * @param vertical specify whether the effect applies on the vertical direction
	 * @param horizontal specify whether the effect applies on the horizontal direction
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param amplitude 幅度
	 * @param waves 波浪数
	 * @param vertical 是否垂直方向有波浪效果
	 * @param horizontal 是否水平方向有波浪效果
	 * \endif
	 */
	wyWaves(float duration, int gridX, int gridY, float amplitude, int waves, bool vertical, bool horizontal);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyWaves();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyWaves_h__
