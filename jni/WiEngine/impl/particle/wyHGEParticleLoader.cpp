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
#include "wyHGEParticleLoader.h"
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyRenderState.h"

#define	HGE_BLEND_ALPHABLEND	2
typedef int hgeSprite;

typedef struct hgeColor {
	float		r,g,b,a;
}hgeColor;

typedef struct hgeParticleSystemInfo {
	hgeSprite*	sprite;    // texture + blend mode
	int			nEmission; // particles per sec
	float		fLifetime;

	float		fParticleLifeMin;
	float		fParticleLifeMax;

	float		fDirection;
	float		fSpread;
	bool		bRelative;

	float		fSpeedMin;
	float		fSpeedMax;

	float		fGravityMin;
	float		fGravityMax;

	float		fRadialAccelMin;
	float		fRadialAccelMax;

	float		fTangentialAccelMin;
	float		fTangentialAccelMax;

	float		fSizeStart;
	float		fSizeEnd;
	float		fSizeVar;

	float		fSpinStart;
	float		fSpinEnd;
	float		fSpinVar;

	hgeColor	colColorStart;
	hgeColor	colColorEnd;
	float		fColorVar;
	float		fAlphaVar;
} hgeParticleSystemInfo;

wyQuadParticleSystem* wyHGEParticleLoader::doload(const char* data, int particleCount, wyTexture2D* tex, float resScale) {
	wyQuadParticleSystem* ps = WYNEW wyQuadParticleSystem(particleCount);
	hgeParticleSystemInfo* hgePI = (hgeParticleSystemInfo*)data;

	// duration
	ps->setDuration(hgePI->fLifetime);

	// the HGE degree is clockwise, wiEngine's is counter-clockwise.
	float fDirection_D = (-wyMath::r2d(hgePI->fDirection)) + 360.0f;
	float angD = wyMath::r2d(hgePI->fSpread / 2.0f);
	if(!hgePI->bRelative) {
		fDirection_D += 90.0f;
	}
	// HGE angle is in radian, but wiEngine's is in degree.
	ps->setDirectionAngleVariance(fDirection_D, angD);

	// life of particles
	ps->setLifeVariance((hgePI->fParticleLifeMax + hgePI->fParticleLifeMin) / 2,
					(hgePI->fParticleLifeMax - hgePI->fParticleLifeMin) / 2);

	// speed of particles
	ps->setSpeedVariance((hgePI->fSpeedMax + hgePI->fSpeedMin) / 2 * resScale,
			(hgePI->fSpeedMax - hgePI->fSpeedMin) / 2 * resScale);

	// size, in pixels
	float size = MAX(tex->getPixelWidth(), tex->getPixelHeight());
	float fSizeVar = (hgePI->fSizeEnd - hgePI->fSizeStart) *  hgePI->fSizeVar * size / 2;
	ps->setStartSizeVariance((hgePI->fSizeStart * size + fSizeVar) * resScale, fSizeVar * resScale);
	ps->setEndSizeVariance(hgePI->fSizeEnd * size * resScale, fSizeVar * resScale);

	// emits per frame
	ps->setEmissionRate(hgePI->nEmission);

	// color of particles
	float fStartColorVar_R = (hgePI->colColorEnd.r-hgePI->colColorStart.r) * hgePI->fColorVar / 2;
	float fStartColorVar_G = (hgePI->colColorEnd.g-hgePI->colColorStart.g) * hgePI->fColorVar / 2;
	float fStartColorVar_B = (hgePI->colColorEnd.b-hgePI->colColorStart.b) * hgePI->fColorVar / 2;
	float fStartColorVar_A = (hgePI->colColorEnd.a-hgePI->colColorStart.a) * hgePI->fAlphaVar / 2;
	ps->setStartColorVariance(hgePI->colColorStart.r + fStartColorVar_R ,
			hgePI->colColorStart.g + fStartColorVar_G,
			hgePI->colColorStart.b + fStartColorVar_B,
			hgePI->colColorStart.a + fStartColorVar_A,
			fStartColorVar_R, fStartColorVar_G, fStartColorVar_B, fStartColorVar_A);
	ps->setEndColorVariance(hgePI->colColorEnd.r, hgePI->colColorEnd.g, hgePI->colColorEnd.b, hgePI->colColorEnd.a,
			fStartColorVar_R, fStartColorVar_G, fStartColorVar_B, fStartColorVar_A);

	// additive
	int blendMode = ((size_t)hgePI->sprite) >> 16;
	if(HGE_BLEND_ALPHABLEND & blendMode) {
		ps->setBlendMode(wyRenderState::ALPHA);
	} else {
		ps->setBlendMode(wyRenderState::ALPHA_ADDITIVE);
	}

	float fSpinVar = wyMath::r2d((hgePI->fSpinEnd - hgePI->fSpinStart) * hgePI->fSpinVar / 2);
	float fSpinStart = wyMath::r2d(hgePI->fSpinStart);

	// HGE rendering logical about spinning is different from wiEngine's
	// the solution is used as a workaround
	float fSpinEnd = wyMath::r2d(hgePI->fSpinEnd * (hgePI->fParticleLifeMax + hgePI->fParticleLifeMin) / 2);
	ps->setStartSpinVariance(-(fSpinStart + fSpinVar), fSpinVar);
	ps->setEndSpinVariance(-fSpinEnd, fSpinVar);

	ps->setSpeedVariance((hgePI->fSpeedMax + hgePI->fSpeedMin) / 2 * resScale,
			(hgePI->fSpeedMax - hgePI->fSpeedMin) / 2 * resScale);

	// HGE gravity and TangentialAccel direction is opposite to wiEngine's
	ps->setParticleGravity(0.0f, -(hgePI->fGravityMax + hgePI->fGravityMin) / 2 * resScale);
	ps->setTangentialAccelerationVariance(-(hgePI->fTangentialAccelMax + hgePI->fTangentialAccelMin) / 2,
										(hgePI->fTangentialAccelMax - hgePI->fTangentialAccelMin) / 2);

	ps->setRadialAccelerationVariance((hgePI->fRadialAccelMax + hgePI->fRadialAccelMin) / 2,
									(hgePI->fRadialAccelMax - hgePI->fRadialAccelMin) / 2);

	ps->setTexture(tex);

	return ps;
}

wyQuadParticleSystem* wyHGEParticleLoader::load(int resId, int particleCount, wyTexture2D* tex) {
	size_t len;
	float scale;
	char* data = wyUtils::loadRaw(resId, &len, &scale);
	if(!data || len != sizeof(hgeParticleSystemInfo)) {
		LOGE("ERROR: failed to load res %d", resId);
		return NULL;
	}
	wyQuadParticleSystem* ps = doload(data, particleCount, tex, scale);
	wyFree(data);
	return (wyQuadParticleSystem*)ps->autoRelease();
}

wyQuadParticleSystem* wyHGEParticleLoader::load(const char* path, int particleCount, wyTexture2D* tex, bool isFile, float inDensity) {
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	size_t len;
	char* data = wyUtils::loadRaw(path, isFile, &len);
	if(!data || len != sizeof(hgeParticleSystemInfo)) {
		LOGE("ERROR: failed to load file %s", path);
		return NULL;
	}
	wyQuadParticleSystem* ps = doload(data, particleCount, tex, wyDevice::density / inDensity);
	wyFree(data);
	return (wyQuadParticleSystem*)ps->autoRelease();
}
