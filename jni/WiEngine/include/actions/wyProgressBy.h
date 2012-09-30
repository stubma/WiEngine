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
#ifndef __wyProgressBy_h__
#define __wyProgressBy_h__

#include "wyIntervalAction.h"

/**
 * @class wyProgressBy
 *
 * \if English
 * Progress action which depends on a \link wyProgressTimer wyProgressTimer\endlink
 * node
 * \else
 * 使节点称为进度条显示的动作封装，根据指定变化的百分比执行动作
 * \endif
 */
class WIENGINE_API wyProgressBy : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * delta percentage
	 * \else
	 * 节点显示变化的百分比，取值0到100
	 * \endif
	 */
	float m_delta;

	/**
	 * \if English
	 * start percentage
	 * \else
	 * 节点起始显示百分比，取值0到100
	 * \endif
	 */
	float m_from;

protected:
	/**
	 * constructor
	 *
	 * @param duration duration time
	 * @param deltaPercents delta percentage
	 */
	wyProgressBy(float duration, float deltaPercents);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time
	 * @param deltaPercents delta percentage
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param deltaPercents 节点变化的百分比，取值0到100
	 * \endif
	 */
	static wyProgressBy* make(float duration, float deltaPercents);

	virtual ~wyProgressBy();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyProgressBy_h__
