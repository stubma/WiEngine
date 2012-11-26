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
#ifndef __wyCEGUINode_h__
#define __wyCEGUINode_h__

#include "CEGUI.h"
#include "wyNode.h"

using namespace CEGUI;

/**
 * wyCEGUINode is a bridge between WiEngine and CEGUI so that CEGUI can be integrated
 * into WiEngine scene. However, wyCEGUINode is only a bridge, to manipulate CEGUI interface,
 * you must use CEGUI API.
 *
 * \par
 * Althrough CEGUI System class is singleton, wyCEGUINode can be multi-instance. wyCEGUINode
 * must be bound with a CEGUI window, but CEGUI system is shared by all wyCEGUINode instances.
 *
 * \par
 * By default wyCEGUINode is full-screen size.
 */
class CEGUIEXPORT wyCEGUINode : public wyNode {
protected:
	/// CEGUI window bound to this node
	Window* m_window;

protected:
	/**
	 * Constructor
	 *
	 * @param window CEGUI window object
	 */
	wyCEGUINode(Window* window);

	/**
	 * Initialize resource group directories, the resource root directory
	 * is specified by \c m_resRoot
	 */
	void initializeResourceGroupDirectories();

	/**
	 * Sync resource group settings to CEGUI
	 */
	void initializeDefaultResourceGroups();

public:
	virtual ~wyCEGUINode();

	static wyCEGUINode* make(Window* window);

	/**
	 * Set CEGUI resource root directory, the root path should be a relative path
	 * in asset folder.
	 *
	 * \note
	 * this method should be called before any wyCEGUINode instance created, and
	 * only need to be called once
	 */
	static void setResourceRoot(const char* root);
    
    /// @see wyNode::beforeRender
    virtual void beforeRender();
    
    /// @see wyNode::afterRender
    virtual void afterRender();

	/// get bound window
	Window* getWindow() { return m_window; }
};

#endif // __wyCEGUINode_h__
