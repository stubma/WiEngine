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
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Collision/Shapes/b2CircleShape.h>
#include <Box2D/Collision/Shapes/b2EdgeShape.h>
#include <Box2D/Collision/Shapes/b2ChainShape.h>
#include "wyBox2D.h"
#include "wyLog.h"

static const GLfloat circleVAR[] = { 0.0000f, 0.0000f,
	0.0000f, 1.0000f, 0.2588f, 0.9659f, 0.5000f, 0.8660f, 0.7071f, 0.7071f, 0.8660f, 0.5000f, 0.9659f, 0.2588f,
	1.0000f, 0.0000f, 0.9659f, -0.2588f, 0.8660f, -0.5000f, 0.7071f, -0.7071f, 0.5000f, -0.8660f, 0.2588f, -0.9659f,
	0.0000f, -1.0000f, -0.2588f, -0.9659f, -0.5000f, -0.8660f, -0.7071f, -0.7071f, -0.8660f, -0.5000f, -0.9659f, -0.2588f,
	-1.0000f, -0.0000f, -0.9659f, 0.2588f, -0.8660f, 0.5000f, -0.7071f, 0.7071f, -0.5000f, 0.8660f, -0.2588f, 0.9659f,
	0.0000f, 1.0000f, 0.0f, 0.0f, // For an extra line to see the rotation.
};
static const int circleVAR_count = sizeof(circleVAR) / sizeof(GLfloat) / 2;

static const GLfloat pillVAR[] = {
	0.0000f, 1.0000f, 0.2588f, 0.9659f, 0.5000f,
	0.8660f, 0.7071f, 0.7071f, 0.8660f, 0.5000f, 0.9659f, 0.2588f, 1.0000f,
	0.0000f, 0.9659f, -0.2588f, 0.8660f, -0.5000f, 0.7071f, -0.7071f,
	0.5000f, -0.8660f, 0.2588f, -0.9659f, 0.0000f, -1.0000f,

	0.0000f, -1.0000f, -0.2588f, -0.9659f, -0.5000f, -0.8660f, -0.7071f,
	-0.7071f, -0.8660f, -0.5000f, -0.9659f, -0.2588f, -1.0000f, -0.0000f,
	-0.9659f, 0.2588f, -0.8660f, 0.5000f, -0.7071f, 0.7071f, -0.5000f,
	0.8660f, -0.2588f, 0.9659f, 0.0000f, 1.0000f
};
static const int pillVAR_count = sizeof(pillVAR) / sizeof(GLfloat) / 2;

/**
 * @typedef wyTexMapHash
 *
 * 保存一个形状和一个贴图之间的映射关系
 */
typedef struct wyTexMapHash {
	/// 形状对象
	b2Fixture* m_fixture;

	/// 贴图对象
	wyTexture2D* m_tex;

	/// 矩形，用于图片集, 如果m_tex不是一个图片集，则m_rect就是m_tex的实际大小
	wyRect m_rect;
} wyTexMapHash;

/**
 * @typedef wyTexMapData
 *
 * 保存一个贴图和相关矩形。由于wyHashSet在构造时只能传送一个data参数，因此需要
 * 用一个中间结构包装一下相关数据
 */
typedef struct wyTexMapData {
	/// 贴图对象
	wyTexture2D* m_tex;

	/// 矩形，用于图片集, 如果m_tex不是一个图片集，则m_rect就是m_tex的实际大小
	wyRect m_rect;
} wyTexMapData;

int wyBox2DRender::hashEquals(void* ptr, void* elt) {
	return ptr == ((wyTexMapHash*)elt)->m_fixture;
}

void* wyBox2DRender::hashTrans(void* ptr, void* data) {
	wyTexMapHash* hash = (wyTexMapHash*)wyCalloc(1, sizeof(wyTexMapHash));
	wyTexMapData* obj = (wyTexMapData*)data;
	hash->m_fixture = (b2Fixture*)ptr;
	hash->m_tex = obj->m_tex;
	hash->m_rect = obj->m_rect;
	wyObjectRetain(obj->m_tex);
	return hash;
}

