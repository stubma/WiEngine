/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

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

/**
 * \if English
 * The Particle emitter lives forever
 * \else
 * 用于表示粒子存活时间无限长的常量
 * \endif
 */
#define PARTICLE_DURATION_INFINITY -1

/**
 * \if English
 * The starting size of the particle is equal to the ending size
 * \else
 * 用于表示粒子结束大小和起始大小一样的常量
 * \endif
 */
#define PARTICLE_START_SIZE_EQUAL_TO_END_SIZE -1

/**
 * \if English
 * The starting radius of the particle is equal to the ending radius
 * \else
 * 用于表示粒子结束半径距离和起始半径距离一样的常量
 * \endif
 */
#define PARTICLE_START_RADIUS_EQUAL_TO_END_RADIUS -1

/**
 * @typedef wyParticleSystemMode
 *
 * \if English
 * Particle system mode
 * \else
 * 粒子系统模式
 * \endif
 */
typedef enum {
	/**
	 * \if English
	 * Gravity mode (A mode)
	 * \else
	 * 重力模式, 即可以给粒子系统指定一个重力
	 * \endif
	 */
	GRAVITY = 1,

	/**
	 * \if English
	 * Radius mode (B mode)
	 * \else
	 * 半径模式, 粒子系统没有重力, 粒子的位置通过角度, 半径等参数描述
	 * \endif
	 */
	RADIUS
} wyParticleSystemMode;

/**
 * @typedef wyParticleSystemPositionType
 *
 * \if English
 * Particle system emission mode
 * \else
 * 粒子释放模式
 * \endif
 */
typedef enum {
	/**
	 * \if English
	 * If the emitter is repositioned, the living particles won't be repositioned
	 * \else
	 * 表示当粒子释放位置发生了变化时, 已经释放出的粒子保持位置不变
	 * \endif
	 */
	FREE = 1,

	/**
	 * \if English
	 * If the emitter is repositioned, the living particles will be repositioned too
	 * \else
	 * 表示当粒子释放位置发生了变化时, 已经释放的粒子跟随释放点而移动, 保持和释放点的相对距离不变
	 * \endif
	 */
	GROUPED,
} wyParticleSystemPositionType;

