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
#ifndef __wyTextBox_h__
#define __wyTextBox_h__

#include "wyNode.h"

class wyTextBox;
class wyNegativeRunnable;
class wyPositiveRunnable;
class wyTextChangedRunnable;

/**
 * Definition of edit text event callback
 */
class WIENGINE_API wyTextBoxCallback {
public:
	/**
	 * Invoked when start editing, generally when input dialog is shown
	 *
	 * @param box related \link wyTextBox wyTextBox\endlink
	 */
	virtual void onTextBoxBeginEditing(wyTextBox* box) = 0;

	/**
	 * Invoked when text changed. All change will be canceled if user click negative button
	 *
	 * @param box related \link wyTextBox wyTextBox\endlink
	 * @param data extra data pointer
	 */
	virtual void onTextBoxTextChanged(wyTextBox* box) = 0;

	/**
	 * Invoked when end editing, no matter user clicks positive or negative button
	 *
	 * @param box related \link wyTextBox wyTextBox\endlink
	 */
	virtual void onTextBoxEndEditing(wyTextBox* box) = 0;
};

/**
 * @class wyTextBox
 *
 * 提供一个单行文本编辑框组件，wyTextBox是一个组合式节点，它是由4个状态节点和一个标签节点组合
 * 而成的。四个状态和\link wyButton wyButton\endlink一样，是普通，焦点，按下，禁止四态，
 * 只有普通态是必须提供的，其它的都可以为NULL。标签节点是用来显示用户输入的问题的，只要是
 * WiEngine支持的标签节点都可以，或者通泛一点说，只要是实现了\link wyNode wyNode\endlink
 * 中set/getText方法的子类都可以。标签节点显示的范围不会超过文本框状态图片的范围。<br/>
 *
 * 文本框节点的大小在创建后会自动根据状态图片的大小决定，当然您也可以手动设置大小，但是不建议这么
 * 做，因为自动计算出的大小是最佳大小。<br/>
 *
 * 文本框编辑的是采用弹框式，因为在手机上可能存在软键盘，当软键盘出现时，有可能会遮挡文本框
 * 节点，因此采用弹框式的设计更容易让用户输入。可以设置弹出框的标题和提示。<br/>
 *
 * 文本框缺省是打开了触摸事件处理的.
 */
class WIENGINE_API wyTextBox : public wyNode {
	friend class wyNegativeRunnable;
	friend class wyPositiveRunnable;
	friend class wyTextChangedRunnable;

protected:
	/// edit text callback
	wyTextBoxCallback* m_callback;

	/// temp variable to save old text
	const char* m_oldText;

	/// current text
	const char* m_text;

	/// title of input dialog
	const char* m_title;

	/// message of input dialog
	const char* m_message;

	/// text of positive button, in utf-8 encoding
	const char* m_positiveButton;

	/// text of negative button, in utf-8 encoding
	const char* m_negativeButton;

	/// 用于显示文本框文字的标签节点
	wyNode* m_label;

	/// 正常状态的\link wyNode wyNode对象指针 \endlink
	wyNode* m_normalState;

	/// 被选中状态的\link wyNode wyNode对象指针 \endlink
	wyNode* m_selectedState;

	/// 禁用状态的\link wyNode wyNode对象指针 \endlink
	wyNode* m_disabledState;

	/// 获得焦点状态的\link wyNode wyNode对象指针 \endlink
	wyNode* m_focusedState;

	/// padding between textbox left border and label left border
	float m_leftPadding;

	/// padding between textbox right border and label right border
	float m_rightPadding;

	/// padding between textbox top border and label top border
	float m_topPadding;

	/// padding between textbox bottom border and label bottom border
	float m_bottomPadding;

	/// true means text box is a password input
	bool m_password;

private:
	/**
	 * 更新标签节点的大小和位置
	 */
	void updateLabelSizeAndPosition();

protected:
	/**
	 * Constructor
	 *
	 * @param normal normal state node, can not be NULL
	 * @param selected selected state node, can be NULL
	 * @param disabled disabled state node, can be NULL
	 * @param focused focused state node, can be NULL
	 * @param label label node used to display text, can be any label node such as \link wyLabel wyLabel\endlink,
	 * 		\link wyAtlasLabel wyAtlasLabel\endlink, \link wyBitmapFontLabel wyBitmapFontLabel\endlink
	 */
	wyTextBox(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyNode* label);

	/*
	 * callback trigger
	 */

	virtual void notifyOnTextChanged();
	virtual void notifyOnBeginEditing();
	virtual void notifyOnEndEditing();

	/**
	 * \if English
	 * Show a dialog for input
	 * \else
	 * 显示一个输入对话框
	 * \endif
	 */
	virtual void showInputDialog() = 0;

