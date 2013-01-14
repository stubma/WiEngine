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
 * @typedef wyParticleSystemMode
 *
 * Particle system mode
 */
typedef enum {
	/**
	 * Gravity mode (A mode)
	 */
	GRAVITY = 1,

	/**
	 * Radius mode (B mode)
	 */
	RADIUS
} wyParticleSystemMode;

/**
 * @typedef wyParticleSystemPositionType
 *
 * Particle system emission mode
 */
typedef enum {
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
	RELATIVE,
} wyParticleSystemPositionType;

/**
 * @class wyParticleSystem
 *
 * Particle system node
 */
class WIENGINE_API wyParticleSystem : public wyNode {
protected:
	/// flag，true表示粒子系统update函数正被调用
	bool m_updating;

	/// 标识粒子系统是否正处于运行状态
	bool m_active;

	/// 粒子系统的生命周期，-1表示一直运行
	float m_duration;

	/// 粒子系统从开始到现在时间，单位妙
	float m_elapsed;

	/// 粒子发射器的位置
	wyPoint m_centerOfGravity;

	/// 粒子发射器的位置变化量，用于随机微调
	wyPoint m_centerOfGravityVar;

	/// 粒子角度(方向)，单位度
	float m_angle;

	/// 粒子角度变化量，单位度
	float m_angleVar;

	/// 粒子起始大小
	float m_startSize;

	/// 粒子起始大小变化量
	float m_startSizeVar;

	/// 粒子结束大小
	float m_endSize;

	/// 粒子结束大小变化量
	float m_endSizeVar;

	/// 粒子生存期，单位秒
	float m_life;
	
	/// 粒子生存期变化量，单位秒
	float m_lifeVar;

	/// 粒子起始颜色
	wyColor4F m_startColor;

	/// 粒子起始颜色变化量
	wyColor4F m_startColorVar;

	/// 粒子结束颜色
	wyColor4F m_endColor;

	/// 粒子结束颜色变化量
	wyColor4F m_endColorVar;

	/// 粒子起始自转角度，单位度
	float m_startSpin;

	/// 粒子起始自转角度变化量
	float m_startSpinVar;

	/// 粒子结束自转角度，单位度
	float m_endSpin;

	/// 粒子结束自转角度变化量
	float m_endSpinVar;

	/// 粒子数组指针
	wyArray* m_particles;

	/// 最大粒子数
	int m_maxParticles;

	/// 活动状态的粒子数
	int m_particleCount;

	/// 每秒发射的粒子数 
	float m_emissionRate;
	
	/// 本次发射器需要发射的粒子数
	float m_emitCounter;

	/// 运动模式，free or grouped
	wyParticleSystemPositionType m_positionType;

	/// 表示该wyNode节点是否从父节点中删除
	bool m_autoRemoveOnFinish;

	/// 粒子数组索引，标识当前正在操作的粒子
	int m_particleIdx;

	/// 发射器发射模式
	wyParticleSystemMode m_emitterMode;

	/// bool flag， 标识是否改变发射器位置
	bool m_pendingPosition;

	/// 发射器的新x坐标
	float m_pendingX;

	/// 发射器的新y坐标
	float m_pendingY;

	/// 回调函数update的timer
	wyTimer* m_timer;

	///////////////////////////////
	//gravity mode only
	///////////////////////////////

	/// 系统的重力
	wyPoint m_gravity;

	/// 粒子的运动速度(大小).
	float m_speed;

	/// 粒子的运动速度变化量
	float m_speedVar;

	/// 粒子的角加速度
	float m_tangentialAccel;

	/// 粒子的角加速度变化量
	float m_tangentialAccelVar;

	/// 粒子的线加速度
	float m_radialAccel;

	/// 粒子的线加速度变化量
	float m_radialAccelVar;

	///////////////////////////////
	//radius mode only
	///////////////////////////////

	/// 粒子的起始半径
	float m_startRadius;

	/// 粒子的起始半径变化量
	float m_startRadiusVar;

	/// 粒子的结束半径
	float m_endRadius;

	/// 粒子的结束半径变化量
	float m_endRadiusVar;

	/// 粒子绕起始位置每秒钟的旋转角度
	float m_rotationDegree;

	/// 旋转角度变化量
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
	wyParticleSystemMode getEmitterMode() { return m_emitterMode; }

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
	void setEmitterMode(wyParticleSystemMode mode) { m_emitterMode = mode; }

	/**
	 * Get particle position mode
	 *
	 * @return mode of particle position, relative to emission spot or not
	 */
	wyParticleSystemPositionType getPositionType() { return m_positionType; }

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
	void setPositionType(wyParticleSystemPositionType type) { m_positionType = type; }

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
