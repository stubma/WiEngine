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
 * @class wyMaterial
 *
 * \if English
 * \c wyMaterial describes the rendering style for a given \link wyGeometry wyGeometry\endlink
 *
 * \par
 * A material is essentially a list of \link wyMaterialParams wyMaterialParams\endlink
 * those parameters map to uniforms which are defined in a shader. Setting the parameters
 * can modify the behavior of a shader.
 * \else
 * \c wyMaterial, 即材质, 描述了一个\link wyGeometry wyGeometry\endlink对象的渲染方式
 *
 * \par
 * 材质实际上是一系列的\link wyMaterialParams wyMaterialParams\endlink组成的, 这些参数对应着
 * shader中的uniform参数, 设置它们会修改shader的uniform参数, 从而改变渲染的效果
 * \endif
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
	 * @param material object
	 */
	static wyMaterial* make(int programKey);

	/**
	 * Create material and auto bound a texture to it
	 *
	 * @param tex texture object
	 * @return material object
	 */
	static wyMaterial* make(wyTexture2D* tex);

	/**
	 * Create material instance which use specified program and a texture bounded
	 *
	 * @param programKey shader program key
	 * @param tex texture object
	 * @param material object
	 */
	static wyMaterial* make(int programKey, wyTexture2D* tex);

	virtual ~wyMaterial();

	/**
	 * \if English
	 * Add parameter
	 *
	 * @param p \link wyMaterialParameter wyMaterialParameter\endlink
	 * \else
	 * 添加材质参数
	 *
	 * @param p \link wyMaterialParameter wyMaterialParameter\endlink
	 * \endif
	 */
	void addParameter(wyMaterialParameter* p);

	/**
	 * \if English
	 * Get map of all parameters
	 *
	 * @return map of all parameters
	 * \else
	 * 得到所有材质参数的哈希表
	 *
	 * @return 材质参数的哈希表
	 * \endif
	 */
	map<unsigned int, wyMaterialParameter*>* getParameters() { return m_params; }

	/**
	 * \if English
	 * Get material parameter by uniform name
	 *
	 * @param uniformName name of uniform that parameter bound to
	 * @return \link wyMaterialParameter wyMaterialParameter\endlink, or NULL if not found
	 * \else
	 * 根据uniform参数名称得到相关的材质参数
	 *
	 * @param uniformName uniform参数名称
	 * @return \link wyMaterialParameter wyMaterialParameter\endlink, 如果没有找到, 返回0
	 * \endif
	 */
	wyMaterialParameter* getParameter(const char* uniformName);

	/**
	 * \if English
	 * Get used technique
	 *
	 * @return \link wyTechnique wyTechnique\endlink
	 * \else
	 * 得到渲染材质所用的技术
	 *
	 * @return \link wyTechnique wyTechnique\endlink
	 * \endif
	 */
	wyTechnique* getTechnique();

	/**
	 * \if English
	 * Set technique
	 *
	 * @param tech \link wyTechnique wyTechnique\endlink
	 * \else
	 * 设置渲染技术
	 *
	 * @param tech \link wyTechnique wyTechnique\endlink
	 * \endif
	 */
	void setTechnique(wyTechnique* tech);
};

#endif // __wyMaterial_h__
