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
#ifndef __wyParticle_h__
#define __wyParticle_h__

#include "wyTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct wyParticle
 *
 * \if English
 * Particle structure
 * \else
 * 代表一个粒子
 * \endif
 */
typedef struct WIENGINE_API wyParticle {
	/**
	 * \if English
	 * current position of this particle
	 * \else
	 * 粒子的当前位置
	 * \endif
	 */
	wyPoint pos;

	/**
	 * \if English
	 * init position when the particle is emitted
	 * \else
	 * 粒子的起始位置
	 * \endif
	 */
	wyPoint startPos;

	/**
	 * \if English
	 * initial color
	 * \else
	 * 粒子的初始颜色
	 * \endif
	 */
	wyColor4F color;

	/**
	 * \if English
	 * Delta color of particle
	 * \else
	 * 粒子颜色的变化范围
	 * \endif
	 */
	wyColor4F deltaColor;

	/**
	 * \if English
	 * particle size
	 * \else
	 * 粒子的初始大小
	 * \endif
	 */
	float size;

	/**
	 * \if English
	 * Size delta range
	 * \else
	 * 粒子大小的可变范围
	 * \endif
	 */
	float deltaSize;

	/**
	 * \if English
	 * rotation in degrees, anchor is particle pos
	 * \else
	 * 粒子的初始自转角度
	 * \endif
	 */
	float rotation;

	/**
	 * \if English
	 * Rotation delta range
	 * \else
	 * 粒子的旋转角度可变范围
	 * \endif
	 */
	float deltaRotation;

	/**
	 * \if English
	 * how many time to live, in seconds
	 * \else
	 * 粒子的存活时间, 单位秒
	 * \endif
	 */
	float timeToLive;

	/**
	 * \if English
	 * gravity direction
	 * \else
	 * 重力方向
	 * \endif
	 */
	wyPoint direction;

	/**
	 * \if English
	 * initial radial acceleration, only used in gravity mode
	 * \else
	 * 初始的角加速度, 仅在重力模式有效
	 * \endif
	 */
	float radialAccel;

	/**
	 * \if English
	 * initial tangential acceleration, only used in gravity mode
	 * \else
	 * 初始的切线方向加速度, 仅在重力模式有效
	 * \endif
	 */
	float tangentialAccel;

	/**
	 * \if English
	 * initial radian position, only used in radius mode
	 * \else
	 * 粒子初始的弧度位置, 仅在半径模式有效
	 * \endif
	 */
	float radian;

	/**
	 * \if English
	 * Delta range of radian position, only used in radius mode
	 * \else
	 * 粒子的弧度位置可变范围, 仅在半径模式有效
	 * \endif
	 */
	float radianPerSecond;

	/**
	 * \if English
	 * Distance to particle system position, only used in radius mode
	 * \else
	 * 粒子的初始出现位置, 通过和参考点的距离来表示, 仅在半径模式有效
	 * \endif
	 */
	float radius;

	/**
	 * \if English
	 * Delta range of particle radius position, only used in radius mode
	 * \else
	 * 粒子距离参考点的可变距离范围, 仅在半径模式有效
	 * \endif
	 */
	float deltaRadius;
} wyParticle;

/**
 * \if English
 * Create a new particle structure and initialized as empty
 *
 * @return \link wyParticle wyParticle\endlink
 * \else
 * 创建一个新的粒子数据结构, 初始化为空
 *
 * @return \link wyParticle wyParticle\endlink
 * \endif
 */
WIENGINE_API wyParticle* wyParticleNew();

#ifdef __cplusplus
}
#endif

#endif // __wyParticle_h__
