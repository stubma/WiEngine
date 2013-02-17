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
#include "wySkeletalSprite.h"
#include "wySkeletalAnimationCache.h"
#include "wyDirector.h"
#include "wySkinAttachment.h"
#include "wyUtils.h"
#include "wyLog.h"

extern wyDirector* gDirector;

wySkeletalSprite::wySkeletalSprite() :
		m_skeleton(NULL),
		m_animation(NULL),
		m_loop(0),
		m_paused(false),
		m_rootBone(NULL),
		m_fillAfter(false),
		m_listener(NULL) {
}

wySkeletalSprite::~wySkeletalSprite() {
	if(m_rootBone)
		clearBoneStates(m_rootBone);
	cleanSlotStates();
	wyObjectRelease(m_skeleton);
	wyObjectRelease(m_animation);
}

wySkeletalSprite* wySkeletalSprite::make(wySkeleton* s) {
	wySkeletalSprite* sprite = WYNEW wySkeletalSprite();
	sprite->setSkeleton(s);
	return (wySkeletalSprite*)sprite->autoRelease();
}

void wySkeletalSprite::visit() {
	if(!m_visible)
		return;
	
	// sync bone state
	if(m_rootBone)
		syncBoneStates(m_rootBone);
	
	// should push matrix to avoid disturb current matrix
	glPushMatrix();
	
	// if grid is set, prepare grid
	// if not, transform self
	bool hasGrid = m_grid != NULL && m_grid->isActive();
	if(hasGrid) {
		m_grid->beforeDraw();
	} else {
		transform();
	}
	
	// check clip
	if(m_hasClip)
		doClip();
	
	// visit slot sprites by display list sequence
	wySkeleton::SlotPtrList& slotDisplayList = m_skeleton->getSlotDisplaySlot();
	for(wySkeleton::SlotPtrList::iterator iter = slotDisplayList.begin(); iter != slotDisplayList.end(); iter++) {
		wySlot* slot = *iter;
		wySlot::State& state = slot->getState(this);
		wySpriteEx* sprite = state.sprite;
		if(sprite) {
			// should push matrix for every slot sprite
			glPushMatrix();
			
			// transform until to this node
			sprite->transformAncestorsUntil(this);
			sprite->transform();
			
			// draw this sprite
			sprite->draw();
			
			// pop matrix
			glPopMatrix();
		}
	}
	
	// restore
	if(m_hasClip && gDirector)
		gDirector->popClipRect();
	
	// if grid is set, end grid
	if(hasGrid) {
		m_grid->afterDraw(this);
	}
	
	// pop matrix
	glPopMatrix();
}

wyPoint wySkeletalSprite::getBonePosition(const char* boneName) {
    // basic check
    if(!m_skeleton)
        return wypZero;
    
    // get bone
    wyBone* bone = m_skeleton->getBone(boneName);
    if(!bone)
        return wypZero;
    
    // get bone node
    wyBone::State& state = bone->getState(this);
    wyAffineTransform t = state.node->getNodeToAncestorTransform(this);
    wyPoint pos = wyp(state.x, state.y);
    return wyaTransformPoint(t, pos);
}

wyPoint wySkeletalSprite::getBonePositionRelativeToWorld(const char* boneName) {
    // basic check
    if(!m_skeleton)
        return wypZero;
    
    // get bone
    wyBone* bone = m_skeleton->getBone(boneName);
    if(!bone)
        return wypZero;
    
    // get bone node
    wyBone::State& state = bone->getState(this);
    wyAffineTransform t = state.node->getNodeToWorldTransform();
    wyPoint pos = wyp(state.x, state.y);
    return wyaTransformPoint(t, pos);
}

void wySkeletalSprite::stopAnimation(bool restore) {
	// no animation? return
	if(!m_animation)
		return;
	
	// clear animation
	wyObjectRelease(m_animation);
	m_animation = NULL;
	
	// restore original state
	if(m_rootBone && restore) {
		syncOriginalBoneStates(m_rootBone);
	}
	
	// notify
	if(m_listener)
		m_listener->onSkeletalAnimationStopped(this);
}

