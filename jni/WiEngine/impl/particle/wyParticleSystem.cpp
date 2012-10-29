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
#include "wyParticleSystem.h"
#include <stdlib.h>
#include <math.h>
#include "wyLog.h"
#include "wyQuadList.h"

bool wyParticleSystem::releaseParticle(wyArray* arr, void* ptr, int index, void* data) {
	wyFree(ptr);
	return true;
}

void wyParticleSystem::initParticle(wyParticle* particle) {
	// timeToLive
	// no negative life. prevent division by 0
	particle->timeToLive = MAX(0, m_life + m_lifeVar * wyMath::randMinusOneToOne());

	// position
	particle->pos.x = m_centerOfGravity.x + m_centerOfGravityVar.x * wyMath::randMinusOneToOne();
	particle->pos.y = m_centerOfGravity.y + m_centerOfGravityVar.y * wyMath::randMinusOneToOne();

	// Color
	wyColor4F start = wyc4fWhite;
	start.r = MIN(1, MAX(0, m_startColor.r + m_startColorVar.r * wyMath::randMinusOneToOne()));
	start.g = MIN(1, MAX(0, m_startColor.g + m_startColorVar.g * wyMath::randMinusOneToOne()));
	start.b = MIN(1, MAX(0, m_startColor.b + m_startColorVar.b * wyMath::randMinusOneToOne()));
	start.a = MIN(1, MAX(0, m_startColor.a + m_startColorVar.a * wyMath::randMinusOneToOne()));

	wyColor4F end = wyc4fWhite;
	end.r = MIN(1, MAX(0, m_endColor.r + m_endColorVar.r * wyMath::randMinusOneToOne()));
	end.g = MIN(1, MAX(0, m_endColor.g + m_endColorVar.g * wyMath::randMinusOneToOne()));
	end.b = MIN(1, MAX(0, m_endColor.b + m_endColorVar.b * wyMath::randMinusOneToOne()));
	end.a = MIN(1, MAX(0, m_endColor.a + m_endColorVar.a * wyMath::randMinusOneToOne()));

	particle->color = start;
	particle->deltaColor.r = (end.r - start.r) / particle->timeToLive;
	particle->deltaColor.g = (end.g - start.g) / particle->timeToLive;
	particle->deltaColor.b = (end.b - start.b) / particle->timeToLive;
	particle->deltaColor.a = (end.a - start.a) / particle->timeToLive;

	// size
	float startS = MAX(0, m_startSize + m_startSizeVar * wyMath::randMinusOneToOne()); // no negative size

	particle->size = startS;
	if(m_endSize == PARTICLE_START_SIZE_EQUAL_TO_END_SIZE)
		particle->deltaSize = 0;
	else {
		float endS = m_endSize + m_endSizeVar * wyMath::randMinusOneToOne();
		endS = MAX(0, endS);
		particle->deltaSize = (endS - startS) / particle->timeToLive;
	}

	// rotation
	float startA = m_startSpin + m_startSpinVar * wyMath::randMinusOneToOne();
	float endA = m_endSpin + m_endSpinVar * wyMath::randMinusOneToOne();
	particle->rotation = startA;
	particle->deltaRotation = (endA - startA) / particle->timeToLive;

	// position
	if(m_positionType == FREE)
		particle->startPos = nodeToWorldSpace(particle->startPos);

	// direction
	float a = wyMath::d2r(m_angle + m_angleVar * wyMath::randMinusOneToOne());

	// Mode Gravity: A
	if(m_emitterMode == GRAVITY) {
		wyPoint v = wypZero;
		v.y = wyMath::sin(a);
		v.x = wyMath::cos(a);
		float s = m_speed + m_speedVar * wyMath::randMinusOneToOne();

		// direction
		particle->direction = wypMul(v, wyp(s, s));

		// radial accel
		particle->radialAccel = m_radialAccel + m_radialAccelVar * wyMath::randMinusOneToOne();

		// tangential accel
		particle->tangentialAccel = m_tangentialAccel + m_tangentialAccelVar * wyMath::randMinusOneToOne();
	} else {
		// Mode Radius: B

		// Set the default diameter of the particle from the source position
		float sRadius = m_startRadius + m_startRadiusVar * wyMath::randMinusOneToOne();
		float eRadius = m_endRadius + m_endRadiusVar * wyMath::randMinusOneToOne();

		particle->radius = sRadius;

		if(m_endRadius == PARTICLE_START_RADIUS_EQUAL_TO_END_RADIUS)
			particle->deltaRadius = 0;
		else
			particle->deltaRadius = (eRadius - sRadius) / particle->timeToLive;

		particle->radian = a;
		particle->radianPerSecond = wyMath::d2r(m_rotationDegree + m_rotationDegreeVar * wyMath::randMinusOneToOne());
	}
}

