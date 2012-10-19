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
#include "wyGLES2Renderer.h"
#include "wyGlobal.h"
#include "wyLog.h"
#include "wyDirector.h"

wyGLES2Renderer::wyGLES2Renderer() :
		m_useVBO(false),
		m_clipStack((wyRect*)wyMalloc(10 * sizeof(wyRect))),
		m_clipStackCount(0),
		m_clipStackCapacity(10) {
	m_state = wyGLState::make();
	m_state->retain();
}

wyGLES2Renderer::~wyGLES2Renderer() {
	wyFree(m_clipStack);
	m_state->release();
}

wyGLES2Renderer* wyGLES2Renderer::make() {
	wyGLES2Renderer* r = WYNEW wyGLES2Renderer();
	return (wyGLES2Renderer*)r->autoRelease();
}

void wyGLES2Renderer::setBackgroundColor(wyColor4B color) {
	glClearColor(color.r / 255.f, color.g / 255.f, color.b / 255.f, color.a / 255.f);
}

void wyGLES2Renderer::clearBuffers(bool color, bool depth, bool stencil) {
    int bits = 0;

    // check color flag
	if(color) {
		// See explanations of the depth below, we must enable color write to be able to clear the color buffer
		if(!m_state->colorWriteEnabled) {
			glColorMask(true, true, true, true);
			m_state->colorWriteEnabled = true;
		}
		bits = GL_COLOR_BUFFER_BIT;
	}

	// check depth flag
	if(depth) {
		// glClear(GL_DEPTH_BUFFER_BIT) seems to not work when glDepthMask is false
		// here s some link on opengl board
		// http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showflat&Number=257223
		// if depth clear is requested, we enable the depthMask
		if(!m_state->depthWriteEnabled) {
			glDepthMask(true);
			m_state->depthWriteEnabled = true;
		}
		bits |= GL_DEPTH_BUFFER_BIT;
	}

	// check stencil flag
	if(stencil) {
		bits |= GL_STENCIL_BUFFER_BIT;
	}

	// clear if bit is set
	if(bits != 0) {
		glClear(bits);
	}
}

void wyGLES2Renderer::setViewport(float x, float y, float w, float h) {
    if (m_state->viewportX != x || m_state->viewportY != y || m_state->viewportWidth != w || m_state->viewportHeight != h) {
        glViewport(x, y, w, h);
        m_state->viewportX = x;
        m_state->viewportY = y;
        m_state->viewportWidth = w;
        m_state->viewportHeight = h;
    }
}

void wyGLES2Renderer::pushClipRect(wyRect& r) {
	// ensure capacity
	while(m_clipStackCount >= m_clipStackCapacity) {
		m_clipStackCapacity *= 2;
		m_clipStack = (wyRect*)wyRealloc(m_clipStack, m_clipStackCapacity * sizeof(wyRect));
	}

	// enable scissor if this is first clip rect
	if(m_clipStackCount == 0) {
	    if (!m_state->clipEnabled) {
	        glEnable(GL_SCISSOR_TEST);
	        m_state->clipEnabled = true;
	    }
	}

	// push clip rect
	m_clipStack[m_clipStackCount++] = r;

	// enable clip
    if (!wyrEquals(m_state->clipRect, r)) {
        glScissor(r.x, r.y, r.width, r.height);
        m_state->clipRect = r;
    }
}

void wyGLES2Renderer::popClipRect() {
	// check count
	if(m_clipStackCount <= 0)
		return;

	// decrease count
	m_clipStackCount--;

	// if this is last clip rect
	if(m_clipStackCount == 0) {
		if (m_state->clipEnabled) {
			glDisable(GL_SCISSOR_TEST);
			m_state->clipEnabled = false;
		}
	} else {
		// enable previous rect
		if(!wyrEquals(m_state->clipRect, m_clipStack[m_clipStackCount - 1])) {
			glScissor(m_clipStack[m_clipStackCount - 1].x,
					m_clipStack[m_clipStackCount - 1].y,
					m_clipStack[m_clipStackCount - 1].width,
					m_clipStack[m_clipStackCount - 1].height);
			m_state->clipRect = m_clipStack[m_clipStackCount - 1];
		}
	}
}

