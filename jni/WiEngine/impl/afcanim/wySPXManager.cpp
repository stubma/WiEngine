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
#include "wySPXManager.h"
#include "wySPXLoader.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
wySPXManager* gSPXManager = NULL;

wySPXManager::wySPXManager() :
		m_spxFileDataList(wyArrayNew(10)),
		m_resScale(1) {
}

wySPXManager::~wySPXManager() {
	releaseAllAnimationFileData();
	wyArrayDestroy(m_spxFileDataList);
	gSPXManager = NULL;
}

wySPXManager* wySPXManager::getInstance() {
	if(gSPXManager == NULL) {
		gSPXManager = WYNEW wySPXManager();
	}
	return gSPXManager;
}

bool wySPXManager::releaseData(wyArray* arr, void* ptr, int index, void* data) {
	((wyObject*)ptr)->release();
	return true;
}

void wySPXManager::releaseAllAnimationFileData() {
	wyArrayEach(m_spxFileDataList, releaseData, NULL);
	wyArrayClear(m_spxFileDataList);
}

wySPXFileData* wySPXManager::load(int spxResId) {
	// search cache first
	wySPXFileData* data = getSPXFileDataWithResId(spxResId);
	if(data != NULL) {
		return data;
	}

	data = wySPXLoader::load(spxResId);
	if(data != NULL) {
		wyArrayPush(m_spxFileDataList, data);
		data->retain();
	}

	return data;
}

wySPXFileData* wySPXManager::load(const char* spxPath, bool isFile) {
	// search cache first
	wySPXFileData* data = getSPXFileDataWithName(spxPath);
	if(data != NULL) {
		return data;
	}

	data = wySPXLoader::load(spxPath, isFile);
	if(data != NULL) {
		wyArrayPush(m_spxFileDataList, data);
		data->retain();
	}

	return data;
}

wySPXFileData* wySPXManager::loadMemory(const char* mfsName) {
	// search cache first
	wySPXFileData* data = getSPXFileDataWithName(mfsName);
	if(data != NULL) {
		return data;
	}

	data = wySPXLoader::loadMemory(mfsName);
	if(data != NULL) {
		wyArrayPush(m_spxFileDataList, data);
		data->retain();
	}

	return data;
}

wySPXFileData* wySPXManager::getSPXFileData(int dataId) {
	for(int i = 0; i < m_spxFileDataList->num; i++){
		wySPXFileData* data = (wySPXFileData*)wyArrayGet(m_spxFileDataList, i);
		if(dataId == data->m_dataId) {
			return data;
		}
	}
	return NULL;
}

wySPXFileData* wySPXManager::getSPXFileDataWithResId(int spxResId) {
	for(int i = 0; i < m_spxFileDataList->num; i++){
		wySPXFileData* data = (wySPXFileData*)wyArrayGet(m_spxFileDataList, i);
		if(spxResId == data->m_dataId) {
			return data;
		}
	}
	return NULL;
}

wySPXFileData* wySPXManager::getSPXFileDataWithName(const char* spxPath) {
	unsigned int hash = wyUtils::strHash(spxPath);
	for(int i = 0; i < m_spxFileDataList->num; i++){
		wySPXFileData* data = (wySPXFileData*)wyArrayGet(m_spxFileDataList, i);
		if(hash == data->m_dataId) {
			return data;
		}
	}
	return NULL;
}

float wySPXManager::resolve(short v) {
	return v * m_resScale;
}

void wySPXManager::parseTile(wySPXTile* spxTile, wySPXFrameTile* spxFrameTile, wyAFCClip* afcClip, int index) {
	wyAFCClipData& afcClipData = afcClip->getData();

	// set type
	afcClip->setType(AFC_CLIP_IMAGE);

	// clip index
	afcClip->setIndex(index);

	// image index
	afcClipData.i.imageIndex = 0;

	// image rect
	afcClipData.i.rect = wyr(resolve(spxTile->x), resolve(spxTile->y), resolve(spxTile->w), resolve(spxTile->h));

	// transform
	switch(spxFrameTile->transform) {
		case SPX_TRANS_MIRROR_ROT180:
			afcClipData.i.flipX = true;
			afcClipData.i.rotation = 180;
			break;
		case SPX_TRANS_MIRROR:
			afcClipData.i.flipX = true;
			break;
		case SPX_TRANS_ROT180:
			afcClipData.i.rotation = 180;
			break;
		case SPX_TRANS_MIRROR_ROT270:
			afcClipData.i.flipX = true;
			afcClipData.i.rotation = 270;
			break;
		case SPX_TRANS_ROT90:
			afcClipData.i.rotation = 90;
			break;
		case SPX_TRANS_ROT270:
			afcClipData.i.rotation = 270;
			break;
		case SPX_TRANS_MIRROR_ROT90:
			afcClipData.i.flipX = true;
			afcClipData.i.rotation = 90;
			break;
	}

	// set clip center position
	// SpriteX y axis is reversed with opengl y axis, and tile pos is top left corner
	// because we want to get center position, must consider the texture rect size based on rotation
	switch(spxFrameTile->transform) {
		case SPX_TRANS_NONE:
		case SPX_TRANS_MIRROR_ROT180:
		case SPX_TRANS_MIRROR:
		case SPX_TRANS_ROT180:
			afcClipData.clipPos = wyp(resolve(spxFrameTile->x + spxTile->w / 2), resolve(-spxFrameTile->y - spxTile->h / 2));
			break;
		case SPX_TRANS_MIRROR_ROT270:
		case SPX_TRANS_ROT90:
		case SPX_TRANS_ROT270:
		case SPX_TRANS_MIRROR_ROT90:
			afcClipData.clipPos = wyp(resolve(spxFrameTile->x + spxTile->h / 2), resolve(-spxFrameTile->y - spxTile->w / 2));
			break;
	}
}

