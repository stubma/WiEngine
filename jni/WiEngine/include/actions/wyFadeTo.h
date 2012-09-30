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
#ifndef __wyFadeTo_h__
#define __wyFadeTo_h__

#include "wyIntervalAction.h"

/**
 * @class wyFadeTo
 *
 * \if English
 * Change alpha of node from one value to another value
 * \else
 * 节点透明度变化效果的动作封装
 * \endif
 */
class WIENGINE_API wyFadeTo : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * end alpha, range from 0 to 255
	 * \else
	 * 目标透明度，取值0到255，255为不透明，0为透明
	 * \endif
	 */
	int m_toAlpha;

	/**
	 * \if English
	 * start alpha, range from 0 to 255
	 * \else
	 * 起始透明度，取值0到255，255为不透明，0为透明
	 * \endif
	 */
	int m_fromAlpha;

	/**
	 * \if English
	 * true indicating modify alpha value of child nodes recursively
	 * \else
	 * true表示递归修改所有子节点的alpha值
	 * \endif
	 */
	bool m_includeChildren;

private:
	/**
	 * \if English
	 * update alpha recursively
	 *
	 * @param node start node
	 * @param alpha destination alpha value
	 * \else
	 * 递归更新alpha值
	 *
	 * @param node 起始结点
	 * @param alpha 目标alpha值
	 * \endif
	 */
	void updateAlpha(wyNode* node, int alpha);

protected:
	/**
	 * Constructor
	 *
	 * @param duration duration time of action
	 * @param fromAlpha start alpha, range from 0 to 255
	 * @param toAlpha end alpha, range from 0 to 255
	 * @param includeChildren true indicating modify alpha value of child nodes recursively
	 */
	wyFadeTo(float duration, int fromAlpha, int toAlpha, bool includeChildren);

public:
	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration duration time of action
	 * @param fromAlpha start alpha, range from 0 to 255
	 * @param toAlpha end alpha, range from 0 to 255
	 * @param includeChildren true indicating modify alpha value of child nodes recursively
	 * @return \link wyFadeTo wyFadeTo\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param fromAlpha 起始透明度，取值0到255，255为不透明，0为透明
	 * @param toAlpha 目标透明度，取值0到255，255为不透明，0为透明
	 * @param includeChildren true表示同时修改所有子节点的alpha值, 缺省是false
	 * @return \link wyFadeTo wyFadeTo\endlink
	 * \endif
	 */
	static wyFadeTo* make(float duration, int fromAlpha, int toAlpha, bool includeChildren = false);

	virtual ~wyFadeTo();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyFadeTo_h__
