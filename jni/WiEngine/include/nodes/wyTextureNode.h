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
#ifndef __wyTextureNode_h__
#define __wyTextureNode_h__

#include "wyNode.h"
#include "wyTypes.h"
#include "wySpriteFrame.h"
#include "wyTexture2D.h"
#include "wyAnimation.h"
#include <stdbool.h>
#include "wyMesh.h"

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
    /// texture reference backup, used to restore texture
    wyTexture2D* m_originalTex;
    
    /// true means texture info is saved
    bool m_originSaved;

	/**
	 * true表示渲染时，贴图会自动适配节点的大小。这样的话，如果贴图大小不等于
	 * 节点大小，则会起到贴图被拉伸的效果。缺省是false。
	 */
	bool m_autoFit;

	/// current frame object
	wySpriteFrame* m_currentFrame;

	/// animation map
	map<int, wyAnimation*>* m_animations;

	/// original texture rectangle saved
	wyRect m_originTexRect;

	/// original node content size saved
	wySize m_originContentSize;

	/// orginal rotate flag saved
	bool m_originRotatedZwoptex;

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

	virtual ~wyTextureNode();

	/// @see wyGeometry::updateMesh
	virtual void updateMesh();

	/// @see wyGeometry::updateMeshColor
	virtual void updateMeshColor();

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex, int index = 0);

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
	wyRect getTextureRect() { return getMesh()->getTextureRect(); }

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

	/// set render offset of this texture
	virtual void setRenderOffset(wyPoint p);

	/**
	 * 设置是否以Y轴为转动轴翻转图片
	 *
	 * @param flipX true为翻转
	 */
	virtual void setFlipX(bool flipX) { getMesh()->setFlipX(flipX); }

	/**
	 * 获得是否以Y轴为转动轴翻转图片
	 *
	 * @return 是否以Y轴为转动轴翻转图片，true为翻转
	 */
	bool isFlipX() { return getMesh()->isFlipX(); }

	/**
	 * 设置是否以X轴为转动轴翻转图片
	 *
	 * @param flipY true为翻转
	 */
	virtual void setFlipY(bool flipY) { getMesh()->setFlipY(flipY); }

	/**
	 * 获得是否以X轴为转动轴翻转图片
	 *
	 * @return 是否以X轴为转动轴翻转图片，true为翻转
	 */
	bool isFlipY() { return getMesh()->isFlipY(); }

	/**
	 * 设置图片来源是一个图片集，且被顺时针旋转了90度
	 *
	 * @param flag true表示图片来源是一个图片集，且被顺时针旋转了90度
	 */
	void setRotatedZwoptex(bool flag) { getMesh()->setRotate90CCW(flag); }

	/**
	 * 是否图片来源是一个图片集，且被顺时针旋转了90度
	 *
	 * @return true表示图片来源是一个图片集，且被顺时针旋转了90度
	 */
	bool isRotatedZwoptex() { return getMesh()->isRotate90CCW(); }

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
	 * Set alpha function. If alpha function is set to GL_ALWAYS, then
	 * alpha test is disabled
	 *
	 * @param func alpha test function
	 * @param ref alpha reference value
	 */
	void setAlphaFunc(GLenum func, float ref);
};

#endif // __wyTextureNode_h__
