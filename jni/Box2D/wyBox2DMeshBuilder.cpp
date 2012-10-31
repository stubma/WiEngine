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
#include "wyBox2DMeshBuilder.h"
#include "wyMesh.h"
#include "wyRectangle.h"
#include "wyShape.h"
#include "wyLog.h"
#include "wyQuadList.h"
#include "wyBox2D.h"

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

wyMesh* wyBox2DMeshBuilder::createMesh(wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect texRect) {
	switch(f->GetType()) {
		case b2Shape::e_circle:
		{
			wyShape* mesh = wyShape::make();
			updateCircleMesh(mesh, box2d, f, texPixelWidth, texPixelHeight, texRect);
			return mesh;
		}
		case b2Shape::e_edge:
		{
			wyRectangle* mesh = wyRectangle::make();
			updateEdgeMesh(mesh, box2d, f, texPixelWidth, texPixelHeight, texRect);
			return mesh;
		}
		case b2Shape::e_chain:
		{
			wyQuadList* mesh = wyQuadList::make();
			updateChainMesh(mesh, box2d, f, texPixelWidth, texPixelHeight, texRect);
			return mesh;
		}
		case b2Shape::e_polygon:
		{
			wyShape* mesh = wyShape::make();
			updatePolygonMesh(mesh, box2d, f, texPixelWidth, texPixelHeight, texRect);
			return mesh;
		}
		default:
			LOGW("wyBox2DMeshBuilder::createMesh: Unknown fixture shape type: %d", f->GetType());
			return NULL;
	}
}

void wyBox2DMeshBuilder::updateEdgeMesh(wyRectangle* mesh, wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect& texRect) {
	// get shape and body
	b2EdgeShape* edge = (b2EdgeShape*)f->GetShape();
	b2Body* body = f->GetBody();

	// get rotation angle in degree
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

	// vertices
	float vertices[12] = {
			-length / 2, -texRect.height / 2, 0,
			length / 2, -texRect.height / 2, 0,
			-length / 2, texRect.height / 2, 0,
			length / 2, texRect.height / 2, 0
	};

	// build transform matrix
	wyAffineTransform t = wyaIdentity;
	wyaTranslate(&t, box2d->meter2Pixel(middle.x), box2d->meter2Pixel(middle.y));
	wyaRotate(&t, angle + atan(v.y / v.x));

	// transform vertices
	wyaTransformPoint2(t, vertices[0], vertices[1]);
	wyaTransformPoint2(t, vertices[3], vertices[4]);
	wyaTransformPoint2(t, vertices[6], vertices[7]);
	wyaTransformPoint2(t, vertices[9], vertices[10]);

	// build tex coords
	float left = texRect.x / texPixelWidth;
	float right = (texRect.x + texRect.width) / texPixelWidth;
	float top = (texRect.y + texRect.height) / texPixelHeight;
	float bottom = texRect.y / texPixelHeight;
	GLfloat texCoords[] = {
		left, bottom,
		right, bottom,
		left, top,
		right, top
	};

	// update mesh
	mesh->updateMesh(vertices, texCoords);
}

void wyBox2DMeshBuilder::updateChainMesh(wyQuadList* mesh, wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect& texRect) {
	// get something
	b2ChainShape* chain = (b2ChainShape*)f->GetShape();
	b2Body* body = f->GetBody();
	const b2Transform& xf = body->GetTransform();
	int count = chain->m_count;
	const b2Vec2* vertices = chain->m_vertices;
	float angle = xf.q.GetAngle();

	// clear
	mesh->removeAllQuads();

	// create quad for every edge
	for(int i = 0; i < count; i++) {
		// get angle of edge, atan returns in [-PI/2, PI/2]
		b2Vec2 v1 = vertices[i];
		b2Vec2 v2 = (i == count - 1) ? vertices[0] : vertices[i + 1];
		b2Vec2 v = v1;
		v -= v2;
		float slop = atan(v.y / v.x);

		// get a matrix can rotate edge to horizontal
		b2Mat22 m = b2Mat22(-slop);

		// get endpoints of edge after rotated
		b2Vec2 mv1 = b2Mul(m, v1);
		b2Vec2 mv2 = b2Mul(m, v2);

		// get edge length
		float length = v.Length();

		// get distance from origin to this edge
		float u = (-mv1.x * (mv2.x - mv1.x) + -mv1.y * (mv2.y - mv1.y)) / length / length;
		b2Vec2 intersect = b2Vec2(mv1.x + u * (mv2.x - mv1.x), mv1.y + u * (mv2.y - mv1.y));
		float distance = box2d->meter2Pixel(intersect.Length());
		bool above = intersect.y > 0;

		// original vertices
		wyQuad3D vertices = {
			box2d->meter2Pixel(mv1.x), -texRect.height / 2 + (above ? distance : -distance), 0,
			box2d->meter2Pixel(mv2.x), -texRect.height / 2 + (above ? distance : -distance), 0,
			box2d->meter2Pixel(mv1.x), texRect.height / 2 + (above ? distance : -distance), 0,
			box2d->meter2Pixel(mv2.x), texRect.height / 2 + (above ? distance : -distance), 0
		};

		// build transform matrix
		wyAffineTransform t = wyaIdentity;
		wyaTranslate(&t, box2d->meter2Pixel(xf.p.x), box2d->meter2Pixel(xf.p.y));
		wyaRotate(&t, angle + slop);

		// transform vertices
		wyaTransformPoint2(t, vertices.bl_x, vertices.bl_y);
		wyaTransformPoint2(t, vertices.br_x, vertices.br_y);
		wyaTransformPoint2(t, vertices.tl_x, vertices.tl_y);
		wyaTransformPoint2(t, vertices.tr_x, vertices.tr_y);

		// get texture coordinates
		float left = texRect.x / texPixelWidth;
		float right = (texRect.x + texRect.width) / texPixelWidth;
		float top = (texRect.y + texRect.height) / texPixelHeight;
		float bottom = texRect.y / texPixelHeight;
		wyQuad2D texCoords = {
				left, bottom,
				right, bottom,
				left, top,
				right, top
		};

		// append quad
		mesh->appendQuad(texCoords, vertices);
	}
}

