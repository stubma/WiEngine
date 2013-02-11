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
		m_rootBone(NULL) {
}

wySkeletalSprite::~wySkeletalSprite() {
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
		wySpriteEx* sprite = slot->getSprite();
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

void wySkeletalSprite::stopAnimation() {
	// clear animation
	wyObjectRelease(m_animation);
	m_animation = NULL;
	
	// restore original state
	if(m_rootBone) {
		restoreBoneInfo(m_rootBone);
		syncBoneStates(m_rootBone);
	}
}

void wySkeletalSprite::playAnimation(wySkeletalAnimation* anim) {
	// stop current
	stopAnimation();
	
	// hold this animation
	wyObjectRetain(anim);
	wyObjectRelease(m_animation);
	m_animation = anim;
	
	// save original frame info
	saveBoneInfo(m_rootBone);
	
	// init for first frame
	setupFirstFrameState();
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
	if(!m_animation)
		return;
	
	// set frame
	m_frameTime += delta;
	if(m_frameTime > m_animation->getDuration()) {
		m_frameTime = fmod(m_frameTime, m_animation->getDuration());
	}
	
	// update frame state
	setFrame(m_frameTime);
}

void wySkeletalSprite::setFrame(float time) {
	// basic checking
	if(!m_animation || !m_skeleton)
		return;
	
	wySkeletalAnimation::BoneTransformPtrList& btList = m_animation->getBoneTransformList();
	for(wySkeletalAnimation::BoneTransformPtrList::iterator iter = btList.begin(); iter != btList.end(); iter++) {
		// try to get bone, if can't, continue
		wyBoneTransform* bt = *iter;
		wyBone* bone = m_skeleton->getBone(bt->getBoneName());
		if(!bone)
			continue;
		
		// calculate info
		bt->populateFrame(time);
		
		// set rotation
		wyBoneTransform::RotationKeyFrame& rkf = bt->getRotationFrame();
		bone->setRotation(rkf.angle);
		
		// set translation
		wyBoneTransform::TranslationKeyFrame& tkf = bt->getTranslationFrame();
		bone->setX(tkf.x);
		bone->setY(tkf.y);
		
		// set scale
		wyBoneTransform::ScaleKeyFrame& skf = bt->getScaleFrame();
		bone->setScaleX(skf.scaleX);
		bone->setScaleY(skf.scaleY);
	}
}

void wySkeletalSprite::setSkeleton(wySkeleton* s) {
	// stop current animation
	stopAnimation();
	
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
	syncBoneStates(m_rootBone);
	syncSkinAttachmentStates();
}

void wySkeletalSprite::syncBoneStates(wyBone* bone) {
	wyNode* boneNode = bone->getNode();
	if(boneNode) {
		boneNode->setPosition(bone->getX(), bone->getY());
		boneNode->setRotation(-bone->getRotation());
		boneNode->setScaleX(bone->getScaleX());
		boneNode->setScaleY(bone->getScaleY());
	}
	
	wyBone::BonePtrList& children = bone->getChildren();
	for(wyBone::BonePtrList::iterator iter = children.begin(); iter != children.end(); iter++) {
		syncBoneStates(*iter);
	}
}

void wySkeletalSprite::syncSkinAttachmentStates() {
	wySkeleton::SlotPtrList& slotDisplayList = m_skeleton->getSlotDisplaySlot();
	for(wySkeleton::SlotPtrList::iterator iter = slotDisplayList.begin(); iter != slotDisplayList.end(); iter++) {
		wySlot* slot = *iter;
		wySpriteEx* sprite = slot->getSprite();
		wySkinAttachment* skin = slot->getActiveSkinAttachment();
		if(skin && sprite) {
			sprite->setPosition(skin->getX(), skin->getY());
			sprite->setRotation(-skin->getRotation());
			sprite->setScaleX(skin->getScaleX());
			sprite->setScaleY(skin->getScaleY());
		}
	}
}

void wySkeletalSprite::saveBoneInfo(wyBone* bone) {
	bone->pushSnapshot();
	
	wyBone::BonePtrList& children = bone->getChildren();
	for(wyBone::BonePtrList::iterator iter = children.begin(); iter != children.end(); iter++) {
		saveBoneInfo(*iter);
	}
}

void wySkeletalSprite::restoreBoneInfo(wyBone* bone) {
	bone->popSnapshot();
	
	wyBone::BonePtrList& children = bone->getChildren();
	for(wyBone::BonePtrList::iterator iter = children.begin(); iter != children.end(); iter++) {
		restoreBoneInfo(*iter);
	}
}

void wySkeletalSprite::createSlotSprites() {
	wySkeleton::SlotPtrList& slotDisplayList = m_skeleton->getSlotDisplaySlot();
	for(wySkeleton::SlotPtrList::iterator iter = slotDisplayList.begin(); iter != slotDisplayList.end(); iter++) {
		// get slot active attachment image file name
		wySlot* slot = *iter;
		
		// create slot sprite
		if(slot->getActiveSkinAttachmentName()) {
			char buf[512];
			sprintf(buf, "%s.png", slot->getActiveSkinAttachmentName());
			wySpriteEx* sprite = createRelatedSprite(buf);
			if(sprite) {
				sprite->getTexture()->setAntiAlias(false);
				slot->setSprite(sprite);
				slot->getBone()->getNode()->addChildLocked(sprite);
			} 
		}
	}
}

void wySkeletalSprite::createBoneNodes(wyBone* bone) {
	// this node is root bone node, so need skip root bone
	wyNode* boneNode = wyNode::make();
	bone->setNode(boneNode);
	if(bone->getParent()) {
		bone->getParent()->getNode()->addChildLocked(boneNode);
	} else {
		addChildLocked(boneNode);
	}
	
	wyBone::BonePtrList& children = bone->getChildren();
	for(wyBone::BonePtrList::iterator iter = children.begin(); iter != children.end(); iter++) {
		createBoneNodes(*iter);
	}
}

wySpriteEx* wySkeletalSprite::createRelatedSprite(const char* name) {
	switch(m_skeleton->getSource()) {
		case wySkeleton::RESOURCE:
		{
			char buf[512];
			sprintf(buf, "R.drawable.%s", name);
			return wySpriteEx::make(wyTexture2D::make(RES(buf)));
		}
		case wySkeleton::ASSETS:
		{
			const char* path = m_skeleton->getPath();
			const char* dirPath = wyUtils::deleteLastPathComponent(path);
			const char* finalPath = wyUtils::appendPathComponent(dirPath, name);
			wySpriteEx* sprite = wySpriteEx::make(wyTexture2D::make(finalPath, false));
			wyFree((void*)dirPath);
			wyFree((void*)finalPath);
			return sprite;
		}
		case wySkeleton::FILE_SYSTEM:
		{
			const char* path = m_skeleton->getPath();
			const char* dirPath = wyUtils::deleteLastPathComponent(path);
			const char* finalPath = wyUtils::appendPathComponent(dirPath, name);
			wySpriteEx* sprite = wySpriteEx::make(wyTexture2D::make(finalPath, true));
			wyFree((void*)dirPath);
			wyFree((void*)finalPath);
			return sprite;
		}
		case wySkeleton::MEMORY_FILE_SYSTEM:
		{
			const char* path = m_skeleton->getPath();
			const char* dirPath = wyUtils::deleteLastPathComponent(path);
			const char* finalPath = wyUtils::appendPathComponent(dirPath, name);
			wySpriteEx* sprite = wySpriteEx::make(wyTexture2D::makeMemory(finalPath));
			wyFree((void*)dirPath);
			wyFree((void*)finalPath);
			return sprite;
		}
		default:
			LOGW("wySkeletalSprite::createRelatedSprite: unknown skeleton source");
			return NULL;
	}
}