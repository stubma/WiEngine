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
#include "wyPrimitives.h"
#include <math.h>
#include <stdlib.h>
#include "wyUtils.h"
#include "wyLog.h"
#include "wyGlobal.h"

void wyDrawPoint(float x, float y) {
	float f[2] = { x, y };
	glVertexPointer(2, GL_FLOAT, 0, f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void wyDrawPoints(float* p, size_t length) {
	glVertexPointer(2, GL_FLOAT, 0, p);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_POINTS, 0, length / 2);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void wyDrawLine(float x1, float y1, float x2, float y2) {
	float f[4] = { x1, y1, x2, y2 };
	glVertexPointer(2, GL_FLOAT, 0, f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_LINES, 0, 2);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void wyDrawPath(float* points, size_t length) {
	glVertexPointer(2, GL_FLOAT, 0, points);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_LINE_STRIP, 0, length / 2);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void wyDrawDashPath(float* points, size_t length, float dashLength) {
	for(int i = 0; i < length - 2; i += 2) {
		wyDrawDashLine(points[i], points[i + 1], points[i + 2], points[i + 3], dashLength);
	}
}

void wyDrawDashLine(float x1, float y1, float x2, float y2, float dashLength) {
	float dx = x2 - x1;
	float dy = y2 - y1;
	float dist = wyMath::sqrt(dx * dx + dy * dy);
	float x = dx / dist * dashLength;
	float y = dy / dist * dashLength;

	wyPoint p1 = wyp(x1, y1);
	int segments = (int)(dist / dashLength);
	int lines = (int)((float)segments / 2.0f);

	wyPoint* vertices = (wyPoint*)wyMalloc(sizeof(wyPoint) * segments);
	for(int i = 0; i < lines; i++) {
		vertices[i * 2] = p1;
		p1 = wyp(p1.x + x, p1.y + y);
		vertices[i * 2 + 1] = p1;
		p1 = wyp(p1.x + x, p1.y + y);
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_LINES, 0, segments);
	glDisableClientState(GL_VERTEX_ARRAY);

	wyFree(vertices);
}

void wyDrawPoly(float* p, size_t length, bool close) {
	glVertexPointer(2, GL_FLOAT, 0, p);
	glEnableClientState(GL_VERTEX_ARRAY);

	// GL_LINE_LOOP is very slow in desire HD, so we draw line strip and then draw last close line
	glDrawArrays(GL_LINE_STRIP, 0, length / 2);
	if(close)
		wyDrawLine(p[length - 2], p[length - 1], p[0], p[1]);

	glDisableClientState(GL_VERTEX_ARRAY);
}

void wyDrawRect(float* p) {
	wyDrawPoly(p, 8, true);
}

void wyDrawRect2(wyRect& r) {
	float p[] = {
		r.x, r.y,
		r.x + r.width, r.y,
		r.x + r.width, r.y + r.height,
		r.x, r.y + r.height
	};
	wyDrawPoly(p, 8, true);
}

void wyDrawCircle(float centerX, float centerY, float r, float radiusLineAngle, int segments, bool drawLineToCenter) {
	float* vertices = (float*)wyMalloc(sizeof(float) * 2 * (segments + 2));

	int additionalSegment = 1;
	if(drawLineToCenter)
		additionalSegment++;

	float coef = 2.0f * M_PI / segments;
	float a = radiusLineAngle / 180.0f * M_PI;

	int index = 0;
	for(int i = 0; i <= segments; i++) {
		float rads = i * coef;
		float j = r * cos(rads + a) + centerX;
		float k = r * sin(rads + a) + centerY;

		vertices[index++] = j;
		vertices[index++] = k;
	}
	vertices[index++] = centerX;
	vertices[index++] = centerY;

	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_LINE_STRIP, 0, segments + additionalSegment);
	glDisableClientState(GL_VERTEX_ARRAY);

	wyFree(vertices);
}

void wyDrawSolidCircle(float centerX, float centerY, float r, int segments, wyColor4B color) {
	float* vertices = (float*)wyMalloc(sizeof(float) * 2 * segments);

	int index = 0;
	float coef = 2.0f * M_PI / segments;
	for(int i = 0; i < segments; i++) {
		float rads = i * coef;
		float j = r * cos(rads) + centerX;
		float k = r * sin(rads) + centerY;

		vertices[index++] = j;
		vertices[index++] = k;
	}

	wyDrawSolidPoly(vertices, segments * 2, color);

	wyFree(vertices);
}

void wyDrawBezier(wyBezierConfig& c, int segments) {
	float step = 1.f / segments;
	float t = 0;
	float* vertices = (float*)wyMalloc(sizeof(float) * 2 * (segments + 1));
	for(int i = 0; i <= segments; i++) {
		wyPoint p = wybcPointAt(c, t);
		vertices[i * 2] = p.x;
		vertices[i * 2 + 1] = p.y;
		t += step;
	}

	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_LINE_STRIP, 0, segments + 1);
	glDisableClientState(GL_VERTEX_ARRAY);

	wyFree(vertices);
}

void wyDrawLagrange(wyLagrangeConfig& c, int segments) {
	float step = 1.f / segments;
	float t = 0;
	float* vertices = (float*)wyMalloc(sizeof(float) * 2 * (segments + 1));
	for(int i = 0; i <= segments; i++) {
		wyPoint p = wylcPointAt(c, t);
		vertices[i * 2] = p.x;
		vertices[i * 2 + 1] = p.y;
		t += step;
	}

	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_LINE_STRIP, 0, segments + 1);
	glDisableClientState(GL_VERTEX_ARRAY);

	wyFree(vertices);
}

