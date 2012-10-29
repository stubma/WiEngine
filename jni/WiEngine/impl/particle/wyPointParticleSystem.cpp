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
#include "wyPointParticleSystem.h"
#include <stdlib.h>

void wyPointParticleSystem::postStep() {
}

void wyPointParticleSystem::appendParticleQuad(wyParticle* particle, wyPoint newPosition) {
	int index = m_particleIdx;
	m_vertices[index * 2] = newPosition.x;
	m_vertices[index * 2 + 1] = newPosition.y;
	m_colors[index * 4] = particle->color.r;
	m_colors[index * 4 + 1] = particle->color.g;
	m_colors[index * 4 + 2] = particle->color.b;
	m_colors[index * 4 + 3] = particle->color.a;
	m_sizes[index] = particle->size;
}

wyPointParticleSystem::~wyPointParticleSystem() {
	wyFree(m_vertices);
	wyFree(m_colors);
	wyFree(m_sizes);
}

void wyPointParticleSystem::draw() {
	// TODO gles2
//	// if no draw flag is set, call wyNode::draw and it
//	// will decide forward drawing to java layer or not
//	if(m_noDraw) {
//		wyNode::draw();
//		return;
//	}
//
//	if(m_particleIdx == 0)
//		return;
//
//	if(m_tex != NULL) {
//		m_tex->load();
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, m_tex->getTexture());
//	}
//
//	glEnable(GL_POINT_SPRITE_OES);
//	glTexEnvi(GL_POINT_SPRITE_OES, GL_COORD_REPLACE_OES, GL_TRUE);
//
//	glVertexPointer(2, GL_FLOAT, 0, m_vertices);
//	glColorPointer(4, GL_FLOAT, 0, m_colors);
//
//	glEnableClientState(GL_POINT_SIZE_ARRAY_OES);
//	glPointSizePointerOES(GL_FLOAT, 0, m_sizes);
//
//	bool newBlend = false;
//	if(m_blendFunc.src != DEFAULT_BLEND_SRC || m_blendFunc.dst != DEFAULT_BLEND_DST) {
//		newBlend = true;
//		glBlendFunc(m_blendFunc.src, m_blendFunc.dst);
//	}
//
//	glDrawArrays(GL_POINTS, 0, m_particleIdx);
//
//	// restore blend state
//	if(newBlend)
//		glBlendFunc(DEFAULT_BLEND_SRC, DEFAULT_BLEND_DST);
//
//	if(m_tex != NULL) {
//		glDisable(GL_TEXTURE_2D);
//	}
//
//	glDisableClientState(GL_POINT_SIZE_ARRAY_OES);
//	glDisable(GL_POINT_SPRITE_OES);
}

wyPointParticleSystem::wyPointParticleSystem(int numberOfParticles) :
		wyParticleSystem(numberOfParticles),
		m_vertices((GLfloat*)wyMalloc(numberOfParticles * 2 * sizeof(GLfloat))),
		m_colors((GLfloat*)wyMalloc(numberOfParticles * 4 * sizeof(GLfloat))),
		m_sizes((GLfloat*)wyMalloc(numberOfParticles * sizeof(GLfloat))) {
}
