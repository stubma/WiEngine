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
#include "wyShaderLoader.h"
#include "wyLog.h"
#include "wyMemory.h"
#include "wyTypes.h"
#include "wyUtils.h"

GLuint wyShaderLoader::load(const char* src, GLenum type) {
	GLuint shader = 0;
	GLint compiled;

	// Create the shader object
	shader = glCreateShader(type);
	if(shader == 0)
		return shader;

	// Load the shader source
	glShaderSource(shader, 1, &src, NULL);

	// Compile the shader
	glCompileShader(shader);

	// Check the compile status
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

	// if failed, print log
	if(!compiled) {
		GLint infoLen = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
		if(infoLen > 1) {
			char* infoLog = (char*)wyMalloc(sizeof(char) * infoLen);
			glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
			LOGE("wyShaderLoader::load: Error compiling shader: %s", infoLog);
			free(infoLog);
		}
		glDeleteShader(shader);
		shader = 0;
	}

	// return shader id
	return shader;
}

GLuint wyShaderLoader::loadVertexShader(int resId) {
	char* src = wyUtils::loadCString(resId);
	GLuint shader = load(src, GL_VERTEX_SHADER);
	wyFree(src);
	return shader;
}

GLuint wyShaderLoader::loadVertexShader(const char* path, bool isFile) {
	char* src = wyUtils::loadCString(path, isFile);
	GLuint shader = load(src, GL_VERTEX_SHADER);
	wyFree(src);
	return shader;
}

GLuint wyShaderLoader::loadMemoryVertexShader(const char* mfsName) {
	char* src = wyUtils::loadCString(mfsName);
	GLuint shader = load(src, GL_VERTEX_SHADER);
	wyFree(src);
	return shader;
}

GLuint wyShaderLoader::loadFragmentShader(int resId) {
	char* src = wyUtils::loadCString(resId);
	GLuint shader = load(src, GL_FRAGMENT_SHADER);
	wyFree(src);
	return shader;
}

GLuint wyShaderLoader::loadFragmentShader(const char* path, bool isFile) {
	char* src = wyUtils::loadCString(path, isFile);
	GLuint shader = load(src, GL_FRAGMENT_SHADER);
	wyFree(src);
	return shader;
}

GLuint wyShaderLoader::loadMemoryFragmentShader(const char* mfsName) {
	char* src = wyUtils::loadCString(mfsName);
	GLuint shader = load(src, GL_FRAGMENT_SHADER);
	wyFree(src);
	return shader;
}
