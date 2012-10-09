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
#include "wyVerletRope.h"
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyMaterial.h"
#include "wyQuadList.h"
#include "wyDirector.h"
#include "wyRenderManager.h"

wyVerletRope::wyVerletRope(wyPoint a, wyPoint b, wyTexture2D* tex, size_t length) :
		m_points(wyArrayNew(16)),
		m_sticks(wyArrayNew(16)),
		m_color(wyc4bWhite),
		m_antiSagHack(0.0f),
		m_tex(NULL),
		m_dirty(true),
		m_stickLength(0),
		m_data(NULL) {
	// create mesh
	m_mesh = wyQuadList::make();
	m_mesh->retain();

	// create material
	m_material = wyMaterial::make();
	m_material->retain();

	// set texture
	setTexture(tex);

	// get distance
	m_length = length == 0 ? wypDistance(a, b) : length;

	//increase value to have less segments per rope, decrease to have more segments
	int segmentFactor = 12;

	// get number of points
	int numPoints = m_length / segmentFactor;

	// get diff vector
	wyPoint diffVector = wypSub(b, a);

	// get distance of adjacent points
	m_stickLength = m_length / (numPoints - 1);

	// calculate all points
	for (int i = 0; i < numPoints; i++) {
		wyPoint tmpVector = wypAdd(a, wypMul2(wypNormalize(diffVector), m_stickLength * i * (1 - m_antiSagHack)));
		wyVerletPoint* tmpPoint = WYNEW wyVerletPoint();
		tmpPoint->setPosition(tmpVector.x, tmpVector.y);
		wyArrayPush(m_points, tmpPoint);
	}

	// create all sticks
	for (int i = 0; i < numPoints - 1; i++) {
		wyVerletPoint* a = (wyVerletPoint*)wyArrayGet(m_points, i);
		wyVerletPoint* b = (wyVerletPoint*)wyArrayGet(m_points, i + 1);
		wyVerletStick* tmpStick = WYNEW wyVerletStick(a, b);
		wyArrayPush(m_sticks, tmpStick);
	}

	// if length is not zero, move to point b
	if(length > 0) {
		update(a, b, 1.0f / 30.f);
	}
}

wyVerletRope::wyVerletRope(wyVerletRope* rope, int startPoint, int endPoint) :
		m_antiSagHack(0.0f),
		m_tex(NULL),
		m_color(wyc4bWhite),
		m_stickLength(0),
		m_dirty(true),
		m_data(NULL) {
	// create mesh
	m_mesh = wyQuadList::make();
	m_mesh->retain();

	// create material
	m_material = wyMaterial::make();
	m_material->retain();

	// set texture
	setTexture(rope->getTexture());

	// create point and stick list
	int numPoints = endPoint - startPoint + 1;
	m_points = wyArrayNew(numPoints);
	m_sticks = wyArrayNew(numPoints - 1);

	// populate points
	wyArray* points = rope->getPoints();
	for(int i = startPoint; i <= endPoint; i++) {
		wyVerletPoint* original = (wyVerletPoint*)wyArrayGet(points, i);
		wyVerletPoint* copy = original->copy();
		copy->retain();
		wyArrayPush(m_points, copy);
	}

	// create all sticks, and copy length from original one
	wyArray* sticks = rope->getSticks();
	for (int i = 0, j = startPoint; i < numPoints - 1; i++, j++) {
		wyVerletStick* original = (wyVerletStick*)wyArrayGet(sticks, j);
		wyVerletPoint* a = (wyVerletPoint*)wyArrayGet(m_points, i);
		wyVerletPoint* b = (wyVerletPoint*)wyArrayGet(m_points, i + 1);
		wyVerletStick* tmpStick = WYNEW wyVerletStick(a, b);
		tmpStick->setLength(original->getLength());
		wyArrayPush(m_sticks, tmpStick);
	}

	// calculate original length of this new rope
	setLength(rope->getLength() * (numPoints - 1) / (rope->getPointCount() - 1));

	// set stick original length
	m_stickLength = m_length / (numPoints - 1);
}

