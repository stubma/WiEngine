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
#include "wyTextureNode.h"
#include "wySpriteFrame.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyMaterial.h"
#include "wyRectangle.h"
#include "wyShaderManager.h"

wyTextureNode::wyTextureNode(wyTexture2D* tex) :
		m_originalTex(NULL),
        m_originSaved(false),
		m_autoFit(false),
		m_currentFrame(NULL),
		m_animations(WYNEW map<int, wyAnimation*>()) {
	// create empty material and mesh, default we use rectangle mesh
	addRenderPair(wyMaterial::make(), wyRectangle::make());

	// set texture
	setTexture(tex);

	// set blend mode
	setBlendMode(wyRenderState::ALPHA);

	// flag update
	setNeedUpdateMesh(true);
}

wyTextureNode* wyTextureNode::make(wyTexture2D* tex) {
	wyTextureNode* n = WYNEW wyTextureNode(tex);
	return (wyTextureNode*)n->autoRelease();
}

void wyTextureNode::releaseAnimation(int id, wyAnimation* anim) {
	wyObjectRelease(anim);
}

void wyTextureNode::updateMesh() {
	// update render width
	wyMesh* mesh = getMesh();
	if(m_autoFit) {
		mesh->setRenderWidth(m_width);
		mesh->setRenderHeight(m_height);
	} else if(mesh->isRotate90CCW()) {
		wyRect r = mesh->getTextureRect();
		mesh->setRenderWidth(r.height);
		mesh->setRenderHeight(r.width);
	} else {
		wyRect r = mesh->getTextureRect();
		mesh->setRenderWidth(r.width);
		mesh->setRenderHeight(r.height);
	}

	// update
	mesh->update();
}

void wyTextureNode::updateMeshColor() {
	// update color of mesh
	wyRectangle* rect = (wyRectangle*)getMesh();
	rect->updateColor4B(m_color);
}

void wyTextureNode::setTextureRect(wyRect rect) {
	// update mesh
	wyMesh* mesh = getMesh();
	mesh->setTextureRect(rect);

	// flag update
	setNeedUpdateMesh(true);
}

void wyTextureNode::setRenderOffset(wyPoint p) {
	wyMesh* mesh = getMesh();
	mesh->setOffsetX(p.x);
	mesh->setOffsetY(p.y);
}

void wyTextureNode::setTexture(wyTexture2D* tex, int index) {
	wyNode::setTexture(tex, 0);

	// sync content size
	if(tex != NULL) {
		// set content size
        if(!m_autoFit)
        	setContentSize(tex->getWidth(), tex->getHeight());

    	// update mesh
		wyMesh* mesh = getMesh();
		mesh->setTexPOTWidth(tex->getPixelWidth());
		mesh->setTexPOTHeight(tex->getPixelHeight());

		// set texture rect
		setTextureRect(wyr(0, 0, tex->getWidth(), tex->getHeight()));
    }
}

void wyTextureNode::addAnimation(wyAnimation* anim) {
	// ensure old entry is released
	int animId = anim->getId();
	map<int, wyAnimation*>::iterator iter = m_animations->find(animId);
	if(iter != m_animations->end()) {
		releaseAnimation(animId, iter->second);
		m_animations->erase(iter);
	}

	// set new entry
	(*m_animations)[animId] = anim;
	wyObjectRetain(anim);
}

wyAnimation* wyTextureNode::getAnimationById(int id) {
	map<int, wyAnimation*>::iterator iter = m_animations->find(id);
	if(iter != m_animations->end())
		return iter->second;
	else
		return NULL;
}

wyFrame* wyTextureNode::getDisplayFrame() {
	return m_currentFrame;
}

void wyTextureNode::setDisplayFrame(wyFrame* newFrame) {
	if(newFrame == NULL) {
		wyObjectRelease(m_currentFrame);
		m_currentFrame = NULL;

		// restore original texture
		if(m_originSaved) {
			setTexture(m_originalTex);
			wyObjectRelease(m_originalTex);
			m_originalTex = NULL;

			// restore content size
			setContentSize(m_originContentSize.width, m_originContentSize.height);

			// restore mesh info
			wyMesh* mesh = getMesh();
			mesh->setTextureRect(m_originTexRect);
			mesh->setRotate90CCW(m_originRotatedZwoptex);
            
            // reset flag
            m_originSaved = false;
		}
	} else {
		wySpriteFrame* f = dynamic_cast<wySpriteFrame*>(newFrame);
		if(f != NULL) {
			// hold frame
			wyObjectRetain(f);
			wyObjectRelease(m_currentFrame);
			m_currentFrame = f;

			// get mesh
			wyMesh* mesh = getMesh();

            // save original frame data
            if(!m_originSaved) {
                m_originSaved = true;
                
				m_originalTex = getTexture();
				wyObjectRetain(m_originalTex);
                m_originTexRect = mesh->getTextureRect();
                m_originContentSize = getContentSize();
                m_originRotatedZwoptex = mesh->isRotate90CCW();
            }

			// set texture
	        wyTexture2D* tex = f->getTexture();
	        if(tex) {
			    setTexture(tex);
            }

	        // get frame info
	        wyPoint offset = f->getOffset();
		    wySize size = f->getOriginalSize();
		    wyRect rect = f->getRect();
			bool rotate = f->isRotated();

		    // update mesh
		    mesh->setOffsetX(offset.x);
		    mesh->setOffsetY(offset.y);
		    mesh->setTexSourceWidth(size.width);
		    mesh->setTexSourceHeight(size.height);
		    mesh->setRotate90CCW(rotate);

	        // set texture rect
	        setTextureRect(rect);

	        // call setContentSize again to make sure the anchor of this node won't impact the animation
	        if(!m_autoFit)
	        	setContentSize(size.width, size.height);
	    } else {
	    	LOGW("setDisplayFrame: wyTextureNode only accepts wySpriteFrame");
	    }
	}

	// flag update
	setNeedUpdateMaterial(true);
	setNeedUpdateMesh(true);
}

void wyTextureNode::setDisplayFrameById(int id, int frameIndex) {
	map<int, wyAnimation*>::iterator iter = m_animations->find(id);
    if(iter != m_animations->end()) {
    	wyAnimation* anim = iter->second;
    	wyArray* frames = anim->getFrames();
    	wyFrame* frame = (wyFrame*)wyArrayGet(frames, frameIndex);
    	setDisplayFrame(frame);
    } else {
    	LOGW("Can't find animation whose id is %d", id);
    }
}

wyTextureNode::~wyTextureNode() {
	for(map<int, wyAnimation*>::iterator iter = m_animations->begin(); iter != m_animations->end(); iter++) {
		releaseAnimation(iter->first, iter->second);
	}
	WYDELETE(m_animations);
	wyObjectRelease(m_currentFrame);
	wyObjectRelease(m_originalTex);
}
