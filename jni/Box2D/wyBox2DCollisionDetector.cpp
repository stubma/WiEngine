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
#include "wyBox2DCollisionDetector.h"
#include <Box2D/Box2D.h>
#include "wyTypes.h"
#include "wyUtils.h"

// reversed for rectangle collision detection
static b2PolygonShape sRectPoly1;
static b2PolygonShape sRectPoly2;
static b2Transform sRectTrans1;
static b2Transform sRectTrans2;

/**
 * @struct wyNodeHash
 *
 * \if English
 * hash for node shape entry
 * \else
 * 节点到形状的映射哈希项
 * \endif
 */
typedef struct wyNodeHash {
	/**
	 * \if English
	 * node object, collision detector doesn't retain it
	 * \else
	 * 节点对象, 碰撞检测器并不增加节点的引用
	 * \endif
	 */
	wyNode* node;

	/**
	 * \if English
	 * shape type of this node
	 * \else
	 * 节点关联的形状类型
	 * \endif
	 */
	b2Shape::Type type;

	/**
	 * \if English
	 * related polygon shape of node
	 * \else
	 * 这个节点的多边形形状定义, 缺省情况下就是个矩形, 但是可以设置自定义的顶点
	 * \endif
	 */
	b2PolygonShape poly;

	/**
	 * \if English
	 * related circle shape of node
	 * \else
	 * 这个节点的圆形形状定义
	 * \endif
	 */
	b2CircleShape circle;

	/*
	 * \if English
	 * transform of shape
	 * \else
	 * 节点自身的旋转, 位置等变换信息
	 * \endif
	 */
	b2Transform transform;
} wyNodeHash;

wyBox2DCollisionDetector::wyBox2DCollisionDetector() :
		m_nodeShapes(wyHashSetNew(10, nodeHashEquals, buildNodeHash)),
		m_meterPixels(DP(16)) {
}

wyBox2DCollisionDetector::~wyBox2DCollisionDetector() {
	wyHashSetFilter(m_nodeShapes, releaseHash, NULL);
	wyHashSetDestroy(m_nodeShapes);
}

wyBox2DCollisionDetector* wyBox2DCollisionDetector::make() {
	wyBox2DCollisionDetector* d = WYNEW wyBox2DCollisionDetector();
	return (wyBox2DCollisionDetector*)d->autoRelease();
}

int wyBox2DCollisionDetector::nodeHashEquals(void* ptr, void* elt) {
	wyNodeHash* hash = (wyNodeHash*)elt;
	return hash->node == ptr;
}

void* wyBox2DCollisionDetector::buildNodeHash(void* ptr, void* data) {
	return data;
}

bool wyBox2DCollisionDetector::releaseHash(void* elt, void* data) {
	wyFree(elt);
	return false;
}

wyNodeHash* wyBox2DCollisionDetector::addNode(wyNode* node) {
	// create hash
	wyNodeHash* hash = (wyNodeHash*)wyCalloc(1, sizeof(wyNodeHash));

	// save node reference
	hash->node = node;

	// set shape size
	hash->poly.SetAsBox(pixel2Meter(node->getWidth()) / 2, pixel2Meter(node->getHeight()) / 2);
	hash->type = b2Shape::e_polygon;

	// set transform
	wyPoint pos = node->nodeToWorldSpace(wyp(node->getWidth() / 2, node->getHeight() / 2));
	b2Vec2 v;
	v.x = pixel2Meter(pos.x);
	v.y = pixel2Meter(pos.y);
	float angle = -wyMath::d2r(node->getRotation());
	hash->transform.Set(v, angle);

	// put to hash set
	wyHashSetInsert(m_nodeShapes, (size_t)node, node, hash);

	return hash;
}

void wyBox2DCollisionDetector::setNodeShape(wyNode* node, wyPoint* points, int count) {
	// get node hash, if not, add it
	wyNodeHash* hash = (wyNodeHash*)wyHashSetFind(m_nodeShapes, (size_t)node, node);
	if(hash == NULL)
		hash = addNode(node);

	// set polygon vertices
	b2Vec2* buf = (b2Vec2*)wyMalloc(count * sizeof(b2Vec2));
	b2Vec2* v = buf;
	for(int i = 0; i < count; i++, v++, points++) {
		v->x = pixel2Meter(points->x);
		v->y = pixel2Meter(points->y);
	}

	// set
	hash->type = b2Shape::e_polygon;
	hash->poly.Set(buf, count);
}

