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
#ifndef __wyDialog_h__
#define __wyDialog_h__

#include "wyColorLayer.h"
#include "wyScene.h"
#include "wyBitmapFont.h"
#include "wyDialogTransition.h"

/**
 * @class wyDialog
 *
 * Base class for dialog abstraction
 */
class WIENGINE_API wyDialog : public wyColorLayer {
private:
	/// button info of dialog
	struct Button {
		/// button node
		wyNode* button;

		/// label node
		wyNode* label;

		/// target selector
		wyTargetSelector* sel;

		/// is two columns button
		bool twoColumns;
	};

protected:
	/// true means dialog is created
	bool m_created;

	/// background node, could be any node, but it is better a sprite or nine patch sprite
	wyNode* m_bg;

	/// background left padding
	float m_leftPadding;

	/// background right padding
	float m_rightPadding;

	/// background top padding
	float m_topPadding;

	/// background bottom padding
	float m_bottomPadding;

	/// title text
	wyNode* m_title;

	/// content node
	wyNode* m_content;

	/// button list
	vector<Button>* m_buttons;

	/// default selector for button
	wyTargetSelector* m_defaultSelector;

	/// transition
	wyDialogTransition* m_transition;

	/// which button is equal with back button
	int m_backKeyButtonIndex;

protected:
	wyDialog();

	/// default method invoked for a button if no selector attached to it
	void onCloseDialog(wyTargetSelector* ts);

public:
	virtual ~wyDialog();
	static wyDialog* make();

	/// @see wyNode::keyDown
	virtual bool keyDown(wyKeyEvent& event);

	/// @see wyNode::keyUp
	virtual bool keyUp(wyKeyEvent& event);

	/// @see wyNode::keyMultiple
	virtual bool keyMultiple(wyKeyEvent& event);

	/// @see wyNode::touchesBegan
	virtual bool touchesBegan(wyMotionEvent& e);

	/// @see wyNode::touchesMoved
	virtual bool touchesMoved(wyMotionEvent& e);

	/// @see wyNode::touchesEnded
	virtual bool touchesEnded(wyMotionEvent& e);

	/// @see wyNode::touchesCancelled
	virtual bool touchesCancelled(wyMotionEvent& e);

	/// @see wyNode::touchesPointerEnded
	virtual bool touchesPointerBegan(wyMotionEvent& e);

	/// @see wyNode::touchesPointerEnded
	virtual bool touchesPointerEnded(wyMotionEvent& e);

	/**
	 * Make the dialog created, i.e., layout is properly decided
	 *
	 * @return self
	 */
	wyDialog* create();

	/**
	 * Show dialog in scene
	 *
	 * @param withAnimation true means performing animation when showing dialog, but this flag is
	 * 		useless if no \link wyDialogTransition wyDialogTransition\endlink is specified. By default
	 * 		it is true
	 * @return self
	 */
	wyDialog* show(bool withAnimation = true);

	/**
	 * Dismiss dialog
	 *
	 * @param withAnimation true means performing animation when dismissing dialog, but this flag is
	 * 		useless if no \link wyDialogTransition wyDialogTransition\endlink is specified. By default
	 * 		it is true
	 */
	void dismiss(bool withAnimation = true);

	/**
	 * Set background of dialog
	 *
	 * \note
	 * If you don't set a background, then WiEngine will use a default background image, mainly white
	 *
	 * @param bg background of dialog, usually it is a \link wyNinePatchSprite wyNinePatchSprite\endlink object,
	 * 		or \link wySprite wySprite\endlink, or \link wySpriteEx wySpriteEx\endlink. You can use other node if
	 * 		you are sure it will be ok.
	 * @return self
	 */
	wyDialog* setBackground(wyNode* bg);

	/**
	 * Get background node, background node is container of other nodes
	 *
	 * @return background node
	 */
	wyNode* getBackground() { return m_bg; }

	/**
	 * Set padding of background node. The size of background node is determined
	 * by content size and padding
	 *
	 * @param left left padding, in pixels
	 * @param top top padding in pixels
	 * @param right right padding in pixels
	 * @param bottom bottom padding in pixels
	 * @return self
	 */
	wyDialog* setBackgroundPadding(float left, float top, float right, float bottom);

	/**
	 * Set title
	 *
	 * @param title title node, it may be \link wyLabel wyLabel\endlink, \link wyAtlasLabel wyAtlasLabel\endlink
	 * 		or \link wyBitmapFontLabel wyBitmapFontLabel\endlink. But you can use other node if you like.
	 * @return self
	 */
	wyDialog* setTitle(wyNode* title);

	/**
	 * Set message node
	 *
	 * @param content content
	 * @return self
	 */
	wyDialog* setContent(wyNode* content);

	/**
	 * Add a button to dialog
	 *
	 * @param button button node
	 * @param label label node or NULL if \c button node already has label in it
	 * @param sel target selector to be triggered for this button or NULL if just close dialog
	 * @return self
	 */
	wyDialog* addButton(wyNode* button, wyNode* label, wyTargetSelector* sel);

	/**
	 * Add two buttons which is managed in two columns layout
	 *
	 * @param button1 button node
	 * @param label1 label node for \c button1
	 * @param sel1 target selector for \c button1. If NULL, this button only close dialog
	 * @param button2 second column button node
	 * @param label2 label node for \c button2
	 * @param sel2 target selector for \c button2. If NULL, this button only close dialog
	 */
	wyDialog* addTwoColumnsButton(wyNode* button1, wyNode* label1, wyTargetSelector* sel1, wyNode* button2, wyNode* label2, wyTargetSelector* sel2);

	/**
	 * Set dialog transition which apply to dialog when showing or closing
	 *
	 * @param t \link wyDialogTransition wyDialogTransition\endlink
	 * @return self
	 */
	wyDialog* setTransition(wyDialogTransition* t);

	/**
	 * Set which button should be checked when back key is pressed. It is useless for device which
	 * doesn't have back key. The default index is zero so it is not related with any button by default.
	 *
	 * @param index index of button, if it is invalid, back key just close dialog without any action
	 * @return self
	 */
	wyDialog* setBackKeyEquivalentButtonIndex(int index);
};

#endif // __wyDialog_h__
