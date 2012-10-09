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
#include "wyQuadParticleSystem.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyTexture2D.h"

void wyQuadParticleSystem::initIndices() {
	for(int i = 0, j = 0; i < m_maxParticles; i++) {
		int i4 = i * 4;
		m_indices[j++] = (GLushort)i4;
		m_indices[j++] = (GLushort)i4 + 1;
		m_indices[j++] = (GLushort)i4 + 2;
		m_indices[j++] = (GLushort)i4 + 1;
		m_indices[j++] = (GLushort)i4 + 2;
		m_indices[j++] = (GLushort)i4 + 3;
	}
}

// rect should be in Texture coordinates, not pixel coordinates
void wyQuadParticleSystem::initTexCoordsWithRect(wyRect rect) {
	float bottomLeftX = rect.x;
	float bottomLeftY = rect.y;

	float bottomRightX = bottomLeftX + rect.width;
	float bottomRightY = bottomLeftY;

	float topLeftX = bottomLeftX;
	float topLeftY = bottomLeftY + rect.height;

	float topRightX = bottomRightX;
	float topRightY = topLeftY;

	for(int i = 0, j = 0; i < m_maxParticles; i++) {
		// bottom-left vertex:
		// remember GL coordinate and android image has different direction
		m_texCoords[j++] = topLeftX;
		m_texCoords[j++] = topLeftY;

		// bottom-right vertex:
		m_texCoords[j++] = topRightX;
		m_texCoords[j++] = topRightY;

		// top-left vertex:
		m_texCoords[j++] = bottomLeftX;
		m_texCoords[j++] = bottomLeftY;

		// top-right vertex:
		m_texCoords[j++] = bottomRightX;
		m_texCoords[j++] = bottomRightY;
	}
}

void wyQuadParticleSystem::postStep() {
}

void wyQuadParticleSystem::updateQuadWithParticle(wyParticle* particle, wyPoint newPosition) {
	int index = m_particleIdx;

	// put bl,br,tl,tr m_colors
	int start = index * 4 * 4;
	m_colors[start++] = particle->color.r;
	m_colors[start++] = particle->color.g;
	m_colors[start++] = particle->color.b;
	m_colors[start++] = particle->color.a;
	m_colors[start++] = particle->color.r;
	m_colors[start++] = particle->color.g;
	m_colors[start++] = particle->color.b;
	m_colors[start++] = particle->color.a;
	m_colors[start++] = particle->color.r;
	m_colors[start++] = particle->color.g;
	m_colors[start++] = particle->color.b;
	m_colors[start++] = particle->color.a;
	m_colors[start++] = particle->color.r;
	m_colors[start++] = particle->color.g;
	m_colors[start++] = particle->color.b;
	m_colors[start++] = particle->color.a;

	// m_vertices
	start = index * 2 * 4;
	float size_2 = particle->size / 2;
	if(particle->rotation != 0) {
		float x1 = -size_2;
		float y1 = -size_2;

		float x2 = size_2;
		float y2 = size_2;
		float x = newPosition.x;
		float y = newPosition.y;

		float r = -wyMath::d2r(particle->rotation);
		float cr = wyMath::cos(r);
		float sr = wyMath::sin(r);
		float ax = x1 * cr - y1 * sr + x;
		float ay = x1 * sr + y1 * cr + y;
		float bx = x2 * cr - y1 * sr + x;
		float by = x2 * sr + y1 * cr + y;
		float cx = x2 * cr - y2 * sr + x;
		float cy = x2 * sr + y2 * cr + y;
		float dx = x1 * cr - y2 * sr + x;
		float dy = x1 * sr + y2 * cr + y;

		// bottom-left
		m_vertices[start++] = ax;
		m_vertices[start++] = ay;

		// bottom-right vertex:
		m_vertices[start++] = bx;
		m_vertices[start++] = by;

		// top-left vertex:
		m_vertices[start++] = dx;
		m_vertices[start++] = dy;

		// top-right vertex:
		m_vertices[start++] = cx;
		m_vertices[start++] = cy;
	} else {
		// bottom-left vertex:
		m_vertices[start++] = newPosition.x - size_2;
		m_vertices[start++] = newPosition.y - size_2;

		// bottom-right vertex:
		m_vertices[start++] = newPosition.x + size_2;
		m_vertices[start++] = newPosition.y - size_2;

		// top-left vertex:
		m_vertices[start++] = newPosition.x - size_2;
		m_vertices[start++] = newPosition.y + size_2;

		// top-right vertex:
		m_vertices[start++] = newPosition.x + size_2;
		m_vertices[start++] = newPosition.y + size_2;
	}
}