wyAFCAnimation* wySPXManager::getAnimationData(wySPXFileData* spx, int animIndex, wyAFCClipMapping* mapping) {
	wyAFCAnimation* afcAnim = wyAFCAnimation::make();

	// save scale
	m_resScale = spx->m_resScale;

	// current action
	wySPXAction* spxAction = spx->getActionAt(animIndex);

	// read all frames
	for(int i = 0; i < spxAction->m_frameCount; i++) {
		// create frame
		wyAFCFrame* afcFrame = wyAFCFrame::make();

		// spx frame in action
		wySPXActionFrame* spxActionFrame = spxAction->m_frames + i;

		// set delay
		afcFrame->setDelay(spxActionFrame->duration);

		// spx frame
		wySPXFrame* spxFrame = spx->getFrameAt(spxActionFrame->index);

		// read all image clip
		for(int j = 0; j < spxFrame->m_frameTileCount; j++) {
			wyAFCClip* afcClip = wyAFCClip::make();

			// tile in frame
			wySPXFrameTile* spxFrameTile = spxFrame->m_tiles + j;

			// need search clip mapping first
			int index = spxFrameTile->index;
			wyAFCClipMappingRule* rule = NULL;
			if(mapping)
				rule = mapping->findRule(index);

			if(!rule) {
				// parse tile into afc clip
				wySPXTile* spxTile = spx->m_tiles + index;
				parseTile(spxTile, spxFrameTile, afcClip, index);
			} else {
				switch(rule->type) {
					case AFC_CMR_INTERNAL_CLIP:
					{
						// if internal mapping, redirect clip index
						if(rule)
							index = rule->icr.destClipIndex;

						// parse tile into afc clip
						wySPXTile* spxTile = spx->m_tiles + index;
						parseTile(spxTile, spxFrameTile, afcClip, index);

						break;
					}
					case AFC_CMR_EXTERNAL_CLIP:
					{
						// get external file data
						wySPXFileData* externalAFD = getSPXFileData(rule->ecr.dataId);
						if(!externalAFD)
							continue;

						// parse arctic module
						wySPXTile* spxTile = externalAFD->m_tiles + rule->ecr.destClipIndex;
						parseTile(spxTile, spxFrameTile, afcClip, rule->ecr.destClipIndex);

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
						clipData.clipPos = wyp(resolve(spxFrameTile->x) + rule->ear.pos.x,
								resolve(-spxFrameTile->y) + rule->ear.pos.y);

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

		// real all collision clip
		for(int j = 0; j < spxFrame->m_collisionCount; j++) {
			wyAFCClip* afcClip = wyAFCClip::make();
			wyAFCClipData& afcClipData = afcClip->getData();

			// spx collision
			wySPXCollision* spxCollision = spxFrame->m_collisions + j;

			// set type
			afcClip->setType(AFC_CLIP_COLLISION_RECT);

			// set clip pos
			// SpriteX y axis is reversed with opengl y axis, and tile pos is top left corner
			afcClipData.clipPos = wyp(resolve(spxCollision->x + spxCollision->width / 2), resolve(-spxCollision->y - spxCollision->height / 2));

			// collision rect
			afcClipData.cr.size = wys(resolve(spxCollision->width), resolve(spxCollision->height));

			// add clip
			afcFrame->addClip(afcClip);
		}

		// real all point clip
		for(int j = 0; j < spxFrame->m_referencePointCount; j++) {
			wyAFCClip* afcClip = wyAFCClip::make();
			wyAFCClipData& afcClipData = afcClip->getData();

			// reference point
			wySPXReferencePoint* spxRefPoint = spxFrame->m_refPoints + j;

			// set type
			afcClip->setType(AFC_CLIP_POINT);

			// set clip pos
			afcClipData.clipPos = wyp(resolve(spxRefPoint->x), resolve(-spxRefPoint->y));

			// add clip
			afcFrame->addClip(afcClip);
		}

		// add frame
		afcAnim->addFrame(afcFrame);
	}

	return afcAnim;
}
