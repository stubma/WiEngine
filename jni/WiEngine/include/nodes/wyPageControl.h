/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyPageControl_h__
#define __wyPageControl_h__

#include "wyLayer.h"
#include "wyArray.h"
#include "wyScroller.h"
#include "wyPageIndicator.h"

class wyPageControl;

/**
 * @struct wyPageControlCallback
 *
 * page control event callback
 */
class WIENGINE_API wyPageControlCallback {
public:
	/**
	 * Invoked when a page is clicked. Clicked page must be current page
	 *
	 * @param pageControl \link wyPageControl wyPageControl\endlink
	 * @param index index of current page, in page list
	 */
	virtual void onPageControlPageClicked(wyPageControl* pageControl, int index) = 0;

	/**
	 * Invoked when current page is changed
	 *
	 * @param pageControl \link wyPageControl wyPageControl\endlink
	 * @param index index of current page in page list
	 */
	virtual void onPageControlPageChanged(wyPageControl* pageControl, int index) = 0;

	/**
	 * Invoked for every page when page control is scrolling
	 *
	 * @param pageControl \link wyPageControl wyPageControl\endlink
	 * @param page page node
	 * @param offset offset of page center, the offset is relative to page control node center.
	 * 		Generally page control's size is same as screen. If you change page control position and size,
	 * 		pay attention to what this \c offset means
	 */
	virtual void onPageControlPagePositionChanged(wyPageControl* pageControl, wyNode* page, float offset) = 0;
};

/**
 * @class wyPageControl
 *
 * 类似于iPhone中的PageControl, 提供一个水平或垂直滚动的列表. 里面的每一项
 * 是一个\link wyNode wyNode\endlink 的子类
 */
class WIENGINE_API wyPageControl : public wyNode {
private:
	/// all page nodes
	wyArray* m_pages;

	/// 页之间的水平间隔
	float m_pageSpacing;

	/// container node of pages
	wyLayer* m_container;

	/// 水平方向的中心点, 缺省是page control的中心位置. 仅用于垂直布局模式.
	float m_centerX;

	/// 垂直方向的中心点, 缺省是page control的中心位置. 仅用于水平布局模式.
	float m_centerY;

	/// 记录上一次touch事件的x位置
	float m_lastX;

	/// 记录上一次touch事件的y位置
	float m_lastY;
	
	/// x position in touch began event
	float m_beginX;
	
	/// y position in touch began event
	float m_beginY;

	/// accumulated delta x move
	float m_xMove;

	/// accumulated delta y move
	float m_yMove;

	/// whether end touch should be considered as a large move
	bool m_largeMove;

	/// true表示当前正在滚动
	bool m_scrolling;

	/// true表示当前正在fling
	bool m_flinging;

	/// true表示垂直排列页, 最下面的索引为0
	bool m_vertical;

	/// start page index
	int m_initialPageIndex;

	/// \link wyScroller wyScroller 结构指针\endlink
	wyScroller* m_scroller;

	/**
	 * 页面指示节点
	 */
	wyPageIndicator* m_indicator;

	/// callback
	wyPageControlCallback* m_callback;

private:
	static bool releasePage(wyArray* arr, void* ptr, int index, void* data);

	/// update fling status
	void updateFling(wyTargetSelector* ts);

	/**
	 * 更新所有的页位置
	 */
	void updatePagePositions();

	/**
	 * 获得某页的中心x位置, 仅适用于水平布局情况
	 *
	 * @param index 页索引
	 * @return 页中心x位置
	 */
	float getPageCenterX(int index);

	/**
	 * 获得某页的中心y位置, 仅适用于垂直布局情况
	 *
	 * @param index 页索引
	 * @return 页中心y位置
	 */
	float getPageCenterY(int index);

	/**
	 * 获得容器的宽度，这个宽度是最佳宽度, 仅用于水平布局模式.
	 *
	 * @return 容器的宽度
	 */
	float getContainerWidth();

	/**
	 * 获得容器的高度，这个宽度是最佳高度, 仅用于垂直布局模式.
	 *
	 * @return 容器的高度
	 */
	float getContainerHeight();

	/**
	 * 根据当前位置得到左边的页索引，如果为-1，表示当前位置已经在第一页
	 *
	 * @return 当前位置左边的页索引
	 */
	int getLeftIndex();

	/**
	 * 根据当前位置得到右边的页索引，如果等于最大页数，表示当前位置已经在最后一页的右边
	 *
	 * @return 当前位置右边的页索引
	 */
	int getRightIndex();

	/**
	 * 根据当前的位置得到一个最接近当前位置的页索引
	 *
	 * @return 最接近当前位置的页索引
	 */
	int getBestIndex();

	/**
	 * 得到可见的第一个页的索引
	 *
	 * @return 可见的第一个页的索引
	 */
	int getVisibleFirstIndex();

	/**
	 * 得到可见的最后一个页的索引
	 *
	 * @return 可见的最后一个页的索引
	 */
	int getVisibleLastIndex();

