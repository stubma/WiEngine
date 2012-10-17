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
#ifndef __wyColorLayer_h__
#define __wyColorLayer_h__

#include "wyLayer.h"
#include "wyGlobal.h"

/**
 * @class wyColorLayer
 * \if English
 * a color layer, visible
 * \else
 * 有底色显示层的封装
 * \endif
 */
class WIENGINE_API wyColorLayer : public wyLayer {
private:
	void updateColor();

public:
	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 */
	static wyColorLayer* make(wyColor4B color = wyc4bTransparent);

	/**
	 * constructor
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 */
	wyColorLayer(wyColor4B color = wyc4bTransparent);

	virtual ~wyColorLayer();

	/// @see wyNode::isGeometry
	virtual bool isGeometry() { return true; }

	/// @see wyNode::updateMesh
	virtual void updateMesh();

	/// @see wyNode::updateMeshColor
	virtual void updateMeshColor();
};

#endif // __wyColorLayer_h__