wyQuadParticleSystem::~wyQuadParticleSystem() {
	wyFree(m_vertices);
	wyFree(m_colors);
	wyFree(m_texCoords);
	wyFree(m_indices);
}

void wyQuadParticleSystem::draw() {
	// TODO gles2
//	// if no draw flag is set, call wyNode::draw and it
//	// will decide forward drawing to java layer or not
//	if(m_noDraw) {
//		wyNode::draw();
//		return;
//	}
//
//	// Default GL states: GL_TEXTURE_2D, GL_VERTEX_ARRAY, GL_COLOR_ARRAY, GL_TEXTURE_COORD_ARRAY
//	// Needed states: GL_TEXTURE_2D, GL_VERTEX_ARRAY, GL_COLOR_ARRAY, GL_TEXTURE_COORD_ARRAY
//	// Unneeded states: -
//	if(m_tex != NULL) {
//		m_tex->load();
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, m_tex->getTexture());
//	}
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_COLOR_ARRAY);
//	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//
//	// set pointer
//	glVertexPointer(2, GL_FLOAT, 0, m_vertices);
//	glColorPointer(4, GL_FLOAT, 0, m_colors);
//	glTexCoordPointer(2, GL_FLOAT, 0, m_texCoords);
//
//	// set blend
//	bool newBlend = false;
//	if(m_blendFunc.src != DEFAULT_BLEND_SRC || m_blendFunc.dst != DEFAULT_BLEND_DST) {
//		newBlend = true;
//		glBlendFunc(m_blendFunc.src, m_blendFunc.dst);
//	}
//
//	// draw
//	glDrawElements(GL_TRIANGLES, m_particleIdx * 6, GL_UNSIGNED_SHORT, m_indices);
//
//	// restore blend state
//	if(newBlend)
//		glBlendFunc(DEFAULT_BLEND_SRC, DEFAULT_BLEND_DST);
//
//	// restore client state
//	if(m_tex != NULL) {
//		glDisable(GL_TEXTURE_2D);
//	}
//	glDisableClientState(GL_VERTEX_ARRAY);
//	glDisableClientState(GL_COLOR_ARRAY);
//	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void wyQuadParticleSystem::setTexture(wyTexture2D* tex) {
	setTexture(tex, wyr(0, 0, tex->getWidth(), tex->getHeight()));
}

wyQuadParticleSystem::wyQuadParticleSystem(int numberOfParticles) :
		wyParticleSystem(numberOfParticles),
		m_vertices((GLfloat*)wyMalloc(numberOfParticles * 2 * 4 * sizeof(GLfloat))),
		m_colors((GLfloat*)wyMalloc(numberOfParticles * 4 * 4 * sizeof(GLfloat))),
		m_texCoords((GLfloat*)wyMalloc(numberOfParticles * 2 * 4 * sizeof(GLfloat))),
		m_indices((GLushort*)wyMalloc(numberOfParticles * 6 * sizeof(GLushort))) {
	// init m_indices
	initIndices();
	initTexCoordsWithRect(wyr(0, 0, 1, 1));
}

void wyQuadParticleSystem::setTexture(wyTexture2D* tex, wyRect rect) {
	wyParticleSystem::setTexture(tex);

	// convert to tex coords
	float wide = tex->getPixelWidth();
	float high = tex->getPixelHeight();
	rect.x /= wide;
	rect.y /= high;
	rect.width /= wide;
	rect.height /= high;
	initTexCoordsWithRect(rect);
}