/**
 * @class wyParticleSystem
 *
 * \if English
 * Particle system node
 * \else
 * 粒子系统
 * \endif
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

	/// 应用在粒子上的贴图
	wyTexture2D* m_tex;

	/// 渲染模式
	wyBlendFunc m_blendFunc;

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
	 * 粒子更新函数
	 *
	 * @param particle 待更新的例子
	 * @param newPosition 粒子的新坐标
	 */    
	virtual void updateQuadWithParticle(wyParticle* particle, wyPoint newPosition) = 0;

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
	 * \if English
	 * Constructor
	 *
	 * @param numberOfParticles max particle count allowed, don't set a huge
	 * 		value because it impacts particle system performance
	 * \else
	 * 构造函数
	 *
	 * @param numberOfParticles 最大能存在的粒子数量, 这个值不宜过大, 因为粒子越多性能
	 * 		越低, 在达到需要的效果的前提下, 越少越好
	 * \endif
	 */ 
	wyParticleSystem(int numberOfParticles);

	virtual ~wyParticleSystem();

	/**
	 * \if English
	 * Update particle position, rotation, color, etc.
	 *
	 * @param ts the selector object which triggered this method
	 * \else
	 * 每次绘制新帧前该函数会被自动调用
	 *
	 * @param ts 触发这个方法的选择子对象
	 * \endif
	 */	
	void update(wyTargetSelector* ts);

	/// @see wyNode::setPosition
	virtual void setPosition(float x, float y);

	/// @see wyNode::getBlendFunc
	virtual wyBlendFunc getBlendFunc() { return m_blendFunc; }

	/// @see wyNode::setBlendFunc
	virtual void setBlendFunc(wyBlendFunc func) { m_blendFunc = func; }

	/// @see wyNode::getTexture
	virtual wyTexture2D* getTexture() { return m_tex; }

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex);

	/**
	 * \if English
	 * Reset particle system so that the particle system will be activated again. Generally
	 * this is called after \c stopSystem to reuse particle system
	 * \else
	 * 重设粒子系统, 重设后所有粒子的生存时间会被清零，也就相当于所有粒子会在下次
	 * 更新时清除。这个方法一般在粒子系统被停止后调用, 这样可以重用粒子系统节点, 而不用重新创建
	 * 新的粒子系统节点.
	 * \endif
	 */
	void resetSystem();

	/**
	 * \if English
	 * Stop particle system. You can reuse it by calling \c resetSystem if it is not released
	 * \else
	 * 停止粒子系统，粒子会停止释放. 如果这个粒子系统节点没有被释放, 之后还可以通过\c resetSystem方法来
	 * 重用这个粒子系统
	 * \endif
	 */
	void stopSystem();

	// setters
	void setBlendAdditive(bool additive);
	bool isBlendAdditive() { return m_blendFunc.src == GL_SRC_ALPHA && m_blendFunc.dst == GL_ONE; }
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
	 * \if English
	 * Get gravity
	 *
	 * @return gravity
	 * \else
	 * 获得重力
	 *
	 * @return 重力
	 * \endif
	 */
	wyPoint getParticleGravity() { return m_gravity; }

	/**
	 * \if English
	 * Set particle emission time
	 *
	 * @param d emission duration time, in seconds
	 * \else
	 * 设置粒子释放持续的时间
	 *
	 * @param d 粒子释放持续的时间, 单位秒
	 * \endif
	 */
	void setDuration(float d) { m_duration = d; }

	/**
	 * \if English
	 * Get particle emissiontime
	 *
	 * @return time of emission, in seconds
	 * \else
	 * 得到粒子释放持续的时间
	 *
	 * @return 粒子释放持续的时间
	 * \endif
	 */
	float getDuration() { return m_duration; }

	/**
	 * \if English
	 * Get initial position of particle emitted
	 *
	 * @return position of particle emitted
	 * \else
	 * 获得粒子出现位置
	 *
	 * @return 粒子的生成位置
	 * \endif
	 */
	wyPoint getCenterOfGravity() { return m_centerOfGravity; }

	/**
	 * \if English
	 * Will particle system node be removed when it is finished.
	 *
	 * @return true means particle system node will be removed when particle emission completed
	 * \else
	 * 是否在粒子释放结束后自动删除粒子系统节点
	 *
	 * @return true表示在粒子释放结束后自动删除粒子系统节点
	 * \endif
	 */
	bool isAutoRemoveOnFinish() { return m_autoRemoveOnFinish; }

	/**
	 * \if English
	 * Set whether or not particle system should be removed when it is finished. It doesn't
	 * work for \c stopSystem.
	 *
	 * @param flag true means particle system will be removed when particle emission completed
	 * \else
	 * 设置是否在粒子释放结束后自动删除粒子系统节点, 不过如果你通过\c stopSystem来停止粒子释放, 这个标志
	 * 是不起作用的.
	 *
	 * @param flag true表示在粒子释放结束后自动删除粒子系统节点
	 * \endif
	 */
	void setAutoRemoveOnFinish(bool flag) { m_autoRemoveOnFinish = flag; }

	/**
	 * \if English
	 * Get particle emission rate, it means how many particles will be emitted in one second
	 *
	 * @return how many particles will be emitted in one second
	 * \else
	 * 得到粒子释放速度
	 *
	 * @return 粒子释放速度, 单位秒，表示多少秒释放一个粒子
	 * \endif
	 */
	float getEmissionRate() { return m_emissionRate; }

	/**
	 * \if English
	 * Set particle emission rate
	 *
	 * @param rate how many particles will be emitted in one second
	 * \else
	 * 设置粒子释放速度
	 *
	 * @param rate 粒子释放速度, 单位秒，表示多少秒释放一个粒子
	 * \endif
	 */
	void setEmissionRate(float rate) { m_emissionRate = rate; }

	/**
	 * \if English
	 * Get particle life time, in second
	 *
	 * @return particle life time, in second
	 * \else
	 * 获得单个粒子的存活时间
	 *
	 * @return 单个粒子的存活时间
	 * \endif
	 */
	float getLife() { return m_life; }

	/**
	 * \if English
	 * Get particle system mode
	 *
	 * @return mode of particle system
	 * \else
	 * 得到粒子系统模式
	 *
	 * @return 粒子系统模式
	 * \endif
	 */
	wyParticleSystemMode getEmitterMode() { return m_emitterMode; }

	/**
	 * \if English
	 * Set particle system mode
	 *
	 * \par
	 * gravity mode: can set a gravity in particle system
	 *
	 * \par
	 * radius mode: no gravity in particle system, particle position is described by radius and radian
	 *
	 * @param mode mode of particle system
	 * \else
	 * 设置粒子系统模式
	 *
	 * \par GRAVITY模式
	 * 粒子系统中可以设置重力, 粒子可以具有线速度和角速度
	 *
	 * \par RADIUS模式
	 * 粒子系统中没有重力，通过设置粒子和释放点的距离，以及旋转速度来控制粒子的运动
	 *
	 * @param mode 粒子系统模式
	 * \endif
	 */
	void setEmitterMode(wyParticleSystemMode mode) { m_emitterMode = mode; }

	/**
	 * \if English
	 * Get particle position mode
	 *
	 * @return mode of particle position, relative to emission spot or not
	 * \else
	 * 得到粒子系统位置改变时粒子的行为
	 *
	 * @return 粒子系统位置改变时粒子的行为
	 * \endif
	 */
	wyParticleSystemPositionType getPositionType() { return m_positionType; }

	/**
	 * \if English
	 * Set particle position mode
	 *
	 * \par
	 * free mode: particle will not follow emission spot
	 *
	 * \par
	 * group mode: particle will follow emission spot
	 *
	 * @param type particle position mode constant
	 * \else
	 * 设置粒子系统位置改变时粒子的行为
	 *
	 * \par FREE
	 * 粒子系统位置改变时，已经生成的粒子保持当前位置不变
	 *
	 * \par GROUPED
	 * 粒子系统位置改变时，已经生成的粒子跟随粒子系统移动
	 *
	 * @param type wyParticleSystemPositionType类型常量
	 * \endif
	 */
	void setPositionType(wyParticleSystemPositionType type) { m_positionType = type; }

	/**
	 * \if English
	 * Get current particle count
	 *
	 * @return current particle count
	 * \else
	 * 得到当前粒子数量
	 *
	 * @return 当前粒子数量
	 * \endif
	 */
	int getParticleCount() { return m_particleCount; }

	/**
	 * \if English
	 * Get max allowed particle count
	 *
	 * @return max allowed particle count
	 * \else
	 * 得到允许同时存在的最大粒子数量
	 *
	 * @return 允许同时存在的最大粒子数量
	 * \endif
	 */
	int getMaxParticles() { return m_maxParticles; }
};

#endif // __wyParticleSystem_h__
