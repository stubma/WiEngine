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
#ifndef __wyBladeRibbon_h__
#define __wyBladeRibbon_h__

#include "wyRibbon.h"

struct wyBlade;

/**
 * to produce a blade effect similar as fruit ninja's
 */
class WIENGINE_API wyBladeRibbon : public wyRibbon {
private:
	/// material
	wyMaterial* m_bladeMat;

	/// to mark the current segment
	wyBlade* m_blade;

	/// segments which will fade out, not include the current segment
	wyArray* m_dyingBlades;

	/// segments which can be reused
	wyArray* m_reusableBlades;

	/// the maximum vertex count, by defulat it is 50
	int m_maxPointCount;

private:
	static bool releaseBlade(wyArray* arr, void* ptr, int index, void* data);

protected:
    /**
     * constructor
     *
     * @param tex \link wyTexture2D wyTexture2D\endlink
     * @param color \link wyColor4B wyColor4B\endlink
     * @param fade time duration of fading out, in seconds. For blade ribbon, it is actually life time because
     * 		blade doesn't fade
	 */
    wyBladeRibbon(wyTexture2D* tex, wyColor4B color, float fade);

public:
    /**
     * fatory function, used to create a new instance with autlRelease enabled
     *
     * @param tex \link wyTexture2D wyTexture2D\endlink
     * @param color \link wyColor4B wyColor4B\endlink
     * @param fade time duration of fading out, in seconds. For blade ribbon, it is actually life time because
     * 		blade doesn't fade
	 */
    static wyBladeRibbon* make(wyTexture2D* tex, wyColor4B color, float fade);

    /**
     * destructor
	 */
    virtual ~wyBladeRibbon();

    /// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex, int index = 0);

	/// @see wyNode::updateMesh
	virtual void updateMesh();

	/**
	 * to be called by the engine, do not call it manually
	 *
	 * @param delta, in seconds, time elapsed since last time this function was entered
	 */
	virtual void update(float delta);

	/**
	 * to add a new vertex
	 *
	 * @param location \link wyPoint wyPoint\endlink
	 */
	virtual void addPoint(wyPoint location);

	/**
	 * clear all points in blade ribbon
	 */
	virtual void reset();

	/**
	 * Set max point allowed in blade ribbon, default value is 50.
	 * The more point allowed, the longer track is.
	 *
	 * @param max max point count
	 */
	void setMaxPointCount(int max);

	/**
	 * get max point allowed in blade ribbon
	 */
	int getMaxPointCount() { return m_maxPointCount; }
};

#endif // __wyBladeRibbon_h__