bool wyBox2DRender::releaseHash(void* elt, void* data) {
	wyTexMapHash* hash = (wyTexMapHash*)elt;
	wyObjectRelease(hash->m_tex);
	wyFree(hash);
	return false;
}

wyBox2DRender::wyBox2DRender() :
		m_texMap(wyHashSetNew(10, hashEquals, hashTrans)) {
}

wyBox2DRender::~wyBox2DRender() {
	wyHashSetFilter(m_texMap, releaseHash, NULL);
	wyHashSetDestroy(m_texMap);
}

void wyBox2DRender::bindTexture(b2Fixture* f, wyTexture2D* tex) {
	bindTexture(f, tex, tex == NULL ? wyrZero : wyr(0, 0, tex->getWidth(), tex->getHeight()));
}

void wyBox2DRender::bindTexture(b2Fixture* f, wyTexture2D* tex, wyRect rect) {
	// do nothing if f is NULL
	if(f == NULL)
		return;

	// must remove it first, no matter what tex is
	// because wyHashSetInsert won't replace existing
	// hash
	wyTexMapHash* hash = (wyTexMapHash*)wyHashSetRemove(m_texMap, (size_t)f, f);
	if(hash != NULL) {
		releaseHash(hash, NULL);
	}

	// if tex is not NULL, insert binding
	if(tex != NULL) {
		wyTexMapData data = {
			tex,
			rect
		};
		wyHashSetInsert(m_texMap, (size_t)f, f, &data);
	}
}

void wyBox2DRender::drawWorld(wyBox2D* box2d) {
	b2World* world = box2d->getWorld();
	for(b2Body* b = world->GetBodyList(); b != NULL; b = b->GetNext()) {
		for(b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext()) {
			drawShape(box2d, f, b);
		}
	}
}

void wyBox2DRender::drawShape(wyBox2D* box2d, b2Fixture* fixture, b2Body* body) {
	// check texture, if no texture, return
	wyTexMapHash* hash = (wyTexMapHash*)wyHashSetFind(m_texMap, (size_t)fixture, fixture);
	if(hash == NULL)
		return;

	// check fixture type and call other methods
	switch(fixture->GetType()) {
		case b2Shape::e_circle:
			drawCircle(box2d, fixture, body, hash->m_tex, hash->m_rect);
			break;
		case b2Shape::e_edge:
			drawEdge(box2d, fixture, body, hash->m_tex, hash->m_rect);
			break;
		case b2Shape::e_chain:
			drawChain(box2d, fixture, body, hash->m_tex, hash->m_rect);
			break;
		case b2Shape::e_polygon:
			drawPolygon(box2d, fixture, body, hash->m_tex, hash->m_rect);
			break;
	}
}

void wyBox2DRender::drawCircle(wyBox2D* box2d, b2Fixture* fixture, b2Body* body, wyTexture2D* tex, wyRect rect) {
	// check texture
	if(tex == NULL)
		return;

	// load texture info if has
	tex->load();

	// create tex coords
	GLfloat TEX[circleVAR_count * 2];
	float off_s = rect.x / tex->getPixelWidth();
	float off_t = rect.y / tex->getPixelHeight();
	float wrap_s = rect.width / tex->getPixelWidth();
	float wrap_t = rect.height / tex->getPixelHeight();
	for(int i = 0; i < circleVAR_count * 2; i += 2) {
		TEX[i] = off_s + (circleVAR[i] / 2.0f + 0.5f) * wrap_s;
		TEX[i + 1] = off_t + (0.5f - circleVAR[i + 1] / 2.0f) * wrap_t;
	}

	// enable state
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
	glVertexPointer(2, GL_FLOAT, 0, circleVAR);
	glTexCoordPointer(2, GL_FLOAT, 0, TEX);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// ensure current texture is active
	glBindTexture(GL_TEXTURE_2D, tex->getTexture());

	// repeat texture in both direction
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glPushMatrix();
	{
		// get circle center, radius and axis
		b2CircleShape* circle = (b2CircleShape*)fixture->GetShape();
		const b2Transform& xf = body->GetTransform();
		b2Vec2 center = b2Mul(xf, circle->m_p);
		float32 radius = circle->m_radius;
		b2Vec2 axis = xf.q.GetXAxis();

		// the axis is (cos, -sin)
		float degree = acosf(axis.x) * 180.f / M_PI;
		if(axis.y < 0)
			degree = 360.f - degree;

		glTranslatef(box2d->meter2Pixel(center.x), box2d->meter2Pixel(center.y), 0.0f);
		glRotatef(degree, 0.0f, 0.0f, 1.0f);
		glScalef(box2d->meter2Pixel(radius), box2d->meter2Pixel(radius), 1.0f);

		glDrawArrays(GL_TRIANGLE_FAN, 0, circleVAR_count);
	}
	glPopMatrix();

	// restore old state
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);
}

