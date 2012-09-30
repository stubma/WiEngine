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
#ifndef __wyRibbon_h__
#define __wyRibbon_h__

#include "wyNode.h"
#include "wyTextureAtlas.h"

/**
 * @class wyRibbon
 *
 * <p>Ribbon是一个动态多边形列表，在渲染时通过一系列三角形绘制出来，形成一个带状的效果。Ribbon
 * 主要的用途是和\link wyMotionStreak wyMotionStreak\endlink结合使用用来显示动作轨迹。wyRibbon
 * 只是一个抽象的接口定义，每个子类都可能有不同的渲染效果. \link wyMotionStreak wyMotionStreak\endlink
 * 中定义了setStyle方法可以让您设置不同的轨迹样式，\link wyMotionStreak wyMotionStreak\endlink会根据
 * 轨迹样式使用不同的wyRibbon子类</p>
 */
class WIENGINE_API wyRibbon : public wyNode {
protected:
	/// 上一次的点
    wyPoint m_lastLocation;

    /// 上上一次的点
    wyPoint m_preLastLocation;

    /// 当前剩余的未计算距离
    float m_remaining;

    /// 淡出时间
    float m_fadeTime;

    /// 下一个点是否是第一个点
    bool m_firstPoint;

    /// 渲染模式\link wyBlendFunc wyBlendFunc结构\endlink
    wyBlendFunc m_blendFunc;

protected:
    /**
	 * 构造函数
	 *
	 * @param fade 淡出时间, 传入0表示不淡出一直保持，直到用reset清除
	 */
    wyRibbon(float fade);

public:
    /**
	 * 析构函数
	 */
    virtual ~wyRibbon();

	/// @see wyNode::setContentSize
	virtual void setContentSize(float w, float h);

    /// @see wyNode::getBlendFunc
	virtual wyBlendFunc getBlendFunc() { return m_blendFunc; }

	/// @see wyNode::setBlendFunc
	virtual void setBlendFunc(wyBlendFunc func) { m_blendFunc = func; }

	/**
	 * 强制指定下一个新端点会产生一个新的RibbonSegment
	 */
	virtual void forceFirstPoint() { m_firstPoint = true; }

	/**
	 * 被Scheduler调用的方法，不要手动调用
	 *
	 * @param delta 帧刷新的间隔时间
	 */
	virtual void update(float delta) = 0;

	/**
	 * 添加一个新端点
	 *
	 * @param location 顶点\link wyPoint wyPoint对象指针\endlink
	 */
	virtual void addPoint(wyPoint location) = 0;

	/**
	 * 重置ribbon，清除当前的点，擦除所有绘制内容
	 */
	virtual void reset() = 0;
};

#endif // __wyRibbon_h__
