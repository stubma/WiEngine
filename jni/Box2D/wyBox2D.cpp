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
#include "wyBox2D.h"
#include "wyPrimitives.h"
#include "wyLog.h"
#include "wyGlobal.h"

#define LINE_COLOR 0.0f, 0.0f, 0.0f, 1.0f

extern void globalJNIInit();

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

class wyBox2DDebugDraw : public b2Draw {
private:
	/// how many pixels for one meter in box2d, by default we treat short edge of screen as 20 meters
	float m_meterPixels;

public:
	wyBox2DDebugDraw();
	virtual ~wyBox2DDebugDraw() {}

	/// Draw a closed polygon provided in CCW order.
	virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

	/// Draw a solid closed polygon provided in CCW order.
	virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

	/// Draw a circle.
	virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);

	/// Draw a solid circle.
	virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);

	/// Draw a line segment.
	virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

	/// Draw a transform. Choose your own length scale.
	/// @param xf a transform.
	virtual void DrawTransform(const b2Transform& xf);

	/// Draw a point
	virtual void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);

	/**
	 * 得到1米对应的像素数
	 *
	 * @return 1米对应的像素数
	 */
	float getMeterPixels() { return m_meterPixels; }

	/**
	 * 设置1米对应的像素数
	 *
	 * @param mp 1米对应的像素数
	 */
	void setMeterPixels(float mp) { m_meterPixels = mp; }

	/**
	 * 根据当前的box2d放缩比例，把像素数转换成米数
	 *
	 * @param pixel 像素数
	 * @return 米数
	 */
	float pixel2Meter(float pixel) { return pixel / m_meterPixels; }

	/**
	 * 根据当前的box2d放缩比例, 把米数转换成像素数
	 *
	 * @param meter 米数
	 * @return 像素数
	 */
	float meter2Pixel(float meter) { return meter * m_meterPixels; }
};

wyBox2DDebugDraw::wyBox2DDebugDraw() {
	SetFlags(e_shapeBit | e_jointBit);
}

void wyBox2DDebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	GLfloat* VAR = (GLfloat*)malloc(vertexCount * 2 * sizeof(GLfloat));

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, VAR);

	for (int i = 0; i < vertexCount; i++) {
		VAR[2 * i] = meter2Pixel(vertices[i].x);
		VAR[2 * i + 1] = meter2Pixel(vertices[i].y);
	}

	glColor4f(color.r, color.g, color.b, 1.f);
	glDrawArrays(GL_LINE_STRIP, 0, vertexCount);

	glDisableClientState(GL_VERTEX_ARRAY);

	free(VAR);
}

void wyBox2DDebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	GLfloat* VAR = (GLfloat*)malloc((vertexCount + 1) * 2 * sizeof(GLfloat));

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, VAR);

	for (int i = 0; i < vertexCount; i++) {
		VAR[2 * i] = meter2Pixel(vertices[i].x);
		VAR[2 * i + 1] = meter2Pixel(vertices[i].y);
	}
	VAR[2 * vertexCount] = meter2Pixel(vertices[0].x);
	VAR[2 * vertexCount + 1] = meter2Pixel(vertices[0].y);

	glColor4f(color.r, color.g, color.b, 1.f);
	glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);

	glColor4f(LINE_COLOR);
	glDrawArrays(GL_LINE_STRIP, 0, vertexCount + 1);

	glDisableClientState(GL_VERTEX_ARRAY);

	free(VAR);
}

void wyBox2DDebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(2, GL_FLOAT, 0, circleVAR);

	glPushMatrix();
	{
		glTranslatef(meter2Pixel(center.x), meter2Pixel(center.y), 0.0f);
		glScalef(meter2Pixel(radius), meter2Pixel(radius), 1.0f);

		glColor4f(color.r, color.g, color.b, 1.f);
		glDrawArrays(GL_LINE_STRIP, 0, circleVAR_count);
	}
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
}

void wyBox2DDebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, circleVAR);

	glPushMatrix();
	{
		// the axis is (cos, -sin)
		float degree = acosf(axis.x) * 180.f / M_PI;
		if(axis.y < 0)
			degree = 360.f - degree;

		glTranslatef(meter2Pixel(center.x), meter2Pixel(center.y), 0.0f);
		glRotatef(degree, 0.0f, 0.0f, 1.0f);
		glScalef(meter2Pixel(radius), meter2Pixel(radius), 1.0f);

		glColor4f(color.r, color.g, color.b, 1.f);
		glDrawArrays(GL_TRIANGLE_FAN, 0, circleVAR_count - 1);

		glColor4f(LINE_COLOR);
		glDrawArrays(GL_LINE_STRIP, 0, circleVAR_count);
	}
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
}

void wyBox2DDebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
	glLineWidth(1.0f);
	glColor4f(color.r, color.g, color.b, 1.f);
	wyDrawLine(meter2Pixel(p1.x), meter2Pixel(p1.y), meter2Pixel(p2.x), meter2Pixel(p2.y));
}

void wyBox2DDebugDraw::DrawTransform(const b2Transform& xf) {
	// we don't draw center of mass
}

void wyBox2DDebugDraw::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color) {
	glPointSize(size);
	glColor4f(color.r, color.g, color.b, 1.f);
	wyDrawPoint(meter2Pixel(p.x), meter2Pixel(p.y));
}

wyBox2D* wyBox2D::make() {
	wyBox2D* box2d = WYNEW wyBox2D();
	return (wyBox2D*)box2d->autoRelease();
}

wyBox2D::wyBox2D() :
		wyNode(),
		m_world(new b2World(b2Vec2(0, 0))),
		m_ddImpl(WYNEW wyBox2DDebugDraw()),
		m_debugDraw(false),
		m_render(NULL) {
	// default meter pixels
	setMeterPixels(MIN(wyDevice::winWidth, wyDevice::winHeight) / 20);

	// set debug draw callback
	m_world->SetDebugDraw(m_ddImpl);
	m_world->SetBox2D(this);

	// common init for android JNI
	globalJNIInit();
}

wyBox2D::~wyBox2D() {
	wyObjectRelease(m_render);
	m_render = NULL;

	delete m_world;
	m_world = NULL;

	WYDELETE(m_ddImpl);
	m_ddImpl = NULL;
}

void wyBox2D::draw() {
	if(m_debugDraw) {
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_POINT_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
		glHint(GL_POINT_SMOOTH_HINT, GL_DONT_CARE);

		m_world->DrawDebugData();

		glDisable(GL_LINE_SMOOTH);
		glDisable(GL_POINT_SMOOTH);
	} else if(m_render != NULL) {
		m_render->drawWorld(this);
	}
}

float wyBox2D::getMeterPixels() {
	return m_ddImpl->getMeterPixels();
}

void wyBox2D::setMeterPixels(float mp) {
	m_ddImpl->setMeterPixels(mp);
}

float wyBox2D::pixel2Meter(float pixel) {
	return m_ddImpl->pixel2Meter(pixel);
}

float wyBox2D::meter2Pixel(float meter) {
	return m_ddImpl->meter2Pixel(meter);
}

void wyBox2D::setBox2DRender(wyBox2DRender* render) {
	if(m_render != NULL)
		m_world->SetDestructionListener(NULL);

	wyObjectRetain(render);
	wyObjectRelease(m_render);
	m_render = render;

	if(render != NULL)
		m_world->SetDestructionListener(render);
}
