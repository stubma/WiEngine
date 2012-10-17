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
#include "wyMaterialTextureParameter.h"
#include "wyTexture2D.h"
#include "wyTechnique.h"
#include "wyRenderer.h"

wyMaterialTextureParameter::wyMaterialTextureParameter(const char* name, wyShaderVariable::Value& v, wyTexture2D* tex, int unit) :
		wyMaterialParameter(name, v),
		m_unit(unit),
		m_tex(NULL) {
	m_tex = tex;
	wyObjectRetain(m_tex);
}

wyMaterialTextureParameter::~wyMaterialTextureParameter() {
	wyObjectRelease(m_tex);
}

wyMaterialTextureParameter* wyMaterialTextureParameter::make(const char* uniformName, wyTexture2D* tex, int unit) {
	wyShaderVariable::Value v;
	v.i = unit;
	wyMaterialTextureParameter* p = WYNEW wyMaterialTextureParameter(uniformName, v, tex, unit);
	return(wyMaterialTextureParameter*)p->autoRelease();
}

void wyMaterialTextureParameter::apply(wyRenderer* r, wyTechnique* tech) {
	r->setTexture(m_unit, m_tex);
	tech->updateUniformValue(m_name, m_value);
}

void wyMaterialTextureParameter::setTexture(wyTexture2D* tex) {
	wyObjectRetain(tex);
	wyObjectRelease(m_tex);
	m_tex = tex;
}
