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
#include <stdlib.h>
#include "wyGlobal.h"
#include "wyFrameBuffer.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
#include "wyDirector.h"
#include "wyRenderManager.h"
#include "wyRenderer.h"
#include "wyMaterial.h"

wyFrameBuffer::~wyFrameBuffer() {
	m_camera->release();
	wyObjectRelease(m_material);
	releaseBuffer();
}

wyFrameBuffer::wyFrameBuffer() :
		m_id(-1),
		m_material(NULL),
		m_texWidth(wyDevice::realWidth),
		m_texHeight(wyDevice::realHeight),
		m_width(wyDevice::winWidth),
		m_height(wyDevice::winHeight) {
	initCamera();
}

wyFrameBuffer::wyFrameBuffer(int width, int height) :
		m_id(-1),
		m_material(NULL),
		m_texWidth(width),
		m_texHeight(height),
		m_width(width),
		m_height(height) {
	initCamera();
}

wyFrameBuffer* wyFrameBuffer::make() {
	wyFrameBuffer* g = WYNEW wyFrameBuffer();
	return (wyFrameBuffer*)g->autoRelease();
}

wyFrameBuffer* wyFrameBuffer::make(int width, int height) {
	wyFrameBuffer* g = WYNEW wyFrameBuffer(width, height);
	return (wyFrameBuffer*)g->autoRelease();
}

void wyFrameBuffer::initCamera() {
	// create camera
	m_camera = wyCamera::make();
	m_camera->retain();

	// set projection and viewport
	float widthRatio = wyDevice::winWidth / m_width;
	float heightRatio = wyDevice::winHeight / m_height;
	m_camera->setOrtho(-1 / widthRatio, 1 / widthRatio, -1 / heightRatio, 1 / heightRatio, -1, 1);
}

void wyFrameBuffer::create() {
	// get renderer
	wyDirector* d = wyDirector::getInstance();
	wyRenderManager* rm = d->getRenderManager();
	wyRenderer* r = rm->getRenderer();

	// redirect to renderer
	m_id = r->createFrameBuffer(m_texWidth, m_texHeight);

	// create material
	m_material = wyMaterial::make();
	m_material->retain();

	// set texture
	int t = r->getFrameBufferTexture(m_id);
	wyTexture2D* tex = wyTexture2D::makeGL(t, m_texWidth, m_texHeight);
	wyMaterialTextureParameter* p = wyMaterialTextureParameter::make(wyUniform::NAME[wyUniform::TEXTURE_2D], tex);
	m_material->addParameter(p);

	// set blend mode
	wyRenderState* rs = wyRenderState::make2D();
	rs->blendMode = wyRenderState::ALPHA;
	m_material->getTechnique()->setRenderState(rs);
}

void wyFrameBuffer::beforeRender() {
	// ensure the texture is grabbed
	if(m_id == -1)
		create();

	// get renderer
	wyDirector* d = wyDirector::getInstance();
	wyRenderManager* rm = d->getRenderManager();
	wyRenderer* r = rm->getRenderer();

	// push matrix and reset to identity
	kmGLMatrixMode(KM_GL_PROJECTION);
	kmGLPushMatrix();
	kmGLLoadIdentity();
	kmGLMatrixMode(KM_GL_MODELVIEW);
	kmGLPushMatrix();
	kmGLLoadIdentity();
	kmGLMatrixMode(KM_GL_WORLD);
	kmGLPushMatrix();
	kmGLLoadIdentity();

	// update viewport range
	r->setViewport(0, 0, m_texWidth, m_texHeight);

	// multiply camera matrix
	kmGLMatrixMode(KM_GL_PROJECTION);
	kmGLMultMatrix(m_camera->getProjectionMatrix());

	// switch to frame buffer
	r->setFrameBuffer(m_id);

	// clear custom frame
	wyColor4B oldColor = r->getBackgroundColor();
	r->setBackgroundColor(wyc4bTransparent);
	r->clearBuffers(true, true, false);
	r->setBackgroundColor(oldColor);
}

void wyFrameBuffer::afterRender() {
	// get renderer
	wyDirector* d = wyDirector::getInstance();
	wyRenderManager* rm = d->getRenderManager();
	wyRenderer* r = rm->getRenderer();

	// switch back to old buffer
	r->restoreFrameBuffer(m_id);

	// pop matrix
	kmGLMatrixMode(KM_GL_PROJECTION);
	kmGLPopMatrix();
	kmGLMatrixMode(KM_GL_MODELVIEW);
	kmGLPopMatrix();
	kmGLMatrixMode(KM_GL_WORLD);
	kmGLPopMatrix();

	// restore viewport
	r->setViewport(0, 0, wyDevice::realWidth, wyDevice::realHeight);
}

void wyFrameBuffer::releaseBuffer() {
	// get renderer
	wyDirector* d = wyDirector::getInstance();
	wyRenderManager* rm = d->getRenderManager();
	wyRenderer* r = rm->getRenderer();

	// release it
	r->releaseFrameBuffer(m_id);
}
