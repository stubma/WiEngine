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
#include "wyMenu.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include <stdarg.h>
#include "wyGlobal.h"
#if ANDROID
	#include "wyJNI.h"
#endif

wyMenu::~wyMenu() {
}

wyMenu::wyMenu() :
		m_selectedItem(NULL)  {
	// set position and state
	setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);

	// enable touch
	setTouchEnabled(true);
}

wyMenu::wyMenu(wyMenuItem* item1, ...) :
		m_selectedItem(NULL) {
	// set position and state
	setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);

	// enable touch
	setTouchEnabled(true);

	// add first
	addChildLocked(item1, 0);

	// add others
	int z = 1;
	va_list items;
	va_start(items, item1);
    for(wyMenuItem* item = va_arg(items, wyMenuItem*); item != NULL; item = va_arg(items, wyMenuItem*), z++) {
    	addChildLocked(item, z);
    }
    va_end(items);
}

wyMenu* wyMenu::make() {
	wyMenu* n = WYNEW wyMenu();
	return (wyMenu*)n->autoRelease();
}

wyMenu* wyMenu::make(wyMenuItem* item1, ...) {
	wyMenu* menu = make();

	// add first
	menu->addChildLocked(item1, 0);

	// add others
	int z = 1;
	va_list items;
	va_start(items, item1);
    for(wyMenuItem* item = va_arg(items, wyMenuItem*); item != NULL; item = va_arg(items, wyMenuItem*), z++) {
    	menu->addChildLocked(item, z);
    }
    va_end(items);

    return menu;
}

wyMenuItem* wyMenu::itemForTouch(wyMotionEvent& event) {
	for(int i = 0; i < m_children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(m_children, i);
		wyPoint loc = { event.x[0], event.y[0] };
		loc = child->worldToNodeSpace(loc);
		wyRect r = child->getBoundingBox();
		if(wyrContains(r, loc)) {
			return (wyMenuItem*)child;
		}
	}
	return NULL;
}

bool wyMenu::touchesBegan(wyMotionEvent& e) {
	m_selectedItem = itemForTouch(e);
	if(m_selectedItem != NULL) {
		m_selectedItem->setSelected(true);

		wyTargetSelector* selector = m_selectedItem->getDownSelector();
		if(selector != NULL && m_selectedItem->isEnabled()) {
			m_selectedItem->beforeInvoke(selector);
			selector->invoke();
		}

		return m_interceptTouch;
	}

	return false;
}

bool wyMenu::touchesMoved(wyMotionEvent& e) {
	wyMenuItem* currentItem = itemForTouch(e);
	if(currentItem != m_selectedItem) {
		if(m_selectedItem != NULL) {
			m_selectedItem->setSelected(false);

			wyTargetSelector* selector = m_selectedItem->getMoveOutSelector();
			if(selector != NULL && m_selectedItem->isEnabled()) {
				m_selectedItem->beforeInvoke(selector);
				selector->invoke();
			}
		}
		m_selectedItem = currentItem;
		if(m_selectedItem != NULL) {
			m_selectedItem->setSelected(true);
		}

		return m_interceptTouch;
	}

	return false;
}

bool wyMenu::touchesEnded(wyMotionEvent& e) {
	if(m_selectedItem != NULL) {
		m_selectedItem->setSelected(false);
		wyTargetSelector* selector = m_selectedItem->getUpSelector();
		if(selector != NULL && m_selectedItem->isEnabled()) {
			m_selectedItem->beforeInvoke(selector);
			selector->invoke();
		}

		return m_interceptTouch;
	}

	return false;
}

bool wyMenu::touchesCancelled(wyMotionEvent& e) {
	if(m_selectedItem != NULL) {
		m_selectedItem->setSelected(false);
		return m_interceptTouch;
	}

	return false;
}

bool wyMenu::hitTest(float x, float y) {
	// return true always for menu
	return true;
}

void wyMenu::addMenuItem(wyMenuItem* item) {
	addChildLocked(item, m_children->num);
}

