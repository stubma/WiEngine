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
#include "wyParticleLoader.h"
#include <stdlib.h>
#include "wyTypes.h"
#include "wyUtils.h"
#include <stdio.h>
#include <errno.h>
#include "wyLog.h"
#include "wyTextureManager.h"
#include <libxml/parser.h>
#include "wyGlobal.h"
#include "wyRenderState.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct wyParticleDesignerPList {
	float angle;
	float angleVariance;
    bool blendAdditive;
	int blendFuncDestination;
	int blendFuncSource;
	float duration;
	int emitterType;
	float finishColorAlpha;
	float finishColorBlue;
	float finishColorGreen;
	float finishColorRed;
	float finishColorVarianceAlpha;
	float finishColorVarianceBlue;
	float finishColorVarianceGreen;
	float finishColorVarianceRed;
	float finishParticleSize;
	float finishParticleSizeVariance;
	float gravityx;
	float gravityy;
	int maxParticles;
	float maxRadius;
	float maxRadiusVariance;
	float minRadius;
	float minRadiusVariance;
	float particleLifespan;
	float particleLifespanVariance;
	float radialAccelVariance;
	float radialAcceleration;
	float rotatePerSecond;
	float rotatePerSecondVariance;
	float rotationEnd;
	float rotationEndVariance;
	float rotationStart;
	float rotationStartVariance;
	float sourcePositionVariancex;
	float sourcePositionVariancey;
	float sourcePositionx;
	float sourcePositiony;
	float speed;
	float speedVariance;
	float startColorAlpha;
	float startColorBlue;
	float startColorGreen;
	float startColorRed;
	float startColorVarianceAlpha;
	float startColorVarianceBlue;
	float startColorVarianceGreen;
	float startColorVarianceRed;
	float startParticleSize;
	float startParticleSizeVariance;
	float tangentialAccelVariance;
	float tangentialAcceleration;
	const char* textureFileName;
	const char* textureImageData;
	int textureImageDataLength;
} wyParticleDesignerPList;

typedef struct wyParseState {
	wyParticleDesignerPList* pd;

	// last key name
	const char* lastKey;

	// tag stack
	int* tags;
	int num;
	int max;

	// resource original scale
	float resScale;
} wyParseState;

extern wyPListTag getPListTag(const char* name);

static void pushTag(wyParseState* state, int tag) {
	while(state->num >= state->max) {
		state->max *= 2;
		state->tags = (int*)wyRealloc(state->tags, state->max);
	}

	state->tags[state->num++] = tag;
}

static inline void popTag(wyParseState* state) {
	state->num--;
}

static inline int topTag(wyParseState* state) {
	return state->tags[state->num - 1];
}

static inline int parentTag(wyParseState* state) {
	return state->tags[state->num - 2];
}

static inline int grandpaTag(wyParseState* state) {
	return state->tags[state->num - 3];
}

#ifdef __cplusplus
}
#endif

void wyParticleLoader::startElement(void* ctx, const xmlChar *name, const xmlChar **atts) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;
	
	// set tag
	pushTag(state, getPListTag((const char*)name));
}

void wyParticleLoader::endElement(void* ctx, const xmlChar *name) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;
	
	// pop
	popTag(state);
}