void wyBox2DMeshBuilder::updatePolygonMesh(wyShape* mesh, wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect& texRect) {
	// get polygon and transform, compute aabb
	b2PolygonShape* poly = (b2PolygonShape*)f->GetShape();
	b2Body* body = f->GetBody();
	const b2Transform& xf = body->GetTransform();
	b2AABB aabb;
	poly->ComputeAABB(&aabb, b2Transform_identity, 0);
	float shapeW = aabb.upperBound.x - aabb.lowerBound.x;
	float shapeH = aabb.upperBound.y - aabb.lowerBound.y;

	// create vertex and texture array
	int count = poly->m_count;
	float* v = (float*)malloc(count * 2 * sizeof(float));
	float* t = (float*)malloc(count * 2 * sizeof(float));

	// build transform matrix
	wyAffineTransform tf = wyaIdentity;
	wyaTranslate(&tf, box2d->meter2Pixel(xf.p.x), box2d->meter2Pixel(xf.p.y));
	wyaRotate(&tf, xf.q.GetAngle());

	// fill array
	float left = texRect.x / texPixelWidth;
	float bottom = (texRect.y + texRect.height) / texPixelHeight;
	float width = texRect.width / texPixelWidth;
	float height = texRect.height / texPixelHeight;
	for (int i = 0; i < count; i++) {
		v[2 * i] = box2d->meter2Pixel(poly->m_vertices[i].x);
		v[2 * i + 1] = box2d->meter2Pixel(poly->m_vertices[i].y);
		wyaTransformPoint2(tf, v[2 * i], v[2 * i + 1]);

		t[2 * i] = left + width * (poly->m_vertices[i].x - aabb.lowerBound.x) / shapeW;
		t[2 * i + 1] = bottom - height * (poly->m_vertices[i].y - aabb.lowerBound.y) / shapeH;
	}

	// build mesh
	mesh->buildCustom2D(v, t, count, wyMesh::TRIANGLE_FAN);

	// free
	free(v);
	free(t);
}

void wyBox2DMeshBuilder::updateCircleMesh(wyShape* mesh, wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect& texRect) {
	// vertices
	GLfloat vertices[circleVAR_count * 2];
	memcpy(vertices, circleVAR, sizeof(circleVAR));

	// get circle center, radius and axis
	b2CircleShape* circle = (b2CircleShape*)f->GetShape();
	b2Body* body = f->GetBody();
	const b2Transform& xf = body->GetTransform();
	b2Vec2 center = b2Mul(xf, circle->m_p);
	float32 radius = circle->m_radius;
	b2Vec2 axis = xf.q.GetXAxis();

	// the axis is (cos, -sin)
	float angle = acosf(axis.x);
	if(axis.y < 0)
		angle = 2 * M_PI - angle;

	// build transform matrix
	wyAffineTransform t = wyaIdentity;
	wyaTranslate(&t, box2d->meter2Pixel(center.x), box2d->meter2Pixel(center.y));
	wyaRotate(&t, angle);
	wyaScale(&t, box2d->meter2Pixel(radius), box2d->meter2Pixel(radius));

	// transform vertices
	for(int i = 0; i < circleVAR_count * 2; i += 2) {
		wyaTransformPoint2(t, vertices[i], vertices[i + 1]);
	}

	// create tex coords
	GLfloat tex[circleVAR_count * 2];
	float off_s = texRect.x / texPixelWidth;
	float off_t = texRect.y / texPixelHeight;
	float wrap_s = texRect.width / texPixelWidth;
	float wrap_t = texRect.height / texPixelHeight;
	for(int i = 0; i < circleVAR_count * 2; i += 2) {
		tex[i] = off_s + (circleVAR[i] / 2.0f + 0.5f) * wrap_s;
		tex[i + 1] = off_t + (0.5f - circleVAR[i + 1] / 2.0f) * wrap_t;
	}

	// build mesh
	mesh->buildCustom2D(vertices, tex, circleVAR_count, wyMesh::TRIANGLE_FAN);
}

void wyBox2DMeshBuilder::updateMesh(wyMesh* mesh, wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect texRect) {
	switch(f->GetType()) {
		case b2Shape::e_circle:
			updateCircleMesh((wyShape*)mesh, box2d, f, texPixelWidth, texPixelHeight, texRect);
			break;
		case b2Shape::e_edge:
			updateEdgeMesh((wyRectangle*)mesh, box2d, f, texPixelWidth, texPixelHeight, texRect);
			break;
		case b2Shape::e_chain:
			updateChainMesh((wyQuadList*)mesh, box2d, f, texPixelWidth, texPixelHeight, texRect);
			break;
		case b2Shape::e_polygon:
			updatePolygonMesh((wyShape*)mesh, box2d, f, texPixelWidth, texPixelHeight, texRect);
			break;
		default:
			LOGW("wyBox2DMeshBuilder::createMesh: Unknown fixture shape type: %d", f->GetType());
			break;
	}
}
