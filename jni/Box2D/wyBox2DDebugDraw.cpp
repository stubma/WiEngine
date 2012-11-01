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
#include "wyBox2DDebugDraw.h"
#include "wyMaterial.h"
#include "wyShape.h"
#include "wyBox2D.h"

static const GLfloat circleVAR[] = { 0.0000f, 0.0000f,
	0.0000f, 1.0000f, 0.2588f, 0.9659f, 0.5000f, 0.8660f, 0.7071f, 0.7071f, 0.8660f, 0.5000f, 0.9659f, 0.2588f,
	1.0000f, 0.0000f, 0.9659f, -0.2588f, 0.8660f, -0.5000f, 0.7071f, -0.7071f, 0.5000f, -0.8660f, 0.2588f, -0.9659f,
	0.0000f, -1.0000f, -0.2588f, -0.9659f, -0.5000f, -0.8660f, -0.7071f, -0.7071f, -0.8660f, -0.5000f, -0.9659f, -0.2588f,
	-1.0000f, -0.0000f, -0.9659f, 0.2588f, -0.8660f, 0.5000f, -0.7071f, 0.7071f, -0.5000f, 0.8660f, -0.2588f, 0.9659f,
	0.0000f, 1.0000f, 0.0f, 0.0f, // For an extra line to see the rotation.
};
static const int circleVAR_count = sizeof(circleVAR) / sizeof(GLfloat) / 2;

wyBox2DDebugDraw::wyBox2DDebugDraw(wyBox2D* box2d) :
		m_box2d(box2d) {
	SetFlags(e_shapeBit | e_jointBit);
}

void wyBox2DDebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	GLfloat* VAR = (GLfloat*)malloc(vertexCount * 2 * sizeof(GLfloat));

	for (int i = 0; i < vertexCount; i++) {
		VAR[2 * i] = meter2Pixel(vertices[i].x);
		VAR[2 * i + 1] = meter2Pixel(vertices[i].y);
	}

	wyShape* s = wyShape::make();
	s->buildPath(VAR, vertexCount);
	s->updateColor(wyc4f(color.r, color.g, color.b, 1.0f));
	m_box2d->addRenderPair(wyMaterial::make(wyShaderManager::PROG_PC), s);

	free(VAR);
}

void wyBox2DDebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	GLfloat* VAR = (GLfloat*)malloc((vertexCount + 1) * 2 * sizeof(GLfloat));

	for (int i = 0; i < vertexCount; i++) {
		VAR[2 * i] = meter2Pixel(vertices[i].x);
		VAR[2 * i + 1] = meter2Pixel(vertices[i].y);
	}
	VAR[2 * vertexCount] = meter2Pixel(vertices[0].x);
	VAR[2 * vertexCount + 1] = meter2Pixel(vertices[0].y);

	wyMaterial* m = wyMaterial::make(wyShaderManager::PROG_PC);
	wyShape* s = wyShape::make();
	s->buildCustom2D(VAR, NULL, vertexCount, wyMesh::TRIANGLE_FAN);
	s->updateColor(wyc4f(color.r, color.g, color.b, 1.0f));
	m_box2d->addRenderPair(m, s);

	// black border
	s = wyShape::make();
	s->buildPath(VAR, vertexCount + 1);
	s->updateColor(wyc4bBlack);
	m_box2d->addRenderPair(m, s);

	free(VAR);
}

void wyBox2DDebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
	// vertices
	GLfloat vertices[circleVAR_count * 2];
	memcpy(vertices, circleVAR, sizeof(circleVAR));

	// build transform matrix
	wyAffineTransform t = wyaIdentity;
	wyaTranslate(&t, m_box2d->meter2Pixel(center.x), m_box2d->meter2Pixel(center.y));
	wyaScale(&t, m_box2d->meter2Pixel(radius), m_box2d->meter2Pixel(radius));

	// transform vertices
	for(int i = 0; i < circleVAR_count * 2; i += 2) {
		wyaTransformPoint2(t, vertices[i], vertices[i + 1]);
	}

	// mesh
	wyShape* s = wyShape::make();
	s->buildPath(vertices, circleVAR_count);
	s->updateColor(wyc4f(color.r, color.g, color.b, 1.0f));
	m_box2d->addRenderPair(wyMaterial::make(wyShaderManager::PROG_PC), s);
}

void wyBox2DDebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
	// vertices
	GLfloat vertices[circleVAR_count * 2];
	memcpy(vertices, circleVAR, sizeof(circleVAR));

	// the axis is (cos, -sin)
	float angle = acosf(axis.x);
	if(axis.y < 0)
		angle = 2 * M_PI - angle;

	// build transform matrix
	wyAffineTransform t = wyaIdentity;
	wyaTranslate(&t, m_box2d->meter2Pixel(center.x), m_box2d->meter2Pixel(center.y));
	wyaRotate(&t, angle);
	wyaScale(&t, m_box2d->meter2Pixel(radius), m_box2d->meter2Pixel(radius));

	// transform vertices
	for(int i = 0; i < circleVAR_count * 2; i += 2) {
		wyaTransformPoint2(t, vertices[i], vertices[i + 1]);
	}

	// mesh for solid
	wyMaterial* m = wyMaterial::make(wyShaderManager::PROG_PC);
	wyShape* s = wyShape::make();
	s->buildCustom2D(vertices, NULL, circleVAR_count - 1, wyMesh::TRIANGLE_FAN);
	s->updateColor(wyc4f(color.r, color.g, color.b, 1.0f));
	m_box2d->addRenderPair(m, s);

	// border mesh
	s = wyShape::make();
	s->buildPath(vertices, circleVAR_count);
	s->updateColor(wyc4bBlack);
	m_box2d->addRenderPair(m, s);
}

void wyBox2DDebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
	wyShape* s = wyShape::make();
	s->buildLine(meter2Pixel(p1.x), meter2Pixel(p1.y), meter2Pixel(p2.x), meter2Pixel(p2.y));
	s->updateColor(wyc4f(color.r, color.g, color.b, 1.0f));
	m_box2d->addRenderPair(wyMaterial::make(wyShaderManager::PROG_PC), s);
}

void wyBox2DDebugDraw::DrawTransform(const b2Transform& xf) {
	// we don't draw center of mass
}

void wyBox2DDebugDraw::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color) {
	wyShape* s = wyShape::make();
	s->buildPoint(meter2Pixel(p.x), meter2Pixel(p.y));
	s->updateColor(wyc4f(color.r, color.g, color.b, 1.0f));
	m_box2d->addRenderPair(wyMaterial::make(wyShaderManager::PROG_PC), s);
}
