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
#include "wyRenderTexture.h"
#include "wyPrimitives.h"
#include <stdlib.h>
#include "wyUtils.h"
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyDirector.h"

void wyRenderTexture::draw() {
	// if no draw flag is set, call wyNode::draw and it
	// will decide forward drawing to java layer or not
	if(m_noDraw) {
		wyNode::draw();
		return;
	}

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_TEXTURE_2D);

    glColor4f(m_color.r / 255.0f, m_color.g / 255.0f, m_color.b / 255.0f, m_color.a / 255.0f);

    bool newBlend = false;
    if (m_blendFunc.src != DEFAULT_BLEND_SRC || m_blendFunc.dst != DEFAULT_BLEND_DST) {
        newBlend = true;
        glBlendFunc(m_blendFunc.src, m_blendFunc.dst);
    }

    // need flip y axis because opengl texture starts from bottom
	if (m_texture != 0) {
		wyDrawTexture(m_texture,
				m_texWidth,
				m_texHeight,
				0,
				0,
				m_width,
				m_height,
				false,
				true);
	}

    if (newBlend)
        glBlendFunc(DEFAULT_BLEND_SRC, DEFAULT_BLEND_DST);

    // is this cheaper than saving/restoring color state ?
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

wyColor3B wyRenderTexture::getColor() {
	wyColor3B c = {
		m_color.r,
		m_color.g,
		m_color.b
	};
	return c;
}

void wyRenderTexture::setColor(wyColor3B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
}

void wyRenderTexture::setColor(wyColor4B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_color.a = color.a;
}

wyRenderTexture::~wyRenderTexture() {
	releaseBuffer();
	releaseTexture();
}

wyRenderTexture::wyRenderTexture(int width, int height) :
		m_needReleaseTexture(true),
		m_texWidth(width),
		m_texHeight(height),
		m_texture(0),
		m_fbo(0),
		m_old_fbo(0),
		m_blendFunc(wybfDefault),
		m_color(wyc4bWhite) {
	// get texture min size
	int w = wyMath::getNextPOT(m_texWidth);
	int h = wyMath::getNextPOT(m_texHeight);

	// create frame buffer
	createFrameBuffer(w, h);

    // set content size
	setContentSize(width, height);
}

wyRenderTexture::wyRenderTexture() :
		m_needReleaseTexture(true),
		m_texWidth(wyDevice::realWidth),
		m_texHeight(wyDevice::realHeight),
		m_texture(0),
		m_fbo(0),
		m_old_fbo(0),
		m_blendFunc(wybfDefault),
		m_color(wyc4bWhite) {
	// get texture min size
	int w = wyMath::getNextPOT(m_texWidth);
	int h = wyMath::getNextPOT(m_texHeight);

	// create frame buffer
	createFrameBuffer(w, h);

    // set content size
	setContentSize(wyDevice::winWidth, wyDevice::winHeight);
}

void wyRenderTexture::createFrameBuffer(int w, int h) {
	// create texture
	glGenTextures(1, (GLuint*)&m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	// apply texture parameters
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// allocate buffer and create texture from it
	GLvoid* pixels = (GLvoid*)wyCalloc(w * h * 4, sizeof(GLubyte));
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	wyFree(pixels);

	// generate a new frame buffer
	glGenFramebuffersOES(1, (GLuint*)&m_fbo);

	// get old frame buffer object
	glGetIntegerv(GL_FRAMEBUFFER_BINDING_OES, (GLint*)&m_old_fbo);

	// bind
	glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_fbo);

	// associate texture with FBO
	glFramebufferTexture2DOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_TEXTURE_2D, m_texture, 0);

	// restore old buffer
	glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_old_fbo);
}

wyRenderTexture* wyRenderTexture::make(int width, int height) {
	wyRenderTexture* n = WYNEW wyRenderTexture(width, height);
	return (wyRenderTexture*)n->autoRelease();
}

wyRenderTexture* wyRenderTexture::make() {
	wyRenderTexture* n = WYNEW wyRenderTexture();
	return (wyRenderTexture*)n->autoRelease();
}

void wyRenderTexture::clear(float r, float g, float b, float a) {
	beginRender(r, g, b, a);
	endRender();
}

void wyRenderTexture::beginRender(float r, float g, float b, float a) {
	// begin rendering
	beginRender();

	// get old clear color
	GLfloat	clearColor[4];
	glGetFloatv(GL_COLOR_CLEAR_VALUE, clearColor);

	// clear
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// restore clear color
	glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
}

void wyRenderTexture::beginRender() {
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

	// bind buffer
	glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_fbo);
}

void wyRenderTexture::endRender() {
	// bind buffer
	glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_old_fbo);

	// pop matrix
	glPopMatrix();

	// restore viewport
	glViewport(0, 0, wyDevice::realWidth, wyDevice::realHeight);
}

void wyRenderTexture::releaseBuffer() {
	// delete custom frame buffer
	if(m_fbo != 0) {
		glDeleteFramebuffersOES(1, (GLuint*)&m_fbo);
		m_fbo = 0;
	}

	// reset old frame buffer object
	m_old_fbo = 0;
}

void wyRenderTexture::releaseTexture() {
	// delete texture
	if(m_texture != 0 && m_needReleaseTexture && wyDirector::getInstance()->isSurfaceCreated()) {
		glDeleteTextures(1, (GLuint*)&m_texture);
		m_texture = 0;
	}
}

wyTexture2D* wyRenderTexture::createTexture() {
	m_needReleaseTexture = false;
	return wyTexture2D::makeGL(m_texture, m_texWidth, m_texHeight);
}