void wyParticleLoader::characters(void* ctx, const xmlChar *ch, int len) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;
	
	// check tag
	switch(topTag(state)) {
		case TAG_KEY:
		{
			char* key = (char*)wyCalloc(len + 1, sizeof(char));
			strncpy(key, (const char*)ch, len);
			wyUtils::trim(key);
			
			// save the last key
			if(state->lastKey != NULL) {
				wyFree((void*)state->lastKey);
				state->lastKey = NULL;
			}
			state->lastKey = key;
			break;
		}
		case TAG_INTEGER:
		{
			char* v = (char*)wyCalloc(len + 1, sizeof(char));
			strncpy(v, (const char*)ch, len);
			wyUtils::trim(v);
			
			if(!strcmp(state->lastKey, "blendFuncDestination")) {
				state->pd->blendFuncDestination = atoi(v);
			} else if(!strcmp(state->lastKey, "blendFuncSource")) {
				state->pd->blendFuncSource = atoi(v);
			}
			
			wyFree(v);
			break;
		}
		case TAG_REAL:
		{
			char* v = (char*)wyCalloc(len + 1, sizeof(char));
			strncpy(v, (const char*)ch, len);
			wyUtils::trim(v);
			
			if(!strcmp(state->lastKey, "angle")) {
				state->pd->angle = atof(v);
			} else if(!strcmp(state->lastKey, "angleVariance")) {
				state->pd->angleVariance = atof(v);
            } else if(!strcmp(state->lastKey, "blendAdditive")) {
                state->pd->blendAdditive = atof(v) == 1;
			} else if(!strcmp(state->lastKey, "duration")) {
				state->pd->duration = atof(v);
			} else if(!strcmp(state->lastKey, "emitterType")) {
				state->pd->emitterType = (int)atof(v);
			} else if(!strcmp(state->lastKey, "finishColorAlpha")) {
				state->pd->finishColorAlpha = atof(v);
			} else if(!strcmp(state->lastKey, "finishColorBlue")) {
				state->pd->finishColorBlue = atof(v);
			} else if(!strcmp(state->lastKey, "finishColorGreen")) {
				state->pd->finishColorGreen = atof(v);
			} else if(!strcmp(state->lastKey, "finishColorRed")) {
				state->pd->finishColorRed = atof(v);
			} else if(!strcmp(state->lastKey, "finishColorVarianceAlpha")) {
				state->pd->finishColorVarianceAlpha = atof(v);
			} else if(!strcmp(state->lastKey, "finishColorVarianceBlue")) {
				state->pd->finishColorVarianceBlue = atof(v);
			} else if(!strcmp(state->lastKey, "finishColorVarianceGreen")) {
				state->pd->finishColorVarianceGreen = atof(v);
			} else if(!strcmp(state->lastKey, "finishColorVarianceRed")) {
				state->pd->finishColorVarianceRed = atof(v);
			} else if(!strcmp(state->lastKey, "finishParticleSize")) {
				state->pd->finishParticleSize = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "finishParticleSizeVariance")) {
				state->pd->finishParticleSizeVariance = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "gravityx")) {
				state->pd->gravityx = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "gravityy")) {
				state->pd->gravityy = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "maxParticles")) {
				state->pd->maxParticles = atoi(v);
			} else if(!strcmp(state->lastKey, "maxRadius")) {
				state->pd->maxRadius = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "maxRadiusVariance")) {
				state->pd->maxRadiusVariance = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "minRadius")) {
				state->pd->minRadius = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "minRadiusVariance")) {
				state->pd->minRadiusVariance = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "particleLifespan")) {
				state->pd->particleLifespan = atof(v);
			} else if(!strcmp(state->lastKey, "particleLifespanVariance")) {
				state->pd->particleLifespanVariance = atof(v);
			} else if(!strcmp(state->lastKey, "radialAccelVariance")) {
				state->pd->radialAccelVariance = atof(v);
			} else if(!strcmp(state->lastKey, "radialAcceleration")) {
				state->pd->radialAcceleration = atof(v);
			} else if(!strcmp(state->lastKey, "rotatePerSecond")) {
				state->pd->rotatePerSecond = atof(v);
			} else if(!strcmp(state->lastKey, "rotatePerSecondVariance")) {
				state->pd->rotatePerSecondVariance = atof(v);
			} else if(!strcmp(state->lastKey, "rotationEnd")) {
				/*
				 * in plist, position value is counter-clockwise, but for particle system,
				 * position value is clockwise, so need negate it
				 */
				state->pd->rotationEnd = -atof(v);
			} else if(!strcmp(state->lastKey, "rotationEndVariance")) {
				state->pd->rotationEndVariance = atof(v);
			} else if(!strcmp(state->lastKey, "rotationStart")) {
				/*
				 * in plist, position value is counter-clockwise, but for particle system,
				 * position value is clockwise, so need negate it
				 */
				state->pd->rotationStart = -atof(v);
			} else if(!strcmp(state->lastKey, "rotationStartVariance")) {
				state->pd->rotationStartVariance = atof(v);
			} else if(!strcmp(state->lastKey, "sourcePositionVariancex")) {
				state->pd->sourcePositionVariancex = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "sourcePositionVariancey")) {
				state->pd->sourcePositionVariancey = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "sourcePositionx")) {
				state->pd->sourcePositionx = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "sourcePositiony")) {
				state->pd->sourcePositiony = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "speed")) {
				state->pd->speed = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "speedVariance")) {
				state->pd->speedVariance = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "startColorAlpha")) {
				state->pd->startColorAlpha = atof(v);
			} else if(!strcmp(state->lastKey, "startColorBlue")) {
				state->pd->startColorBlue = atof(v);
			} else if(!strcmp(state->lastKey, "startColorGreen")) {
				state->pd->startColorGreen = atof(v);
			} else if(!strcmp(state->lastKey, "startColorRed")) {
				state->pd->startColorRed = atof(v);
			} else if(!strcmp(state->lastKey, "startColorVarianceAlpha")) {
				state->pd->startColorVarianceAlpha = atof(v);
			} else if(!strcmp(state->lastKey, "startColorVarianceBlue")) {
				state->pd->startColorVarianceBlue = atof(v);
			} else if(!strcmp(state->lastKey, "startColorVarianceGreen")) {
				state->pd->startColorVarianceGreen = atof(v);
			} else if(!strcmp(state->lastKey, "startColorVarianceRed")) {
				state->pd->startColorVarianceRed = atof(v);
			} else if(!strcmp(state->lastKey, "startParticleSize")) {
				state->pd->startParticleSize = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "startParticleSizeVariance")) {
				state->pd->startParticleSizeVariance = atof(v) * state->resScale;
			} else if(!strcmp(state->lastKey, "tangentialAccelVariance")) {
				state->pd->tangentialAccelVariance = atof(v);
			} else if(!strcmp(state->lastKey, "tangentialAcceleration")) {
				state->pd->tangentialAcceleration = atof(v);
			}
			
			wyFree(v);
			break;
		}
		case TAG_STRING:
		{
			char* v = (char*)wyCalloc(len + 1, sizeof(char));
			strncpy(v, (const char*)ch, len);
			size_t outLen = wyUtils::trim(v);
			
			if(!strcmp(state->lastKey, "textureFileName")) {
				state->pd->textureFileName = v;
			} else if(!strcmp(state->lastKey, "textureImageData")) {
				char* data = wyUtils::decodeBase64((const char*)v, outLen, &outLen);
				wyFree(v);
				
				char* out = NULL;
				outLen = wyUtils::gunzip(data, outLen, &out);
				wyFree(data);
				
				state->pd->textureImageData = out;
				state->pd->textureImageDataLength = outLen;
			} else {
				wyFree(v);
			}
			break;
		}
	}
}

