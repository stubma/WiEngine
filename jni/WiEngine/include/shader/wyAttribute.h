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
 * Shader attribute parameter
 */
class WIENGINE_API wyAttribute : public wyShaderVariable {
public:
	/// attribute parameter binding index
	enum Binding {
		/// vertex position
		POSITION,

		/// vertex color
		COLOR,

		/// vertex texture coordinates
		TEXTURE,

		/// normal coordinates
		NORMAL,

		/// Custom attribute which is defined by shader writer
		CUSTOM
	};

	/// Attribute for default attribute binding
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
	 * Constructor
	 *
	 * @param program related shader program id
	 * @param type variable type
	 * @param binding attribute binding type
	 * @return \link wyAttribute wyAttribute\endlink
	 */
	static wyAttribute* make(GLuint program, Type type, Binding binding);

	/**
	 * Constructor
	 *
	 * @param program related shader program id
	 * @param type variable type
	 * @param name attribute name
	 * @param binding attribute binding type
	 * @return \link wyAttribute wyAttribute\endlink
	 */
	static wyAttribute* make(GLuint program, Type type, const char* name, Binding binding);

	virtual ~wyAttribute();

	/// @see wyShaderVariable::getLocation
	virtual GLint getLocation();

	/**
	 * Get related shader program id
	 *
	 * @return shader program id
	 */
	GLuint getProgram() { return m_program; }

	/**
	 * Get attribute binding type
	 *
	 * @return binding type
	 */
	Binding getBinding() { return m_binding; }
};

#endif // __wyAttribute_h__
