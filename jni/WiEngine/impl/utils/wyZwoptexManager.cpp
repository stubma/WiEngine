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
#include "wyZwoptexManager.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"

wyZwoptexManager* gZwoptexManager;

wyZwoptexManager* wyZwoptexManager::getInstance() {
	if(gZwoptexManager == NULL)
		gZwoptexManager = WYNEW wyZwoptexManager();
	return gZwoptexManager;
}

wyZwoptexManager::wyZwoptexManager() :
		m_cache(WYNEW WY_ZWOPTEX_MAP()) {
}

wyZwoptexManager::~wyZwoptexManager() {
	for(WY_ZWOPTEX_ITER iter = m_cache->begin(); iter != m_cache->end(); iter++) {
		wyFree((void*)iter->first);
		iter->second->release();
	}
	WYDELETE(m_cache);

	gZwoptexManager = NULL;
}


wyZwoptexFrame* wyZwoptexManager::findFrame(const char* frameName, wyZwoptex** outZwoptex, char** outName) {
	for(WY_ZWOPTEX_ITER iter = m_cache->begin(); iter != m_cache->end(); iter++) {
		wyZwoptexFrame* f = iter->second->getFrame(frameName);
		if(f) {
			if(outZwoptex)
				*outZwoptex = iter->second;
			if(outName)
				*outName = (char*)iter->first;
			return f;
		}
	}
	return NULL;
}

wySpriteFrame* wyZwoptexManager::findSpriteFrame(const char* frameName) {
	for(WY_ZWOPTEX_ITER iter = m_cache->begin(); iter != m_cache->end(); iter++) {
		wySpriteFrame* f = iter->second->getSpriteFrame(frameName);
		if(f)
			return f;
	}
	return NULL;
}

void wyZwoptexManager::addZwoptex(const char* name, int resId, wyTexture2D* tex) {
	if(!hasZwoptex(name)) {
		wyZwoptex* z = WYNEW wyZwoptex(resId);
		z->setTexture(tex);
		(*m_cache)[wyUtils::copy(name)] = z;
	}
}

void wyZwoptexManager::addZwoptex(const char* name, const char* path, bool isFile, wyTexture2D* tex, float inDensity) {
	if(!hasZwoptex(name)) {
		wyZwoptex* z = WYNEW wyZwoptex(path, isFile, inDensity);
		z->setTexture(tex);
		(*m_cache)[wyUtils::copy(name)] = z;
	}
}

wyZwoptex* wyZwoptexManager::getZwoptex(const char* name) {
	return (*m_cache)[name];
}

void wyZwoptexManager::removeZwoptex(const char* name) {
	WY_ZWOPTEX_ITER iter = m_cache->find(name);
	if(iter != m_cache->end()) {
		wyFree((void*)iter->first);
		iter->second->release();
		m_cache->erase(iter);
	}
}

void wyZwoptexManager::removeAllZwoptex() {
	for(WY_ZWOPTEX_ITER iter = m_cache->begin(); iter != m_cache->end(); iter++) {
		wyFree((void*)iter->first);
		iter->second->release();
	}
	m_cache->clear();
}

bool wyZwoptexManager::hasZwoptex(const char* name) {
	return m_cache->find(name) != m_cache->end();
}

const char** wyZwoptexManager::getFrameNames(const char* name, size_t* count) {
	wyZwoptex* z = getZwoptex(name);
	if(z) {
		return z->getFrameNames(count);
	} else {
		*count = 0;
		return NULL;
	}
}

wyRect wyZwoptexManager::getFrameRect(const char* zwoptexName, const char* frameName) {
	wyZwoptex* z = getZwoptex(zwoptexName);
	return z == NULL ? wyrZero : z->getFrameRect(frameName);
}

wyRect wyZwoptexManager::getFrameRect(const char* frameName) {
	wyZwoptexFrame* f = findFrame(frameName);
	return f == NULL ? wyrZero : f->rect;
}

wyRect* wyZwoptexManager::getFrameRects(const char* zwoptexName, size_t* count) {
	wyZwoptex* z = getZwoptex(zwoptexName);
	return z == NULL ? NULL : z->getFrameRects(count);
}

int wyZwoptexManager::getFrameCount(const char* zwoptexName) {
	wyZwoptex* z = getZwoptex(zwoptexName);
	return z == NULL ? 0 : z->getFrameCount();
}

wyZwoptexFrame* wyZwoptexManager::getZwoptexFrame(const char* frameName) {
	return findFrame(frameName);
}

wyZwoptexFrame* wyZwoptexManager::getZwoptexFrame(const char* zwoptexName, const char* frameName) {
	wyZwoptex* zwoptex = getZwoptex(zwoptexName);
	if(zwoptex != NULL)
		return zwoptex->getFrame(frameName);
	else
		return NULL;
}

wySpriteFrame* wyZwoptexManager::getSpriteFrame(const char* frameName) {
	return findSpriteFrame(frameName);
}

