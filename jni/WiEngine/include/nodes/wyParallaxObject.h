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
#ifndef __wyParallaxObject_h__
#define __wyParallaxObject_h__

#include "wyObject.h"

class wyNode;

/**
 * @class wyParallaxObject
 *
 * 视差对象, wyNode的子类可以实现createParallaxObject方法来创建
 * 自定义的视差对象
 */
class WIENGINE_API wyParallaxObject : public wyObject {
private:
	/// x axis scrolling ratio
	float m_ratioX;

	/// y axis scrolling ratio
	float m_ratioY;

	/// related node
	wyNode* m_node;

protected:
	/**
	 * 构造函数
	 */
	wyParallaxObject();

public:
	/**
	 * 静态构造函数
	 *
	 * @return \link wyParallaxObject wyParallaxObject\endlink
	 */
	static wyParallaxObject* make();

	virtual ~wyParallaxObject();

	/**
	 * 移动这个视差对象
	 *
	 * @param dx x方向移动量
	 * @param dy y方向移动量
	 */
	virtual void translate(float dx, float dy);

	float getRatioX() { return m_ratioX; }

	void setRatioX(float r) { m_ratioX = r; }

	float getRatioY() { return m_ratioY; }

	void setRatioY(float r) { m_ratioY = r; }

	wyNode* getNode() { return m_node; }

	void setNode(wyNode* node);
};

#endif // __wyParallaxObject_h__
