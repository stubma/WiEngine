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
#ifndef __wyButton_h__
#define __wyButton_h__

#include "wyCompoundNode.h"

/**
 * @class wyButton
 * Button class. Each button has 6 states, which are normal, selected, disabled, focused.
 */
class WIENGINE_API wyButton : public wyCompoundNode {
private:
	/// old color of normal state node
	wyColor3B m_oldNormalColor;

protected:
	/**
	 * specify how much the button will be scaled while being clicked
	 */
	float m_clickScale;

	/**
	 * Save original scale before perform clicking scale effect
	 */
	float m_originalScale;

protected:
	/// @see wyCompoundNode::getStateTag
	virtual int getStateTag();

public:
	/**
	 * factory function, used to create a new instance with autoRelease enabled.
	 *
	 * @param normal \link wyNode wyNode\endlink, can't be NULL
	 * @param selected can be NULL
	 * @param disabled can be NULL
	 * @param focused can be NULL
	 * @param downSelector \link wyTargetSelector wyTargetSelector\endlink triggered when clicked down, can be NULL
	 * @param upSelector \link wyTargetSelector wyTargetSelector\endlink triggered when clicked up, can be NULL
	 */
	static wyButton* make(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyTargetSelector* downSelector, wyTargetSelector* upSelector);

	/**
	 * constructor
	 * @param normal \link wyNode wyNode\endlink, can't be NULL
	 * @param selected can be NULL
	 * @param disabled can be NULL
	 * @param focused can be NULL
	 * @param downSelector \link wyTargetSelector wyTargetSelector\endlink triggered when clicked down, can be NULL
	 * @param upSelector \link wyTargetSelector wyTargetSelector\endlink triggered when clicked up, can be NULL
	 */
	wyButton(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyTargetSelector* downSelector, wyTargetSelector* upSelector);

	/**
	 * destructor
	 */
	virtual ~wyButton();

	/// @see wyNode::setSelected
	virtual void setSelected(bool selected);

	/**
	 * setter, to set the normal state node
	 *
	 * @param \link wyNode wyNode\endlink, can't be NULL
	 */
	void setNormalState(wyNode* normal);

	/**
	 * setter, to set the selected state
	 *
	 * @param selected \link wyNode wyNode\endlink
	 */
	void setSelectedState(wyNode* selected);

	/**
	 * setter, to set the disabled state
	 *
	 * @param disabled \link wyNode wyNode\endlink
	 */
	void setDisabledState(wyNode* disabled);

	/**
	 * setter, to set the focused state
	 *
	 * @param focused \link wyNode wyNode\endlink
	 */
	void setFocusedState(wyNode* focused);

	/**
	 * to set the corresponding state's texture through one single call
	 *
	 * @param normal \link wyTexture2D wyTexture2D\endlink, the normal state won't change if this value is NULL
	 * @param selected \link wyTexture2D wyTexture2D\endlink, the selected state won't change if this value is NULL
	 * @param disabled \link wyTexture2D wyTexture2D\endlink, the disabled state won't change if this value is NULL
	 * @param focused \link wyTexture2D wyTexture2D\endlink, the focused state won't change if this value is NULL
	 */
	void setTexture(wyTexture2D* normal, wyTexture2D* selected, wyTexture2D* disabled, wyTexture2D* focused);

	/**
	 * Set texture rect of button state node. But not all node has setTextureRect method so only
	 * \link wyTextureNode wyTextureNode\endlink and \link wySpriteEx wySpriteEx\endlink support this usage.
	 *
	 * @param normalRect texture rect of normal state, or NULL if you don't want to change it
	 * @param selectedRect texture rect of selected state, or NULL if you don't want to change it
	 * @param disabledRect texture rect of disabled state, or NULL if you don't want to change it
	 * @param focusedRect texture rect of focused state, or NULL if you don't want to change it
	 */
	void setTextureRect(wyRect* normalRect, wyRect* selectedRect, wyRect* disabledRect, wyRect* focusedRect);

	/**
	 * to specify how much the button will be scaled while being clicked
	 *
	 * @param scale <1.0f means scale down, >1.0f means scale up
	 */
	void setClickScale(float scale) { m_clickScale = scale; }

	/**
	 * getter
	 */
	float getClickScale() { return m_clickScale; }
};

#endif // __wyButton_h__
