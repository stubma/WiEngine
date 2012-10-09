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
	/**
	 * \if English
	 * Binding of uniform
	 * \else
	 * Uniform参数绑定
	 * \endif
	 */
	enum Binding {
	    /**
	     * \if English
	     * The world matrix. Converts Model space to World space.
	     * \else
	     * 世界矩阵, 将模型坐标转换为世界坐标
	     * \endif
	     */
	    WORLD_MATRIX,

	    /**
	     * \if English
	     * The view matrix. Converts World space to View space.
	     * \else
	     * 视图矩阵, 将世界坐标转换为视图坐标
	     * \endif
	     */
	    VIEW_MATRIX,

	    /**
	     * \if English
	     * The projection matrix. Converts View space to Clip/Projection space.
	     * \else
	     * 投影矩阵, 将视图坐标转换为投影坐标
	     * \endif
	     */
	    PROJECTION_MATRIX,

	    /**
	     * \if English
	     * The world view matrix. Converts Model space to View space.
	     * \else
	     * World-view矩阵, 将模型坐标转换为视图坐标
	     * \endif
	     */
	    WORLD_VIEW_MATRIX,

	    /**
	     * \if English
	     * The normal matrix. The inverse transpose of the worldview matrix.
	     * Converts normals from model space to view space.
	     * Type: mat3
	     * \else
	     * 法线矩阵, 其是world-view矩阵的逆转置, 将法线从模型坐标转换到视图坐标, 类型是mat3
	     * \endif
	     */
	    NORMAL_MATRIX,

	    /**
	     * \if English
	     * The world view projection matrix. Converts Model space to Clip/Projection
	     * space.
	     * \else
	     * world-view-projection矩阵, 将模型坐标转换为投影坐标
	     * \endif
	     */
	    WORLD_VIEW_PROJECTION_MATRIX,

	    /**
	     * \if English
	     * The view projection matrix. Converts View space to Clip/Projection
	     * space.
	     * \else
	     * view-projection matrix, 将视图坐标转换为投影坐标
	     * \endif
	     */
	    VIEW_PROJECTION_MATRIX,

	    /**
	     * \if English
	     * Texture 2D sample
	     * \else
	     * 2D贴图
	     * \endif
	     */
	    TEXTURE_2D,

	    /**
	     * \if English
	     * A placeholder indicating how many binding type here
	     * \else
	     * 用来表示由多少个绑定类型的占位符号
	     * \endif
	     */
	    CUSTOM
	};

	/**
	 * \if English
	 * Default name for predefined bindings
	 * \else
	 * 预定义的uniform名称
	 * \endif
	 */
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
