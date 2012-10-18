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
#ifndef __wySpotRibbon_h__
#define __wySpotRibbon_h__

#include "wyRibbon.h"

/**
 * @class wySpotRibbon
 *
 * 绘制一个不连续的点状带。这里说的点其实就是一个完整的贴图，并不是指一个像素点。这个渲染
 * 的效果类似于愤怒小鸟中的那种轨迹效果。
 */
class WIENGINE_API wySpotRibbon : public wyRibbon {
private:
    /// 间隔距离，用于非连续模式, 缺省是20个dp
    float m_distance;

public:
    /**
	 * 静态构造函数
	 *
	 * @param tex 贴图\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param color 贴图渲染颜色
	 * @param fade 淡出时间, 传入0表示不淡出一直保持，直到用reset清除
	 */
    static wySpotRibbon* make(wyTexture2D* tex, wyColor4B color, float fade);

    /**
	 * 构造函数
	 *
	 * @param tex 贴图\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param color 贴图渲染颜色
	 * @param fade 淡出时间, 传入0表示不淡出一直保持，直到用reset清除
	 */
    wySpotRibbon(wyTexture2D* tex, wyColor4B color, float fade);

    /**
	 * 析构函数
	 */
    virtual ~wySpotRibbon();

	/// @see wyNode::updateMeshColor
	virtual void updateMeshColor();

	/**
	 * 被Scheduler调用的方法，不要手动调用
	 *
	 * @param delta 帧刷新的间隔时间
	 */
	virtual void update(float delta);

	/**
	 * 添加一个新端点
	 *
	 * @param location 顶点\link wyPoint wyPoint对象指针\endlink
	 */
	virtual void addPoint(wyPoint location);

	/**
	 * 重置ribbon，清除当前的点，擦除所有绘制内容
	 */
	virtual void reset();

	/**
	 * 设置渲染间隔，仅用于非连续渲染模式
	 *
	 * @param d 贴图渲染之间的间隔
	 */
	void setDistance(float d) { m_distance = d; }

	/**
	 * 得到渲染间隔，仅用于非连续渲染模式
	 *
	 * @return 渲染间隔
	 */
	float getDistance() { return m_distance; }
};

#endif // __wySpotRibbon_h__