void wyMenu::alignItemsVertically(float padding) {
	float height = -padding;
	for(int i = 0; i < m_children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(m_children, i);
		height += child->getHeight() * child->getScaleY() + padding;
	}

	float y = height / 2.0f;
	for(int i = 0; i < m_children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(m_children, i);
		child->setPosition(0, y - child->getHeight() * child->getScaleY() / 2.0f);
		y -= child->getHeight() * child->getScaleY() + padding;
	}
}

void wyMenu::alignItemsHorizontally(float padding) {
	float width = -padding;
	for(int i = 0; i < m_children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(m_children, i);
		width += child->getWidth() * child->getScaleX() + padding;
	}

	float x = width / 2.0f;
	for(int i = 0; i < m_children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(m_children, i);
		child->setPosition(x - child->getWidth() * child->getScaleX() / 2.0f, 0);
		x -= child->getWidth() * child->getScaleX() + padding;
	}
}

void wyMenu::alignItemsInColumns(int count, int* columns, float padding) {
	int* rows = (int*)wyMalloc(count * sizeof(int));
	memcpy(rows, columns, count * sizeof(int));

	int height = -padding;
	int row = 0, rowHeight = 0, columnsOccupied = 0, rowColumns;
	for(int i = 0; i < m_children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(m_children, i);

		rowColumns = rows[row];

		rowHeight = MAX(rowHeight, child->getHeight());
		++columnsOccupied;

		if(columnsOccupied >= rowColumns) {
			height += rowHeight + padding;

			columnsOccupied = 0;
			rowHeight = 0;
			++row;
		}
	}

	row = 0;
	rowHeight = 0;
	rowColumns = 0;
	float w = 0, x = 0, y = height / 2;
	for(int i = 0; i < m_children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(m_children, i);
		if(rowColumns == 0) {
			rowColumns = rows[row];
			w = wyDevice::winWidth / rowColumns;
			x = w / 2;
		}

		rowHeight = MAX(rowHeight, child->getHeight());
		child->setPosition(x - wyDevice::winWidth / 2, y - child->getHeight() / 2);

		x += w;
		++columnsOccupied;

		if(columnsOccupied >= rowColumns) {
			y -= rowHeight + padding;

			columnsOccupied = 0;
			rowColumns = 0;
			rowHeight = 0;
			++row;
		}
	}

	wyFree(rows);
}

void wyMenu::alignItemsInRows(int count, int* rows, float padding) {
	int* columns = (int*)wyMalloc(count * sizeof(int));
	memcpy(columns, rows, count * sizeof(int));

	int* columnWidths = (int*)wyCalloc(count, sizeof(int));
	int* columnHeights = (int*)wyCalloc(count, sizeof(int));
	int sizeIndex = 0;

	int width = -padding, columnHeight = -5;
	int column = 0, columnWidth = 0, rowsOccupied = 0, columnRows;
	for(int i = 0; i < m_children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(m_children, i);

		columnRows = columns[column];

		columnWidth = MAX(columnWidth, child->getWidth());
		columnHeight += child->getHeight() + 5;
		++rowsOccupied;

		if(rowsOccupied >= columnRows) {
			columnWidths[sizeIndex] = columnWidth;
			columnHeights[sizeIndex++] = columnHeight;
			width += columnWidth + padding;

			rowsOccupied = 0;
			columnWidth = 0;
			columnHeight = -5;
			++column;
		}
	}

	column = 0;
	columnWidth = 0;
	columnRows = 0;
	float x = -width / 2, y = 0;
	for(int i = 0; i < m_children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(m_children, i);
		if(columnRows == 0) {
			columnRows = columns[column];
			y = columnHeights[column] + wyDevice::winHeight / 2;
		}

		columnWidth = MAX(columnWidth, child->getWidth());
		child->setPosition(x + columnWidths[column] / 2, y - wyDevice::winHeight / 2);

		y -= child->getHeight() + 5;
		++rowsOccupied;

		if(rowsOccupied >= columnRows) {
			x += columnWidth + padding;

			rowsOccupied = 0;
			columnRows = 0;
			columnWidth = 0;
			++column;
		}
	}

	wyFree(columns);
	wyFree(columnWidths);
	wyFree(columnHeights);
}
