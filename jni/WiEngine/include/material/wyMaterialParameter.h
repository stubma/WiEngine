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
#ifndef __wyMaterialParameter_h__
#define __wyMaterialParameter_h__

#include "wyObject.h"
#include "wyUniform.h"

class wyTechnique;
class wyRenderer;

/**
 * Material parameter which will be bound to shader uniform
 */
class WIENGINE_API wyMaterialParameter : public wyObject {
protected:
	/// related uniform name of this parameter
	const char* m_name;

	/// value of uniform
	wyShaderVariable::Value m_value;

protected:
	/**
	 * Static constructor
	 *
	 * @param name related uniform parameter name
	 * @param v value of uniform
	 */
	wyMaterialParameter(const char* name, wyShaderVariable::Value& v);

public:
	/**
	 * Static constructor
	 *
	 * @param uniformName uniform parameter name
	 * @param v value of uniform
	 * @return \link wyMaterialParameter wyMaterialParameter\endlink
	 */
	static wyMaterialParameter* make(const char* uniformName, wyShaderVariable::Value& v);

	virtual ~wyMaterialParameter();

	/**
	 * Apply this parameter to a technique
	 *
	 * @param r \link wyRenderer wyRenderer\endlink
	 * @param tech \link wyTechnique wyTechnique\endlink
	 */
	virtual void apply(wyRenderer* r, wyTechnique* tech);

	/**
	 * Get parameter name, the name must be same as someone in shader
	 *
	 * @return parameter name
	 */
	const char* getName() { return m_name; }

	/**
	 * Get parameter value
	 *
	 * @return parameter value
	 */
	wyShaderVariable::Value& getValue() { return m_value; }

	/**
	 * Set parameter value. You must ensure the value has proper content against
	 * uniform type.
	 *
	 * @param v new value
	 */
	void setValue(wyShaderVariable::Value v);
};

#endif // __wyMaterialParameter_h__
