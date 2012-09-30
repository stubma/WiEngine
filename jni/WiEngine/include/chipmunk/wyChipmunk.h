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
#ifndef __wyChipmunk_h__
#define __wyChipmunk_h__

#include "wyNode.h"
#include "chipmunk.h"
#include "chipmunk_unsafe.h"
#include "drawSpace.h"
#include "wyShapeAnimation.h"

/**
 * @class wyChipmunk
 *
 * \if English
 * encapsulate chipmunk as a node so that it can be added into scene. Every
 * wyChipmunk contains a cpSpace
 * \else
 * 封装Chipmunk的根元素, 它是一个\link wyNode wyNode\endlink 的子类, 因此可以被
 * 添加到场景中. 每个wyChipmunk类包含一个cpSpace结构.
 * \endif
 */
class CHIPMUNK_API wyChipmunk : public wyNode {
private:
	/**
	 * \if English
	 * chipmunk space object
	 * \else
	 * chipmunk的space对象
	 * \endif
	 */
	cpSpace* m_space;

	/**
	 * \if English
	 * debug drawing option
	 * \else
	 * 调试渲染模式的选项
	 * \endif
	 */
	drawSpaceOptions m_options;

public:
	static wyChipmunk* make();
	wyChipmunk();
	virtual ~wyChipmunk();

	static void applyDampedSpring(cpBody* a, cpBody* b, wyPoint anchor1, wyPoint anchor2, float rlen, float k, float dmp, float dt);

	/// @see wyNode::draw
	virtual void draw();

	/**
	 * \if English
	 * enable debug drawing mode or not
	 *
	 * @param debugDraw true indicating enable debug draw
	 * \else
	 * 设置是否使用调试渲染模式
	 *
	 * @param debugDraw true表示使用调试渲染模式
	 * \endif
	 */
	void setDebugDraw(bool debugDraw) { m_options.debugDraw = debugDraw ? 1 : 0; }

	/**
	 * \if English
	 * is in debug drawing mode?
	 *
	 * @return true indicating debug draw is enabled
	 * \else
	 * 是否使用调试渲染模式
	 *
	 * @return true表示使用调试渲染模式
	 * \endif
	 */
	bool isDebugDraw() { return m_options.debugDraw == 1; }

	/**
	 * \if English
	 * get chipmunk space structure
	 *
	 * @return chipmunk cpSpace object
	 * \else
	 * 得到cpSpace结构
	 *
	 * @return chipmunk的cpSpace结构
	 * \endif
	 */
	cpSpace* getSpace() { return m_space; }
};

#endif // __wyChipmunk_h__
