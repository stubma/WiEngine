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
 * \c wyRenderState specifies material rendering properties that cannot
 * be controlled by a shader on a \link wyMaterial wyMaterial\endlink. The properties
 * allow manipulation of rendering features such as depth testing, alpha blending,
 * face culling, stencil operations, and much more.
 */
class WIENGINE_API wyRenderState : public wyObject {
public:
	/// Blend mode
	enum BlendMode {
        /// No blending mode is used.
        NO_BLEND,

        /**
         * Additive blending. For use with glows and particle emitters.
         *
         * \par
         * Result = Source Color + Destination Color -> (GL_ONE, GL_ONE)
         */
        ADDITIVE,

        /**
         * Premultiplied alpha blending, for use with premultiplied alpha textures.
         *
         * \par
         * Result = Source Color + (Dest Color * (1 - Source Alpha) ) -> (GL_ONE, GL_ONE_MINUS_SRC_ALPHA)
         */
        PREMULTIPLIED_ALPHA,

        /**
         * Additive blending that is multiplied with source alpha.
         * For use with glows and particle emitters.
         *
         * \par
         * Result = (Source Alpha * Source Color) + Dest Color -> (GL_SRC_ALPHA, GL_ONE)
         */
        ALPHA_ADDITIVE,

        /**
         * Color blending, blends in color from dest color
         * using source color.
         *
         * \par
         * Result = Source Color + (1 - Source Color) * Dest Color -> (GL_ONE, GL_ONE_MINUS_SRC_COLOR)
         */
        COLOR,

        /**
         * Alpha blending, interpolates to source color from dest color
         * using source alpha.
         *
         * \par
         * Result = Source Alpha * Source Color + (1 - Source Alpha) * Dest Color -> (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
         */
        ALPHA,

        /**
         * Multiplies the source and dest colors.
         *
         * \par
         * Result = Source Color * Dest Color -> (GL_DST_COLOR, GL_ZERO)
         */
        MODULATE,

        /**
         * Multiplies the source and dest colors then doubles the result.
         *
         * \par
         * Result = 2 * Source Color * Dest Color -> (GL_DST_COLOR, GL_SRC_COLOR)
         */
        MODULATE_X2
	};

	/// face culling mode
	enum CullMode {
        /// Face culling is disabled.
        NO_CULL,

        /// Cull front faces
        FRONT,

        /// Cull back faces
        BACK,

        /// Cull both front and back faces.
        BOTH
	};

public:
	/// blending mode
	BlendMode blendMode;

	/// face culling mode
	CullMode cullMode;

	/// enable dither or not
	bool ditherEnabled;

	/// enable depth test or not
	bool depthTestEnabled;

	/// Is depth buffer writing enabled or not
	bool depthWriteEnabled;

	/// Is color buffer writing enabled or not
	bool colorWriteEnabled;

protected:
	wyRenderState();

public:
	/**
	 * Generate a default render state for 2D rendering
	 *
	 * @return \link wyRenderState wyRenderState\endlink
	 */
	static wyRenderState* make2D();

	/**
	 * Generate a default render state for 3D rendering
	 *
	 * @return \link wyRenderState wyRenderState\endlink
	 */
	static wyRenderState* make3D();

	virtual ~wyRenderState();
};

#endif // __wyRenderState_h__
