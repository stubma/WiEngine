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
#include "wyArcticManager.h"
#include "wyArcticLoader.h"
#include "wyArcticConstants.h"
#include "wyTypes.h"
#include "wyUtils.h"

wyArcticManager* gArcticManager = NULL;

wyArcticManager::wyArcticManager() :
		m_arcticFileDataList(wyArrayNew(10)),
		m_resScale(1) {
}

wyArcticManager::~wyArcticManager() {
	releaseAllAnimationFileData();
	wyArrayDestroy(m_arcticFileDataList);
	gArcticManager = NULL;
}

wyArcticManager* wyArcticManager::getInstance() {
	if(gArcticManager == NULL) {
		gArcticManager = WYNEW wyArcticManager();
	}
	return gArcticManager;
}

bool wyArcticManager::releaseData(wyArray* arr, void* ptr, int index, void* data) {
	((wyObject*)ptr)->release();
	return true;
}

void wyArcticManager::releaseAllAnimationFileData() {
	wyArrayEach(m_arcticFileDataList, releaseData, NULL);
	wyArrayClear(m_arcticFileDataList);
}

wyArcticFileData* wyArcticManager::load(int spxResId) {
	// search cache first
	wyArcticFileData* data = getArcticFileDataWithResId(spxResId);
	if(data != NULL) {
		return data;
	}

	data = wyArcticLoader::load(spxResId);
	if(data != NULL) {
		wyArrayPush(m_arcticFileDataList, data);
		data->retain();
	}

	return data;
}

wyArcticFileData* wyArcticManager::load(const char* spxPath, bool isFile) {
	// search cache first
	wyArcticFileData* data = getArcticFileDataWithName(spxPath);
	if(data != NULL) {
		return data;
	}

	data = wyArcticLoader::load(spxPath, isFile);
	if(data != NULL) {
		wyArrayPush(m_arcticFileDataList, data);
		data->retain();
	}

	return data;
}

wyArcticFileData* wyArcticManager::loadMemory(const char* mfsName) {
	// search cache first
	wyArcticFileData* data = getArcticFileDataWithName(mfsName);
	if(data != NULL) {
		return data;
	}

	data = wyArcticLoader::loadMemory(mfsName);
	if(data != NULL) {
		wyArrayPush(m_arcticFileDataList, data);
		data->retain();
	}

	return data;
}

wyArcticFileData* wyArcticManager::getArcticFileData(int dataId) {
	for(int i = 0; i < m_arcticFileDataList->num; i++){
		wyArcticFileData* data = (wyArcticFileData*)wyArrayGet(m_arcticFileDataList, i);
		if(dataId == data->m_dataId) {
			return data;
		}
	}
	return NULL;
}

wyArcticFileData* wyArcticManager::getArcticFileDataWithResId(int asResId) {
	for(int i = 0; i < m_arcticFileDataList->num; i++){
		wyArcticFileData* data = (wyArcticFileData*)wyArrayGet(m_arcticFileDataList, i);
		if(asResId == data->m_dataId) {
			return data;
		}
	}
	return NULL;
}

wyArcticFileData* wyArcticManager::getArcticFileDataWithName(const char* asPath) {
	unsigned int hash = wyUtils::strHash(asPath);
	for(int i = 0; i < m_arcticFileDataList->num; i++){
		wyArcticFileData* data = (wyArcticFileData*)wyArrayGet(m_arcticFileDataList, i);
		if(hash == data->m_dataId) {
			return data;
		}
	}
	return NULL;
}

float wyArcticManager::resolve(short v) {
	return v * m_resScale;
}

void wyArcticManager::parseModule(wyArcticModule* arcticModule, wyArcticFrameModule* arcticFrameModule, wyAFCClip* afcClip, int index, int offsetX, int offsetY) {
	wyAFCClipData& afcClipData = afcClip->getData();

	// set type
	afcClip->setType(AFC_CLIP_IMAGE);

	// set index
	afcClip->setIndex(index);

	// image index
	afcClipData.i.imageIndex = arcticModule->imageIndex;

	// clip pos
	// ASprite y axis is reversed with opengl y axis, and origin is top left corner
	afcClipData.clipPos = wyp(resolve(arcticFrameModule->x + arcticModule->w / 2 + offsetX),
			resolve(-arcticFrameModule->y - arcticModule->h / 2 - offsetY));

	// save image rect
	afcClipData.i.rect = wyr(resolve(arcticModule->x), resolve(arcticModule->y), resolve(arcticModule->w), resolve(arcticModule->h));

	// set flip flag
	afcClipData.i.flipX = (arcticFrameModule->flags & AS_FLIP_X) != 0;
	if((arcticFrameModule->flags & AS_FLIP_Y) != 0) {
		afcClipData.i.flipX = !afcClipData.i.flipX;
		afcClipData.i.rotation = 180;
	}
}

