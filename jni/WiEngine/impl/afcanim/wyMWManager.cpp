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
#include "wyMWManager.h"
#include "wyMWLoader.h"
#include "wyUtils.h"
#include "wyLog.h"
#include "wyGlobal.h"

#define O_CLIPDATA_NUM 4
#define O_FRAMEDATA_NUM 4

wyMWManager* gMWManager;

bool wyMWManager::releaseData(wyArray* arr, void* ptr, int index, void* data) {
	wyMWFileData* d = (wyMWFileData*)ptr;
	wyObjectRelease(d);
	return true;
}

wyMWManager::wyMWManager() :
		m_animationFileDataList(wyArrayNew(10)) {
}

wyMWManager::~wyMWManager() {
	releaseAllAnimationFileData();
	wyArrayDestroy(m_animationFileDataList);
	gMWManager = NULL;
}

wyMWManager* wyMWManager::getInstance() {
	if(gMWManager == NULL) {
		gMWManager = WYNEW wyMWManager();
	}
	return gMWManager;
}

void wyMWManager::releaseAllAnimationFileData() {
	wyArrayEach(m_animationFileDataList, releaseData, NULL);
	wyArrayClear(m_animationFileDataList);
}

wyMWFileData* wyMWManager::getAnimationFileDataWithPath(const char* path) {
	return getAnimationFileDataWithName(path);
}

wyMWFileData* wyMWManager::getAnimationFileData(int dataId) {
	for(int i = 0; i < m_animationFileDataList->num; i++){
		wyMWFileData* data = (wyMWFileData*)wyArrayGet(m_animationFileDataList, i);
		if(dataId == data->m_dataId) {
			return data;
		}
	}
	return NULL;
}

wyMWFileData* wyMWManager::getAnimationFileDataWithResId(int resId) {
	for(int i = 0; i < m_animationFileDataList->num; i++){
		wyMWFileData* data = (wyMWFileData*)wyArrayGet(m_animationFileDataList, i);
		if(resId == data->m_dataId) {
			return data;
		}
	}
	return NULL;
}

wyMWFileData* wyMWManager::getAnimationFileDataWithName(const char* mfsName) {
	unsigned int hash = wyUtils::strHash(mfsName);
	for(int i = 0; i < m_animationFileDataList->num; i++){
		wyMWFileData* data = (wyMWFileData*)wyArrayGet(m_animationFileDataList, i);
		if(hash == data->m_dataId) {
			return data;
		}
	}
	return NULL;
}

wyMWFileData* wyMWManager::load(int resId) {
	// search cache first
	wyMWFileData* data = getAnimationFileDataWithResId(resId);
	if(data != NULL) {
		return data;
	}

	// load data
	data = wyMWLoader::load(resId);
	if(data != NULL) {
		wyArrayPush(m_animationFileDataList, data);
		data->retain();
	}

	// return
	return data;
}

wyMWFileData* wyMWManager::load(const char* path, bool isFile) {
	// search cache first
	wyMWFileData* data = getAnimationFileDataWithPath(path);
	if(data != NULL) {
		return data;
	}

	// load data
	data = wyMWLoader::load(path, isFile);
	if(data != NULL) {
		wyArrayPush(m_animationFileDataList, data);
		data->retain();
	}

	// return
	return data;
}

wyMWFileData* wyMWManager::loadMemory(const char* mfsName) {
	// search cache first
	wyMWFileData* data = getAnimationFileDataWithName(mfsName);
	if(data != NULL) {
		return data;
	}

	// get data from memory file system
	data = wyMWLoader::loadMemory(mfsName);
	if(data != NULL) {
		wyArrayPush(m_animationFileDataList, data);
		data->retain();
	}

	// return
	return data;
}

float wyMWManager::resolve(short v) {
	return v * m_resScale;
}