	/**
	 * 调用回调通知page改变事件
	 */
	void notifyOnPageChanged();

	/**
	 * 调用回调通知page点击事件
	 *
	 * @param index 被点击的页索引
	 */
	void notifyOnPageClicked(int index);

	/**
	 * Notify callback about page position changed
	 */
	void notifyOnPagePositionChanged();

protected:
	wyPageControl();

public:
	static wyPageControl* make();

	virtual ~wyPageControl();

	/// @see wyNode::touchesBegan
	virtual bool touchesBegan(wyMotionEvent& e);

	/// @see wyNode::touchesMoved
	virtual bool touchesMoved(wyMotionEvent& e);

	/// @see wyNode::touchesEnded
	virtual bool touchesEnded(wyMotionEvent& e);

	/// @see wyNode::touchesCancelled
	virtual bool touchesCancelled(wyMotionEvent& e);

	/**
	 * 添加一页
	 *
	 * @param page \link wyNode wyNode\endlink
	 */
	void addPage(wyNode* page);

	/**
	 * 在指定位置添加一页
	 *
	 * @param page \link wyNode wyNode\endlink
	 * @param index 指定要添加到的位置, 如果超过有效范围, 则不做任何事
	 */
	void addPageAt(wyNode* page, int index);

	/**
	 * 删除一页
	 *
	 * @param page \link wyNode wyNode\endlink
	 */
	void removePage(wyNode* page);

	/**
	 * 删除指定位置的页
	 *
	 * @param index 页索引，如果超出范围则无效果
	 */
	void removePageAt(int index);

	/**
	 * 删除所有页
	 */
	void removeAllPages();

	/**
	 * 设置初始页，该方法可用来初始化当前显示的页。这个方法不会触发page
	 * changed回调。使用这个方法设置页没有滚动的动画效果，因此只适合
	 * 在创建时期初始化page control.
	 */
	void setInitialPage(int index);

	/**
	 * 切换到某页
	 *
	 * @param index 要切换到的页
	 * @param animate true表示需要附带切换的动画效果, false表示不需要. 缺省是false
	 * @param duration 切换动画效果的持续时间, 仅当animate为true时有效. 缺省值是1秒.
	 */
	void gotoPage(int index, bool animate = false, float duration = 1.0f);

	/**
	 * 设置页间的间隔
	 *
	 * @param spacing 页之间的间隔
	 */
	void setPageSpacing(float spacing);

	/**
	 * 获得页间的间隔
	 *
	 * @return 页之间的间隔
	 */
	float getPageSpacing() { return m_pageSpacing; }

	/**
	 * 获得页在垂直位置的中心, 仅适用于水平型布局
	 *
	 * @return 垂直位置的中心
	 */
	float getCenterY() { return m_centerY; }

	/**
	 * 设置垂直位置的中心, 仅适用于水平型布局
	 *
	 * @param y 垂直位置的中心
	 */
	void setCenterY(float y) { m_centerY = y; }

	/**
	 * 获得页在水平位置的中心, 仅适用于垂直型布局
	 *
	 * @return 水平位置的中心
	 */
	float getCenterX() { return m_centerX; }

	/**
	 * 设置水平位置的中心, 仅适用于垂直型布局
	 *
	 * @param x 水平位置的中心
	 */
	void setCenterX(float x) { m_centerX = x; }

	/**
	 * 得到页数
	 *
	 * @return 页数
	 */
	int getPageCount() { return m_pages->num; }

	/**
	 * 设置回调
	 *
	 * @param callback \link wyPageControlCallback wyPageControlCallback\endlink 结构指针, callback的内容
	 * 		会被复制，因此\link wyPageControl wyPageControl\endlink 不会负责释放该指针。如果指针为NULL，表示清
	 * 		除之前设置的回调
	 */
	void setCallback(wyPageControlCallback* callback) { m_callback = callback; }

	/**
	 * 是否垂直排列页
	 *
	 * @return true表示垂直排列页
	 */
	bool isVertical() { return m_vertical; }

	/**
	 * 设置是否垂直排列页
	 *
	 * @param flag true表示垂直排列页
	 */
	void setVertical(bool flag);

	/**
	 * 设置一个页面指示节点, 必须是\link wyPageIndicator wyPageIndicator\endlink的子类. 页面指示节点将被
	 * 加为\link wyPageControl wyPageControl\endlink的子节点
	 *
	 * @param indicator \link wyPageIndicator wyPageIndicator\endlink的子类, 如果为NULL表示去掉页面指示节点
	 */
	void setPageIndicator(wyPageIndicator* indicator);

	/**
	 * 获得当前的页面指示节点
	 *
	 * @return \link wyPageIndicator wyPageIndicator\endlink的子类
	 */
	wyPageIndicator* getPageIndicator() { return m_indicator; }
};

#endif // __wyPageControl_h__
