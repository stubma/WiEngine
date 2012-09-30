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
#ifndef __wyHGEParticleLoader_h__
#define __wyHGEParticleLoader_h__

#include "wyQuadParticleSystem.h"

/**
 * @class wyHGEParticleLoader
 *
 * \if English
 * Haff's Game Engine is an open source game engine which has a particle editing tool, named
 * HGE Particle Ed. WiEngine supports to load its export file.
 * \else
 * 用于载入HGE(HAFF'S GAME ENGINE)的粒子系统描述文件
 * \endif
 */
class WIENGINE_API wyHGEParticleLoader {
private:
	/**
	 * 载入HGE粒子系统的描述文件
	 *
	 * @param data .psi描述文件的raw数据
	 * @param particleCount 粒子系统的粒子数量
	 * @param tex 指定粒子系统的粒子贴图
	 * @param resScale 大小和位置相关数值需要缩放的比例, 缺省是1
	 *
	 * @return \link wyQuadParticleSystem wyQuadParticleSystem\endlink
	 */
	static wyQuadParticleSystem* doload(const char* data, int particleCount, wyTexture2D* tex, float resScale = 1.f);

public:
	/**
	 * \if English
	 * Load particle description file exported by HGE Particle Ed, the suffix should be .psi
	 *
	 * @param resId resource id of .psi file
	 * @param particleCount max particle count in particle system
	 * @param tex texture of particle
	 * @return \link wyQuadParticleSystem wyQuadParticleSystem\endlink
	 * \else
	 * 载入HGE粒子系统的描述文件
	 *
	 * @param resId .psi描述文件的资源id
	 * @param particleCount 指定粒子系统的粒子数量
	 * @param tex 指定粒子系统的粒子贴图
	 * @return \link wyQuadParticleSystem wyQuadParticleSystem\endlink
	 * \endif
	 */
	static wyQuadParticleSystem* load(int resId, int particleCount, wyTexture2D* tex);

	/**
	 * \if English
	 * Load particle description file exported by HGE Particle Ed, the suffix should be .psi
	 *
	 * @param path file path of .psi file
	 * @param particleCount max particle count in particle system
	 * @param tex texture of particle
	 * @param isFile true means \c path is an absolute path in file system, or false means
	 * 		\c path is a relative path under assets
	 * @param inDensity input density of particle description file. Default is zero and it means
	 * 		use default input density saved in \c wyDevice::defaultInDensity
	 * \else
	 * @return \link wyQuadParticleSystem wyQuadParticleSystem\endlink
	 * 载入HGE粒子系统的描述文件
	 *
	 * @param path .psi描述文件的asset路径或者文件系统路径
	 * @param particleCount 指定粒子系统的粒子数量
	 * @param tex 指定粒子系统的粒子贴图
	 * @param isFile 可选参数, true表示path是一个文件系统路径, false表示path是一个assets下的相对路径
	 * @param inDensity 密度, 缺省为0, 表示使用系统缺省的输入密度
	 * @return \link wyQuadParticleSystem wyQuadParticleSystem\endlink
	 * \endif
	 */
	static wyQuadParticleSystem* load(const char* path, int particleCount, wyTexture2D* tex, bool isFile = false, float inDensity = 0);
};

#endif // __wyHGEParticleLoader_h__
