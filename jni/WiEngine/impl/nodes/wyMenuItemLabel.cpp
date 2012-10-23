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
#include "wyMenuItemLabel.h"
#include <stdlib.h>

wyMenuItemLabel::~wyMenuItemLabel() {
}

wyMenuItemLabel* wyMenuItemLabel::make(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wyLabel* label) {
	wyMenuItemLabel* n = WYNEW wyMenuItemLabel(downSelector, upSelector, label);
	return (wyMenuItemLabel*)n->autoRelease();
}

void wyMenuItemLabel::setEnabled(bool enabled) {
    if (m_enabled != enabled) {
        if (!enabled) {
			wyColor3B c = {
				m_disabledColor.r,
				m_disabledColor.g,
				m_disabledColor.b
			};
			getStateNode()->setColor(c);
        } else {
			wyColor3B c = {
				m_normalColor.r,
				m_normalColor.g,
				m_normalColor.b
			};
			getStateNode()->setColor(c);
        }
    }

    wyMenuItem::setEnabled(enabled);
}

void wyMenuItemLabel::beforeInvoke(wyTargetSelector* ts) {
	if(ts == m_upSelector) {
		stopAllActions(false);
		setScale(1.0f);
	}
}

void wyMenuItemLabel::setAlpha(int alpha) {
	wyMenuItem::setAlpha(alpha);

	// set alpha
	m_normalColor.a = alpha;
}

wyColor3B wyMenuItemLabel::getColor() {
	wyColor3B c = {
		m_normalColor.r,
		m_normalColor.b,
		m_normalColor.b
	};
	return c;
}

void wyMenuItemLabel::setColor(wyColor3B color) {
	wyMenuItem::setColor(color);

	m_normalColor.r = color.r;
	m_normalColor.g = color.g;
	m_normalColor.b = color.b;
}

void wyMenuItemLabel::setColor(wyColor4B color) {
	wyMenuItem::setColor(color);

	m_normalColor.r = color.r;
	m_normalColor.g = color.g;
	m_normalColor.b = color.b;
	m_normalColor.a = color.a;
}

void wyMenuItemLabel::setDisabledColor(wyColor3B color) {
	m_disabledColor.r = color.r;
	m_disabledColor.g = color.g;
	m_disabledColor.b = color.b;
}

wyColor3B wyMenuItemLabel::getDisabledColor() {
	wyColor3B c = {
		m_disabledColor.r,
		m_disabledColor.g,
		m_disabledColor.b
	};
	return c;
}

wyMenuItemLabel::wyMenuItemLabel(wyTargetSelector* downSelector, wyTargetSelector* upSelector, wyLabel* label) :
		wyMenuItem(downSelector, upSelector),
		m_normalColor(wyc4bWhite),
		m_disabledColor(wyc4bGray) {
	setLabel(label);
}

void wyMenuItemLabel::setLabel(wyLabel* label) {
	registerNode(0, label, false);
}
