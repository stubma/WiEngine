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
#ifndef __wyViewport_h__
#define __wyViewport_h__

#include "wyCamera.h"
#include "wyNode.h"
#include "wyRenderQueue.h"

/**
 * @class wyViewport
 *
 * \if English
 * \c wyViewport is start point of a render branch and it must be bound with a
 * \link wyNode wyNode\endlink. The node it bound is called root of view port.
 * There can be multiple \c wyViewport so rendering can be grouped easily.
 * \else
 * \c wyViewport是代表了一个渲染分支, 它负责渲染某个节点开始的树结构. \c wyViewport可以
 * 有多个, 每个都对应一个特定的节点, \c wyViewport对应的节点称为\c wyViewport的根节点, 它
 * 是\c wyViewport渲染的起始点.
 * \endif
 */
class WIENGINE_API wyViewport : public wyObject {
private:
	/// render queue
	wyRenderQueue* m_queue;

	/// main camera of this viewport
	wyCamera* m_camera;

	/// viewport name
	const char* m_name;

	/// root node
	wyNode* m_root;

	/// true indicating color should be cleared before render
	bool m_clearColor;

	/// true indicating depth should be cleared before render
	bool m_clearDepth;

	/// true indicating stencil should be cleared before render
	bool m_clearStencil;

	/// background color when clearing color
	wyColor4B m_color;

	/// true means this viewport is enabled
	bool m_enabled;

protected:
	/**
	 * Constructor
	 *
	 * @param name name of viewport
	 * @param camera main camera of this viewport
	 */
	wyViewport(const char* name, wyCamera* camera);

public:
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param camera main camera of this viewport
	 * @return \link wyViewport wyViewport\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param camera 视口的主摄像机
	 * @return \link wyViewport wyViewport\endlink
	 * \endif
	 */
	static wyViewport* make(wyCamera* camera);

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param name name of viewport
	 * @param camera main camera of this viewport
	 * @return \link wyViewport wyViewport\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param name 视图的名字
	 * @param camera 视口的主摄像机
	 * @return \link wyViewport wyViewport\endlink
	 * \endif
	 */
	static wyViewport* make(const char* name, wyCamera* camera);

	virtual ~wyViewport();

	/**
	 * \if English
	 * Get main camera of this viewport
	 *
	 * @return \link wyCamera wyCamera\endlink
	 * \else
	 * 得到视图的主摄像机
	 *
	 * @return \link wyCamera wyCamera\endlink
	 * \endif
	 */
	wyCamera* getCamera() { return m_camera; }

	/**
	 * \if English
	 * Get name of viewport
	 *
	 * @return name of viewport, caller should not release it
	 * \else
	 * 得到视口的名称
	 *
	 * @return 视口名称, 调用者不需要释放
	 * \endif
	 */
	const char* getName() { return m_name; }

	/**
	 * \if English
	 * Attach a root node to this viewport
	 *
	 * @param root root node of this viewport, it is the rendering start point
	 * \else
	 * 往当前视口追加根节点
	 *
	 * @param root 该视口的根节点
	 * \endif
	 */
	void attachRoot(wyNode* root);

	/**
	 * \if English
	 * Get root node of this viewport
	 *
	 * @return root node
	 * \else
	 * 得到视口的根节点
	 *
	 * @return 根节点
	 * \endif
	 */
	wyNode* getRoot() { return m_root; }

	/**
	 * \if English
	 * Set clear flag
	 *
	 * @param clearColor true means color should be cleared before rendering
	 * @param clearDepth true means depth should be cleared before rendering
	 * @param clearStencil true means stencil should be cleared before rendering
	 * \else
	 * 设置清除标志
	 *
	 * @param clearColor true表示渲染之前颜色缓冲需要被清空
	 * @param clearDepth true表示渲染之前深度缓冲需要被清空
	 * @param clearStencil true表示渲染之前模版缓冲需要被清空
	 * \endif
	 */
	void setClearFlag(bool clearColor, bool clearDepth, bool clearStencil);

	/**
	 * \if English
	 * Should clear color buffer?
	 *
	 * @return true means need clear color buffer
	 * \else
	 * 是否需要清空颜色缓冲区
	 *
	 * @return true表示需要清空颜色缓冲区
	 * \endif
	 */
	bool shouldClearColor() { return m_clearColor; }

	/**
	 * \if English
	 * Should clear depth buffer?
	 *
	 * @return true means need clear depth buffer
	 * \else
	 * 是否需要清空深度缓冲区
	 *
	 * @return true表示需要清空深度缓冲区
	 * \endif
	 */
	bool shouldClearDepth() { return m_clearDepth; }

	/**
	 * \if English
	 * Should clear stencil buffer?
	 *
	 * @return true means need clear stencil buffer
	 * \else
	 * 是否需要清空模版缓冲区
	 *
	 * @return true表示需要清空模版缓冲区
	 * \endif
	 */
	bool shouldClearStencil() { return m_clearStencil; }

	/**
	 * \if English
	 * Set background color of this viewport
	 *
	 * @param color background color
	 * \else
	 * 设置视口的背景色
	 *
	 * @param color 背景色
	 * \endif
	 */
	void setBackgroundColor(wyColor4B color);

	/**
	 * \if English
	 * Get background color of this viewport
	 *
	 * @return background color
	 * \else
	 * 得到视口的背景色
	 *
	 * @return 背景色
	 * \endif
	 */
	wyColor4B getBackgroundColor() { return m_color; }

	/**
	 * \if English
	 * Get render queue
	 *
	 * @return \link wyRenderQueue wyRenderQueue\endlink
	 * \else
	 * 得到渲染队列
	 *
	 * @return \link wyRenderQueue wyRenderQueue\endlink
	 * \endif
	 */
	wyRenderQueue* getQueue() { return m_queue; }

	/**
	 * \if English
	 * Is viewport enabled. A disabled viewport won't be rendered
	 * \else
	 * 视口是否使能, 被禁止的视口不会被渲染
	 * \endif
	 */
	bool isEnabled() { return m_enabled; }

	/**
	 * \if English
	 * Set viewport enabled or not. A disabled viewport won't be rendered
	 * \else
	 * 禁止或使能视口. 被禁止的视口不会被渲染
	 * \endif
	 */
	void setEnabled(bool flag) { m_enabled = flag; }
};

#endif // __wyViewport_h__
