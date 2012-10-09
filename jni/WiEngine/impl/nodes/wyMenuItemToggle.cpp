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
#include "wyMenuItemToggle.h"
#include <stdlib.h>
#include <stdarg.h>
#include "wyLog.h"

bool wyMenuItemToggle::releaseItem(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyNode*)ptr);
	return true;
}

wyMenuItemToggle::~wyMenuItemToggle() {
	removeChildByTagLocked(TAG_CURRENT_ITEM, false);
	wyArrayEach(m_items, releaseItem, NULL);
	wyArrayClear(m_items);
	wyArrayDestroy(m_items);
}

void wyMenuItemToggle::beforeInvoke(wyTargetSelector* ts) {
	if(ts == m_upSelector) {
		int newIndex = (m_selectedIndex + 1) % m_items->num;
		setSelectedIndex(newIndex);
	}
}

void wyMenuItemToggle::setAlpha(int alpha) {
	for(int i = 0; i < m_items->num; i++) {
		wyMenuItem* item = (wyMenuItem*)wyArrayGet(m_items, i);
		item->setAlpha(alpha);
	}
}

wyColor3B wyMenuItemToggle::getColor() {
	wyColor3B c = {
		m_color.r,
		m_color.g,
		m_color.b
	};
	return c;
}

void wyMenuItemToggle::setColor(wyColor3B color) {
	for(int i = 0; i < m_items->num; i++) {
		wyMenuItem* item = (wyMenuItem*)wyArrayGet(m_items, i);
		item->setColor(color);
	}
}

void wyMenuItemToggle::setColor(wyColor4B color) {
	for(int i = 0; i < m_items->num; i++) {
		wyMenuItem* item = (wyMenuItem*)wyArrayGet(m_items, i);
		item->setColor(color);
	}
}

void wyMenuItemToggle::setEnabled(bool enabled) {
	wyMenuItem::setEnabled(enabled);
	for(int i = 0; i < m_items->num; i++) {
		wyNode* item = (wyNode*)wyArrayGet(m_items, i);
		item->setEnabled(enabled);
	}
}

void wyMenuItemToggle::setSelected(bool selected) {
	wyNode* item = (wyNode*)wyArrayGet(m_items, m_selectedIndex);
	item->setSelected(selected);
}

wyMenuItemToggle::wyMenuItemToggle(wyTargetSelector* downSelector, wyTargetSelector* upSelector, ...) :
		wyMenuItem(downSelector, upSelector),
		m_selectedIndex(-1),
		m_items(wyArrayNew(3)),
		m_color(wyc4bWhite) {
	// add all menu items
	va_list menuitems;
	va_start(menuitems, upSelector);
    for(wyMenuItem* child = va_arg(menuitems, wyMenuItem*); child != NULL; child = va_arg(menuitems, wyMenuItem*)) {
    	wyArrayPush(m_items, child);
    	wyObjectRetain(child);
    }
	va_end(menuitems);

	// set first item as selected
	setSelectedIndex(0);
}

wyMenuItemToggle* wyMenuItemToggle::make(wyTargetSelector* downSelector, wyTargetSelector* upSelector, ...) {
	wyMenuItemToggle* toggle = WYNEW wyMenuItemToggle(downSelector, upSelector, NULL);

	// add all menu items
	va_list menuitems;
	va_start(menuitems, upSelector);
    for(wyMenuItem* child = va_arg(menuitems, wyMenuItem*); child != NULL; child = va_arg(menuitems, wyMenuItem*)) {
    	wyArrayPush(toggle->m_items, child);
    	wyObjectRetain(child);
    }
	va_end(menuitems);

	// set first item as selected
	toggle->setSelectedIndex(0);

	return (wyMenuItemToggle*)toggle->autoRelease();
}

void wyMenuItemToggle::setSelectedIndex(int index) {
    if (index != m_selectedIndex && index >= 0 && index < m_items->num) {
    	m_selectedIndex = index;
    	removeChildByTagLocked(TAG_CURRENT_ITEM, false);

        wyNode* child = (wyNode*)wyArrayGet(m_items, m_selectedIndex);
        addChildLocked(child, 0, TAG_CURRENT_ITEM);

        float width = child->getWidth();
        float height = child->getHeight();

        setContentSize(width, height);
        child->setPosition(width / 2, height / 2);
    }
}

void wyMenuItemToggle::addMenuItem(wyMenuItem* item) {
	wyArrayPush(m_items, item);
	wyObjectRetain(item);
}
