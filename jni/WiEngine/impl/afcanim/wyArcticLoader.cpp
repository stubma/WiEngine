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
#include "wyArcticLoader.h"
#include "wyArcticConstants.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include <stdlib.h>
#include "wyGlobal.h"
#include "wyLog.h"
#include <math.h>

/// data is in parsing
static const char* s_data;

/// position of read
static int s_pos;

static int readByte() {
	return s_data[s_pos++] & 0xFF;
}

static short readShort() {
	short ret = *(short*)(s_data + s_pos);
	ret = letoh16(ret);
	s_pos += sizeof(short);
	return ret;
}

static int readInt() {
	int ret = *(int*)(s_data + s_pos);
	ret = letoh32(ret);
	s_pos += sizeof(int);
	return ret;
}

static void skip(size_t len) {
	s_pos += len;
}

wyArcticFileData* wyArcticLoader::load(const char* data, size_t length, float resScale) {
	wyArcticFileData* afd = wyArcticFileData::make();
	s_data = data;
	s_pos = 0;

	// set scale
	afd->m_resScale = resScale;

	// version
	afd->m_version = readShort();

	// skip id for other editor
	if(afd->m_version > 0x30)
		skip(4);

	// flags
	afd->m_flags = readInt();

	// read all modules
	if((afd->m_flags & AS_MODULES) != 0) {
		// module count
		afd->m_moduleCount = readShort();

		if(afd->m_moduleCount > 0) {
			// allocate memory
			afd->m_modules = (wyArcticModule*)wyCalloc(afd->m_moduleCount, sizeof(wyArcticModule));

			for(int i = 0; i < afd->m_moduleCount; i++) {
				wyArcticModule* module = afd->m_modules + i;

				// image index
				if((afd->m_flags & AS_MODULES_IMG) != 0) {
					module->imageIndex = readByte();
				}

				// location
				if((afd->m_flags & AS_MODULES_XY) != 0) {
					if((afd->m_flags & AS_MODULES_XY_SHORT) != 0) {
						module->x = readShort();
						module->y = readShort();
					} else {
						module->x = readByte();
						module->y = readByte();
					}
				}

				// size
				if((afd->m_flags & AS_MODULES_WH_SHORT) != 0) {
					module->w = readShort();
					module->h = readShort();
				} else {
					module->w = readByte();
					module->h = readByte();
				}
			}
		}
	}

	// read all frames
	if((afd->m_flags & AS_FRAMES) != 0) {
		// count of frame modules
		afd->m_frameModuleCount = readShort();

		// read all frame modules
		if(afd->m_frameModuleCount > 0) {
			afd->m_frameModules = (wyArcticFrameModule*)wyCalloc(afd->m_frameModuleCount, sizeof(wyArcticFrameModule));
			for(int i = 0; i < afd->m_frameModuleCount; i++) {
				wyArcticFrameModule* fm = afd->m_frameModules + i;
				fm->index = readByte();
				if((afd->m_flags & AS_FM_OFF_SHORT) != 0) {
					fm->x = readShort();
					fm->y = readShort();
				} else {
					fm->x = readByte();
					fm->y = readByte();
				}
				fm->flags = readByte();
			}
		}

		// count of frames
		afd->m_frameCount = readShort();

		// read all frames
		if(afd->m_frameCount > 0) {
			afd->m_frames = (wyArcticFrame*)wyCalloc(afd->m_frameCount, sizeof(wyArcticFrame));
			for(int i = 0; i < afd->m_frameCount; i++) {
				wyArcticFrame* f = afd->m_frames + i;
				f->moduleCount = readByte();
				f->firstModuleIndex = readShort();
			}
		}
		
		// read collision rect of this frame
		if((afd->m_flags & AS_FRAME_COL_RC) != 0) {
			for(int i = 0; i < afd->m_frameCount; i++) {
				wyArcticFrame* f = afd->m_frames + i;
				f->collisionRectCount = readByte();
				if(f->collisionRectCount > 0) {
					f->collisionRects = (wyRect*)wyCalloc(f->collisionRectCount, sizeof(wyRect));
					wyRect* r = f->collisionRects;
					for(int j = 0; j < f->collisionRectCount; j++, r++) {
						r->x = readShort();
						r->y = readShort();
						r->width = readShort();
						r->height = readShort();
					}
				}
			}
		}
	}

	// read all animations
	if((afd->m_flags & AS_ANIMS) != 0) {
		// count of animation frames
		afd->m_animationFrameCount = readShort();

		// read all animation frames
		if(afd->m_animationFrameCount > 0) {
			afd->m_animationFrames = (wyArcticAnimationFrame*)wyCalloc(afd->m_animationFrameCount, sizeof(wyArcticAnimationFrame));
			for(int i = 0; i < afd->m_animationFrameCount; i++) {
				wyArcticAnimationFrame* af = afd->m_animationFrames + i;
				af->index = readByte();
				af->delay = readByte();
				if((afd->m_flags & AS_AF_OFF_SHORT) != 0) {
					af->offsetX = readShort();
					af->offsetY = readShort();
				} else {
					af->offsetX = readByte();
					af->offsetY = readByte();
				}
				af->flags = readByte();
			}
		}

		// count of animations
		afd->m_animationCount = readShort();

		// read all animations
		if(afd->m_animationCount > 0) {
			afd->m_animations = (wyArcticAnimation*)wyCalloc(afd->m_animationCount, sizeof(wyArcticAnimation));
			for(int i = 0; i < afd->m_animationCount; i++) {
				wyArcticAnimation* a = afd->m_animations + i;
				
				// number of animation frame
				if((afd->m_flags & AS_AF_NUM_SHORT) != 0) 
					a->frameCount = readShort();
				else
					a->frameCount = readByte();
				
				// first animation index
				a->firstFrameIndex = readShort();
			}
		}
	}

	return afd;
}

wyArcticFileData* wyArcticLoader::load(int asResId) {
	size_t len;
	float scale;
	char* data = wyUtils::loadRaw(asResId, &len, &scale);
	wyArcticFileData* as = load(data, len, scale);
	as->m_dataId = asResId;
	wyFree(data);
	return as;
}

wyArcticFileData* wyArcticLoader::load(const char* asPath, bool isFile) {
	size_t len;
	char* data = wyUtils::loadRaw(asPath, isFile, &len);
	wyArcticFileData* as = load(data, len, wyDevice::density / wyDevice::defaultInDensity);
	as->m_dataId = wyUtils::strHash(asPath);
	wyFree(data);
	return as;
}

wyArcticFileData* wyArcticLoader::loadMemory(const char* mfsName) {
	const char* mfsData = NULL;
	size_t length = 0;
	wyUtils::getFile(mfsName, &mfsData, &length);
	wyArcticFileData* as = load(mfsData, length, wyDevice::density / wyDevice::defaultInDensity);
	as->m_dataId = wyUtils::strHash(mfsName);
	return as;
}