void wyArcticManager::parseFrameModules(wyArcticFileData* afd, wyArcticFrame* arcticFrame, wyAFCFrame* afcFrame, int offsetX, int offsetY, wyAFCClipMapping* mapping) {
	for(int j = 0; j < arcticFrame->moduleCount; j++) {
		wyAFCClip* afcClip = wyAFCClip::make();
		
		// arctic frame module
		wyArcticFrameModule* arcticFrameModule = afd->m_frameModules + j + arcticFrame->firstModuleIndex;
		
		// index, maybe module or hyper frame
		int index = ((arcticFrameModule->flags & AS_INDEX_EX_MASK) << AS_INDEX_EX_SHIFT) | arcticFrameModule->index;
		
		// is hyper frame?
		if((arcticFrameModule->flags & AS_HYPER_FM) != 0) {
			wyArcticFrame* hyperFrame = afd->m_frames + index;
			parseFrameModules(afd, hyperFrame, afcFrame, arcticFrameModule->x, arcticFrameModule->y, mapping);
		} else {
			// need search clip mapping first
			wyAFCClipMappingRule* rule = NULL;
			if(mapping)
				rule = mapping->findRule(index);
			
			// depend on this rule, build clip way different
			if(!rule) {
				// arctic module
				wyArcticModule* arcticModule = afd->m_modules + index;
				parseModule(arcticModule, arcticFrameModule, afcClip, index, offsetX, offsetY);

				// set index
				afcClip->setIndex(index);
			} else {
				switch(rule->type) {
					case AFC_CMR_INTERNAL_CLIP:
					{
						// if internal mapping, redirect clip index
						if(rule)
							index = rule->icr.destClipIndex;

						// arctic module
						wyArcticModule* arcticModule = afd->m_modules + index;
						parseModule(arcticModule, arcticFrameModule, afcClip, index, offsetX, offsetY);

						break;
					}
					case AFC_CMR_EXTERNAL_CLIP:
					{
						// get external file data
						wyArcticFileData* externalAFD = getArcticFileData(rule->ecr.dataId);
						if(!externalAFD)
							continue;

						// parse arctic module
						wyArcticModule* arcticModule = externalAFD->m_modules + rule->ecr.destClipIndex;
						parseModule(arcticModule, arcticFrameModule, afcClip, rule->ecr.destClipIndex, offsetX, offsetY);

						// need redirect sheet to external sheet
						afcClip->getData().i.sheet = rule->ecr.sheet;

						break;
					}
					case AFC_CMR_EXTERNAL_ATLAS:
					{
						wyAFCClipData& clipData = afcClip->getData();

						// sheet
						clipData.i.sheet = rule->ear.sheet;

						// clip pos
						clipData.clipPos = wyp(resolve(arcticFrameModule->x) + rule->ear.pos.x,
								resolve(-arcticFrameModule->y) + rule->ear.pos.y);

						// clip image rect
						clipData.i.rect = rule->ear.texRect;

						// flip flag
						clipData.i.flipX = rule->ear.flipX;
						clipData.i.rotation = rule->ear.rotation;

						break;
					}
				}
			}
			
			// add clip
			afcFrame->addClip(afcClip);
		}
	}
	
	// collision rects
	if(arcticFrame->collisionRectCount > 0) {
		wyRect* cr = arcticFrame->collisionRects;
		for(int i = 0; i < arcticFrame->collisionRectCount; i++, cr++) {
			wyAFCClip* afcClip = wyAFCClip::make();
			wyAFCClipData& afcClipData = afcClip->getData();
			
			// set type
			afcClip->setType(AFC_CLIP_COLLISION_RECT);
			
			// clip pos
			// ASprite y axis is reversed with opengl y axis, and origin is top left corner
			afcClipData.clipPos = wyp(resolve(cr->x + cr->width / 2 + offsetX),
					resolve(-cr->y - cr->height / 2 - offsetY));
			
			// set rect
			afcClipData.cr.size = wys(resolve(cr->width), resolve(cr->height));
			
			// add clip
			afcFrame->addClip(afcClip);
		}
	}
}

wyAFCAnimation* wyArcticManager::getAnimationData(wyArcticFileData* afd, int animIndex, wyAFCClipMapping* mapping) {
	wyAFCAnimation* afcAnim = wyAFCAnimation::make();

	// save scale
	m_resScale = afd->m_resScale;

	// current action
	wyArcticAnimation* arcticAnim = afd->m_animations + animIndex;

	// read all frames
	float prevOffsetX = 0;
	float prevOffsetY = 0;
	for(int i = 0; i < arcticAnim->frameCount; i++) {
		// create frame
		wyAFCFrame* afcFrame = wyAFCFrame::make();

		// animation frame
		wyArcticAnimationFrame* arcticAnimFrame = afd->m_animationFrames + i + arcticAnim->firstFrameIndex;

		// set delay
		afcFrame->setUseTickDelay(true);
		afcFrame->setDelay(arcticAnimFrame->delay);

		// save offset, we need convert it to offset relative to previous frame
		// arctic y axis is reversed to opengl y axis, so negate it
		if(i > 0) {
			afcFrame->setIncrementation(wyp(resolve(arcticAnimFrame->offsetX - prevOffsetX), resolve(-arcticAnimFrame->offsetY - prevOffsetY)));
		}
		prevOffsetX = arcticAnimFrame->offsetX;
		prevOffsetY = -arcticAnimFrame->offsetY;

		// arctic frame
		int index = ((arcticAnimFrame->flags & AS_INDEX_EX_MASK) << AS_INDEX_EX_SHIFT) | arcticAnimFrame->index;
		wyArcticFrame* arcticFrame = afd->m_frames + index;

		// if frame flipped?
		afcFrame->setFlipX((arcticAnimFrame->flags & AS_FLIP_X) != 0);
		afcFrame->setFlipY((arcticAnimFrame->flags & AS_FLIP_Y) != 0);

		// read all modules
		parseFrameModules(afd, arcticFrame, afcFrame, 0, 0, mapping);

		// add frame
		afcAnim->addFrame(afcFrame);
	}

	return afcAnim;
}
