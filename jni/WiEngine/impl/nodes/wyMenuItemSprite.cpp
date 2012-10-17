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
#include "wyMenuItemSprite.h"
#include <stdlib.h>

wyMenuItemSprite::~wyMenuItemSprite() {
	wyObjectRelease(m_normalState);
	wyObjectRelease(m_selectedState);
	wyObjectRelease(m_disabledState);
}

wyMenuItemSprite* wyMenuItemSprite::make(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wySprite* normal, wySprite* selected, wySprite* disabled) {
	wyMenuItemSprite* n = WYNEW wyMenuItemSprite(downSelector, upSelector, normal, selected, disabled);
	return (wyMenuItemSprite*)n->autoRelease();
}

//void wyMenuItemSprite::draw() {
//	// if no draw flag is set, call wyNode::draw and it
//	// will decide forward drawing to java layer or not
//	if(m_noDraw) {
//		wyNode::draw();
//		return;
//	}
//
//    if (m_enabled) {
//        if (m_selected) {
//        	if(m_selectedState != NULL)
//        		m_selectedState->draw();
//        	else
//        		m_normalState->draw();
//        } else
//        	m_normalState->draw();
//    } else {
//        if (m_disabledState != NULL)
//        	m_disabledState->draw();
//        else
//        	m_normalState->draw();
//    }
//}

void wyMenuItemSprite::adjustContentSize() {
    if (m_enabled) {
        if (m_selected) {
        	if(m_selectedState != NULL)
        		setContentSize(m_selectedState->getWidth(), m_selectedState->getHeight());
        	else
        		setContentSize(m_normalState->getWidth(), m_normalState->getHeight());
        } else
        	setContentSize(m_normalState->getWidth(), m_normalState->getHeight());
    } else {
        if (m_disabledState != NULL)
        	setContentSize(m_disabledState->getWidth(), m_disabledState->getHeight());
        else
        	setContentSize(m_normalState->getWidth(), m_normalState->getHeight());
    }
}

void wyMenuItemSprite::setSelected(bool selected) {
	wyMenuItem::setSelected(selected);
	adjustContentSize();
}

void wyMenuItemSprite::setEnabled(bool enabled) {
	wyMenuItem::setEnabled(enabled);
	adjustContentSize();
}

void wyMenuItemSprite::setAlpha(int alpha) {
	m_normalState->setAlpha(alpha);
	if(m_selectedState != NULL)
		m_selectedState->setAlpha(alpha);
	if(m_disabledState != NULL)
		m_disabledState->setAlpha(alpha);
}

void wyMenuItemSprite::setColor(wyColor3B color) {
	m_normalState->setColor(color);
	if(m_selectedState != NULL)
		m_selectedState->setColor(color);
	if(m_disabledState != NULL)
		m_disabledState->setColor(color);
}

void wyMenuItemSprite::setColor(wyColor4B color) {
	m_normalState->setColor(color);
	if(m_selectedState != NULL)
		m_selectedState->setColor(color);
	if(m_disabledState != NULL)
		m_disabledState->setColor(color);
}

void wyMenuItemSprite::setBlendMode(wyRenderState::BlendMode mode) {
	m_normalState->setBlendMode(mode);
	if(m_selectedState != NULL)
		m_selectedState->setBlendMode(mode);
	if(m_disabledState != NULL)
		m_disabledState->setBlendMode(mode);
}

void wyMenuItemSprite::setRotation(float rot) {
	wyMenuItem::setRotation(rot);
	m_normalState->setRotation(rot);
	if(m_selectedState != NULL)
		m_selectedState->setRotation(rot);
	if(m_disabledState != NULL)
		m_disabledState->setRotation(rot);
}

void wyMenuItemSprite::setScale(float scale) {
	wyMenuItem::setScale(scale);
	m_normalState->setScale(scale);
	if(m_selectedState != NULL)
		m_selectedState->setScale(scale);
	if(m_disabledState != NULL)
		m_disabledState->setScale(scale);
}

void wyMenuItemSprite::setScaleX(float scaleX) {
	wyMenuItem::setScaleX(scaleX);
	m_normalState->setScaleX(scaleX);
	if(m_selectedState != NULL)
		m_selectedState->setScaleX(scaleX);
	if(m_disabledState != NULL)
		m_disabledState->setScaleX(scaleX);
}

void wyMenuItemSprite::setScaleY(float scaleY) {
	wyMenuItem::setScaleY(scaleY);
	m_normalState->setScaleY(scaleY);
	if(m_selectedState != NULL)
		m_selectedState->setScaleY(scaleY);
	if(m_disabledState != NULL)
		m_disabledState->setScaleY(scaleY);
}

wyMenuItemSprite::wyMenuItemSprite(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wySprite* normal, wySprite* selected, wySprite* disabled) :
		wyMenuItem(downSelector, upSelector),
		m_normalState(NULL),
		m_selectedState(NULL),
		m_disabledState(NULL) {
	setNormalSprite(normal);
	setSelectedSprite(selected);
	setDisabledSprite(disabled);

	setContentSize(normal->getWidth(), normal->getHeight());
}

void wyMenuItemSprite::setNormalSprite(wySprite* normal) {
	wyObjectRetain(normal);
	wyObjectRelease(m_normalState);
	m_normalState = normal;
}

void wyMenuItemSprite::setSelectedSprite(wySprite* selected) {
	wyObjectRetain(selected);
	wyObjectRelease(m_selectedState);
	m_selectedState = selected;
}

void wyMenuItemSprite::setDisabledSprite(wySprite* disabled) {
	wyObjectRetain(disabled);
	wyObjectRelease(m_disabledState);
	m_disabledState = disabled;
}
