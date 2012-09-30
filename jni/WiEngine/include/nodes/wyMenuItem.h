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
#ifndef __wyMenuItem_h__
#define __wyMenuItem_h__

#include "wyNode.h"
#include "wyTargetSelector.h"

/**
 * \if English
 * the default font size, in SP
 * \else
 * 缺省菜单字体大小，单位是SP
 * \endif
 */
#define DEFAULT_FONT_SIZE 32

/**
 * \if English
 * tag of the current selected item
 * \else
 * 用于表示当前菜单的tag
 * \endif
 */
#define TAG_CURRENT_ITEM 0xc0c05001

/**
 * \if English
 * tag of the zoom action when the item is clicked
 * \else
 * 用来表示缩放动作的tag，菜单点击时是有一个放大的效果的。
 * \endif
 */
#define TAG_ZOOM_ACTION 0xc0c05002

/**
 * @class wyMenuItem
 * \if English
 * Menu item. Different from a normal node, nodes of this type will
 * not be added as a child.
 * \else
 * 菜单项的封装, 是所有菜单项的基类. 菜单项虽然是\link wyNode wyNode\endlink
 * 的子类, 但是却不会被添加到节点树中, 而是由\link wyMenu wyMenu\endlink 进行
 * 托管, 因此\link wyNode wyNode\endlink 中的一些生命周期方法是不会被调用的.
 * \endif
 */
class WIENGINE_API wyMenuItem : public wyNode {
protected:
	/**
	 * \if English
	 * the scale rate when the item is clicked
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

protected:
	/// check click scale, if set, do scaling
	void checkClickScale(bool selected);

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up, \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param downSelector 按下菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param upSelector 松开菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * \endif
	 */
	static wyMenuItem* make(wyTargetSelector* downSelector, wyTargetSelector* upSelector);

	/**
	 * \if English
	 * constructor
	 *
	 * @param downSelector called back when the item is clicked down, \link wyTargetSelector wyTargetSelector\endlink
	 * @param upSelector called back when the item is clicked up, \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 构造函数
	 *
	 * @param downSelector 按下菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * @param upSelector 松开菜单项的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * \endif
	 */
	wyMenuItem(wyTargetSelector* downSelector, wyTargetSelector* upSelector);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyMenuItem();

	/// @see wyNode::setSelected
	virtual void setSelected(bool selected);

	/**
	 * \if English
	 * called before click down, up or move event is handled
	 *
	 * @param ts callback \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 当鼠标按下，移动，松开之前的回调
	 *
	 * @param ts 回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * \endif
	 */
	virtual void beforeInvoke(wyTargetSelector* ts);

	/**
	 * \if English
	 * set the scale rate, default value is 1.4f
	 * \else
	 * 设置被点击时候的缩放比, 缺省的缩放比是1.4f
	 * \endif
	 */
	void setClickScale(float scale) { m_clickScale = scale; }

	/**
	 * \if English
	 * get the scale rate, default value is 1.4f
	 * \else
	 * 得到被点击时候的缩放比, 缺省的缩放比是1.4f
	 * \endif
	 */
	float getClickScale() { return m_clickScale; }
};

#endif // __wyMenuItem_h__
