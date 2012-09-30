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
#include "wyAuroraManager.h"
#include "wyAuroraLoader.h"
#include "wyAuroraConstants.h"
#include "wyTypes.h"
#include "wyUtils.h"

wyAuroraManager* gAuroraManager = NULL;

wyAuroraManager::wyAuroraManager() :
		m_auroraFileDataList(wyArrayNew(10)),
		m_resScale(1) {
}

wyAuroraManager::~wyAuroraManager() {
	releaseAllAnimationFileData();
	wyArrayDestroy(m_auroraFileDataList);
	gAuroraManager = NULL;
}

wyAuroraManager* wyAuroraManager::getInstance() {
	if(gAuroraManager == NULL) {
		gAuroraManager = WYNEW wyAuroraManager();
	}
	return gAuroraManager;
}

bool wyAuroraManager::releaseData(wyArray* arr, void* ptr, int index, void* data) {
	((wyObject*)ptr)->release();
	return true;
}

void wyAuroraManager::releaseAllAnimationFileData() {
	wyArrayEach(m_auroraFileDataList, releaseData, NULL);
	wyArrayClear(m_auroraFileDataList);
}

wyAuroraFileData* wyAuroraManager::load(int spxResId) {
	// search cache first
	wyAuroraFileData* data = getAuroraFileDataWithResId(spxResId);
	if(data != NULL) {
		return data;
	}

	data = wyAuroraLoader::load(spxResId);
	if(data != NULL) {
		wyArrayPush(m_auroraFileDataList, data);
		data->retain();
	}

	return data;
}

wyAuroraFileData* wyAuroraManager::load(const char* spxPath, bool isFile) {
	// search cache first
	wyAuroraFileData* data = getAuroraFileDataWithName(spxPath);
	if(data != NULL) {
		return data;
	}

	data = wyAuroraLoader::load(spxPath, isFile);
	if(data != NULL) {
		wyArrayPush(m_auroraFileDataList, data);
		data->retain();
	}

	return data;
}

wyAuroraFileData* wyAuroraManager::loadMemory(const char* mfsName) {
	// search cache first
	wyAuroraFileData* data = getAuroraFileDataWithName(mfsName);
	if(data != NULL) {
		return data;
	}

	data = wyAuroraLoader::loadMemory(mfsName);
	if(data != NULL) {
		wyArrayPush(m_auroraFileDataList, data);
		data->retain();
	}

	return data;
}

wyAuroraFileData* wyAuroraManager::getAuroraFileData(int dataId) {
	for(int i = 0; i < m_auroraFileDataList->num; i++){
		wyAuroraFileData* data = (wyAuroraFileData*)wyArrayGet(m_auroraFileDataList, i);
		if(dataId == data->m_dataId) {
			return data;
		}
	}
	return NULL;
}

wyAuroraFileData* wyAuroraManager::getAuroraFileDataWithResId(int asResId) {
	for(int i = 0; i < m_auroraFileDataList->num; i++){
		wyAuroraFileData* data = (wyAuroraFileData*)wyArrayGet(m_auroraFileDataList, i);
		if(asResId == data->m_dataId) {
			return data;
		}
	}
	return NULL;
}

wyAuroraFileData* wyAuroraManager::getAuroraFileDataWithName(const char* asPath) {
	unsigned int hash = wyUtils::strHash(asPath);
	for(int i = 0; i < m_auroraFileDataList->num; i++){
		wyAuroraFileData* data = (wyAuroraFileData*)wyArrayGet(m_auroraFileDataList, i);
		if(hash == data->m_dataId) {
			return data;
		}
	}
	return NULL;
}

float wyAuroraManager::resolve(short v) {
	return v * m_resScale;
}