void wySkeletalSprite::playAnimation(wySkeletalAnimation* anim) {
	// stop current
	stopAnimation(false);
	
	// hold this animation
	wyObjectRetain(anim);
	wyObjectRelease(m_animation);
	m_animation = anim;
	
	// init for first frame
	setupFirstFrameState();
	
	// notify
	if(m_listener)
		m_listener->onSkeletalAnimationStarted(this);
}

void wySkeletalSprite::playAnimation(const char* animName) {
	wySkeletalAnimation* anim = wySkeletalAnimationCache::getInstance()->getAnimation(animName);
	if(anim) {
		playAnimation(anim);
	}
}

void wySkeletalSprite::setupFirstFrameState() {
	// reset time to zero
	m_frameTime = 0;
	
	// reset flag
	m_paused = false;
	
	// set animation to the very beginning
	setFrame(m_frameTime);
}

void wySkeletalSprite::tick(float delta) {
	// is paused?
	if(m_paused)
		return;
	
	// basic checking
	if(!m_animation || !m_skeleton)
		return;
	
	// update frame time
	m_frameTime += delta;
	if(m_frameTime > m_animation->getDuration()) {
		if(m_loop < 0) {
			m_frameTime = fmod(m_frameTime, m_animation->getDuration());
			setFrame(m_frameTime);
			
			// notify
			if(m_listener)
				m_listener->onSkeletalAnimationUpdated(this, m_frameTime);
		} else if(m_loop > 1) {
			m_loop--;
			m_frameTime = fmod(m_frameTime, m_animation->getDuration());
			setFrame(m_frameTime);
			
			// notify
			if(m_listener)
				m_listener->onSkeletalAnimationUpdated(this, m_frameTime);
		} else {
			// ensure last frame is set
			if(m_fillAfter) {
				setFrame(m_animation->getDuration());
				
				// notify
				if(m_listener)
					m_listener->onSkeletalAnimationUpdated(this, m_frameTime);
			}
			
			// stop animation
			stopAnimation(!m_fillAfter);
			
			// reset some members
			m_loop = 0;
		}
	} else {
		setFrame(m_frameTime);
		
		// notify
		if(m_listener)
			m_listener->onSkeletalAnimationUpdated(this, m_frameTime);
	}
}

void wySkeletalSprite::setFrame(float time) {
	wySkeletalAnimation::TransformPtrList& tList = m_animation->getTransformList();
	for(wySkeletalAnimation::TransformPtrList::iterator iter = tList.begin(); iter != tList.end(); iter++) {
		// calculate info
		wyTransform* t = *iter;
		t->populateFrame(time);
		
		// apply frame
		t->applyTo(this);
	}
}

void wySkeletalSprite::setSkeleton(wySkeleton* s) {
	// stop current animation
	stopAnimation(false);
	
	// hold skeleton
	wyObjectRetain(s);
	wyObjectRelease(m_skeleton);
	m_skeleton = s;
	
	// clear all children node and references
	removeAllChildren(true);
	
	// re-create bone nodes
	m_rootBone = m_skeleton->getRootBone();
	createBoneNodes(m_rootBone);
	
	// re-create slot sprite
	createSlotSprites();
	
	// sync states
	syncOriginalBoneStates(m_rootBone);
	syncSkinAttachmentStates();
}

void wySkeletalSprite::clearBoneStates(wyBone* bone) {
	bone->clearState(this);
	
	wyBone::BonePtrList& children = bone->getChildren();
	for(wyBone::BonePtrList::iterator iter = children.begin(); iter != children.end(); iter++) {
		clearBoneStates(*iter);
	}
}

