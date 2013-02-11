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
#include "wySkeletalAnimationCache.h"

/// singleton instance
wySkeletalAnimationCache* gSkeletalAnimationCache = NULL;

wySkeletalAnimationCache::wySkeletalAnimationCache() {
}

wySkeletalAnimationCache::~wySkeletalAnimationCache() {
	for(AnimationMap::iterator iter = m_animMap.begin(); iter != m_animMap.end(); iter++) {
		wyObjectRelease(iter->second);
	}
	gSkeletalAnimationCache = NULL;
}

wySkeletalAnimationCache* wySkeletalAnimationCache::getInstance() {
	if(!gSkeletalAnimationCache) {
		gSkeletalAnimationCache = WYNEW wySkeletalAnimationCache();
	}
	return gSkeletalAnimationCache;
}

wySkeletalAnimationCache* wySkeletalAnimationCache::peekInstance() {
	return gSkeletalAnimationCache;
}

void wySkeletalAnimationCache::purgeCache() {
	for(AnimationMap::iterator iter = m_animMap.begin(); iter != m_animMap.end(); iter++) {
		wyObjectRelease(iter->second);
	}
	m_animMap.clear();
}

void wySkeletalAnimationCache::addAnimation(wySkeletalAnimation* anim) {
	AnimationMap::iterator iter = m_animMap.find(anim->getName());
	if(iter == m_animMap.end()) {
		m_animMap[anim->getName()] = anim;
		wyObjectRetain(anim);
	}
}

void wySkeletalAnimationCache::addAnimation(const char* name, wySkeletalAnimation* anim) {
	anim->setName(name);
	addAnimation(anim);
}

wySkeletalAnimation* wySkeletalAnimationCache::getAnimation(const char* name) {
	AnimationMap::iterator iter = m_animMap.find(name);
	if(iter != m_animMap.end()) {
		return iter->second;
	} else {
		return NULL;
	}
}