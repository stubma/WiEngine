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
#include "wyShaderManager.h"
#include "common_position_texture_color_fsh.h"
#include "common_position_texture_color_vsh.h"

/// global singleton
wyShaderManager* gShaderManager = NULL;

wyShaderManager::wyShaderManager() {
	m_programs = WYNEW map<int, wyShaderProgram*>();
	loadBuiltinShaders();
}

wyShaderManager::~wyShaderManager() {
	for(map<int, wyShaderProgram*>::iterator iter = m_programs->begin(); iter != m_programs->end(); iter++)
		wyObjectRelease(iter->second);
	WYDELETE(m_programs);

	// clear singleton
	gShaderManager = NULL;
}

wyShaderManager* wyShaderManager::getInstance() {
	if(gShaderManager == NULL)
		gShaderManager = WYNEW wyShaderManager();
	return gShaderManager;
}

void wyShaderManager::loadBuiltinShaders() {
	wyShader* vsh = wyShader::makeRaw(wyShader::VERTEX, common_position_texture_color_vsh);
	wyShader* fsh = wyShader::makeRaw(wyShader::FRAGMENT, common_position_texture_color_fsh);
	wyShaderProgram* p = addProgram(PROG_PCT, vsh, fsh);
	p->addAttribute(wyShaderVariable::VEC4, wyAttribute::NAME[wyAttribute::POSITION], wyAttribute::POSITION);
	p->addAttribute(wyShaderVariable::VEC4, wyAttribute::NAME[wyAttribute::COLOR], wyAttribute::COLOR);
	p->addAttribute(wyShaderVariable::VEC2, wyAttribute::NAME[wyAttribute::TEXTURE], wyAttribute::TEXTURE);
	if(p->link()) {
		p->addUniform(wyShaderVariable::MAT4,
				wyUniform::NAME[wyUniform::WORLD_VIEW_PROJECTION_MATRIX],
				wyUniform::WORLD_VIEW_PROJECTION_MATRIX);
		p->addUniform(wyShaderVariable::TEXTURE_2D,
				wyUniform::NAME[wyUniform::TEXTURE_2D],
				wyUniform::TEXTURE_2D);
	}
}

wyShaderProgram* wyShaderManager::getProgram(int key) {
	map<int, wyShaderProgram*>::iterator iter = m_programs->find(key);
	if(iter == m_programs->end()) {
		iter = m_programs->find(EXTERNAL + key);
		if(iter == m_programs->end())
			return NULL;
		else
			return iter->second;
	} else {
		return iter->second;
	}
}

wyShaderProgram* wyShaderManager::addProgram(int programKey, wyShader* vsh, wyShader* fsh) {
	wyShaderProgram* p = wyShaderProgram::make(vsh, fsh);
	(*m_programs)[programKey] = p;
	p->retain();
	return p;
}

wyShaderProgram* wyShaderManager::addProgram(int programKey, const char* vshPath, bool vshIsFile, const char* fshPath, bool fshIsFile) {
	wyShader* vsh = wyShader::make(wyShader::VERTEX, vshPath, vshIsFile);
	wyShader* fsh = wyShader::make(wyShader::FRAGMENT, fshPath, fshIsFile);
	return addProgram(EXTERNAL + programKey, vsh, fsh);
}

wyShaderProgram* wyShaderManager::addProgram(int programKey, int vshResId, int fshResId) {
	wyShader* vsh = wyShader::make(wyShader::VERTEX, vshResId);
	wyShader* fsh = wyShader::make(wyShader::FRAGMENT, fshResId);
	return addProgram(EXTERNAL + programKey, vsh, fsh);
}

wyShaderProgram* wyShaderManager::addProgram(int programKey, const char* vshSrc, const char* fshSrc) {
	wyShader* vsh = wyShader::makeRaw(wyShader::VERTEX, vshSrc);
	wyShader* fsh = wyShader::makeRaw(wyShader::FRAGMENT, fshSrc);
	return addProgram(EXTERNAL + programKey, vsh, fsh);
}
