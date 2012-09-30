/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wySprite_h__
#define __wySprite_h__

#include "wyTextureNode.h"
#include "wyZwoptex.h"

/**
 * @class wySprite
 *
 * 图片对象的封装
 */
class WIENGINE_API wySprite : public wyTextureNode {
public:
	/**
	 * 构造\link wySprite wySprite对象指针\endlink
	 *
	 * @param tex \link wyTexture2D wyTexture2D对象指针\endlink
	 * @return \link wySprite wySprite对象指针\endlink
	 */
	static wySprite* make(wyTexture2D* tex);

	/**
	 * 构造\link wySprite wySprite对象指针\endlink
	 *
	 * @param tex \link wyTexture2D wyTexture2D对象指针\endlink
	 * @param texRect 贴图区域，单位为像素
	 * @return \link wySprite wySprite对象指针\endlink
	 */
	static wySprite* make(wyTexture2D* tex, wyRect texRect);

	/**
	 * 根据\link wyZwoptexFrame wyZwoptexFrame\endlink 构造一个sprite对象
	 *
	 * @param tex \link wyTexture2D wyTexture2D对象指针\endlink
	 * @param f \link wyZwoptexFrame wyZwoptexFrame\endlink 对象
	 * @return \link wySprite wySprite对象指针\endlink
	 */
	static wySprite* make(wyTexture2D* tex, wyZwoptexFrame* f);

	/**
	 * 构造函数
	 *
	 * @param tex \link wyTexture2D wyTexture2D对象指针\endlink
	 */
	wySprite(wyTexture2D* tex);

	/**
	 * 构造函数
	 *
	 * @param tex \link wyTexture2D wyTexture2D对象指针\endlink
	 * @param texRect 贴图区域，单位为像素
	 */
	wySprite(wyTexture2D* tex, wyRect texRect);

	/**
	 * 根据\link wyZwoptexFrame wyZwoptexFrame\endlink 构造一个sprite对象
	 *
	 * @param tex \link wyTexture2D wyTexture2D对象指针\endlink
	 * @param f \link wyZwoptexFrame wyZwoptexFrame\endlink 对象
	 */
	wySprite(wyTexture2D* tex, wyZwoptexFrame* f);

	/**
	 * 析构函数
	 */
	virtual ~wySprite();
};

#endif // __wySprite_h__
