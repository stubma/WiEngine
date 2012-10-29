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
#include "wyMaterial.h"
#include "wyQuadList.h"

wySpriteBatchNode* wySpriteBatchNode::make(wyTexture2D* tex) {
	wySpriteBatchNode* bn = WYNEW wySpriteBatchNode(tex);
	bn->autoRelease();
	return bn;
}

wySpriteBatchNode::wySpriteBatchNode():
		m_marker(0) {
	init(NULL);
}

wySpriteBatchNode::wySpriteBatchNode(wyTexture2D* tex):
		m_marker(0) {
	init(tex);
}

void wySpriteBatchNode::init(wyTexture2D* tex) {
	// create empty material and mesh
	addRenderPair(wyMaterial::make(), wyQuadList::make());

	// set blend mode
	setBlendMode(wyRenderState::ALPHA);

	// set anchor
	setRelativeAnchorPoint(false);

	// set texture
	setTexture(tex);
}

wySpriteBatchNode::~wySpriteBatchNode() {
}

void wySpriteBatchNode::updateMeshColor() {
	wyQuadList* quadList = (wyQuadList*)getMesh();
	quadList->updateColor(m_color);
}

void wySpriteBatchNode::beforeRender() {
	updateMesh();
}

void wySpriteBatchNode::updateMesh() {
	for(int i = 0; i < m_children->num; i++) {
		wySpriteEx* n = (wySpriteEx*)wyArrayGet(m_children, i);
		n->updateTransform();
	}
}

void wySpriteBatchNode::addSprite(wySpriteEx* sprite) {
	int index = sprite->getAtlasIndex();
	if(index >= 0) {
		sprite->setBatchNode(this);
		sprite->useBatchNode(true);
		((wyQuadList*)getMesh())->insertQuad(index, sprite->m_texCoords, sprite->m_vertices);

		// child need to be updated, so need update mesh flag should be set
		setNeedUpdateMesh(true);

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
	wyQuadList* atlas = (wyQuadList*)getMesh();
	int total = atlas->getTotalQuads();
    int index = sprite->getAtlasIndex();
    atlas->removeQuad(index);
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
	((wyQuadList*)getMesh())->removeAllQuads();
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