void wySkeletalSprite::syncOriginalBoneStates(wyBone* bone) {
	wyBone::State& originalState = bone->getOriginalState();
	wyBone::State& state = bone->getState(this);
	wyNode* boneNode = state.node;
	if(boneNode) {
		boneNode->setPosition(originalState.x, originalState.y);
		boneNode->setRotation(-originalState.rotation);
		boneNode->setScaleX(originalState.scaleX);
		boneNode->setScaleY(originalState.scaleY);
	}
	
	wyBone::BonePtrList& children = bone->getChildren();
	for(wyBone::BonePtrList::iterator iter = children.begin(); iter != children.end(); iter++) {
		syncOriginalBoneStates(*iter);
	}
}

void wySkeletalSprite::syncBoneStates(wyBone* bone) {
	wyBone::State& state = bone->getState(this);
	wyNode* boneNode = state.node;
	if(boneNode) {
		boneNode->setPosition(state.x, state.y);
		boneNode->setRotation(-state.rotation);
		boneNode->setScaleX(state.scaleX);
		boneNode->setScaleY(state.scaleY);
	}
	
	wyBone::BonePtrList& children = bone->getChildren();
	for(wyBone::BonePtrList::iterator iter = children.begin(); iter != children.end(); iter++) {
		syncBoneStates(*iter);
	}
}

void wySkeletalSprite::cleanSlotStates() {
	wySkeleton::SlotPtrList& slotDisplayList = m_skeleton->getSlotDisplaySlot();
	for(wySkeleton::SlotPtrList::iterator iter = slotDisplayList.begin(); iter != slotDisplayList.end(); iter++) {
		(*iter)->clearState(this);
	}
}

void wySkeletalSprite::syncSkinAttachmentStates() {
	wySkeleton::SlotPtrList& slotDisplayList = m_skeleton->getSlotDisplaySlot();
	for(wySkeleton::SlotPtrList::iterator iter = slotDisplayList.begin(); iter != slotDisplayList.end(); iter++) {
		wySlot* slot = *iter;
		wySlot::State& state = slot->getState(this);
		wySpriteEx* sprite = state.sprite;
		wySkinAttachment* skin = slot->getActiveSkinAttachment(this);
		if(skin && sprite) {
			sprite->setPosition(skin->getX(), skin->getY());
			sprite->setRotation(-skin->getRotation());
			sprite->setScaleX(skin->getScaleX());
			sprite->setScaleY(skin->getScaleY());
		}
	}
}

void wySkeletalSprite::createSlotSprites() {
	wySkeleton::SlotPtrList& slotDisplayList = m_skeleton->getSlotDisplaySlot();
	for(wySkeleton::SlotPtrList::iterator iter = slotDisplayList.begin(); iter != slotDisplayList.end(); iter++) {
		// get slot active attachment image file name
		wySlot* slot = *iter;
		
		// create slot sprite
		wySlot::State& state = slot->getState(this);
		if(state.activeSkinAttachmentName) {
			wySpriteEx* sprite = wySpriteEx::make(createRelatedTexture(state.activeSkinAttachmentName));
			if(sprite) {
				state.sprite = sprite;
				wyBone::State& state = slot->getBone()->getState(this);
				if(state.node)
					state.node->addChildLocked(sprite);
			} 
		}
	}
}

void wySkeletalSprite::createBoneNodes(wyBone* bone) {
	// this node is root bone node, so need skip root bone
	wyBone::State& state = bone->getState(this);
	wyNode* boneNode = wyNode::make();
	state.node = boneNode;
	if(bone->getParent()) {
		wyBone::State& parentState = bone->getParent()->getState(this);
		parentState.node->addChildLocked(boneNode);
	} else {
		addChildLocked(boneNode);
	}
	
	wyBone::BonePtrList& children = bone->getChildren();
	for(wyBone::BonePtrList::iterator iter = children.begin(); iter != children.end(); iter++) {
		createBoneNodes(*iter);
	}
}

