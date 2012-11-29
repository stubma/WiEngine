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
#include "wyCEGUINode.h"
#include "WiEngine.h"
#include "CEGUIWiEngineResourceProvider.h"
#include "CEGUIWiEngineRenderer.h"
#include "CEGUIWiEngineLogger.h"
#include <stdlib.h>

/// a reference count of how many wyCEGUINode exists
static int s_systemRefCount = 0;

/// CEGUI resource root directory, it should be a relative path in assets folder
static const char* s_resRoot = NULL;

wyCEGUINode::wyCEGUINode(Window* window) :
		m_window(window) {
	// increase ref count
	s_systemRefCount++;

	// default size and position
	setContentSize(wyDevice::winWidth, wyDevice::winHeight);
    setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
}

wyCEGUINode::~wyCEGUINode() {
	// decrease ref count, if it reaches zero, destroy system
	s_systemRefCount--;
	if(s_systemRefCount == 0) {
		System* sys = System::getSingletonPtr();
		if(sys) {
			WiEngineRenderer* r = (WiEngineRenderer*)sys->getRenderer();
			WiEngineResourceProvider* rp = (WiEngineResourceProvider*)sys->getResourceProvider();
			System::destroy();
			delete r;
			delete rp;
		}
        
        // delete logger
        delete Logger::getSingletonPtr();

		// release others
		if(s_resRoot) {
			wyFree((void*)s_resRoot);
			s_resRoot = NULL;
		}
	}
}

void wyCEGUINode::bootstrapSystem(const char* root) {
    // create system if not ready
	if(!System::getSingletonPtr()) {
        // create WiEngine logger so that default logger will not be used
        new WiEngineLogger();
        
        // set resource root
        setResourceRoot(root == NULL ? "cegui" : root);
        
        // create system
		WiEngineRenderer* r = new WiEngineRenderer();
		r->setDisplaySize(CEGUI::Size(wyDevice::winWidth, wyDevice::winHeight));
		WiEngineResourceProvider* rp = new WiEngineResourceProvider();
		System::create(*r, rp);
        
		// initialize resource groups
		initializeResourceGroupDirectories();
		initializeDefaultResourceGroups();
	}
}

wyCEGUINode* wyCEGUINode::make(Window* window) {
	wyCEGUINode* n = WYNEW wyCEGUINode(window);
	return (wyCEGUINode*)n->autoRelease();
}

void wyCEGUINode::setResourceRoot(const char* root) {
	if(s_resRoot) {
		wyFree((void*)s_resRoot);
		s_resRoot = NULL;
	}
	s_resRoot = wyUtils::copy(root);
}

void wyCEGUINode::initializeResourceGroupDirectories() {
    WiEngineResourceProvider* rp = (WiEngineResourceProvider*)System::getSingleton().getResourceProvider();
    char resourcePath[PATH_MAX];

    // for each resource type, set a resource group directory
    sprintf(resourcePath, "%s/%s", s_resRoot, "schemes/");
    rp->setResourceGroupDirectory("schemes", resourcePath);
    sprintf(resourcePath, "%s/%s", s_resRoot, "imagesets/");
    rp->setResourceGroupDirectory("imagesets", resourcePath);
    sprintf(resourcePath, "%s/%s", s_resRoot, "fonts/");
    rp->setResourceGroupDirectory("fonts", resourcePath);
    sprintf(resourcePath, "%s/%s", s_resRoot, "layouts/");
    rp->setResourceGroupDirectory("layouts", resourcePath);
    sprintf(resourcePath, "%s/%s", s_resRoot, "looknfeel/");
    rp->setResourceGroupDirectory("looknfeels", resourcePath);
    sprintf(resourcePath, "%s/%s", s_resRoot, "lua_scripts/");
    rp->setResourceGroupDirectory("lua_scripts", resourcePath);
    sprintf(resourcePath, "%s/%s", s_resRoot, "xml_schemas/");
    rp->setResourceGroupDirectory("schemas", resourcePath);
    sprintf(resourcePath, "%s/%s", s_resRoot, "animations/");
    rp->setResourceGroupDirectory("animations", resourcePath);
}

void wyCEGUINode::initializeDefaultResourceGroups() {
    // set the default resource groups to be used
    Imageset::setDefaultResourceGroup("imagesets");
    Font::setDefaultResourceGroup("fonts");
    Scheme::setDefaultResourceGroup("schemes");
    WidgetLookManager::setDefaultResourceGroup("looknfeels");
    WindowManager::setDefaultResourceGroup("layouts");
    ScriptModule::setDefaultResourceGroup("lua_scripts");
    AnimationManager::setDefaultResourceGroup("animations");

    // setup default group for validation schemas
    XMLParser* parser = System::getSingleton().getXMLParser();
    if (parser->isPropertyPresent("SchemaDefaultResourceGroup"))
        parser->setProperty("SchemaDefaultResourceGroup", "schemas");
}

void wyCEGUINode::beforeRender() {
    System* sys = System::getSingletonPtr();
    if(sys) {
        if(sys->getGUISheet() != m_window)
            sys->setGUISheet(m_window);
        sys->renderGUI();
    }
}

void wyCEGUINode::afterRender() {
    System* sys = System::getSingletonPtr();
    if(sys)
        sys->signalRedraw();
}

bool wyCEGUINode::touchesBegan(wyMotionEvent& e) {
    wyPoint loc = wyp(e.x[0], e.y[0]);
    loc = worldToNodeSpace(loc);
    System::getSingleton().injectMousePosition(loc.x, wyDevice::winHeight - loc.y);
    System::getSingleton().injectMouseButtonDown(LeftButton);
    
    return wyNode::touchesBegan(e);
}

bool wyCEGUINode::touchesMoved(wyMotionEvent& e) {
    wyPoint loc = wyp(e.x[0], e.y[0]);
    loc = worldToNodeSpace(loc);
    System::getSingleton().injectMousePosition(loc.x, wyDevice::winHeight - loc.y);
    
    return wyNode::touchesMoved(e);
}

bool wyCEGUINode::touchesEnded(wyMotionEvent& e) {
    wyPoint loc = wyp(e.x[0], e.y[0]);
    loc = worldToNodeSpace(loc);
    System::getSingleton().injectMousePosition(loc.x, wyDevice::winHeight - loc.y);
    System::getSingleton().injectMouseButtonUp(LeftButton);
    
    return wyNode::touchesEnded(e);
}

bool wyCEGUINode::touchesCancelled(wyMotionEvent& e) {
    wyPoint loc = wyp(e.x[0], e.y[0]);
    loc = worldToNodeSpace(loc);
    System::getSingleton().injectMousePosition(loc.x, wyDevice::winHeight - loc.y);
    System::getSingleton().injectMouseButtonUp(LeftButton);
    
    return wyNode::touchesCancelled(e);
}
