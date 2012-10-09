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
#ifndef __wyRenderState_h__
#define __wyRenderState_h__

#include "wyObject.h"

/**
 * @class wyRenderState
 *
 * \if English
 * \c wyRenderState specifies material rendering properties that cannot
 * be controlled by a shader on a \link wyMaterial wyMaterial\endlink. The properties
 * allow manipulation of rendering features such as depth testing, alpha blending,
 * face culling, stencil operations, and much more.
 * \else
 * 渲染状态包含了一些无法被shader控制的参数, 比如深度测试, alpha混合, face culling, 蒙版测试等.
 * \endif
 */
class WIENGINE_API wyRenderState : public wyObject {
public:
	/**
	 * \if English
	 * Blend mode
	 * \else
	 * 渲染模式
	 * \endif
	 */
	enum BlendMode {
        /**
         * \if English
         * No blending mode is used.
         * \else
         * 不打开渲染模式
         * \endif
         */
        NO_BLEND,

        /**
         * \if English
         * Additive blending. For use with glows and particle emitters.
         *
         * \par
         * Result = Source Color + Destination Color -> (GL_ONE, GL_ONE)
         * \else
         * 追加式渲染
         *
         * \par
         * 结果 = 源色彩 + 目标色彩 = (GL_ONE, GL_ONE)
         * \endif
         */
        ADDITIVE,

        /**
         * \if English
         * Premultiplied alpha blending, for use with premultiplied alpha textures.
         *
         * \par
         * Result = Source Color + (Dest Color * (1 - Source Alpha) ) -> (GL_ONE, GL_ONE_MINUS_SRC_ALPHA)
         * \else
         * 预先计算alpha情况下的渲染
         *
         * \par
         * 结果 = 源色彩 + (目标色彩 * (1 - 源透明度)) = (GL_ONE, GL_ONE_MINUS_SRC_ALPHA)
         * \endif
         */
        PREMULTIPLIED_ALPHA,

        /**
         * \if English
         * Additive blending that is multiplied with source alpha.
         * For use with glows and particle emitters.
         *
         * \par
         * Result = (Source Alpha * Source Color) + Dest Color -> (GL_SRC_ALPHA, GL_ONE)
         * \else
         * 追加式渲染, 考虑源色彩透明度
         *
         * \par
         * 结果 = (源透明度 * 源色彩) + 目标色彩 = (GL_SRC_ALPHA, GL_ONE)
         * \endif
         */
        ALPHA_ADDITIVE,

        /**
         * \if English
         * Color blending, blends in color from dest color
         * using source color.
         *
         * \par
         * Result = Source Color + (1 - Source Color) * Dest Color -> (GL_ONE, GL_ONE_MINUS_SRC_COLOR)
         * \else
         * 颜色混合模式
         *
         * \par
         * 结果 = 源色彩 + (1 - 源色彩) * 目标色彩 = (GL_ONE, GL_ONE_MINUS_SRC_COLOR)
         * \endif
         */
        COLOR,

        /**
         * \if English
         * Alpha blending, interpolates to source color from dest color
         * using source alpha.
         *
         * \par
         * Result = Source Alpha * Source Color + (1 - Source Alpha) * Dest Color -> (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
         * \else
         * alpha渲染, 最常见的一种形式
         *
         * \par
         * 结果 = 源透明度 * 源色彩 + (1 - 源透明度) * 目标色彩 = (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
         * \endif
         */
        ALPHA,

        /**
         * \if English
         * Multiplies the source and dest colors.
         *
         * \par
         * Result = Source Color * Dest Color -> (GL_DST_COLOR, GL_ZERO)
         * \else
         * 调和模式
         *
         * \par
         * 结果 = 源色彩 * 目标色彩 = (GL_DST_COLOR, GL_ZERO)
         * \endif
         */
        MODULATE,

        /**
         * \if English
         * Multiplies the source and dest colors then doubles the result.
         *
         * \par
         * Result = 2 * Source Color * Dest Color -> (GL_DST_COLOR, GL_SRC_COLOR)
         * \else
         * 双倍调和模式
         *
         * \par
         * 结果 = 2 * 源色彩 * 目标色彩 = (GL_DST_COLOR, GL_SRC_COLOR)
         * \endif
         */
        MODULATE_X2
	};

	/**
	 * \if English
	 * face culling mode
	 * \else
	 * 面裁剪方式
	 * endif
	 */
	enum CullMode {
        /**
         * \if English
         * Face culling is disabled.
         * \else
         * 不裁剪
         * \endif
         */
        NO_CULL,

        /**
         * \if English
         * Cull front faces
         * \else
         * 裁剪正面
         * \endif
         */
        FRONT,

        /**
         * \if English
         * Cull back faces
         * \else
         * 裁剪背面
         * \endif
         */
        BACK,

        /**
         * \if English
         * Cull both front and back faces.
         * \else
         * 都裁剪
         * \endif
         */
        BOTH
	};

public:
	/**
	 * \if English
	 * blending mode
	 * \else
	 * 混合模式
	 * \endif
	 */
	BlendMode blendMode;

	/**
	 * \if English
	 * face culling mode
	 * \else
	 * 面剪裁方式
	 * \endif
	 */
	CullMode cullMode;

	/**
	 * \if English
	 * enable dither or not
	 * \else
	 * 是否打开颜色抖动
	 * \endif
	 */
	bool ditherEnabled;

	/**
	 * \if English
	 * enable depth test or not
	 * \else
	 * 是否打开深度测试
	 * \endif
	 */
	bool depthTestEnabled;

	/**
	 * \if English
	 * Is depth buffer writing enabled or not
	 * \else
	 * 深度缓冲区的写是否打开
	 * \endif
	 */
	bool depthWriteEnabled;

	/**
	 * \if English
	 * Is color buffer writing enabled or not
	 * \else
	 * 颜色缓冲区的写是否打开
	 * \endif
	 */
	bool colorWriteEnabled;

protected:
	wyRenderState();

public:
	/**
	 * \if English
	 * Generate a default render state for 2D rendering
	 *
	 * @return \link wyRenderState wyRenderState\endlink
	 * \else
	 * 创建一个缺省的渲染状态, 用于2D渲染
	 *
	 * @return \link wyRenderState wyRenderState\endlink
	 * \endif
	 */
	static wyRenderState* make2D();

	/**
	 * \if English
	 * Generate a default render state for 3D rendering
	 *
	 * @return \link wyRenderState wyRenderState\endlink
	 * \else
	 * 创建一个缺省的渲染状态, 用于3D渲染
	 *
	 * @return \link wyRenderState wyRenderState\endlink
	 * \endif
	 */
	static wyRenderState* make3D();

	virtual ~wyRenderState();
};

#endif // __wyRenderState_h__
