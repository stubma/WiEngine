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
#ifndef __wyPointParticleSystem_h__
#define __wyPointParticleSystem_h__

#include "wyParticleSystem.h"

/**
 * @class wyPointParticleSystem
 *
 * \if English
 * Point particle system. Particle is renderred by point sprite but it may not supported
 * in all device and rom
 * \else
 * 点粒子系统, 每个粒子通过点来渲染, 但是由于用到的渲染API可能不被某些设备或固件支持, 因此不一定能保证
 * 兼容性
 * \endif
 */
class WIENGINE_API wyPointParticleSystem : public wyParticleSystem {
protected:
	/// 点的二维坐标数组，每个点用2个GLfloat表示
	GLfloat* m_vertices;

	/// 颜色数组，每个点用4个GLfloat表示，格式为RGBA
	GLfloat* m_colors;

	/// 粒子大小数组，GLfloat值表示粒子直径
	GLfloat* m_sizes;

	/// @see wyParticleSystem::postStep
	virtual void postStep();
	
	/// @see wyParticleSystem::updateQuadWithParticle
	virtual void updateQuadWithParticle(wyParticle* particle, wyPoint newPosition);

public:
	/**
	 * \if English
	 * Constructor
	 *
	 * @param numberOfParticles max allowed particle count
	 * \else
	 * 构造函数
	 *
	 * @param numberOfParticles 最大允许存在的粒子数量
	 * \endif
	 */
	wyPointParticleSystem(int numberOfParticles);
	
	virtual ~wyPointParticleSystem();

	/// @see wyNode::draw
	virtual void draw();
};

#endif // __wyPointParticleSystem_h__
