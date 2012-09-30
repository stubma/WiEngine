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
#ifndef __wyShaky3D_h__
#define __wyShaky3D_h__

#include "wyGrid3DAction.h"
#include "wyTypes.h"

/**
 * @class wyShaky3D
 * \if English
 * Node performing this action will produce an effect of shaking
 * \else
 * 抖动效果
 * \endif
 */
class WIENGINE_API wyShaky3D : public wyGrid3DAction {
protected:
	/**
	 * \if English
	 * the shake amplitude
	 * \else
	 * 抖动的幅度，越大越剧烈
	 * \endif
	 */
	int m_range;

	/**
	 * \if English
	 * tuning of shake amplitude
	 * \else
	 * 抖动的幅度变化值
	 * \endif
	 */
	int m_deltaRange;

	int m_lastRange;

	/**
	 * \if English
	 * specify whether the shaking is performed on the z axis
	 * \else
	 * 是否在z轴方向上抖动
	 * \endif
	 */
	///
	bool m_shakeZ;

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @param range the shake amplitude
	 * @param deltaRange tuning of shake amplitude
	 * @param shakeZ specify whether the shaking is performed on the z axis
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param range 抖动的幅度，越大越剧烈
	 * @param deltaRange 抖动的幅度变化值
	 * @param shakeZ 是否在z轴方向上抖动
	 * \endif
	 */
	static wyShaky3D* make(float duration, int gridX, int gridY, int range, int deltaRange, bool shakeZ);

	/**
	 * \if English
	 * constructor
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @param range the shake amplitude
	 * @param deltaRange tuning of shake amplitude
	 * @param shakeZ specify whether the shaking is performed on the z axis
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param range 抖动的幅度，越大越剧烈
	 * @param deltaRange 抖动的幅度变化值
	 * @param shakeZ 是否在z轴方向上抖动
	 * \endif
	 */
	wyShaky3D(float duration, int gridX, int gridY, int range, int deltaRange, bool shakeZ);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyShaky3D();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyShaky3D_h__