void wyGLES2Renderer::setDepthRange(float start, float end) {
	glDepthRangef(start, end);
}

void wyGLES2Renderer::applyRenderState(wyRenderState* rs) {
	// do null checking
	if(!rs)
		return;

	// depth test
	if(m_state->depthTestEnabled != rs->depthTestEnabled) {
		if(rs->depthTestEnabled) {
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LEQUAL);
		} else {
			glDisable(GL_DEPTH_TEST);
		}

		m_state->depthTestEnabled = rs->depthTestEnabled;
	}

	// depth write
	if(m_state->depthWriteEnabled != rs->depthWriteEnabled) {
		glDepthMask(rs->depthWriteEnabled);
		m_state->depthWriteEnabled = rs->depthWriteEnabled;
	}

	// dither
	if(m_state->ditherEnabled != rs->ditherEnabled) {
		if(rs->ditherEnabled) {
			glEnable(GL_DITHER);
		} else {
			glDisable(GL_DITHER);
		}

		m_state->ditherEnabled = rs->ditherEnabled;
	}

	// color write
	if(m_state->colorWriteEnabled != rs->colorWriteEnabled) {
		glColorMask(rs->colorWriteEnabled, rs->colorWriteEnabled, rs->colorWriteEnabled, rs->colorWriteEnabled);
		m_state->colorWriteEnabled = rs->colorWriteEnabled;
	}

	// face culling
	if(m_state->cullMode != rs->cullMode) {
		if(rs->cullMode == wyRenderState::NO_CULL) {
			glDisable(GL_CULL_FACE);
		} else {
			glEnable(GL_CULL_FACE);
			switch(rs->cullMode) {
				case wyRenderState::FRONT:
					glCullFace(GL_FRONT);
					break;
				case wyRenderState::BACK:
					glCullFace(GL_BACK);
					break;
				case wyRenderState::BOTH:
					glCullFace(GL_FRONT_AND_BACK);
					break;
			}
		}

		m_state->cullMode = rs->cullMode;
	}

	// blending
	if(m_state->blendMode != rs->blendMode) {
		if(rs->blendMode == wyRenderState::NO_BLEND) {
			glDisable(GL_BLEND);
		} else {
			glEnable(GL_BLEND);
			switch(rs->blendMode) {
				case wyRenderState::ADDITIVE:
					glBlendFunc(GL_ONE, GL_ONE);
					break;
				case wyRenderState::PREMULTIPLIED_ALPHA:
					glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
					break;
				case wyRenderState::ALPHA_ADDITIVE:
					glBlendFunc(GL_SRC_ALPHA, GL_ONE);
					break;
				case wyRenderState::COLOR:
					glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);
					break;
				case wyRenderState::ALPHA:
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					break;
				case wyRenderState::MODULATE:
					glBlendFunc(GL_DST_COLOR, GL_ZERO);
					break;
				case wyRenderState::MODULATE_X2:
					glBlendFunc(GL_DST_COLOR, GL_SRC_COLOR);
					break;
			}
		}

		m_state->blendMode = rs->blendMode;
	}
}

