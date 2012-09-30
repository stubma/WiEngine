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

wyTextureNode::wyTextureNode(wyTexture2D* tex) :
		m_tex(NULL),
		m_originalTex(NULL),
		m_blendFunc(wybfDefault),
		m_color(wyc4bWhite),
        m_originSaved(false),
		m_flipX(false),
		m_flipY(false),
		m_blend(true),
		m_alphaTest(false),
		m_alphaFunc(GL_ALWAYS),
		m_alphaRef(0),
		m_dither(false),
		m_rotatedZwoptex(false),
		m_autoFit(false),
		m_currentFrame(NULL),
		m_pointLeftBottom(wypZero),
		m_animations(WYNEW map<int, wyAnimation*>()),
		m_texRect(wyrZero) {
	setTexture(tex);
}

wyTextureNode* wyTextureNode::make(wyTexture2D* tex) {
	wyTextureNode* n = WYNEW wyTextureNode(tex);
	return (wyTextureNode*)n->autoRelease();
}

void wyTextureNode::releaseAnimation(int id, wyAnimation* anim) {
	wyObjectRelease(anim);
}

wyColor3B wyTextureNode::getColor() {
	wyColor3B c = {
		m_color.r,
		m_color.g,
		m_color.b
	};
	return c;
}

void wyTextureNode::setColor(wyColor3B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
}

void wyTextureNode::setColor(wyColor4B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_color.a = color.a;
}

void wyTextureNode::setTextureRect(wyRect rect) {
	m_texRect = rect;
	if(!m_autoFit)
		setContentSize(rect.width, rect.height);
}

void wyTextureNode::setTexture(wyTexture2D* tex) {
	wyObjectRetain(tex);
	wyObjectRelease(m_tex);
	m_tex = tex;

	// sync content size
	if(tex != NULL) {
		// if node is set to auto fit, don't change texture size
		if(!m_autoFit)
			setContentSize(tex->getWidth(), tex->getHeight());

    	// update texture rect
    	m_texRect.x = 0;
    	m_texRect.y = 0;
    	m_texRect.width = tex->getWidth();
    	m_texRect.height = tex->getHeight();
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

			m_texRect = m_originTexRect;
			setContentSize(m_originContentSize.width, m_originContentSize.height);
			m_rotatedZwoptex = m_originRotatedZwoptex;
			m_pointLeftBottom = m_originPointLeftBottom;
            
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

			// is rotated
			m_rotatedZwoptex = f->isRotated();
            
            // save original frame data
            if(!m_originSaved) {
                m_originSaved = true;
                
				m_originalTex = m_tex;
				wyObjectRetain(m_originalTex);
                m_originTexRect = m_texRect;
                m_originContentSize = getContentSize();
                m_originRotatedZwoptex = m_rotatedZwoptex;
                m_originPointLeftBottom = m_pointLeftBottom;
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

		    // calculate offset
	        m_pointLeftBottom.x = (size.width - (m_rotatedZwoptex ? rect.height : rect.width)) / 2 + offset.x;
	        m_pointLeftBottom.y = (size.height - (m_rotatedZwoptex ? rect.width : rect.height)) / 2 + offset.y;

	        // set texture rect
	        setTextureRect(rect);

	        // call setContentSize again to make sure the anchor of this node won't impact the animation
	        if(!m_autoFit)
	        	setContentSize(size.width, size.height);
	    } else {
	    	LOGW("setDisplayFrame: wyTextureNode only accepts wySpriteFrame");
	    }
	}
}

wySpriteFrame* wyTextureNode::makeFrame() {
	float offsetX = m_pointLeftBottom.x - (m_width - (m_rotatedZwoptex ? m_texRect.height : m_texRect.width)) / 2;
	float offsetY = m_pointLeftBottom.y - (m_height - (m_rotatedZwoptex ? m_texRect.width : m_texRect.height)) / 2;
	return wySpriteFrame::make(0,
			m_tex,
			m_texRect,
			wyp(offsetX, offsetY),
			wys(m_width, m_height),
			m_rotatedZwoptex);
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
	wyObjectRelease(m_tex);
	wyObjectRelease(m_originalTex);
}

void wyTextureNode::draw() {
	// if no draw flag is set, call wyNode::draw and it
	// will decide forward drawing to java layer or not
	if(m_noDraw) {
		wyNode::draw();
		return;
	}

	// check dither
	if(m_dither)
		glEnable(GL_DITHER);

    glColor4f(m_color.r / 255.0f, m_color.g / 255.0f, m_color.b / 255.0f, m_color.a / 255.0f);

    // check alpha
    if(m_alphaTest) {
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(m_alphaFunc, m_alphaRef);
    }

	// check blend
	if(!m_blend)
		glDisable(GL_BLEND);

    bool newBlend = false;
    if (m_blendFunc.src != DEFAULT_BLEND_SRC || m_blendFunc.dst != DEFAULT_BLEND_DST) {
        newBlend = true;
        glBlendFunc(m_blendFunc.src, m_blendFunc.dst);
    }

    if (m_tex != NULL) {
    	m_tex->draw(m_autoFit ? 0 : m_pointLeftBottom.x,
    			m_autoFit ? 0 : m_pointLeftBottom.y,
    			m_autoFit ? m_width : (m_rotatedZwoptex ? m_texRect.height : m_texRect.width),
    			m_autoFit ? m_height : (m_rotatedZwoptex ? m_texRect.width : m_texRect.height),
                m_width,
                m_height,
				m_flipX,
				m_flipY,
				m_texRect,
				m_rotatedZwoptex);
    }

    if (newBlend)
        glBlendFunc(DEFAULT_BLEND_SRC, DEFAULT_BLEND_DST);

	// check blend
	if(!m_blend)
		glEnable(GL_BLEND);

    // check alpha
    if(m_alphaTest)
    	glDisable(GL_ALPHA_TEST);

    // is this cheaper than saving/restoring color state ?
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    // check dither
    if(m_dither)
    	glDisable(GL_DITHER);
}

void wyTextureNode::setAlphaFunc(GLenum func, float ref) {
	if(func == GL_ALWAYS) {
		m_alphaTest = false;
	} else {
		m_alphaTest = true;
		m_alphaFunc = func;
		m_alphaRef = ref;
	}
}
