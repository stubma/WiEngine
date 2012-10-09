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
#ifndef __wySpriteFrame_h__
#define __wySpriteFrame_h__

#include "wyFrame.h"
#include "wyTypes.h"

class wyTexture2D;

/**
 * @class wySpriteFrame
 *
 * \if English
 * A frame which is related to a texture or part of texture
 * \else
 * 帧引用了某个贴图或者只是某个贴图的一部分
 * \endif
 */
class WIENGINE_API wySpriteFrame : public wyFrame {
private:
	/// 矩形
	wyRect m_rect;

	/// rectangle of opaque content in original image
	wyRect m_sourceColorRect;

	/// offset of opaque content in original image
	wyPoint m_offset;

	/// 原始大小
	wySize m_originalSize;

	/// true means image is clockwise rotated 90 degrees in atlas
	bool m_rotated;

	/// texture of this sprite, may be single texture or atlas texture
	wyTexture2D* m_texture;

protected:
	wySpriteFrame();

public:
	virtual ~wySpriteFrame();

	/**
	 * 通过贴图对象创建\link wySpriteFrame wySpriteFrame\endlink, 创建的
	 * 帧为整个贴图
	 *
	 * @param duration 持续时间
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @return \link wySpriteFrame wySpriteFrame\endlink
	 */
	static wySpriteFrame* make(float duration, wyTexture2D* tex);

	/**
	 * 通过矩形创建一个\link wySpriteFrame wySpriteFrame\endlink, 创建的帧的贴图应该属于某个
	 * 图片集
	 *
	 * @param duration 持续时间
	 * @param rect \link wyRect wyRect\endlink
	 * @return \link wySpriteFrame wySpriteFrame\endlink
	 */
	static wySpriteFrame* make(float duration, wyRect rect);

	/**
	 * 通过贴图对象创建\link wySpriteFrame wySpriteFrame\endlink, 并指定帧图片在
	 * 贴图中的范围
	 *
	 * @param duration 持续时间
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param rect \link wyRect wyRect\endlink
	 * @return \link wySpriteFrame wySpriteFrame\endlink
	 */
	static wySpriteFrame* make(float duration, wyTexture2D* tex, wyRect rect);

	/**
	 * 通过贴图对象创建\link wySpriteFrame wySpriteFrame\endlink, 并指定帧图片在
	 * 贴图中的范围, 以及帧的偏移位置和原始大小
	 *
	 * @param duration 持续时间
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param rect \link wyRect wyRect\endlink
	 * @param offset \link wyPoint wyPoint\endlink
	 * @param originalSize \link wySize wySize\endlink
	 * @return \link wySpriteFrame wySpriteFrame\endlink
	 */
	static wySpriteFrame* make(float duration, wyTexture2D* tex, wyRect rect, wyPoint offset, wySize originalSize);

	/**
	 * 通过贴图对象创建\link wySpriteFrame wySpriteFrame\endlink, 并指定帧图片在
	 * 贴图中的范围, 以及帧的偏移位置和原始大小
	 *
	 * @param duration 持续时间
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param rect \link wyRect wyRect\endlink
	 * @param offset \link wyPoint wyPoint\endlink
	 * @param originalSize \link wySize wySize\endlink
	 * @param rotated true表示图片在图片集中顺时针旋转了90度
	 * @return \link wySpriteFrame wySpriteFrame\endlink
	 */
	static wySpriteFrame* make(float duration, wyTexture2D* tex, wyRect rect, wyPoint offset, wySize originalSize, bool rotated);

	wyRect getRect() { return m_rect; }
	void setRect(wyRect r) { m_rect = r; }
	wyRect getSourceColorRect() { return m_sourceColorRect; }
	void setSourceColorRect(wyRect r) { m_sourceColorRect = r; }
	wyPoint getOffset() { return m_offset; }
	void setOffset(wyPoint p) { m_offset = p; }
	wySize getOriginalSize() { return m_originalSize; }
	void setOriginalSize(wySize s) { m_originalSize = s; }
	wyTexture2D* getTexture() { return m_texture; }
	void setTexture(wyTexture2D* tex);
	void setRotated(bool flag) { m_rotated = flag; }
	bool isRotated() { return m_rotated; }
};

#endif // __wySpriteFrame_h__
