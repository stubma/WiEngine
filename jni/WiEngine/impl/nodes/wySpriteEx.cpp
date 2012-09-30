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
#include "wySpriteEx.h"
#include "wySpriteFrame.h"
#include "wyLog.h"
#include <typeinfo>
#include "wyTypes.h"
#include "wyUtils.h"

#define INVALID_INDEX -1

wySpriteEx* wySpriteEx::make(wyTexture2D* pTex) {
	wySpriteEx* sprite = WYNEW wySpriteEx(pTex);
	sprite->autoRelease();
	return sprite;
}

wySpriteEx* wySpriteEx::make(wyTexture2D* pTex, wyRect r) {
	wySpriteEx* sprite = WYNEW wySpriteEx(pTex, r);
	sprite->autoRelease();
	return sprite;
}

wySpriteEx* wySpriteEx::make(wyTexture2D* pTex, wyZwoptexFrame* f) {
	wySpriteEx* sprite = WYNEW wySpriteEx(pTex, f);
	sprite->autoRelease();
	return sprite;
}

wySpriteEx* wySpriteEx::make(wySpriteBatchNode* pBatchNode, wyRect r, int zOrder) {
	/*
	 * 这里把autoRelease移到前面，因为autoRelease有可能不在gl线程中执行，导致
	 * 对象被放入delay release pool, 而后面的addChildLocked可以把它清除出
	 * delay pool. 如果autorelease放在后面就不会了。也许大部分情况下没什么问题，
	 * 但是如果恰好第三方应用在之后也没有继续retain的话，就导致它一直在delay pool
	 * 里面呆着而无法释放了，在director end之前它将无法被清除。
	 */
    wySpriteEx* sprite = WYNEW wySpriteEx(pBatchNode->getTexture(), r);
    sprite->autoRelease();
    pBatchNode->addChildLocked(sprite, zOrder);
    return sprite;
}

wySpriteEx* wySpriteEx::make(wySpriteBatchNode* pBatchNode, wyZwoptexFrame* f, int zOrder) {
    wySpriteEx* sprite = WYNEW wySpriteEx(pBatchNode->getTexture(), f);
    sprite->autoRelease();
    pBatchNode->addChildLocked(sprite, zOrder);
    return sprite;
}

void wySpriteEx::init() {
	m_useBatchNode = false;
	m_atlasIndex = INVALID_INDEX;
	m_batchNode = NULL;
	m_colorDirty = true;
	m_texDirty = true;
    memset(&m_texCoords, 0, sizeof(m_texCoords));
    memset(&m_vertices, 0, sizeof(m_vertices));
}

wySpriteEx::wySpriteEx() {
	init();
}

wySpriteEx::wySpriteEx(wyTexture2D* pTex) : wyTextureNode(pTex) {
    init();
}

wySpriteEx::wySpriteEx(wyTexture2D* pTex, wyRect r) : wyTextureNode(pTex) {
    init();
    
	setTextureRect(r);
}

wySpriteEx::wySpriteEx(wyTexture2D* pTex, wyZwoptexFrame* f) : wyTextureNode(pTex) {
	init();

	setTextureRect(f->rect);
	setContentSize(f->sourceSize.width, f->sourceSize.height);
	setRotatedZwoptex(f->rotated);
	m_pointLeftBottom.x = f->sourceSize.width / 2 + f->offset.x - (f->rotated ? f->rect.height : f->rect.width) / 2;
	m_pointLeftBottom.y = f->sourceSize.height / 2 + f->offset.y - (f->rotated ? f->rect.width : f->rect.height) / 2;
}

wySpriteEx::~wySpriteEx() {
}

void wySpriteEx::draw() {
	// don't draw if in batch mode
    if(m_useBatchNode)
        return;

    // call super
    wyTextureNode::draw();
}

void wySpriteEx::setAlpha(int alpha) {
	wyTextureNode::setAlpha(alpha);
	m_colorDirty = true;
}

void wySpriteEx::setColor(wyColor3B color) {
	wyTextureNode::setColor(color);
	m_colorDirty = true;
}

void wySpriteEx::setColor(wyColor4B color) {
	wyTextureNode::setColor(color);
	m_colorDirty = true;
}

