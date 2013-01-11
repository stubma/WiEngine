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
#include "wyAuroraLoader.h"
#include "wyAuroraConstants.h"
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

static int peekByte() {
	return s_data[s_pos];
}

static void skip(size_t len) {
	s_pos += len;
}

wyAuroraFileData* wyAuroraLoader::load(const char* data, size_t length, float resScale) {
	wyAuroraFileData* afd = wyAuroraFileData::make();
	s_data = data;
	s_pos = 0;

	// set scale
	afd->m_resScale = resScale;

	// version
	afd->m_version = readShort();

	// currently we only support version 3
	if(afd->m_version != BS_VERSION_3) {
		LOGW("wyAuroraLoader::load: currently WiEngine only support version 3 BSprite file");
		return afd;
	}

	// flags
	afd->m_flags = readInt();

	// read all modules
	if((afd->m_flags & BS_MODULES) != 0) {
		// module count
		afd->m_moduleCount = readShort();

		if(afd->m_moduleCount > 0) {
			// allocate memory
			afd->m_modules = (wyAuroraModule*)wyCalloc(afd->m_moduleCount, sizeof(wyAuroraModule));

			for(int i = 0; i < afd->m_moduleCount; i++) {
				wyAuroraModule* module = afd->m_modules + i;

				// check first byte to decide what the module is
				int head = peekByte();
				if(head == 0xFF) {
					module->type = BSM_RECT;
					readByte();
					module->color = readInt();
					module->w = readByte();
					module->h = readByte();
				} else if(head == 0xFE) {
					module->type = BSM_FILL_RECT;
					readByte();
					module->color = readInt();
					module->w = readByte();
					module->h = readByte();
				} else if(head == 0xFD) {
					module->type = BSM_MARKER;
					readByte();
					module->w = readByte();
					module->h = readByte();
				} else {
					module->type = BSM_IMAGE;
					if((afd->m_flags & BS_MODULES_IMG) != 0) 
						module->imageIndex = readByte();
					if((afd->m_flags & BS_MODULES_XY_SHORT) != 0) {
						module->x = readShort();
						module->y = readShort();
					} else if((afd->m_flags & BS_MODULES_XY) != 0) {
						module->x = readByte();
						module->y = readByte();
					}
					if((afd->m_flags & BS_MODULES_WH_SHORT) != 0) {
						module->w = readShort();
						module->h = readShort();
					} else {
						module->w = readByte();
						module->h = readByte();
					}

					// decide image count
					afd->m_imageCount = MAX(afd->m_imageCount, module->imageIndex + 1);
				}
			}
		}
	}

	// read all frames
	if((afd->m_flags & BS_FRAMES) != 0) {
		// count of frame modules
		afd->m_frameModuleCount = readShort();

		// read all frame modules
		if(afd->m_frameModuleCount > 0) {
			afd->m_frameModules = (wyAuroraFrameModule*)wyCalloc(afd->m_frameModuleCount, sizeof(wyAuroraFrameModule));
			for(int i = 0; i < afd->m_frameModuleCount; i++) {
				wyAuroraFrameModule* fm = afd->m_frameModules + i;
				fm->index = readByte();
				if((afd->m_flags & BS_FM_OFF_SHORT) != 0) {
					fm->x = readShort();
					fm->y = readShort();
				} else {
					fm->x = readByte();
					fm->y = readByte();
				}
				if((afd->m_flags & BS_FM_PALETTE) != 0)
					fm->palette = readByte();
				fm->flags = readByte();
			}
		}

		// read all collision rect
		if((afd->m_flags & BS_FRAME_RECTS) != 0) {
			afd->m_collisionRectCount = readShort();
			if(afd->m_collisionRectCount > 0) {
				afd->m_collisionRects = (wyRect*)wyCalloc(afd->m_collisionRectCount, sizeof(wyRect));
				for(int i = 0; i < afd->m_collisionRectCount; i++) {
					wyRect* r = afd->m_collisionRects + i;
					r->x = readByte();
					r->y = readByte();
					r->width = readByte();
					r->height = readByte();
				}
			}
		}

		// read all frames
		afd->m_frameCount = readShort();
		if(afd->m_frameCount > 0) {
			afd->m_frames = (wyAuroraFrame*)wyCalloc(afd->m_frameCount, sizeof(wyAuroraFrame));
			for(int i = 0; i < afd->m_frameCount; i++) {
				wyAuroraFrame* f = afd->m_frames + i;

				// module count
				if((afd->m_flags & BS_NFM_1_BYTE) != 0)
					f->moduleCount = readByte();
				else
					f->moduleCount = readShort();

				// first module index
				if((afd->m_flags & BS_NO_FM_START) == 0)
					f->firstModuleIndex = readShort();

				// collision rect count
				if((afd->m_flags & BS_FRAME_RECTS) != 0)
					f->collisionRectCount = readByte();
			}

			// read frame bounds
			if((afd->m_flags & BS_SKIP_FRAME_RC) == 0) {
				for(int i = 0; i < afd->m_frameCount; i++) {
					wyAuroraFrame* f = afd->m_frames + i;
					f->bound.x = readByte();
					f->bound.y = readByte();
					f->bound.width = readByte();
					f->bound.height = readByte();
				}
			}

			// skip collision rect, the collision rect is actually frame rects and we already load it before
			if((afd->m_flags & BS_FRAME_COLL_RC) != 0) {
				skip(4 * afd->m_frameCount);
			}
		}
	}

	// read all animations
	if((afd->m_flags & BS_ANIMS) != 0) {
		// count of animation frames
		afd->m_animationFrameCount = readShort();

		// read all animation frames
		if(afd->m_animationFrameCount > 0) {
			afd->m_animationFrames = (wyAuroraAnimationFrame*)wyCalloc(afd->m_animationFrameCount, sizeof(wyAuroraAnimationFrame));
			for(int i = 0; i < afd->m_animationFrameCount; i++) {
				wyAuroraAnimationFrame* af = afd->m_animationFrames + i;
				af->index = readByte();
				af->delay = readByte();
				if((afd->m_flags & BS_AF_OFF_SHORT) != 0) {
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
			afd->m_animations = (wyAuroraAnimation*)wyCalloc(afd->m_animationCount, sizeof(wyAuroraAnimation));
			for(int i = 0; i < afd->m_animationCount; i++) {
				wyAuroraAnimation* a = afd->m_animations + i;

				// number of frame
				if((afd->m_flags & BS_NAF_1_BYTE) != 0)
					a->frameCount = readByte();
				else
					a->frameCount = readShort();

				// first animation frame inex
				if((afd->m_flags & BS_NO_AF_START) == 0)
					a->firstFrameIndex = readShort();
			}
		}
	}

	return afd;
}

wyAuroraFileData* wyAuroraLoader::load(int asResId) {
	size_t len;
	float scale;
	char* data = wyUtils::loadRaw(asResId, &len, &scale);
	wyAuroraFileData* as = load(data, len, scale);
	as->m_dataId = asResId;
	wyFree(data);
	return as;
}

wyAuroraFileData* wyAuroraLoader::load(const char* asPath, bool isFile) {
	size_t len;
	char* data = wyUtils::loadRaw(asPath, isFile, &len);
	wyAuroraFileData* as = load(data, len, wyDevice::density / wyDevice::defaultInDensity);
	as->m_dataId = wyUtils::strHash(asPath);
	wyFree(data);
	return as;
}

wyAuroraFileData* wyAuroraLoader::loadMemory(const char* mfsName) {
	size_t len;
	char* data = wyUtils::loadRaw(mfsName, &len);
	wyAuroraFileData* as = load(data, len, wyDevice::density / wyDevice::defaultInDensity);
	as->m_dataId = wyUtils::strHash(mfsName);
	wyFree(data);
	return as;
}
