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
#include "wyMultiplexLayer.h"
#include "wyLog.h"
#include <stdlib.h>

bool wyMultiplexLayer::releaseLayer(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyNode*)ptr);
	return true;
}

wyMultiplexLayer::~wyMultiplexLayer() {
	wyArrayEach(m_layers, releaseLayer, NULL);
	wyArrayClear(m_layers);
	wyArrayDestroy(m_layers);
}

// create layer
wyMultiplexLayer::wyMultiplexLayer() :
		m_layers(wyArrayNew(3)),
		m_enabledLayer(-1) {
}

wyMultiplexLayer* wyMultiplexLayer::make() {
	wyMultiplexLayer* n = WYNEW wyMultiplexLayer();
	return (wyMultiplexLayer*)n->autoRelease();
}

void wyMultiplexLayer::addLayer(wyLayer* layer) {
	wyArrayPush(m_layers, layer);
	wyObjectRetain(layer);

	// add
	if(m_enabledLayer == -1) {
		m_enabledLayer = 0;
		addChildLocked(layer);
	}
}

void wyMultiplexLayer::removeLayer(int index) {
	if(index < 0 || index >= m_layers->num) {
		LOGW("wyMultiplexLayerRemoveLayer: index is out of bound");
		return;
	}

	if(m_layers->num < 2) {
		LOGW("You can't remove layer when there is only one left");
		return;
	}

	wyLayer* layer = (wyLayer*)wyArrayDeleteIndex(m_layers, index);
	wyObjectRelease(layer);
	if(index == m_enabledLayer) {
		removeChildLocked(layer, false);

		m_enabledLayer = 0;
		layer = (wyLayer*)wyArrayGet(m_layers, m_enabledLayer);
		addChildLocked(layer);
	}
}

void wyMultiplexLayer::switchTo(int index) {
	if(index < 0)
		return;

	// mod index
	index %= m_layers->num;

	// remove current layer first
	wyLayer* layer = (wyLayer*)wyArrayGet(m_layers, m_enabledLayer);
	removeChildLocked(layer, false);

	// add specified layer
	m_enabledLayer = index;
    layer = (wyLayer*)wyArrayGet(m_layers, index);
    addChildLocked(layer);
}
