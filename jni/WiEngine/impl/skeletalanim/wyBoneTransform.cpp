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
#include "wyBoneTransform.h"
#include "wyUtils.h"
#include "wyLog.h"
#include "wySkeletalSprite.h"

wyBoneTransform::wyBoneTransform() :
		m_boneName(NULL) {
}

wyBoneTransform::~wyBoneTransform() {
	if(m_boneName) {
		wyFree((void*)m_boneName);
		m_boneName = NULL;
	}
}

wyBoneTransform* wyBoneTransform::make() {
	wyBoneTransform* bt = WYNEW wyBoneTransform();
	return (wyBoneTransform*)bt->autoRelease();
}

void wyBoneTransform::setBoneName(const char* name) {
	if(m_boneName) {
		wyFree((void*)m_boneName);
		m_boneName = NULL;
	}
	m_boneName = wyUtils::copy(name);
}

void wyBoneTransform::addRotationKeyFrame(RotationKeyFrame kf) {
	m_rkfList.push_back(kf);
}

void wyBoneTransform::addTranslationKeyFrame(TranslationKeyFrame kf) {
	m_tkfList.push_back(kf);
}

void wyBoneTransform::addScaleKeyFrame(ScaleKeyFrame kf) {
	m_skfList.push_back(kf);
}

void wyBoneTransform::populateFrame(float time) {
	// process rotation frame
	{
		// set time to current time
		m_currentRotation.time = time;
		m_currentRotation.valid = true;
		
		// if empty, just set to zero
		// if not, found key frame, do interpolation if needed
		if(m_rkfList.empty()) {
			m_currentRotation.valid = false;
		} else {
			RotationKeyFrameList::iterator iter = m_rkfList.begin();
			for(; iter != m_rkfList.end(); iter++) {
				RotationKeyFrame& kf = *iter;
				if(time < kf.time) {
					if(iter == m_rkfList.begin()) {
						m_currentRotation.angle = kf.angle;
					} else {
						RotationKeyFrame& prevKf = *(iter - 1);
						wyPoint t = getInterpolationTime(prevKf.time, kf.time, time, prevKf.interpolator);
						
						// simplifies rotation by rotating the shorter distance
						float prevAngle = prevKf.angle;
						float angle = kf.angle;
						while (prevAngle > 180)
							prevAngle -= 360;
						while (prevAngle < -180)
							prevAngle += 360;
						while (angle > 180)
							angle -= 360;
						while (angle < -180)
							angle += 360;
						
						// interpolate
						m_currentRotation.angle = t.x * (angle - prevAngle) + prevAngle;
					}
					break;
				} else if(time == kf.time) {
					m_currentRotation = kf;
					break;
				}
			}
			
			// if exceed last one
			if(iter == m_rkfList.end()) {
				m_currentRotation.angle = m_rkfList.rbegin()->angle;
			}
		}
	}
	
	// process translation
	{
		// set time to current time
		m_currentTranslation.time = time;
		m_currentTranslation.valid = true;
		
		// if empty, just set to zero
		// if not, found key frame, do interpolation if needed
		if(m_tkfList.empty()) {
			m_currentTranslation.valid = false;
		} else {
			TranslationKeyFrameList::iterator iter = m_tkfList.begin();
			for(; iter != m_tkfList.end(); iter++) {
				TranslationKeyFrame& kf = *iter;
				if(time < kf.time) {
					if(iter == m_tkfList.begin()) {
						m_currentTranslation.x = kf.x;
						m_currentTranslation.y = kf.y;
					} else {
						TranslationKeyFrame& prevKf = *(iter - 1);
						wyPoint t = getInterpolationTime(prevKf.time, kf.time, time, prevKf.interpolator);
						m_currentTranslation.x = t.x * (kf.x - prevKf.x) + prevKf.x;
						m_currentTranslation.y = t.y * (kf.y - prevKf.y) + prevKf.y;
					}
					break;
				} else if(time == kf.time) {
					m_currentTranslation = kf;
					break;
				}
			}
			
			// if exceed last one
			if(iter == m_tkfList.end()) {
				TranslationKeyFrame& kf = *m_tkfList.rbegin();
				m_currentTranslation.x = kf.x;
				m_currentTranslation.y = kf.y;
			}
		}
	}
	
	// process scale
	{
		// set time to current time
		m_currentScale.time = time;
		m_currentScale.valid = true;
		
		// if empty, just set to zero
		// if not, found key frame, do interpolation if needed
		if(m_skfList.empty()) {
			m_currentScale.valid = false;
		} else {
			ScaleKeyFrameList::iterator iter = m_skfList.begin();
			for(; iter != m_skfList.end(); iter++) {
				ScaleKeyFrame& kf = *iter;
				if(time < kf.time) {
					if(iter == m_skfList.begin()) {
						m_currentScale.scaleX = kf.scaleX;
						m_currentScale.scaleY = kf.scaleY;
					} else {
						ScaleKeyFrame& prevKf = *(iter - 1);
						wyPoint t = getInterpolationTime(prevKf.time, kf.time, time, prevKf.interpolator);
						m_currentScale.scaleX = t.x * (kf.scaleX - prevKf.scaleX) + prevKf.scaleX;
						m_currentScale.scaleY = t.y * (kf.scaleY - prevKf.scaleY) + prevKf.scaleY;
					}
					break;
				} else if(time == kf.time) {
					m_currentScale = kf;
					break;
				}
			}
			
			// if exceed last one
			if(iter == m_skfList.end()) {
				ScaleKeyFrame& kf = *m_skfList.rbegin();
				m_currentScale.scaleX = kf.scaleX;
				m_currentScale.scaleY = kf.scaleY;
			}
		}
	}
}

