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
#include "wyQuadList.h"
#include "wyMaterial.h"

wyQuadParticleSystem::wyQuadParticleSystem(int numberOfParticles) :
		wyParticleSystem(numberOfParticles) {
	// add render pair
	addRenderPair(wyMaterial::make(), wyQuadList::make());

	// set blend mode
	setBlendMode(wyRenderState::ALPHA);
}

wyQuadParticleSystem* wyQuadParticleSystem::make(int numberOfParticles) {
	wyQuadParticleSystem* s = WYNEW wyQuadParticleSystem(numberOfParticles);
	return (wyQuadParticleSystem*)s->autoRelease();
}

void wyQuadParticleSystem::postStep() {
}

void wyQuadParticleSystem::appendParticleQuad(wyParticle* particle, wyPoint newPosition) {
	// quad list
	wyQuadList* mesh = (wyQuadList*)getMesh();

	// vertex color
	wyColor4B c = wyc4b(particle->color.r * 255, particle->color.g * 255, particle->color.b * 255, particle->color.a * 255);

	// tex coordinate
	// remember GL coordinate and android image has different direction
	wyQuad2D t = {
			0, 1,
			1, 1,
			0, 0,
			1, 0
	};

	// m_vertices
	wyQuad3D v;
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
		v.bl_x = ax;
		v.bl_y = ay;
		v.bl_z = 0;

		// bottom-right vertex:
		v.br_x = bx;
		v.br_y = by;
		v.br_z = 0;

		// top-left vertex:
		v.tl_x = dx;
		v.tl_y = dy;
		v.tl_z = 0;

		// top-right vertex:
		v.tr_x = cx;
		v.tr_y = cy;
		v.tr_z = 0;
	} else {
		// bottom-left vertex:
		v.bl_x = newPosition.x - size_2;
		v.bl_y = newPosition.y - size_2;
		v.bl_z = 0;

		// bottom-right vertex:
		v.br_x = newPosition.x + size_2;
		v.br_y = newPosition.y - size_2;
		v.br_z = 0;

		// top-left vertex:
		v.tl_x = newPosition.x - size_2;
		v.tl_y = newPosition.y + size_2;
		v.tl_z = 0;

		// top-right vertex:
		v.tr_x = newPosition.x + size_2;
		v.tr_y = newPosition.y + size_2;
		v.tr_z = 0;
	}

	// update quad
	mesh->appendQuad(t, v, c);
}

wyQuadParticleSystem::~wyQuadParticleSystem() {
}

void wyQuadParticleSystem::updateMesh() {
	// get texture
	wyTexture2D* tex = getTexture();
	if(!tex)
		return;

	// convert to tex coords
	float pW = tex->getPixelWidth();
	float pH = tex->getPixelHeight();
	float x = m_texRect.x / pW;
	float y = m_texRect.y / pH;
	float w = m_texRect.width / pW;
	float h = m_texRect.height / pH;
	wyQuad2D t = {
			x, y + h,
			x + w, y + h,
			x, y,
			x + w, y
	};

	// replace all in mesh
	((wyQuadList*)getMesh())->replaceTexCoord(t);
}

void wyQuadParticleSystem::setTexture(wyTexture2D* tex) {
	setTexture(tex, wyr(0, 0, tex->getWidth(), tex->getHeight()));
}

void wyQuadParticleSystem::setTexture(wyTexture2D* tex, wyRect rect) {
	wyParticleSystem::setTexture(tex);

	// save texture rect
	m_texRect = rect;
}