void wyGLES2Renderer::setShaderProgram(wyShaderProgram* program) {
	// use program and save it in state
	if(!program) {
		glUseProgram(0);
		m_state->activeProgram = NULL;
	} else {
		if(m_state->activeProgram == NULL || m_state->activeProgram->getProgram() != program->getProgram()) {
			glUseProgram(program->getProgram());
			m_state->activeProgram = program;
		}

		// bind all uniforms
		WY_UNIFORM_MAP* uniforms = program->getUniforms();
		for(WY_UNIFORM_ITER iter = uniforms->begin(); iter != uniforms->end(); iter++) {
			wyUniform* uniform = iter->second;

			// if uniform is not dirty, no need set
			if(!uniform->isNeedSync())
				continue;

			// set uniform
			const wyShaderVariable::Value& v = uniform->getValue();
			GLint loc = uniform->getLocation();
			switch(uniform->getType()) {
				case wyShaderVariable::BOOLEAN:
					glUniform1i(loc, v.b ? GL_TRUE : GL_FALSE);
					break;
				case wyShaderVariable::INT:
				case wyShaderVariable::TEXTURE_2D:
				case wyShaderVariable::TEXTURE_3D:
				case wyShaderVariable::TEXTURE_CUBEMAP:
					glUniform1i(loc, v.i);
					break;
				case wyShaderVariable::FLOAT:
					glUniform1f(loc, v.f);
					break;
				case wyShaderVariable::VEC2:
					glUniform2fv(loc, 1, (const GLfloat*)&v.v2);
					break;
				case wyShaderVariable::VEC3:
					glUniform3fv(loc, 1, (const GLfloat*)&v.v3);
					break;
				case wyShaderVariable::VEC4:
					glUniform4fv(loc, 1, (const GLfloat*)&v.v4);
					break;
				case wyShaderVariable::MAT3:
					glUniformMatrix3fv(loc, 1, false, v.m3.mat);
					break;
				case wyShaderVariable::MAT4:
					glUniformMatrix4fv(loc, 1, false, v.m4.mat);
					break;
				case wyShaderVariable::FLOAT_ARRAY:
					glUniform1fv(loc, v.a.size, v.a.p);
					break;
				case wyShaderVariable::VEC2_ARRAY:
					glUniform2fv(loc, v.a.size / 2, v.a.p);
					break;
				case wyShaderVariable::VEC3_ARRAY:
					glUniform2fv(loc, v.a.size / 3, v.a.p);
					break;
				case wyShaderVariable::VEC4_ARRAY:
					glUniform2fv(loc, v.a.size / 4, v.a.p);
					break;
				case wyShaderVariable::MAT3_ARRAY:
					glUniformMatrix3fv(loc, v.a.size / 9, false, v.a.p);
					break;
				case wyShaderVariable::MAT4_ARRAY:
					glUniformMatrix4fv(loc, v.a.size / 16, false, v.a.p);
					break;
				default:
					LOGW("wyGLES2Renderer::setShaderProgram: Unknown shader variable type: %d", uniform->getType());
					break;
			}

			// clear sync flag
			uniform->setNeedSync(false);
		}
	}
}

void wyGLES2Renderer::setTexture(int unit, wyTexture2D* tex) {
	// null check
	if(!tex)
		return;

	// ensure this texture is loaded
	tex->load();

	// active texture unit
	if(m_state->activeTextureUnit != unit) {
		glActiveTexture(GL_TEXTURE0 + unit);
		m_state->activeTextureUnit = unit;
	}

	// bind texture
	if(m_state->boundTextures[unit] != tex->getTexture()) {
		glBindTexture(GL_TEXTURE_2D, tex->getTexture());
		m_state->boundTextures[unit] = tex->getTexture();
	}

	// apply texture parameters
	tex->applyParameters();
}

void wyGLES2Renderer::onSurfaceCreated() {
}

void wyGLES2Renderer::onSurfaceDestroyed() {
	m_state->reset();
}

