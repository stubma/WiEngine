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
#include "wyGrabber.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
#include "wyDirector.h"

wyGrabber::~wyGrabber() {
	releaseBuffer();
}

wyGrabber::wyGrabber() :
		m_texture(0),
		m_texWidth(wyDevice::realWidth),
		m_texHeight(wyDevice::realHeight),
		m_width(wyDevice::winWidth),
		m_height(wyDevice::winHeight),
		m_fbo(0),
		m_old_fbo(0) {
}

wyGrabber::wyGrabber(int width, int height) :
		m_texture(0),
		m_texWidth(width),
		m_texHeight(height),
		m_width(width),
		m_height(height),
		m_fbo(0),
		m_old_fbo(0) {
}

wyGrabber* wyGrabber::make() {
	wyGrabber* g = WYNEW wyGrabber();
	return (wyGrabber*)g->autoRelease();
}

wyGrabber* wyGrabber::make(int width, int height) {
	wyGrabber* g = WYNEW wyGrabber(width, height);
	return (wyGrabber*)g->autoRelease();
}

GLenum wyGrabber::grab() {
	if(m_texture == 0) {
		// get POT size of texture
		int w = wyMath::getNextPOT(m_texWidth);
		int h = wyMath::getNextPOT(m_texHeight);

		// create texture
		int texture;
		glGenTextures(1, (GLuint*)&m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);

		// apply texture parameters
		glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		// allocate buffer and create texture from it
		GLvoid* pixels = wyMalloc(sizeof(GLubyte) * w * h * 4);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
		wyFree(pixels);
	}

	if(m_texture) {
		// generate a new frame buffer
		glGenFramebuffersOES(1, (GLuint*)&m_fbo);

		// get old frame buffer object
		glGetIntegerv(GL_FRAMEBUFFER_BINDING_OES, (GLint*)&m_old_fbo);

		// bind
		glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_fbo);

		// associate texture with FBO
		glFramebufferTexture2DOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_TEXTURE_2D, m_texture, 0);

		// get status
		GLenum status = glCheckFramebufferStatusOES(GL_FRAMEBUFFER_OES);

		// restore old buffer
		glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_old_fbo);

		return status;
	} else {
		return GL_FRAMEBUFFER_UNSUPPORTED_OES;
	}
}

void wyGrabber::beforeRender() {
	// ensure the texture is grabbed
	if(m_texture == 0)
		grab();

	// push matrix
	glPushMatrix();

	// Calculate the adjustment ratios based on the old and new projections
	// Adjust the orthographic propjection and viewport
	float widthRatio = wyDevice::winWidth / m_width;
	float heightRatio = wyDevice::winHeight / m_height;
	glOrthof(-1 / widthRatio, 1 / widthRatio, -1 / heightRatio, 1 / heightRatio, -1, 1);

	// set viewport to real surface size
	glViewport(0, 0, m_texWidth, m_texHeight);

	// get old frame buffer object
	glGetIntegerv(GL_FRAMEBUFFER_BINDING_OES, (GLint*)&m_old_fbo);

	// bind custom frame buffer
	glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_fbo);

	// clear custom frame
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void wyGrabber::afterRender() {
	glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_old_fbo);

	// pop matrix
	glPopMatrix();

	// restore viewport
	glViewport(0, 0, wyDevice::realWidth, wyDevice::realHeight);
}

void wyGrabber::releaseBuffer() {
	// delete custom frame buffer
	if(m_fbo != 0) {
		glDeleteFramebuffersOES(1, (GLuint*)&m_fbo);
		m_fbo = 0;
	}

	// delete texture
	if(m_texture != 0 && wyDirector::getInstance()->isSurfaceCreated()) {
		glDeleteTextures(1, (GLuint*)&m_texture);
		m_texture = 0;
	}

	// reset old frame buffer object
	m_old_fbo = 0;
}
