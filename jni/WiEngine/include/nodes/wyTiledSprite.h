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
#ifndef __wyTiledSprite_h__
#define __wyTiledSprite_h__

#include "wyNode.h"
#include "wyScroller.h"

class wyTiledSpriteParallaxObject;

/**
 * @class wyTiledSprite
 *
 * \par
 * 对一个贴图进行平铺, 可以用来做游戏背景。wyTiledSprite支持在水平和垂直方向进行贴图平铺，
 * 适合于构建平铺式背景。并且还提供了滚动和fling的方法，因此也适合于构建超大重复滚轴式背景。
 * wyTiledSprite的初始大小是和SurfaceView的大小一样.
 *
 * \par
 * 缺省情况下wyTiledSprite将在水平和垂直方向都平铺贴图，如果设置在两个方向上都不平铺，则
 * 贴图会居中显示。平铺的方向也会影响到滚动时的处理，如果只设置了水平平铺，则垂直方向上不会
 * 发生滚动，如果设置了垂直平铺，则水平方向上不会发生滚动，如果两个方向都设置了平铺，则两个
 * 方向都可以滚动。
 */
class WIENGINE_API wyTiledSprite : public wyNode {
	friend class wyTiledSpriteParallaxObject;

private:
	/**
	 * 如果这个贴图是一个图片集中的某帧，则可以设置矩形参数，缺省情况下
	 * 这个矩形是{0, 0, m_tex->getWidth(), m_tex->getHeight() }，即贴图
	 * 对象的有效区域大小
	 */
	wyRect m_rect;

	/// true表示进行垂直平铺，false表示垂直方向上将居中. 缺省是true
	bool m_tileVertical;

	/// true表示进行水平平铺，false表示水平方向上将居中. 缺省是true
	bool m_tileHorizontal;

	/// true表示在不平铺的方向上拉伸贴图
	bool m_stretch;

	/// 左边界(水平平铺时)的偏移值，为正时相当于把贴图向右移动，为负时相当于向左移动
	float m_offsetX;

	/// 上边界(垂直平铺时)的偏移值，为正时相当于把贴图向上移动，为负时相当于向下移动
	float m_offsetY;

	/// max offset in x axis, default is MAX_FLOAT
	float m_maxOffsetX;

	/// min offset in x axis, default is -MAX_FLOAT
	float m_minOffsetX;

	/// max offset in y axis, default is MAX_FLOAT
	float m_maxOffsetY;

	/// min offset in y axis, default is -MAX_FLOAT
	float m_minOffsetY;

	/// true表示当前正在fling
	bool m_flinging;

	/// \link wyScroller wyScroller 结构指针\endlink
	wyScroller* m_scroller;

    /// x方向平铺间隔
    float m_spacingX;

    /// y方向平铺间隔
    float m_spacingY;

private:
	/**
	 * 更新atlas中的四边形
	 */
	void updateQuads();

protected:
	/// update fling status
	void updateFling(wyTargetSelector* ts);

public:
	/**
	 * 静态构造函数。缺省情况下，wyTiledSprite节点和Surface一样大。
	 *
	 * @param tex 贴图对象，可以为NULL，之后可以通过setTexture再设置
	 */
	static wyTiledSprite* make(wyTexture2D* tex = NULL);

	/**
	 * 构造函数。缺省情况下，wyTiledSprite节点和Surface一样大。
	 *
	 * @param tex 贴图对象，可以为NULL，之后可以通过setTexture再设置
	 */
	wyTiledSprite(wyTexture2D* tex = NULL);

