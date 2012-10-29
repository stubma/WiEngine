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
#include "wyArcticSprite.h"
#include "wyArcticManager.h"
#include "wySpriteBatchNode.h"
#include <stdarg.h>

wyArcticSprite::wyArcticSprite() :
		m_arctic(NULL) {
}

wyArcticSprite::~wyArcticSprite() {
	wyObjectRelease(m_arctic);
}

wyArcticSprite* wyArcticSprite::make(int asResId, int animIndex, wyTexture2D** tex, int count) {
	// create arctic sprite
	wyArcticSprite* sprite = WYNEW wyArcticSprite();

	// load anu file data
	sprite->m_arctic = wyArcticManager::getInstance()->load(asResId);
	sprite->m_arctic->retain();

	// add others
	for(int i = 0; i < count; i++) {
		wySpriteBatchNode* sheet = wySpriteBatchNode::make(tex[i]);
		wyArrayPush(sprite->m_sheetList, sheet);
		sheet->retain();
	}

	// start animation
	sprite->playAnimation(animIndex);

	// return
	sprite->autoRelease();
	return sprite;
}

wyArcticSprite* wyArcticSprite::make(int asResId, int animIndex, wyTexture2D* tex, ...) {
	// create arctic sprite
	wyArcticSprite* sprite = WYNEW wyArcticSprite();

	// load anu file data
	sprite->m_arctic = wyArcticManager::getInstance()->load(asResId);
	sprite->m_arctic->retain();

	va_list textures;
	va_start(textures, tex);

	// add first
	wySpriteBatchNode* sheet = wySpriteBatchNode::make(tex);
	wyArrayPush(sprite->m_sheetList, sheet);
	sheet->retain();

	// add others
	for(wyTexture2D* t = va_arg(textures, wyTexture2D*); t != NULL; t = va_arg(textures, wyTexture2D*)) {
		sheet = wySpriteBatchNode::make(t);
		wyArrayPush(sprite->m_sheetList, sheet);
		sheet->retain();
	}

	va_end(textures);

	// start animation
	sprite->playAnimation(animIndex);

	// return
	sprite->autoRelease();
	return sprite;
}

wyArcticSprite* wyArcticSprite::make(const char* path, bool isFile, int animIndex, wyTexture2D** tex, int count) {
	// create arctic sprite
	wyArcticSprite* sprite = WYNEW wyArcticSprite();

	// load anu file data
	sprite->m_arctic = wyArcticManager::getInstance()->load(path, isFile);
	sprite->m_arctic->retain();

	// add others
	for(int i = 0; i < count; i++) {
		wySpriteBatchNode* sheet = wySpriteBatchNode::make(tex[i]);
		wyArrayPush(sprite->m_sheetList, sheet);
		sheet->retain();
	}

	// start animation
	sprite->playAnimation(animIndex);

	// return
	sprite->autoRelease();
	return sprite;
}

wyArcticSprite* wyArcticSprite::make(const char* path, bool isFile, int animIndex, wyTexture2D* tex, ...) {
	// create arctic sprite
	wyArcticSprite* sprite = WYNEW wyArcticSprite();

	// load anu file data
	sprite->m_arctic = wyArcticManager::getInstance()->load(path, isFile);
	sprite->m_arctic->retain();

	va_list textures;
	va_start(textures, tex);

	// add first
	wySpriteBatchNode* sheet = wySpriteBatchNode::make(tex);
	wyArrayPush(sprite->m_sheetList, sheet);
	sheet->retain();

	// add others
	for(wyTexture2D* t = va_arg(textures, wyTexture2D*); t != NULL; t = va_arg(textures, wyTexture2D*)) {
		sheet = wySpriteBatchNode::make(t);
		wyArrayPush(sprite->m_sheetList, sheet);
		sheet->retain();
	}

	va_end(textures);

	// start animation
	sprite->playAnimation(animIndex);

	// return
	sprite->autoRelease();
	return sprite;
}

wyArcticSprite* wyArcticSprite::make(const char* mfsName, int animIndex, wyTexture2D* tex, ...) {
	// create arctic sprite
	wyArcticSprite* sprite = WYNEW wyArcticSprite();

	// load anu file data
	sprite->m_arctic = wyArcticManager::getInstance()->load(mfsName);
	sprite->m_arctic->retain();

	va_list textures;
	va_start(textures, tex);

	// add first
	wySpriteBatchNode* sheet = wySpriteBatchNode::make(tex);
	wyArrayPush(sprite->m_sheetList, sheet);
	sheet->retain();

	// add others
	for(wyTexture2D* t = va_arg(textures, wyTexture2D*); t != NULL; t = va_arg(textures, wyTexture2D*)) {
		sheet = wySpriteBatchNode::make(t);
		wyArrayPush(sprite->m_sheetList, sheet);
		sheet->retain();
	}

	va_end(textures);

	// start animation
	sprite->playAnimation(animIndex);

	// return
	sprite->autoRelease();
	return sprite;
}

wyAFCAnimation* wyArcticSprite::getAnimationAt(int index, wyAFCClipMapping* mapping) {
	if(index < 0 || index >= getAnimationCount())
		return NULL;
	else
		return wyArcticManager::getInstance()->getAnimationData(m_arctic, index, mapping);
}

int wyArcticSprite::getAnimationCount() {
	return m_arctic->m_animationCount;
}

int wyArcticSprite::getImageCount() {
	return 1;
}
