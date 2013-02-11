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
#include "wySkeleton.h"
#include "wyLog.h"

wySkeleton::wySkeleton() {
}

wySkeleton::~wySkeleton() {
	for(BoneMap::iterator iter = m_boneMap.begin(); iter != m_boneMap.end(); iter++) {
		wyObjectRelease(iter->second);
	}
	for(SlotMap::iterator iter = m_slotMap.begin(); iter != m_slotMap.end(); iter++) {
		wyObjectRelease(iter->second);
	}
}

wySkeleton* wySkeleton::make() {
	wySkeleton* s = WYNEW wySkeleton();
	return (wySkeleton*)s->autoRelease();
}

void wySkeleton::addBone(wyBone* bone) {
	BoneMap::iterator iter = m_boneMap.find(bone->getName());
	if(iter == m_boneMap.end()) {
		m_boneMap[bone->getName()] = bone;
		wyObjectRetain(bone);
	}
}

void wySkeleton::addSlot(wySlot* slot) {
	SlotMap::iterator iter = m_slotMap.find(slot->getName());
	if(iter == m_slotMap.end()) {
		m_slotMap[slot->getName()] = slot;
		wyObjectRetain(slot);
	}
}

wyBone* wySkeleton::getBone(const char* name) {
	BoneMap::iterator iter = m_boneMap.find(name);
	if(iter != m_boneMap.end()) {
		return iter->second;
	} else {
		return NULL;
	}
}

wySlot* wySkeleton::getSlot(const char* name) {
	SlotMap::iterator iter = m_slotMap.find(name);
	if(iter != m_slotMap.end()) {
		return iter->second;
	} else {
		return NULL;
	}
}

void wySkeleton::dump() {
	// dump bone
	LOGD("bone count: %ld", m_boneMap.size());
	for(BoneMap::iterator iter = m_boneMap.begin(); iter != m_boneMap.end(); iter++) {
		LOGD("bone %s, parent: %s, len: %f, x: %f, y: %f, rotation: %f, scalex: %f, scaley: %f",
			 iter->second->getName(),
			 iter->second->getParent() ? iter->second->getParent()->getName() : "none",
			 iter->second->getLength(),
			 iter->second->getX(),
			 iter->second->getY(),
			 iter->second->getRotation(),
			 iter->second->getScaleX(),
			 iter->second->getScaleY());
	}

	// dump slot
	LOGD("slot count: %ld", m_slotMap.size());
	for(SlotMap::iterator iter = m_slotMap.begin(); iter != m_slotMap.end(); iter++) {
		LOGD("slot %s, bone: %s, activeskin: %s, color: 0x%x",
			 iter->second->getName(),
			 iter->second->getBone()->getName(),
			 iter->second->getActiveSkinAttachmentName() ? iter->second->getActiveSkinAttachmentName() : "null",
			 wyc4bToInteger(iter->second->getColor()));
	}
}
