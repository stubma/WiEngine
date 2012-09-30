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

wyButton* wyButton::make(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyTargetSelector* downSelector, wyTargetSelector* upSelector) {
	wyButton* n = WYNEW wyButton(normal, selected, disabled, focused, downSelector, upSelector);
	return (wyButton*)n->autoRelease();
}

int wyButton::getAlpha() {
    if(m_normalState != NULL)
	    return m_normalState->getAlpha();

	if(m_selectedState != NULL)
		return m_selectedState->getAlpha();

	if(m_disabledState != NULL)
		return m_disabledState->getAlpha();

	if(m_focusedState != NULL)
		return m_focusedState->getAlpha();

    return -1;
}

void wyButton::setAlpha(int alpha) {
    if(m_normalState != NULL) {
	    m_normalState->setAlpha(alpha);
    }

	if(m_selectedState != NULL) {
		m_selectedState->setAlpha(alpha);
	}

	if(m_disabledState != NULL) {
		m_disabledState->setAlpha(alpha);
	}

	if(m_focusedState != NULL) {
		m_focusedState->setAlpha(alpha);
	}
}

wyColor3B wyButton::getColor() {
    if(m_normalState != NULL) {
	    return m_normalState->getColor();
    }

	if(m_selectedState != NULL) {
		return m_selectedState->getColor();
	}

	if(m_disabledState != NULL) {
		return m_disabledState->getColor();
	}
	
	if(m_focusedState != NULL) {
		return m_focusedState->getColor();
	}

	return wyc3bWhite;
}

void wyButton::setColor(wyColor3B color) {
    if(m_normalState != NULL) {
	    m_normalState->setColor(color);
    }

	if(m_selectedState != NULL) {
		m_selectedState->setColor(color);
	}

	if(m_disabledState != NULL) {
		m_disabledState->setColor(color);
	}
	if(m_focusedState != NULL) {
		m_focusedState->setColor(color);
	}
}

void wyButton::setColor(wyColor4B color) {
    if(m_normalState != NULL) {
	    m_normalState->setColor(color);
    }

	if(m_selectedState != NULL) {
		m_selectedState->setColor(color);
	}

	if(m_disabledState != NULL) {
		m_disabledState->setColor(color);
	}
	if(m_focusedState != NULL) {
		m_focusedState->setColor(color);
	}
}

wyButton::~wyButton() {
	wyObjectRelease(m_normalState);
	wyObjectRelease(m_selectedState);
	wyObjectRelease(m_disabledState);
	wyObjectRelease(m_focusedState);
}

void wyButton::onEnter() {
	wyNode::onEnter();

	if(m_normalState != NULL)
		m_normalState->onEnter();
	if(m_selectedState != NULL)
		m_selectedState->onEnter();
	if(m_disabledState != NULL)
		m_disabledState->onEnter();
	if(m_focusedState != NULL)
		m_focusedState->onEnter();
}

void wyButton::onExit() {
	wyNode::onExit();

	if(m_normalState != NULL)
		m_normalState->onExit();
	if(m_selectedState != NULL)
		m_selectedState->onExit();
	if(m_disabledState != NULL)
		m_disabledState->onExit();
	if(m_focusedState != NULL)
		m_focusedState->onExit();
}

void wyButton::draw() {
	// if no draw flag is set, call wyNode::draw and it
	// will decide forward drawing to java layer or not
	if(m_noDraw) {
		wyNode::draw();
		return;
	}

	bool autoRenderPress = false;
	wyNode* node = NULL;
    if (m_enabled) {
        if (m_selected) {
        	if(m_selectedState != NULL)
        		node = m_selectedState;
        	else {
        		autoRenderPress = true;
        		node = m_normalState;
        	}
        } else if (m_focused) {
        	if(m_focusedState != NULL)
				node = m_focusedState;
			else
				node = m_normalState;
        } else
        	node = m_normalState;
    } else {
        if (m_disabledState != NULL)
        	node = m_disabledState;
        else
        	node = m_normalState;
    }
    
    if(node) {
        glTranslatef((getWidth() - node->getWidth()) / 2, (getHeight() - node->getHeight()) / 2, 0);

        // if need auto render pressed state, save old color and degrade brightness for node
        wyColor3B oldColor = node->getColor();
        if(autoRenderPress) {
        	wyColorHSV hsv = wyc3b2hsv(oldColor);
        	hsv.v = MAX(0, hsv.v - 0.2f);
        	wyColor3B c = wychsv2c3b(hsv);
        	node->setColor(c);
        }

        // draw node
        node->draw();

        // restore color
        if(autoRenderPress) {
        	node->setColor(oldColor);
        }
    }
}

void wyButton::setRotation(float rot) {
	wyNode::setRotation(rot);
    if(m_normalState != NULL)
	    m_normalState->setRotation(rot);
	if(m_selectedState != NULL)
		m_selectedState->setRotation(rot);
	if(m_disabledState != NULL)
		m_disabledState->setRotation(rot);
	if(m_focusedState != NULL)
		m_focusedState->setRotation(rot);
}

