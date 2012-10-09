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
#include "wyTechnique.h"
#include "wyShaderManager.h"

extern wyShaderManager* gShaderManager;

wyTechnique::wyTechnique(int programKey) :
		m_programKey(programKey),
		m_renderState(NULL) {
}

wyTechnique::~wyTechnique() {
	wyObjectRelease(m_renderState);
}

wyTechnique* wyTechnique::make(int programKey) {
	wyTechnique* t = WYNEW wyTechnique(programKey);
	return (wyTechnique*)t->autoRelease();
}

wyTechnique* wyTechnique::make() {
	return make(wyShaderManager::DEFAULT_PROGRAM);
}

void wyTechnique::setRenderState(wyRenderState* state) {
	wyObjectRetain(state);
	wyObjectRelease(m_renderState);
	m_renderState = state;
}

wyRenderState* wyTechnique::getRenderState() {
	if(!m_renderState)
		setRenderState(wyRenderState::make2D());
	return m_renderState;
}

void wyTechnique::updateUniformValue(const char* name, wyShaderVariable::Value& v) {
	if(gShaderManager) {
		wyShaderProgram* program = gShaderManager->getProgram(m_programKey);
		if(program) {
			wyUniform* uniform = program->getUniform(name);
			if(uniform)
				uniform->setValue(v);
		}
	}
}
