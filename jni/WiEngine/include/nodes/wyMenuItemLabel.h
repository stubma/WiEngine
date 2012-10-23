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
#ifndef __wyMenuItemLabel_h__
#define __wyMenuItemLabel_h__

#include "wyMenuItem.h"
#include "wyLabel.h"

/**
 * a type of menu item which uses label to construct its content
 */
class WIENGINE_API wyMenuItemLabel : public wyMenuItem {
protected:
	/// color of the normal state, \link wyColor4B wyColor4B\endlink
	wyColor4B m_normalColor;

	/// color of the disabled state, \link wyColor4B wyColor4B\endlink
	wyColor4B m_disabledColor;

public:
	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up
	 * @param label \link wyLabel wyLabel object\endlink
	 */
	static wyMenuItemLabel* make(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wyLabel* label);

	/**
	 * constructor
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up
	 * @param label \link wyLabel wyLabel object\endlink
	 */
	wyMenuItemLabel(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wyLabel* label);

	virtual ~wyMenuItemLabel();

	/// @see wyNode::setEnabled
	virtual void setEnabled(bool enabled);

	/// @see wyMenuItem::beforeInvoke
	virtual void beforeInvoke(wyTargetSelector* ts);

	/// @see wyNode::getAlpha
	virtual int getAlpha() { return m_normalColor.a; }

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha);

	/// @see wyNode::getColor
	virtual wyColor3B getColor();

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::setColor
	virtual void setColor(wyColor4B color);

	/**
	 * set the \link wyLabel wyLabel object\endlink
	 *
	 * @param label label of the menu item
	 */
	void setLabel(wyLabel* label);

	/**
	 * Get label node
	 *
	 * @return label of this menu item
	 */
	wyLabel* getLabel() { return (wyLabel*)getStateNode(); }

	/**
	 * set the color of disabled state
	 *
	 * @param color color of disable state
	 */
	void setDisabledColor(wyColor3B color);

	/**
	 * get the color of disabled state
	 *
	 * @return color of disable state
	 */
	wyColor3B getDisabledColor();
};

#endif // __wyMenuItemLabel_h__
