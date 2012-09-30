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
#ifndef __wyMenu_h__
#define __wyMenu_h__

#include "wyLayer.h"
#include "wyMenuItem.h"

#define DEFAULT_PADDING 5

/**
 * @class wyMenu
 * \if English
 * menu. A menu consists of one or more menu items.
 * \else
 * 菜单显示层的封装
 * \endif
 */
class WIENGINE_API wyMenu : public wyLayer {
protected:
	/**
	 * \if English
	 * to mark the menu item being selected, \link wyMenuItem wyMenuItem\endlink
	 * \else
	 * 当前事件选中的\link wyMenuItem wyMenuItem对象指针\endlink
	 * \endif
	 */
	wyMenuItem* m_selectedItem;

private:
	wyMenuItem* itemForTouch(wyMotionEvent& event);

public:
	/**
	 * \if English
	 * factory function, used to create instance with autoRelease enabled
	 * \else
	 * 静态构造函数
	 * \endif
	 */
	static wyMenu* make();

	/**
	 * \if English
	 * factory function, used to create instance with autoRelease enabled.
	 * The parameters passed in must ends with a NULL parameter.
	 *
	 * @param item1 the first menu item of the menu \link wyMenuItem wyMenuItem\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param item1 添加到菜单显示层中的\link wyMenuItem wyMenuItem对象指针\endlink,可以添加多个，以NULL结束
	 * \endif
	 */
	static wyMenu* make(wyMenuItem* item1, ...);

	/**
	 * \if English
	 * constructor
	 * \else
	 * 构造函数
	 * \endif
	 */
	wyMenu();

	/**
	 * \if English
	 * constructor
	 * The parameters passed in must ends with a NULL parameter.
	 *
	 * @param item1 the 1st menu item \link wyMenuItem wyMenuItem\endlink
	 * \else
	 * 构造函数
	 *
	 * @param item1 添加到菜单显示层中的\link wyMenuItem wyMenuItem对象指针\endlink,可以添加多个，以NULL结束
	 * \endif
	 */
	wyMenu(wyMenuItem* item1, ...);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
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
	 * \if English
	 * align menu items into one column, from the top to the bottom
	 *
	 * @param padding the padding between 2 neighbor items
	 * \else
	 * 垂直排列菜单, 只排一列
	 *
	 * @param padding 菜单项垂直间隔
	 * \endif
	 */
	void alignItemsVertically(float padding = DEFAULT_PADDING);

	/**
	 * \if English
	 * align menu items into one row, form the left to the right
	 *
	 * @param padding the padding between 2 neighbor items
	 * \else
	 * 水平排列菜单, 只排一行
	 *
	 * @param padding 菜单项水平间隔
	 * \endif
	 */
	void alignItemsHorizontally(float padding = DEFAULT_PADDING);

	/**
	 * \if English
	 * align menu items into one or more columns, the columns will be aligned from left to right
	 *
	 * @param count specify the row count
	 * @param[in] columns an array. For example, array of [3, 2] means 3 items in 1st row and 2 in the 2nd
	 * @param padding padding between 2 neighbor rows
	 * \else
	 * 从第1行开始一直往下排列，每一行的列数通过参数指定. 每一行的列宽度是相等的。
	 *
	 * @param count columns数组的长度
	 * @param columns 每一行中的列数，比如{3, 2}，那么第一行会排3个，第二行会排2个
	 * @param padding 每行之间的间隔
	 * \endif
	 */
	void alignItemsInColumns(int count, int* columns, float padding = DEFAULT_PADDING);

	/**
	 * \if English
	 * align menu items into one or more rows, the rows will be aligned from top to bottom
	 *
	 * @param count the capacity of one single row
	 * @param[in] rows an array. For example, array of [3, 2] means 3 items in 1st column and 2 in the 2nd
	 * @param padding padding between 2 neighbor columns
	 * \else
	 * 从第1列开始一直往右排列，每一列的行数通过参数指定. 每一列的行的高度是相等的.
	 *
	 * @param count rows数组的长度
	 * @param rows 每一列中的行数，比如{3, 2}，那么第一列会排3个，第二列会排2个
	 * @param padding 每列之间的间隔
	 * \endif
	 */
	void alignItemsInRows(int count, int* rows, float padding = DEFAULT_PADDING);

	/**
	 * \if English
	 * add one menu item
	 *
	 * @param item \link wyMenuItem wyMenuItem\endlink
	 * \else
	 * 添加一个菜单项\link wyMenuItem wyMenuItem对象指针\endlink
	 *
	 * @param item 添加到菜单显示层中的\link wyMenuItem wyMenuItem对象指针\endlink
	 * \endif
	 */
	void addMenuItem(wyMenuItem* item);
};

#endif // __wyMenu_h__
