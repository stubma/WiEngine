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
#include "wyUtils.h"

const char* wySkeleton::DEFALT_SKIN_NAME = "default";

wySkeleton::wySkeleton() :
		m_source(RESOURCE),
		m_path(NULL) {
}

wySkeleton::~wySkeleton() {
	if(m_path) {
		wyFree((void*)m_path);
	}
	for(BoneMap::iterator iter = m_boneMap.begin(); iter != m_boneMap.end(); iter++) {
		wyObjectRelease(iter->second);
	}
	for(SlotMap::iterator iter = m_slotMap.begin(); iter != m_slotMap.end(); iter++) {
		wyObjectRelease(iter->second);
	}
    for(SkinMap::iterator iter = m_skinMap.begin(); iter != m_skinMap.end(); iter++) {
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
		m_slotDisplayList.push_back(slot);
		wyObjectRetain(slot);
	}
}

void wySkeleton::addSkin(wySkin* skin) {
    SkinMap::iterator iter = m_skinMap.find(skin->getName());
	if(iter == m_skinMap.end()) {
		m_skinMap[skin->getName()] = skin;
		wyObjectRetain(skin);
	}
}

wyBone* wySkeleton::getRootBone() {
	for(BoneMap::iterator iter = m_boneMap.begin(); iter != m_boneMap.end(); iter++) {
		if(!iter->second->getParent())
			return iter->second;
	}
	return NULL;
}

wyBone* wySkeleton::getBone(const char* name) {
	if(!name)
	   return NULL;
	
	BoneMap::iterator iter = m_boneMap.find(name);
	if(iter != m_boneMap.end()) {
		return iter->second;
	} else {
		return NULL;
	}
}

wySlot* wySkeleton::getSlot(const char* name) {
	if(!name)
		return NULL;
	
	SlotMap::iterator iter = m_slotMap.find(name);
	if(iter != m_slotMap.end()) {
		return iter->second;
	} else {
		return NULL;
	}
}

wySkin* wySkeleton::getSkin(const char* name) {
    if(!name)
		return NULL;
	
	SkinMap::iterator iter = m_skinMap.find(name);
	if(iter != m_skinMap.end()) {
		return iter->second;
	} else {
		return NULL;
	}
}

void wySkeleton::setPath(const char* path) {
	if(m_path) {
		wyFree((void*)m_path);
		m_path = NULL;
	}
	m_path = wyUtils::copy(path);
}

void wySkeleton::dump() {
	// dump bone
	LOGD("bone count: %ld", m_boneMap.size());
	for(BoneMap::iterator iter = m_boneMap.begin(); iter != m_boneMap.end(); iter++) {
		wyBone::State& state = iter->second->getOriginalState();
		LOGD("bone %s, parent: %s, len: %f, x: %f, y: %f, rotation: %f, scalex: %f, scaley: %f",
			 iter->second->getName(),
			 iter->second->getParent() ? iter->second->getParent()->getName() : "none",
			 iter->second->getLength(),
			 state.x,
			 state.y,
			 state.rotation,
			 state.scaleX,
			 state.scaleY);
	}

	// dump slot
	LOGD("slot count: %ld", m_slotMap.size());
	for(SlotMap::iterator iter = m_slotMap.begin(); iter != m_slotMap.end(); iter++) {
		wySlot::State& state = iter->second->getOriginalState();
		LOGD("slot %s, bone: %s, activeskin: %s, color: 0x%x",
			 iter->second->getName(),
			 iter->second->getBone()->getName(),
			 state.activeAttachmentName ? state.activeAttachmentName : "null",
			 state.color);
	}
}

wyTexture2D* wySkeleton::createRelatedTexture(wySkeleton* s, const char* name) {
	switch(s->getSource()) {
		case wySkeleton::RESOURCE:
		{
			char buf[512];
			sprintf(buf, "R.drawable.%s", name);
			return wyTexture2D::make(RES(buf));
		}
		case wySkeleton::ASSETS:
		{
            char buf[512];
            if(wyUtils::endsWith(name, ".png"))
                sprintf(buf, "%s", name);
            else
                sprintf(buf, "%s.png", name);
			const char* path = s->getPath();
			const char* dirPath = wyUtils::deleteLastPathComponent(path);
			const char* finalPath = wyUtils::appendPathComponent(dirPath, buf);
			wyTexture2D* tex = wyTexture2D::make(finalPath, false);
			wyFree((void*)dirPath);
			wyFree((void*)finalPath);
			return tex;
		}
		case wySkeleton::FILE_SYSTEM:
		{
            char buf[512];
            if(wyUtils::endsWith(name, ".png"))
                sprintf(buf, "%s", name);
            else
                sprintf(buf, "%s.png", name);
			const char* path = s->getPath();
			const char* dirPath = wyUtils::deleteLastPathComponent(path);
			const char* finalPath = wyUtils::appendPathComponent(dirPath, buf);
			wyTexture2D* tex = wyTexture2D::make(finalPath, true);
			wyFree((void*)dirPath);
			wyFree((void*)finalPath);
			return tex;
		}
		case wySkeleton::MEMORY_FILE_SYSTEM:
		{
            char buf[512];
            if(wyUtils::endsWith(name, ".png"))
                sprintf(buf, "%s", name);
            else
                sprintf(buf, "%s.png", name);
			const char* path = s->getPath();
			const char* dirPath = wyUtils::deleteLastPathComponent(path);
			const char* finalPath = wyUtils::appendPathComponent(dirPath, buf);
			wyTexture2D* tex = wyTexture2D::makeMemory(finalPath);
			wyFree((void*)dirPath);
			wyFree((void*)finalPath);
			return tex;
		}
		default:
			LOGW("wySkeleton::createRelatedTexture: unknown skeleton source");
			return NULL;
	}
}