void wyBox2DRender::drawEdge(wyBox2D* box2d, b2Fixture* fixture, b2Body* body, wyTexture2D* tex, wyRect rect) {
	// check texture
	if(tex == NULL)
		return;

	// load texture info if has
	tex->load();

	// get rotation angle in degree
	b2EdgeShape* edge = (b2EdgeShape*)fixture->GetShape();
	const b2Transform& xf = body->GetTransform();
	float angle = xf.q.GetAngle();
	b2Vec2 v = edge->m_vertex1;
	v -= edge->m_vertex2;

	// get middle point
	b2Vec2 middle = edge->m_vertex1;
	middle += edge->m_vertex2;
	middle *= 0.5f;

	// get length in pixel
	float length = box2d->meter2Pixel(v.Length());

	// build vertices
	GLfloat vertices[] = {
		-length / 2, -rect.height / 2,
		length / 2, -rect.height / 2,
		-length / 2, rect.height / 2,
		length / 2, rect.height / 2
	};

	// build tex coords
	float left = rect.x / tex->getPixelWidth();
	float right = (rect.x + rect.width) / tex->getPixelWidth();
	float top = (rect.y + rect.height) / tex->getPixelHeight();
	float bottom = rect.y / tex->getPixelHeight();
	GLfloat texCoords[] = {
		left, bottom,
		right, bottom,
		left, top,
		right, top
	};

	// enable state
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// ensure current texture is active
	glBindTexture(GL_TEXTURE_2D, tex->getTexture());

	// repeat texture in both direction
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// draw
	glPushMatrix();
	{
		glTranslatef(box2d->meter2Pixel(middle.x), box2d->meter2Pixel(middle.y), 0.0f);
		glRotatef(wyMath::r2d(angle + atan(v.y / v.x)), 0, 0, 1);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	}
	glPopMatrix();

	// restore old state
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);
}

