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
#ifndef __wyRectangle_h__
#define __wyRectangle_h__

#include "wyMesh.h"
#include "wyGlobal.h"
#include "wyTexture2D.h"

/**
 * @class wyRectangle
 *
 * \if English
 * Rectangle in 2D
 * \else
 * 2D的矩形网孔
 * \endif
 */
class WIENGINE_API wyRectangle : public wyMesh {
protected:
	wyRectangle();

public:
	/**
	 * \if English
	 * Create a nothing rectangle mesh
	 *
	 * @return \link wyRectangle wyRectangle\endlink
	 * \else
	 * 创建一个2d的矩形网格
	 *
	 * @return \link wyRectangle wyRectangle\endlink
	 * \endif
	 */
	static wyRectangle* make();

	virtual ~wyRectangle();

	/**
	 * \if English
	 * Update mesh data for a texture 2d object
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param x render x position
	 * @param y render y position
	 * @param width render width
	 * @param height render height
	 * @param sourceWidth original width of texture
	 * @param sourceHeight original height of texture
	 * @param flipX true means need flip texture in x axis
	 * @param flipY true means need flip texture in y axis
	 * @param texRect texture rect if \c tex is a atlas texture, or just tex rect
	 * @param rotate90 true means texture need to be rotated 90 degress counter-clockwise
	 * \else
	 * 根据一个贴图对象更新网格数据
	 *
	 * @param x x位置
	 * @param y y位置
	 * @param width 渲染宽度，单位像素
	 * @param height 渲染高度，单位像素
	 * @param sourceWidth 图片的原始宽度
	 * @param sourceHeight 图片的原始高度
	 * @param flipX true表示渲染时要在x方向翻转图片
	 * @param flipY true表示渲染时要在y方向翻转图片
	 * @param texRect 贴图区域
	 * @param rotate90 true表示贴图需要逆时针渲染90度
	 * \endif
	 */
	void updateForTexture(wyTexture2D* tex, float x, float y, float width, float height,
			float sourceWidth, float sourceHeight, bool flipX, bool flipY, wyRect texRect, bool rotate90);

	/**
	 * \if English
	 * Update color info
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 * \else
	 * 更新颜色信息
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 * \endif
	 */
	void updateColor(wyColor4B color);
};

#endif // __wyRectangle_h__