void wyDrawHypotrochoid(wyHypotrochoidConfig& c, int segments) {
	float step = 1.f / segments;
	float t = 0;
	float* vertices = (float*)wyMalloc(sizeof(float) * 2 * (segments + 1));
	for (int i = 0; i <= segments; i++) {
		wyPoint p = wyhcPointAt(c, t);
		vertices[i * 2] = p.x;
		vertices[i * 2 + 1] = p.y;
		t += step;
	}

	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_LINE_STRIP, 0, segments + 1);
	glDisableClientState(GL_VERTEX_ARRAY);

	wyFree(vertices);
}

void wyDrawTexture(int texture, float texW, float texH, float x, float y, float w, float h, bool flipX, bool flipY) {
	wyRect texRect = {0, 0, texW, texH};
	wyDrawTexture2(texture, texRect, texW, texH, x, y, w, h, flipX, flipY);
}

void wyDrawTexture2(int texture, wyRect texRect, float texW, float texH, float x, float y, float w, float h, bool flipX, bool flipY) {
	// get drawing size
	float potWidth = wyMath::getNextPOT(texW);
	float potHeight = wyMath::getNextPOT(texH);

	// get vertices
	float vertices[] = { x, y, 0.0f, w + x, y, 0.0f, x, h + y, 0.0f, w + x, h + y, 0.0f };

	// get texture coordination
    float left = texRect.x / potWidth;
    float right = (texRect.x + texRect.width) / potWidth;
    float top = texRect.y / potHeight;
    float bottom = (texRect.y + texRect.height) / potHeight;
    float texCoords[] = {
		left, bottom,
		right, bottom,
		left, top,
		right, top
    };
    
	if(flipY) {
		wyUtils::swap(texCoords, 0, 4);
		wyUtils::swap(texCoords, 1, 5);
		wyUtils::swap(texCoords, 2, 6);
		wyUtils::swap(texCoords, 3, 7);
	}
	if(flipX) {
		wyUtils::swap(texCoords, 0, 2);
		wyUtils::swap(texCoords, 1, 3);
		wyUtils::swap(texCoords, 4, 6);
		wyUtils::swap(texCoords, 5, 7);
	}

	// enable states
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);

	// ensure current texture is active
	glBindTexture(GL_TEXTURE_2D, texture);

	// apply texture parameters in both direction
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// set vertices and texture coordination and draw
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	// disable states
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);
}

void wyDrawSolidPoly(float* p, size_t length, wyColor4B color) {
	GLubyte* colors = (GLubyte*) wyMalloc(length * 2 * sizeof(GLubyte));
	for(int i = 0; i < length / 2; i++) {
		colors[i * 4] = color.r;
		colors[i * 4 + 1] = color.g;
		colors[i * 4 + 2] = color.b;
		colors[i * 4 + 3] = color.a;
	}

	glEnableClientState( GL_VERTEX_ARRAY);
	glEnableClientState( GL_COLOR_ARRAY);

	glVertexPointer(2, GL_FLOAT, 0, p);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, colors);

	glDrawArrays(GL_TRIANGLE_FAN, 0, length / 2);

	// Clear the vertex and color arrays
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	wyFree(colors);
}

void wyDrawSolidRect(float* p, wyColor4B color) {
	wyDrawSolidPoly(p, 8, color);
}
