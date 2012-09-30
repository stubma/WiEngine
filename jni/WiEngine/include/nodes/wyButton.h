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
#ifndef __wyButton_h__
#define __wyButton_h__

#include "wyNode.h"

/**
 * @class wyButton
 * \if English
 * Button class. Each button has 6 states, which are normal, selected, disabled, focused.
 * \else
 * 按钮的封装. 一个按钮有四个状态: 普通, 选中，焦点，禁止. 普通状态是必须要指定的, 其它
 * 几个状态可以没有. 这四个状态分别由四个\link wyNode wyNode\endlink 节点对象代表,
 * 因此按钮可以很灵活的由各种节点组成. 状态节点和按钮之间没有父子关系, 但是不影响
 * 状态节点接收事件, 因为按钮在onEnter和onExit发生时也会调用它们的相应方法.
 * \endif
 */
class WIENGINE_API wyButton : public wyNode {
protected:
	/**
	 * \if English
	 * normal state
	 * \else
	 * 正常状态的\link wyNode wyNode对象指针 \endlink
	 * \endif
	 */
	wyNode* m_normalState;

	/**
	 * \if English
	 * selected state
	 * \else
	 * 被选中状态的\link wyNode wyNode对象指针 \endlink
	 * \endif
	 */
	wyNode* m_selectedState;

	/**
	 * \if English
	 * disabled state
	 * \else
	 * 禁用状态的\link wyNode wyNode对象指针 \endlink
	 * \endif
	 */
	wyNode* m_disabledState;

	/**
	 * \if English
	 * focused state
	 * \else
	 * 获得焦点状态的\link wyNode wyNode对象指针 \endlink
	 * \endif
	 */
	wyNode* m_focusedState;

	/**
	 * \if English
	 * specify how much the button will be scaled while being clicked
	 * \else
	 * 当被点击时候的缩放比
	 * \endif
	 */
	float m_clickScale;

	/**
	 * \if English
	 * Save original scale before perform clicking scale effect
	 * \else
	 * 用来保存原来的缩放值以便点击结束时恢复
	 * \endif
	 */
	float m_originalScale;

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled.
	 *
	 * @param normal \link wyNode wyNode\endlink, can't be NULL
	 * @param selected can be NULL
	 * @param disabled can be NULL
	 * @param focused can be NULL
	 * @param downSelector \link wyTargetSelector wyTargetSelector\endlink triggered when clicked down, can be NULL
	 * @param upSelector \link wyTargetSelector wyTargetSelector\endlink triggered when clicked up, can be NULL
	 * \else
	 * 静态构造函数
	 *
	 * @param normal 正常状态的\link wyNode wyNode对象指针 \endlink
	 * @param selected 被选中状态的\link wyNode wyNode对象指针 \endlink
	 * @param disabled 禁用状态的\link wyNode wyNode对象指针 \endlink
	 * @param focused  获得焦点状态的\link wyNode wyNode对象指针 \endlink
	 * @param downSelector 按下按钮的\link wyTargetSelector wyTargetSelector对象指针 \endlink
	 * @param upSelector 松开按钮的\link wyTargetSelector wyTargetSelector对象指针 \endlink
	 * \endif
	 */
	static wyButton* make(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyTargetSelector* downSelector, wyTargetSelector* upSelector);

	/**
	 * \if English
	 * constructor
	 * @param normal \link wyNode wyNode\endlink, can't be NULL
	 * @param selected can be NULL
	 * @param disabled can be NULL
	 * @param focused can be NULL
	 * @param downSelector \link wyTargetSelector wyTargetSelector\endlink triggered when clicked down, can be NULL
	 * @param upSelector \link wyTargetSelector wyTargetSelector\endlink triggered when clicked up, can be NULL
	 * \else
	 * 构造函数
	 *
	 * @param normal 正常状态的\link wyNode wyNode对象指针 \endlink
	 * @param selected 被选中状态的\link wyNode wyNode对象指针 \endlink
	 * @param disabled 禁用状态的\link wyNode wyNode对象指针 \endlink
	 * @param focused  获得焦点状态的\link wyNode wyNode对象指针 \endlink
	 * @param downSelector 按下按钮的\link wyTargetSelector wyTargetSelector对象指针 \endlink
	 * @param upSelector 松开按钮的\link wyTargetSelector wyTargetSelector对象指针 \endlink
	 * \endif
	 */
	wyButton(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyTargetSelector* downSelector, wyTargetSelector* upSelector);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyButton();

	/// @see wyNode::draw
	virtual void draw();

	/// @see wyNode::onEnter
	virtual void onEnter();

	/// @see wyNode::onExit
	virtual void onExit();

	/// @see wyNode::setRotation
	virtual void setRotation(float rot);

	/// @see wyNode::setScale
	virtual void setScale(float scale);

	/// @see wyNode::setScaleX
	virtual void setScaleX(float scaleX);

	/// @see wyNode::setScaleY
	virtual void setScaleY(float scaleY);

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

