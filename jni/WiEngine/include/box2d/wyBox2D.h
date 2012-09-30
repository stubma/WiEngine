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
#ifndef __wyBox2D_h__
#define __wyBox2D_h__

#include "wyNode.h"
#include "wyBox2DRender.h"
#include "wyFixtureAnimation.h"
#include <Box2D/Box2D.h>

class wyBox2DDebugDraw;

/**
 * @class wyBox2D
 *
 * \if English
 * encapsulation for box2d. wyBox2D is a node so you can add it to scene. every
 * wyBox2D contains a b2World.
 * \else
 * 对Box2D进行了一个节点形式的封装，wyBox2D是wyNode的子类，因此可以被添加到场景中。
 * 一个wyBox2D对应于一个b2World对象.
 * \endif
 */
class BOX2D_API wyBox2D : public wyNode {
private:
	/**
	 * \if English
	 * the world contained by wyBox2D node
	 * \else
	 * Box2D的World对象
	 * \endif
	 */
	b2World* m_world;

	/**
	 * \if English
	 * implementation of b2Draw, enabled when \c m_debugDraw set to true
	 * \else
	 * b2Draw实现, 仅用于debug draw模式
	 * \endif
	 */
	wyBox2DDebugDraw* m_ddImpl;

	/**
	 * \if English
	 * true indicating using debug render mode
	 * \else
	 * true表示使用debug draw模式渲染World
	 * \endif
	 */
	bool m_debugDraw;

	/**
	 * \if English
	 * render of non debug mode, supporting binding texture to a fixture. you can use it
	 * or do drawing yourself, it is mainly used for simple scenario and it is not good for
	 * complicated world.
	 * \else
	 * Box2D的非调试模式渲染器
	 * \endif
	 */
	wyBox2DRender* m_render;

public:
	static wyBox2D* make();
	wyBox2D();
	virtual ~wyBox2D();

	/// @see wyNode::draw
	virtual void draw();

	/**
	 * \if English
	 * get world object pointer, the world object is created when wyBox2D created
	 *
	 * @return b2World pointer
	 * \else
	 * 得到世界对象指针，世界对象在wyBox2D对象初始化时被创建
	 *
	 * @return b2World对象指针
	 * \endif
	 */
	b2World* getWorld() { return m_world; }

	/**
	 * \if English
	 * get flag of debug draw
	 *
	 * @return debug flag of debug draw, true means debug draw is enabled
	 * \else
	 * 得到是否是debug draw模式的标志
	 *
	 * @return debug draw模式的标志, true表示是debug draw模式
	 * \endif
	 */
	bool isDebugDraw() { return m_debugDraw; }

	/**
	 * \if English
	 * set using debug draw or not
	 *
	 * @param flag true means debug draw should be used
	 * \else
	 * 设置是否debug draw. Debug draw模式下使用简单的线条和色块渲染物体。
	 *
	 * @param flag true表示使用debug draw
	 * \endif
	 */
	void setDebugDraw(bool flag) { m_debugDraw = flag; }

	/**
	 * \if English
	 * according to current scale rate, convert pixel to meter
	 *
	 * @param pixel pixel
	 * @return meter
	 * \else
	 * 根据当前的box2d放缩比例，把像素数转换成米数
	 *
	 * @param pixel 像素数
	 * @return 米数
	 * \endif
	 */
	float pixel2Meter(float pixel);

	/**
	 * \if English
	 * according to current scale rate, convert meter to pixel
	 *
	 * @param meter mter
	 * @return pixel
	 * \else
	 * 根据当前的box2d放缩比例, 把米数转换成像素数
	 *
	 * @param meter 米数
	 * @return 像素数
	 * \endif
	 */
	float meter2Pixel(float meter);

	/**
	 * 得到1米对应的像素数
	 *
	 * @return 1米对应的像素数
	 */
	float getMeterPixels();

	/**
	 * \if English
	 * set how many pixels one meter stands for
	 *
	 * @param mp pixels for one meter
	 * \else
	 * 设置1米对应的像素数
	 *
	 * @param mp 1米对应的像素数
	 * \endif
	 */
	void setMeterPixels(float mp);

	/**
	 * \if English
	 * get b2Draw implementation pointer
	 *
	 * @return b2Draw implementation
	 * \else
	 * 得到b2Draw接口的实现类指针
	 *
	 * @return b2Draw接口的实现, 这个接口是由Box2D定义的
	 * \endif
	 */
	b2Draw* getDebugDrawImpl() { return (b2Draw*)m_ddImpl; }

	/**
	 * \if English
	 * set a custom box2d render, must be a subclass of wyBox2DRender
	 *
	 * @param render \link wyBox2DRender wyBox2DRender\endlink
	 * \else
	 * 设置使用缺省的Box2D渲染器
	 *
	 * @param render \link wyBox2DRender wyBox2DRender\endlink
	 * \endif
	 */
	void setBox2DRender(wyBox2DRender* render);

	/**
	 * \if English
	 * get current box2d render, or NULL if none
	 *
	 * @return \link wyBox2DRender wyBox2DRender\endlink
	 * \else
	 * 获得当前的Box2D渲染器, 如果没有设置，返回NULL
	 *
	 * @return \link wyBox2DRender wyBox2DRender\endlink
	 * \endif
	 */
	wyBox2DRender* getBox2DRender() { return m_render; }
};

#endif // __wyBox2D_h__