void wySkeletalSprite::setBonePosition(const char* boneName, float x, float y, bool fixed) {
    // basic check
    if(!m_skeleton)
        return;
    
    // get bone
    wyBone* bone = m_skeleton->getBone(boneName);
    if(!bone)
        return;
    
    // set
    wyBone::State& state = bone->getState(this);
    state.x = x;
    state.y = y;
    if(fixed)
        bone->addFlag(wyBone::FIXED_POSITION);
    else
        bone->removeFlag(wyBone::FIXED_POSITION);
}

void wySkeletalSprite::setBoneRotation(const char* boneName, float angle, bool fixed) {
    // basic check
    if(!m_skeleton)
        return;
    
    // get bone
    wyBone* bone = m_skeleton->getBone(boneName);
    if(!bone)
        return;
    
    // set
    wyBone::State& state = bone->getState(this);
    state.rotation = angle;
    if(fixed)
        bone->addFlag(wyBone::FIXED_ROTATION);
    else
        bone->removeFlag(wyBone::FIXED_ROTATION);
}

void wySkeletalSprite::setBoneScale(const char* boneName, float scaleX, float scaleY, bool fixed) {
    // basic check
    if(!m_skeleton)
        return;
    
    // get bone
    wyBone* bone = m_skeleton->getBone(boneName);
    if(!bone)
        return;
    
    // set
    wyBone::State& state = bone->getState(this);
    state.scaleX = scaleX;
    state.scaleY = scaleY;
    if(fixed)
        bone->addFlag(wyBone::FIXED_SCALE);
    else
        bone->removeFlag(wyBone::FIXED_SCALE);
}

void wySkeletalSprite::setSlotColor(const char* slotName, int color, bool fixed) {
    // basic check
    if(!m_skeleton)
        return;
    
    // get slot
    wySlot* slot = m_skeleton->getSlot(slotName);
    if(!slot)
        return;
    
    // set
    wySlot::State& state = slot->getState(this);
    state.color = color;
    state.sprite->setColor(wyc4bFromInteger(color));
    if(fixed)
        slot->addFlag(wySlot::FIXED_COLOR);
    else
        slot->removeFlag(wySlot::FIXED_COLOR);
}

void wySkeletalSprite::setSlotAttachment(const char* slotName, const char* attachmentName, bool fixed) {
    // basic check
    if(!m_skeleton)
        return;
    
    // get slot
    wySlot* slot = m_skeleton->getSlot(slotName);
    if(!slot)
        return;
    
    // set
    wySlot::State& state = slot->getState(this);
    state.activeSkinAttachmentName = attachmentName;
    wyTexture2D* tex = createRelatedTexture(attachmentName);
    state.sprite->setTexture(tex);
    if(fixed)
        slot->addFlag(wySlot::FIXED_ATTACHMENT);
    else
        slot->removeFlag(wySlot::FIXED_ATTACHMENT);
}

wyTexture2D* wySkeletalSprite::createRelatedTexture(const char* name) {
	switch(m_skeleton->getSource()) {
		case wySkeleton::RESOURCE:
		{
			char buf[512];
			sprintf(buf, "R.drawable.%s", name);
			return wyTexture2D::make(RES(buf));
		}
		case wySkeleton::ASSETS:
		{
			char buf[512];
			sprintf(buf, "%s.png", name);
			const char* path = m_skeleton->getPath();
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
			sprintf(buf, "%s.png", name);
			const char* path = m_skeleton->getPath();
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
			sprintf(buf, "%s.png", name);
			const char* path = m_skeleton->getPath();
			const char* dirPath = wyUtils::deleteLastPathComponent(path);
			const char* finalPath = wyUtils::appendPathComponent(dirPath, buf);
			wyTexture2D* tex = wyTexture2D::makeMemory(finalPath);
			wyFree((void*)dirPath);
			wyFree((void*)finalPath);
			return tex;
		}
		default:
			LOGW("wySkeletalSprite::createRelatedTexture: unknown skeleton source");
			return NULL;
	}
}