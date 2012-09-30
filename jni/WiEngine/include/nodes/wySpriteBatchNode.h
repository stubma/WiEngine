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
#ifndef __wySpirteBatchNode_h__
#define __wySpirteBatchNode_h__

#include "wyNode.h"
#include "wySpriteEx.h"

class wySpriteEx;
class wyMWSprite;

/**
 * @class wySpriteBatchNode
 *
 * \if English
 * Batch render sprite node, but it only accept \link wySpriteEx wySpriteEx\endlink as
 * child node.
 * \else
 * 用于图像节点的批处理，仅接受 \link wySpriteEx wySpriteEx\endlink作为子节点。
 * 所有子节点共享一张贴图，所有节点的绘制一次完成，可提高性能。
 * \endif
 */
class WIENGINE_API wySpriteBatchNode : public wyNode {
	friend class wySpriteEx;

protected:
	/**
	 * \if English
	 * underlying texture atlas object
	 * \else
	 * 底层的图片集对象
	 * \endif
	 */
	wyTextureAtlas* m_atlas;

	/**
	 * \if English
	 * blend function
	 * \else
	 * 渲染方式
	 * \endif
	 */
	wyBlendFunc	m_blendFunc;

	/// current color
	wyColor4B m_color;

	/**
	 * \if English
	 * enable dither or not, default is false
	 * \else
	 * 标识是否抖动图片, 抖动可以消除某些颜色值丰富的图片显示时的渐变感, 缺省是false
	 * \endif
	 */
	bool m_dither;

	/**
	 * \if English
	 * enable alpha blending or not, default is true
	 * \else
	 * 是否打开alpha blending, 缺省是true
	 * \endif
	 */
	bool m_blend;

	/**
	 * \if English
	 * enable alpha test or not
	 * \else
	 * true表示打开alpha测试, false表示不打开
	 * \endif
	 */
	bool m_alphaTest;

	/**
	 * \if English
	 * alpha function defined by OpenGL
	 * \else
	 * alpha测试方式, 由OpenGL定义
	 * \endif
	 */
	GLenum m_alphaFunc;

	/**
	 * \if English
	 * Alpha reference value, from 0 to 1
	 * \else
	 * alpha参考值, 从0到1
	 * \endif
	 */
	float m_alphaRef;

	/**
	 * \if English
	 * the start drawing position when using \c drawFromMarker
	 * \else
	 * 当调用drawFromMarker进行渲染时, \c m_marker表示从第几个四边形开始渲染
	 * \endif
	 */
	int m_marker;

protected:
	wySpriteBatchNode();

	/**
	 * \if English
	 * Add \link wySpriteEx wySpriteEx\endlink info to underlying atlas. Before this
	 * calling, sprite is already added as child node and assigned an atlas index. This
	 * method does nothing if atlas index is less than zero
	 *
	 * @param sprite \link wySpriteEx wySpriteEx\endlink
	 * \else
	 * 添加一个\link wySpriteEx wySpriteEx\endlink对象到atlas中, 在这个方法调用前,
	 * sprite对象已经是子节点, 并且已经被分配了一个atlas索引. 如果这个sprite对象的atlas
	 * 索引小于0, 则不做任何事
	 *
	 * @param sprite \link wySpriteEx wySpriteEx\endlink
	 * \endif
	 */
	void addSprite(wySpriteEx* sprite);

	/**
	 * \if English
	 * Remove info of a \link wySpriteEx wySpriteEx\endlink from atlas. It does nothing
	 * if atlas index is less than zero
	 *
	 * @param sprite \link wySpriteEx wySpriteEx\endlink
	 * \else
	 * 从atlas中去掉这个\link wySpriteEx wySpriteEx\endlink 对象, 如果这个sprite对象的atlas
	 * 索引小于0, 则不做任何事
	 *
	 * @param sprite \link wySpriteEx wySpriteEx\endlink
	 * \endif
	 */
	void removeSprite(wySpriteEx* sprite);

	/**
	 * \if English
	 * Remove all managed sprite
	 * \else
	 * 删除所有托管的精灵
	 * \endif
	 */
	void removeAllSprites();

	/**
	 * \if English
	 * initialization after constructor
	 * \else
	 * 初始化
	 * \endif
	 */
	void init();

	/**
	 * \if English
	 * Update transform matrices of children
	 * \else
	 * 更新子节点的转换矩阵
	 * \endif
	 */
	void updateChildrenTransform();

public:
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param tex texture related to this batch node
	 * @return \link wySpriteBatchNode wySpriteBatchNode\endlink
	 * \else
	 * 创建一个wySpriteBatchNode类型的节点
	 *
	 * @param tex 贴图
	 * @return \link wySpriteBatchNode wySpriteBatchNode\endlink
	 * \endif
	 */
	static wySpriteBatchNode* make(wyTexture2D* tex);