wySpriteFrame* wyZwoptexManager::getSpriteFrame(const char* zwoptexName, const char* frameName) {
	wyZwoptex* zwoptex = getZwoptex(zwoptexName);
	if(zwoptex != NULL)
		return zwoptex->getSpriteFrame(frameName);
	else
		return NULL;
}

wySprite* wyZwoptexManager::makeSprite(const char* zwoptexName, const char* frameName, wyTexture2D* tex) {
	wyZwoptex* z = getZwoptex(zwoptexName);
	if(z == NULL) {
		LOGW("makeSprite: didn't find zwoptex whose name is %s", zwoptexName);
		return NULL;
	} else {
		wyZwoptexFrame* f = z->getFrame(frameName);
		if(f == NULL) {
			LOGW("makeSprite: didn't find zwoptex frame whose name is %s", frameName);
			return NULL;
		} else {
			if(tex == NULL) {
				if(z->getTexture() == NULL) {
					LOGW("makeSprite: zwoptex %s doesn't has bound texture", zwoptexName);
					return NULL;
				} else {
					wySprite* sprite = WYNEW wySprite(z->getTexture(), f);
					return (wySprite*)sprite->autoRelease();
				}
			} else {
				wySprite* sprite = WYNEW wySprite(tex, f);
				return (wySprite*)sprite->autoRelease();
			}
		}
	}
}

wySprite* wyZwoptexManager::makeSprite(const char* frameName) {
	wyZwoptex* z = NULL;
	char* name = NULL;
	wyZwoptexFrame* f = findFrame(frameName, &z, &name);
	if(f == NULL) {
		return NULL;
	} else if(z->getTexture() == NULL) {
		LOGW("findSprite: zwoptex %s doesn't has bound texture", name);
		return NULL;
	} else {
		return wySprite::make(z->getTexture(), f);
	}
}

wyButton* wyZwoptexManager::makeButton(const char* zwoptexName, const char* frameName, wyTargetSelector* ts, wyTexture2D* tex) {
	wySprite* sprite = makeSprite(zwoptexName, frameName, tex);
	if(sprite)
		return wyButton::make(sprite, NULL, NULL, NULL, NULL, ts);
	else
		return NULL;
}

wyButton* wyZwoptexManager::makeButton(const char* frameName, wyTargetSelector* ts) {
	wySprite* sprite = makeSprite(frameName);
	if(sprite)
		return wyButton::make(sprite, NULL, NULL, NULL, NULL, ts);
	else
		return NULL;
}

wySpriteEx* wyZwoptexManager::makeSpriteEx(const char* zwoptexName, const char* frameName, wyTexture2D* tex) {
	wyZwoptex* z = getZwoptex(zwoptexName);
	if(z == NULL) {
		LOGW("makeSpriteEx: didn't find zwoptex whose name is %s", zwoptexName);
		return NULL;
	} else {
		wyZwoptexFrame* f = z->getFrame(frameName);
		if(f == NULL) {
			LOGW("makeSpriteEx: didn't find zwoptex frame whose name is %s", frameName);
			return NULL;
		} else {
			if(tex == NULL) {
				if(z->getTexture() == NULL) {
					LOGW("makeSpriteEx: zwoptex %s doesn't has bound texture", zwoptexName);
					return NULL;
				} else {
					wySpriteEx* sprite = WYNEW wySpriteEx(z->getTexture(), f);
					return (wySpriteEx*)sprite->autoRelease();
				}
			} else {
				wySpriteEx* sprite = WYNEW wySpriteEx(tex, f);
				return (wySpriteEx*)sprite->autoRelease();
			}
		}
	}
}

wySpriteEx* wyZwoptexManager::makeSpriteEx(const char* frameName, int zi, wySpriteBatchNode * batch) {
	wyZwoptex* z = NULL;
	char* name = NULL;
	wyZwoptexFrame* f = findFrame(frameName, &z, &name);
	if(f == NULL) {
		return NULL;
	} else if(z->getTexture() == NULL) {
		LOGW("findSpriteEx: zwoptex %s doesn't has bound texture", name);
		return NULL;
	} else if (batch == NULL) {
		return wySpriteEx::make(z->getTexture(), f);
	} else {
        return wySpriteEx::make(batch, f, zi);
    }
}


wySpriteEx* wyZwoptexManager::makeSpriteEx(const char* zwoptexName, const char* frameName, int zi, wySpriteBatchNode * batch) {
    wyZwoptex* z = getZwoptex(zwoptexName);
	if(z == NULL) {
		LOGW("makeSpriteEx: didn't find zwoptex whose name is %s", zwoptexName);
		return NULL;
	}
    	
    wyZwoptexFrame* f = z -> getFrame(frameName);
	
    if(f == NULL) {
		return NULL;
	}
    
    if(z->getTexture() == NULL) {
        LOGW("makeSpriteEx: zwoptex %s doesn't has bound texture", zwoptexName);
        return NULL;
    }
    
    if (batch == NULL) {
        wySpriteEx* sprite = WYNEW wySpriteEx(z->getTexture(), f);
        return (wySpriteEx*)sprite->autoRelease();
    }

    return wySpriteEx::make(batch, f, zi);
    
}
