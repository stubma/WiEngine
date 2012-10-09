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
#ifndef __wyBox2DRender_h__
#define __wyBox2DRender_h__

#include "wyObject.h"
#include "wyHashSet.h"
#include "wyTexture2D.h"
#include "wyTypes.h"
#include <Box2D/Dynamics/b2World.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Dynamics/b2Body.h>

class wyBox2D;

/**
 * @class wyBox2DRender
 *
 * \if English
 * Renderer of box2d. It can bind texture to fixture and render it. This is a simple
 * way but not a high performance way.
 * \else
 * Box2D的渲染器, 通过这个类可以为物体绑定贴图, 绑定的贴图将被这个渲染器所渲染. 这是一种较为
 * 省事的方式, 但性能并不好.
 * \endif
 */
class BOX2D_API wyBox2DRender : public wyObject, public b2DestructionListener {
private:
	/**
	 * \if English
	 * texture mapping of fixture
	 * \else
	 * 保存物体和贴图之间的映射关系
	 * \endif
	 */
	wyHashSet* m_texMap;

private:
	static int hashEquals(void* ptr, void* elt);
	static void* hashTrans(void* ptr, void* data);
	static bool releaseHash(void* elt, void* data);

public:
	wyBox2DRender();
	virtual ~wyBox2DRender();

	/**
	 * \if English
	 * bind a texture to fixture
	 *
	 * @param f b2Fixture object
	 * @param tex \link wyTexture2D wyTexture2D\endlink, or NULL to cancel binding
	 * \else
	 * 给某个fixture绑定一个贴图
	 *
	 * @param f b2Fixture对象
	 * @param tex \link wyTexture2D wyTexture2D\endlink, 如果为NULL， 则是取消之前的绑定
	 * \endif
	 */
	void bindTexture(b2Fixture* f, wyTexture2D* tex);

	/**
	 * \if English
	 * bind a atlas texture to fixture
	 *
	 * @param f b2Fixture object
	 * @param tex \link wyTexture2D wyTexture2D\endlink, or NULL to cancel binding
	 * @param rect \link wyRect wyRect\endlink, the texture rectangle in atlas
	 * \else
	 * 给某个fixture绑定一个图片集中的区域
	 *
	 * @param f b2Fixture对象
	 * @param tex \link wyTexture2D wyTexture2D\endlink, 如果为NULL， 则是取消之前的绑定
	 * @param rect 贴图在图片集中的矩形
	 * \endif
	 */
	void bindTexture(b2Fixture* f, wyTexture2D* tex, wyRect rect);

	/**
	 * \if English
	 * draw the entire world
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * \else
	 * 渲染世界
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * \endif
	 */
	virtual void drawWorld(wyBox2D* box2d);

	/**
	 * \if English
	 * draw a single shape, it is called by drawWorld to draw every shape. In non debug mode,
	 * only fixture which has texture bound will be drawn
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * @param fixture Box2D b2Fixture object
	 * @param body Box2D b2Body object
	 * \else
	 * 渲染一个形状, 这个方法会被drawWorld调用去绘制每个形状. 缺省情况下，
	 * 如果一个形状和一个贴图有绑定，则会被渲染，否则不会被渲染。
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * @param fixture Box2D的b2Fixture对象
	 * @param body Box2D的刚体对象
	 * \endif
	 */
	virtual void drawShape(wyBox2D* box2d, b2Fixture* fixture, b2Body* body);

	/**
	 * \if English
	 * draw a circle shape, called by drawShape
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * @param fixture Box2D b2Fixture object
	 * @param body Box2D b2Body object
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param rect texture rectangle in atlas
	 * \else
	 * 画一个有贴图绑定的圆形, 这个方法被drawShape调用
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * @param fixture Box2D的b2Fixture对象
	 * @param body Box2D的刚体对象
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param rect \link wyRect wyRect\endlink
	 * \endif
	 */
	virtual void drawCircle(wyBox2D* box2d, b2Fixture* fixture, b2Body* body, wyTexture2D* tex, wyRect rect);

	/**
	 * \if English
	 * draw a edge shape, called by drawShape
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * @param fixture Box2D b2Fixture object
	 * @param body Box2D b2Body object
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param rect texture rectangle in atlas
	 * \else
	 * 画一个有贴图绑定的线段, 这个方法被drawShape调用
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * @param fixture Box2D的b2Fixture对象
	 * @param body Box2D的刚体对象
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param rect \link wyRect wyRect\endlink
	 * \endif
	 */
	virtual void drawEdge(wyBox2D* box2d, b2Fixture* fixture, b2Body* body, wyTexture2D* tex, wyRect rect);

	/**
	 * \if English
	 * draw a loop shape, called by drawShape
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * @param fixture Box2D b2Fixture object
	 * @param body Box2D b2Body object
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param rect texture rectangle in atlas
	 * \else
	 * 画一个有贴图绑定的闭合线段形状, 这个方法被drawShape调用
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * @param fixture Box2D的b2Fixture对象
	 * @param body Box2D的刚体对象
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param rect \link wyRect wyRect\endlink
	 * \endif
	 */
	virtual void drawChain(wyBox2D* box2d, b2Fixture* fixture, b2Body* body, wyTexture2D* tex, wyRect rect);

	/**
	 * \if English
	 * draw a polygon shape, called by drawShape
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * @param fixture Box2D b2Fixture object
	 * @param body Box2D b2Body object
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param rect texture rectangle in atlas
	 * \else
	 * 画一个有贴图绑定的多边形, 这个方法被drawShape调用
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * @param fixture Box2D的b2Fixture对象
	 * @param body Box2D的刚体对象
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param rect \link wyRect wyRect\endlink
	 * \endif
	 */
	virtual void drawPolygon(wyBox2D* box2d, b2Fixture* fixture, b2Body* body, wyTexture2D* tex, wyRect rect);

	/**
	 * \if English
	 * Called when any joint is about to be destroyed due
	 * to the destruction of one of its attached bodies.
	 *
	 * @param joint b2Joint to be destroyed
	 * \else
	 * 一个b2Joint对象被销毁时被调用，这是b2DestructionListener的实现
	 *
	 * @param joint 被销毁的b2Joint
	 * \endif
	 */
	virtual void SayGoodbye(b2Joint* joint) {}

	/**
	 * \if English
	 * Called when any fixture is about to be destroyed due
	 * to the destruction of its parent body.
	 *
	 * @param fixture b2Fixture to be destroyed
	 * \else
	 * 一个b2Fixture对象被销毁时被调用，这是b2DestructionListener的实现
	 *
	 * @param fixture 被销毁的b2Fixture
	 * \endif
	 */
	virtual void SayGoodbye(b2Fixture* fixture) { bindTexture(fixture, NULL); }
};

#endif // __wyBox2DRender_h__