bool wyParticleSystem::addParticle() {
	if(isFull())
		return false;

	wyParticle* particle = wyParticleNew();

	initParticle(particle);
	wyArrayPush(m_particles, particle);
	m_particleCount++;

	return true;
}

wyParticleSystem::~wyParticleSystem() {
	wyArrayEach(m_particles, releaseParticle, NULL);
	wyArrayClear(m_particles);
	wyArrayDestroy(m_particles);
}

void wyParticleSystem::setPosition(float x, float y) {
	// cache position if updating, or set it if not
	if(m_pendingPosition)
		return;

	if(m_updating) {
		m_pendingX = x;
		m_pendingY = y;
		m_pendingPosition = true;
	} else {
		wyNode::setPosition(x, y);
		m_pendingPosition = false;
	}
}

wyParticleSystem::wyParticleSystem(int numberOfParticles) :
		m_updating(false),
		m_active(true),
		m_duration(0),
		m_elapsed(0),
		m_centerOfGravity(wypZero),
		m_centerOfGravityVar(wypZero),
		m_angle(0),
		m_angleVar(0),
		m_startSize(0),
		m_startSizeVar(0),
		m_endSize(0),
		m_endSizeVar(0),
		m_life(0),
		m_lifeVar(0),
		m_startColor(wyc4fWhite),
		m_startColorVar(wyc4fBlack),
		m_endColor(wyc4fWhite),
		m_endColorVar(wyc4fBlack),
		m_startSpin(0),
		m_startSpinVar(0),
		m_endSpin(0),
		m_endSpinVar(0),
		m_maxParticles(numberOfParticles),
		m_particleCount(0),
		m_particles(wyArrayNew(numberOfParticles)),
		m_emissionRate(0),
		m_emitCounter(0),
		m_positionType(FREE),
		m_autoRemoveOnFinish(false),
		m_particleIdx(0),
		m_emitterMode(GRAVITY),
		m_pendingPosition(false),
		m_pendingX(0),
		m_pendingY(0),
		m_timer(NULL),
		m_gravity(wypZero),
		m_speed(0),
		m_speedVar(0),
		m_tangentialAccel(0),
		m_tangentialAccelVar(0),
		m_radialAccel(0),
		m_radialAccelVar(0),
		m_startRadius(0),
		m_startRadiusVar(0),
		m_endRadius(0),
		m_endRadiusVar(0),
		m_rotationDegree(0),
		m_rotationDegreeVar(0) {
	// update after action in run!
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyParticleSystem::update));
    m_timer = wyTimer::make(ts);
    scheduleLocked(m_timer);
}

void wyParticleSystem::stopSystem() {
	m_active = false;
	m_elapsed = m_duration;
	m_emitCounter = 0;
	m_pendingPosition = false;
}

void wyParticleSystem::resetSystem() {
	m_active = true;
	m_pendingPosition = false;
	m_elapsed = 0;
	for(m_particleIdx = 0; m_particleIdx < m_particleCount; ++m_particleIdx) {
		wyParticle* p = (wyParticle*)wyArrayGet(m_particles, m_particleIdx);
		p->timeToLive = 0;
	}
}

