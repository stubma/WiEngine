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
#ifndef __wyRenderManager_h__
#define __wyRenderManager_h__

#include "wyObject.h"
#include "wyViewport.h"

class wyRenderer;
class wyRenderQueue;
class wyShaderProgram;

/**
 * \c wyRenderManager is a high-level rendering interface that is
 * above renderer implementation. \c wyRenderManager takes care
 * of rendering the scene graphs attached to each viewport
 */
class WIENGINE_API wyRenderManager : public wyObject {
	friend class wyRenderQueue;

private:
	/// renderer
	wyRenderer* m_renderer;

	/// main view port list
	vector<wyViewport*>* m_viewports;

	/// post view port list
	vector<wyViewport*>* m_postViewports;

	/// current camera of viewport
	wyCamera* m_camera;

	/// current world matrix, also known as model matrix
	kmMat4 m_worldMatrix;

	/// curent view matrix
	kmMat4 m_viewMatrix;

	/// current projection matrix
	kmMat4 m_projectionMatrix;

	/// current model-view-projection matrix
	kmMat4 m_MVPMatrix;

protected:
	/**
	 * Constructor
	 *
	 * @param renderer Renderer implementation
	 */
	wyRenderManager(wyRenderer* renderer);

	/**
	 * Render a viewport
	 *
	 * @param v viewport to be rendered
	 * @param delta gap between last frame and now
	 */
	void renderViewport(wyViewport* v, float delta);

	/**
	 * Update viewport
	 *
	 * @param v \link wyViewport wyViewport\endlink
	 */
	void updateViewport(wyViewport* v);

	/**
	 * Render queue of viewport
	 *
	 * @param v viewport
	 */
	void flushQueue(wyViewport* v);

	/**
	 * Clear queue of viewport
	 *
	 * @param v viewport
	 */
	void clearQueue(wyViewport* v);

	/**
	 * Render a single geometry node
	 *
	 * @param g geometry node
	 */
	void renderNode(wyNode* g);

	/**
	 * update uniform value
	 *
	 * @param p shader program
	 */
	void updateUniformValues(wyShaderProgram* p);

public:
	/**
	 * Static constructor
	 *
	 * @param renderer \link wyRenderer wyRenderer\endlink implementation
	 * @return \link wyRenderManager wyRenderManager\endlink
	 */
	static wyRenderManager* make(wyRenderer* renderer);

	virtual ~wyRenderManager();

	/**
	 * Start to render a frame
	 *
	 * @param delta gap between last frame and current frame
	 */
	void render(float delta);

	/**
	 * Render a material in current node space. You must ensure current space
     * is correctly transformed before calling this method
	 *
	 * @param material material to be rendered
	 * @param mesh mesh of this material
	 */
	void renderMaterial(wyMaterial* material, wyMesh* mesh);

	/**
	 * Render from start node recursively
	 *
	 * @param node start node, generally it is the root node of viewport
	 */
	void renderNodeRecursively(wyNode* node);

	/**
	 * Get renderer currently used
	 *
	 * @return \link wyRenderer wyRenderer\endlink implementation
	 */
	wyRenderer* getRenderer() { return m_renderer; }

	/**
	 * Add a main viewport
	 *
	 * @param v \link wyViewport wyViewport\endlink
	 */
	void addViewport(wyViewport* v);

	/**
	 * Add a post viewport
	 *
	 * @param v \link wyViewport wyViewport\endlink
	 */
	void addPostViewport(wyViewport* v);

	/**
	 * Remove a viewport by name, it will search all viewport list and remove a
	 * matched one. If no matched, nothing change
	 *
	 * @param name name of viewport
	 */
	void removeViewport(const char* name);
};

#endif // __wyRenderManager_h__
