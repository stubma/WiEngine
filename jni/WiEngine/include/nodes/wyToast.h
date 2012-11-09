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
 * \if English
 * A UI component behaves like Android Toast control. It consists of background and content
 * node, so it can display anything. Background node is better to be a scalable node, such as
 * \link wyNinePatchSprite wyNinePatchSprite\endlink
 * \else
 * 类似于Android的toast控件的节点, 由一个背景和内容两个节点组成. 因此它不限于只能显示文字, 内容节点可以
 * 为任意类型. 背景节点最好是一个可以拉伸的节点, 比如\link wyNinePatchSprite wyNinePatchSprite\endlink.
 * \endif
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
	 * \if English
	 * Create a toast with background and content node
	 *
	 * @param bg background node
	 * @param content content node
	 * @param duration duration in seconds
	 * \else
	 * 创建一个toast节点, 指定背景和内容节点
	 *
	 * @param bg 背景节点
	 * @param content 内容节点
	 * @param duration 持续显示时间, 时间到后会渐渐消失
	 * \endif
	 */
	static wyToast* make(wyNode* bg, wyNode* content, float duration);

	/**
	 * \if English
	 * Create a toast with content node, it uses default background
	 *
	 * @param content content node
	 * @param duration duration in seconds
	 * \else
	 * 创建一个toast节点, 指定内容节点, 使用缺省背景
	 *
	 * @param content 内容节点
	 * @param duration 持续显示时间, 时间到后会渐渐消失
	 * \endif
	 */
	static wyToast* make(wyNode* content, float duration);

	/**
	 * \if English
	 * Create a toast with background node, and content text, the text
	 * will be assigned to a \link wyLabel wyLabel\endlink
	 *
	 * @param bg background node
	 * @param text content text string
	 * @param duration duration in seconds
	 * \else
	 * 创建一个toast, 仅指定背景节点和内容文字. 文字会被赋于一个\link wyLabel wyLabel\endlink节点.
	 *
	 * @param bg 背景节点
	 * @param text 内容文字
	 * @param duration 持续显示时间, 时间到后会渐渐消失
	 * \endif
	 */
	static wyToast* make(wyNode* bg, const char* text, float duration);

	/**
	 * \if English
	 * Create a toast with content text. The background will be set to default style
	 *
	 * @param text content text
	 * @param duration duration in seconds
	 * \else
	 * 创建一个Toast节点, 只指定内容文字. 背景会设置成缺省样式
	 *
	 * @param text 内容文字
	 * @param duration 持续显示时间, 时间到后会渐渐消失
	 * \endif
	 */
	static wyToast* make(const char* text, float duration);

	/// @see wyActonCallback::onActionStart
	virtual void onActionStart(wyAction* action) {}

	/// @see wyActonCallback::onActionStop
	virtual void onActionStop(wyAction* action);

	/// @see wyActonCallback::onActionStop
	virtual void onActionUpdate(wyAction* action, float t) {}

	/**
	 * \if English
	 * Show this toast
	 *
	 * @param immediately true means the toast should be visible right now, or false
	 * 		means it will be shown after previous toast is disappeared, default is false
	 * \else
	 * 显示这个toast
	 *
	 * @param immediately true表示立刻显示这个toast. false表示等它之前一个toast消失之后再显示,
	 * 		缺省是false
	 * \endif
	 */
	void show(bool immediately = false);

	/**
	 * \if English
	 * Get background node
	 * \else
	 * 得到背景节点
	 * \endif
	 */
	wyNode* getBackground() { return m_bg; }

	/**
	 * \if English
	 * Get content node
	 * \else
	 * 得到内容节点
	 * \endif
	 */
	wyNode* getContent() { return m_content; }

	/**
	 * \if English
	 * Set margin between content and background node.
	 * \else
	 * 设置内容节点和背景节点边界的距离
	 * \endif
	 */
	void setMargin(float top, float left, float right, float bottom);

	/**
	 * \if English
	 * Get left margin
	 * \else
	 * 得到左边空隙
	 * \endif
	 */
	float getLeftMargin() { return m_leftMargin; }

	/**
	 * \if English
	 * Get right margin
	 * \else
	 * 得到右边空隙
	 * \endif
	 */
	float getRightMargin() { return m_rightMargin; }

	/**
	 * \if English
	 * Get top margin
	 * \else
	 * 得到上边空隙
	 * \endif
	 */
	float getTopMargin() { return m_topMargin; }

	/**
	 * \if English
	 * Get bottom margin
	 * \else
	 * 得到下边空隙
	 * \endif
	 */
	float getBottomMargin() { return m_bottomMargin; }

	/**
	 * \if English
	 * Set desired position where toast will be shown. If not set,
	 * toast will be placed in (wyDevice::winWidth / 2, wyDevice::winHeight * 4 / 5)
	 * \else
	 * 设置toast出现的位置, 如果不设置. 则缺省会放在屏幕中间偏下的位置, 具体坐标是:
	 * (wyDevice::winWidth / 2, wyDevice::winHeight * 4 / 5)
	 * \endif
	 */
	void setToastPosition(float x, float y);
};

#endif // __wyToast_h__