	/// @see wyNode::setSelected
	virtual void setSelected(bool selected);

	/**
	 * \if English
	 * setter, to set the normal state node
	 *
	 * @param \link wyNode wyNode\endlink, can't be NULL
	 * \else
	 * 设置正常状态的\link wyNode wyNode对象指针\endlink
	 *
	 * @param normal 正常状态的\link wyNode wyNode对象指针\endlink
	 * \endif
	 */
	void setNormalState(wyNode* normal);

	/**
	 * \if English
	 * setter, to set the selected state
	 *
	 * @param selected \link wyNode wyNode\endlink
	 * \else
	 * 设置选中状态的\link wyNode wyNode对象指针\endlink
	 *
	 * @param selected 选中状态的\link wyNode wyNode对象指针\endlink
	 * \endif
	 */
	void setSelectedState(wyNode* selected);

	/**
	 * \if English
	 * setter, to set the disabled state
	 *
	 * @param disabled \link wyNode wyNode\endlink
	 * \else
	 * 设置禁用状态的\link wyNode wyNode对象指针\endlink
	 *
	 * @param disabled 禁用状态的\link wyNode wyNode对象指针\endlink
	 * \endif
	 */
	void setDisabledState(wyNode* disabled);

	/**
	 * \if English
	 * setter, to set the focused state
	 *
	 * @param focused \link wyNode wyNode\endlink
	 * \else
	 * 设置获得焦点状态的\link wyNode wyNode对象指针\endlink
	 *
	 * @param focused 获得焦点状态的\link wyNode wyNode对象指针\endlink
	 * \endif
	 */
	void setFocusedState(wyNode* focused);

	/**
	 * \if English
	 * to set the corresponding state's texture through one single call
	 *
	 * @param normal \link wyTexture2D wyTexture2D\endlink, the normal state won't change if this value is NULL
	 * @param selected \link wyTexture2D wyTexture2D\endlink, the selected state won't change if this value is NULL
	 * @param disabled \link wyTexture2D wyTexture2D\endlink, the disabled state won't change if this value is NULL
	 * @param focused \link wyTexture2D wyTexture2D\endlink, the focused state won't change if this value is NULL
	 * \else
	 * 改变按钮的图片, 方便于一次修改按钮的图片
	 *
	 * @param normal 正常状态的贴图, 为NULL则不更新贴图
	 * @param selected 按下状态的贴图, 为NULL则不更新贴图
	 * @param disabled 禁止状态的贴图, 为NULL则不更新贴图
	 * @param focused  获得焦点状态的贴图, 为NULL则不更新贴图
	 * \endif
	 */
	void setTexture(wyTexture2D* normal, wyTexture2D* selected, wyTexture2D* disabled, wyTexture2D* focused);

	/**
	 * \if English
	 * Set texture rect of button state node. But not all node has setTextureRect method so only
	 * \link wyTextureNode wyTextureNode\endlink and \link wySpriteEx wySpriteEx\endlink support this usage.
	 *
	 * @param normalRect texture rect of normal state, or NULL if you don't want to change it
	 * @param selectedRect texture rect of selected state, or NULL if you don't want to change it
	 * @param disabledRect texture rect of disabled state, or NULL if you don't want to change it
	 * @param focusedRect texture rect of focused state, or NULL if you don't want to change it
	 * \else
	 * 修改按钮节点的贴图矩形, 如果按钮的贴图来自于一个图片集, 则可以使用这个方法修改按钮贴图. 但是并不是所有的节点都有
	 * setTextureRect方法, 因此这个用法只对\link wyTextureNode wyTextureNode\endlink和\link wySpriteEx wySpriteEx\endlink
	 * 有效
	 *
	 * @param normalRect 正常态的贴图矩形, 或者为NULL表示你不想更新这个矩形
	 * @param selectedRect 选择态的贴图矩形, 或者为NULL表示你不想更新这个矩形
	 * @param disabledRect 禁止态的贴图矩形, 或者为NULL表示你不想更新这个矩形
	 * @param focusedRect 焦点态的贴图矩形, 或者为NULL表示你不想更新这个矩形
	 * \endif
	 */
	void setTextureRect(wyRect* normalRect, wyRect* selectedRect, wyRect* disabledRect, wyRect* focusedRect);

	/**
	 * \if English
	 * to specify how much the button will be scaled while being clicked
	 *
	 * @param scale <1.0f means scale down, >1.0f means scale up
	 * \else
	 * 设置被点击时候的缩放比
	 *
	 * @param scale 被点击时候的缩放比
	 * \endif
	 */
	void setClickScale(float scale) { m_clickScale = scale; }

	/**
	 * \if English
	 * getter
	 * \else
	 * 得到被点击时候的缩放比
	 *
	 * @return 被点击时候的缩放比
	 * \endif
	 */
	float getClickScale() { return m_clickScale; }
};

#endif // __wyButton_h__
