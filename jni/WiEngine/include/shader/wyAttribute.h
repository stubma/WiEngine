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
#ifndef __wyAttribute_h__
#define __wyAttribute_h__

#include "wyShaderVariable.h"

/**
 * @class wyAttribute
 *
 * \if English
 * Attribute argument
 * \else
 * 属性参数
 * \endif
 */
class WIENGINE_API wyAttribute : public wyShaderVariable {
public:
	/**
	 * \if English
	 * attribute parameter binding index
	 * \else
	 * 属性参数的绑定位置和含义
	 * \endif
	 */
	enum Binding {
		/**
		 * \if English
		 * vertex position
		 * \else
		 * 顶点位置
		 * \endif
		 */
		POSITION,

		/**
		 * \if English
		 * vertex color
		 * \else
		 * 顶点颜色
		 * \endif
		 */
		COLOR,

		/**
		 * \if English
		 * vertex texture coordinates
		 * \else
		 * 顶点贴图坐标
		 * \endif
		 */
		TEXTURE,

		/**
		 * \if English
		 * normal coordinates
		 * \else
		 * 法线坐标
		 * \endif
		 */
		NORMAL,

		/**
		 * \if English
		 * Custom attribute which is defined by shader writer
		 * \else
		 * 用作其它目的的属性参数
		 * \endif
		 */
		CUSTOM
	};

	/**
	 * \if English
	 * Attribute for default attribute binding
	 * \else
	 * 预定义的属性参数名称
	 * \endif
	 */
	static const char* NAME[];

private:
	/// attribute binding type
	Binding m_binding;

	/// related programe id
	GLuint m_program;

protected:
	/**
	 * Constructor
	 *
	 * @param program related shader program id
	 * @param type variable type
	 * @param name attribute name
	 * @param binding attribute binding type
	 */
	wyAttribute(GLuint program, Type type, const char* name, Binding binding);

public:
	/**
	 * \if English
	 * Constructor
	 *
	 * @param program related shader program id
	 * @param type variable type
	 * @param binding attribute binding type
	 * @return \link wyAttribute wyAttribute\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param program 相关的shader程序id
	 * @param type 参数类型
	 * @param binding 属性绑定类型
	 * @return \link wyAttribute wyAttribute\endlink
	 * \endif
	 */
	static wyAttribute* make(GLuint program, Type type, Binding binding);

	/**
	 * \if English
	 * Constructor
	 *
	 * @param program related shader program id
	 * @param type variable type
	 * @param name attribute name
	 * @param binding attribute binding type
	 * @return \link wyAttribute wyAttribute\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param program 相关的shader程序id
	 * @param type 参数类型
	 * @param name 参数名称
	 * @param binding 属性绑定类型
	 * @return \link wyAttribute wyAttribute\endlink
	 * \endif
	 */
	static wyAttribute* make(GLuint program, Type type, const char* name, Binding binding);

	virtual ~wyAttribute();

	/// @see wyShaderVariable::getLocation
	virtual GLint getLocation();

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
	 * Get attribute binding type
	 *
	 * @return binding type
	 * \else
	 * 得到属性参数的绑定含义
	 *
	 * @return 属性参数的绑定含义
	 * \endif
	 */
	Binding getBinding() { return m_binding; }
};

#endif // __wyAttribute_h__
