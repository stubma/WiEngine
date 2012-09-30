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
#include "wyScene.h"
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyDirector.h"

wyScene* wyScene::make() {
	wyScene* scene = WYNEW wyScene();
	return (wyScene*)scene->autoRelease();
}

wyScene::wyScene() : m_backKeyTracing(false) {
	setContentSize(wyDevice::winWidth, wyDevice::winHeight);
	setRelativeAnchorPoint(false);

	// we need a node which can handle back key, so the scene is
	// the best candidate
	setKeyEnabled(true);
}

wyScene::~wyScene() {
}

bool wyScene::keyDown(wyKeyEvent& event) {
	switch(event.keyCode) {
		case KEYCODE_BACK:
			m_backKeyTracing = true;
			return true;
	}

	return wyNode::keyDown(event);
}

bool wyScene::keyUp(wyKeyEvent& event) {
	switch(event.keyCode) {
		case KEYCODE_BACK:
			if(m_backKeyTracing) {
				wyDirector::getInstance()->popScene();
				m_backKeyTracing = false;
				return true;
			} else {
				return false;
			}
	}

	return wyNode::keyUp(event);
}
