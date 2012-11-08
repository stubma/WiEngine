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
#ifndef __wyMaterial_h__
#define __wyMaterial_h__

#include "wyObject.h"
#include "wyMaterialTextureParameter.h"
#include "wyTechnique.h"

/**
 * \c wyMaterial describes the rendering style for a given \link wyNode wyNode\endlink
 *
 * \par
 * A material is essentially a list of \link wyMaterialParameter wyMaterialParameter\endlink
 * those parameters map to uniforms which are defined in a shader. Setting the parameters
 * can modify the behavior of a shader.
 */
class WIENGINE_API wyMaterial : public wyObject {
private:
	/// parameter map
	map<unsigned int, wyMaterialParameter*>* m_params;

	/// technique used to render this material
	wyTechnique* m_technique;

	/// shader program key
	int m_programKey;

protected:
	/**
	 * Constructor
	 *
	 * @param programKey shader program key
	 */
	wyMaterial(int programKey);

public:
	static wyMaterial* make();

	/**
	 * Create material instance which use non-default shader program
	 *
	 * @param programKey shader program key
	 */
	static wyMaterial* make(int programKey);

	/**
	 * Create material and auto bound a texture to it
	 *
	 * @param tex texture object
	 */
	static wyMaterial* make(wyTexture2D* tex);

	/**
	 * Create material instance which use specified program and a texture bounded
	 *
	 * @param programKey shader program key
	 * @param tex texture object
	 */
	static wyMaterial* make(int programKey, wyTexture2D* tex);

	virtual ~wyMaterial();

	/**
	 * Add parameter
	 *
	 * @param p \link wyMaterialParameter wyMaterialParameter\endlink
	 */
	void addParameter(wyMaterialParameter* p);

	/**
	 * Get map of all parameters
	 *
	 * @return map of all parameters
	 */
	map<unsigned int, wyMaterialParameter*>* getParameters() { return m_params; }

	/**
	 * Get material parameter by uniform name
	 *
	 * @param uniformName name of uniform that parameter bound to
	 * @return \link wyMaterialParameter wyMaterialParameter\endlink, or NULL if not found
	 */
	wyMaterialParameter* getParameter(const char* uniformName);

	/**
	 * Get used technique
	 *
	 * @return \link wyTechnique wyTechnique\endlink
	 */
	wyTechnique* getTechnique();

	/**
	 * Set technique
	 *
	 * @param tech \link wyTechnique wyTechnique\endlink
	 */
	void setTechnique(wyTechnique* tech);
};

#endif // __wyMaterial_h__
