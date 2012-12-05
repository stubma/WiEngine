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
 * into WiEngine scene. By default wyCEGUINode is full-screen size. And you should NOT 
 * change its size and position. However, wyCEGUINode is only a bridge, to manipulate 
 * CEGUI interface, you must use CEGUI API. One thing you must remember: CEGUI's origin
 * is at top-left of screen, be careful with this stuff when using CEGUI API.
 *
 * \par
 * Althrough CEGUI System class is singleton, wyCEGUINode can be multi-instance. wyCEGUINode
 * must be bound with a CEGUI window, but CEGUI system is shared by all wyCEGUINode instances.
 * Before creating first wyCEGUINode instance, the \c bootstrapSystem method must be invoked.
 * You don't need to worry about destroying CEGUI system, wyCEGUINode handles it when last
 * wyCEGUINode instance destroyed.
 */
class CEGUIEXPORT wyCEGUINode : public wyNode {
protected:
	/// CEGUI window bound to this node
	Window* m_window;
    
private:
    /**
	 * Set CEGUI resource root directory, the root path should be a relative path
	 * in asset folder.
	 */
	static void setResourceRoot(const char* root);

    /**
	 * Initialize resource group directories, the resource root directory
	 * is specified by \c m_resRoot
	 */
	static void initializeResourceGroupDirectories();
    
	/**
	 * Sync resource group settings to CEGUI
	 */
	static void initializeDefaultResourceGroups();
    
protected:
	/**
	 * Constructor
	 *
	 * @param window CEGUI window object
	 */
	wyCEGUINode(Window* window);

public:
	virtual ~wyCEGUINode();

    /**
     * Create a bridge node for a CEGUI window
     *
     * @param window CEGUI window
     * @return \link wyCEGUINode wyCEGUINode\endlink
     */
	static wyCEGUINode* make(Window* window);
    
    /**
     * Setup CEGUI system, it must be called once before any
     * CEGUI api called
     *
     * @param root the CEGUI resource file root directory. It is optional and
     *      will be "cegui" if NULL
     */
    static void bootstrapSystem(const char* root = NULL);
    
    /// @see wyNode::beforeRender
    virtual void beforeRender();
    
    /// @see wyNode::afterRender
    virtual void afterRender();
    
    /// @see wyNode::touchesBegan
    virtual bool touchesBegan(wyMotionEvent& e);
    
    /// @see wyNode::touchesMoved
	virtual bool touchesMoved(wyMotionEvent& e);
    
	/// @see wyNode::touchesEnded
	virtual bool touchesEnded(wyMotionEvent& e);
    
	/// @see wyNode::touchesCancelled
	virtual bool touchesCancelled(wyMotionEvent& e);
    
    /// @see wyNode::keyDown
    virtual bool keyDown(wyKeyEvent& e);
  
    /// @see wyNode::keyUp
	virtual bool keyUp(wyKeyEvent& e);
 
    /// @see wyNode::keyMultiple
	virtual bool keyMultiple(wyKeyEvent& e);

	/// get bound window
	Window* getWindow() { return m_window; }
};

#endif // __wyCEGUINode_h__
