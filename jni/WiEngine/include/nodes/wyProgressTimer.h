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
#ifndef __wyProgressTimer_h__
#define __wyProgressTimer_h__

#include "wyNode.h"
#include "wySprite.h"
#include "wyGlobal.h"
#include "wyProgress.h"

/**
 * Progress timer node, can be bar style or radial style. The progress timer
 * has a percentage property which should be between 0 and 100. 
 *
 * \note
 * Progress timer support atlas texture but with one limitation: it doesn't support
 * border-trimmed texture. So, if you want to set atlas texture to progress timer, the
 * "trim" option in texture packing software should not be checked
 */
class WIENGINE_API wyProgressTimer : public wyNode {
protected:
	/// underlying sprite
	wySprite* m_sprite;

protected:
	/**
	 * Constructor
	 *
	 * @param sprite \link wySprite wySprite\endlink
	 */
	wyProgressTimer(wySprite* sprite);

public:
	/**
	 * 通过一个\link wyTexture2D wyTexture2D\endlink 对象构造一个
	 * 进度条，通过这种方式构造的进度条将使用这个贴图的完整大小.
	 *
	 * @param tex 贴图\link wyTexture2D wyTexture2D对象指针\endlink
	 */
	static wyProgressTimer* make(wyTexture2D* tex);

	/**
	 * 通过一个\link wySprite wySprite\endlink 构造一个进度条.
	 * 进度条可能只使用相关贴图的一部分，因为sprite也许是个图片集贴图。
	 *
	 * @param sprite \link wySprite wySprite\endlink 指针
	 */
	static wyProgressTimer* make(wySprite* sprite);

	virtual ~wyProgressTimer();

	/// @see wyNode::updateMesh
	virtual void updateMesh();

	/// @see wyNode::updateMeshColor
	virtual void updateMeshColor();

	/**
	 * Set percentage value, from 0 to 100
	 *
	 * @param percentage percentage, from 0 to 100
	 */
	void setPercentage(float percentage);

	/**
	 * Get current percentage, from 0 to 100
	 *
	 * @return percentage value, from 0 to 100
	 */
	float getPercentage() { return ((wyProgress*)getMesh())->getPercentage(); }

	/**
	 * Increase percentage by given \c delta. If new value is more than 100, it will be set to 100
	 *
	 * @param delta delta value added to percentage
	 */
	void increase(float delta);

	/**
	 * Set related sprite
	 *
	 * @param sprite \link wySprite wySprite\endlink
	 */
	void setSprite(wySprite* sprite);

	/**
	 * Set progress timer style
	 *
	 * @param style progress style, actually it is progress mesh style
	 */
	void setStyle(wyProgress::Style style);

	/**
	 * Get progress style
	 *
	 * @return mesh style
	 */
	wyProgress::Style getStyle() { return ((wyProgress*)getMesh())->getStyle(); }
};

#endif // __wyProgressTimer_h__
