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
#ifndef __wyDotPageIndicator_h__
#define __wyDotPageIndicator_h__

#include "wyPageIndicator.h"
#include "WiEngine-Classes.h"

/**
 * Dot indicator of page control
 */
class WIENGINE_API wyDotPageIndicator : public wyPageIndicator {
private:
	/// material for texture of unselected state
	wyMaterial* m_dotMaterial;

	/// material for texture of selected state
	wyMaterial* m_selectedDotMaterial;

	/// dot texture
	wyTexture2D* m_dot;

	/// selected dot texture
	wyTexture2D* m_selectedDot;

	/// the rect area used in dot texture
	wyRect m_dotRect;

	/// the rect area used in selected dot texture
	wyRect m_selectedDotRect;

	/**
	 * 当前页面总数
	 */
	int m_pageCount;

	/**
	 * 当前页面索引
	 */
	int m_selectedIndex;

	/**
	 * 点之间的间距, 缺省为DP(4)
	 */
	float m_dotSpacing;

protected:
	/**
	 * 构造函数
	 *
	 * @param dot 页面没有被选中时的图片, 不能为NULL
	 * @param dotRect 如果dot是一个图片集, 则表示点图片在图片集中的位置
	 * @param selectedDot 页面被选中时的图片, 不能为NULL
	 * @param selectedDotRect 如果selectedDot是一个图片集, 则表示选中的点图片在图片集中的位置
	 */
	wyDotPageIndicator(wyTexture2D* dot, wyRect dotRect, wyTexture2D* selectedDot, wyRect selectedDotRect);

	/// @see wyPageIndicator::initWithPages
	virtual void initWithPages(int page, int selectedIndex);

	/// @see wyPageIndicator::onPageAdded
	virtual void onPageAdded(int index);

	/// @see wyPageIndicator::onPageRemoved
	virtual void onPageRemoved(wyNode* page, int index);

	/// @see wyPageIndicator::onPageAllRemoved
	virtual void onPageAllRemoved();

	/// @see wyPageIndicator::onPageChanged
	virtual void onPageChanged(int index);

private:
	/**
	 * 更新页面指示节点的大小
	 */
	void updateContentSize();

public:
	/**
	 * Static creator
	 *
	 * @param dot dot texture
	 * @param selectedDot dot texture for current page
	 * @return \link wyDotPageIndicator wyDotPageIndicator\endlink
	 */
	static wyDotPageIndicator* make(wyTexture2D* dot, wyTexture2D* selectedDot);

	/**
	 * Static creator
	 *
	 * @param dot dot texture for inactive pages
	 * @param dotRect texture rect when \c dot is an atlas texture
	 * @param selectedDot dot texture for current page
	 * @param selectedDotRect texture rect when \c selectedDot is an atlas texture
	 * @return \link wyDotPageIndicator wyDotPageIndicator\endlink
	 */
	static wyDotPageIndicator* make(wyTexture2D* dot, wyRect dotRect, wyTexture2D* selectedDot, wyRect selectedDotRect);

	virtual ~wyDotPageIndicator();

	/// @see wyNode::updateMesh
	virtual void updateMesh();

	/// set spacing between dot
	void setDotSpacing(float spacing) { m_dotSpacing = spacing; }

	/// get spacing between dot
	float getDotSpacing() { return m_dotSpacing; }
};

#endif // __wyDotPageIndicator_h__
