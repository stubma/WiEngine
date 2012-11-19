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
#ifndef __wyShaderLoader_h__
#define __wyShaderLoader_h__

#include "wyGlobal.h"

/**
 * @class wyShaderLoader
 *
 * Shader loader
 */
class WIENGINE_API wyShaderLoader {
public:
	/**
	 * Load shader from source string
	 *
	 * @param src shader source
	 * @param type shader type
	 * @return shader id
	 */
	static GLuint load(const char* src, GLenum type);

	/**
	 * Load vertex shader from resource id
	 *
	 * @param resId shader file resource id
	 * @return shader id
	 */
	static GLuint loadVertexShader(int resId);

	/**
	 * Load vertex shader from resource id
	 *
	 * @param path vertex shader file path
	 * @param isFile true means \c path is an absolution path in file system, or false means \c path
	 * 		is a relative path under assets
	 * @return shader id
	 */
	static GLuint loadVertexShader(const char* path, bool isFile = false);

	/**
	 * Load vertex shader from memory file
	 *
	 * @param mfsName shader memory file name
	 * @return shader id
	 */
	static GLuint loadMemoryVertexShader(const char* mfsName);

	/**
	 * Load fragment shader from resource id
	 *
	 * @param resId shader file resource id
	 * @return shader id
	 */
	static GLuint loadFragmentShader(int resId);

	/**
	 * Load fragment shader from resource id
	 *
	 * @param path vertex shader file path
	 * @param isFile true means \c path is an absolution path in file system, or false means \c path
	 * 		is a relative path under assets
	 * @return shader id
	 */
	static GLuint loadFragmentShader(const char* path, bool isFile = false);

	/**
	 * Load fragment shader from memory file
	 *
	 * @param mfsName shader memory file name
	 * @return shader id
	 */
	static GLuint loadMemoryFragmentShader(const char* mfsName);
};

#endif // __wyShaderLoader_h__
