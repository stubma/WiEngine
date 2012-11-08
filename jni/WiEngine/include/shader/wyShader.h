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
#ifndef __wyShader_h__
#define __wyShader_h__

#include "wyObject.h"

/**
 * Represent a shader, such as fragment shader, vertex shader
 */
class WIENGINE_API wyShader : public wyObject {
public:
	/// Shader language define
	enum Language {
		/// OpenGL shading language
		GLSL,

		/// for DirectX, high level shading language
		HLSL,

		/// nvidia shading language, for OpenGL and DirectX
		CG
	};

	/// Shader type
	enum Type {
        /// Control vertex processing. (e.g transform of model to clip space)
		VERTEX,

        /// Control fragment rasterization. (e.g color of pixel).
		FRAGMENT,

        /**
         * Control geometry assembly. (e.g compile a triangle list from input data).
         * Supported after GLSL 1.5
         */
		GEOMETRY
	};

protected:
	/// shader language
	Language m_language;

	/// shader type
	Type m_type;

	/// shader id
	GLuint m_shader;

protected:
	/**
	 * Constructor
	 *
	 * @param type shader type
	 * @param shader shader id
	 */
	wyShader(Type type, GLuint shader);

public:
	/**
	 * Static constructor
	 *
	 * @param type shader type
	 * @param resId resource id of shader file
	 * @return \link wyShader wyShader\endlink
	 */
	static wyShader* make(Type type, int resId);

	/**
	 * Static constructor
	 *
	 * @param type shader type
	 * @param path shader file path
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 		is a relative path under assets
	 * @return \link wyShader wyShader\endlink
	 */
	static wyShader* make(Type type, const char* path, bool isFile = false);

	/**
	 * Static constructor
	 *
	 * @param type shader type
	 * @param mfsName memory file name of shader file
	 * @return \link wyShader wyShader\endlink
	 */
	static wyShader* makeMemory(Type type, const char* mfsName);

	/**
	 * Static constructor
	 *
	 * @param type shader type
	 * @param src shader source
	 * @return \link wyShader wyShader\endlink
	 */
	static wyShader* makeRaw(Type type, const char* src);

	virtual ~wyShader();

	/**
	 * Get shader type
	 *
	 * @return shader type, defined by GL
	 */
	Type getType() { return m_type; }

	/**
	 * Get shader id
	 *
	 * @return shader id
	 */
	GLuint getShader() { return m_shader; }

	/**
	 * Get shader language
	 *
	 * @return shader language constant
	 */
	Language getLanguage() { return m_language; }
};

#endif // __wyShader_h__
