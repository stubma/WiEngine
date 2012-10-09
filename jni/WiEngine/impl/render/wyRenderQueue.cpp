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
#include "wyRenderQueue.h"
#include "wyNode.h"
#include "wyLog.h"
#include "wyRenderManager.h"

wyRenderQueue::wyRenderQueue() {
	m_guiList = WYNEW vector<wyNode*>();
	m_guiList->reserve(32);

	m_opaqueList = WYNEW vector<wyNode*>();
	m_opaqueList->reserve(32);

	m_transparentList = WYNEW vector<wyNode*>();
	m_transparentList->reserve(32);

	m_skyList = WYNEW vector<wyNode*>();
	m_skyList->reserve(32);

	m_translucentList = WYNEW vector<wyNode*>();
	m_translucentList->reserve(32);
}

wyRenderQueue::~wyRenderQueue() {
	WYDELETE(m_guiList);
	WYDELETE(m_opaqueList);
	WYDELETE(m_transparentList);
	WYDELETE(m_skyList);
	WYDELETE(m_translucentList);
}

wyRenderQueue* wyRenderQueue::make() {
	wyRenderQueue* rq = WYNEW wyRenderQueue();
	return (wyRenderQueue*)rq->autoRelease();
}

void wyRenderQueue::addToQueue(wyNode* n, Bucket bucket) {
	switch (bucket) {
		case GUI_BUCKET:
			m_guiList->push_back(n);
			break;
		case OPAQUE_BUCKET:
			m_opaqueList->push_back(n);
			break;
		case SKY_BUCKET:
			m_skyList->push_back(n);
			break;
		case TRANSPARENT_BUCKET:
			m_transparentList->push_back(n);
			break;
		case TRANSLUCENT_BUCKET:
			m_translucentList->push_back(n);
			break;
		default:
			LOGW("wyRenderQueue::addToQueue: unknown bucket type: %d", bucket);
			break;
	}
}

void wyRenderQueue::clear() {
	m_guiList->clear();
	m_opaqueList->clear();
	m_skyList->clear();
	m_transparentList->clear();
	m_translucentList->clear();
}

bool wyRenderQueue::isBucketEmpty(Bucket bucket) {
	switch (bucket) {
		case GUI_BUCKET:
			return m_guiList->size() <= 0;
		case OPAQUE_BUCKET:
			return m_opaqueList->size() <= 0;
		case SKY_BUCKET:
			return m_skyList->size() <= 0;
		case TRANSPARENT_BUCKET:
			return m_transparentList->size() <= 0;
		case TRANSLUCENT_BUCKET:
			return m_translucentList->size() <= 0;
		default:
			LOGW("wyRenderQueue::isBucketEmpty: unknown bucket type: %d", bucket);
			return true;
	}
}

void wyRenderQueue::renderBucket(Bucket bucket, wyRenderManager* rm) {
	switch (bucket) {
		case GUI_BUCKET:
			renderNodeList(m_guiList, rm);
			break;
		case OPAQUE_BUCKET:
			renderNodeList(m_opaqueList, rm);
			break;
		case SKY_BUCKET:
			renderNodeList(m_skyList, rm);
			break;
		case TRANSPARENT_BUCKET:
			renderNodeList(m_transparentList, rm);
			break;
		case TRANSLUCENT_BUCKET:
			renderNodeList(m_translucentList, rm);
			break;
	}
}

void wyRenderQueue::renderNodeList(vector<wyNode*>* list, wyRenderManager* rm) {
    for(vector<wyNode*>::iterator iter = list->begin(); iter != list->end(); iter++) {
        rm->renderNode(*iter);
    }
}
