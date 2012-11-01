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

#define WY_UNIFORM_MAP map<const char*, wyUniform*, wyStrPredicate>
#define WY_UNIFORM_ITER WY_UNIFORM_MAP::iterator
#define WY_ATTRIBUTE_MAP map<const char*, wyAttribute*, wyStrPredicate>
#define WY_ATTRIBUTE_ITER WY_ATTRIBUTE_MAP::iterator

/**
 * shader program
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
	 * Constructor
	 *
	 * @param vsh vertex shader object
	 * @param fsh fragment shader object
	 * @return \link wyShaderProgram wyShaderProgram\endlink
	 */
	static wyShaderProgram* make(wyShader* vsh, wyShader* fsh);

	virtual ~wyShaderProgram();

	/**
	 * Link program, this method should be called after addAttribute
	 *
	 * @return true if linking is ok
	 */
	bool link();

	/**
	 * Add an uniform binding to this program
	 *
	 * @param type uniform type
	 * @param name uniform name
	 * @param binding uniform binding type
	 */
	void addUniform(wyShaderVariable::Type type, const char* name, wyUniform::Binding binding);

	/**
	 * Add an attribute binding to this program
	 *
	 * @param type attribute type
	 * @param name attribute name
	 * @param binding attribute binding type
	 */
	void addAttribute(wyShaderVariable::Type type, const char* name, wyAttribute::Binding binding);

	/**
	 * Get program id
	 *
	 * @return program id
	 */
	GLuint getProgram() { return m_program; }

	/**
	 * Get uniform by name
	 *
	 * @param name uniform name
	 * @return \link wyUniform wyUniform\endlink, or NULL if not found
	 */
	wyUniform* getUniform(const char* name);

	/**
	 * Get uniform map
	 *
	 * @return map of all uniforms
	 */
	WY_UNIFORM_MAP* getUniforms() { return m_uniforms; }

	/**
	 * Get attribute by name
	 *
	 * @param name attribute name
	 * @return \link wyAttribute wyAttribute\endlink, or NULL if not found
	 */
	wyAttribute* getAttribute(const char* name);

	/**
	 * Get attribute map
	 *
	 * @return map of all attributes
	 */
	WY_ATTRIBUTE_MAP* getAttributes() { return m_attributes; }
};

#endif // __wyShaderProgram_h__