wyVerletRope::~wyVerletRope() {
	wyArrayEach(m_points, releaseObject, NULL);
	wyArrayDestroy(m_points);
	wyArrayEach(m_sticks, releaseObject, NULL);
	wyArrayDestroy(m_sticks);
	wyObjectRelease(m_material);
	wyObjectRelease(m_mesh);
	wyObjectRelease(m_tex);
}

void wyVerletRope::setTexture(wyTexture2D* tex) {
	wyObjectRetain(tex);
	wyObjectRelease(m_tex);
	m_tex = tex;

	// get texture parameter, if none, create
	wyMaterialParameter* mp = m_material->getParameter(wyUniform::NAME[wyUniform::TEXTURE_2D]);
	if(!mp) {
		wyMaterialTextureParameter* p = wyMaterialTextureParameter::make(wyUniform::NAME[wyUniform::TEXTURE_2D], m_tex);
		m_material->addParameter(p);
	} else {
		wyMaterialTextureParameter* mtp = (wyMaterialTextureParameter*)mp;
		mtp->setTexture(m_tex);
	}
}

bool wyVerletRope::releaseObject(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

void wyVerletRope::appendQuad(wyVerletPoint* a, wyVerletPoint* b) {
	// get wyPoint
	wyPoint pa = wyp(a->m_x, a->m_y);
	wyPoint pb = wyp(b->m_x, b->m_y);

	// get texture effect size
	float tW = m_tex->getWidth();
	float tH = m_tex->getHeight();
	float tPW = m_tex->getPixelWidth();
	float tPH = m_tex->getPixelHeight();

	// construct wyPoint, get rotation and distance
	float radian = wypToRadian(wypSub(pa, pb));
	float distance = wypDistance(pa, pb);

	// get midpoint
	wyPoint m = wypMidpoint(pa, pb);

	// distance may be longer than texture width, so need divide them
	float remaining = distance;
	float len = MIN(remaining, tW);
	remaining -= len;
	wyPoint start_bl = wyp(-distance / 2, -tH / 2);
	wyPoint start_tl = wyp(-distance / 2, tH / 2);
	while(len > 0) {
		// get bottom right and top right
		wyPoint bl = start_bl;
		start_bl.x += len;
		wyPoint br = wyp(start_bl.x, -tH / 2);
		wyPoint tl = start_tl;
		start_tl.x += len;
		wyPoint tr = wyp(start_tl.x, tH / 2);

		// transform points
		wyAffineTransform t = wyaMakeRotate(radian);
		bl = wyaTransformPoint(t, bl);
		br = wyaTransformPoint(t, br);
		tl = wyaTransformPoint(t, tl);
		tr = wyaTransformPoint(t, tr);

		// build vertex
		wyQuad3D vertex;
		vertex.bl_x = bl.x + m.x;
		vertex.bl_y = bl.y + m.y;
		vertex.bl_z = 0;
		vertex.br_x = br.x + m.x;
		vertex.br_y = br.y + m.y;
		vertex.br_z = 0;
		vertex.tl_x = tl.x + m.x;
		vertex.tl_y = tl.y + m.y;
		vertex.tl_z = 0;
		vertex.tr_x = tr.x + m.x;
		vertex.tr_y = tr.y + m.y;
		vertex.tr_z = 0;

		// get four corner
		float left = 0;
		float top = 0;
		float right = len / tPW;
		float bottom = tH / tPH;

		// build tex coordinates
		wyQuad2D texCoords;
		texCoords.bl_x = left;
		texCoords.bl_y = bottom;
		texCoords.br_x = right;
		texCoords.br_y = bottom;
		texCoords.tl_x = left;
		texCoords.tl_y = top;
		texCoords.tr_x = right;
		texCoords.tr_y = top;

		// append quad
		m_mesh->appendQuad(texCoords, vertex);

		// get next segment length
		len = MIN(remaining, tW);
		remaining -= len;
	}
}

void wyVerletRope::updateQuads() {
	// remove all quads
	m_mesh->removeAllQuads();

	for (int i = 0; i < m_points->num - 1; i++) {
		// get stick points
		wyVerletStick* stick = (wyVerletStick*)wyArrayGet(m_sticks, i);
		wyVerletPoint* a = stick->getPointA();
		wyVerletPoint* b = stick->getPointB();

		// append one quad to atlas
		appendQuad(a, b);
	}
}

void wyVerletRope::reset(wyPoint a, wyPoint b) {
	// get distance
	float distance = wypDistance(a, b);

	// get diff vector
	wyPoint diffVector = wypSub(b, a);

	// get distance of adjacent points
	float multiplier = distance / (m_points->num - 1);

	// create all points
	for (int i = 0; i < m_points->num; i++) {
		wyPoint tmpVector = wypAdd(a, wypMul2(wypNormalize(diffVector), multiplier * i * (1 - m_antiSagHack)));
		wyVerletPoint* tmpPoint = (wyVerletPoint*)wyArrayGet(m_points, i);
		tmpPoint->setPosition(tmpVector.x, tmpVector.y);
	}

	// set flag
	m_dirty = true;
}

void wyVerletRope::update(wyPoint a, wyPoint b, float dt) {
	// manually set position for first and last point of rope
	wyVerletPoint* p = (wyVerletPoint*)wyArrayGet(m_points, 0);
	p->setPosition(a.x, a.y);
	p = (wyVerletPoint*)wyArrayGet(m_points, m_points->num - 1);
	p->setPosition(b.x, b.y);

	// update points, apply gravity
	for (int i = 1; i < m_points->num - 1; i++) {
		wyVerletPoint* p = (wyVerletPoint*) wyArrayGet(m_points, i);
		p->applyGravity(dt);
		p->update();
	}

	// contract sticks
	int iterations = 3;
	for (int j = 0; j < iterations; j++) {
		for (int i = 0; i < m_points->num - 2; i++) {
			wyVerletStick* s = (wyVerletStick*) wyArrayGet(m_sticks, i);
			s->contract(false);
		}
		for (int i = m_points->num - 2; i > 0; i--) {
			wyVerletStick* s = (wyVerletStick*) wyArrayGet(m_sticks, i);
			s->contract(true);
		}

		// attenuate
		for (int i = 1; i < m_points->num - 1; i++) {
			wyVerletPoint* p = (wyVerletPoint*) wyArrayGet(m_points, i);
			p->attenuate(0.05f);
		}
	}

	// set flag
	m_dirty = true;
}

float wyVerletRope::getCurrentLength() {
	float length = 0;
	for(int i = 0; i < m_points->num - 1; i++) {
		wyVerletStick* s = (wyVerletStick*) wyArrayGet(m_sticks, i);
		length += s->getCurrentLength();
	}
	return length;
}

wyColor3B wyVerletRope::getColor() {
	wyColor3B c = {
		m_color.r,
		m_color.g,
		m_color.b
	};
	return c;
}

void wyVerletRope::setColor(wyColor3B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_mesh->updateColor(m_color);
}

void wyVerletRope::setColor(wyColor4B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_color.a = color.a;
	m_mesh->updateColor(m_color);
}

bool wyVerletRope::isStretched() {
	wyVerletPoint* a = getPointAt(0);
	wyVerletPoint* b = getPointAt(getPointCount() - 1);
	wyPoint pa = wyp(a->getX(), a->getY());
	wyPoint pb = wyp(b->getX(), b->getY());
	float distance = wypDistance(pa, pb);
	return distance > m_length * 1.04f + 1.f;
}

void wyVerletRope::draw(wyNode* parent) {
	// update quads
	if(m_dirty) {
		updateQuads();
		m_dirty = false;
	}

	// apply render state
	wyRenderManager* rm = wyDirector::getInstance()->getRenderManager();
	rm->renderMaterial(parent, m_material, m_mesh);
}

int wyVerletRope::rayCast(wyPoint s, wyPoint e) {
	for(int i = 0; i < m_sticks->num; i++) {
		wyVerletStick* stick = (wyVerletStick*)wyArrayGet(m_sticks, i);
		wyVerletPoint* a = stick->getPointA();
		wyVerletPoint* b = stick->getPointB();
		wyPoint pa = wyp(a->getX(), a->getY());
		wyPoint pb = wyp(b->getX(), b->getY());
		if(wyMath::isIntersected(s, e, pa, pb))
			return i;
	}

	return -1;
}

wyVerletRope* wyVerletRope::subRope(int startPoint, int endPoint) {
	if(startPoint < 0 || startPoint >= getPointCount() ||
			endPoint < 0 || endPoint >= getPointCount() ||
			endPoint <= startPoint)
		return NULL;

	wyVerletRope* rope = WYNEW wyVerletRope(this, startPoint, endPoint);
	rope->autoRelease();
	return rope;
}

void wyVerletRope::changeLength(float delta) {
	// check delta
	if(delta > 0) {
		// get last stick
		wyVerletStick* lastStick = getStickAt(m_points->num - 2);

		// 如果stick的长度加上delta也没有超过stick原始长度，则直接修改最好一个stick
		// 如果超过了，把最后一个stick变成原始长度，再新建一个stick
		float lastStickLength = lastStick->getLength();
		if(lastStickLength + delta <= m_stickLength) {
			wyVerletPoint* a = lastStick->getPointA();
			wyVerletPoint* b = lastStick->getPointB();
			float deltaX = (b->m_x - a->m_x) * delta / lastStickLength;
			float deltaY = (b->m_y - a->m_y) * delta / lastStickLength;
			b->setPosition(b->m_x + deltaX, b->m_y + deltaY);
			lastStick->setLength(lastStickLength + delta);
		} else {
			// extend last stick to original length
			float lastStickDelta = m_stickLength - lastStickLength;
			wyVerletPoint* a = lastStick->getPointA();
			wyVerletPoint* b = lastStick->getPointB();
			float deltaX = (b->m_x - a->m_x) * lastStickDelta / lastStickLength;
			float deltaY = (b->m_y - a->m_y) * lastStickDelta / lastStickLength;
			b->setPosition(b->m_x + deltaX, b->m_y + deltaY);
			lastStick->setLength(m_stickLength);
			delta -= lastStickDelta;

			// create a new stick
			deltaX = (b->m_x - a->m_x) * delta / m_stickLength;
			deltaY = (b->m_y - a->m_y) * delta / m_stickLength;
			wyVerletPoint* b2 = WYNEW wyVerletPoint();
			b2->setPosition(b->m_x + deltaX, b->m_y + deltaY);
			wyArrayPush(m_points, b2);
			wyVerletStick* newLastStick = WYNEW wyVerletStick(b, b2);
			wyArrayPush(m_sticks, newLastStick);
		}

		// update rope length
		m_length += delta;
	} else if(delta < 0) {
		// 如果stick的长度大于delta，则直接减去
		// 如果小于delta，则要删除stick，同时再看接着的stick
		while(delta < 0 && m_sticks->num > 0) {
			// get last stick
			wyVerletStick* lastStick = getStickAt(m_points->num - 2);

			// get length of last stick
			float lastStickLength = lastStick->getLength();

			if(lastStickLength < -delta) {
				// delete last stick and last point
				wyArrayDeleteIndex(m_sticks, m_points->num - 2);
				lastStick->release();
				wyVerletPoint* point = (wyVerletPoint*)wyArrayDeleteIndex(m_points, m_points->num - 1);
				point->release();

				// adjust delta
				delta += lastStickLength;
			} else if(lastStickLength > -delta) {
				// substract delta from last stick
				wyVerletPoint* a = lastStick->getPointA();
				wyVerletPoint* b = lastStick->getPointB();
				float deltaX = (b->m_x - a->m_x) * delta / lastStickLength;
				float deltaY = (b->m_y - a->m_y) * delta / lastStickLength;
				b->setPosition(b->m_x + deltaX, b->m_y + deltaY);
				lastStick->setLength(lastStickLength + delta);

				// adjust delta
				delta = 0;
			} else {
				// delete last stick and last point
				wyArrayDeleteIndex(m_sticks, m_points->num - 2);
				lastStick->release();
				wyVerletPoint* point = (wyVerletPoint*)wyArrayDeleteIndex(m_points, m_points->num - 1);
				point->release();

				// adjust delta
				delta = 0;
			}
		}
	}

	// set flag
	m_dirty = true;
}