	/// show dialog action
	void onShowDialog(wyTargetSelector* ts);

public:
	/**
	 * 静态构造函数
	 *
	 * @param normal 正常状态的\link wyNode wyNode对象指针 \endlink, 不能为NULL
	 * @param selected 被选中状态的\link wyNode wyNode对象指针 \endlink，可以为NULL
	 * @param disabled 禁用状态的\link wyNode wyNode对象指针 \endlink，可以为NULL
	 * @param focused  获得焦点状态的\link wyNode wyNode对象指针 \endlink，可以为NULL
	 * @param label 文字标签节点，只要是WiEngine中支持的标签节点都可以，比如\link wyLabel wyLabel\endlink,
	 * 		\link wyAtlasLabel wyAtlasLabel\endlink, \link wyBitmapFontLabel wyBitmapFontLabel\endlink等
	 */
	static wyTextBox* make(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyNode* label);

	virtual ~wyTextBox();

	/// @see wyNode::getText
	virtual const char* getText();

	/// @see wyNode::setText
	virtual void setText(const char* text);

	/// @see wyNode::beforeRender
	virtual void beforeRender();

	/// @see wyNode::getColor
	virtual wyColor3B getColor();

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::setColor
	virtual void setColor(wyColor4B color);

	/// @see wyNode::getAlpha
	virtual int getAlpha();

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha);

	/**
	 * Set callback
	 *
	 * @param callback \link wyTextBoxCallback wyTextBoxCallback\endlink structure. NULL means clear current callback.
	 */
	void setCallback(wyTextBoxCallback* callback) { m_callback = callback; }

	/**
	 * 设置弹出框的标题
	 *
	 * @param title 标题字符串, 这个字符串会被复制，因此方法返回后可以立刻释放
	 */
	void setTitle(const char* title);

	/**
	 * 获得弹出框的标题
	 *
	 * @return 弹出框的标题字符串, 调用者不需要负责释放
	 */
	const char* getTitle() { return m_title; }

	/**
	 * 设置弹出框的提示，这个提示不要超过3行，不然在iOS上会显示不下.
	 *
	 * @param msg 提示字符串, 这个字符串会被复制，因此方法返回后可以立刻释放
	 */
	void setMessage(const char* msg);

	/**
	 * 获得弹出框的提示
	 *
	 * @return 弹出框的提示字符串, 调用者不需要负责释放
	 */
	const char* getMessage() { return m_message; }

	/**
	 * 设置弹出框的确定按钮文字
	 *
	 * @param btn 确定按钮文字字符串, 这个字符串会被复制，因此方法返回后可以立刻释放
	 */
	void setPositiveButton(const char* btn);

	/**
	 * 获得弹出框的确定按钮文字
	 *
	 * @return 弹出框的确定按钮文字, 调用者不需要负责释放
	 */
	const char* getPositiveButton() { return m_positiveButton; }

	/**
	 * 设置弹出框的取消按钮文字
	 *
	 * @param btn 取消按钮文字字符串, 这个字符串会被复制，因此方法返回后可以立刻释放
	 */
	void setNegativeButton(const char* btn);

	/**
	 * 获得弹出框的取消按钮文字
	 *
	 * @return 弹出框的取消按钮文字, 调用者不需要负责释放
	 */
	const char* getNegativeButton() { return m_negativeButton; }

	/**
	 * 当确定按钮被按下时被调用，主要由内部调用
	 *
	 * @param text 新的字符串
	 */
	void onPositiveButtonClicked(const char* text);

	/**
	 * 当取消按钮被按下时被调用，主要由内部调用
	 */
	void onNegativeButtonClicked();

	/**
	 * 当文字输入改变时调用，主要由内部调用。由于采用的是弹框式输入方法，
	 * 所以实际上是在对话框中输入改变时会调用这个方法。
	 *
	 * @param newText 改变后的字符串
	 */
	void onTextChanged(const char* newText);

	/**
	 * 设置文本框矩形和标签节点之间的空隙. 默认都是0.
	 *
	 * @param left 左边间隔
	 * @param top 上边间隔
	 * @param right 右边间隔
	 * @param bottom 下边间隔
	 */
	void setPadding(float left, float top, float right, float bottom);

	/**
	 * \if English
	 * Set text box as password style
	 * \else
	 * 设置文本框为密码输入框
	 * \endif
	 */
	void setPassword(bool flag) { m_password = flag; }

	/**
	 * \if English
	 * Is text box a password input?
	 * \else
	 * 文本框是否是密码输入框
	 * \endif
	 */
	bool isPassword() { return m_password; }
};

#endif // __wyTextBox_h__
