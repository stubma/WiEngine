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
#ifndef __wyRenderQueue_h__
#define __wyRenderQueue_h__

#include "wyObject.h"
#include "WiEngine-Classes.h"

/**
 * @class wyRenderQueue
 *
 * Render queue to speed up same type geometry rendering speed, it sorts geometry
 * to keep z order correct
 */
class WIENGINE_API wyRenderQueue : public wyObject {
public:
	/**
	 * Render bucket
	 */
	enum Bucket {
        /**
         * The renderer will try to find the optimal order for rendering all
         * objects using this mode.
         * You should use this mode for most normal objects, except transparent
         * ones, as it could give a nice performance boost to your application.
         */
        OPAQUE_BUCKET,

        /**
         * This is the mode you should use for object with
         * transparency in them. It will ensure the objects furthest away are
         * rendered first. That ensures when another transparent object is drawn on
         * top of previously drawn objects, you can see those (and the object drawn
         * using Opaque) through the transparent parts of the newly drawn
         * object.
         */
        TRANSPARENT_BUCKET,

        /**
         * A special mode used for rendering really far away, flat objects -
         * e.g. skies. In this mode, the depth is set to infinity so
         * nodes in this bucket will appear behind everything, the downside
         * to this bucket is that 3D objects will not be rendered correctly
         * due to lack of depth testing.
         */
        SKY_BUCKET,

        /**
         * A special mode used for rendering transparent objects that
         * should not be effected by scene processor
         * Generally this would contain translucent objects, and
         * also objects that do not write to the depth buffer such as
         * particle emitters.
         */
        TRANSLUCENT_BUCKET,

        /**
         * This is a special mode, for drawing 2D object
         * without perspective (such as GUI or HUD parts).
         * The node's world coordinate system has the range
         * of [0, 0, -1] to [Width, Height, 1] where Width/Height is
         * the resolution of the screen rendered to. Any node
         * outside of that range are culled.
         */
        GUI_BUCKET,

        /**
         * A special mode, that will ensure that this node uses the same
         * mode as the parent Node does.
         */
        INHERIT_BUCKET
	};

private:
	/// render list for gui node
	vector<wyNode*>* m_guiList;

	/// render list for opaque geometry
	vector<wyNode*>* m_opaqueList;

	/// render list for transparent geometry
	vector<wyNode*>* m_transparentList;

	/// render list for sky geometry
	vector<wyNode*>* m_skyList;

	/// render list for translucent geometry
	vector<wyNode*>* m_translucentList;

protected:
	wyRenderQueue();

	/**
	 * Render node list
	 *
	 * @param list vector of node, those nodes should always be geometry node
	 * @param rm \link wyRenderManager wyRenderManager\endlink
	 */
	void renderNodeList(vector<wyNode*>* list, wyRenderManager* rm);

public:
	static wyRenderQueue* make();
	virtual ~wyRenderQueue();

	/**
	 * Adds a node to the given bucket. The \link wyRenderManager wyRenderManager\endlink automatically handles this task
	 * when flattening the scene graph
	 *
	 * @param n The geometry to add
	 * @param bucket The bucket to add to
	 */
	void addToQueue(wyNode* n, Bucket bucket);

	/**
	 * Clear all geometries in all list
	 */
	void clear();

	/**
	 * Check is a bucket empty or not?
	 *
	 * @param bucket bucket type
	 * @return true means bucket is empty
	 */
	bool isBucketEmpty(Bucket bucket);

	/**
	 * Render a bucket
	 *
	 * @param bucket bucket type
	 * @param rm \link wyRenderManager wyRenderManager\endlink
	 */
	void renderBucket(Bucket bucket, wyRenderManager* rm);
};

#endif // __wyRenderQueue_h__