void wyAuroraManager::parseModule(wyAuroraModule* auroraModule, wyAuroraFrameModule* auroraFrameModule, wyAFCClip* afcClip, int index, int offsetX, int offsetY) {
	wyAFCClipData& afcClipData = afcClip->getData();

	// set index
	afcClip->setIndex(index);

	// set module info
	switch(auroraModule->type) {
		case BSM_IMAGE:
			// set type
			afcClip->setType(AFC_CLIP_IMAGE);

			// image index
			afcClipData.i.imageIndex = auroraModule->imageIndex;

			// clip pos
			// BSprite y axis is reversed with opengl y axis, and origin is top left corner
			afcClipData.clipPos = wyp(resolve(auroraFrameModule->x + auroraModule->w / 2 + offsetX),
					resolve(-auroraFrameModule->y - auroraModule->h / 2 - offsetY));

			// save image rect
			afcClipData.i.rect = wyr(resolve(auroraModule->x), resolve(auroraModule->y),
					resolve(auroraModule->w), resolve(auroraModule->h));

			// set flip flag
			afcClipData.i.flipX = (auroraFrameModule->flags & BS_FLIP_X) != 0;
			if((auroraFrameModule->flags & BS_FLIP_Y) != 0) {
				afcClipData.i.flipX = !afcClipData.i.flipX;
				afcClipData.i.rotation = 180;
			}

			break;
		case BSM_RECT:
			// set type
			afcClip->setType(AFC_CLIP_RECT);

			// clip pos
			// BSprite y axis is reversed with opengl y axis, and origin is top left corner
			afcClipData.clipPos = wyp(resolve(auroraFrameModule->x + auroraModule->w / 2 + offsetX),
					resolve(-auroraFrameModule->y - auroraModule->h / 2 - offsetY));

			// set rect size
			afcClipData.r.size.width = resolve(auroraModule->w);
			afcClipData.r.size.height = resolve(auroraModule->h);

			break;
		case BSM_FILL_RECT:
			// set type
			afcClip->setType(AFC_CLIP_RECT);

			// clip pos
			// BSprite y axis is reversed with opengl y axis, and origin is top left corner
			afcClipData.clipPos = wyp(resolve(auroraFrameModule->x + auroraModule->w / 2 + offsetX),
					resolve(-auroraModule->h / 2 - auroraFrameModule->y - offsetY));

			// set rect size
			afcClipData.r.size.width = resolve(auroraModule->w);
			afcClipData.r.size.height = resolve(auroraModule->h);

			// set color
			afcClipData.r.color = auroraModule->color;

			break;
	}
}

