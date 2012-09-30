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
#include "wyTextureAtlas.h"

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
	 * \link wyTextureAtlas wyTexturAtlas object\endlink
	 * \else
	 * 图片显示的\link wyTextureAtlas wyTextureAtlas对象指针\endlink
	 * \endif
	 */
    wyTextureAtlas* m_atlas;

    /**
     * \if English
     * specify the blending mode\link wyBlendFunc wyBlendFunc\endlink
     * else
     * 渲染模式\link wyBlendFunc wyBlendFunc结构\endlink
     * \endif
     */
    wyBlendFunc m_blendFunc;

    /**
     * \if English
     * color, \link wyColor4B wyColor4B\endlink
     * \else
     * 颜色\link wyColor4B wyColor4B结构\endlink
     * \endif
     */
	wyColor4B m_color;

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

	/**
	 * \if English
	 * flag to mark whether to need to do updating
	 * \else
	 * true表示需要更新渲染信息
	 * \endif
	 */
	bool m_dirty;

	/**
	 * \if English
	 * flag to mark whether to enable alpha blending, by default it is enabled
	 * \else
	 * 是否打开alpha blending, 缺省是打开的
	 * \endif
	 */
	bool m_blend;

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

	/// @see wyNode::draw
	virtual void draw();

	/// @see wyNode::setContentSize
	virtual void setContentSize(float w, float h);

	/// @see wyNode::getAlpha
	virtual int getAlpha() { return m_color.a; }

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha) { m_color.a = alpha; }

	/// @see wyNode::getColor
	virtual wyColor3B getColor();

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::setColor
	virtual void setColor(wyColor4B color);

	/// @see wyNode::getBlendFunc
	virtual wyBlendFunc getBlendFunc() { return m_blendFunc; }

	/// @see wyNode::setBlendFunc
	virtual void setBlendFunc(wyBlendFunc func) { m_blendFunc = func; }

	/// @see wyNode::getTexture
	virtual wyTexture2D* getTexture() { return m_atlas->getTexture(); }

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex);

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

	/**
	 * \if English
	 * get whether alpha blending is enabled
	 * \else
	 * 是否进行alpha渲染
	 *
	 * @return true表示打开alpha blending
	 * \endif
	 */
	bool isBlend() { return m_blend; }

	/**
	 * \if English
	 * set whether to enable alpha blending
	 *
	 * @param flag true means enable
	 * \else
	 * 是否打开alpha渲染, 对于不透明的大图片, 可以考虑关闭blend以提升性能
	 *
	 * @param flag true表示打开alpha渲染
	 * \endif
	 */
	void setBlend(bool flag) { m_blend = flag; }
};

#endif // __wyNinePatchSprite_h__
