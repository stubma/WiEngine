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
#include "wyLog.h"
#include "wyBox2D.h"

wyMesh* wyBox2DMeshBuilder::createMesh(wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect texRect) {
	switch(f->GetType()) {
		case b2Shape::e_circle:
			return createCircleMesh(box2d, f, texPixelWidth, texPixelHeight, texRect);
		case b2Shape::e_edge:
			return createEdgeMesh(box2d, f, texPixelWidth, texPixelHeight, texRect);
		case b2Shape::e_chain:
			return createChainMesh(box2d, f, texPixelWidth, texPixelHeight, texRect);
		case b2Shape::e_polygon:
			return createPolygonMesh(box2d, f, texPixelWidth, texPixelHeight, texRect);
		default:
			LOGW("wyBox2DMeshBuilder::createMesh: Unknown fixture shape type: %d", f->GetType());
			return NULL;
	}
}

wyMesh* wyBox2DMeshBuilder::createEdgeMesh(wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect& texRect) {
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
	GLfloat vertices[12];

	// build transform matrix
	wyAffineTransform t = wyaIdentity;
	wyaTranslate(&t, box2d->meter2Pixel(middle.x), box2d->meter2Pixel(middle.y));
	wyaRotate(&t, angle + atan(v.y / v.x));

	// transform vertices
	wyPoint p = wyp(-length / 2, -texRect.height / 2);
	p = wyaTransformPoint(t, p);
	vertices[0] = p.x;
	vertices[1] = p.y;
	vertices[2] = 0;
	p = wyp(length / 2, -texRect.height / 2);
	p = wyaTransformPoint(t, p);
	vertices[3] = p.x;
	vertices[4] = p.y;
	vertices[5] = 0;
	p = wyp(-length / 2, texRect.height / 2);
	p = wyaTransformPoint(t, p);
	vertices[6] = p.x;
	vertices[7] = p.y;
	vertices[8] = 0;
	p = wyp(length / 2, texRect.height / 2);
	p = wyaTransformPoint(t, p);
	vertices[9] = p.x;
	vertices[10] = p.y;
	vertices[11] = 0;

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

	// create mesh, fill data and return
	wyRectangle* mesh = wyRectangle::make();
	mesh->updateMesh(vertices, texCoords);
	return mesh;
}

wyMesh* wyBox2DMeshBuilder::createChainMesh(wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect& texRect) {
	return NULL;
}

wyMesh* wyBox2DMeshBuilder::createPolygonMesh(wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect& texRect) {
	return NULL;
}

wyMesh* wyBox2DMeshBuilder::createCircleMesh(wyBox2D* box2d, b2Fixture* f, float texPixelWidth, float texPixelHeight, wyRect& texRect) {
	return NULL;
}