void wyButton::setScale(float scale) {
	wyNode::setScale(scale);
    if(m_normalState != NULL)
	    m_normalState->setScale(scale);
	if(m_selectedState != NULL)
		m_selectedState->setScale(scale);
	if(m_disabledState != NULL)
		m_disabledState->setScale(scale);
	if(m_focusedState != NULL)
		m_focusedState->setScale(scale);
}

void wyButton::setScaleX(float scaleX) {
	wyNode::setScaleX(scaleX);
    if(m_normalState != NULL)
	    m_normalState->setScaleX(scaleX);
	if(m_selectedState != NULL)
		m_selectedState->setScaleX(scaleX);
	if(m_disabledState != NULL)
		m_disabledState->setScaleX(scaleX);
	if(m_focusedState != NULL)
		m_focusedState->setScaleX(scaleX);
}

void wyButton::setScaleY(float scaleY) {
	wyNode::setScaleY(scaleY);
    if(m_normalState != NULL)
	    m_normalState->setScaleY(scaleY);
	if(m_selectedState != NULL)
		m_selectedState->setScaleY(scaleY);
	if(m_disabledState != NULL)
		m_disabledState->setScaleY(scaleY);
	if(m_focusedState != NULL)
		m_focusedState->setScaleY(scaleY);
}

wyButton::wyButton(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyTargetSelector* downSelector, wyTargetSelector* upSelector) :
		m_clickScale(1.f),
		m_originalScale(0.f),
		m_normalState(NULL),
		m_selectedState(NULL),
		m_disabledState(NULL),
		m_focusedState(NULL) {
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
	if(normal != NULL && m_normalState != NULL) {
		m_normalState->setTexture(normal);
		setContentSize(MAX(m_normalState->getWidth(), m_width), MAX(m_normalState->getHeight(), m_height));
	}

	if(selected != NULL && m_selectedState != NULL) {
		m_selectedState->setTexture(selected);
		setContentSize(MAX(m_selectedState->getWidth(), m_width), MAX(m_selectedState->getHeight(), m_height));
	}

	if(disabled != NULL && m_disabledState != NULL) {
		m_disabledState->setTexture(disabled);
		setContentSize(MAX(m_disabledState->getWidth(), m_width), MAX(m_disabledState->getHeight(), m_height));
	}

	if(focused != NULL && m_focusedState != NULL) {
		m_focusedState->setTexture(focused);
		setContentSize(MAX(m_focusedState->getWidth(), m_width), MAX(m_focusedState->getHeight(), m_height));
	}
}

void wyButton::setTextureRect(wyRect* normalRect, wyRect* selectedRect, wyRect* disabledRect, wyRect* focusedRect) {
	if(m_normalState && normalRect) {
		wyTextureNode* tn = dynamic_cast<wyTextureNode*>(m_normalState);
		wySpriteEx* se = dynamic_cast<wySpriteEx*>(m_normalState);
		if(tn)
			tn->setTextureRect(*normalRect);
		if(se)
			se->setTextureRect(*normalRect);
	}

	if(m_selectedState && selectedRect) {
		wyTextureNode* tn = dynamic_cast<wyTextureNode*>(m_selectedState);
		wySpriteEx* se = dynamic_cast<wySpriteEx*>(m_selectedState);
		if(tn)
			tn->setTextureRect(*selectedRect);
		if(se)
			se->setTextureRect(*selectedRect);
	}

	if(m_disabledState && disabledRect) {
		wyTextureNode* tn = dynamic_cast<wyTextureNode*>(m_disabledState);
		wySpriteEx* se = dynamic_cast<wySpriteEx*>(m_disabledState);
		if(tn)
			tn->setTextureRect(*disabledRect);
		if(se)
			se->setTextureRect(*disabledRect);
	}

	if(m_focusedState && focusedRect) {
		wyTextureNode* tn = dynamic_cast<wyTextureNode*>(m_focusedState);
		wySpriteEx* se = dynamic_cast<wySpriteEx*>(m_focusedState);
		if(tn)
			tn->setTextureRect(*focusedRect);
		if(se)
			se->setTextureRect(*focusedRect);
	}
}

void wyButton::setNormalState(wyNode* normal) {
	wyObjectRetain(normal);
	wyObjectRelease(m_normalState);
	m_normalState = normal;
}

void wyButton::setSelectedState(wyNode* selected) {
	wyObjectRetain(selected);
	wyObjectRelease(m_selectedState);
	m_selectedState = selected;
}

void wyButton::setDisabledState(wyNode* disabled) {
	wyObjectRetain(disabled);
	wyObjectRelease(m_disabledState);
	m_disabledState = disabled;
}

void wyButton::setFocusedState(wyNode* focused) {
	wyObjectRetain(focused);
	wyObjectRelease(m_focusedState);
	m_focusedState = focused;
}

void wyButton::setSelected(bool selected) {
    // subclass to change the default action
    if (m_enabled && selected != m_selected) {
    	wyNode::setSelected(selected);

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
