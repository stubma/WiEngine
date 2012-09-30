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
#include "wySpriteBatchNode.h"
#include "wyLog.h"
#include "wyGlobal.h"

wySpriteBatchNode* wySpriteBatchNode::make(wyTexture2D* tex) {
	wySpriteBatchNode* bn = WYNEW wySpriteBatchNode(tex);
	bn->autoRelease();
	return bn;
}

void wySpriteBatchNode::init() {
	setRelativeAnchorPoint(false);
}

wySpriteBatchNode::wySpriteBatchNode():
		m_atlas(NULL),
		m_blendFunc(wybfDefault),
		m_color(wyc4bWhite),
		m_dither(false),
		m_blend(true),
		m_alphaTest(false),
		m_alphaFunc(GL_ALWAYS),
		m_alphaRef(0),
		m_marker(0) {
    init();
    m_atlas = wyTextureAtlas::make(NULL);
    m_atlas->retain();
}

wySpriteBatchNode::wySpriteBatchNode(wyTexture2D* tex):
		m_atlas(NULL),
		m_blendFunc(wybfDefault),
		m_color(wyc4bWhite),
		m_dither(false),
		m_blend(true),
		m_alphaTest(false),
		m_alphaFunc(GL_ALWAYS),
		m_alphaRef(0),
		m_marker(0) {
    init();
    m_atlas = wyTextureAtlas::make(tex);
    m_atlas->retain();
}

wySpriteBatchNode::~wySpriteBatchNode() {
	wyObjectRelease(m_atlas);
}

void wySpriteBatchNode::setTexture(wyTexture2D* tex) {
    m_atlas->setTexture(tex);
}

wyTexture2D* wySpriteBatchNode::getTexture() {
    return m_atlas->getTexture();
}

wyColor3B wySpriteBatchNode::getColor() {
	return wyc4b2c3b(m_color);
}

void wySpriteBatchNode::setColor(wyColor3B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_atlas->updateColor(m_color);
}

void wySpriteBatchNode::setColor(wyColor4B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_color.a = color.a;
	m_atlas->updateColor(m_color);
}

void wySpriteBatchNode::visit() {
	if(!m_visible)
		return;

	// should push matrix to avoid disturb current matrix
	glPushMatrix();

	// if grid is set, prepare grid
	if(m_grid != NULL && m_grid->isActive()) {
		m_grid->beforeDraw();
		transformAncestors();
	}

	// transform for myself
	transform();

	// check clip
	if(m_hasClip)
		doClip();

	// draw self
	draw();

	// restore
	if(m_hasClip)
		glDisable(GL_SCISSOR_TEST);

	// if grid is set, end grid
	if(m_grid != NULL && m_grid->isActive()) {
		m_grid->afterDraw(this);
	}

	// pop matrix
	glPopMatrix(); 
}

void wySpriteBatchNode::updateChildrenTransform() {
	for(int i = 0; i < m_children->num; i++) {
		wySpriteEx* n = (wySpriteEx*)wyArrayGet(m_children, i);
		n->updateTransform();
	}
}

bool wySpriteBatchNode::drawRange(int start, int count) {
	// if texture is not attached, return true directly
	if(m_atlas->getTexture() == NULL)
		return true;

	// update its children
	updateChildrenTransform();

	// check dither
	if(m_dither)
		glEnable(GL_DITHER);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);

	bool newBlend = false;
	if(m_blendFunc.src != DEFAULT_BLEND_SRC || m_blendFunc.dst != DEFAULT_BLEND_DST) {
		newBlend = true;
		glBlendFunc(m_blendFunc.src, m_blendFunc.dst);
	}

    bool ret = m_atlas->drawRange(start, count);

	if(newBlend)
		glBlendFunc(DEFAULT_BLEND_SRC, DEFAULT_BLEND_DST);

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    // check dither
    if(m_dither)
    	glDisable(GL_DITHER);

    return ret;
}

void wySpriteBatchNode::drawFromMarker(int count) {
	if(drawRange(m_marker, count))
		m_marker += count;
}

