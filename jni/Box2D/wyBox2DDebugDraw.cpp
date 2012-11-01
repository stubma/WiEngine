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

#define LINE_COLOR 0.0f, 0.0f, 0.0f, 1.0f

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

wyBox2DDebugDraw::wyBox2DDebugDraw() {
	SetFlags(e_shapeBit | e_jointBit);
}

void wyBox2DDebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	// TODO gles2
//	GLfloat* VAR = (GLfloat*)malloc(vertexCount * 2 * sizeof(GLfloat));
//
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glVertexPointer(2, GL_FLOAT, 0, VAR);
//
//	for (int i = 0; i < vertexCount; i++) {
//		VAR[2 * i] = meter2Pixel(vertices[i].x);
//		VAR[2 * i + 1] = meter2Pixel(vertices[i].y);
//	}
//
//	glColor4f(color.r, color.g, color.b, 1.f);
//	glDrawArrays(GL_LINE_STRIP, 0, vertexCount);
//
//	glDisableClientState(GL_VERTEX_ARRAY);
//
//	free(VAR);
}

void wyBox2DDebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	// TODO gles2
//	GLfloat* VAR = (GLfloat*)malloc((vertexCount + 1) * 2 * sizeof(GLfloat));
//
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glVertexPointer(2, GL_FLOAT, 0, VAR);
//
//	for (int i = 0; i < vertexCount; i++) {
//		VAR[2 * i] = meter2Pixel(vertices[i].x);
//		VAR[2 * i + 1] = meter2Pixel(vertices[i].y);
//	}
//	VAR[2 * vertexCount] = meter2Pixel(vertices[0].x);
//	VAR[2 * vertexCount + 1] = meter2Pixel(vertices[0].y);
//
//	glColor4f(color.r, color.g, color.b, 1.f);
//	glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
//
//	glColor4f(LINE_COLOR);
//	glDrawArrays(GL_LINE_STRIP, 0, vertexCount + 1);
//
//	glDisableClientState(GL_VERTEX_ARRAY);
//
//	free(VAR);
}

void wyBox2DDebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
	// TODO gles2
//	glEnableClientState(GL_VERTEX_ARRAY);
//
//	glVertexPointer(2, GL_FLOAT, 0, circleVAR);
//
//	glPushMatrix();
//	{
//		glTranslatef(meter2Pixel(center.x), meter2Pixel(center.y), 0.0f);
//		glScalef(meter2Pixel(radius), meter2Pixel(radius), 1.0f);
//
//		glColor4f(color.r, color.g, color.b, 1.f);
//		glDrawArrays(GL_LINE_STRIP, 0, circleVAR_count);
//	}
//	glPopMatrix();
//
//	glDisableClientState(GL_VERTEX_ARRAY);
}

void wyBox2DDebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
	// TODO gles2
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glVertexPointer(2, GL_FLOAT, 0, circleVAR);
//
//	glPushMatrix();
//	{
//		// the axis is (cos, -sin)
//		float degree = acosf(axis.x) * 180.f / M_PI;
//		if(axis.y < 0)
//			degree = 360.f - degree;
//
//		glTranslatef(meter2Pixel(center.x), meter2Pixel(center.y), 0.0f);
//		glRotatef(degree, 0.0f, 0.0f, 1.0f);
//		glScalef(meter2Pixel(radius), meter2Pixel(radius), 1.0f);
//
//		glColor4f(color.r, color.g, color.b, 1.f);
//		glDrawArrays(GL_TRIANGLE_FAN, 0, circleVAR_count - 1);
//
//		glColor4f(LINE_COLOR);
//		glDrawArrays(GL_LINE_STRIP, 0, circleVAR_count);
//	}
//	glPopMatrix();
//
//	glDisableClientState(GL_VERTEX_ARRAY);
}

void wyBox2DDebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
	// TODO gles2
//	glLineWidth(1.0f);
//	glColor4f(color.r, color.g, color.b, 1.f);
//	wyDrawLine(meter2Pixel(p1.x), meter2Pixel(p1.y), meter2Pixel(p2.x), meter2Pixel(p2.y));
}

void wyBox2DDebugDraw::DrawTransform(const b2Transform& xf) {
	// we don't draw center of mass
}

void wyBox2DDebugDraw::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color) {
	// TODO gles2
//	glPointSize(size);
//	glColor4f(color.r, color.g, color.b, 1.f);
//	wyDrawPoint(meter2Pixel(p.x), meter2Pixel(p.y));
}
