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
#include "wySPXLoader.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include <stdlib.h>
#include "wyGlobal.h"
#include "wyLog.h"
#include "wySPXFrame.h"
#include "wySPXAction.h"
#include <math.h>

// sprite x file version, 3.3
#define SPX_VERSION 34

// endian
#define SPX_BIG_ENDIAN 1
#define SPX_LITTLE_ENDIAN 0

/// 当前解析的SpriteX文件的字节序
static bool s_bigEndian;

/// 当前正在解析的数据
static const char* s_data;

/// 当前指针位置
static int s_pos;

static short readShort() {
	short ret = *(short*)(s_data + s_pos);
	if(s_bigEndian)
		ret = betoh16(ret);
	else
		ret = letoh16(ret);
	s_pos += sizeof(short);
	return ret;
}

static int readInt() {
	int ret = *(int*)(s_data + s_pos);
	if(s_bigEndian)
		ret = betoh32(ret);
	else
		ret = letoh32(ret);
	s_pos += sizeof(int);
	return ret;
}

static int readByte() {
	return s_data[s_pos++] & 0xFF;
}

wySPXFileData* wySPXLoader::load(const char* data, size_t length, float resScale) {
	// verify sig
	s_data = data;
	if(s_data[0] != 'S' || s_data[1] != 'P' || s_data[2] != 'R' || s_data[3] != 'X') {
		LOGE("wySPXLoader::load: Invalid SpriteX file header");
		return NULL;
	}
	s_pos = 4;

	// verify version
	if(readByte() != SPX_VERSION) {
		LOGE("wySPXLoader::load: unsupported SpriteX file version: %d", s_data[s_pos]);
		return NULL;
	}

	// check byte order
	s_bigEndian = readByte() == SPX_BIG_ENDIAN;

	// create data object
	wySPXFileData* spx = wySPXFileData::make();

	// save scale
	spx->m_resScale = resScale;

	// get tile count
	spx->m_tileCount = readInt();

	// read all tile info
	spx->m_tiles = (wySPXTile*)wyMalloc(spx->m_tileCount * sizeof(wySPXTile));
	for(int i = 0; i < spx->m_tileCount; i++) {
		// read x, y, w, h
		spx->m_tiles[i].x = readShort();
		spx->m_tiles[i].y = readShort();
		spx->m_tiles[i].w = readShort();
		spx->m_tiles[i].h = readShort();
	}

	// get frame count
	spx->m_frameCount = readInt();

	// read all frames
	for(int i = 0; i < spx->m_frameCount; i++) {
		// create frame
		wySPXFrame* frame = WYNEW wySPXFrame();

		// read frame info
		frame->m_frameTileCount = readInt();
		frame->m_collisionCount = readInt();
		frame->m_referencePointCount = readInt();
		frame->m_height = abs(readShort() - readShort());
		frame->m_width = abs(readShort() - readShort());

		// read frame tiles
		if(frame->m_frameTileCount > 0) {
			frame->m_tiles = (wySPXFrameTile*)wyMalloc(sizeof(wySPXFrameTile) * frame->m_frameTileCount);
			for(int i = 0; i < frame->m_frameTileCount; i++) {
				frame->m_tiles[i].index = readShort();
				frame->m_tiles[i].x = readShort();
				frame->m_tiles[i].y = readShort();
				frame->m_tiles[i].transform = (wySPXTransform)readShort();
			}
		}

		// read frame collision
		if(frame->m_collisionCount) {
			frame->m_collisions = (wySPXCollision*)wyMalloc(sizeof(wySPXCollision) * frame->m_collisionCount);
			for(int i = 0; i < frame->m_collisionCount; i++) {
				frame->m_collisions[i].x = readShort();
				frame->m_collisions[i].y = readShort();
				frame->m_collisions[i].width = readShort();
				frame->m_collisions[i].height = readShort();
			}
		}

		// read frame reference points
		if(frame->m_referencePointCount > 0) {
			frame->m_refPoints = (wySPXReferencePoint*)wyMalloc(sizeof(wySPXReferencePoint) * frame->m_referencePointCount);
			for(int i = 0; i < frame->m_referencePointCount; i++) {
				frame->m_refPoints[i].x = readShort();
				frame->m_refPoints[i].y = readShort();
			}
		}

		// add frame
		wyArrayPush(spx->m_frames, frame);
	}

	// get action count
	spx->m_actionCount = readInt();

	// read all actions
	for(int i = 0; i < spx->m_actionCount; i++) {
		// create action
		wySPXAction* action = WYNEW wySPXAction();

		// read frame count
		action->m_frameCount = readInt();

		// read delay
		int delay = readByte();
		float duration = delay / 1000.f;
		bool uniformDelay = delay != 1;

		// read transform
		action->m_transform = (wySPXTransform)readInt();

		// read frame info
		int maxTile = 0;
		action->m_frames = (wySPXActionFrame*)wyMalloc(sizeof(wySPXActionFrame) * action->m_frameCount);
		for(int i = 0; i < action->m_frameCount; i++) {
			action->m_frames[i].index = readShort();
			if(uniformDelay)
				action->m_frames[i].duration = duration;
			else
				action->m_frames[i].duration = readShort() / 1000.f;

			// check max tile
			wySPXFrame* f = spx->getFrameAt(action->m_frames[i].index);
			maxTile = MAX(maxTile, f->m_frameTileCount);
		}

		// set max frame tile
		action->m_maxFrameTile = maxTile;

		// add action
		wyArrayPush(spx->m_actions, action);
	}

	return spx;
}

wySPXFileData* wySPXLoader::load(int spxResId) {
	size_t len;
	float scale;
	char* data = wyUtils::loadRaw(spxResId, &len, &scale);
	wySPXFileData* spx = load(data, len, scale);
	spx->m_dataId = spxResId;
	wyFree(data);
	return spx;
}

wySPXFileData* wySPXLoader::load(const char* spxPath, bool isFile) {
	size_t len;
	char* data = wyUtils::loadRaw(spxPath, isFile, &len);
	wySPXFileData* spx = load(data, len, wyDevice::density / wyDevice::defaultInDensity);
	spx->m_dataId = wyUtils::strHash(spxPath);
	wyFree(data);
	return spx;
}

wySPXFileData* wySPXLoader::loadMemory(const char* mfsName) {
	// get data from memory file system
	const char* mfsData = NULL;
	size_t length = 0;
	wyUtils::getFile(mfsName, &mfsData, &length);
	wySPXFileData* spx = load(mfsData, length, wyDevice::density / wyDevice::defaultInDensity);
	spx->m_dataId = wyUtils::strHash(mfsName);
	return spx;
}
