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
#ifndef __wyParallaxNode_h__
#define __wyParallaxNode_h__

#include "wyNode.h"
#include "wyArray.h"
#include "wyScroller.h"

/**
 * @class wyParallaxNode
 *
 * <p>视差滚动支持。可以为子节点指定视差比率，视差比率越大的子节点移动越迅速，所以会产生一种
 * 远近程度不同的感觉。视差节点的缺省大小是全屏幕, 在移动子节点时, 使用offsetBy方法, 不要
 * 使用setPosition方法, 因为setPosition是改变视差节点的位置, 而offsetBy是改变子节点的位置.<p><br>
 *
 * <p>视差节点维护了一个偏移值, 刚创建时偏移值是0且无限制, 可以调用相关方法设置最大和最小偏移,
 * 这在某些情况下, 比如使用fling时, 可以控制滚动的范围. 对于范围的计算, 设定一个基准点为0,
 * 如果这个基准点往左移, 则是负的偏移, 如果基准点往右移, 则是正偏移.</p><br>
 *
 * <p>视差对象还可以设定一个缩放范围, 举例来说, 如果设定一个视差对象的水平缩放范围是0到2,
 * 那么当ParallaxNode的偏移为最小值时, 这个对象对应的节点是看不见的, 而ParallaxNode的偏移
 * 为最大值时, 这个对象对应节点有两倍大.</p>
 */
class WIENGINE_API wyParallaxNode : public wyNode {
protected:
	/// 视差对象列表
	wyArray* m_parallaxObjects;

	/// 当前x偏移
	float m_xOffset;

	/// 当前y偏移
	float m_yOffset;

	/// 最小x偏移
	float m_minXOffset;

	/// 最小y偏移
	float m_minYOffset;

	/// 最大x偏移
	float m_maxXOffset;

	/// 最大y偏移
	float m_maxYOffset;

	/// true表示当前正在fling
	bool m_flinging;

	/// \link wyScroller wyScroller 结构指针\endlink
	wyScroller* m_scroller;

private:
	static bool releaseObject(wyArray* arr, void* ptr, int index, void* data);

protected:
	/// update fling status
	void updateFling(wyTargetSelector* ts);

public:
	static wyParallaxNode* make();

	wyParallaxNode();
	virtual ~wyParallaxNode();

	/// @see wyNode::addChild
	virtual void addChild(wyNode* child, int z, int tag);

	/// @see wyNode::removeAllChildren
	virtual void removeAllChildren(bool cleanup);

	/// @see wyNode::removeChild
	virtual void removeChild(wyNode* child, bool cleanup);

	/**
	 * 添加子节点
	 *
	 * @param child 子节点
	 * @param z 子节点的z order值
	 * @param ratioX x视差比例
	 * @param ratioY y视差比例
	 */
	void addChild(wyNode* child, int z, float ratioX, float ratioY);

	/**
	 * 对视差节点进行内部位移, 这个方法不改变视差节点的位置, 只是改变视差节点内子节点的位置
	 *
	 * @param dx x位移
	 * @param dy y位移
	 */
	void offsetBy(float dx, float dy);

	/**
	 * 开始fling, 如果当前正在fling，则不做任何事.
	 *
	 * @param velocityX x方向的fling速度, 如果没有设置水平平铺，则被忽略
	 * @param velocityY y方向的fling速度, 如果没有设置垂直平铺，则被忽略
	 */
	void fling(float velocityX, float velocityY);

	/**
	 * 中止fling，如果当前没有在fling，则不做任何事
	 */
	void stopFling();

	float getOffsetX() { return m_xOffset; }

	float getOffsetY() { return m_yOffset; }

	void setMinX(float x);

	void setMinY(float y);

	float getMinX() { return m_minXOffset; }

	float getMinY() { return m_minYOffset; }

	void setMaxX(float x);

	void setMaxY(float y);

	float getMaxX() { return m_maxXOffset; }

	float getMaxY() { return m_maxYOffset; }
};

#endif // __wyParallaxNode_h__
