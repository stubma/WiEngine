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
#ifndef __wyMenuItemSprite_h__
#define __wyMenuItemSprite_h__

#include "wyMenuItem.h"
#include "wySprite.h"

/**
 * a type of menu item which uses \link wySprite wySprite object\endlink as its content
 */
class WIENGINE_API wyMenuItemSprite : public wyMenuItem {
protected:
	/// @see wyCompoundNode::getStateTag
	virtual int getStateTag();

public:
	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up
	 * @param normal sprite of the normal state, \link wySprite wySprite\endlink
	 * @param selected sprite of the selected state
	 * @param disabled sprite of the disabled state
	 */
	static wyMenuItemSprite* make(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wySprite* normal, wySprite* selected, wySprite* disabled);

	/**
	 * constructor
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up
	 * @param normal sprite of the normal state, \link wySprite wySprite\endlink
	 * @param selected sprite of the selected state
	 * @param disabled sprite of the disabled state
	 */
	wyMenuItemSprite(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wySprite* normal, wySprite* selected, wySprite* disabled);

	virtual ~wyMenuItemSprite();

	/**
	 * set sprite of the normal state
	 *
	 * @param normal \link wySprite wySprite object\endlink
	 */
	void setNormalSprite(wySprite* normal);

	/**
	 * get sprite of the normal state
	 *
	 * @return \link wySprite wySprite\endlink of normal state
	 */
	wySprite* getNormalSprite();

	/**
	 * set sprite of the selected state
	 *
	 * @param selected \link wySprite wySprite object\endlink
	 */
	void setSelectedSprite(wySprite* selected);

	/**
	 * get sprite of the selected state
	 *
	 * @return \link wySprite wySprite\endlink of selected state
	 */
	wySprite* getSelectedSprite();

	/**
	 * set sprite of the disabled state
	 *
	 * @param disabled \link wySprite wySprite object \endlink
	 */
	void setDisabledSprite(wySprite* disabled);

	/**
	 * get sprite of the disabled state
	 *
	 * @return \link wySprite wySprite\endlink of disabled state
	 */
	wySprite* getDisabledSprite();
};

#endif // __wyMenuItemSprite_h__