wyBlendFunc wySpriteEx::getBlendFunc() {
    if(m_useBatchNode) {
        LOGW("No BlendFunc due to this sprite is using batchnode");
    }
    return m_useBatchNode ? wybfDefault : wyTextureNode::getBlendFunc();
}

void wySpriteEx::setBlendFunc(wyBlendFunc func) {
    if(m_useBatchNode) {
        LOGW("Can't setBlendFunc due to this sprite is using batchnode");
    } else {
    	wyTextureNode::setBlendFunc(func);
    }
}

wyTexture2D* wySpriteEx::getTexture() {
    if(m_useBatchNode) {
        return m_batchNode->getTexture();
    } else {
        return wyTextureNode::getTexture();
    }
};

void wySpriteEx::setTexture(wyTexture2D* tex) {
    if(m_useBatchNode) {
        LOGW("sprite is using batchnode, this OP may impact other sprites");
        m_batchNode->setTexture(tex);
    } else {
    	wyTextureNode::setTexture(tex);
    }
}

void wySpriteEx::updateTransform() {
    if(!m_useBatchNode) {
        LOGW("This func only applies to sprite using batchnode");
        return;
    }
    
    if(!m_texDirty && !m_colorDirty && !m_transformDirty) {
        return;
    }

    if(m_texDirty || m_transformDirty) {
        if(m_transformDirty) {
            wyAffineTransform t = getNodeToBatchNodeTransform();
            updateVertices(t);
        }

        if(m_texDirty)
            updateTextureCoords();

    	m_batchNode->m_atlas->updateQuad(m_texCoords, m_vertices, m_atlasIndex);
    }

    if(m_colorDirty) {
        updateColor();
    }
    
    m_texDirty = m_colorDirty = m_transformDirty = false;
}

void wySpriteEx::setVisible(bool visible) {
    wyTextureNode::setVisible(visible);
    
    // must update vertices if use batch render, so need flag transform is dirty
    if(m_useBatchNode)
        setTransformDirty();
}

wyAffineTransform wySpriteEx::getNodeToBatchNodeTransform() {
	updateNodeToParentTransform();
	wyAffineTransform t = m_transformMatrix;

	for(wyNode* p = m_parent; p != m_batchNode; p = p->getParent()) {
        wyAffineTransform tp = p->getTransformMatrix();
		wyaConact(&t, &tp);
	}

	return t;
}

void wySpriteEx::updateColor() {
	m_batchNode->m_atlas->updateColor(m_color, m_atlasIndex);
}

void wySpriteEx::updateTextureCoords() {
	float atlasWidth = m_batchNode->getTexture()->getPixelWidth();
	float atlasHeight = m_batchNode->getTexture()->getPixelHeight();

	float left = (2 * m_texRect.x + 1) / (2 * atlasWidth);
	float right = left + (m_texRect.width * 2 - 2) / (2 * atlasWidth);
	float top = (2 * m_texRect.y + 1) / (2 * atlasHeight);
	float bottom = top + (m_texRect.height * 2 - 2) / (2 * atlasHeight);

	if(m_flipX) {
		float tmp = left;
		left = right;
		right = tmp;
	}
	if(m_flipY) {
		float tmp = top;
		top = bottom;
		bottom = tmp;
	}

	if(m_rotatedZwoptex) {
		m_texCoords.bl_x = left;
		m_texCoords.bl_y = top;
		m_texCoords.br_x = left;
		m_texCoords.br_y = bottom;
		m_texCoords.tl_x = right;
		m_texCoords.tl_y = top;
		m_texCoords.tr_x = right;
		m_texCoords.tr_y = bottom;
	} else {
		m_texCoords.bl_x = left;
		m_texCoords.bl_y = bottom;
		m_texCoords.br_x = right;
		m_texCoords.br_y = bottom;
		m_texCoords.tl_x = left;
		m_texCoords.tl_y = top;
		m_texCoords.tr_x = right;
		m_texCoords.tr_y = top;
	}
}

