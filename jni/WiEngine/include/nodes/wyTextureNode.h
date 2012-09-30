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
#ifndef __wyTextureNode_h__
#define __wyTextureNode_h__

#include "wyNode.h"
#include "wyTypes.h"
#include "wySpriteFrame.h"
#include "wyTexture2D.h"
#include "wyAnimation.h"
#include <stdbool.h>

/**
 * @class wyTextureNode
 *
 * 图片节点的封装. 如果一个贴图的大小和节点大小不符合，则贴图会被自动拉伸。在设置贴图时，
 * 节点大小会被设置成和贴图一样大，因此缺省情况下自动拉伸不会发生，如果需要（比如在设置
 * 一个背景图时），可以在设置贴图后再调用setContentSize修改节点大小，则可以起到拉伸
 * 贴图的效果。
 */
class WIENGINE_API wyTextureNode : public wyNode {
protected:
    /// 图片显示的\link wyTexture2D wyTexture2D对象指针\endlink
    wyTexture2D* m_tex;

    /// 原始的贴图对象，由于可以在节点上设置帧，所以对于原始的贴图需要保留一份引用以便动画结束时能够恢复
    wyTexture2D* m_originalTex;

    /// 渲染模式\link wyBlendFunc wyBlendFunc结构\endlink
    wyBlendFunc m_blendFunc;

	/// 颜色\link wyColor4B wyColor4B结构\endlink
	wyColor4B m_color;
    
    /// true表示原始的贴图数据已经被保存
    bool m_originSaved;

	/**
	 * 标识是否以X轴为转动轴翻转图片, 在wyTexture2D中，也有关于图片翻转的设置，
	 * 这里的设置和\link wyTexture2D wyTexture2D\endlink 的设置是互相独立的，这样可以保证一个
	 * \link wyTexture2D wyTexture2D\endlink 可以被多个wyTextureNode使用时可以渲染的不一样
	 */
	bool m_flipY;

	/**
	 * 标识是否以Y轴为转动轴翻转图片, 在wyTexture2D中，也有关于图片翻转的设置，
	 * 这里的设置和\link wyTexture2D wyTexture2D\endlink 的设置是互相独立的，这样可以保证一个
	 * \link wyTexture2D wyTexture2D\endlink 可以被多个wyTextureNode使用时可以渲染的不一样
	 */
	bool m_flipX;

	/// true表示图片来源于一个图片集，则图片集中的图片被顺时针旋转了90度
	bool m_rotatedZwoptex;

	/// 是否打开alpha blending, 缺省是打开的
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
	 * 标识是否抖动图片, 抖动可以消除某些颜色值丰富的图片显示时的渐变感
	 */
	bool m_dither;

	/**
	 * true表示渲染时，贴图会自动适配节点的大小。这样的话，如果贴图大小不等于
	 * 节点大小，则会起到贴图被拉伸的效果。缺省是false。
	 */
	bool m_autoFit;

	/// 当前图片帧的\link wySpriteFrame wySpriteFrame对象指针\endlink
	wySpriteFrame* m_currentFrame;

	/// animation map
	map<int, wyAnimation*>* m_animations;

	/// 所用贴图区域
	wyRect m_texRect;

	/// 图片左下顶点坐标
	wyPoint m_pointLeftBottom;

	/// 原始的贴图对象所用贴图区域, 以便动画结束时能够恢复原始图像
	wyRect m_originTexRect;

	/// 原始的贴图对象大小, 以便动画结束时能够恢复原始图像
	wySize m_originContentSize;

	/// 原始的贴图对象旋转标志, 以便动画结束时能够恢复原始图像
	bool m_originRotatedZwoptex;

	/// 原始的图片左下顶点坐标，以便动画结束时能够恢复原始图像
	wyPoint m_originPointLeftBottom;

private:
	static void releaseAnimation(int id, wyAnimation* anim);

public:
	/**
	 * 静态构造函数
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 */
	static wyTextureNode* make(wyTexture2D* tex = NULL);

	/**
	 * 构造函数
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 */
	wyTextureNode(wyTexture2D* tex = NULL);

	/**
	 * 析构函数
	 */
	virtual ~wyTextureNode();

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
	virtual wyTexture2D* getTexture() { return m_tex; }

