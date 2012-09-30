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
#ifndef __wyFollow_h__
#define __wyFollow_h__

#include "wyAction.h"
#include "wyNode.h"

/**
 * @class wyFollow
 *
 * \if English
 * An action that "follows" a node
 * \else
 * 跟踪一个节点, 让屏幕内容跟随节点的移动
 * \endif
 */
class WIENGINE_API wyFollow : public wyAction {

private:
	/// 要跟踪的\link wyNode wyNode\endlink节点
	wyNode* m_followedNode;

	/// 标示是否设置了最大的跟踪范围, true表示已设置
	bool m_boundarySet;

	/// 表示屏幕大小是否超过设置的最大跟踪范围, true表示超过
	bool m_boundaryFullyCovered;

	/// 屏幕尺寸
	wyPoint m_halfScreenSize;

	/// 一半屏幕尺寸
	wyPoint m_fullScreenSize;

	/* world boundaries */
	float m_leftBoundary;
	float m_rightBoundary;
	float m_topBoundary;
	float m_bottomBoundary;

protected:
	/**
	 * \if English
	 * Constructor
	 *
	 * @param fNode node to follow
	 * @param worldBoundary rectangle of world
	 * \else
	 * 构造函数
	 *
	 * @param fNode 要跟踪的\link wyNode wyNode\endlink节点
	 * @param worldBoundary 最大移动空间的矩形范围,如不设置表示fNode永远为中心点
	 * \endif
	 */
	wyFollow(wyNode* fNode, wyRect worldBoundary);

public:
	/**
	 * \if English
	 * Static Constructor
	 *
	 * @param fNode node to follow
	 * @param worldBoundary rectangle of world
	 * @return \link wyFollow wyFollow\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param fNode 要跟踪的\link wyNode wyNode\endlink节点
	 * @param worldBoundary 最大移动空间的矩形范围,如不设置表示fNode永远为中心点
	 * @return \link wyFollow wyFollow\endlink
	 * \endif
	 */
	static wyFollow* make(wyNode* fNode, wyRect worldBoundary = wyrZero);

	virtual ~wyFollow();

	/// @see wyAction::step
	virtual void step(float t);

	/// @see wyAction::isDone
	virtual bool isDone();
};

#endif // __wyFollow_h__
