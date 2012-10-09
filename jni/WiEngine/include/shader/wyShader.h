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
 * @class wyShader
 *
 * \if English
 * Represent a shader
 * \else
 * 代表了一个shader
 * \endif
 */
class WIENGINE_API wyShader : public wyObject {
public:
	/**
	 * \if English
	 * Shader language define
	 * \else
	 * shader语言类型
	 * \endif
	 */
	enum Language {
		/**
		 * \if English
		 * OpenGL shading language
		 * \else
		 * OpenGL专用的shading语言
		 * \endif
		 */
		GLSL,

		/**
		 * \if English
		 * for DirectX, high level shading language
		 * \else
		 * DirectX专用的shading语言
		 * \endif
		 */
		HLSL,

		/**
		 * \if English
		 * nvidia shading language, for OpenGL and DirectX
		 * \else
		 * nvidia定义的可以用于OpenGL和DirectX的shading语言
		 * \endif
		 */
		CG
	};

	/**
	 * \if English
	 * Shader type
	 * \else
	 * shader类型
	 */
	enum Type {
        /**
         * \if English
         * Control vertex processing. (e.g transform of model to clip space)
         * \else
         * 顶点shader
         * \endif
         */
		VERTEX,

        /**
         * \if English
         * Control fragment rasterization. (e.g color of pixel).
         * \else
         * 分片shader
         * \endif
         */
		FRAGMENT,

        /**
         * \if English
         * Control geometry assembly. (e.g compile a triangle list from input data).
         * Supported after GLSL 1.5
         * \else
         * 物体shader, GLSL 1.5之后支持
         * \endif
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
	 * \if English
	 * Static constructor
	 *
	 * @param type shader type
	 * @param resId resource id of shader file
	 * @return \link wyShader wyShader\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param type shader类型
	 * @param resId shader源文件的资源id
	 * @return \link wyShader wyShader\endlink
	 * \endif
	 */
	static wyShader* make(Type type, int resId);

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param type shader type
	 * @param path shader file path
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 		is a relative path under assets
	 * @return \link wyShader wyShader\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param type shader类型
	 * @param path shader文件路径
	 * @param isFile true表示\c path是一个文件系统的绝对路径, false表示\c path是一个assets下的
	 * 		相对路径
	 * @return \link wyShader wyShader\endlink
	 * \endif
	 */
	static wyShader* make(Type type, const char* path, bool isFile = false);

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param type shader type
	 * @param mfsName memory file name of shader file
	 * @return \link wyShader wyShader\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param type shader类型
	 * @param mfsName shader文件的内存文件名
	 * @return \link wyShader wyShader\endlink
	 * \endif
	 */
	static wyShader* makeMemory(Type type, const char* mfsName);

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param type shader type
	 * @param src shader source
	 * @return \link wyShader wyShader\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param type shader类型
	 * @param src shader源代码
	 * @return \link wyShader wyShader\endlink
	 * \endif
	 */
	static wyShader* makeRaw(Type type, const char* src);

	virtual ~wyShader();

	/**
	 * \if English
	 * Get shader type
	 *
	 * @return shader type, defined by GL
	 * \else
	 * 得到shader类型
	 *
	 * @return shader类型
	 * \endif
	 */
	Type getType() { return m_type; }

	/**
	 * \if English
	 * Get shader id
	 *
	 * @return shader id
	 * \else
	 * 得到shader id
	 *
	 * @return shader id
	 * \endif
	 */
	GLuint getShader() { return m_shader; }

	/**
	 * \if English
	 * Get shader language
	 *
	 * @return shader language constant
	 * \else
	 * 得到shader语言类型
	 *
	 * @return shader语言类型常量
	 * \endif
	 */
	Language getLanguage() { return m_language; }
};

#endif // __wyShader_h__
