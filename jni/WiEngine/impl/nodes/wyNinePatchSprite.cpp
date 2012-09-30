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
#include "wyNinePatchSprite.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyGlobal.h"

wyNinePatchSprite* wyNinePatchSprite::make(wyTexture2D* tex, wyRect patchRect) {
	return make(tex, wyr(0, 0, tex->getWidth(), tex->getHeight()), patchRect);
}

wyNinePatchSprite* wyNinePatchSprite::make(wyTexture2D* tex, wyRect texRect, wyRect patchRect) {
	wyNinePatchSprite* sprite = WYNEW wyNinePatchSprite(tex, texRect, patchRect);
	return (wyNinePatchSprite*)sprite->autoRelease();
}

wyNinePatchSprite::wyNinePatchSprite(wyTexture2D* tex, wyRect texRect, wyRect patchRect) :
		m_atlas(NULL),
		m_blendFunc(wybfDefault),
		m_color(wyc4bWhite),
		m_blend(true),
		m_dirty(false),
		m_patchRect(patchRect),
		m_texRect(wyrZero) {
	m_atlas = wyTextureAtlas::make(NULL);
	m_atlas->retain();
	setTexture(tex);
	setTextureRect(texRect);
}

wyNinePatchSprite::~wyNinePatchSprite() {
	m_atlas->release();
}

void wyNinePatchSprite::setContentSize(float w, float h) {
	wyNode::setContentSize(w, h);
	m_dirty = true;
}

wyColor3B wyNinePatchSprite::getColor() {
	wyColor3B c = {
		m_color.r,
		m_color.g,
		m_color.b
	};
	return c;
}

void wyNinePatchSprite::setColor(wyColor3B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
}

void wyNinePatchSprite::setColor(wyColor4B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_color.a = color.a;
}

void wyNinePatchSprite::setTextureRect(wyRect rect) {
	m_texRect = rect;
	setContentSize(MAX(m_width, rect.width), MAX(m_height, rect.height));
	m_dirty = true;
}

void wyNinePatchSprite::setTexture(wyTexture2D* tex) {
	m_atlas->setTexture(tex);

	// sync content size
	if(tex != NULL) {
		setContentSize(MAX(m_width, tex->getWidth()), MAX(m_height, tex->getHeight()));

    	// update texture rect
		if(m_texRect.width == 0 || m_texRect.height == 0) {
	    	m_texRect.x = 0;
	    	m_texRect.y = 0;
	    	m_texRect.width = tex->getWidth();
	    	m_texRect.height = tex->getHeight();
		}

    	// set dirty flag
    	m_dirty = true;
    }
}