void wyBox2DRender::drawChain(wyBox2D* box2d, b2Fixture* fixture, b2Body* body, wyTexture2D* tex, wyRect rect) {
	// check texture
	if(tex == NULL)
		return;

	// load texture info if has
	tex->load();

	// get something
	b2ChainShape* chain = (b2ChainShape*)fixture->GetShape();
	const b2Transform& xf = body->GetTransform();
	int count = chain->m_count;
	const b2Vec2* vertices = chain->m_vertices;
	float angle = xf.q.GetAngle();

	// enable state
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);

	// ensure current texture is active
	glBindTexture(GL_TEXTURE_2D, tex->getTexture());

	// repeat texture in both direction
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	for(int i = 0; i < count; i++) {
		// 得到一条边的倾斜角度, atan的返回值范围是-PI/2到-PI/2
		b2Vec2 v1 = vertices[i];
		b2Vec2 v2 = (i == count - 1) ? vertices[0] : vertices[i + 1];
		b2Vec2 v = v1;
		v -= v2;
		float slop = atan(v.y / v.x);

		// 构造一个矩阵，可以让这条边旋转到水平位置
		b2Mat22 m = b2Mat22(-slop);

		// 选择这条边，得到旋转后的两个端点
		b2Vec2 mv1 = b2Mul(m, v1);
		b2Vec2 mv2 = b2Mul(m, v2);

		// 得到边长
		float length = v.Length();

		// 计算从原点到这条边的距离
		float u = (-mv1.x * (mv2.x - mv1.x) + -mv1.y * (mv2.y - mv1.y)) / length / length;
		b2Vec2 intersect = b2Vec2(mv1.x + u * (mv2.x - mv1.x), mv1.y + u * (mv2.y - mv1.y));
		float distance = box2d->meter2Pixel(intersect.Length());
		bool above = intersect.y > 0;

		// 根据以上参数就可以构造出旋转到水平位置后，边的顶点数组
		GLfloat vertices[] = {
			box2d->meter2Pixel(mv1.x), -rect.height / 2 + (above ? distance : -distance),
			box2d->meter2Pixel(mv2.x), -rect.height / 2 + (above ? distance : -distance),
			box2d->meter2Pixel(mv1.x), rect.height / 2 + (above ? distance : -distance),
			box2d->meter2Pixel(mv2.x), rect.height / 2 + (above ? distance : -distance)
		};

		// 得到贴图坐标的范围
		float left = rect.x / tex->getPixelWidth();
		float right = (rect.x + rect.width) / tex->getPixelWidth();
		float top = (rect.y + rect.height) / tex->getPixelHeight();
		float bottom = rect.y / tex->getPixelHeight();
		GLfloat texCoords[] = {
			left, bottom,
			right, bottom,
			left, top,
			right, top
		};

		// set array
		glVertexPointer(2, GL_FLOAT, 0, vertices);
		glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

		// draw
		glPushMatrix();
		{
			glTranslatef(box2d->meter2Pixel(xf.p.x), box2d->meter2Pixel(xf.p.y), 0.0f);
			glRotatef(wyMath::r2d(angle + slop), 0, 0, 1);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		}
		glPopMatrix();
	}

	// restore old state
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);
}

void wyBox2DRender::drawPolygon(wyBox2D* box2d, b2Fixture* fixture, b2Body* body, wyTexture2D* tex, wyRect rect) {
	// check texture
	if(tex == NULL)
		return;

	// load texture info if has
	tex->load();

	// get polygon and transform, compute aabb
	b2PolygonShape* poly = (b2PolygonShape*)fixture->GetShape();
	const b2Transform& xf = body->GetTransform();
	b2AABB aabb;
	poly->ComputeAABB(&aabb, b2Transform_identity, 0);
	float shapeW = aabb.upperBound.x - aabb.lowerBound.x;
	float shapeH = aabb.upperBound.y - aabb.lowerBound.y;

	// create vertex and texture array
	int count = poly->m_count;
	GLfloat* VAR = (GLfloat*)malloc(count * 2 * sizeof(GLfloat));
	GLfloat* TEX = (GLfloat*)malloc(count * 2 * sizeof(GLfloat));

	// enable state
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
	glVertexPointer(2, GL_FLOAT, 0, VAR);
	glTexCoordPointer(2, GL_FLOAT, 0, TEX);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// ensure current texture is active
	glBindTexture(GL_TEXTURE_2D, tex->getTexture());

	// repeat texture in both direction
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// fill array
	float left = rect.x / tex->getPixelWidth();
	float bottom = (rect.y + rect.height) / tex->getPixelHeight();
	float width = rect.width / tex->getPixelWidth();
	float height = rect.height / tex->getPixelHeight();
	for (int i = 0; i < count; i++) {
		VAR[2 * i] = box2d->meter2Pixel(poly->m_vertices[i].x);
		VAR[2 * i + 1] = box2d->meter2Pixel(poly->m_vertices[i].y);

		TEX[2 * i] = left + width * (poly->m_vertices[i].x - aabb.lowerBound.x) / shapeW;
		TEX[2 * i + 1] = bottom - height * (poly->m_vertices[i].y - aabb.lowerBound.y) / shapeH;
	}

	glPushMatrix();
	{
		glTranslatef(box2d->meter2Pixel(xf.p.x), box2d->meter2Pixel(xf.p.y), 0.0f);
		glRotatef(wyMath::r2d(xf.q.GetAngle()), 0, 0, 1);
		glDrawArrays(GL_TRIANGLE_FAN, 0, count);
	}
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);

	// free
	free(VAR);
	free(TEX);
}
