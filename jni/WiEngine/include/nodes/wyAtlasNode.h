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
#ifndef __wyAtlasNode_h__
#define __wyAtlasNode_h__

#include "wyNode.h"
#include "wyTextureAtlas.h"

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
	/**
	 * \if English
	 * \link wyTextureAtlas wyTextureAtlas\endlink
	 * \else
	 * 图片集\link wyTextureAtlas wyTextureAtlas对象指针\endlink
	 * \endif
	 */
    wyTextureAtlas* m_atlas;

    /**
     * \if English
     * sub sprite count of a row
     * \else
     * 标识每行有多少图片
     * \endif
     */
    int m_itemsPerRow;

    /**
     * \if English
     * sub sprite count of a column
     * \else
     * 标识每列有多少图片
     * \endif
     */
    int m_itemsPerColumn;

    /**
     * \if English
     * the value to be added to the texture coordinate when the tile moves one on the x axis
     * \else
     * 贴图坐标在x轴方向每前进一个tile需要增加的值
     * \endif
     */
    float m_texStepX;

    /**
     * \if English
     * the value to be added to the texture coordinate when the tile moves one on the y axis
     * \else
     * 贴图坐标在y轴方向每前进一个tile需要增加的值
     * \endif
     */
    float m_texStepY;

    /**
     * \if English
     * tile width of one, in pixels
     * \else
     * 每个分块图片的宽度
     * \endif
     */
    int m_itemWidth;

    /**
     * \if English
     * tile height of one, in pixels
     * \else
     * 每个分块图片的高度
     * \endif
     */
    int m_itemHeight;

    /**
     * \if Englsih
     * \link wyBlendFunc wyBlendFunc\endlink
     * \else
     * 渲染模式\link wyBlendFunc wyBlendFunc结构\endlink
     * \endif
     */
    wyBlendFunc m_blendFunc;

    /**
     * \if English
     * \link wyColor4B wyColor4B\endlink
     * \else
     * 颜色\link wyColor4B wyColor4B结构\endlink
     * \endif
     */
    wyColor4B m_color;

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

    /// @see wyNode::draw
    virtual void draw();

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
	virtual void setTexture(wyTexture2D* tex) { m_atlas->setTexture(tex); }

	/**
	 * \if English
	 * setter
	 *
	 * @param atlas \link wyTextureAtlas wyTextureAtlas\endlink
	 * \else
	 * 设置图片集\link wyTextureAtlas wyTextureAtlas对象指针\endlink
	 *
	 * @param atlas 图片集\link wyTextureAtlas wyTextureAtlas对象指针\endlink
	 * \endif
	 */
	void setAtlas(wyTextureAtlas* atlas);

	/**
	 * \if English
	 * getter
	 * \else
	 * 返回图片集\link wyTextureAtlas wyTextureAtlas对象指针\endlink
	 *
	 * @return 图片集\link wyTextureAtlas wyTextureAtlas对象指针\endlink
	 * \endif
	 */
	wyTextureAtlas* getAtlas() { return m_atlas; }
};

#endif // __wyAtlasNode_h__