void wyParticleSystem::update(wyTargetSelector* ts) {
	float dt = ts->getDelta();
	m_updating = true;

	// clear mesh
	((wyQuadList*)getMesh())->removeAllQuads();

	// check pending position
	// currently we save position because setPosition and update
	// are running in different thread, so we cache position to avoid flashing
	if(m_pendingPosition) {
		setPosition(m_pendingX, m_pendingY);
		setTransformDirty();
		m_pendingPosition = false;
	}

	if(m_active && m_emissionRate != 0) {
		float rate = 1.0f / m_emissionRate;
		m_emitCounter += dt;
		while(m_particleCount < m_maxParticles && m_emitCounter > rate) {
			addParticle();
			m_emitCounter -= rate;
		}
        
        /*
         * Make a mod here to confine emit counter value. If not do this, in some situation
         * the emit counter will be bigger and bigger. Imagine a particle system whose max particles 
         * and emission rate are both 20, and game runs in 60 fps. The tolerance accumulated in 
         * every frame will make m_emitCounter increasing continuously. Finally the particle emission
         * is totally messed.
         */
        m_emitCounter = fmodf(m_emitCounter, rate);

		m_elapsed += dt;
		if(m_duration != -1 && m_duration < m_elapsed)
			stopSystem();
	}

	m_particleIdx = 0;

	wyPoint currentPosition = wypZero;
	if(m_positionType == FREE)
		currentPosition = nodeToWorldSpace(currentPosition);

	while(m_particleIdx < m_particleCount) {
		wyParticle* p = (wyParticle*)wyArrayGet(m_particles, m_particleIdx);

		// life
		p->timeToLive -= dt;

		if(p->timeToLive > 0) {
			// Mode A: gravity, direction, tangential accel & radial accel
			if(m_emitterMode == GRAVITY) {
				wyPoint tmp, radial, tangential;

				// radial acceleration
				radial = wypZero;
				if(p->pos.x != 0 || p->pos.y != 0)
					radial = wypNormalize(p->pos);
				tangential = radial;
				radial = wypMul(radial, wyp(p->radialAccel, p->radialAccel));

				// tangential acceleration
				float newy = tangential.x;
				tangential.x = -tangential.y;
				tangential.y = newy;
				tangential = wypMul(tangential, wyp(p->tangentialAccel, p->tangentialAccel));

				// (gravity + radial + tangential) * dt
				tmp = radial;
				tmp = wypAdd(tmp, tangential);
				tmp = wypAdd(tmp, m_gravity);
				tmp = wypMul(tmp, wyp(dt, dt));
				p->direction = wypAdd(p->direction, tmp);
				tmp = wypMul(p->direction, wyp(dt, dt));
				p->pos = wypAdd(p->pos, tmp);
			} else {
				// Mode B: radius movement
				// Update the angle and radius of the particle.
				p->radian += p->radianPerSecond * dt;
				p->radius += p->deltaRadius * dt;

				p->pos.x = -wyMath::cos(p->radian) * p->radius;
				p->pos.y = -wyMath::sin(p->radian) * p->radius;
			}

			// color
			p->color.r += (p->deltaColor.r * dt);
			p->color.g += (p->deltaColor.g * dt);
			p->color.b += (p->deltaColor.b * dt);
			p->color.a += (p->deltaColor.a * dt);

			// size
			p->size += (p->deltaSize * dt);
			p->size = MAX(0, p->size);

			// angle
			p->rotation += (p->deltaRotation * dt);

			//
			// update values in quad
			//
			wyPoint newPos;
			if(m_positionType == FREE) {
				wyPoint diff = wypSub(currentPosition, p->startPos);
				newPos = wypSub(p->pos, diff);
			} else
				newPos = p->pos;

			appendParticleQuad(p, newPos);

			// update particle counter
			m_particleIdx++;
		} else {
			// life < 0
			wyParticle* particle = NULL;
			if(m_particleIdx != m_particleCount - 1) {
				wyParticle* lastParticle = (wyParticle*)wyArrayDeleteIndex(m_particles, m_particleCount - 1);
				particle = (wyParticle*)wyArrayDeleteIndex(m_particles, m_particleIdx);
				wyArrayInsert(m_particles, lastParticle, m_particleIdx);
			} else {
				particle = (wyParticle*)wyArrayDeleteIndex(m_particles, m_particleIdx);
            }

			// free particle
			if(particle)
				wyFree(particle);
            
			// decrease count
			m_particleCount--;

			// auto remove if flag is set and particle count is zero
			if(m_particleCount == 0 && m_autoRemoveOnFinish) {
				unscheduleLocked(m_timer);
				m_parent->removeChildLocked(this, true);
				return;
			}
		}
	}

	postStep();

	m_updating = false;
}