	/**
	 * 设置贴图, 贴图设置后, 如果\c m_autoFit为true, 则不改变节点本身大小.
	 * 如果\c m_autoFit为false, 则将把节点大小修改为贴图大小
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 */
	virtual void setTexture(wyTexture2D* tex);

	/**
	 * 指定所使用的贴图区域, 同时改变图片大小为当前贴图区域大小, 单位为像素.
	 * 贴图区域默认为整张图片,如需改变则调用此函数.
	 *
	 * @param rect 矩形，(rect.x, rect.y)为左上角
	 */
	virtual void setTextureRect(wyRect rect);

	/**
	 * 获得当前所使用的贴图区域,单位为像素.
	 *
	 * @return 矩形，(rect.x, rect.y)为左上角
	 */
	wyRect getTextureRect() { return m_texRect; }

	/// @see wyNode::addAnimation(wyAnimation*)
	virtual void addAnimation(wyAnimation* anim);

	/// @see wyNode::getAnimationById(int)
	virtual wyAnimation* getAnimationById(int id);

	/// @see wyNode::getDisplayFrame
	virtual wyFrame* getDisplayFrame();

	/// @see wyNode::isFrameDisplayed
	virtual bool isFrameDisplayed(wyFrame* frame) { return m_currentFrame == frame; }

	/// @see wyNode::setDisplayFrame
	virtual void setDisplayFrame(wyFrame* newFrame);

	/// @see wyNode::setDisplayFrameById
	virtual void setDisplayFrameById(int id, int frameIndex);

	/**
	 * 设置是否以Y轴为转动轴翻转图片
	 *
	 * @param flipX true为翻转
	 */
	virtual void setFlipX(bool flipX) { m_flipX = flipX; }

	/**
	 * 获得是否以Y轴为转动轴翻转图片
	 *
	 * @return 是否以Y轴为转动轴翻转图片，true为翻转
	 */
	bool isFlipX() { return m_flipX; }

	/**
	 * 设置是否以X轴为转动轴翻转图片
	 *
	 * @param flipY true为翻转
	 */
	virtual void setFlipY(bool flipY) { m_flipY = flipY; }

	/**
	 * 获得是否以X轴为转动轴翻转图片
	 *
	 * @return 是否以X轴为转动轴翻转图片，true为翻转
	 */
	bool isFlipY() { return m_flipY; }

	/**
	 * 是否打开抖动
	 *
	 * @return true表示打开抖动, false表示不打开抖动
	 */
	bool isDither() { return m_dither; }

	/**
	 * 设置是否打开抖动
	 *
	 * @param flag true表示打开抖动, false表示不打开抖动
	 */
	void setDither(bool flag) { m_dither = flag; }

	/**
	 * 是否进行alpha渲染
	 *
	 * @return true表示打开alpha blending
	 */
	bool isBlend() { return m_blend; }

	/**
	 * 是否打开alpha渲染, 对于不透明的大图片, 可以考虑关闭blend以提升性能
	 *
	 * @param flag true表示打开alpha渲染
	 */
	void setBlend(bool flag) { m_blend = flag; }

	/**
	 * 设置图片来源是一个图片集，且被顺时针旋转了90度
	 *
	 * @param flag true表示图片来源是一个图片集，且被顺时针旋转了90度
	 */
	void setRotatedZwoptex(bool flag) { m_rotatedZwoptex = flag; }

	/**
	 * 是否图片来源是一个图片集，且被顺时针旋转了90度
	 *
	 * @return true表示图片来源是一个图片集，且被顺时针旋转了90度
	 */
	bool isRotatedZwoptex() { return m_rotatedZwoptex; }

	/**
	 * 设置是否自动拉伸贴图以便能匹配节点大小
	 *
	 * @param flag true表示自动拉伸贴图以便能匹配节点大小
	 */
	void setAutoFit(bool flag) { m_autoFit = flag; }

	/**
	 * 是否自动拉伸贴图以便能匹配节点大小
	 *
	 * @return true表示自动拉伸贴图以便能匹配节点大小
	 */
	bool isAutoFit() { return m_autoFit; }

	/**
	 * 将自身包装成一个\link wySpriteFrame wySpriteFrame\endlink, 生成的\link wySpriteFrame wySpriteFrame\endlink
	 * 的duration是0, 需要在返回后由开发者设置.
	 */
	wySpriteFrame* makeFrame();

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
};

#endif // __wyTextureNode_h__