void wyAuroraManager::parseFrameModules(wyAuroraFileData* afd, wyAuroraFrame* auroraFrame, wyAFCFrame* afcFrame, int offsetX, int offsetY, wyAFCClipMapping* mapping) {
	for(int j = 0; j < auroraFrame->moduleCount; j++) {
		wyAFCClip* afcClip = wyAFCClip::make();
		
		// aurora frame module
		wyAuroraFrameModule* auroraFrameModule = afd->m_frameModules + j + auroraFrame->firstModuleIndex;
		
		// get index, maybe module or frame index
		int index = ((auroraFrameModule->flags & BS_INDEX_EX_MASK) << BS_INDEX_EX_SHIFT) | auroraFrameModule->index;
		
		// is hyper frame?
		if((auroraFrameModule->flags & BS_HYPER_FM) != 0) {
			wyAuroraFrame* hyperFrame = afd->m_frames + index;
			parseFrameModules(afd, hyperFrame, afcFrame, auroraFrameModule->x, auroraFrameModule->y, mapping);
		} else {
			// need search clip mapping first
			wyAFCClipMappingRule* rule = NULL;
			if(mapping)
				rule = mapping->findRule(index);
			
			// depend on this rule, build clip way different
			if(!rule) {
				// parse aurora module
				wyAuroraModule* auroraModule = afd->m_modules + index;
				parseModule(auroraModule, auroraFrameModule, afcClip, index, offsetX, offsetY);
			} else {
				switch(rule->type) {
					case AFC_CMR_INTERNAL_CLIP:
					{
						// redirect index
						index = rule->icr.destClipIndex;
						
						// parse aurora module
						wyAuroraModule* auroraModule = afd->m_modules + index;
						parseModule(auroraModule, auroraFrameModule, afcClip, index, offsetX, offsetY);
						break;
					}
					case AFC_CMR_EXTERNAL_CLIP:
					{
						// get external file data
						wyAuroraFileData* externalAFD = getAuroraFileData(rule->ecr.dataId);
						if(!externalAFD)
							continue;

						// parse aurora module
						wyAuroraModule* auroraModule = externalAFD->m_modules + rule->ecr.destClipIndex;
						parseModule(auroraModule, auroraFrameModule, afcClip, rule->ecr.destClipIndex, offsetX, offsetY);
						
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
						clipData.clipPos = wyp(resolve(auroraFrameModule->x) + rule->ear.pos.x,
								resolve(-auroraFrameModule->y) + rule->ear.pos.y);
						
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
}

wyAFCAnimation* wyAuroraManager::getAnimationData(wyAuroraFileData* afd, int animIndex, wyAFCClipMapping* mapping) {
	wyAFCAnimation* afcAnim = wyAFCAnimation::make();

	// save scale
	m_resScale = afd->m_resScale;

	// current action
	wyAuroraAnimation* auroraAnim = afd->m_animations + animIndex;

	// read all frames
	float prevOffsetX = 0;
	float prevOffsetY = 0;
	wyRect* collisionRect = afd->m_collisionRects;
	for(int i = 0; i < auroraAnim->frameCount; i++) {
		// create frame
		wyAFCFrame* afcFrame = wyAFCFrame::make();

		// animation frame
		wyAuroraAnimationFrame* auroraAnimFrame = afd->m_animationFrames + i + auroraAnim->firstFrameIndex;

		// set delay
		afcFrame->setUseTickDelay(true);
		afcFrame->setDelay(auroraAnimFrame->delay);

		// save offset, we need convert it to offset relative to previous frame
		// aurora y axis is reversed to opengl y axis, so negate it
		if(i > 0) {
			afcFrame->setIncrementation(wyp(resolve(auroraAnimFrame->offsetX - prevOffsetX), resolve(-auroraAnimFrame->offsetY - prevOffsetY)));
		}
		prevOffsetX = auroraAnimFrame->offsetX;
		prevOffsetY = -auroraAnimFrame->offsetY;

		// aurora frame
		int index = ((auroraAnimFrame->flags & BS_INDEX_EX_MASK) << BS_INDEX_EX_SHIFT) | auroraAnimFrame->index;
		wyAuroraFrame* auroraFrame = afd->m_frames + index;

		// if frame flipped?
		afcFrame->setFlipX((auroraAnimFrame->flags & BS_FLIP_X) != 0);
		afcFrame->setFlipY((auroraAnimFrame->flags & BS_FLIP_Y) != 0);

		// read all modules
		parseFrameModules(afd, auroraFrame, afcFrame, 0, 0, mapping);

		// add collision rects
		for(int j = 0; j < auroraFrame->collisionRectCount; j++, collisionRect++) {
			// create clip
			wyAFCClip* afcClip = wyAFCClip::make();
			wyAFCClipData& afcClipData = afcClip->getData();

			// set type
			afcClip->setType(AFC_CLIP_COLLISION_RECT);

			// set clip pos
			afcClipData.clipPos = wyp(resolve(collisionRect->x + collisionRect->width / 2),
					resolve(-collisionRect->y - collisionRect->height / 2));

			// set rect size
			afcClipData.cr.size.width = resolve(collisionRect->width);
			afcClipData.cr.size.height = resolve(collisionRect->height);

			// add clip
			afcFrame->addClip(afcClip);
		}

		// add frame
		afcAnim->addFrame(afcFrame);
	}

	return afcAnim;
}
