/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyMenuItemAtlasLabel_h__
#define __wyMenuItemAtlasLabel_h__

#include "wyMenuItem.h"
#include "wyAtlasLabel.h"

/**
 * @class wyMenuItemAtlasLabel
 * \if English
 * a type of menu item which uses \link wyAtlasLabel wyAtlasLabel\endlink to construct its contents
 * \else
 * 图片集标签菜单项的封装
 * \endif
 */
class WIENGINE_API wyMenuItemAtlasLabel : public wyMenuItem {
protected:
	/**
	 * \if English
	 * \link wyAtlasLabel wyAtlasLabel\endlink
	 * \else
	 * 图片集标签\link wyAtlasLabel wyAtlasLabel对象指针\endlink
	 * \endif
	 */
	wyAtlasLabel* m_label;

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
	 * color of the disabled color, \link wyColor4B wyColor4B\endlink
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
	 * @param downSelector callback when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector callback when the item is clicked up
	 * @param label \link wyAtlasLabel wyAtlasLabel object\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param downSelector 按下菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param upSelector 松开菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param label 图片集标签\link wyAtlasLabel wyAtlasLabel对象指针\endlink
	 * \endif
	 */
	static wyMenuItemAtlasLabel* make(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wyAtlasLabel* label);

	/**
	 * \if English
	 * constructor
	 *
	 * @param downSelector callback when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector callback when the item is clicked up
	 * @param label \link wyAtlasLabel wyAtlasLabel object\endlink
	 * \else
	 * 构造函数
	 *
	 * @param downSelector 按下菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param upSelector 松开菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param label 图片集标签\link wyAtlasLabel wyAtlasLabel对象指针\endlink
	 * \endif
	 */
	wyMenuItemAtlasLabel(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wyAtlasLabel* label);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyMenuItemAtlasLabel();

	/// @see wyNode::draw
	virtual void draw();

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

	/**
	 * \if English
	 * set the atlas label
	 * \else
	 * 设置图片集标签\link wyAtlasLabel wyAtlasLabel对象指针\endlink
	 *
	 * @param label 图片集标签\link wyAtlasLabel wyAtlasLabel对象指针\endlink
	 * \endif
	 */
	void setLabel(wyAtlasLabel* label);
};

#endif // __wyMenuItemAtlasLabel_h__
