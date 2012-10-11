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
#include "wyMaterial.h"

wyMaterial::wyMaterial(int programKey) :
		m_programKey(programKey),
		m_technique(NULL) {
	m_params = WYNEW map<unsigned int, wyMaterialParameter*>();
}

wyMaterial::~wyMaterial() {
	for(map<unsigned int, wyMaterialParameter*>::iterator iter = m_params->begin(); iter != m_params->end(); iter++)
		wyObjectRelease(iter->second);
	WYDELETE(m_params);

	wyObjectRelease(m_technique);
}

wyMaterial* wyMaterial::make() {
	wyMaterial* m = WYNEW wyMaterial(wyShaderManager::DEFAULT_PROGRAM);
	return (wyMaterial*)m->autoRelease();
}

wyMaterial* wyMaterial::make(int programKey) {
	wyMaterial* m = WYNEW wyMaterial(programKey);
	return (wyMaterial*)m->autoRelease();
}

void wyMaterial::addParameter(wyMaterialParameter* p) {
	if(p) {
		(*m_params)[wyUtils::strHash(p->getName())] = p;
		p->retain();
	}
}

wyMaterialParameter* wyMaterial::getParameter(const char* uniformName) {
	map<unsigned int, wyMaterialParameter*>::iterator iter = m_params->find(wyUtils::strHash(uniformName));
	if(iter == m_params->end())
		return NULL;
	else
		return iter->second;
}

void wyMaterial::setTechnique(wyTechnique* tech) {
	wyObjectRetain(tech);
	wyObjectRelease(m_technique);
	m_technique = tech;
}

wyTechnique* wyMaterial::getTechnique() {
	if(!m_technique) {
		setTechnique(wyTechnique::make(m_programKey));
	}
	return m_technique;
}
