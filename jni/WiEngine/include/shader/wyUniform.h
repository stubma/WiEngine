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
#ifndef __wyUniform_h__
#define __wyUniform_h__

#include "wyShaderVariable.h"

/**
 * @class wyUniform
 *
 * \if English
 * Uniform argument
 * \else
 * Uniform参数
 * \endif
 */
class WIENGINE_API wyUniform : public wyShaderVariable {
public:
	/// Binding of uniform
	enum Binding {
	    /// The world matrix. Converts Model space to World space.
	    WORLD_MATRIX,

	    /// The view matrix. Converts World space to View space.
	    VIEW_MATRIX,

	    /// The projection matrix. Converts View space to Clip/Projection space.
	    PROJECTION_MATRIX,

	    /// The world view matrix. Converts Model space to View space.
	    WORLD_VIEW_MATRIX,

	    /**
	     * The normal matrix. The inverse transpose of the worldview matrix.
	     * Converts normals from model space to view space.
	     * Type: mat3
	     */
	    NORMAL_MATRIX,

	    /**
	     * The world view projection matrix. Converts Model space to Clip/Projection
	     * space.
	     */
	    WORLD_VIEW_PROJECTION_MATRIX,

	    /**
	     * The view projection matrix. Converts View space to Clip/Projection
	     * space.
	     */
	    VIEW_PROJECTION_MATRIX,

	    /// Texture 2D sample
	    TEXTURE_2D,

	    /// point sprite size
	    POINT_SIZE,

	    /// A placeholder indicating how many binding type here
	    CUSTOM
	};

	/// Default name for predefined bindings
	static const char* NAME[];

private:
	/// uniform binding type
	Binding m_binding;

	/// related shader program
	GLuint m_program;

protected:
	/**
	 * Constructor
	 *
	 * @param program shader program id
	 * @param type variable type
	 * @param name name of uniform
	 * @param binding binding type for this uniform
	 */
	wyUniform(GLuint program, Type type, const char* name, Binding binding);

public:
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param program shader program id
	 * @param type variable type
	 * @param binding binding type for this uniform
	 * @return \link wyUniform wyUniform\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param program shader程序id
	 * @param type 参数类型
	 * @param binding uniform绑定类型
	 * @return \link wyUniform wyUniform\endlink
	 * \endif
	 */
	static wyUniform* make(GLuint program, Type type, Binding binding);

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param program shader program id
	 * @param type variable type
	 * @param name name of uniform
	 * @param binding binding type for this uniform
	 * @return \link wyUniform wyUniform\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param program shader程序id
	 * @param type 参数类型
	 * @param name uniform参数名称
	 * @param binding uniform绑定类型
	 * @return \link wyUniform wyUniform\endlink
	 * \endif
	 */
	static wyUniform* make(GLuint program, Type type, const char* name, Binding binding);

	virtual ~wyUniform();

	/**
	 * \if English
	 * Get related shader program id
	 *
	 * @return shader program id
	 * \else
	 * 得到相关的shader程序id
	 *
	 * @return shader程序id
	 * \endif
	 */
	GLuint getProgram() { return m_program; }

	/**
	 * if English
	 * Get uniform binding type
	 *
	 * @return binding type
	 * \else
	 * 得到uniform参数的绑定含义
	 *
	 * @return uniform参数的绑定含义
	 * \endif
	 */
	Binding getBinding() { return m_binding; }
};

#endif // __wyUniform_h__
