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
#include "wyCompoundNode.h"
#include "wyLog.h"

wyCompoundNode::wyCompoundNode() {
	m_nodes = WYNEW WY_NODE_MAP();
}

wyCompoundNode::~wyCompoundNode() {
	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		wyObjectRelease(iter->second);
	}
	WYDELETE(m_nodes);
}

void wyCompoundNode::registerNode(int tag, wyNode* node, bool asChild) {
	// basic validation
	if(!node)
		return;

	// if conflict, release old one
	WY_NODE_ITER iter = m_nodes->find(tag);
	if(iter != m_nodes->end()) {
		wyObjectRelease(iter->second);
		m_nodes->erase(iter);
	}

	// add to node map
	(*m_nodes)[tag] = node;

	// retain it
	node->retain();

	// add as child or not?
	if(asChild)
		addChildLocked(node);
}

wyNode* wyCompoundNode::getStateNode() {
	WY_NODE_ITER iter = m_nodes->find(getStateTag());
	if(iter != m_nodes->end())
		return iter->second;
	else
		return NULL;
}

wyNode* wyCompoundNode::getNode(int tag) {
	WY_NODE_ITER iter = m_nodes->find(tag);
	if(iter != m_nodes->end())
		return iter->second;
	else
		return NULL;
}

void wyCompoundNode::onEnter() {
	wyNode::onEnter();

	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->onEnter();
	}
}

void wyCompoundNode::onExit() {
	wyNode::onExit();

	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->onExit();
	}
}

void wyCompoundNode::setRotation(float rot) {
	wyNode::setRotation(rot);

	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->setRotation(rot);
	}
}

void wyCompoundNode::setScale(float scale) {
	wyNode::setScale(scale);

	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->setScale(scale);
	}
}

void wyCompoundNode::setScaleX(float scaleX) {
	wyNode::setScaleX(scaleX);

	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->setScaleX(scaleX);
	}
}

void wyCompoundNode::setScaleY(float scaleY) {
	wyNode::setScaleY(scaleY);

	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->setScaleY(scaleY);
	}
}

void wyCompoundNode::setColor(wyColor3B color) {
	wyNode::setColor(color);

	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->setColor(color);
	}
}

void wyCompoundNode::setColor(wyColor4B color) {
	wyNode::setColor(color);

	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->setColor(color);
	}
}

void wyCompoundNode::setAlpha(int alpha) {
	wyNode::setAlpha(alpha);

	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->setAlpha(alpha);
	}
}

int wyCompoundNode::getAlpha() {
	wyNode* node = getStateNode();
	return node == NULL ? wyNode::getAlpha() : node->getAlpha();
}

wyColor3B wyCompoundNode::getColor() {
	wyNode* node = getStateNode();
	return node == NULL ? wyNode::getColor() : node->getColor();
}

wyRenderState::BlendMode wyCompoundNode::getBlendMode() {
	wyNode* node = getStateNode();
	return node == NULL ? wyRenderState::NO_BLEND : node->getBlendMode();
}

void wyCompoundNode::setBlendMode(wyRenderState::BlendMode mode) {
	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->setBlendMode(mode);
	}
}

int wyCompoundNode::getRenderPairCount() {
	wyNode* node = getStateNode();
	if(node)
		return node->getRenderPairCount();
	else
		return 0;
}

wyMaterial* wyCompoundNode::getMaterial(int index) {
	wyNode* node = getStateNode();
	if(node)
		return node->getMaterial(index);
	else
		return NULL;
}

wyMesh* wyCompoundNode::getMesh(int index) {
	wyNode* node = getStateNode();
	if(node)
		return node->getMesh(index);
	else
		return NULL;
}

int wyCompoundNode::getLodLevel(int index) {
	wyNode* node = getStateNode();
	if(node)
		return node->getLodLevel(index);
	else
		return 0;
}

void wyCompoundNode::setLodLevel(int level, int index) {
	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->setLodLevel(level, index);
	}
}

void wyCompoundNode::updateMaterial() {
	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		if(iter->second->isNeedUpdateMaterial())
			iter->second->updateMaterial();
	}
}

void wyCompoundNode::updateMesh() {
	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		if(iter->second->isNeedUpdateMesh())
			iter->second->updateMesh();
	}
}

void wyCompoundNode::updateMeshColor() {
	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		if(iter->second->isNeedUpdateMeshColor())
			iter->second->updateMeshColor();
	}
}

bool wyCompoundNode::isNeedUpdateMaterial() {
	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		if(iter->second->isNeedUpdateMaterial())
			return true;
	}

	return false;
}

bool wyCompoundNode::isNeedUpdateMesh() {
	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		if(iter->second->isNeedUpdateMesh())
			return true;
	}

	return false;
}

bool wyCompoundNode::isNeedUpdateMeshColor() {
	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		if(iter->second->isNeedUpdateMeshColor())
			return true;
	}

	return false;
}

void wyCompoundNode::setNeedUpdateMaterial(bool flag) {
	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->setNeedUpdateMaterial(flag);
	}
}

void wyCompoundNode::setNeedUpdateMesh(bool flag) {
	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->setNeedUpdateMesh(flag);
	}
}

void wyCompoundNode::setNeedUpdateMeshColor(bool flag) {
	for(WY_NODE_ITER iter = m_nodes->begin(); iter != m_nodes->end(); iter++) {
		iter->second->setNeedUpdateMeshColor(flag);
	}
}
