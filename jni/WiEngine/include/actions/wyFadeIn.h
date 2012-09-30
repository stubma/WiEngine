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
#ifndef __wyFadeIn_h__
#define __wyFadeIn_h__

#include "wyIntervalAction.h"

/**
 * @class wyFadeIn
 *
 * \if English
 * Fade in a node, it changes alpha of node from 0 to 1
 * \else
 * 节点淡入效果的动作封装
 * \endif
 */
class WIENGINE_API wyFadeIn : public wyIntervalAction {
private:
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
	 * \if English
	 * Constructor
	 *
	 * @param duration duration time of this action
	 * @param includeChildren true indicating modify alpha value of child nodes recursively
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param includeChildren true表示同时修改所有子节点的alpha值, 缺省是false
	 * \endif
	 */
	wyFadeIn(float duration, bool includeChildren = false);

public:
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration duration time of this action
	 * @param includeChildren true indicating modify alpha value of child nodes recursively
	 * @return \link wyFadeIn wyFadeIn\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param includeChildren true表示同时修改所有子节点的alpha值, 缺省是false
	 * @return \link wyFadeIn wyFadeIn\endlink
	 * \endif
	 */
	static wyFadeIn* make(float duration, bool includeChildren = false);

	virtual ~wyFadeIn();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::update
	virtual void update(float t);

	/// @see wyAction::start
	virtual void start(wyNode* target);
};

#endif // __wyFadeIn_h__
