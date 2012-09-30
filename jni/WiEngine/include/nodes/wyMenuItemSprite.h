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
#ifndef __wyMenuItemSprite_h__
#define __wyMenuItemSprite_h__

#include "wyMenuItem.h"
#include "wySprite.h"

/**
 * @class wyMenuItemSprite
 * \if English
 * a type of menu item which uses \link wySprite wySprite object\endlink as its content
 * \else
 * 图片对象菜单项的封装
 * \endif
 */
class WIENGINE_API wyMenuItemSprite : public wyMenuItem {
protected:
	/**
	 * \if English
	 * sprite of the normal state, \link wySprite wySprite\endlink
	 * \else
	 * 正常状态图片对象\link wySprite wySprite对象指针\endlink
	 * \endif
	 */
	wySprite* m_normalState;

	/**
	 * \if English
	 * sprite of the selected state
	 * \else
	 * 选中状态图片对象\link wySprite wySprite对象指针\endlink
	 * \endif
	 */
	wySprite* m_selectedState;

	/**
	 * \if English
	 * sprite of the disabled state
	 * \else
	 * 禁用状态图片对象\link wySprite wySprite对象指针\endlink
	 * \endif
	 */
	wySprite* m_disabledState;

protected:
	/**
	 * 调整大小，因为状态的变化会导致sprite变化，不同状态的sprite
	 * 可能有不同的大小
	 */
	void adjustContentSize();

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up
	 * @param normal sprite of the normal state, \link wySprite wySprite\endlink
	 * @param selected sprite of the selected state
	 * @param disabled sprite of the disabled state
	 * \else
	 * 静态构造函数
	 *
	 * @param downSelector 按下菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param upSelector 松开菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param normal 正常状态图片对象\link wySprite wySprite对象指针\endlink
	 * @param selected 选中状态图片对象\link wySprite wySprite对象指针\endlink
	 * @param disabled 禁用状态图片对象\link wySprite wySprite对象指针\endlink
	 * \endif
	 */
	static wyMenuItemSprite* make(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wySprite* normal, wySprite* selected, wySprite* disabled);

	/**
	 * \if English
	 * constructor
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up
	 * @param normal sprite of the normal state, \link wySprite wySprite\endlink
	 * @param selected sprite of the selected state
	 * @param disabled sprite of the disabled state
	 * \else
	 * 构造函数
	 *
	 * @param downSelector 按下菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param upSelector 松开菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param normal 正常状态图片对象\link wySprite wySprite对象指针\endlink
	 * @param selected 选中状态图片对象\link wySprite wySprite对象指针\endlink
	 * @param disabled 禁用状态图片对象\link wySprite wySprite对象指针\endlink
	 * \endif
	 */
	wyMenuItemSprite(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wySprite* normal, wySprite* selected, wySprite* disabled);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyMenuItemSprite();

	/// @see wyNode::draw
	virtual void draw();

	/// @see wyNode::draw
	virtual void setRotation(float rot);

	/// @see wyNode::setScale
	virtual void setScale(float scale);

	/// @see wyNode::setScaleX
	virtual void setScaleX(float scaleX);

	/// @see wyNode::setScaleY
	virtual void setScaleY(float scaleY);

	/// @see wyNode::getAlpha
	virtual int getAlpha() { return m_normalState->getAlpha(); }

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha);

	/// @see wyNode::getColor
	virtual wyColor3B getColor() { return m_normalState->getColor(); }

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::setColor
	virtual void setColor(wyColor4B color);

	/// @see wyNode::getBlendFunc
	virtual wyBlendFunc getBlendFunc() { return m_normalState->getBlendFunc(); }

	/// @see wyNode::setBlendFunc
	virtual void setBlendFunc(wyBlendFunc func);

	/// @see wyNode::setSelected
	virtual void setSelected(bool selected);

	/// @see wyNode::setEnabled
	virtual void setEnabled(bool enabled);

	/**
	 * \if English
	 * set sprite of the normal state
	 *
	 * @parm normal \link wySprite wySprite object\endlink
	 * \else
	 * 设置正常状态图片对象\link wySprite wySprite对象指针\endlink
	 *
	 * @param normal 正常状态图片对象\link wySprite wySprite对象指针\endlink
	 * \endif
	 */
	void setNormalSprite(wySprite* normal);

	/**
	 * \if English
	 * get sprite of the normal state
	 * \else
	 * 得到正常状态\link wySprite wySprite对象指针\endlink
	 *
	 * @return 正常状态\link wySprite wySprite对象指针\endlink
	 * \endif
	 */
	wySprite* getNormalSprite() { return m_normalState; }

	/**
	 * \if English
	 * set sprite of the selected state
	 *
	 * @param selected \link wySprite wySprite object\endlink
	 * \else
	 * 设置选中状态图片对象\link wySprite wySprite对象指针\endlink
	 *
	 * @param selected 选中状态图片对象\link wySprite wySprite对象指针\endlink
	 * \endif
	 */
	void setSelectedSprite(wySprite* selected);

	/**
	 * \if English
	 * get sprite of the selected state
	 * \else
	 * 得到选择状态\link wySprite wySprite对象指针\endlink
	 *
	 * @return 选择状态\link wySprite wySprite对象指针\endlink
	 * \endif
	 */
	wySprite* getSelectedSprite() { return m_selectedState; }

	/**
	 * \if English
	 * set sprite of the disabled state
	 *
	 * @param disabled \link wySprite wySprite object \endlink
	 * \else
	 * 设置禁用状态图片对象\link wySprite wySprite对象指针\endlink
	 *
	 * @param disabled 禁用状态图片对象\link wySprite wySprite对象指针\endlink
	 * \endif
	 */
	void setDisabledSprite(wySprite* disabled);

	/**
	 * \if English
	 * get sprite of the disabled state
	 * \else
	 * 得到禁止状态\link wySprite wySprite对象指针\endlink
	 *
	 * @return 禁止状态\link wySprite wySprite对象指针\endlink
	 * \endif
	 */
	wySprite* getDisabledSprite() { return m_disabledState; }
};

#endif // __wyMenuItemSprite_h__
