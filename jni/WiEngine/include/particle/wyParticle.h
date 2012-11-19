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
#ifndef __wyParticle_h__
#define __wyParticle_h__

#include "wyTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct wyParticle
 *
 * Particle structure
 */
typedef struct WIENGINE_API wyParticle {
	/**
	 * current position of this particle
	 */
	wyPoint pos;

	/**
	 * init position when the particle is emitted
	 */
	wyPoint startPos;

	/**
	 * initial color
	 */
	wyColor4F color;

	/**
	 * Delta color of particle
	 */
	wyColor4F deltaColor;

	/**
	 * particle size
	 */
	float size;

	/**
	 * Size delta range
	 */
	float deltaSize;

	/**
	 * rotation in degrees, anchor is particle pos
	 */
	float rotation;

	/**
	 * Rotation delta range
	 */
	float deltaRotation;

	/**
	 * how many time to live, in seconds
	 */
	float timeToLive;

	/**
	 * gravity direction
	 */
	wyPoint direction;

	/**
	 * initial radial acceleration, only used in gravity mode
	 */
	float radialAccel;

	/**
	 * initial tangential acceleration, only used in gravity mode
	 */
	float tangentialAccel;

	/**
	 * initial radian position, only used in radius mode
	 */
	float radian;

	/**
	 * Delta range of radian position, only used in radius mode
	 */
	float radianPerSecond;

	/**
	 * Distance to particle system position, only used in radius mode
	 */
	float radius;

	/**
	 * Delta range of particle radius position, only used in radius mode
	 */
	float deltaRadius;
} wyParticle;

/**
 * Create a new particle structure and initialized as empty
 *
 * @return \link wyParticle wyParticle\endlink
 */
WIENGINE_API wyParticle* wyParticleNew();

#ifdef __cplusplus
}
#endif

#endif // __wyParticle_h__