void wyBox2DCollisionDetector::setNodeShape(wyNode* node, int radius) {
	// get node hash, if not, add it
	wyNodeHash* hash = (wyNodeHash*)wyHashSetFind(m_nodeShapes, (size_t)node, node);
	if(hash == NULL)
		hash = addNode(node);

	// set radius
	hash->type = b2Shape::e_circle;
	hash->circle.m_radius = pixel2Meter(radius);
}

bool wyBox2DCollisionDetector::isCollided(wyNode* node1, wyNode* node2, wyBox2DCDResult* result) {
	// get node hash, if not, add it
	wyNodeHash* hash1 = (wyNodeHash*)wyHashSetFind(m_nodeShapes, (size_t)node1, node1);
	wyNodeHash* hash2 = (wyNodeHash*)wyHashSetFind(m_nodeShapes, (size_t)node2, node2);
	if(hash1 == NULL)
		hash1 = addNode(node1);
	if(hash2 == NULL)
		hash2 = addNode(node2);
	
	// update node1 transform
	wyPoint pos = node1->nodeToWorldSpace(wyp(node1->getWidth() / 2, node1->getHeight() / 2));
	b2Vec2 v;
	v.x = pixel2Meter(pos.x);
	v.y = pixel2Meter(pos.y);
	float angle = -wyMath::d2r(node1->getRotation());
	hash1->transform.Set(v, angle);
	
	// update node2 transform
	pos = node2->nodeToWorldSpace(wyp(node2->getWidth() / 2, node2->getHeight() / 2));
	v.x = pixel2Meter(pos.x);
	v.y = pixel2Meter(pos.y);
	angle = -wyMath::d2r(node2->getRotation());
	hash2->transform.Set(v, angle);

	// collision detection
	bool reverseNormal = false;
	b2Manifold manifold;
	switch(hash1->type) {
		case b2Shape::e_polygon:
			switch(hash2->type) {
				case b2Shape::e_polygon:
					b2CollidePolygons(&manifold, &hash1->poly, hash1->transform, &hash2->poly, hash2->transform);
					break;
				case b2Shape::e_circle:
					b2CollidePolygonAndCircle(&manifold, &hash1->poly, hash1->transform, &hash2->circle, hash2->transform);
					break;
			}
			break;
		case b2Shape::e_circle:
			switch(hash2->type) {
				case b2Shape::e_polygon:
					b2CollidePolygonAndCircle(&manifold, &hash2->poly, hash2->transform, &hash1->circle, hash1->transform);
					reverseNormal = true;
					break;
				case b2Shape::e_circle:
					b2CollideCircles(&manifold, &hash1->circle, hash1->transform, &hash2->circle, hash2->transform);
					break;
			}
			break;
	}

	// to world coordinates
	if(manifold.pointCount > 0) {
		// write data back
		if(result) {
			// convert to world coordinate
			b2WorldManifold worldManifold;
			if(reverseNormal) {
				worldManifold.Initialize(&manifold,
										 hash2->transform,
										 hash2->type == b2Shape::e_polygon ? hash2->poly.m_radius : hash2->circle.m_radius,
										 hash1->transform,
										 hash1->type == b2Shape::e_polygon ? hash1->poly.m_radius : hash1->circle.m_radius);
			} else {
				worldManifold.Initialize(&manifold,
										 hash1->transform,
										 hash1->type == b2Shape::e_polygon ? hash1->poly.m_radius : hash1->circle.m_radius,
										 hash2->transform,
										 hash2->type == b2Shape::e_polygon ? hash2->poly.m_radius : hash2->circle.m_radius);
			}

			// save contact points
			result->pointCount = manifold.pointCount;
			for(int i = 0; i < manifold.pointCount; i++) {
				result->points[i] = wyp(meter2Pixel(worldManifold.points[i].x), meter2Pixel(worldManifold.points[i].y));
			}
			
			// save normal
			if(reverseNormal)
				result->normal = wyp(-worldManifold.normal.x, -worldManifold.normal.y);
			else
				result->normal = wyp(worldManifold.normal.x, worldManifold.normal.y);
		}	
	}

	return manifold.pointCount > 0;
}