void wyParticleSystem::setParticlePositionVariance(float baseX, float baseY, float varianceX, float varianceY) {
	m_centerOfGravity.x = baseX;
	m_centerOfGravity.y = baseY;
	m_centerOfGravityVar.x = varianceX;
	m_centerOfGravityVar.y = varianceY;
}

void wyParticleSystem::setDirectionAngleVariance(float base, float variance) {
	m_angle = base;
	m_angleVar = variance;
}

void wyParticleSystem::setStartSizeVariance(float base, float variance) {
	m_startSize = base;
	m_startSizeVar = variance;
}

void wyParticleSystem::setEndSizeVariance(float base, float variance) {
	m_endSize = base;
	m_endSizeVar = variance;
}

void wyParticleSystem::setLifeVariance(float base, float variance) {
	m_life = base;
	m_lifeVar = variance;
}

void wyParticleSystem::setStartColorVariance(float baseR, float baseG, float baseB, float baseA, float varR, float varG, float varB, float varA) {
	m_startColor.r = baseR;
	m_startColor.g = baseG;
	m_startColor.b = baseB;
	m_startColor.a = baseA;
	m_startColorVar.r = varR;
	m_startColorVar.g = varG;
	m_startColorVar.b = varB;
	m_startColorVar.a = varA;
}

void wyParticleSystem::setEndColorVariance(float baseR, float baseG, float baseB, float baseA, float varR, float varG, float varB, float varA) {
	m_endColor.r = baseR;
	m_endColor.g = baseG;
	m_endColor.b = baseB;
	m_endColor.a = baseA;
	m_endColorVar.r = varR;
	m_endColorVar.g = varG;
	m_endColorVar.b = varB;
	m_endColorVar.a = varA;
}

void wyParticleSystem::setStartSpinVariance(float base, float variance) {
	m_startSpin = base;
	m_startSpinVar = variance;
}

void wyParticleSystem::setEndSpinVariance(float base, float variance) {
	m_endSpin = base;
	m_endSpinVar = variance;
}

void wyParticleSystem::setSpeedVariance(float base, float variance) {
	m_speed = base;
	m_speedVar = variance;
}

void wyParticleSystem::setParticleGravity(float gravityX, float gravityY) {
	m_gravity.x = gravityX;
	m_gravity.y = gravityY;
}

void wyParticleSystem::setTangentialAccelerationVariance(float base, float variance) {
	m_tangentialAccel = base;
	m_tangentialAccelVar = variance;
}

void wyParticleSystem::setRadialAccelerationVariance(float base, float variance) {
	m_radialAccel = base;
	m_radialAccelVar = variance;
}

void wyParticleSystem::setStartRadiusVariance(float base, float variance) {
	m_startRadius = base;
	m_startRadiusVar = variance;
}

void wyParticleSystem::setEndRadiusVariance(float base, float variance) {
	m_endRadius = base;
	m_endRadiusVar = variance;
}

void wyParticleSystem::setRotationVariance(float base, float variance) {
	m_rotationDegree = base;
	m_rotationDegreeVar = variance;
}
