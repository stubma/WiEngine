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
#ifndef __wyScaleBy_h__
#define __wyScaleBy_h__

#include "wyIntervalAction.h"

/**
 * @class wyScaleBy
 *
 * \if English
 * scale a node
 * \else
 * 节点缩放的动作封装,根据设置缩放比例进行节点缩放
 * \endif
 */
class WIENGINE_API wyScaleBy : public wyIntervalAction {
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

protected:
	/**
	 * \if English
	 * constructor
	 *
	 * @param duration duration of action in second
	 * @param scaleX delta x scale
	 * @param scaleY delta y scale
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param scaleX 缩放变化的x轴缩放比
	 * @param scaleY 缩放变化的y轴缩放比
	 * \endif
	 */
	wyScaleBy(float duration, float scaleX, float scaleY);

	/**
	 * \if English
	 * constructor
	 *
	 * @param duration duration of action in second
	 * @param scale delta scale
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param scale 缩放变化的缩放比
	 * \endif
	 */
	wyScaleBy(float duration, float scale);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration of action in second
	 * @param scaleX delta x scale
	 * @param scaleY delta y scale
	 * @return \link wyScaleBy wyScaleBy\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param scaleX 缩放变化的x轴缩放比
	 * @param scaleY 缩放变化的y轴缩放比
	 * @return \link wyScaleBy wyScaleBy\endlink
	 * \endif
	 */
	static wyScaleBy* make(float duration, float scaleX, float scaleY);

	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration of action in second
	 * @param scale delta scale
	 * @return \link wyScaleBy wyScaleBy\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param scale 缩放变化的缩放比
	 * @return \link wyScaleBy wyScaleBy\endlink
	 * \endif
	 */
	static wyScaleBy* make(float duration, float scale);

	virtual ~wyScaleBy();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyScaleBy_h__