void wyNinePatchSprite::updateAtlas() {
	/*
	 * 图片被划分为9个区域
	 * (5, 6, 9, 10)是patchRect对应的范围
	 *
		0--1------2--3
		|  |      |  |
		4--5------6--7
		|  |      |  |
		|  |      |  |
		|  |      |  |
		8--9-----10--11
		|  |      |  |
		12-13----14--15
	 */

	// clear old
	m_atlas->removeAllQuads();

	// calculate texture borders
	wyTexture2D* tex = m_atlas->getTexture();
	float texPW = tex->getPixelWidth();
	float texPH = tex->getPixelHeight();
	float texX0 = m_texRect.x / texPW;
	float texX1 = (m_texRect.x + m_patchRect.x) / texPW;
	float texX2 = (m_texRect.x + m_patchRect.x + m_patchRect.width) / texPW;
	float texX3 = (m_texRect.x + m_texRect.width) / texPW;
	float texY0 = m_texRect.y / texPH;
	float texY4 = (m_texRect.y + m_patchRect.y) / texPH;
	float texY8 = (m_texRect.y + m_patchRect.y + m_patchRect.height) / texPH;
	float texY12 = (m_texRect.y + m_texRect.height) / texPH;

	// calculate vertex borders
	float vX0 = 0;
	float vX1 = m_patchRect.x;
	float vX2 = m_width - (m_texRect.width - m_patchRect.x - m_patchRect.width);
	float vX3 = m_width;
	float vY0 = m_height;
	float vY4 = m_height - m_patchRect.y;
	float vY8 = m_texRect.height - m_patchRect.y - m_patchRect.height;
	float vY12 = 0;

	// construct nine patches
	wyQuad2D t;
	wyQuad3D v;

	// (4, 5, 1, 0)
	wyq2Set(t, texX0, texY4, texX1, texY4, texX0, texY0, texX1, texY0);
	wyq3Set(v, vX0, vY4, 0, vX1, vY4, 0, vX0, vY0, 0, vX1, vY0, 0);
	m_atlas->appendQuad(t, v);

	// 5, 6, 1, 2
	wyq2Set(t, texX1, texY4, texX2, texY4, texX1, texY0, texX2, texY0);
	wyq3Set(v, vX1, vY4, 0, vX2, vY4, 0, vX1, vY0, 0, vX2, vY0, 0);
	m_atlas->appendQuad(t, v);

	// 6, 7, 2, 3
	wyq2Set(t, texX2, texY4, texX3, texY4, texX2, texY0, texX3, texY0);
	wyq3Set(v, vX2, vY4, 0, vX3, vY4, 0, vX2, vY0, 0, vX3, vY0, 0);
	m_atlas->appendQuad(t, v);

	// 8, 9, 4, 5
	wyq2Set(t, texX0, texY8, texX1, texY8, texX0, texY4, texX1, texY4);
	wyq3Set(v, vX0, vY8, 0, vX1, vY8, 0, vX0, vY4, 0, vX1, vY4, 0);
	m_atlas->appendQuad(t, v);

	// 9, 10, 5, 6
	wyq2Set(t, texX1, texY8, texX2, texY8, texX1, texY4, texX2, texY4);
	wyq3Set(v, vX1, vY8, 0, vX2, vY8, 0, vX1, vY4, 0, vX2, vY4, 0);
	m_atlas->appendQuad(t, v);

	// 10, 11, 6, 7
	wyq2Set(t, texX2, texY8, texX3, texY8, texX2, texY4, texX3, texY4);
	wyq3Set(v, vX2, vY8, 0, vX3, vY8, 0, vX2, vY4, 0, vX3, vY4, 0);
	m_atlas->appendQuad(t, v);

	// 12, 13, 8, 9
	wyq2Set(t, texX0, texY12, texX1, texY12, texX0, texY8, texX1, texY8);
	wyq3Set(v, vX0, vY12, 0, vX1, vY12, 0, vX0, vY8, 0, vX1, vY8, 0);
	m_atlas->appendQuad(t, v);

	// 13, 14, 9, 10
	wyq2Set(t, texX1, texY12, texX2, texY12, texX1, texY8, texX2, texY8);
	wyq3Set(v, vX1, vY12, 0, vX2, vY12, 0, vX1, vY8, 0, vX2, vY8, 0);
	m_atlas->appendQuad(t, v);

	// 14, 15, 10, 11
	wyq2Set(t, texX2, texY12, texX3, texY12, texX2, texY8, texX3, texY8);
	wyq3Set(v, vX2, vY12, 0, vX3, vY12, 0, vX2, vY8, 0, vX3, vY8, 0);
	m_atlas->appendQuad(t, v);
}

void wyNinePatchSprite::draw() {
	// if no draw flag is set, call wyNode::draw and it
	// will decide forward drawing to java layer or not
	if(m_noDraw) {
		wyNode::draw();
		return;
	}

	// check dirty flag
	if(m_dirty) {
		updateAtlas();
		m_dirty = false;
	}

	// enable states
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);

	// check blend
	if(!m_blend)
		glDisable(GL_BLEND);

    glColor4f(m_color.r / 255.0f, m_color.g / 255.0f, m_color.b / 255.0f, m_color.a / 255.0f);

    bool newBlend = false;
    if (m_blendFunc.src != DEFAULT_BLEND_SRC || m_blendFunc.dst != DEFAULT_BLEND_DST) {
        newBlend = true;
        glBlendFunc(m_blendFunc.src, m_blendFunc.dst);
    }

    // draw
	m_atlas->drawAll();

    if (newBlend)
        glBlendFunc(DEFAULT_BLEND_SRC, DEFAULT_BLEND_DST);

	// check blend
	if(!m_blend)
		glEnable(GL_BLEND);

    // is this cheaper than saving/restoring color state ?
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// disable states
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);
}
