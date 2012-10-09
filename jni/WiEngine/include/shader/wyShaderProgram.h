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
#ifndef __wyShaderProgram_h__
#define __wyShaderProgram_h__

#include "wyObject.h"
#include "wyUniform.h"
#include "wyAttribute.h"
#include "wyShader.h"

/**
 * @class wyShaderProgram
 *
 * \if English
 * shader program
 * \else
 * shader程序
 * \endif
 */
class WIENGINE_API wyShaderProgram : public wyObject {
private:
	/// program id
	GLuint m_program;

	/// vertex shader
	wyShader* m_vertexShader;

	/// fragment shader
	wyShader* m_fragmentShader;

	/// uniforms
	WY_UNIFORM_MAP* m_uniforms;

	/// attribute
	WY_ATTRIBUTE_MAP* m_attributes;

protected:
	/**
	 * Constructor
	 *
	 * @param vsh vertex shader object
	 * @param fsh fragment shader object
	 */
	wyShaderProgram(wyShader* vsh, wyShader* fsh);

public:
	/**
	 * \if English
	 * Constructor
	 *
	 * @param vsh vertex shader object
	 * @param fsh fragment shader object
	 * @return \link wyShaderProgram wyShaderProgram\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param vsh 顶点shader
	 * @param fsh 分片shader
	 * @return \link wyShaderProgram wyShaderProgram\endlink
	 * \endif
	 */
	static wyShaderProgram* make(wyShader* vsh, wyShader* fsh);

	virtual ~wyShaderProgram();

	/**
	 * \if English
	 * Link program, this method should be called after addAttribute
	 *
	 * @return true if linking is ok
	 * \else
	 * 链接shader程序, 如果想要手动绑定attribute, 则这个方法必须要在\c addAttribute之后
	 * 调用
	 *
	 * @return true表示链接成功
	 * \endif
	 */
	bool link();

	/**
	 * \if English
	 * Add an uniform binding to this program
	 *
	 * @param type uniform type
	 * @param name uniform name
	 * @param binding uniform binding type
	 * \else
	 * 给shader程序添加一个uniform绑定
	 *
	 * @param type uniform参数类型
	 * @param name uniform参数名称
	 * @param binding uniform绑定类型
	 * \endif
	 */
	void addUniform(wyShaderVariable::Type type, const char* name, wyUniform::Binding binding);

	/**
	 * \if English
	 * Add an attribute binding to this program
	 *
	 * @param type attribute type
	 * @param name attribute name
	 * @param binding attribute binding type
	 * \else
	 * 给shader程序添加一个attribute绑定
	 *
	 * @param type 属性参数类型
	 * @param name 属性参数名称
	 * @param binding attribute绑定类型
	 * \endif
	 */
	void addAttribute(wyShaderVariable::Type type, const char* name, wyAttribute::Binding binding);

	/**
	 * \if English
	 * Get program id
	 *
	 * @return program id
	 * \else
	 * 得到shader程序id
	 *
	 * @return 程序id
	 * \endif
	 */
	GLuint getProgram() { return m_program; }

	/**
	 * \if English
	 * Get uniform by name
	 *
	 * @param name uniform name
	 * @return \link wyUniform wyUniform\endlink, or NULL if not found
	 * \else
	 * 根据名称得到uniform参数对象
	 *
	 * @param name uniform参数名称
	 * @return \link wyUniform wyUniform\endlink, 如果没有则返回NULL
	 * \endif
	 */
	wyUniform* getUniform(const char* name);

	/**
	 * \if English
	 * Get uniform map
	 *
	 * @return map of all uniforms
	 * \else
	 * 得到所有的uniform参数哈希表
	 *
	 * @return uniform参数哈希表
	 * \endif
	 */
	WY_UNIFORM_MAP* getUniforms() { return m_uniforms; }

	/**
	 * \if English
	 * Get attribute by name
	 *
	 * @param name attribute name
	 * @return \link wyAttribute wyAttribute\endlink, or NULL if not found
	 * \else
	 * 根据名称得到属性参数对象
	 *
	 * @param name 属性参数名称
	 * @return \link wyAttribute wyAttribute\endlink, 如果没有则返回NULL
	 * \endif
	 */
	wyAttribute* getAttribute(const char* name);

	/**
	 * \if English
	 * Get attribute map
	 *
	 * @return map of all attributes
	 * \else
	 * 得到所有的attribute参数哈希表
	 *
	 * @return attribute参数哈希表
	 * \endif
	 */
	WY_ATTRIBUTE_MAP* getAttributes() { return m_attributes; }
};

#endif // __wyShaderProgram_h__
