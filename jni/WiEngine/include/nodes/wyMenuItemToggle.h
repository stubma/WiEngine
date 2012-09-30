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
#ifndef __wyMenuItemToggle_h__
#define __wyMenuItemToggle_h__

#include "wyMenuItem.h"
#include "wyArray.h"

/**
 * @class wyMenuItemToggle
 * \if English
 * a type of menu item. It consists of an array of menu items, only one of these items is valid and displays as
 * the current menu item. The valid item toggles between them every time the item is clicked.
 * \else
 * Toggle菜单项，用于集成多个菜单项，每点击一次就切换到下一个菜单项，如果是最后一个菜单项，则切会第一个菜单项
 * \endif
 */
class WIENGINE_API wyMenuItemToggle : public wyMenuItem {
protected:
	/**
	 * \if English
	 * the index of valid item
	 * \else
	 * 当前菜单项显示的位置
	 * \endif
	 */
	int m_selectedIndex;

	/**
	 * \if English
	 * \link wyArray wyArray\endlink
	 * \else
	 * 保存菜单项\link wyArray wyArray对象指针\endlink
	 * \endif
	 */
	wyArray* m_items;

	/**
	 * \if English
	 * \link wyColor4B wyColor4B\endlink
	 * \else
	 * 颜色\link wyColor4B wyColor4B结构\endlink
	 * \endif
	 */
	wyColor4B m_color;

private:
	static bool releaseItem(wyArray* arr, void* ptr, int index, void* data);

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up
	 * @param ... variable parameter list of \link wyMenuItem wyMenuItem object\endlink, must ends with NULL
	 * \else
	 * 静态构造函数
	 *
	 * @param downSelector 按下菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param upSelector 松开菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param ... \link wyMenuItem wyMenuItem对象指针\endlink，可以为多个, 以NULL结束
	 * \endif
	 */
	static wyMenuItemToggle* make(wyTargetSelector* downSelector, wyTargetSelector* upSelector, ...);

	/**
	 * \if English
	 * constructor
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up
	 * @param ... variable parameter list of \link wyMenuItem wyMenuItem object\endlink, must ends with NULL
	 * \else
	 * 构造函数
	 *
	 * @param downSelector 按下菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param upSelector 松开菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param ... \link wyMenuItem wyMenuItem对象指针\endlink，可以为多个, 以NULL结束
	 * \endif
	 */
	wyMenuItemToggle(wyTargetSelector* downSelector, wyTargetSelector* upSelector, ...);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyMenuItemToggle();

	/// @see wyNode::setSelected
	virtual void setSelected(bool selected);

	/// @see wyNode::setEnabled
	virtual void setEnabled(bool enabled);

	/// @see wyMenuItem::beforeInvoke
	virtual void beforeInvoke(wyTargetSelector* ts);

	/// @see wyNode::getAlpha
	virtual int getAlpha() { return m_color.a; }

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha);

	/// @see wyNode::getColor
	virtual wyColor3B getColor();

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::setColor
	virtual void setColor(wyColor4B color);

	/**
	 * \if English
	 * set the valid item
	 *
	 * @param index index of the valid item in the array, zero based
	 * \else
	 * 设置当前菜单项显示的位置
	 *
	 * @param index 当前菜单项显示的位置
	 * \endif
	 */
	void setSelectedIndex(int index);

	/**
	 * \if English
	 * get the index of the valid item
	 * \else
	 * 得到当前菜单项显示的位置
	 *
	 * @return 当前菜单项显示的位置
	 * \endif
	 */
	int getSelectedIndex() { return m_selectedIndex; }

	/**
	 * \if English
	 * get array of the menu items
	 * \else
	 * 得到所有的菜单项数组
	 *
	 * @return \link wyArray wyArary\endlink
	 * \endif
	 */
	wyArray* getMenuItems() { return m_items; }

	/**
	 * \if English
	 * add one menu item to the array
	 *
	 * @param item \link wyMenuItem wyMenuItem object\endlink
	 * \else
	 * 添加一个菜单项\link wyMenuItem wyMenuItem对象指针\endlink
	 *
	 * @param item 菜单项\link wyMenuItem wyMenuItem对象指针\endlink
	 * \endif
	 */
	void addMenuItem(wyMenuItem* item);
};

#endif // __wyMenuItemToggle_h__
