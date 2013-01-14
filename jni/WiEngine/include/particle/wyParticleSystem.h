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
#ifndef __wyParticleSystem_h__
#define __wyParticleSystem_h__

#include "wyNode.h"
#include "wyParticle.h"
#include "wyArray.h"
#include "wyScheduler.h"
#include "wyTexture2D.h"

/**
 * The Particle emitter lives forever
 */
#define PARTICLE_DURATION_INFINITY -1

/**
 * The starting size of the particle is equal to the ending size
 */
#define PARTICLE_START_SIZE_EQUAL_TO_END_SIZE -1

/**
 * The starting radius of the particle is equal to the ending radius
 */
#define PARTICLE_START_RADIUS_EQUAL_TO_END_RADIUS -1

/**
 * @class wyParticleSystem
 *
 * Particle system node
 */
class WIENGINE_API wyParticleSystem : public wyNode {
public:
	/**
	 * Particle system mode
	 */
	enum Mode {
		/**
		 * Gravity mode (A mode)
		 */
		GRAVITY = 1,

		/**
		 * Radius mode (B mode)
		 */
		RADIUS,
	};

	/**
	 * Particle system emission mode
	 */
	enum PositionType {
		/**
		 * If the emitter is repositioned, the living particles won't be repositioned
		 */
		FREE = 1,

		/**
		 * If the emitter is repositioned, the living particles will be repositioned too
		 */
		GROUPED,

		/**
		 * If the emitter is repositioned, the living particles won't be repositioned, node to its parents
		 */
		RELATIVE_TO_PARENT,
	};

protected:
	/// true means update method is in processing
	bool m_updating;

	/// true means particle system is active
	bool m_active;

	/// duration of emission, -1 means forever
	float m_duration;

	/// elapsed time, seconds
	float m_elapsed;

	/// the position of emission
	wyPoint m_centerOfGravity;

	/// variance of emission
	wyPoint m_centerOfGravityVar;

	/// particle direction in degree
	float m_angle;

	/// variance of particle direction
	float m_angleVar;

	/// start size of particle
	float m_startSize;

	/// variance of particle start size
	float m_startSizeVar;

	/// end size of particle
	float m_endSize;

	/// variance of particle end size
	float m_endSizeVar;

	/// particle life in second
	float m_life;
	
	/// variance of particle life
	float m_lifeVar;

	/// start color of particle
	wyColor4F m_startColor;

	/// variance of particle start color
	wyColor4F m_startColorVar;

	/// end color of particle
	wyColor4F m_endColor;

	/// variance of particle end color
	wyColor4F m_endColorVar;

	/// start rotation angle in degree
	float m_startSpin;

	/// variance of start rotation angle
	float m_startSpinVar;

	/// end rotation angle in degree
	float m_endSpin;

	/// variance of end rotation angle
	float m_endSpinVar;

	/// particle array
	wyArray* m_particles;

	/// max live particle allowed
	int m_maxParticles;

	/// current number of live particle
	int m_particleCount;

	/// number of particle emitted every second
	float m_emissionRate;
	
	/// a helper variable used when emit particle
	float m_emitCounter;

	/// position mode
	PositionType m_positionType;

	/// remove particle when no particle will be emitted
	bool m_autoRemoveOnFinish;

	/// current particle index on which is operated
	int m_particleIdx;

	/// emitter mode
	Mode m_emitterMode;

	/// true means emitter position will be updated
	bool m_pendingPosition;

	/// new x position of emitter
	float m_pendingX;

	/// new y position of emitter
	float m_pendingY;

	/// timer for update method
	wyTimer* m_timer;

	///////////////////////////////
	//gravity mode only
	///////////////////////////////

	/// gravity force
	wyPoint m_gravity;

	/// initial speed of particle
	float m_speed;

	/// variance of particle speed
	float m_speedVar;

	/// tangential acceleration of particle
	float m_tangentialAccel;

	/// variance of particle tangential acceleration
	float m_tangentialAccelVar;

	/// radial acceleration of particle
	float m_radialAccel;

	/// variance of radial acceleration
	float m_radialAccelVar;

	///////////////////////////////
	//radius mode only
	///////////////////////////////

	/// start radius of particle
	float m_startRadius;

	/// variance of particle start radius
	float m_startRadiusVar;

	/// end radius of particle
	float m_endRadius;

	/// variance of particle end radius
	float m_endRadiusVar;

	/// particle revolution speed in degree, the pivot is particle emission position
	float m_rotationDegree;

	/// variance of particle revolution
	float m_rotationDegreeVar;

private:
	static bool releaseParticle(wyArray* arr, void* ptr, int index, void* data);

protected:
	/**
	 * 每次粒子更新后调用此函数.
	 */    
	virtual void postStep() = 0;

	/**
	 * append particle quadrangle to buffer
	 *
	 * @param particle the particle need to be appended
	 * @param newPosition new position of this particle
	 */    
	virtual void appendParticleQuad(wyParticle* particle, wyPoint newPosition) = 0;

	/**
	 * 判断当前粒子数是否已满
	 *
	 * \return 如粒子数等于允许最大粒子数, 返回true, 否则返回false 
	 */   
	bool isFull() { return m_particleCount == m_maxParticles; }

