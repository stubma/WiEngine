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
#include "wyDotPageIndicator.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyMaterial.h"
#include "wyRectangle.h"

wyDotPageIndicator::wyDotPageIndicator(wyTexture2D* dot, wyRect dotRect, wyTexture2D* selectedDot, wyRect selectedDotRect) :
		m_pageCount(0),
		m_selectedIndex(-1),
		m_dotSpacing(DP(4)) {
	m_dotRect = dotRect;
	m_selectedDotRect = selectedDotRect;
	m_dot = dot;
	wyObjectRetain(m_dot);
	m_selectedDot = selectedDot;
	wyObjectRetain(m_selectedDot);

	// create dot material
	m_dotMaterial = wyMaterial::make();
	wyMaterialTextureParameter* p = wyMaterialTextureParameter::make(wyUniform::NAME[wyUniform::TEXTURE_2D], dot);
	m_dotMaterial->addParameter(p);
	m_dotMaterial->retain();

	// create selected to material
	m_selectedDotMaterial = wyMaterial::make();
	p = wyMaterialTextureParameter::make(wyUniform::NAME[wyUniform::TEXTURE_2D], selectedDot);
	m_selectedDotMaterial->addParameter(p);
	m_selectedDotMaterial->retain();

	/*
	 * set blend mode, don't call setBlendMode directly because
	 * we didn't add any render pair yet
	 */
	m_dotMaterial->getTechnique()->getRenderState()->blendMode = wyRenderState::ALPHA;
	m_selectedDotMaterial->getTechnique()->getRenderState()->blendMode = wyRenderState::ALPHA;
}

wyDotPageIndicator::~wyDotPageIndicator() {
	wyObjectRelease(m_dotMaterial);
	wyObjectRelease(m_selectedDotMaterial);
	wyObjectRelease(m_dot);
	wyObjectRelease(m_selectedDot);
}

wyDotPageIndicator* wyDotPageIndicator::make(wyTexture2D* dot, wyTexture2D* selectedDot) {
	wyDotPageIndicator* i = WYNEW wyDotPageIndicator(dot,
			wyr(0, 0, dot->getWidth(), dot->getHeight()),
			selectedDot,
			wyr(0, 0, selectedDot->getWidth(), selectedDot->getHeight()));
	return (wyDotPageIndicator*)i->autoRelease();
}

wyDotPageIndicator* wyDotPageIndicator::make(wyTexture2D* dot, wyRect dotRect, wyTexture2D* selectedDot, wyRect selectedDotRect) {
	wyDotPageIndicator* i = WYNEW wyDotPageIndicator(dot, dotRect, selectedDot, selectedDotRect);
	return (wyDotPageIndicator*)i->autoRelease();
}

void wyDotPageIndicator::initWithPages(int page, int selectedIndex) {
	m_pageCount = page;
	m_selectedIndex = selectedIndex;
	updateContentSize();
}

void wyDotPageIndicator::onPageAdded(int index) {
	m_pageCount++;
	updateContentSize();
}

void wyDotPageIndicator::onPageRemoved(wyNode* page, int index) {
	m_pageCount--;
	updateContentSize();
}

void wyDotPageIndicator::onPageAllRemoved() {
	m_pageCount = 0;
	m_selectedIndex = -1;
	updateContentSize();
}

void wyDotPageIndicator::onPageChanged(int index) {
	m_selectedIndex = index;
	setNeedUpdateMesh(true);
}

void wyDotPageIndicator::updateContentSize() {
	if(m_pageCount <= 0)
		setContentSize(0, 0);
	else
		setContentSize(MAX(m_dotRect.width, m_selectedDotRect.width) * m_pageCount + m_dotSpacing * (m_pageCount - 1),
				MAX(m_dotRect.height, m_selectedDotRect.height));
}

void wyDotPageIndicator::updateMesh() {
	// clear current render pairs
	clearRenderPairs();

	float dotW = MAX(m_dotRect.width, m_selectedDotRect.width);
	float dotH = MAX(m_dotRect.height, m_selectedDotRect.height);
	float x = dotW / 2;
	float y = dotH / 2;
	for(int i = 0; i < m_pageCount; i++) {
		if(m_selectedIndex == i) {
			wyRectangle* r = wyRectangle::make();
			r->updateMesh(m_selectedDot->getPixelWidth(),
					m_selectedDot->getPixelHeight(),
					x - m_selectedDotRect.width / 2,
					y - m_selectedDotRect.height / 2,
					m_selectedDotRect.width,
					m_selectedDotRect.height,
					m_selectedDot->getWidth(),
					m_selectedDot->getHeight(),
					false,
					false,
					m_selectedDotRect,
					false);
			addRenderPair(m_selectedDotMaterial, r);
		} else {
			wyRectangle* r = wyRectangle::make();
			r->updateMesh(m_dot->getPixelWidth(),
					m_dot->getPixelHeight(),
					x - m_dotRect.width / 2,
					y - m_dotRect.height / 2,
					m_dotRect.width,
					m_dotRect.height,
					m_dot->getWidth(),
					m_dot->getHeight(),
					false,
					false,
					m_dotRect,
					false);
			addRenderPair(m_dotMaterial, r);
		}

		x += dotW + m_dotSpacing;
	}
}
