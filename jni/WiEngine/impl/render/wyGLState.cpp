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
#include "wyGLState.h"
#include "wyGlobal.h"

wyGLState::wyGLState() {
	// init bound textures array
	glGetIntegerv(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, &maxVertexTextureUnits);
	boundTextures = (GLuint*)wyCalloc(maxVertexTextureUnits, sizeof(GLuint));

	// attribute state cache
	attribBoundBuffers = WYNEW map<int, wyBuffer*>();
	attribEnableMap = WYNEW map<int, bool>();
	frameBuffers = WYNEW map<int, FrameBuffer>();

	// ensure state all clear
	reset();
}

wyGLState::~wyGLState() {
	wyFree(boundTextures);
	WYDELETE(attribBoundBuffers);
	WYDELETE(attribEnableMap);
	WYDELETE(frameBuffers);
}

wyGLState* wyGLState::make() {
	wyGLState* s = WYNEW wyGLState();
	return (wyGLState*)s->autoRelease();
}

void wyGLState::reset() {
	activeProgram = NULL;
	cullMode = wyRenderState::NO_CULL;
	blendMode = wyRenderState::NO_BLEND;
	colorWriteEnabled = true;
	depthWriteEnabled = true;
	depthTestEnabled = false;
	ditherEnabled = false;
	clipEnabled = false;
	clipRect = wyrZero;
	viewportX = 0;
	viewportY = 0;
	viewportWidth = 0;
	viewportHeight = 0;
	activeTextureUnit = -1;
	memset(boundTextures, 0, sizeof(GLuint) * maxVertexTextureUnits);
	pointSize = 1;
	lineWidth = 1;
	attribBoundBuffers->clear();
	attribEnableMap->clear();
}

bool wyGLState::isAttributeVertexArrayEnabled(int loc) {
	map<int, bool>::iterator iter = attribEnableMap->find(loc);
	if(iter != attribEnableMap->end())
		return iter->second;
	else
		return false;
}

wyBuffer* wyGLState::getAttributeVertexPointer(int loc) {
	map<int, wyBuffer*>::iterator iter = attribBoundBuffers->find(loc);
	if(iter != attribBoundBuffers->end())
		return iter->second;
	else
		return NULL;
}

wyGLState::FrameBuffer* wyGLState::getFrameBuffer(int fid) {
	map<int, FrameBuffer>::iterator iter = frameBuffers->find(fid);
	if(iter != frameBuffers->end())
		return &iter->second;
	else
		return NULL;
}

void wyGLState::removeFrameBuffer(int fid) {
	map<int, FrameBuffer>::iterator iter = frameBuffers->find(fid);
	if(iter != frameBuffers->end()) {
		frameBuffers->erase(iter);
	}
}
