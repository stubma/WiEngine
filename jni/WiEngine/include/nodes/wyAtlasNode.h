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
#ifndef __wyAtlasNode_h__
#define __wyAtlasNode_h__

#include "wyNode.h"

/**
 * @class wyAtlasNode
 *
 * \if English
 * Base class of \link wyTileMapAtlas wyTileMapAtlas\endlink
 * \else
 * 图片集节点的封装,是图片集节点的基类
 * \endif
 */
class WIENGINE_API wyAtlasNode : public wyNode {
protected:
    /// sprite count of a row
    int m_itemsPerRow;

    /// sprite count of a column
    int m_itemsPerColumn;

    /// the value to be added to the texture coordinate when the tile moves on the x axis
    float m_texStepX;

    /// the value to be added to the texture coordinate when the tile moves on the y axis
    float m_texStepY;

    /// tile width in pixels
    int m_itemWidth;

    /// tile height in pixels
    int m_itemHeight;

protected:
    /**
     * \if English
     * to do initialization
     *
     * @param tex see \link wyTexture2D wyTexture2D\endlink
     * @param itemWidth tile width, in pixels
     * @param itemHeight tile height, in pixels
     * @param capacity for cache purpose, to specify how much tiles will be cached
     * \else
	 * 初始化
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param itemWidth 图片块的宽度
	 * @param itemHeight 图片块的高度
	 * @param capacity 缓存数
	 * \endif
	 */
    void init(wyTexture2D* tex, int itemWidth, int itemHeight, int capacity);

    /**
     * \if English
     * constructor
     * \else
	 * 构造函数
	 * \endif
	 */
    wyAtlasNode();

public:
    /**
     * \if English
     * factory function, used to create a new instance with autoRelease enabled
     *
     * @param tex see \link wyTexture2D wyTexture2D\endlink
     * @param itemWidth tile width, in pixels
     * @param itemHeight tile height, in pixels
     * @param capacity for cache purpose, to specify how much tiles will be cached
     * \else
	 * 静态构造函数
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param itemWidth 图片块的宽度
	 * @param itemHeight 图片块的高度
	 * @param capacity 缓存数
	 * \endif
	 */
    static wyAtlasNode* make(wyTexture2D* tex, int itemWidth, int itemHeight, int capacity);

    /**
     * \if English
     * constructor
     *
     * @param tex see \link wyTexture2D wyTexture2D\endlink
     * @param itemWidth tile width, in pixels
     * @param itemHeight tile height, in pixels
     * @param capacity for cache purpose, to specify how much tiles will be cached
     * \else
	 * 构造函数
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param itemWidth 图片块的宽度
	 * @param itemHeight 图片块的高度
	 * @param capacity 缓存数
	 * \endif
	 */
    wyAtlasNode(wyTexture2D* tex, int itemWidth, int itemHeight, int capacity);

    /**
     * \if English
     * destructor
     * \else
	 * 析构函数
	 * \endif
	 */
    virtual ~wyAtlasNode();

    /// @see wyNode::updateMaterial
    virtual void updateMaterial();

	/// @see wyNode::updateMeshColor
	virtual void updateMeshColor();
};

#endif // __wyAtlasNode_h__
