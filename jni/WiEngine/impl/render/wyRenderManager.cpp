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
#include "wyRenderManager.h"
#include "wyRenderer.h"
#include "wyGlobal.h"
#include "wyMesh.h"
#include "wyMaterial.h"
#include "wyNode.h"
#include "wyTechnique.h"
#include "wyShaderProgram.h"

wyRenderManager::wyRenderManager(wyRenderer* renderer) :
		m_camera(NULL) {
	// save renderer
	m_renderer = renderer;
	wyObjectRetain(m_renderer);

	// init viewport list
	m_viewports = WYNEW vector<wyViewport*>();
	m_viewports->reserve(5);
	m_postViewports = WYNEW vector<wyViewport*>();
	m_postViewports->reserve(5);
}

wyRenderManager::~wyRenderManager() {
	wyObjectRelease(m_renderer);

	for(vector<wyViewport*>::iterator iter = m_viewports->begin(); iter != m_viewports->end(); iter++) {
		wyObjectRelease(*iter);
	}
	WYDELETE(m_viewports);

	for(vector<wyViewport*>::iterator iter = m_postViewports->begin(); iter != m_postViewports->end(); iter++) {
		wyObjectRelease(*iter);
	}
	WYDELETE(m_postViewports);
}

wyRenderManager* wyRenderManager::make(wyRenderer* renderer) {
	wyRenderManager* rm = WYNEW wyRenderManager(renderer);
	return (wyRenderManager*)rm->autoRelease();
}

void wyRenderManager::addViewport(wyViewport* v) {
	if(v) {
		m_viewports->push_back(v);
		v->retain();
	}
}

void wyRenderManager::addPostViewport(wyViewport* v) {
	if(v) {
		m_postViewports->push_back(v);
		v->retain();
	}
}

void wyRenderManager::removeViewport(const char* name) {
	for(vector<wyViewport*>::iterator iter = m_viewports->begin(); iter != m_viewports->end(); ) {
		const char* vname = (*iter)->getName();
		if(vname && !strcmp(name, vname)) {
			(*iter)->release();
			iter = m_viewports->erase(iter);
		} else {
			iter++;
		}
	}
}

void wyRenderManager::updateViewport(wyViewport* v) {
	wyCamera* c = v->getCamera();
	if(m_camera != c) {
		// if current camera is not null, then matrix must be pushed before, so pop
		if(m_camera) {
			// pop matrix
			kmGLMatrixMode(KM_GL_PROJECTION);
			kmGLPopMatrix();
			kmGLMatrixMode(KM_GL_MODELVIEW);
			kmGLPopMatrix();
		}

		// push matrix
		kmGLMatrixMode(KM_GL_PROJECTION);
		kmGLPushMatrix();
		kmGLMatrixMode(KM_GL_MODELVIEW);
		kmGLPushMatrix();

		// update viewport range
		wyRect vr = c->getViewportRect();
		m_renderer->setViewport(vr.x, vr.y, vr.width, vr.height);

		// clip to current viewport range
		m_renderer->pushClipRect(vr);

		// multiply camera matrix
		kmGLMatrixMode(KM_GL_PROJECTION);
		kmGLMultMatrix(c->getProjectionMatrix());
		kmGLMatrixMode(KM_GL_MODELVIEW);
		kmGLMultMatrix(c->getViewMatrix());

		// set as current camera
		m_camera = c;
	}
}

void wyRenderManager::render(float delta) {
	// basic check for render
	if(!m_renderer)
		return;

	// render viewport one by one
	for(vector<wyViewport*>::iterator iter = m_viewports->begin(); iter != m_viewports->end(); iter++) {
		renderViewport(*iter, delta);
	}
	for(vector<wyViewport*>::iterator iter = m_postViewports->begin(); iter != m_postViewports->end(); iter++) {
		renderViewport(*iter, delta);
	}
}

