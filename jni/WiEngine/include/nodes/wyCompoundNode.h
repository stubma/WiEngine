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
#ifndef __wyCompoundNode_h__
#define __wyCompoundNode_h__

#include "wyNode.h"

// for compound node
#define WY_NODE_MAP map<int, wyNode*>
#define WY_NODE_ITER WY_NODE_MAP::iterator

/**
 * @class wyCompoundNode
 *
 * \if English
 * wyCompoundNode is a common abstraction for node which consisted of
 * other nodes.
 * \else
 * 组合型节点的抽象实现, 组合型节点指的是本身没有渲染逻辑, 而是通过包含其它节点
 * 来组成一个新的节点
 * \endif
 */
class WIENGINE_API wyCompoundNode : public wyNode {
protected:
	/// map of sub nodes, key is node tag. however
	/// the tag key is not node tag, they are different thing
	WY_NODE_MAP* m_nodes;

protected:
	wyCompoundNode();

	/**
	 * Register a sub node into node map
	 *
	 * @param tag key tag of this sub node
	 * @param node sub node
	 * @param asChild true means this sub node should be added as a child node
	 */
	void registerNode(int tag, wyNode* node, bool asChild);

	/// get sub node by tag
	wyNode* getNode(int tag);

	/// get current active node, or NULL if none
	wyNode* getStateNode();

	/**
	 * Return a tag indicating which sub node is in active and should be responsible
	 * for some invocation
	 *
	 * @return a tag of sub node
	 */
	virtual int getStateTag() { return 0; }

public:
	virtual ~wyCompoundNode();

	/// @see wyNode::onEnter
	virtual void onEnter();

	/// @see wyNode::onExit
	virtual void onExit();

	/// @see wyNode::setRotation
	virtual void setRotation(float rot);

	/// @see wyNode::setScale
	virtual void setScale(float scale);

	/// @see wyNode::setScaleX
	virtual void setScaleX(float scaleX);

	/// @see wyNode::setScaleY
	virtual void setScaleY(float scaleY);

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::setColor
	virtual void setColor(wyColor4B color);

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha);

	/// @see wyNode::getColor
	virtual wyColor3B getColor();

	/// @see wyNode::getAlpha
	virtual int getAlpha();

	/// @see wyNode::getBlendMode
	virtual wyRenderState::BlendMode getBlendMode();

	/// @see wyNode::setBlendMode
	virtual void setBlendMode(wyRenderState::BlendMode mode);

	/// @see wyNode::getRenderPairCount
	virtual int getRenderPairCount();

	/// @see wyNode::getMaterial
	virtual wyMaterial* getMaterial(int index = 0);

	/// @see wyNode::getMesh
	virtual wyMesh* getMesh(int index = 0);

	/// @see wyNode::getLodLevel
    virtual int getLodLevel(int index = 0);

	/// @see wyNode::setLodLevel
    virtual void setLodLevel(int level, int index = 0);

	/// @see wyNode::updateMaterial
	virtual void updateMaterial();

	/// @see wyNode::updateMesh
	virtual void updateMesh();

	/// @see wyNode::updateMeshColor
	virtual void updateMeshColor();

	/// @see wyNode::isNeedUpdateMaterial
	virtual bool isNeedUpdateMaterial();

	/// @see wyNode::isNeedUpdateMesh
	virtual bool isNeedUpdateMesh();

	/// @see wyNode::isNeedUpdateMeshColor
	virtual bool isNeedUpdateMeshColor();

	/// @see wyNode::setNeedUpdateMaterial
	virtual void setNeedUpdateMaterial(bool flag);

	/// @see wyNode::setNeedUpdateMesh
	virtual void setNeedUpdateMesh(bool flag);

	/// @see wyNode::setNeedUpdateMeshColor
	virtual void setNeedUpdateMeshColor(bool flag);
};

#endif // __wyCompoundNode_h__
