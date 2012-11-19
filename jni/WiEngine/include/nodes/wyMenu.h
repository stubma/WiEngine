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
#ifndef __wyMenu_h__
#define __wyMenu_h__

#include "wyLayer.h"
#include "wyMenuItem.h"

#define DEFAULT_PADDING 5

/**
 * @class wyMenu
 * menu. A menu consists of one or more menu items.
 */
class WIENGINE_API wyMenu : public wyLayer {
protected:
	/**
	 * to mark the menu item being selected, \link wyMenuItem wyMenuItem\endlink
	 */
	wyMenuItem* m_selectedItem;

private:
	wyMenuItem* itemForTouch(wyMotionEvent& event);

public:
	/**
	 * factory function, used to create instance with autoRelease enabled
	 */
	static wyMenu* make();

	/**
	 * factory function, used to create instance with autoRelease enabled.
	 * The parameters passed in must ends with a NULL parameter.
	 *
	 * @param item1 the first menu item of the menu \link wyMenuItem wyMenuItem\endlink
	 */
	static wyMenu* make(wyMenuItem* item1, ...);

	/**
	 * constructor
	 */
	wyMenu();

	/**
	 * constructor
	 * The parameters passed in must ends with a NULL parameter.
	 *
	 * @param item1 the 1st menu item \link wyMenuItem wyMenuItem\endlink
	 */
	wyMenu(wyMenuItem* item1, ...);

	/**
	 * destructor
	 */
	virtual ~wyMenu();

	/// @see wyNode::touchesBegan
	virtual bool touchesBegan(wyMotionEvent& e);

	/// @see wyNode::touchesMoved
	virtual bool touchesMoved(wyMotionEvent& e);

	/// @see wyNode::touchesEnded
	virtual bool touchesEnded(wyMotionEvent& e);

	/// @see wyNode::touchesCancelled
	virtual bool touchesCancelled(wyMotionEvent& e);

	/// @see wyNode::hitTest
	virtual bool hitTest(float x, float y);

	/**
	 * align menu items into one column, from the top to the bottom
	 *
	 * @param padding the padding between 2 neighbor items
	 */
	void alignItemsVertically(float padding = DEFAULT_PADDING);

	/**
	 * align menu items into one row, form the left to the right
	 *
	 * @param padding the padding between 2 neighbor items
	 */
	void alignItemsHorizontally(float padding = DEFAULT_PADDING);

	/**
	 * align menu items into one or more columns, the columns will be aligned from left to right
	 *
	 * @param count specify the row count
	 * @param[in] columns an array. For example, array of [3, 2] means 3 items in 1st row and 2 in the 2nd
	 * @param padding padding between 2 neighbor rows
	 */
	void alignItemsInColumns(int count, int* columns, float padding = DEFAULT_PADDING);

	/**
	 * align menu items into one or more rows, the rows will be aligned from top to bottom
	 *
	 * @param count the capacity of one single row
	 * @param[in] rows an array. For example, array of [3, 2] means 3 items in 1st column and 2 in the 2nd
	 * @param padding padding between 2 neighbor columns
	 */
	void alignItemsInRows(int count, int* rows, float padding = DEFAULT_PADDING);

	/**
	 * add one menu item
	 *
	 * @param item \link wyMenuItem wyMenuItem\endlink
	 */
	void addMenuItem(wyMenuItem* item);
};

#endif // __wyMenu_h__
