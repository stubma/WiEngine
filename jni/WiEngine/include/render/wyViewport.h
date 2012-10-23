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

#include "wyObject.h"
#include "wyCamera.h"
#include "WiEngine-Classes.h"

/**
 * \c wyViewport is start point of a render branch and it must be bound with a
 * \link wyNode wyNode\endlink. The node it bound is called root of view port.
 * There can be multiple \c wyViewport so rendering can be grouped easily.
 *
 * Viewport can have second root node, this only occurs when switching scene.
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

	/// second root
	wyNode* m_secondRoot;

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
	 * Static constructor
	 *
	 * @param camera main camera of this viewport
	 * @return \link wyViewport wyViewport\endlink
	 */
	static wyViewport* make(wyCamera* camera);

	/**
	 * Static constructor
	 *
	 * @param name name of viewport
	 * @param camera main camera of this viewport
	 * @return \link wyViewport wyViewport\endlink
	 */
	static wyViewport* make(const char* name, wyCamera* camera);

	virtual ~wyViewport();

	/**
	 * Get main camera of this viewport
	 *
	 * @return \link wyCamera wyCamera\endlink
	 */
	wyCamera* getCamera() { return m_camera; }

	/**
	 * Get name of viewport
	 *
	 * @return name of viewport, caller should not release it
	 */
	const char* getName() { return m_name; }

	/**
	 * Attach a root node to this viewport
	 *
	 * @param root root node of this viewport, it is the rendering start point.
	 * 		This node can be any subclass of \link wyNode wyNode\endlink
	 */
	void attachRoot(wyNode* root);

	/**
	 * Attach a scene node to this viewport.
	 *
	 * @param s root node of this viewport, it must be a subclass of \link wyScene wyScene\endlink
	 */
	void attachScene(wyScene* s);

	/**
	 * Get root node of this viewport
	 */
	wyNode* getRoot() { return m_root; }

	/**
	 * Get second root node
	 */
	wyNode* getSecondRoot() { return m_secondRoot; }

	/**
	 * Set clear flag
	 *
	 * @param clearColor true means color should be cleared before rendering
	 * @param clearDepth true means depth should be cleared before rendering
	 * @param clearStencil true means stencil should be cleared before rendering
	 */
	void setClearFlag(bool clearColor, bool clearDepth, bool clearStencil);

	/**
	 * Should clear color buffer?
	 *
	 * @return true means need clear color buffer
	 */
	bool shouldClearColor() { return m_clearColor; }

	/**
	 * Should clear depth buffer?
	 *
	 * @return true means need clear depth buffer
	 */
	bool shouldClearDepth() { return m_clearDepth; }

	/**
	 * Should clear stencil buffer?
	 *
	 * @return true means need clear stencil buffer
	 */
	bool shouldClearStencil() { return m_clearStencil; }

	/**
	 * Set background color of this viewport
	 *
	 * @param color background color
	 */
	void setBackgroundColor(wyColor4B color);

	/**
	 * Get background color of this viewport
	 *
	 * @return background color
	 */
	wyColor4B getBackgroundColor() { return m_color; }

	/**
	 * Get render queue
	 *
	 * @return \link wyRenderQueue wyRenderQueue\endlink
	 */
	wyRenderQueue* getQueue() { return m_queue; }

	/**
	 * Is viewport enabled. A disabled viewport won't be rendered
	 */
	bool isEnabled() { return m_enabled; }

	/**
	 * Set viewport enabled or not. A disabled viewport won't be rendered
	 */
	void setEnabled(bool flag) { m_enabled = flag; }
};

#endif // __wyViewport_h__