	/**
	 * 向粒子系统中增加一个粒子
	 *
	 * \return 成功返回true, 否则返回false
	 */ 	
	bool addParticle();
	
	/**
	 * 初始化粒子
	 *
	 * @param particle 待初始化的粒子
	 */ 		
	void initParticle(wyParticle* particle);

public:
	/**
	 * Constructor
	 *
	 * @param numberOfParticles max particle count allowed, don't set a huge
	 * 		value because it impacts particle system performance
	 */ 
	wyParticleSystem(int numberOfParticles);

	virtual ~wyParticleSystem();

	/**
	 * Update particle position, rotation, color, etc.
	 *
	 * @param ts the selector object which triggered this method
	 */	
	void update(wyTargetSelector* ts);

	/// @see wyNode::setPosition
	virtual void setPosition(float x, float y);

	/**
	 * Reset particle system so that the particle system will be activated again. Generally
	 * this is called after \c stopSystem to reuse particle system
	 */
	void resetSystem();

	/**
	 * Stop particle system. You can reuse it by calling \c resetSystem if it is not released
	 */
	void stopSystem();

	// setters
	void setParticlePositionVariance(float baseX, float baseY, float varianceX, float varianceY);
	void setDirectionAngleVariance(float base, float variance);
	void setStartSizeVariance(float base, float variance);
	void setEndSizeVariance(float base, float variance);
	void setLifeVariance(float base, float variance);
	void setStartColorVariance(float baseR, float baseG, float baseB, float baseA, float varR, float varG, float varB, float varA);
	void setEndColorVariance(float baseR, float baseG, float baseB, float baseA, float varR, float varG, float varB, float varA);
	void setStartSpinVariance(float base, float variance);
	void setEndSpinVariance(float base, float variance);
	void setSpeedVariance(float base, float variance);
	void setParticleGravity(float gravityX, float gravityY);
	void setTangentialAccelerationVariance(float base, float variance);
	void setRadialAccelerationVariance(float base, float variance);
	void setStartRadiusVariance(float base, float variance);
	void setEndRadiusVariance(float base, float variance);
	void setRotationVariance(float base, float variance);

	/**
	 * Get gravity
	 *
	 * @return gravity
	 */
	wyPoint getParticleGravity() { return m_gravity; }

	/**
	 * Set particle emission time
	 *
	 * @param d emission duration time, in seconds
	 */
	void setDuration(float d) { m_duration = d; }

	/**
	 * Get particle emissiontime
	 *
	 * @return time of emission, in seconds
	 */
	float getDuration() { return m_duration; }

	/**
	 * Get initial position of particle emitted
	 *
	 * @return position of particle emitted
	 */
	wyPoint getCenterOfGravity() { return m_centerOfGravity; }

	/**
	 * Will particle system node be removed when it is finished.
	 *
	 * @return true means particle system node will be removed when particle emission completed
	 */
	bool isAutoRemoveOnFinish() { return m_autoRemoveOnFinish; }

	/**
	 * Set whether or not particle system should be removed when it is finished. It doesn't
	 * work for \c stopSystem.
	 *
	 * @param flag true means particle system will be removed when particle emission completed
	 */
	void setAutoRemoveOnFinish(bool flag) { m_autoRemoveOnFinish = flag; }

	/**
	 * Get particle emission rate, it means how many particles will be emitted in one second
	 *
	 * @return how many particles will be emitted in one second
	 */
	float getEmissionRate() { return m_emissionRate; }

	/**
	 * Set particle emission rate
	 *
	 * @param rate how many particles will be emitted in one second
	 */
	void setEmissionRate(float rate) { m_emissionRate = rate; }

	/**
	 * Get particle life time, in second
	 *
	 * @return particle life time, in second
	 */
	float getLife() { return m_life; }

	/**
	 * Get particle system mode
	 *
	 * @return mode of particle system
	 */
	Mode getEmitterMode() { return m_emitterMode; }

	/**
	 * Set particle system mode
	 *
	 * \par
	 * gravity mode: can set a gravity in particle system
	 *
	 * \par
	 * radius mode: no gravity in particle system, particle position is described by radius and radian
	 *
	 * @param mode mode of particle system
	 */
	void setEmitterMode(Mode mode) { m_emitterMode = mode; }

	/**
	 * Get particle position mode
	 *
	 * @return mode of particle position, relative to emission spot or not
	 */
	PositionType getPositionType() { return m_positionType; }

	/**
	 * Set particle position mode
	 *
	 * \par
	 * free mode: particle will not follow emission spot
	 *
	 * \par
	 * group mode: particle will follow emission spot
	 *
	 * @param type particle position mode constant
	 */
	void setPositionType(PositionType type) { m_positionType = type; }

	/**
	 * Get current particle count
	 *
	 * @return current particle count
	 */
	int getParticleCount() { return m_particleCount; }

	/**
	 * Get max allowed particle count
	 *
	 * @return max allowed particle count
	 */
	int getMaxParticles() { return m_maxParticles; }
};

#endif // __wyParticleSystem_h__
