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
#ifndef __wyCollisionDetector_h__
#define __wyCollisionDetector_h__

#include <Box2D/Box2D.h>
#include "wyHashSet.h"
#include "wyNode.h"

struct wyNodeHash;

/**
 * @struct wyBox2DCDResult
 *
 * \if English
 * Result of collision detection
 * \else
 * 碰撞检测的结果
 * \endif
 */
typedef struct BOX2D_API wyBox2DCDResult {
	/**
	 * \if English
	 * collision point count
	 * \else
	 * 碰撞点个数
	 * \endif
	 */
	int pointCount;

	/**
	 * \if English
	 * collision points, max is two and they are in world coordinates
	 * \else
	 * 碰撞点数组, 最多两个且用的是全局坐标
	 * \endif
	 */
	wyPoint points[2];

	/**
	 * \if English
	 * normal of collision, in world coordinate. It points from first node
	 * to second node.
	 * \else
	 * 碰撞方向, 以全局坐标表示. 总是从第一个节点指向第二个节点.
	 * \endif
	 */
	wyPoint normal;
} wyBox2DCDResult;

/**
 * @class wyBox2DCollisionDetector
 *
 * \if English
 * A collision detector based on Box2D collision detection utility but
 * no need to establish whole world. It encapsulates detailed implementation of
 * Box2D and exposes those features in \link wyNode wyNode\endlink structure.
 * \else
 * 一个基于Box2D的碰撞检测工具, 但是它并不需要去建立整个世界. 这个工具类隐藏Box2D的具体
 * 实现, 提供了一个基于节点架构的接口以方便使用
 * \endif
 */
class BOX2D_API wyBox2DCollisionDetector : public wyObject {
private:
	/**
	 * \if English
	 * mapping from node to shape
	 * \else
	 * 节点到形状的映射
	 * \endif
	 */
	wyHashSet* m_nodeShapes;

	/**
	 * \if English
	 * pixels of one meter
	 * \else
	 * 一米的像素数
	 * \endif
	 */
	float m_meterPixels;

private:
	static int nodeHashEquals(void* ptr, void* elt);
	static void* buildNodeHash(void* ptr, void* data);
	static bool releaseHash(void* elt, void* data);

	/**
	 * \if English
	 * Add a node to collision detector so that it will be managed
	 * and you can later call detection method for it. If you want to
	 * perform collision detection on a node, you must add it. Good
	 * news is this method is invoked internally
	 *
	 * @return hash entry of node
	 * \else
	 * 把一个节点添加到碰撞检测器, 使其被托管. 如果要对一个节点进行碰撞检测,
	 * 必须先添加这个节点. 不过这个方法是自动调用的.
	 *
	 * @return 节点的哈希项
	 * \endif
	 */
	wyNodeHash* addNode(wyNode* node);

	/**
	 * \if English
	 * according to current scale rate, convert pixel to meter
	 *
	 * @param pixel pixel
	 * @return meter
	 * \else
	 * 根据当前的放缩比例，把像素数转换成米数
	 *
	 * @param pixel 像素数
	 * @return 米数
	 * \endif
	 */
	float pixel2Meter(float pixel) { return pixel / m_meterPixels; }

	/**
	 * \if English
	 * according to current scale rate, convert meter to pixel
	 *
	 * @param meter mter
	 * @return pixel
	 * \else
	 * 根据当前的放缩比例, 把米数转换成像素数
	 *
	 * @param meter 米数
	 * @return 像素数
	 * \endif
	 */
	float meter2Pixel(float meter) { return meter * m_meterPixels; }

protected:
	wyBox2DCollisionDetector();

public:
	virtual ~wyBox2DCollisionDetector();
	static wyBox2DCollisionDetector* make();

	/**
	 * \if English
	 * Are two nodes collided each other?
	 *
	 * @param node1 first node
	 * @param node2 second node
	 * @param result returns result of collision, if NULL, no data written.
	 * 		If not collided, no data written also.
	 * @return true if they are collided
	 * \else
	 * 两个节点是否发生了碰撞
	 *
	 * @param node1 节点1
	 * @param node2 节点2
	 * @param result 用来返回碰撞的结果, 传入NULL表示不希望获得碰撞信息. 如果没有
	 * 		碰撞发生, 也不会写入信息
	 * @return true表示发生了碰撞
	 * \endif
	 */
	bool isCollided(wyNode* node1, wyNode* node2, wyBox2DCDResult* result);

	/**
	 * \if English
	 * Is node collided with a rectangle
	 *
	 * @param node node
	 * @param r rectangle, must in global coordinate
	 * @param result returns result of collision, if NULL, no data written.
	 * 		If not collided, no data written also.
	 * @return true if they are collided
	 * \else
	 * 判断一个节点是否和一个矩形发生了碰撞
	 *
	 * @param node 节点
	 * @param r 矩形, 必须是全局坐标
	 * @param result 用来返回碰撞的结果, 传入NULL表示不希望获得碰撞信息. 如果没有
	 * 		碰撞发生, 也不会写入信息
	 * @return true表示发生了碰撞
	 * \endif
	 */
	bool isCollided(wyNode* node, wyRect& r, wyBox2DCDResult* result);

	/**
	 * \if English
	 * Are two rectangle collided each other?
	 *
	 * @param r1 first rectangle, must in same coordinates as \c r2
	 * @param r2 second rectangle, must in same coordinates as \c r1
	 * @param result returns result of collision, if NULL, no data written.
	 * 		If not collided, no data written also.
	 * @return true if they are collided
	 * \else
	 * 两个矩形是否发生了碰撞
	 *
	 * @param r1 矩形1, 必须和\c r2在同一个坐标系中
	 * @param r2 矩形2, 必须和\c r1在同一个坐标系中
	 * @param result 用来返回碰撞的结果, 传入NULL表示不希望获得碰撞信息. 如果没有
	 * 		碰撞发生, 也不会写入信息
	 * @return true表示发生了碰撞
	 * \endif
	 */
	bool isCollided(wyRect& r1, wyRect& r2, wyBox2DCDResult* result);

	/**
	 * \if English
	 * Set polygon shape of a node
	 *
	 * @param node shape of node whose shape need to be defined
	 * @param points vertices of shape, must in counter-clockwise sequence and in
	 * 		WiEngine global coordinates.
	 * @param count point count in \c points
	 * \else
	 * 修改节点相关的多边形
	 *
	 * @param node 需要修改关联形状的节点对象
	 * @param points 多边形的点, 必须以逆时针顺序指定. 其值必须是WiEngine的全局坐标
	 * @param count \c points中的点数
	 * \endif
	 */
	void setNodeShape(wyNode* node, wyPoint* points, int count);

	/**
	 * \if English
	 * Set circle shape of a node
	 *
	 * @param node shape of node whose shape need to be defined
	 * @param radius radius of circle
	 * \else
	 * 修改节点的关联形状为圆形
	 *
	 * @param node 需要修改关联形状的节点对象
	 * @param radius 圆的半径, 单位为像素
	 * \endif
	 */
	void setNodeShape(wyNode* node, int radius);
};

#endif // __wyCollisionDetector_h__
