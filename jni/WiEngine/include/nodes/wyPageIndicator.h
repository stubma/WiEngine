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
#ifndef __wyPageIndicator_h__
#define __wyPageIndicator_h__

#include "wyNode.h"

class wyPageControl;

/**
 * @class wyPageIndicator
 *
 * \link wyPageControl wyPageControl\endlink中的页面指示组件, 它是一个虚类, 可以通过
 * 继承实现不同风格的页面指示组件. 如果一个\link wyPageControl wyPageControl\endlink指定
 * 了一个页面指示组件, 则页面指示节点会是\link wyPageControl wyPageControl\endlink的子
 * 节点
 */
class WIENGINE_API wyPageIndicator : public wyNode {
	friend class wyPageControl;

protected:
	/**
	 * 当第一次初始化时调用
	 *
	 * @param page 当前\link wyPageControl wyPageControl\endlink的页面个数
	 * @param selectedIndex 当前选择的页面索引
	 */
	virtual void initWithPages(int page, int selectedIndex) = 0;

	/**
	 * 当有一个新页被添加时调用
	 *
	 * @param index 新页的索引
	 */
	virtual void onPageAdded(int index) = 0;

	/**
	 * 当有一个页面被删除时调用
	 *
	 * @param page 被删除的页节点
	 * @param index 被删除页的索引
	 */
	virtual void onPageRemoved(wyNode* page, int index) = 0;

	/**
	 * 当所有页面一次全部删除时被调用
	 */
	virtual void onPageAllRemoved() = 0;

	/**
	 * 当前页面改变时调用
	 *
	 * @param index 新的当前页索引
	 */
	virtual void onPageChanged(int index) = 0;

public:
	wyPageIndicator() {}
	virtual ~wyPageIndicator() {}
};

#endif // __wyPageIndicator_h__
