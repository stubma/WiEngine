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

wyBoneTransform::wyBoneTransform() :
		m_boneName(NULL) {
}

wyBoneTransform::~wyBoneTransform() {
	for(SlotSkinKeyFrameList::iterator iter = m_sskfList.begin(); iter != m_sskfList.end(); iter++) {
		wyFree((void*)iter->skinName);
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

void wyBoneTransform::addSlotSkinKeyFrame(SlotSkinKeyFrame kf) {
	m_sskfList.push_back(kf);
}

void wyBoneTransform::addSlotColorKeyFrame(SlotColorKeyFrame kf) {
	m_sckfList.push_back(kf);
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
	
	// dump slot skin key frame
	for(SlotSkinKeyFrameList::iterator iter = m_sskfList.begin(); iter != m_sskfList.end(); iter++) {
		SlotSkinKeyFrame& kf = *iter;
		LOGD("slot skin key frame, time: %f, skin: %s", kf.time, kf.skinName);
	}
	
	// dump slot color key frame
	for(SlotColorKeyFrameList::iterator iter = m_sckfList.begin(); iter != m_sckfList.end(); iter++) {
		SlotColorKeyFrame& kf = *iter;
		LOGD("slot color key frame, time: %f, color: 0x%x", kf.time, kf.color);
	}
}