bool wyBox2DCollisionDetector::isCollided(wyNode* node, wyRect& r, wyBox2DCDResult* result) {
	// init transform 2
	sRectTrans2.SetIdentity();
	b2Vec2 v;
	v.x = pixel2Meter(r.x + r.width / 2);
	v.y = pixel2Meter(r.y + r.height / 2);
	sRectTrans2.Set(v, 0);

	// init shape 2
	sRectPoly2.SetAsBox(pixel2Meter(r.width) / 2, pixel2Meter(r.height) / 2);

	// get node hash, if not, add it
	wyNodeHash* hash = (wyNodeHash*)wyHashSetFind(m_nodeShapes, (size_t)node, node);
	if(hash == NULL)
		hash = addNode(node);

	// update node1 transform
	wyPoint pos = node->nodeToWorldSpace(wyp(node->getWidth() / 2, node->getHeight() / 2));
	v.x = pixel2Meter(pos.x);
	v.y = pixel2Meter(pos.y);
	float angle = -wyMath::d2r(node->getRotation());
	hash->transform.Set(v, angle);

	// collision detection
	bool reverseNormal = false;
	b2Manifold manifold;
	switch(hash->type) {
		case b2Shape::e_polygon:
			b2CollidePolygons(&manifold, &hash->poly, hash->transform, &sRectPoly2, sRectTrans2);
			break;
		case b2Shape::e_circle:
			b2CollidePolygonAndCircle(&manifold, &sRectPoly2, sRectTrans2, &hash->circle, hash->transform);
			reverseNormal = true;
			break;
	}

	// to world coordinates
	if(manifold.pointCount > 0) {
		// write data back
		if(result) {
			// convert to world coordinate
			b2WorldManifold worldManifold;
			if(reverseNormal) {
				worldManifold.Initialize(&manifold,
										 sRectTrans2,
										 sRectPoly2.m_radius,
										 hash->transform,
										 hash->type == b2Shape::e_polygon ? hash->poly.m_radius : hash->circle.m_radius);
			} else {
				worldManifold.Initialize(&manifold,
										 hash->transform,
										 hash->type == b2Shape::e_polygon ? hash->poly.m_radius : hash->circle.m_radius,
										 sRectTrans2,
										 sRectPoly2.m_radius);
			}

			// save contact points
			result->pointCount = manifold.pointCount;
			for(int i = 0; i < manifold.pointCount; i++) {
				result->points[i] = wyp(meter2Pixel(worldManifold.points[i].x), meter2Pixel(worldManifold.points[i].y));
			}

			// save normal
			if(reverseNormal)
				result->normal = wyp(-worldManifold.normal.x, -worldManifold.normal.y);
			else
				result->normal = wyp(worldManifold.normal.x, worldManifold.normal.y);
		}
	}

	return manifold.pointCount > 0;
}

bool wyBox2DCollisionDetector::isCollided(wyRect& r1, wyRect& r2, wyBox2DCDResult* result) {
	// init transform 1
	sRectTrans1.SetIdentity();
	b2Vec2 v;
	v.x = pixel2Meter(r1.x + r1.width / 2);
	v.y = pixel2Meter(r1.y + r1.height / 2);
	sRectTrans1.Set(v, 0);

	// init transform 2
	sRectTrans2.SetIdentity();
	v.x = pixel2Meter(r2.x + r2.width / 2);
	v.y = pixel2Meter(r2.y + r2.height / 2);
	sRectTrans2.Set(v, 0);

	// init shape 1
	sRectPoly1.SetAsBox(pixel2Meter(r1.width) / 2, pixel2Meter(r1.height) / 2);

	// init shape 2
	sRectPoly2.SetAsBox(pixel2Meter(r2.width) / 2, pixel2Meter(r2.height) / 2);

	// collision detection
	b2Manifold manifold;
	b2CollidePolygons(&manifold, &sRectPoly1, sRectTrans1, &sRectPoly2, sRectTrans2);

	// to world coordinates
	if(manifold.pointCount > 0) {
		// write data back
		if(result) {
			// convert to world coordinate
			b2WorldManifold worldManifold;
			worldManifold.Initialize(&manifold, sRectTrans1, sRectPoly1.m_radius, sRectTrans2, sRectPoly2.m_radius);

			result->pointCount = manifold.pointCount;
			for(int i = 0; i < manifold.pointCount; i++) {
				result->points[i] = wyp(meter2Pixel(worldManifold.points[i].x), meter2Pixel(worldManifold.points[i].y));
			}

			result->normal = wyp(worldManifold.normal.x, worldManifold.normal.y);
		}
	}

	return manifold.pointCount > 0;
}
