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
#include "wyTexture2D.h"
#include "wyMaterial.h"
#include "wyQuadList.h"

wyNinePatchSprite* wyNinePatchSprite::make(wyTexture2D* tex, wyRect patchRect) {
	return make(tex, wyr(0, 0, tex->getWidth(), tex->getHeight()), patchRect);
}

wyNinePatchSprite* wyNinePatchSprite::make(wyTexture2D* tex, wyRect texRect, wyRect patchRect) {
	wyNinePatchSprite* sprite = WYNEW wyNinePatchSprite(tex, texRect, patchRect);
	return (wyNinePatchSprite*)sprite->autoRelease();
}

wyNinePatchSprite::wyNinePatchSprite(wyTexture2D* tex, wyRect texRect, wyRect patchRect) :
		m_patchRect(patchRect),
		m_texRect(wyrZero) {
	// create empty material and mesh
	setMaterial(wyMaterial::make());
	setMesh(wyQuadList::make());

	// set blend mode
	setBlendMode(wyRenderState::ALPHA);

	// set texture and rect
	setTexture(tex);
	setTextureRect(texRect);
}

wyNinePatchSprite::~wyNinePatchSprite() {
}

void wyNinePatchSprite::setTextureRect(wyRect rect) {
	m_texRect = rect;
	setContentSize(MAX(m_width, rect.width), MAX(m_height, rect.height));
}

void wyNinePatchSprite::setTexture(wyTexture2D* tex) {
	wyNode::setTexture(tex);

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
    }
}

void wyNinePatchSprite::updateMesh() {
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
	wyQuadList* quadList = (wyQuadList*)getMesh();
	quadList->removeAllQuads();

	// calculate texture borders
	float texPW = m_tex->getPixelWidth();
	float texPH = m_tex->getPixelHeight();
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
	quadList->appendQuad(t, v);

	// 5, 6, 1, 2
	wyq2Set(t, texX1, texY4, texX2, texY4, texX1, texY0, texX2, texY0);
	wyq3Set(v, vX1, vY4, 0, vX2, vY4, 0, vX1, vY0, 0, vX2, vY0, 0);
	quadList->appendQuad(t, v);

	// 6, 7, 2, 3
	wyq2Set(t, texX2, texY4, texX3, texY4, texX2, texY0, texX3, texY0);
	wyq3Set(v, vX2, vY4, 0, vX3, vY4, 0, vX2, vY0, 0, vX3, vY0, 0);
	quadList->appendQuad(t, v);

	// 8, 9, 4, 5
	wyq2Set(t, texX0, texY8, texX1, texY8, texX0, texY4, texX1, texY4);
	wyq3Set(v, vX0, vY8, 0, vX1, vY8, 0, vX0, vY4, 0, vX1, vY4, 0);
	quadList->appendQuad(t, v);

	// 9, 10, 5, 6
	wyq2Set(t, texX1, texY8, texX2, texY8, texX1, texY4, texX2, texY4);
	wyq3Set(v, vX1, vY8, 0, vX2, vY8, 0, vX1, vY4, 0, vX2, vY4, 0);
	quadList->appendQuad(t, v);

	// 10, 11, 6, 7
	wyq2Set(t, texX2, texY8, texX3, texY8, texX2, texY4, texX3, texY4);
	wyq3Set(v, vX2, vY8, 0, vX3, vY8, 0, vX2, vY4, 0, vX3, vY4, 0);
	quadList->appendQuad(t, v);

	// 12, 13, 8, 9
	wyq2Set(t, texX0, texY12, texX1, texY12, texX0, texY8, texX1, texY8);
	wyq3Set(v, vX0, vY12, 0, vX1, vY12, 0, vX0, vY8, 0, vX1, vY8, 0);
	quadList->appendQuad(t, v);

	// 13, 14, 9, 10
	wyq2Set(t, texX1, texY12, texX2, texY12, texX1, texY8, texX2, texY8);
	wyq3Set(v, vX1, vY12, 0, vX2, vY12, 0, vX1, vY8, 0, vX2, vY8, 0);
	quadList->appendQuad(t, v);

	// 14, 15, 10, 11
	wyq2Set(t, texX2, texY12, texX3, texY12, texX2, texY8, texX3, texY8);
	wyq3Set(v, vX2, vY12, 0, vX3, vY12, 0, vX2, vY8, 0, vX3, vY8, 0);
	quadList->appendQuad(t, v);
}

void wyNinePatchSprite::updateMaterial() {
	// get texture parameter, if none, create
	wyMaterialParameter* mp = getMaterial()->getParameter(wyUniform::NAME[wyUniform::TEXTURE_2D]);
	if(!mp) {
		wyMaterialTextureParameter* p = wyMaterialTextureParameter::make(wyUniform::NAME[wyUniform::TEXTURE_2D], m_tex);
		m_material->addParameter(p);
	} else {
		wyMaterialTextureParameter* mtp = (wyMaterialTextureParameter*)mp;
		mtp->setTexture(m_tex);
	}
}

void wyNinePatchSprite::updateMeshColor() {
	wyQuadList* quadList = (wyQuadList*)getMesh();
	quadList->updateColor(m_color);
}
