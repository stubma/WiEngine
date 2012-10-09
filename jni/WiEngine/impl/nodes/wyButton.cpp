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
#include "wyButton.h"
#include "wyLog.h"
#include "wyMenuItem.h"
#include "wyScaleTo.h"
#include <stdlib.h>
#include "wySpriteEx.h"
#include "wyTextureNode.h"

#define STATE_NORMAL 1
#define STATE_SELECTED 2
#define STATE_DISABLED 3
#define STATE_FOCUSED 4

wyButton* wyButton::make(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyTargetSelector* downSelector, wyTargetSelector* upSelector) {
	wyButton* n = WYNEW wyButton(normal, selected, disabled, focused, downSelector, upSelector);
	return (wyButton*)n->autoRelease();
}

int wyButton::getStateTag() {
    if (m_enabled) {
        if (m_selected) {
        	if(getNode(STATE_SELECTED) != NULL)
        		return STATE_SELECTED;
        	else
				return STATE_NORMAL;
        } else if (m_focused) {
        	if(getNode(STATE_FOCUSED) != NULL)
        		return STATE_FOCUSED;
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

wyButton::~wyButton() {
}

wyButton::wyButton(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyTargetSelector* downSelector, wyTargetSelector* upSelector) :
		m_clickScale(1.f),
		m_originalScale(0.f) {
	setNormalState(normal);
	setSelectedState(selected);
	setDisabledState(disabled);
	setFocusedState(focused);
	setDownSelector(downSelector);
	setUpSelector(upSelector);

	float width = 0;
	float height = 0;
	if (normal != NULL) {
		width = normal->getWidth();
		height = normal->getHeight();
	}

	if (selected != NULL) {
		width = MAX(selected->getWidth(), width);
		height = MAX(selected->getHeight(), height);
	}

	if (disabled != NULL) {
		width = MAX(disabled->getWidth(), width);
		height = MAX(disabled->getHeight(), height);
	}
	if (focused != NULL) {
		width = MAX(focused->getWidth(), width);
		height = MAX(focused->getHeight(), height);
	}
	setContentSize(width, height);
	setTouchEnabled(true);
}

void wyButton::setTexture(wyTexture2D* normal, wyTexture2D* selected, wyTexture2D* disabled, wyTexture2D* focused) {
	wyNode* normalState = getNode(STATE_NORMAL);
	if(normal != NULL && normalState != NULL) {
		normalState->setTexture(normal);
		setContentSize(MAX(normalState->getWidth(), m_width), MAX(normalState->getHeight(), m_height));
	}

	wyNode* selectedState = getNode(STATE_SELECTED);
	if(selected != NULL && selectedState != NULL) {
		selectedState->setTexture(selected);
		setContentSize(MAX(selectedState->getWidth(), m_width), MAX(selectedState->getHeight(), m_height));
	}

	wyNode* disabledState = getNode(STATE_DISABLED);
	if(disabled != NULL && disabledState != NULL) {
		disabledState->setTexture(disabled);
		setContentSize(MAX(disabledState->getWidth(), m_width), MAX(disabledState->getHeight(), m_height));
	}

	wyNode* focusedState = getNode(STATE_FOCUSED);
	if(focused != NULL && focusedState != NULL) {
		focusedState->setTexture(focused);
		setContentSize(MAX(focusedState->getWidth(), m_width), MAX(focusedState->getHeight(), m_height));
	}
}

void wyButton::setTextureRect(wyRect* normalRect, wyRect* selectedRect, wyRect* disabledRect, wyRect* focusedRect) {
	wyNode* normalState = getNode(STATE_NORMAL);
	if(normalState && normalRect) {
		wyTextureNode* tn = dynamic_cast<wyTextureNode*>(normalState);
		if(tn)
			tn->setTextureRect(*normalRect);
	}

	wyNode* selectedState = getNode(STATE_SELECTED);
	if(selectedState && selectedRect) {
		wyTextureNode* tn = dynamic_cast<wyTextureNode*>(selectedState);
		if(tn)
			tn->setTextureRect(*selectedRect);
	}

	wyNode* disabledState = getNode(STATE_DISABLED);
	if(disabledState && disabledRect) {
		wyTextureNode* tn = dynamic_cast<wyTextureNode*>(disabledState);
		if(tn)
			tn->setTextureRect(*disabledRect);
	}

	wyNode* focusedState = getNode(STATE_FOCUSED);
	if(focusedState && focusedRect) {
		wyTextureNode* tn = dynamic_cast<wyTextureNode*>(focusedState);
		if(tn)
			tn->setTextureRect(*focusedRect);
	}
}

void wyButton::setNormalState(wyNode* normal) {
	registerNode(STATE_NORMAL, normal, false);
}

void wyButton::setSelectedState(wyNode* selected) {
	registerNode(STATE_SELECTED, selected, false);
}

void wyButton::setDisabledState(wyNode* disabled) {
	registerNode(STATE_DISABLED, disabled, false);
}

void wyButton::setFocusedState(wyNode* focused) {
	registerNode(STATE_FOCUSED, focused, false);
}

void wyButton::setSelected(bool selected) {
    // subclass to change the default action
    if (m_enabled && selected != m_selected) {
    	wyCompoundNode::setSelected(selected);

    	// get node
    	wyNode* selectedState = getNode(STATE_SELECTED);
    	wyNode* normalState = getNode(STATE_NORMAL);

		// if selected state is null, we auto render pressed state
		if(!selectedState) {
			if(m_selected) {
				m_oldNormalColor = normalState->getColor();
        		wyColorHSV hsv = wyc3b2hsv(m_oldNormalColor);
        		hsv.v = MAX(0, hsv.v - 0.2f);
        		wyColor3B c = wychsv2c3b(hsv);
        		normalState->setColor(c);
			} else {
				normalState->setColor(m_oldNormalColor);
			}
		}

    	// do scale action when click scale is not 1
    	if(m_clickScale != 1.f) {
			if(selected) {
				// if first time, save original scale
				if(m_originalScale == 0) {
					m_originalScale = getScale();
				}

				stopAction(TAG_ZOOM_ACTION);
				wyAction* zoomAction = wyScaleTo::make(0.1f, m_originalScale, m_clickScale);
				zoomAction->setTag(TAG_ZOOM_ACTION);
				runAction(zoomAction);
			} else {
				stopAction(TAG_ZOOM_ACTION);
				wyAction* zoomAction = wyScaleTo::make(0.1f, m_clickScale, m_originalScale);
				zoomAction->setTag(TAG_ZOOM_ACTION);
				runAction(zoomAction);
			}
    	}
    }
}