	/**
	 * 析构函数
	 */
	virtual ~wyTiledSprite();

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex, int index = 0);

	/// @see wyNode::updateMesh
	virtual void updateMesh();

	/// @see wyNode::updateMeshColor
	virtual void updateMeshColor();

	/**
	 * 得到是否垂直平铺标志
	 *
	 * @return true表示垂直方向进行平铺
	 */
	bool isTileVertical() { return m_tileVertical; }

	/**
	 * 得到是否水平平铺标志
	 *
	 * @return true表示水平方向进行平铺
	 */
	bool isTileHorizontal() { return m_tileHorizontal; }

	/**
	 * 设置平铺方向
	 *
	 * @param horizontal true表示水平方向进行平铺
	 * @param vertical true表示垂直方向进行平铺
	 */
	void setTileDirection(bool horizontal, bool vertical);

	/**
	 * 如果贴图代表了一个图片集，则可以设置要平铺的贴图在图片集中的矩形位置
	 *
	 * @param r 要平铺的贴图在图片集中的矩形位置，(x, y)代表贴图的左上角坐标
	 */
	void setTextureRect(wyRect r);

	/**
	 * 获得贴图的矩形，如果贴图是一个图片集，则这个方法可以获得实际绘制帧的矩形
	 *
	 * @return 贴图的矩形位置，对于图片集时有意义
	 */
	wyRect getTextureRect() { return m_rect; }

	/**
	 * 设置X方向的偏移量，为正时相当于把贴图向左移动，为负时相当于向右移动
	 *
	 * @param offset 偏移量
	 */
	void setOffsetX(float offset);

	/**
	 * 设置Y方向的偏移量，为正时相当于把贴图向上移动，为负时相当于向下移动
	 *
	 * @param offset 偏移量
	 */
	void setOffsetY(float offset);

	/**
	 * 调整偏移量
	 *
	 * @param dx X偏移量的调整值，会添加到现有偏移量上
	 * @param dy Y偏移量的调整值，会添加到现有偏移量上
	 */
	void offsetBy(float dx, float dy);

	/**
	 * 是否正在惯性移动中
	 *
	 * @return true表示正在惯性移动中
	 */
	bool isFlinging() { return m_flinging; }

	/**
	 * 设置最大的x方向偏移量
	 *
	 * @param max 最大x方向偏移量
	 */
	void setMaxOffsetX(float max) { m_maxOffsetX = MAX(0, max); }

	/**
	 * 得到最大x方向偏移量
	 *
	 * @return 最大x方向偏移量
	 */
	float getMaxOffsetX() { return m_maxOffsetX; }

	/**
	 * 设置最小的x方向偏移量
	 *
	 * @param min 最小x方向偏移量
	 */
	void setMinOffsetX(float min) { m_minOffsetX = MIN(0, min); }

	/**
	 * 得到最小x方向偏移量
	 *
	 * @return 最小x方向偏移量
	 */
	float getMinOffsetX() { return m_minOffsetX; }

	/**
	 * 设置最大的y方向偏移量
	 *
	 * @param max 最大y方向偏移量
	 */
	void setMaxOffsetY(float max) { m_maxOffsetY = MAX(0, max); }

	/**
	 * 得到最大y方向偏移量
	 *
	 * @return 最大y方向偏移量
	 */
	float getMaxOffsetY() { return m_maxOffsetY; }

	/**
	 * 设置最小的y方向偏移量
	 *
	 * @param min 最小y方向偏移量
	 */
	void setMinOffsetY(float min) { m_minOffsetY = MIN(0, min); }

	/**
	 * 得到最小y方向偏移量
	 *
	 * @return 最小y方向偏移量
	 */
	float getMinOffsetY() { return m_minOffsetY; }

	/**
	 * 中止fling，如果当前没有在fling，则不做任何事
	 */
	void stopFling();

	/**
	 * 开始fling, 如果当前正在fling，则不做任何事.
	 *
	 * @param velocityX x方向的fling速度, 如果没有设置水平平铺，则被忽略
	 * @param velocityY y方向的fling速度, 如果没有设置垂直平铺，则被忽略
	 */
	void fling(float velocityX, float velocityY);

	/// @see wyNode::createParallaxObject
	virtual wyParallaxObject* createParallaxObject();

	/**
	 * 设置是否在不平铺的方向上拉伸贴图, 比如贴图在水平方向上平铺, 垂直方向上不平铺,
	 * 则设置此标志为true可以让贴图在垂直方向上充满节点大小
	 *
	 * @param flag true表示在不平铺的方向上拉伸贴图
	 */
	void setStretch(bool flag);

	/**
	 * 是否在不平铺的方向上拉伸贴图
	 *
	 * @return true表示在不平铺的方向上拉伸贴图
	 */
	bool isStretch() { return m_stretch; }

	/**
	 * 设置平铺的间隔
	 *
	 * @param x 水平方向间隔, 如果没有设置在水平方向上平铺则不起作用
	 * @param y 垂直方向间隔, 如果没有设置在水平方向上平铺则不起作用
	 */
	void setSpacing(float x, float y);

	/**
	 * 得到水平方向平铺间隔
	 *
	 * @return 水平方向平铺间隔
	 */
	float getSpacingX() { return m_spacingX; }

	/**
	 * 得到垂直方向平铺间隔
	 *
	 * @return 垂直方向平铺间隔
	 */
	float getSpacingY() { return m_spacingY; }
};

#endif // __wyTiledSprite_h__