void wyParticleLoader::warning(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGW("%s", msg);
    va_end(args);
}

void wyParticleLoader::error(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGE("%s", msg);
    va_end(args);
}

wyQuadParticleSystem* wyParticleLoader::load(const char* data, size_t length, float resScale) {
	xmlSAXHandlerV1 sSAXHandler = {
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		startElement,
		endElement,
		NULL,
		characters,
		NULL,
		NULL,
		NULL,
		warning,
		error,
		NULL,
		NULL,
		NULL,
		NULL,
		0
	};
	
	// create map object
	wyParticleDesignerPList* pd = (wyParticleDesignerPList*)wyCalloc(1, sizeof(wyParticleDesignerPList));
	wyParseState* state = (wyParseState*)wyCalloc(1, sizeof(wyParseState));
	state->pd = pd;
	state->tags = (int*)wyMalloc(10 * sizeof(int));
	state->tags[0] = DOCUMENT;
	state->num = 1;
	state->max = 10;
	state->resScale = resScale;

	// start to parser xml file
	xmlSAXUserParseMemory((xmlSAXHandlerPtr)&sSAXHandler, state, data, length);

	// clean parser
	xmlCleanupParser();

	// release helper struct
	if(state->lastKey != NULL)
		wyFree((void*)state->lastKey);
	wyFree(state->tags);
	wyFree(state);

	// create particle system
	wyQuadParticleSystem* ps = wyQuadParticleSystem::make(pd->maxParticles);
	ps->setEmitterMode(pd->emitterType == 0 ? GRAVITY : RADIUS);
	ps->setDirectionAngleVariance(pd->angle, pd->angleVariance);
    if(pd->blendAdditive) {
    	ps->setBlendMode(wyRenderState::ALPHA_ADDITIVE);
    } else {
    	ps->setBlendMode(wyRenderState::ALPHA);
    }
	ps->setDuration(pd->duration);
	ps->setStartColorVariance(
			pd->startColorRed, pd->startColorGreen, pd->startColorBlue, pd->startColorAlpha,
			pd->startColorVarianceRed, pd->startColorVarianceGreen, pd->startColorVarianceBlue, pd->startColorVarianceAlpha);
	ps->setEndColorVariance(
			pd->finishColorRed, pd->finishColorGreen, pd->finishColorBlue, pd->finishColorAlpha,
			pd->finishColorVarianceRed, pd->finishColorVarianceGreen, pd->finishColorVarianceBlue, pd->finishColorVarianceAlpha);
	ps->setLifeVariance(pd->particleLifespan, pd->particleLifespanVariance);
	ps->setParticlePositionVariance(pd->sourcePositionx, pd->sourcePositiony, pd->sourcePositionVariancex, pd->sourcePositionVariancey);
	ps->setStartSizeVariance(pd->startParticleSize, pd->startParticleSizeVariance);
	ps->setEndSizeVariance(pd->finishParticleSize, pd->finishParticleSizeVariance);
	ps->setStartSpinVariance(pd->rotationStart, pd->rotationStartVariance);
	ps->setEndSpinVariance(pd->rotationEnd, pd->rotationEndVariance);
	ps->setEmissionRate(pd->maxParticles / pd->particleLifespan);
	switch(ps->getEmitterMode()) {
		case GRAVITY:
			ps->setParticleGravity(pd->gravityx, pd->gravityy);
			ps->setRadialAccelerationVariance(pd->radialAcceleration, pd->radialAccelVariance);
			ps->setSpeedVariance(pd->speed, pd->speedVariance);
			ps->setTangentialAccelerationVariance(pd->tangentialAcceleration, pd->tangentialAccelVariance);
			break;
		case RADIUS:
			ps->setStartRadiusVariance(pd->maxRadius, pd->maxRadiusVariance);
			ps->setEndRadiusVariance(pd->minRadius, pd->minRadiusVariance);
			ps->setRotationVariance(pd->rotatePerSecond, pd->rotatePerSecondVariance);
			break;
	}

	// extract texture data if it is embedded in plist
	if(pd->textureImageData != NULL) {
		wyTexture2D* tex = wyTexture2D::makeRaw(pd->textureImageData, pd->textureImageDataLength, 0,
				wyTextureManager::getInstance()->getTexturePixelFormat(), wyDevice::density / resScale);
		ps->setTexture(tex);
	}

	// free pd
	if(pd->textureImageData != NULL)
		wyFree((void*)pd->textureImageData);
	if(pd->textureFileName != NULL)
		wyFree((void*)pd->textureFileName);
	wyFree(pd);

	return ps;
}

wyQuadParticleSystem* wyParticleLoader::load(int resId) {
	size_t len;
	float scale;
	char* data = wyUtils::loadRaw(resId, &len, &scale);
	wyQuadParticleSystem* ps = load(data, len, scale);
	wyFree(data);
	return ps;
}

wyQuadParticleSystem* wyParticleLoader::load(const char* path, bool isFile, float inDensity) {
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	size_t len;
	char* data = wyUtils::loadRaw(path, isFile, &len);
	wyQuadParticleSystem* ps = load(data, len, wyDevice::density / inDensity);
	wyFree(data);
	return ps;
}