bool wyMWManager::parseClip(wyMWFileData* animationFileData, int clipAdditionalDataIndex, wyMWClipType type, float clipPosX, float clipPosY, wyAFCClip* afcClip) {
	wyAFCClipData& afcClipData = afcClip->getData();

	// process based on clip type
	if(type % 2 == 0) {
		afcClip->setType(AFC_CLIP_IMAGE);

		// image index
		afcClipData.i.imageIndex = type / 8;

		// flip flag
		switch(type & 0x7) {
			case ClipType_ImageFlipX:
				afcClipData.i.flipX = true;
				break;
			case ClipType_ImageFlipY:
				afcClipData.i.flipX = true;
				afcClipData.i.rotation = 180;
				break;
			case ClipType_ImageFlipXY:
				afcClipData.i.rotation = 180;
				break;
		}

		// image rect in atlas
		afcClipData.i.rect = wyr(resolve(animationFileData->m_imageClipPool[clipAdditionalDataIndex * 4]),
				resolve(animationFileData->m_imageClipPool[clipAdditionalDataIndex * 4 + 1]),
				resolve(animationFileData->m_imageClipPool[clipAdditionalDataIndex * 4 + 2]),
				resolve(animationFileData->m_imageClipPool[clipAdditionalDataIndex * 4 + 3]));

		// in motion welder coordinate system, upper y axis is negative
		// we need to reverse it
		// don't resolve y again because clippos and image rect are all resolved before
		afcClipData.clipPos = wyp(clipPosX + afcClipData.i.rect.width / 2,
				-clipPosY - afcClipData.i.rect.height / 2);
	} else if(type == ClipType_CollisionRect) {
		afcClip->setType(AFC_CLIP_COLLISION_RECT);
		afcClipData.cr.size = wys(resolve(animationFileData->m_positionerRectangleClipPool[clipAdditionalDataIndex * 2]),
				resolve(animationFileData->m_positionerRectangleClipPool[clipAdditionalDataIndex * 2 + 1]));

		// in motion welder coordinate system, upper y axis is negative
		// we need to reverse it
		// don't resolve y again because clippos and image rect are all resolved before
		afcClipData.clipPos = wyp(clipPosX + afcClipData.cr.size.width / 2,
				-clipPosY - afcClipData.cr.size.height / 2);
	} else if(type == ClipType_Line) {
		afcClip->setType(AFC_CLIP_LINE);
		afcClipData.l.endPoint = wyp(resolve(animationFileData->m_lineClipPool[clipAdditionalDataIndex * 2]),
				resolve(animationFileData->m_lineClipPool[clipAdditionalDataIndex * 2 + 1]));
		afcClipData.l.color = animationFileData->m_lineClipPool[clipAdditionalDataIndex * 2 + 2];
		afcClipData.clipPos = wyp(clipPosX, -clipPosY);
	} else if(type == ClipType_Rect || type == ClipType_Rect_Filled) {
		afcClip->setType(AFC_CLIP_RECT);
		afcClipData.r.size = wys(resolve(animationFileData->m_rectangleClipPool[clipAdditionalDataIndex * 2]),
				resolve(animationFileData->m_rectangleClipPool[clipAdditionalDataIndex * 2 + 1]));
		afcClipData.r.color = animationFileData->m_rectangleClipPool[clipAdditionalDataIndex * 2 + 2];

		// in motion welder coordinate system, upper y axis is negative
		// we need to reverse it
		// don't resolve y again because clippos and image rect are all resolved before
		afcClipData.clipPos = wyp(clipPosX + afcClipData.r.size.width / 2,
				-clipPosY - afcClipData.r.size.height / 2);
	} else if(type == ClipType_RoundRect || type == ClipType_RoundRect_Filled) {
		afcClip->setType(AFC_CLIP_ROUNDRECT);
		afcClipData.rr.size = wys(resolve(animationFileData->m_roundedRectangleClipPool[clipAdditionalDataIndex * 2]),
				resolve(animationFileData->m_roundedRectangleClipPool[clipAdditionalDataIndex * 2 + 1]));
		afcClipData.rr.arcWidth = resolve(animationFileData->m_roundedRectangleClipPool[clipAdditionalDataIndex * 2 + 2]);
		afcClipData.rr.arcHeight = resolve(animationFileData->m_roundedRectangleClipPool[clipAdditionalDataIndex * 2 + 3]);
		afcClipData.rr.color = animationFileData->m_roundedRectangleClipPool[clipAdditionalDataIndex * 2 + 4];

		// in motion welder coordinate system, upper y axis is negative
		// we need to reverse it
		// don't resolve y again because clippos and image rect are all resolved before
		afcClipData.clipPos = wyp(clipPosX + afcClipData.rr.size.width / 2,
				-clipPosY - afcClipData.rr.size.height / 2);
	} else if(type == ClipType_Ecllipse || type == ClipType_Ecllipse_Filled) {
		afcClip->setType(AFC_CLIP_ELLIPSE);
		afcClipData.e.size = wys(resolve(animationFileData->m_ellipseClipPool[clipAdditionalDataIndex * 2]),
				resolve(animationFileData->m_ellipseClipPool[clipAdditionalDataIndex * 2 + 1]));
		afcClipData.e.startAngle = animationFileData->m_ellipseClipPool[clipAdditionalDataIndex * 2 + 2];
		afcClipData.e.endAngle = animationFileData->m_ellipseClipPool[clipAdditionalDataIndex * 2 + 3];
		afcClipData.e.color = animationFileData->m_ellipseClipPool[clipAdditionalDataIndex * 2 + 4];

		// in motion welder coordinate system, upper y axis is negative
		// we need to reverse it
		// don't resolve y again because clippos and image rect are all resolved before
		afcClipData.clipPos = wyp(clipPosX + afcClipData.e.size.width / 2,
				-clipPosY - afcClipData.e.size.height / 2);
	} else {
		return false;
	}

	return true;
}

