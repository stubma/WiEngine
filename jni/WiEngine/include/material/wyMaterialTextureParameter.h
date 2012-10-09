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
#ifndef __wyMaterialTextureParameter_h__
#define __wyMaterialTextureParameter_h__

#include "wyMaterialParameter.h"

class wyTexture2D;

/**
 * @class wyMaterialTextureParameter
 *
 * \if English
 * Texture parameter for shader
 * \else
 * 用于绑定shader中的贴图参数
 * \endif
 */
class WIENGINE_API wyMaterialTextureParameter : public wyMaterialParameter {
private:
	/// texture unit
	int m_unit;

	/// texture object
	wyTexture2D* m_tex;

protected:
	/**
	 * Static constructor
	 *
	 * @param name related uniform parameter name
	 * @param v value of uniform
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param unit texture unit
	 */
	wyMaterialTextureParameter(const char* name, wyShaderVariable::Value& v, wyTexture2D* tex, int unit);

public:
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param uniformName uniform parameter name
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param unit texture unit, default it zero
	 * @return \link wyMaterialParameter wyMaterialParameter\endif
	 * \else
	 * 静态构造函数
	 *
	 * @param uniformName 材质参数相关的uniform参数名称
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param unit 贴图单元, 缺省是0
	 * @return \link wyMaterialParameter wyMaterialParameter\endlink
	 * \endif
	 */
	static wyMaterialTextureParameter* make(const char* uniformName, wyTexture2D* tex, int unit = 0);

	virtual ~wyMaterialTextureParameter();

	/// @see wyMaterialParameter::apply
	virtual void apply(wyRenderer* r, wyTechnique* tech);

	/**
	 * \if English
	 * Get texture unit
	 *
	 * @return texture unit
	 * \else
	 * 得到贴图单元序号
	 *
	 * @return 贴图单元
	 * \endif
	 */
	int getUnit() { return m_unit; }

	/**
	 * \if English
	 * Set texture
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * \else
	 * 设置贴图
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * \endif
	 */
	void setTexture(wyTexture2D* tex) { m_tex = tex; }
};

#endif // __wyMaterialTextureParameter_h__