void wySpriteBatchNode::draw() {
	// if no draw flag is set, call wyNode::draw and it
	// will decide forward drawing to java layer or not
	if(m_noDraw) {
		wyNode::draw();
		return;
	}

	// if no texture attached, draw nothing
	if(m_atlas->getTexture() == NULL)
		return;

	// update its children
	updateChildrenTransform();

	// check dither
	if(m_dither)
		glEnable(GL_DITHER);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);

    // check alpha
    if(m_alphaTest) {
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(m_alphaFunc, m_alphaRef);
    }

	// check blend
	if(!m_blend)
		glDisable(GL_BLEND);

	bool newBlend = false;
	if(m_blendFunc.src != DEFAULT_BLEND_SRC || m_blendFunc.dst != DEFAULT_BLEND_DST) {
		newBlend = true;
		glBlendFunc(m_blendFunc.src, m_blendFunc.dst);
	}

    m_atlas->drawAll();

	if(newBlend)
		glBlendFunc(DEFAULT_BLEND_SRC, DEFAULT_BLEND_DST);

	// check blend
	if(!m_blend)
		glEnable(GL_BLEND);

    // check alpha
    if(m_alphaTest)
    	glDisable(GL_ALPHA_TEST);

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    // check dither
    if(m_dither)
    	glDisable(GL_DITHER);
}

void wySpriteBatchNode::addSprite(wySpriteEx* sprite) {
	int index = sprite->getAtlasIndex();
	if(index >= 0) {
		sprite->setBatchNode(this);
		sprite->useBatchNode(true);
		m_atlas->insertQuad(sprite->m_texCoords, sprite->m_vertices, index);

		// adjust other children index
    	for(int i = 0; i < m_children->num; i++) {
    		wySpriteEx* s = (wySpriteEx*)wyArrayGet(m_children, i);
    		if(s != sprite && s->getAtlasIndex() >= index) {
    			s->setAtlasIndex(s->getAtlasIndex() + 1);
    		}
    	}
	}
}

void wySpriteBatchNode::removeSprite(wySpriteEx* sprite) {
	int total = m_atlas->getTotalQuads();
    int index = sprite->getAtlasIndex();
    m_atlas->removeQuad(index);
    sprite->useBatchNode(false);
    sprite->setBatchNode(NULL);

    // need adjust atlas index if deletion is in middle
    if(index < total - 1) {
    	for(int i = 0; i < m_children->num; i++) {
    		wySpriteEx* s = (wySpriteEx*)wyArrayGet(m_children, i);
    		if(s->getAtlasIndex() > index) {
    			s->setAtlasIndex(s->getAtlasIndex() - 1);
    		}
    	}
    }
}

void wySpriteBatchNode::removeAllSprites() {
	m_atlas->removeAllQuads();
	for(int i = 0; i < m_children->num; i++) {
		wySpriteEx* s = (wySpriteEx*)wyArrayGet(m_children, i);
		s->useBatchNode(false);
		s->setBatchNode(NULL);
	}
}

void wySpriteBatchNode::addChild(wyNode* child, int z, int tag) {
    wySpriteEx* sprite = dynamic_cast<wySpriteEx*>(child);
    if(!sprite){
        LOGW("wySpriteBatchNode: Can't add a non-wySpriteEx node as child");
        return;
    }

    wyNode::addChild(child, z, tag);
    int index = wyArrayIndexOf(m_children, sprite, NULL, NULL);
    sprite->setAtlasIndex(index);
    addSprite(sprite);
}

void wySpriteBatchNode::removeChild(wyNode* child, bool cleanup) {
    wySpriteEx* sprite = dynamic_cast<wySpriteEx*>(child);
    if(!sprite || sprite->getParent() != this) {
        return;
    }
    removeSprite(sprite);
	wyNode::removeChild(child, cleanup);
}

int wySpriteBatchNode::reorderChild(wyNode* child, int z) {
    wySpriteEx* spriteEx = dynamic_cast<wySpriteEx*>(child);
    if(!spriteEx || spriteEx->getParent() != this) {
        return -1;
    }
    int ret = wyNode::reorderChild(child, z);
    removeSprite(spriteEx);
    addSprite(spriteEx);
    return ret;
}

void wySpriteBatchNode::removeAllChildren(bool cleanup) {
	removeAllSprites();
	wyNode::removeAllChildren(cleanup);
}

void wySpriteBatchNode::setAlphaFunc(GLenum func, float ref) {
	if(func == GL_ALWAYS) {
		m_alphaTest = false;
	} else {
		m_alphaTest = true;
		m_alphaFunc = func;
		m_alphaRef = ref;
	}
}
