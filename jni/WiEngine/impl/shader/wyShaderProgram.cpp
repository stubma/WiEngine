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
#include "wyShaderProgram.h"
#include "wyLog.h"
#include "wyMemory.h"
#include "wyDirector.h"

extern wyDirector* gDirector;

wyShaderProgram::wyShaderProgram(wyShader* vsh, wyShader* fsh) {
	// save shader
	m_vertexShader = vsh;
	m_vertexShader->retain();
	m_fragmentShader = fsh;
	m_fragmentShader->retain();

	// create uniform and attribute list
	m_uniforms = WYNEW WY_UNIFORM_MAP();
	m_attributes = WYNEW WY_ATTRIBUTE_MAP();

	// Create the program object
	m_program = glCreateProgram();
	if(m_program != 0) {
		// attach shader to program
		glAttachShader(m_program, m_vertexShader->getShader());
		glAttachShader(m_program, m_fragmentShader->getShader());
	}
}

wyShaderProgram::~wyShaderProgram() {
	// release shaders
	m_vertexShader->release();
	m_fragmentShader->release();

	// release uniform
	for(WY_UNIFORM_ITER iter = m_uniforms->begin(); iter != m_uniforms->end(); iter++) {
		wyFree((void*)iter->first);
		wyObjectRelease(iter->second);
	}
	WYDELETE(m_uniforms);

	// release attribute
	for(WY_ATTRIBUTE_ITER iter = m_attributes->begin(); iter != m_attributes->end(); iter++) {
		wyFree((void*)iter->first);
		wyObjectRelease(iter->second);
	}
	WYDELETE(m_attributes);

	// release program
	if(m_program > 0 && gDirector->isSurfaceCreated()) {
		glDeleteProgram(m_program);
		m_program = 0;
	}
}

wyShaderProgram* wyShaderProgram::make(wyShader* vsh, wyShader* fsh) {
	wyShaderProgram* p = WYNEW wyShaderProgram(vsh, fsh);
	if(p->getProgram() <= 0) {
		p->release();
		return NULL;
	} else {
		return (wyShaderProgram*)p->autoRelease();
	}
}

bool wyShaderProgram::link() {
	// Link the program
	glLinkProgram(m_program);

	// Check the link status
	GLint linked = 0;
	glGetProgramiv(m_program, GL_LINK_STATUS, &linked);
	if(!linked) {
		GLint infoLen = 0;
		glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &infoLen);
		if(infoLen > 1) {
			char* infoLog = (char*)wyMalloc(sizeof(char) * infoLen);
			glGetProgramInfoLog(m_program, infoLen, NULL, infoLog);
			LOGE("wyShaderProgram::link: error, %s", infoLog);
			wyFree(infoLog);
		}
		glDeleteProgram(m_program);
		return false;
	} else {
		return true;
	}
}

wyUniform* wyShaderProgram::getUniform(const char* name) {
	WY_UNIFORM_ITER iter = m_uniforms->find(name);
	if(iter == m_uniforms->end())
		return NULL;
	else
		return iter->second;
}

wyAttribute* wyShaderProgram::getAttribute(const char* name) {
	WY_ATTRIBUTE_ITER iter = m_attributes->find(name);
	if(iter == m_attributes->end())
		return NULL;
	else
		return iter->second;
}

void wyShaderProgram::addUniform(wyShaderVariable::Type type, const char* name, wyUniform::Binding binding) {
	wyUniform* u = wyUniform::make(m_program, type, name, binding);
	if(u->getLocation() < 0) {
		LOGW("wyShaderProgram::addUniform: failed to bind uniform %s", name);
	} else {
		(*m_uniforms)[wyUtils::copy(name)] = u;
		u->retain();
	}
}

void wyShaderProgram::addAttribute(wyShaderVariable::Type type, const char* name, wyAttribute::Binding binding) {
	wyAttribute* a = wyAttribute::make(m_program, type, name, binding);
	(*m_attributes)[wyUtils::copy(name)] = a;
	a->retain();
}