void wyRenderManager::renderViewport(wyViewport* v, float delta) {
	// if viewport is not enabled, skip render
	if(!v->isEnabled())
		return;

	// set viewport
	updateViewport(v);

	// check clear flag
	if(v->shouldClearColor() || v->shouldClearDepth() || v->shouldClearStencil()) {
		// if need clear color, set clear color
		if(v->shouldClearColor())
			m_renderer->setBackgroundColor(v->getBackgroundColor());

		// clear
		m_renderer->clearBuffers(v->shouldClearColor(), v->shouldClearDepth(), v->shouldClearStencil());
	}

	// get root node
	wyNode* root = v->getRoot();
	renderScene(root, v);

	// render queues
	flushQueue(v);

	// clear queue
	clearQueue(v);

	// pop view port clip
	m_renderer->popClipRect();
}

void wyRenderManager::renderScene(wyNode* node, wyViewport* v) {
	// if node is invisible, just return
	if(!node->isVisible())
		return;

	// push world matrix
	kmGLMatrixMode(KM_GL_WORLD);
	kmGLPushMatrix();

	// multiply current node world matrix
	wyAffineTransform t = node->getTransformMatrix();
	kmMat4 m;
	wyaToGL(t, m.mat);
	m.mat[14] = node->getVertexZ();
	kmGLMultMatrix(&m);

	// if node has camera, apply it
	if(node->hasCamera() && !node->isGridActive()) {
		bool translate = node->getAnchorX() != 0 || node->getAnchorY() != 0;
		if(translate)
			kmGLTranslatef(node->getAnchorX(), node->getAnchorY(), 0);

		kmGLMultMatrix(node->getCamera()->getViewMatrix());

		if(translate)
			kmGLTranslatef(-node->getAnchorX(), -node->getAnchorY(), 0);
	}

	// render children whose z order is less than 0
	int i = 0;
	wyArray* children = node->getChildren();
	if(node->isVisitable()) {
		for(; i < children->num; i++) {
			wyNode* child = (wyNode*)wyArrayGet(children, i);
			if(child->getZOrder() < 0)
				renderScene(child, v);
			else
				break;
		}
	}

	// check node type
	// if geometry, add to render queue
	// if not, check custom render
	if(!node->isGeometry()) {
		// TODO do what if not geometry?
	} else {
		// set calculated world matrix to geometry
		if(!node->isNoDraw()) {
			kmGLGetMatrix(KM_GL_WORLD, &m);
			kmMat4Fill(node->getWorldMatrix(), m.mat);

			// to queue
			v->getQueue()->addToQueue(node, node->getQueueBucket());
		}
	}

	// render children
	if(node->isVisitable()) {
		for(; i < children->num; i++) {
			wyNode* child = (wyNode*)wyArrayGet(children, i);
			renderScene(child, v);
		}
	}

	// pop world matrix
	kmGLMatrixMode(KM_GL_WORLD);
	kmGLPopMatrix();
}

void wyRenderManager::flushQueue(wyViewport* v) {
	wyRenderQueue* queue = v->getQueue();
	bool depthRangeChanged = false;

	// check GUI bucket
	if(!queue->isBucketEmpty(wyRenderQueue::GUI_BUCKET)) {
		m_renderer->setDepthRange(0, 0);
		queue->renderBucket(wyRenderQueue::GUI_BUCKET, this);
		depthRangeChanged = true;
	}

	// need to restore depth range
	if(depthRangeChanged)
		m_renderer->setDepthRange(0, 1);
}

void wyRenderManager::clearQueue(wyViewport* v) {
	v->getQueue()->clear();
}

void wyRenderManager::renderNode(wyNode* g) {
	// push clip rect
	bool clip = g->hasClipRect();
	if(clip) {
		wyRect r = g->getResolvedClipRect();
		m_renderer->pushClipRect(r);
	}

	// check update flag
	if(g->isNeedUpdateMaterial()) {
		g->updateMaterial();
		g->setNeedUpdateMaterial(false);
	}
	if(g->isNeedUpdateMesh()) {
		g->updateMesh();
		g->setNeedUpdateMesh(false);
	}
	if(g->isNeedUpdateMeshColor()) {
		g->updateMeshColor();
		g->setNeedUpdateMeshColor(false);
	}

	// before render notify
	g->beforeRender();

	// render every material
	int c = g->getRenderPairCount();
	for(int i = 0; i < c; i++) {
		wyMaterial* material = g->getMaterial(i);
		wyMesh* mesh = g->getMesh(i);

		// get technique and shader programe
		wyTechnique* tech = material->getTechnique();
		wyShaderProgram* program = tech->getShaderProgram();
		if(!tech || !program)
			continue;

		// apply render state
		wyRenderState* rs = tech->getRenderState();
		m_renderer->applyRenderState(rs);

		// update general uniform
		updateUniformValues(program, g);

		// apply material parameters
		map<unsigned int, wyMaterialParameter*>* matParams = material->getParameters();
		for(map<unsigned int, wyMaterialParameter*>::iterator iter = matParams->begin(); iter != matParams->end(); iter++) {
			iter->second->apply(m_renderer, tech);
		}

		// enable shader program in renderer
		m_renderer->setShaderProgram(program);

		// start to render mesh
		m_renderer->renderMesh(mesh, g->getLodLevel(i));
	}

	// pop clip
	if(clip)
		m_renderer->popClipRect();
}

