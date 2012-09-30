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
#ifndef __wyScaleTo_h__
#define __wyScaleTo_h__

#include "wyIntervalAction.h"

/**
 * @class wyScaleBy
 *
 * \if English
 * scale node
 * \else
 * 节点缩放的动作封装,根据设置起始缩放比进行缩放操作
 * \endif
 */
class WIENGINE_API wyScaleTo : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * original x scale
	 * \else
	 * 初始x轴缩放比，取值大于0
	 * \endif
	 */
	float m_startScaleX;

	/**
	 * \if English
	 * original y scale
	 * \else
	 * 初始y轴缩放比，取值大于0
	 * \endif
	 */
	float m_startScaleY;

	/**
	 * \if English
	 * end x scale
	 * \else
	 * 目标x轴缩放比，取值大于0
	 * \endif
	 */
	float m_endScaleX;

	/**
	 * \if English
	 * end y scale
	 * \else
	 * 目标y轴缩放比，取值大于0
	 * \endif
	 */
	float m_endScaleY;

	/**
	 * \if English
	 * delta x scale
	 * \else
	 * 缩放变化的x轴缩比例
	 * \endif
	 */
	float m_deltaX;

	/**
	 * \if English
	 * delta y scale
	 * \else
	 * 缩放变化的y轴缩比例
	 * \endif
	 */
	float m_deltaY;

private:
	/**
	 * \if English
	 * initialize action
	 *
	 * @param startScaleX initial x scale
	 * @param startScaleY initial y scale
	 * @param endScaleX end x scale
	 * @param endScaleY end y scale
	 * \else
	 * 初始化函数
	 *
	 * @param startScaleX 初始x轴缩放比，取值大于0
	 * @param startScaleY 初始y轴缩放比，取值大于0
	 * @param endScaleX 目标x轴缩放比，取值大于0
	 * @param endScaleY 目标y轴缩放比，取值大于0
	 * \endif
	 */
	void init(float startScaleX, float startScaleY, float endScaleX, float endScaleY);

protected:
	/**
	 * constructor
	 *
	 * @param duration duration time of action in second
	 * @param startScaleX initial x scale
	 * @param startScaleY initial y scale
	 * @param endScaleX end x scale
	 * @param endScaleY end y scale
	 */
	wyScaleTo(float duration, float startScaleX, float startScaleY, float endScaleX, float endScaleY);

	/**
	 * constructor
	 *
	 * @param duration duration time of action in second
	 * @param startScale initial scale
	 * @param endScale end scale
	 */
	wyScaleTo(float duration, float startScale, float endScale);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action in second
	 * @param startScaleX initial x scale
	 * @param startScaleY initial y scale
	 * @param endScaleX end x scale
	 * @param endScaleY end y scale
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startScaleX 初始x轴缩放比，取值大于0
	 * @param startScaleY 初始y轴缩放比，取值大于0
	 * @param endScaleX 目标x轴缩放比，取值大于0
	 * @param endScaleY 目标y轴缩放比，取值大于0
	 * \endif
	 */
	static wyScaleTo* make(float duration, float startScaleX, float startScaleY, float endScaleX, float endScaleY);

	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action in second
	 * @param startScale initial scale
	 * @param endScale end scale
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startScale 初始缩放比
	 * @param endScale 目标缩放比
	 * \endif
	 */
	static wyScaleTo* make(float duration, float startScale, float endScale);

	virtual ~wyScaleTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyScaleTo_h__
