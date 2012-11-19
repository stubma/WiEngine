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
#ifndef __wyMenuItem_h__
#define __wyMenuItem_h__

#include "wyCompoundNode.h"
#include "wyTargetSelector.h"

/// the default font size, in SP
#define DEFAULT_FONT_SIZE 32

/// tag of the current selected item
#define TAG_CURRENT_ITEM 0xc0c05001

/// tag of the zoom action when the item is clicked
#define TAG_ZOOM_ACTION 0xc0c05002

/**
 * Menu item base class. It must be used with \link wyMenu wyMenu\endlink.
 */
class WIENGINE_API wyMenuItem : public wyCompoundNode {
protected:
	/// the scale rate when the item is clicked
	float m_clickScale;

	/// Save original scale before perform clicking scale effect
	float m_originalScale;

protected:
	/// check click scale, if set, do scaling
	void checkClickScale(bool selected);

public:
	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up, \link wyTargetSelector wyTargetSelector\endlink
	 */
	static wyMenuItem* make(wyTargetSelector* downSelector, wyTargetSelector* upSelector);

	/**
	 * constructor
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up, \link wyTargetSelector wyTargetSelector\endlink
	 */
	wyMenuItem(wyTargetSelector* downSelector, wyTargetSelector* upSelector);

	virtual ~wyMenuItem();

	/// @see wyNode::setSelected
	virtual void setSelected(bool selected);

	/**
	 * called before click down, up or move event is handled
	 *
	 * @param ts callback \link wyTargetSelector wyTargetSelector\endlink
	 */
	virtual void beforeInvoke(wyTargetSelector* ts);

	/**
	 * set the scale rate, default value is 1.4f
	 */
	void setClickScale(float scale) { m_clickScale = scale; }

	/**
	 * get the scale rate, default value is 1.4f
	 */
	float getClickScale() { return m_clickScale; }
};

#endif // __wyMenuItem_h__
