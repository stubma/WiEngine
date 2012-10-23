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

#define STATE_NORMAL 1
#define STATE_SELECTED 2
#define STATE_DISABLED 3

wyMenuItemSprite::~wyMenuItemSprite() {
}

wyMenuItemSprite* wyMenuItemSprite::make(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wySprite* normal, wySprite* selected, wySprite* disabled) {
	wyMenuItemSprite* n = WYNEW wyMenuItemSprite(downSelector, upSelector, normal, selected, disabled);
	return (wyMenuItemSprite*)n->autoRelease();
}

wyMenuItemSprite::wyMenuItemSprite(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wySprite* normal, wySprite* selected, wySprite* disabled) :
		wyMenuItem(downSelector, upSelector) {
	setNormalSprite(normal);
	setSelectedSprite(selected);
	setDisabledSprite(disabled);
}

void wyMenuItemSprite::setNormalSprite(wySprite* normal) {
	registerNode(STATE_NORMAL, normal, false);
}

wySprite* wyMenuItemSprite::getNormalSprite() {
	return (wySprite*)getNode(STATE_NORMAL);
}

void wyMenuItemSprite::setSelectedSprite(wySprite* selected) {
	registerNode(STATE_SELECTED, selected, false);
}

wySprite* wyMenuItemSprite::getSelectedSprite() {
	return (wySprite*)getNode(STATE_SELECTED);
}

void wyMenuItemSprite::setDisabledSprite(wySprite* disabled) {
	registerNode(STATE_DISABLED, disabled, false);
}

wySprite* wyMenuItemSprite::getDisabledSprite() {
	return (wySprite*)getNode(STATE_DISABLED);
}

int wyMenuItemSprite::getStateTag() {
    if (m_enabled) {
        if (m_selected) {
        	if(getNode(STATE_SELECTED) != NULL)
        		return STATE_SELECTED;
        	else
				return STATE_NORMAL;
        } else {
			return STATE_NORMAL;
        }
    } else {
        if (getNode(STATE_DISABLED) != NULL)
        	return STATE_DISABLED;
        else
			return STATE_NORMAL;
    }
}
