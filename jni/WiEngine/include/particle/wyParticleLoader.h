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
#ifndef __wyParticleLoader_h__
#define __wyParticleLoader_h__

#include "wyQuadParticleSystem.h"

typedef unsigned char xmlChar;

/**
 * @class wyParticleLoader
 *
 * \if English
 * It loads exported file of particle designer
 * \else
 * 用于载入particle designer设计的粒子系统描述文件
 * \endif
 */
class WIENGINE_API wyParticleLoader {
private:
	/**
	 * 载入particle designer描述文件
	 *
	 * @param data pd描述文件的raw数据
	 * @param length data的长度
	 * @param resScale 需要缩放的比例
	 * @return \link wyQuadParticleSystem wyQuadParticleSystem\endlink
	 */
	static wyQuadParticleSystem* load(const char* data, size_t length, float resScale = 1.f);

	static void startElement(void* ctx, const xmlChar *name, const xmlChar **atts);
	static void endElement(void* ctx, const xmlChar *name);
	static void characters(void* ctx, const xmlChar *ch, int len);
	static void warning(void* ctx, const char* msg, ...);
	static void error(void* ctx, const char* msg, ...);
	
public:
	/**
	 * \if English
	 * Load particle system from particle designer file
	 *
	 * @param resId resource id of particle designer file
	 * @return \link wyQuadParticleSystem wyQuadParticleSystem\endlink
	 * \else
	 * 载入particle designer描述文件
	 *
	 * @param resId pd描述文件的资源id
	 * @return \link wyQuadParticleSystem wyQuadParticleSystem\endlink
	 * \endif
	 */
	static wyQuadParticleSystem* load(int resId);

	/**
	 * \if English
	 * Load particle system from particle designer file
	 *
	 * @param path file path of particle designer file
	 * @param isFile true means \c path is an absolute path in file system, or false means
	 * 		\c path is a relative path under assets
	 * @param inDensity input density of particle description file. Default is zero and it means
	 * 		use default input density saved in \c wyDevice::defaultInDensity
	 * @return \link wyQuadParticleSystem wyQuadParticleSystem\endlink
	 * \else
	 * 载入particle designer描述文件
	 *
	 * @param path pd描述文件的asset路径或者文件系统路径
	 * @param isFile 可选参数, true表示path是一个文件系统路径, false表示path是一个assets下的相对路径
	 * @param inDensity 密度, 缺省为0, 表示使用系统缺省的输入密度
	 * @return \link wyQuadParticleSystem wyQuadParticleSystem\endlink
	 * \endif
	 */
	static wyQuadParticleSystem* load(const char* path, bool isFile = false, float inDensity = 0);
};

#endif // __wyParticleLoader_h__
