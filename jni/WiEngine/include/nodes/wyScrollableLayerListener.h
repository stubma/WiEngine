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
#ifndef __wyScrollableLayerListener_h__
#define __wyScrollableLayerListener_h__

class wyScrollableLayer;
class wyNode;

/**
 * @class wyScrollableLayerListener
 *
 * \if English
 * Scrollablelayer event interface
 * \else
 * 滚动层回调定义
 * \endif
 */
class wyScrollableLayerListener {
public:
	/**
	 * \if English
	 * Invoked when scrollable content offset is changed. You can query current offset
	 * by \c getOffsetX and \c getOffsetY
	 *
	 * @param layer \link wyScrollableLayer wyScrollableLayer\endlink
	 * \else
	 * 当滚动层的偏移位置发生变化时被调用, 可以通过getOffsetX, getOffsetY方法获得当前的位置.
	 *
	 * @param layer \link wyScrollableLayer wyScrollableLayer\endlink
	 * \endif
	 */
	virtual void onScrollOffsetChanged(wyScrollableLayer* layer) {}

	/**
	 * \if English
	 * Invoked when user releases his finger and scrollable layer is about to fling
	 *
	 * @param layer \link wyScrollableLayer wyScrollableLayer\endlink
	 * \else
	 * 当正要开始抛掷时被调用, 在抛掷结束前, onScrollOffsetChanged会被持续触发. 但是
	 * 要注意onScrollOffsetChanged在没有抛掷时也会发生, 只要偏移改变就会发生
	 *
	 * @param layer \link wyScrollableLayer wyScrollableLayer\endlink
	 * \endif
	 */
	virtual void onStartFling(wyScrollableLayer* layer) {}

	/**
	 * \if English
	 * Invoked when fling is ended
	 *
	 * @param layer \link wyScrollableLayer wyScrollableLayer\endlink
	 * \else
	 * 当抛掷结束时被调用
	 *
	 * @param layer \link wyScrollableLayer wyScrollableLayer\endlink
	 * \endif
	 */
	virtual void onEndFling(wyScrollableLayer* layer) {}

	/**
	 * \if English
	 * Invoked for every scrollable child when it is outside of scrollable layer area.
	 * You can do some resource releasing in this method, and it is critical if your
	 * have many many textures in scrollablelayer.
	 *
	 * @param layer \link wyScrollableLayer wyScrollableLayer\endlink
	 * @param child child node which is outside scrollable layer area
	 * \else
	 * 当一个可滚动节点离开了可见滚动区域时被调用, 在这个方法里可以做一些资源释放工作. 如果一个可
	 * 滚动层里非常多的贴图, 则及时的释放那些不可见的贴图是很重要的.
	 *
	 * @param layer \link wyScrollableLayer wyScrollableLayer\endlink
	 * @param child 离开了可见滚动区域的节点
	 * \endif
	 */
	virtual void onScrollableChildNotVisible(wyScrollableLayer* layer, wyNode* child) {}
};

#endif // __wyScrollableLayerListener_h__