bool wyBoneTransform::applyTo(wySkeletalSprite* owner) {
	wySkeleton* s = owner->getSkeleton();
	wyBone* bone = s->getBone(m_boneName);
	if(!bone)
		return false;
	
	// get state of this owner, and original state
	wyBone::State& ownerState = bone->getState(owner);
	wyBone::State& originalState = bone->getOriginalState();
	
	// set rotation
	if(m_currentRotation.valid && !bone->hasFlag(wyBone::FIXED_ROTATION)) {
		ownerState.rotation = originalState.rotation + m_currentRotation.angle;
	}
	
	// set translation
	if(m_currentTranslation.valid && !bone->hasFlag(wyBone::FIXED_POSITION)) {
		ownerState.x = originalState.x + m_currentTranslation.x;
		ownerState.y = originalState.y + m_currentTranslation.y;
	}
	
	// set scale
	if(m_currentScale.valid && !bone->hasFlag(wyBone::FIXED_SCALE)) {
		ownerState.scaleX = originalState.scaleX * m_currentScale.scaleX;
		ownerState.scaleY = originalState.scaleY * m_currentScale.scaleY;
	}
	
	return true;
}

void wyBoneTransform::dump() {
	// dump rotation key frame
	for(RotationKeyFrameList::iterator iter = m_rkfList.begin(); iter != m_rkfList.end(); iter++) {
		RotationKeyFrame& kf = *iter;
		LOGD("rotation key frame, time: %f, angle: %f", kf.time, kf.angle);
	}
	
	// dump translation key frame
	for(TranslationKeyFrameList::iterator iter = m_tkfList.begin(); iter != m_tkfList.end(); iter++) {
		TranslationKeyFrame& kf = *iter;
		LOGD("translation key frame, time: %f, x: %f, y: %f", kf.time, kf.x, kf.y);
	}
	
	// dump scale key frame
	for(ScaleKeyFrameList::iterator iter = m_skfList.begin(); iter != m_skfList.end(); iter++) {
		ScaleKeyFrame& kf = *iter;
		LOGD("scale key frame, time: %f, scalex: %f, scaley: %f", kf.time, kf.scaleX, kf.scaleY);
	}
}