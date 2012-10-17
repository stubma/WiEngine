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
#ifndef __wyNinePatchSprite_h__
#define __wyNinePatchSprite_h__

#include "wyNode.h"
#include "wyTypes.h"
#include "WiEngine-Classes.h"

/**
 * @class wyNinePatchSprite
 * \if English
 * wrapper class to support nine patch pictures like android .9 picture.
 *
 * Notice:
 * rotated atlas picture is not supported.
 * \else
 * 点9精灵图片对象. 可以对一个图片指定一个可缩放区域, 这样一个小图片可以被缩放
 * 为任意大小. 这类似于Android提供的.9图片格式, 不过并不支持不连续的缩放区域.
 *
 * 目前wyNinePatchSprite不支持旋转过的图片集图片, 即rotated属性为true的图片集
 * 图片尚不支持
 * \endif
 */
class WIENGINE_API wyNinePatchSprite : public wyNode {
private:
	/**
	 * \if English
	 * the texture rectangle area to be used, if not specified, the whole texture is used
	 * \else
	 * 所用贴图区域
	 * \endif
	 */
	wyRect m_texRect;

	/**
	 * \if English
	 * the rectangle area to be scaled, in texture coordinates, the upper left corner is regarded as original point
	 * \else
	 * 拉伸区域, 相对于图片坐标, 以图片左上角为原点
	 * \endif
	 */
	wyRect m_patchRect;

protected:
	/**
	 * \if English
	 * constructor
	 *
	 * @param tex \link wyTexture2D wyTexture2D object\endlink
	 * @param texRect the texture rectangle area to be used
	 * @param patchRect the rectangle area to be scaled， in texture coordinates, the upper left corner is regarded as original point
	 * \else
	 * 构造函数
	 *
	 * @param tex \link wyTexture2D wyTexture2D对象指针\endlink
	 * @param texRect 如果tex代表了一个图片集, 则可以通过\c texRect 指定图片集中的图片矩形
	 * @param patchRect 图片中被拉伸的矩形区域, 坐标相对于图片, 以图片的左上角为原点
	 * \endif
	 */
	wyNinePatchSprite(wyTexture2D* tex, wyRect texRect, wyRect patchRect);

	/**
	 * \if English
	 * do updating
	 * \else
	 * 更新atlas信息
	 * \endif
	 */
	void updateAtlas();

public:
	/**
	 * \if English
	 * create a new instance with autoRelease enabled
	 *
	 * @param tex \link wyTexture2D wyTexture2D object\endlink
	 * @param patchRect the rectangle area to be scaled， in texture coordinates, the upper left corner is regarded as original point
	 * \else
	 * 构造\link wyNinePatchSprite wyNinePatchSprite对象指针\endlink
	 *
	 * @param tex \link wyTexture2D wyTexture2D对象指针\endlink
	 * @param patchRect 图片中被拉伸的矩形区域, 坐标相对于图片, 以图片的左上角为原点
	 * @return \link wyNinePatchSprite wyNinePatchSprite对象指针\endlink
	 * \endif
	 */
	static wyNinePatchSprite* make(wyTexture2D* tex, wyRect patchRect);

	/**
	 * \if English
	 * create a new instance with autoRelease enabled
	 *
	 * @param tex \link wyTexture2D wyTexture2D object\endlink
	 * @param texRect the texture rectangle area to be used
	 * @param patchRect the rectangle area to be scaled， in texture coordinates, the upper left corner is regarded as original point
	 * \else
	 * 构造\link wyNinePatchSprite wyNinePatchSprite对象指针\endlink
	 *
	 * @param tex \link wyTexture2D wyTexture2D对象指针\endlink
	 * @param texRect 如果tex代表了一个图片集, 则可以通过\c texRect 指定图片集中的图片矩形
	 * @param patchRect 图片中被拉伸的矩形区域, 坐标相对于图片, 以图片的左上角为原点
	 * @return \link wyNinePatchSprite wyNinePatchSprite对象指针\endlink
	 * \endif
	 */
	static wyNinePatchSprite* make(wyTexture2D* tex, wyRect texRect, wyRect patchRect);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyNinePatchSprite();

	/// @see wyNode::isGeometry
	virtual bool isGeometry() { return true; }

	/// @see wyNode::updateMesh
	virtual void updateMesh();

	/// @see wyNode::updateMeshColor
	virtual void updateMeshColor();

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex, int index = 0);

	/**
	 * \if English
	 * set the texture rectangle and align the content size to rectangle size.
	 *
	 * @param[in] rect \link wyRect wyRect\endlink, in pixels, (rect.x, rect.y) is the left upper corner
	 * \else
	 * 指定所使用的贴图区域, 同时改变图片大小为当前贴图区域大小, 单位为像素.
	 * 贴图区域默认为整张图片,如需改变则调用此函数.
	 *
	 * @param[in] rect 矩形，(rect.x, rect.y)为左上角
	 * \endif
	 */
	void setTextureRect(wyRect rect);

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得当前所使用的贴图区域,单位为像素.
	 *
	 * @return 矩形，(rect.x, rect.y)为左上角
	 * \endif
	 */
	wyRect getTextureRect() { return m_texRect; }
};

#endif // __wyNinePatchSprite_h__
