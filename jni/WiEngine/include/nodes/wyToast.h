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
#ifndef __wyToast_h__
#define __wyToast_h__

#include "wyNode.h"
#include "wyAction.h"

class wyDirector;

/**
 * @class wyToast
 *
 * A UI component behaves like Android Toast control. It consists of background and content
 * node, so it can display anything. Background node is better to be a scalable node, such as
 * \link wyNinePatchSprite wyNinePatchSprite\endlink
 */
class WIENGINE_API wyToast : public wyNode, public wyActionCallback {
	friend class wyDirector;

private:
	/// shared queue of all toasts
	static vector<wyToast*>* s_toastQueue;

	/// background node
	wyNode* m_bg;

	/// content node
	wyNode* m_content;

	/// margin left
	float m_leftMargin;

	/// margin right
	float m_rightMargin;

	/// margin top
	float m_topMargin;

	/// margin bottom
	float m_bottomMargin;

	/// dirty flag
	bool m_dirty;

	/// width of default background texture
	float m_defaultBgWidth;

	/// height of default background texture
	float m_defaultBgHeight;

	/// true means background is default
	bool m_useDefaultBg;

	/// duration in seconds
	float m_duration;

	/// toast position x
	float m_toastPositionX;

	/// toast position y
	float m_toastPositionY;

	/// true means use default toast position
	bool m_useDefaultPosition;

	/// true means this toast is shown immediately
	bool m_immediately;

protected:
	/**
	 * Constructor
	 *
	 * @param bg background node
	 * @param content content node
	 * @param duration duration in seconds
	 */
	wyToast(wyNode* bg, wyNode* content, float duration);

	/// clear all pending toast and release queue
	static void clear();

	/// perform layout of toast, including set position and size
	void layout();

	/// show a toast
	void putToScene();

	/// remove background node
	void removeBackground();

	/// add background node to running scene
	void addBackground();

	/// remove content node from bg
	void removeContent();

	/// add content node to bg node
	void addContent();

	/// Set background node
	void setBackground(wyNode* bg);

	/// Set content node
	void setContent(wyNode* c);

public:
	virtual ~wyToast();

	/**
	 * Create a toast with background and content node
	 *
	 * @param bg background node
	 * @param content content node
	 * @param duration duration in seconds
	 */
	static wyToast* make(wyNode* bg, wyNode* content, float duration);

	/**
	 * Create a toast with content node, it uses default background
	 *
	 * @param content content node
	 * @param duration duration in seconds
	 */
	static wyToast* make(wyNode* content, float duration);

	/**
	 * Create a toast with background node, and content text, the text
	 * will be assigned to a \link wyLabel wyLabel\endlink
	 *
	 * @param bg background node
	 * @param text content text string
	 * @param duration duration in seconds
	 */
	static wyToast* make(wyNode* bg, const char* text, float duration);

	/**
	 * Create a toast with content text. The background will be set to default style
	 *
	 * @param text content text
	 * @param duration duration in seconds
	 */
	static wyToast* make(const char* text, float duration);

	/// @see wyActonCallback::onActionStart
	virtual void onActionStart(wyAction* action) {}

	/// @see wyActonCallback::onActionStop
	virtual void onActionStop(wyAction* action);

	/// @see wyActonCallback::onActionStop
	virtual void onActionUpdate(wyAction* action, float t) {}

	/**
	 * Show this toast
	 *
	 * @param immediately true means the toast should be visible right now, or false
	 * 		means it will be shown after previous toast is disappeared, default is false
	 */
	void show(bool immediately = false);

	/**
	 * Get background node
	 */
	wyNode* getBackground() { return m_bg; }

	/**
	 * Get content node
	 */
	wyNode* getContent() { return m_content; }

	/**
	 * Set margin between content and background node.
	 */
	void setMargin(float top, float left, float right, float bottom);

	/**
	 * Get left margin
	 */
	float getLeftMargin() { return m_leftMargin; }

	/**
	 * Get right margin
	 */
	float getRightMargin() { return m_rightMargin; }

	/**
	 * Get top margin
	 */
	float getTopMargin() { return m_topMargin; }

	/**
	 * Get bottom margin
	 */
	float getBottomMargin() { return m_bottomMargin; }

	/**
	 * Set desired position where toast will be shown. If not set,
	 * toast will be placed in (wyDevice::winWidth / 2, wyDevice::winHeight * 4 / 5)
	 */
	void setToastPosition(float x, float y);
};

#endif // __wyToast_h__
