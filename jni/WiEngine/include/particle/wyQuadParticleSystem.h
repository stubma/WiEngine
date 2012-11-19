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
#ifndef __wyQuadParticleSystem_h__
#define __wyQuadParticleSystem_h__

#include "wyParticleSystem.h"
#include "WiEngine-Classes.h"

/**
 * quadrangled particle system, every particle is a quadrangle
 */
class WIENGINE_API wyQuadParticleSystem : public wyParticleSystem {
protected:
	/// texture rect
	wyRect m_texRect;

protected:
	/**
	 * Constructor
	 *
	 * @param numberOfParticles max allowed particle count
	 */
	wyQuadParticleSystem(int numberOfParticles);

	/// @see wyParticleSystem::postStep
	virtual void postStep();
	
	/// @see wyParticleSystem::appendParticleQuad
	virtual void appendParticleQuad(wyParticle* particle, wyPoint newPosition);

public:
	/**
	 * Create a quadrangled particle system
	 *
	 * @param numberOfParticles max number of particles
	 */
	static wyQuadParticleSystem* make(int numberOfParticles);
	
	virtual ~wyQuadParticleSystem();

	/// @see wyNode::updateMesh
	virtual void updateMesh();

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex);

	/**
	 * Set particle texture
	 *
	 * @param tex texture
	 * @param rect texture rect, so you can specify a part of atlas texture used as particle texture
	 */	
	void setTexture(wyTexture2D* tex, wyRect rect);
};

#endif // __wyQuadParticleSystem_h__
