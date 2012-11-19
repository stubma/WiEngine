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
#ifndef __wyMenuItemToggle_h__
#define __wyMenuItemToggle_h__

#include "wyMenuItem.h"
#include "wyArray.h"

/**
 * @class wyMenuItemToggle
 * a type of menu item. It consists of an array of menu items, only one of these items is valid and displays as
 * the current menu item. The valid item toggles between them every time the item is clicked.
 */
class WIENGINE_API wyMenuItemToggle : public wyMenuItem {
protected:
	/**
	 * the index of valid item
	 */
	int m_selectedIndex;

	/**
	 * \link wyArray wyArray\endlink
	 */
	wyArray* m_items;

	/**
	 * \link wyColor4B wyColor4B\endlink
	 */
	wyColor4B m_color;

private:
	static bool releaseItem(wyArray* arr, void* ptr, int index, void* data);

public:
	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up
	 * @param ... variable parameter list of \link wyMenuItem wyMenuItem object\endlink, must ends with NULL
	 */
	static wyMenuItemToggle* make(wyTargetSelector* downSelector, wyTargetSelector* upSelector, ...);

	/**
	 * constructor
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up
	 * @param ... variable parameter list of \link wyMenuItem wyMenuItem object\endlink, must ends with NULL
	 */
	wyMenuItemToggle(wyTargetSelector* downSelector, wyTargetSelector* upSelector, ...);

	/**
	 * destructor
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
	 * set the valid item
	 *
	 * @param index index of the valid item in the array, zero based
	 */
	void setSelectedIndex(int index);

	/**
	 * get the index of the valid item
	 */
	int getSelectedIndex() { return m_selectedIndex; }

	/**
	 * get array of the menu items
	 */
	wyArray* getMenuItems() { return m_items; }

	/**
	 * add one menu item to the array
	 *
	 * @param item \link wyMenuItem wyMenuItem object\endlink
	 */
	void addMenuItem(wyMenuItem* item);
};

#endif // __wyMenuItemToggle_h__