void wyRenderManager::updateUniformValues(wyShaderProgram* p, wyNode* g) {
	WY_UNIFORM_MAP* uniforms = p->getUniforms();
	for(WY_UNIFORM_ITER iter = uniforms->begin(); iter != uniforms->end(); iter++) {
		// get uniform, mark it is set first
		wyUniform* uniform = iter->second;
		wyShaderVariable::Value value;
		bool set = true;

		// check binding type
		switch(uniform->getBinding()) {
			case wyUniform::WORLD_MATRIX:
				kmMat4Fill(&value.m4, g->getWorldMatrix()->mat);
				break;
			case wyUniform::VIEW_MATRIX:
				kmGLGetMatrix(KM_GL_MODELVIEW, &value.m4);
				break;
			case wyUniform::PROJECTION_MATRIX:
				kmGLGetMatrix(KM_GL_PROJECTION, &value.m4);
				break;
			case wyUniform::WORLD_VIEW_MATRIX:
			{
				kmMat4 m;
				kmGLGetMatrix(KM_GL_MODELVIEW, &m);
				kmMat4Multiply(&m, &m, g->getWorldMatrix());
				kmMat4Fill(&value.m4, m.mat);
				break;
			}
			case wyUniform::NORMAL_MATRIX:
				break;
			case wyUniform::WORLD_VIEW_PROJECTION_MATRIX:
			{
				// we need reverse the multiply order because MVP * v != PVM * v
				kmMat4 m1, m2;
				kmGLGetMatrix(KM_GL_PROJECTION, &m1);
				kmGLGetMatrix(KM_GL_MODELVIEW, &m2);
				kmMat4Multiply(&m1, &m1, &m2);
				kmMat4Multiply(&m1, &m1, g->getWorldMatrix());
				kmMat4Fill(&value.m4, m1.mat);
				break;
			}
			case wyUniform::VIEW_PROJECTION_MATRIX:
			{
				kmMat4 m1, m2;
				kmGLGetMatrix(KM_GL_PROJECTION, &m1);
				kmGLGetMatrix(KM_GL_MODELVIEW, &m2);
				kmMat4Multiply(&m1, &m1, &m2);
				kmMat4Fill(&value.m4, m1.mat);
				break;
			}
			default:
				// for any binding we can't set it here, clear the set flag
				set = false;
				break;
		}

		// if set, pass the value to it
		if(set)
			uniform->setValue(value);
		else
			uniform->clearValue();
	}
}

void wyRenderManager::renderMaterial(wyNode* space, wyMaterial* material, wyMesh* mesh) {
	// basic checking
	if(!space || !material || !mesh)
		return;

	// apply render state
	wyTechnique* tech = material->getTechnique();
	wyRenderer* r = getRenderer();
	wyShaderProgram* program = tech->getShaderProgram();

	// apply render state
	wyRenderState* rs = tech->getRenderState();
	r->applyRenderState(rs);

	// update general uniform
	updateUniformValues(program, space);

	// apply material parameters
	map<unsigned int, wyMaterialParameter*>* matParams = material->getParameters();
	for(map<unsigned int, wyMaterialParameter*>::iterator iter = matParams->begin(); iter != matParams->end(); iter++) {
		iter->second->apply(r, tech);
	}

	// enable shader program in renderer
	r->setShaderProgram(program);

	// start to render mesh
	r->renderMesh(mesh, 0);
}