	/**
	 * \if English
	 * Constructor
	 *
	 * @param tex texture related to this batch node
	 * \else
	 * 创建一个wySpriteBatchNode类型的节点
	 *
	 * @param tex 贴图
	 * \endif
	 */
	wySpriteBatchNode(wyTexture2D* tex);
	
	virtual ~wySpriteBatchNode();

	/**
	 * \if English
	 * Get underlying atlas object
	 *
	 * @return \link wyTextureAtlas wyTextureAtlas\endlink
	 * \else
	 * 返回图片集对象
	 *
	 * @return \link wyTextureAtlas wyTextureAtlas\endlink
	 * \endif
	 */
	wyTextureAtlas* getTexAtlas() { return m_atlas; }

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex);

	/// @see wyNode::getTexture
	virtual wyTexture2D* getTexture();
	
	/// @see wyNode::draw()
	virtual void draw();
	
	/// @see wyNode::visit()
	virtual void visit();
	
	/// @see wyNode::addChild(wyNode*, int, int)
	virtual void addChild(wyNode* child, int z, int tag);
	
	/// @see wyNode::removeChild(wyNode*, bool)
	virtual void removeChild(wyNode* child, bool cleanup); 

	/// @see wyNode::reorderChild(wyNode*, int);
	virtual int reorderChild(wyNode* child, int z);

	/// @see wyNode::removeAllChildren
	virtual void removeAllChildren(bool cleanup);

	/// @see wyNode::getBlendFunc
	virtual wyBlendFunc getBlendFunc() { return m_blendFunc; }

	/// @see wyNode::setBlendFunc
	virtual void setBlendFunc(wyBlendFunc func) { m_blendFunc = func; }

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

	/**
	 * \if English
	 * Draw quads in a specified range
	 *
	 * @param start start position
	 * @param count max count to be drawn
	 * @return if drawing is performed, return true, otherwise false
	 * \else
	 * 只画一定范围内的四边形
	 *
	 * @param start 起始的Quad
	 * @param count 画的Quad的个数
	 * @return 如果渲染操作成功执行, 返回true, 否则返回false
	 * \endif
	 */
	bool drawRange(int start, int count);

	/**
	 * \if English
	 * Draw from current marker position. The marker position will move forward
	 * by drawn quads
	 *
	 * @param count max quads to be drawn
	 * \else
	 * 从当前标记位置出开始渲染, 渲染完成后标记位置会往前推进渲染的四边形个数
	 *
	 * @param count 最多渲染多少个四边形
	 * \endif
	 */
	void drawFromMarker(int count);

	/**
	 * \if English
	 * Is dither enabled or not?
	 *
	 * @return true means dither is enabled, or false if not
	 * \else
	 * 是否打开抖动
	 *
	 * @return true表示打开抖动, false表示不打开抖动
	 * \endif
	 */
	bool isDither() { return m_dither; }

	/**
	 * \if English
	 * Enable dither or not
	 *
	 * @param flag true means dither should be enabled
	 * \else
	 * 设置是否打开抖动
	 *
	 * @param flag true表示打开抖动, false表示不打开抖动
	 * \endif
	 */
	void setDither(bool flag) { m_dither = flag; }

	/**
	 * \if English
	 * Is alpha blending enabled or not?
	 *
	 * @return true means alpha blending is enabled
	 * \else
	 * 是否进行alpha渲染
	 *
	 * @return true表示打开alpha blending
	 * \endif
	 */
	bool isBlend() { return m_blend; }

	/**
	 * \if English
	 * Enable alpha blending or not. Default is true, but you can turn it off
	 * if image doesn't have alpha channel
	 *
	 * @param flag true means alpha blending should be turned on
	 * \else
	 * 是否打开alpha渲染, 对于不透明的大图片, 可以考虑关闭blend以提升性能
	 *
	 * @param flag true表示打开alpha渲染
	 * \endif
	 */
	void setBlend(bool flag) { m_blend = flag; }

	/**
	 * \if English
	 * Set alpha function. If alpha function is set to GL_ALWAYS, then
	 * alpha test is disabled
	 *
	 * @param func alpha test function
	 * @param ref alpha reference value
	 * \else
	 * 设置alpha比较方式. 如果把alpha比较方式设置为GL_ALWAYS, 则相当于
	 * 禁止alpha测试
	 *
	 * @param func alpha比较方式, 由OpenGL定义, 缺省是GL_ALWAYS
	 * @param ref alpha参考值
	 * \endif
	 */
	void setAlphaFunc(GLenum func, float ref);

	/**
	 * \if English
	 * Set marker position, it will affect \c drawFromMarker method
	 *
	 * @param pos position of marker
	 * \else
	 * 设置标记位置, 将会影响\c drawFromMarker方法
	 *
	 * @param pos 标记位置
	 * \endif
	 */
	void setMarker(int pos) { m_marker = pos; }

	/**
	 * \if English
	 * Get current marker position
	 *
	 * @return current marker position
	 * \else
	 * 得到当前的标记位置
	 *
	 * @return 当前标记位置
	 * \endif
	 */
	int getMarker() { return m_marker; }
};

#endif
