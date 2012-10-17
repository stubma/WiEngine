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
 * @class wyMenuItemLabel
 * \if English
 * a type of menu item which uses label to construct its content
 * \else
 * 标签菜单项的封装
 * \endif
 */
class WIENGINE_API wyMenuItemLabel : public wyMenuItem {
protected:
	/**
	 * \if English
	 * \link wyLabel wyLabel\endlink
	 * \else
	 * 标签\link wyLabel wyLabel对象指针\endlink
	 * \endif
	 */
	wyLabel* m_label;

	/**
	 * \if English
	 * color of the normal state, \link wyColor4B wyColor4B\endlink
	 * \else
	 * 正常状态的颜色\link wyColor4B wyColor4B结构\endlink
	 * \endif
	 */
	wyColor4B m_normalColor;

	/**
	 * \if English
	 * color of the disabled state, \link wyColor4B wyColor4B\endlink
	 * \else
	 * 禁用状态的颜色\link wyColor4B wyColor4B结构\endlink
	 * \endif
	 */
	wyColor4B m_disabledColor;

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up
	 * @param label \link wyLabel wyLabel object\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param downSelector 按下菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param upSelector 松开菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param label 标签\link wyLabel wyLabel对象指针\endlink
	 * \endif
	 */
	static wyMenuItemLabel* make(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wyLabel* label);

	/**
	 * \if English
	 * constructor
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up
	 * @param label \link wyLabel wyLabel object\endlink
	 * \else
	 * 构造函数
	 *
	 * @param downSelector 按下菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param upSelector 松开菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param label 标签\link wyLabel wyLabel对象指针\endlink
	 * \endif
	 */
	wyMenuItemLabel(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wyLabel* label);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
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

	/// @see wyNode::getText
	virtual const char* getText() { return m_label ? m_label->getText() : NULL; }

	/**
	 * \if English
	 * set the \link wyLabel wyLabel object\endlink
	 * \else
	 * 设置标签\link wyLabel wyLabel对象指针\endlink
	 *
	 * @param label 标签\link wyLabel wyLabel对象指针\endlink
	 * \endif
	 */
	void setLabel(wyLabel* label);

	/**
	 * \if English
	 * Get label node
	 * \else
	 * 得到关联的label节点
	 * \endif
	 */
	wyLabel* getLabel() { return m_label; }

	/**
	 * \if English
	 * set the displayed string
	 *
	 * @param text C string
	 * \else
	 * 设置标签显示的字符串
	 *
	 * @param text 标签显示的字符串
	 * \endif
	 */
	void setString(const char* text);

	/**
	 * \if English
	 * set the color of disabled state
	 * \else
	 * 设置禁用时的颜色\link wyColor3B wyColor3B结构\endlink
	 *
	 * @param color 禁用时的颜色\link wyColor3B wyColor3B结构\endlink
	 * \endif
	 */
	void setDisabledColor(wyColor3B color);

	/**
	 * \if English
	 * get the color of disabled state
	 * \else
	 * 得到禁用时的颜色\link wyColor3B wyColor3B结构\endlink
	 *
	 * @return 禁用时的颜色\link wyColor3B wyColor3B结构\endlink
	 * \endif
	 */
	wyColor3B getDisabledColor();
};

#endif // __wyMenuItemLabel_h__