void wySpriteEx::updateVertices(wyAffineTransform& t) {
	// if not visible then everything is 0
	if(!m_visible) {
		memset(&(m_vertices), 0, sizeof(wyQuad3D));
	} else {
		float x1 = m_autoFit ? 0 : m_pointLeftBottom.x;
		float y1 = m_autoFit ? 0 : m_pointLeftBottom.y;
		float x2 = x1 + (m_autoFit ? m_width : (m_rotatedZwoptex ? m_texRect.height : m_texRect.width));
		float y2 = y1 + (m_autoFit ? m_height : (m_rotatedZwoptex ? m_texRect.width : m_texRect.height));

        m_vertices.bl_x = x1;
		m_vertices.bl_y = y1;
		m_vertices.bl_z = 0;
		m_vertices.br_x = x2;
		m_vertices.br_y = y1;
		m_vertices.br_z = 0;
		m_vertices.tl_x = x1;
		m_vertices.tl_y = y2;
		m_vertices.tl_z = 0;
		m_vertices.tr_x = x2;
		m_vertices.tr_y = y2;
		m_vertices.tr_z = 0;

		if(m_flipY) {
			// adjust vertices y value
			m_vertices.bl_y = m_height - m_vertices.bl_y;
			m_vertices.br_y = m_height - m_vertices.br_y;
			m_vertices.tl_y = m_height - m_vertices.tl_y;
			m_vertices.tr_y = m_height - m_vertices.tr_y;

			// swap bl and tl, swap br and tr
			wyUtils::swap((float*)&m_vertices, 0, 6);
			wyUtils::swap((float*)&m_vertices, 1, 7);
			wyUtils::swap((float*)&m_vertices, 2, 8);
			wyUtils::swap((float*)&m_vertices, 3, 9);
			wyUtils::swap((float*)&m_vertices, 4, 10);
			wyUtils::swap((float*)&m_vertices, 5, 11);
		}

		if(m_flipX) {
			// adjust vertices x value
			m_vertices.bl_x = m_width - m_vertices.bl_x;
			m_vertices.br_x = m_width - m_vertices.br_x;
			m_vertices.tl_x = m_width - m_vertices.tl_x;
			m_vertices.tr_x = m_width - m_vertices.tr_x;

			// swap bl and br, swap tl and tr
			wyUtils::swap((float*)&m_vertices, 0, 3);
			wyUtils::swap((float*)&m_vertices, 1, 4);
			wyUtils::swap((float*)&m_vertices, 2, 5);
			wyUtils::swap((float*)&m_vertices, 6, 9);
			wyUtils::swap((float*)&m_vertices, 7, 10);
			wyUtils::swap((float*)&m_vertices, 8, 11);
		}

        wyPoint temp;
        temp.x = m_vertices.bl_x;
        temp.y = m_vertices.bl_y;
        temp = wyaTransformPoint(t, temp);
        m_vertices.bl_x = temp.x;
        m_vertices.bl_y = temp.y;

        temp.x = m_vertices.br_x;
        temp.y = m_vertices.br_y;
        temp = wyaTransformPoint(t, temp);
        m_vertices.br_x = temp.x;
        m_vertices.br_y = temp.y;   

        temp.x = m_vertices.tl_x;
        temp.y = m_vertices.tl_y;
        temp = wyaTransformPoint(t, temp);
        m_vertices.tl_x = temp.x;
        m_vertices.tl_y = temp.y;

        temp.x = m_vertices.tr_x;
        temp.y = m_vertices.tr_y;
        temp = wyaTransformPoint(t, temp);
        m_vertices.tr_x = temp.x;
        m_vertices.tr_y = temp.y;
	}
}

void wySpriteEx::setTextureRect(wyRect rt) {
	wyTextureNode::setTextureRect(rt);
    m_texDirty = true;
}

void wySpriteEx::setFlipX(bool flipX) {
	wyTextureNode::setFlipX(flipX);
	m_texDirty = true;
}

void wySpriteEx::setFlipY(bool flipY) {
	wyTextureNode::setFlipY(flipY);
	m_texDirty = true;
}

void wySpriteEx::addChild(wyNode* child, int z, int tag) {
    if(m_useBatchNode) {
        LOGW("Can't add a child to wySpriteEx if it uses batch node");
        return;
    }

    wyNode::addChild(child, z, tag);
}

void wySpriteEx::setBatchNode(wySpriteBatchNode* batchNode) {
	// don't retain batch node because batch node will retain sprite
	// we need avoid retain cycling
    m_batchNode = batchNode;
}
