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
#include "wySPXSprite.h"
#include "wySPXManager.h"

wySPXSprite::wySPXSprite() :
		m_spx(NULL) {
}

wySPXSprite::~wySPXSprite() {
	wyObjectRelease(m_spx);
}

wySPXSprite* wySPXSprite::make(int spxResId, wyTexture2D* tex, int actionIndex) {
	// create sprite
	wySPXSprite* s = WYNEW wySPXSprite();

	// get spx file data
	s->m_spx = wySPXManager::getInstance()->load(spxResId);
	s->m_spx->retain();

	// create batch node for texture
	wySpriteBatchNode* sheet = wySpriteBatchNode::make(tex);
	wyArrayPush(s->m_sheetList, sheet);
	sheet->retain();

	// start action
	s->playAnimation(actionIndex);

	// return
	return (wySPXSprite*)s->autoRelease();
}

wySPXSprite* wySPXSprite::make(const char* spxPath, bool isFile, wyTexture2D* tex, int actionIndex) {
	// create sprite
	wySPXSprite* s = WYNEW wySPXSprite();

	// get spx file data
	s->m_spx = wySPXManager::getInstance()->load(spxPath, isFile);
	s->m_spx->retain();

	// create batch node for texture
	wySpriteBatchNode* sheet = wySpriteBatchNode::make(tex);
	wyArrayPush(s->m_sheetList, sheet);
	sheet->retain();

	// start action
	s->playAnimation(actionIndex);

	// return
	return (wySPXSprite*)s->autoRelease();
}

wyAFCAnimation* wySPXSprite::getAnimationAt(int index, wyAFCClipMapping* mapping) {
	if(index < 0 || index >= getAnimationCount())
		return NULL;
	else
		return wySPXManager::getInstance()->getAnimationData(m_spx, index, mapping);
}

int wySPXSprite::getAnimationCount() {
	return m_spx->m_actionCount;
}

int wySPXSprite::getImageCount() {
	return 1;
}
