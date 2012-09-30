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
#include "wyAtlasNode.h"
#include "wyTextureManager.h"
#include "wyLog.h"

wyAtlasNode::~wyAtlasNode() {
	wyObjectRelease(m_atlas);
}

wyAtlasNode::wyAtlasNode() :
		m_atlas(NULL),
		m_itemsPerRow(0),
		m_itemsPerColumn(0),
		m_texStepX(0),
		m_texStepY(0),
		m_itemWidth(0),
		m_itemHeight(0),
		m_blendFunc(wybfDefault),
		m_color(wyc4bWhite) {
	// only used for subclass
}

wyAtlasNode::wyAtlasNode(wyTexture2D* tex, int itemWidth, int itemHeight, int capacity) :
		m_atlas(NULL),
		m_itemsPerRow(0),
		m_itemsPerColumn(0),
		m_texStepX(0),
		m_texStepY(0),
		m_itemWidth(0),
		m_itemHeight(0),
		m_blendFunc(wybfDefault),
		m_color(wyc4bWhite) {
	init(tex, itemWidth, itemHeight, capacity);
}

wyAtlasNode* wyAtlasNode::make(wyTexture2D* tex, int itemWidth, int itemHeight, int capacity) {
	wyAtlasNode* n = WYNEW wyAtlasNode(tex, itemWidth, itemHeight, capacity);
	return (wyAtlasNode*)n->autoRelease();
}

void wyAtlasNode::draw() {
	// if no draw flag is set, call wyNode::draw and it
	// will decide forward drawing to java layer or not
	if(m_noDraw) {
		wyNode::draw();
		return;
	}

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_TEXTURE_2D);

    glColor4f(m_color.r / 255.0f, m_color.g / 255.0f, m_color.b / 255.0f, m_color.a / 255.0f);

    bool newBlend = false;
    if (m_blendFunc.src != DEFAULT_BLEND_SRC || m_blendFunc.dst != DEFAULT_BLEND_DST) {
        newBlend = true;
        glBlendFunc(m_blendFunc.src, m_blendFunc.dst);
    }

	m_atlas->drawAll();

    if (newBlend)
        glBlendFunc(DEFAULT_BLEND_SRC, DEFAULT_BLEND_DST);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

wyColor3B wyAtlasNode::getColor() {
	wyColor3B c = {
		m_color.r,
		m_color.g,
		m_color.b
	};
	return c;
}

void wyAtlasNode::setColor(wyColor3B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
}

void wyAtlasNode::setColor(wyColor4B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_color.a = color.a;
}

void wyAtlasNode::init(wyTexture2D* tex, int itemWidth, int itemHeight, int capacity) {
	// create texture and atlas and set
	m_atlas = WYNEW wyTextureAtlas(tex, capacity);

	m_itemWidth = itemWidth;
	m_itemHeight = itemHeight;
	m_height = itemHeight;
	m_color = wyc4bWhite;
	m_blendFunc.src = DEFAULT_BLEND_SRC;
	m_blendFunc.dst = DEFAULT_BLEND_DST;
	m_itemsPerColumn = (int) (m_atlas->getTexture()->getHeight() / m_itemHeight);
	m_itemsPerRow = (int) (m_atlas->getTexture()->getWidth() / m_itemWidth);
	m_texStepX = m_itemWidth / (float)m_atlas->getTexture()->getPixelWidth();
	m_texStepY = m_itemHeight / (float)m_atlas->getTexture()->getPixelHeight();
}

void wyAtlasNode::setAtlas(wyTextureAtlas* atlas) {
	wyObjectRetain(atlas);
	wyObjectRelease(m_atlas);
	m_atlas = atlas;
}