void wyGLES2Renderer::renderMesh(wyMesh* mesh, int lodLevel) {
	// check point size, and line width
	switch(mesh->getMode()) {
		case wyMesh::POINTS:
		{
			// try to find point size uniform and set it
			WY_UNIFORM_MAP* uniforms = m_state->activeProgram->getUniforms();
			WY_UNIFORM_ITER iter = uniforms->find(wyUniform::NAME[wyUniform::POINT_SIZE]);
			if(iter != uniforms->end()) {
				// sync value to uniform
				wyShaderVariable::Value v;
				v.f = mesh->getPointSize();
				iter->second->setValue(v);

				// send it to opengl
				GLint loc = iter->second->getLocation();
				glUniform1f(loc, v.f);

				// clear need sync flag
				iter->second->setNeedSync(false);
			}

			// save point size in state
			if(m_state->pointSize != mesh->getPointSize()) {
				m_state->pointSize = mesh->getPointSize();
			}
			break;
		}
		case wyMesh::LINES:
		case wyMesh::LINE_STRIP:
		case wyMesh::LINE_LOOP:
			if(m_state->lineWidth != mesh->getLineWidth()) {
	            glLineWidth(mesh->getLineWidth());
	            m_state->lineWidth = mesh->getLineWidth();
			}
			break;
	}

	// now render
	if(m_useVBO) {
		renderMeshVBO(mesh, lodLevel);
	} else {
		renderMeshDefault(mesh, lodLevel);
	}
}

void wyGLES2Renderer::renderMeshVBO(wyMesh* mesh, int lodLevel) {
	// TODO
}

void wyGLES2Renderer::renderMeshDefault(wyMesh* mesh, int lodLevel) {
	// bind attributes
	bindMeshAttributes(mesh);

	// get indices with specified level of detail
	wyBuffer* indices = NULL;
	if(mesh->getNumberOfLodLevel() > 0)
		indices = mesh->getLodLevelBuffer(lodLevel);

	// draw with or without indices
	if(indices) {
		glDrawElements(GL_TRIANGLES, indices->getElementCount(), GL_UNSIGNED_SHORT, indices->getData());
	} else {
		glDrawArrays(meshModeToGL(mesh->getMode()), 0, mesh->getElementCount());
	}
}

void wyGLES2Renderer::bindMeshAttributes(wyMesh* mesh) {
	vector<wyMesh::AttributeConnection*>* conns = mesh->getConnections();
	for(vector<wyMesh::AttributeConnection*>::iterator iter = conns->begin(); iter != conns->end(); iter++) {
		wyMesh::AttributeConnection* conn = *iter;

		// get attribute, if NULL, next
		wyAttribute* attr = m_state->activeProgram->getAttribute(conn->name);
		if(!attr)
			continue;

		// get location
		int loc = attr->getLocation();

		// value
		wyShaderVariable::Value& v = conn->value;

		// check attribute value type
		switch(conn->type) {
			case wyShaderVariable::FLOAT:
				glVertexAttrib1f(loc, v.f);
				break;
			case wyShaderVariable::VEC2:
				glVertexAttrib2fv(loc, (const GLfloat*)&v.v2);
				break;
			case wyShaderVariable::VEC3:
				glVertexAttrib3fv(loc, (const GLfloat*)&v.v3);
				break;
			case wyShaderVariable::VEC4:
				glVertexAttrib4fv(loc, (const GLfloat*)&v.v4);
				break;
			case wyShaderVariable::INTERLEAVED_BUFFER:
			{
				// buffer
				wyBuffer* buf = v.ib.buf;

				// bind
				if(m_state->getAttributeVertexPointer(loc) != buf) {
					// bind pointer
					glVertexAttribPointer(loc,
							v.ib.components,
							bufferFormatToGL(buf->getFormat()),
							GL_FALSE,
							buf->getBytePerElement(),
							(char*)buf->getData() + v.ib.offset);

					// cache state
					(*(m_state->attribBoundBuffers))[loc] = buf;
				}

				// enable vertex attrib array
				if(!m_state->isAttributeVertexArrayEnabled(loc)) {
					glEnableVertexAttribArray(loc);
					(*(m_state->attribEnableMap))[loc] = true;
				}

				break;
			}
		}
	}
}