wyAFCAnimation* wyMWManager::getAnimationData(wyMWFileData* animationFileData, int animIndex, wyAFCClipMapping* mapping) {
	wyAFCAnimation* afcAnim = wyAFCAnimation::make();

	unsigned short startFrame = animationFileData->m_animationTable[animIndex * 2];
	unsigned short endFrame = animationFileData->m_animationTable[animIndex * 2 + 1];
	unsigned short numberOfFrame = endFrame - startFrame + 1;

	// save current resource scale
	m_resScale = animationFileData->m_resScale;

	for(unsigned short i = 0; i < numberOfFrame; i++) {
		// create frame
		wyAFCFrame* afcFrame = wyAFCFrame::make();

		// set delay and incrementation
		int frameGlobalIndex = startFrame + i;
		afcFrame->setUseTickDelay(true);
		afcFrame->setDelay(animationFileData->m_frameTable[frameGlobalIndex * O_FRAMEDATA_NUM + 1]);
		afcFrame->setIncrementation(wyp(resolve(animationFileData->m_frameTable[frameGlobalIndex * O_FRAMEDATA_NUM + 2]),
				resolve(animationFileData->m_frameTable[frameGlobalIndex * O_FRAMEDATA_NUM + 3])));

		// get frame index in pool
		int frameInFrameTableIndex = animationFileData->m_frameTable[frameGlobalIndex * O_FRAMEDATA_NUM];
		unsigned short startFramePoolIndex = animationFileData->m_frameTableIndex[frameInFrameTableIndex * 2];
		unsigned short endFramePoolIndex = animationFileData->m_frameTableIndex[frameInFrameTableIndex * 2 + 1];

		// get number of clip in frame
		unsigned short noOfClip = (endFramePoolIndex - startFramePoolIndex + 1) / O_CLIPDATA_NUM;

		// load clip data
		for(unsigned short j = 0; j < noOfClip; j++) {
			wyAFCClip* afcClip = wyAFCClip::make();
			unsigned int startClipDataIndex = startFramePoolIndex + j * O_CLIPDATA_NUM;
			unsigned short clipAdditionalDataIndex = animationFileData->m_framePoolTable[startClipDataIndex];

			// get clip pos and type
			float clipPosX = resolve(animationFileData->m_framePoolTable[startClipDataIndex + 1]);
			float clipPosY = resolve(animationFileData->m_framePoolTable[startClipDataIndex + 2]);
			wyMWClipType type = (wyMWClipType)animationFileData->m_framePoolTable[startClipDataIndex + 3];

			// parse clip into afc clip
			if(!parseClip(animationFileData, clipAdditionalDataIndex, type, clipPosX, clipPosY, afcClip))
				continue;

			afcFrame->addClip(afcClip);
		}

		afcAnim->addFrame(afcFrame);
	}

	return afcAnim;
}
