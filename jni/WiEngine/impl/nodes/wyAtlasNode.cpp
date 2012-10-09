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
#include "wyMaterial.h"
#include "wyQuadList.h"
#include "wyMaterialTextureParameter.h"

wyAtlasNode::~wyAtlasNode() {
}

wyAtlasNode::wyAtlasNode() :
		m_itemsPerRow(0),
		m_itemsPerColumn(0),
		m_texStepX(0),
		m_texStepY(0),
		m_itemWidth(0),
		m_itemHeight(0) {
	// only used for subclass
}

wyAtlasNode::wyAtlasNode(wyTexture2D* tex, int itemWidth, int itemHeight, int capacity) :
		m_itemsPerRow(0),
		m_itemsPerColumn(0),
		m_texStepX(0),
		m_texStepY(0),
		m_itemWidth(0),
		m_itemHeight(0) {
	init(tex, itemWidth, itemHeight, capacity);
}

wyAtlasNode* wyAtlasNode::make(wyTexture2D* tex, int itemWidth, int itemHeight, int capacity) {
	wyAtlasNode* n = WYNEW wyAtlasNode(tex, itemWidth, itemHeight, capacity);
	return (wyAtlasNode*)n->autoRelease();
}

void wyAtlasNode::init(wyTexture2D* tex, int itemWidth, int itemHeight, int capacity) {
	// init member
	m_itemWidth = itemWidth;
	m_itemHeight = itemHeight;
	m_height = itemHeight;
	m_itemsPerColumn = (int) (tex->getHeight() / m_itemHeight);
	m_itemsPerRow = (int) (tex->getWidth() / m_itemWidth);
	m_texStepX = m_itemWidth / (float)tex->getPixelWidth();
	m_texStepY = m_itemHeight / (float)tex->getPixelHeight();

	// set texture
	setTexture(tex);

	// create empty material and mesh
	setMaterial(wyMaterial::make());
	setMesh(wyQuadList::make());

	// set blend mode
	setBlendMode(wyRenderState::ALPHA);
}

void wyAtlasNode::updateMaterial() {
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

void wyAtlasNode::updateMeshColor() {
	wyQuadList* quadList = (wyQuadList*)getMesh();
	quadList->updateColor(m_color);
}