GLenum wyGLES2Renderer::meshModeToGL(wyMesh::Mode m) {
    switch (m) {
        case wyMesh::POINTS:
            return GL_POINTS;
        case wyMesh::LINES:
            return GL_LINES;
        case wyMesh::LINE_LOOP:
            return GL_LINE_LOOP;
        case wyMesh::LINE_STRIP:
            return GL_LINE_STRIP;
        case wyMesh::TRIANGLES:
            return GL_TRIANGLES;
        case wyMesh::TRIANGLE_FAN:
            return GL_TRIANGLE_FAN;
        case wyMesh::TRIANGLE_STRIP:
            return GL_TRIANGLE_STRIP;
        default:
        	return GL_TRIANGLES;
    }
}

GLenum wyGLES2Renderer::bufferFormatToGL(wyBuffer::Format f) {
	switch(f) {
		case wyBuffer::FLOAT:
			return GL_FLOAT;
		case wyBuffer::UNSIGNED_BYTE:
			return GL_UNSIGNED_BYTE;
		case wyBuffer::UNSIGNED_SHORT:
			return GL_UNSIGNED_SHORT;
		default:
			return GL_FLOAT;
	}
}

int wyGLES2Renderer::createFrameBuffer(int desiredWidth, int desiredHeight) {
	wyGLState::FrameBuffer fb;

	// get POT size of texture
	int w = wyMath::getNextPOT(desiredWidth);
	int h = wyMath::getNextPOT(desiredHeight);

	// create texture
	glGenTextures(1, (GLuint*)&fb.texture);
	glBindTexture(GL_TEXTURE_2D, fb.texture);

	// apply texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// allocate buffer and create texture from it
	GLvoid* pixels = wyMalloc(sizeof(GLubyte) * w * h * 4);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	wyFree(pixels);

	// if creating texture failed, return 0
	// if successful, create fbo and bind it with texture
	if(fb.texture) {
		// generate a new frame buffer
		glGenFramebuffers(1, (GLuint*)&fb.fbo);

		// get old frame buffer object
		glGetIntegerv(GL_FRAMEBUFFER_BINDING, (GLint*)&fb.oldFBO);

		// bind
		glBindFramebuffer(GL_FRAMEBUFFER, fb.fbo);

		// associate texture with FBO
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fb.texture, 0);

		// get status
		GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

		// restore old buffer
		glBindFramebuffer(GL_FRAMEBUFFER, fb.oldFBO);

		// check status, if ok, add to frame buffer list
		if(status == GL_FRAMEBUFFER_COMPLETE) {
			(*m_state->frameBuffers)[fb.fbo] = fb;
			return fb.fbo;
		} else {
			return -1;
		}
	} else {
		return -1;
	}
}

void wyGLES2Renderer::setFrameBuffer(int fid) {
	// get frame buffer
	wyGLState::FrameBuffer* fb = m_state->getFrameBuffer(fid);
	if(!fb)
		return;

	// get old frame buffer object
	glGetIntegerv(GL_FRAMEBUFFER_BINDING, (GLint*)&fb->oldFBO);

	// bind custom frame buffer
	glBindFramebuffer(GL_FRAMEBUFFER, fb->fbo);
}

void wyGLES2Renderer::restoreFrameBuffer(int fid) {
	// get frame buffer
	wyGLState::FrameBuffer* fb = m_state->getFrameBuffer(fid);
	if(!fb)
		return;

	// to old buffer
	glBindFramebuffer(GL_FRAMEBUFFER, fb->oldFBO);
}

void wyGLES2Renderer::releaseFrameBuffer(int fid) {
	// get frame buffer
	wyGLState::FrameBuffer* fb = m_state->getFrameBuffer(fid);
	if(!fb)
		return;

	// release fbo
	glDeleteFramebuffers(1, (GLuint*)&fb->fbo);

	// delete texture
	if(fb->texture != 0 && wyDirector::getInstance()->isSurfaceCreated()) {
		glDeleteTextures(1, (GLuint*)&fb->texture);
	}

	// remove entry
	m_state->removeFrameBuffer(fid);
}
