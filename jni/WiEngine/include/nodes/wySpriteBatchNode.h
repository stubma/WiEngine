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
#ifndef __wySpirteBatchNode_h__
#define __wySpirteBatchNode_h__

#include "wyNode.h"
#include "wySpriteEx.h"

class wySpriteEx;
class wyMWSprite;

/**
 * @class wySpriteBatchNode
 *
 * Batch render sprite node, but it only accept \link wySpriteEx wySpriteEx\endlink as
 * child node.
 */
class WIENGINE_API wySpriteBatchNode : public wyNode {
	friend class wySpriteEx;

protected:
	/// the start drawing position when using \c drawFromMarker
	int m_marker;

protected:
	wySpriteBatchNode();

	/// init node
	void init(wyTexture2D* tex);

	/**
	 * Add \link wySpriteEx wySpriteEx\endlink info to underlying atlas. Before this
	 * calling, sprite is already added as child node and assigned an atlas index. This
	 * method does nothing if atlas index is less than zero
	 *
	 * @param sprite \link wySpriteEx wySpriteEx\endlink
	 */
	void addSprite(wySpriteEx* sprite);

	/**
	 * Remove info of a \link wySpriteEx wySpriteEx\endlink from atlas. It does nothing
	 * if atlas index is less than zero
	 *
	 * @param sprite \link wySpriteEx wySpriteEx\endlink
	 */
	void removeSprite(wySpriteEx* sprite);

	/// Remove all managed sprite
	void removeAllSprites();

public:
	/**
	 * Static constructor
	 *
	 * @param tex texture related to this batch node
	 * @return \link wySpriteBatchNode wySpriteBatchNode\endlink
	 */
	static wySpriteBatchNode* make(wyTexture2D* tex);

	/**
	 * Constructor
	 *
	 * @param tex texture related to this batch node
	 */
	wySpriteBatchNode(wyTexture2D* tex);
	
	virtual ~wySpriteBatchNode();

	/// @see wyNode::isVisitable
	virtual bool isVisitable() { return false; }
	
	/// @see wyNode::beforeRender
	virtual void beforeRender();

	/// @see wyNode::updateMesh
	virtual void updateMesh();

	/// @see wyNode::updateMeshColor
	virtual void updateMeshColor();

	/// @see wyNode::addChild(wyNode*, int, int)
	virtual void addChild(wyNode* child, int z, int tag);
	
	/// @see wyNode::removeChild(wyNode*, bool)
	virtual void removeChild(wyNode* child, bool cleanup); 

	/// @see wyNode::reorderChild(wyNode*, int);
	virtual int reorderChild(wyNode* child, int z);

	/// @see wyNode::removeAllChildren
	virtual void removeAllChildren(bool cleanup);

	/**
	 * Set marker position, it will affect \c drawFromMarker method
	 *
	 * @param pos position of marker
	 */
	void setMarker(int pos) { m_marker = pos; }

	/**
	 * Get current marker position
	 *
	 * @return current marker position
	 */
	int getMarker() { return m_marker; }
};

#endif
