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
 * \if English
 * Base class for dialog abstraction
 * \else
 * 对话框基类
 * \endif
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
	 * \if English
	 * Make the dialog created, i.e., layout is properly decided
	 *
	 * @return self
	 * \else
	 * 创建对话框, 也就是让对话框的界面布局最终定型
	 *
	 * @return 对话框自身
	 * \endif
	 */
	wyDialog* create();

	/**
	 * \if English
	 * Show dialog in scene
	 *
	 * @param withAnimation true means performing animation when showing dialog, but this flag is
	 * 		useless if no \link wyDialogTransition wyDialogTransition\endlink is specified. By default
	 * 		it is true
	 * @return self
	 * \else
	 * 显示对话框
	 *
	 * @param withAnimation true表示显示对话框的时候带有动画效果, 当然如果对话框本身并未设置
	 * 		\link wyDialogTransition wyDialogTransition\endlink则该标志无意义. 缺省是true
	 * @return 对话框自身
	 * \endif
	 */
	wyDialog* show(bool withAnimation = true);

	/**
	 * \if English
	 * Dismiss dialog
	 *
	 * @param withAnimation true means performing animation when dismissing dialog, but this flag is
	 * 		useless if no \link wyDialogTransition wyDialogTransition\endlink is specified. By default
	 * 		it is true
	 * \else
	 * 关闭对话框
	 *
	 * @param withAnimation true表示关闭对话框的时候带有动画效果, 当然如果对话框本身并未设置
	 * 		\link wyDialogTransition wyDialogTransition\endlink则该标志无意义. 缺省是true
	 * \endif
	 */
	void dismiss(bool withAnimation = true);

	/**
	 * \if English
	 * Set background of dialog
	 *
	 * \note
	 * If you don't set a background, then WiEngine will use a default background image, mainly white
	 *
	 * @param bg background of dialog, usually it is a \link wyNinePatchSprite wyNinePatchSprite\endlink object,
	 * 		or \link wySprite wySprite\endlink, or \link wySpriteEx wySpriteEx\endlink. You can use other node if
	 * 		you are sure it will be ok.
	 * @return self
	 * \else
	 * 设置对话框背景
	 *
	 * \note
	 * 如果你不设置对话框背景, 则WiEngine会使用一张缺省的背景作为对话框背景, 缺省的背景以
	 * 白色为主
	 *
	 * @param bg 对话框背景, 通常这可以是一个\link wyNinePatchSprite wyNinePatchSprite\endlink, 或者\link wySprite wySprite\endlink,
	 * 		或者\link wySpriteEx wySpriteEx\endlink. 你也可以使用其它节点只要你确定这么做没问题.
	 * @return 对话框自身
	 * \endif
	 */
	wyDialog* setBackground(wyNode* bg);

	/**
	 * \if English
	 * Get background node, background node is container of other nodes
	 *
	 * @return background node
	 * \else
	 * 得到对话框的背景节点, 背景节点是对话框节点的容器节点
	 *
	 * @return 背景节点
	 * \endif
	 */
	wyNode* getBackground() { return m_bg; }

	/**
	 * \if English
	 * Set padding of background node. The size of background node is determined
	 * by content size and padding
	 *
	 * @param left left padding, in pixels
	 * @param top top padding in pixels
	 * @param right right padding in pixels
	 * @param bottom bottom padding in pixels
	 * @return self
	 * \else
	 * 设置背景节点的边缘填充距离, 背景节点的大小最终会等于内容大小加上填充距离
	 *
	 * @param left 左边填充大小, 单位像素
	 * @param top 顶部填充大小, 单位像素
	 * @param right 右边填充大小, 单位像素
	 * @param bottom 底部填充大小, 单位像素
	 * @return 对话框自身
	 * \endif
	 */
	wyDialog* setBackgroundPadding(float left, float top, float right, float bottom);

	/**
	 * \if English
	 * Set title
	 *
	 * @param title title node, it may be \link wyLabel wyLabel\endlink, \link wyAtlasLabel wyAtlasLabel\endlink
	 * 		or \link wyBitmapFontLabel wyBitmapFontLabel\endlink. But you can use other node if you like.
	 * @return self
	 * \else
	 * 设置对话框标题
	 *
	 * @param title 标题节点, 其一般是\link wyLabel wyLabel\endlink, \link wyAtlasLabel wyAtlasLabel\endlink或者
	 * 		\link wyBitmapFontLabel wyBitmapFontLabel\endlink. 当然你也可以使用其它节点, 只要你喜欢.
	 * @return 对话框自身
	 * \endif
	 */
	wyDialog* setTitle(wyNode* title);

	/**
	 * \if English
	 * Set message node
	 *
	 * @param content content
	 * @return self
	 * \else
	 * 设置对话框标题
	 *
	 * @param content 内容节点
	 * @return 对话框自身
	 * \endif
	 */
	wyDialog* setContent(wyNode* content);

	/**
	 * \if English
	 * Add a button to dialog
	 *
	 * @param button button node
	 * @param label label node or NULL if \c button node already has label in it
	 * @param sel target selector to be triggered for this button or NULL if just close dialog
	 * @return self
	 * \else
	 * 给对话框添加一个按钮
	 *
	 * @param button 按钮节点
	 * @param label 按钮上的字符串节点, 如果\c button已经包含了文字内容, 则这个可以为NULL
	 * @param sel 按钮触发的方法, 如果为NULL, 则这个按钮只是关掉对话框
	 * @return 对话框自身
	 * \endif
	 */
	wyDialog* addButton(wyNode* button, wyNode* label, wyTargetSelector* sel);

	/**
	 * \if English
	 * Add two buttons which is managed in two columns layout
	 *
	 * @param button1 button node
	 * @param label1 label node for \c button1
	 * @param sel1 target selector for \c button1. If NULL, this button only close dialog
	 * @param button2 second column button node
	 * @param label2 label node for \c button2
	 * @param sel2 target selector for \c button2. If NULL, this button only close dialog
	 * \else
	 * 添加两个按钮, 按照两列的方式布局
	 *
	 * @param button1 第一列上的按钮节点
	 * @param label1 第一个按钮的标签节点
	 * @param sel1 第一个按钮的选择子, 如果是NULL, 则按钮只是关闭对话框
	 * @param button2 第二列上的按钮节点
	 * @param label2 第二列按钮上的标签节点
	 * @param sel2 第二列按钮的选择子, 如果是NULL, 则按钮只是关闭对话框
	 * \endif
	 */
	wyDialog* addTwoColumnsButton(wyNode* button1, wyNode* label1, wyTargetSelector* sel1, wyNode* button2, wyNode* label2, wyTargetSelector* sel2);

	/**
	 * \if English
	 * Set dialog transition which apply to dialog when showing or closing
	 *
	 * @param t \link wyDialogTransition wyDialogTransition\endlink
	 * @return self
	 * \else
	 * 设置对话框显示或关闭时的效果
	 *
	 * @param t \link wyDialogTransition wyDialogTransition\endlink
	 * @return 对话框自身
	 * \endif
	 */
	wyDialog* setTransition(wyDialogTransition* t);

	/**
	 * \if English
	 * Set which button should be checked when back key is pressed. It is useless for device which
	 * doesn't have back key. The default index is zero so it is not related with any button by default.
	 *
	 * @param index index of button, if it is invalid, back key just close dialog without any action
	 * @return self
	 * \else
	 * 设置按下back键时, 相当于哪个按钮被点击. 这只对存在back键的设备有效, 比如android. 缺省的值是-1, 也就是不对应
	 * 任何按钮.
	 *
	 * @param index 按钮的索引, 从0开始. 按照调用addButton的顺序决定. 如果这个索引非法, 则back键仅仅就是关闭对话框
	 * @return 对话框本身
	 * \endif
	 */
	wyDialog* setBackKeyEquivalentButtonIndex(int index);
};

#endif // __wyDialog_h__
