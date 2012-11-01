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
#ifndef __wyTechnique_h__
#define __wyTechnique_h__

#include "wyShaderManager.h"
#include "wyRenderState.h"

/**
 * \c wyTechnique represents all settings need to be known when render a geometry. Change
 * it with other instance can achieve different render effect
 */
class WIENGINE_API wyTechnique : public wyObject {
protected:
	/// shader program key
	int m_programKey;

	/// render state object
	wyRenderState* m_renderState;

protected:
	/**
	 * constructor
	 *
	 * @param programKey shader program key
	 */
	wyTechnique(int programKey);

public:
	/**
	 * Static constructor
	 *
	 * @param programKey shader program key
	 * @return \link wyTechnique wyTechnique\endlink
	 */
	static wyTechnique* make(int programKey);

	/**
	 * Create a default technique
	 *
	 * @return \link wyTechnique wyTechnique\endlink
	 */
	static wyTechnique* make();

	virtual ~wyTechnique();

	/**
	 * Change shader program of this technique
	 *
	 * @param key program key, also known as id, generated when add program to shader manager
	 */
	void setProgram(int key) { m_programKey = key; }

	/**
	 * Get shader program this technique used
	 *
	 * @return \link wyShaderProgram wyShaderProgram\endlink
	 */
	wyShaderProgram* getShaderProgram() { return wyShaderManager::getInstance()->getProgram(m_programKey); }

	/**
	 * Update uniform value by uniform name
	 *
	 * @param name name of uniform
	 * @param v value of uniform
	 */
	void updateUniformValue(const char* name, wyShaderVariable::Value& v);

	/**
	 * Get render state this technique use
	 *
	 * @param \link wyRenderState wyRenderState\endlink
	 */
	wyRenderState* getRenderState();

	/**
	 * Set render state
	 *
	 * @param state \link wyRenderState wyRenderState\endlink
	 */
	void setRenderState(wyRenderState* state);
};

#endif // __wyTechnique_h__
