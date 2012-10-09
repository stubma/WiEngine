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
#include "wyAutoReleasePool.h"
#include <pthread.h>
#include "wyEventDispatcher.h"
#include "wyLog.h"

// global event dispatcher
extern wyEventDispatcher* gEventDispatcher;

// global pools
#define MAP map<ssize_t, wyAutoReleasePool*>
#define ITER MAP::iterator
static MAP* s_pools = NULL;

wyAutoReleasePool::wyAutoReleasePool() {
	// init global pool mapping
	if(!s_pools) {
		s_pools = WYNEW MAP();
	}

	// init object list
	m_objects = WYNEW vector<wyObject*>();

	// get current thread id
	m_thread = currentThreadId();

	// put self in map
	ITER iter = s_pools->find(m_thread);
	if(iter == s_pools->end()) {
		(*s_pools)[m_thread] = this;
	}
}

wyAutoReleasePool::~wyAutoReleasePool() {
	// release all objects
	for(vector<wyObject*>::iterator iter = m_objects->begin(); iter != m_objects->end(); iter++) {
		wyObjectRelease(*iter);
	}
	WYDELETE(m_objects);

	// remove self from pool map
	ITER iter = s_pools->find(m_thread);
	if(iter != s_pools->end()) {
		s_pools->erase(iter);

		// if pool map is empty, release map also
		if(s_pools->empty()) {
			WYDELETE(s_pools);
			s_pools = NULL;
		}
	}
}

wyAutoReleasePool* wyAutoReleasePool::make() {
	/*
	 * This is special case for auto release pool because we don't call autorelease
	 * in make method
	 */
	return WYNEW wyAutoReleasePool();
}

void wyAutoReleasePool::addToPool(wyObject* obj) {
	// get current thread id
	ssize_t t = currentThreadId();

	// if pool map is not here, create
	if(!s_pools)
		wyAutoReleasePool::make();

	// add to object list
	ITER iter = s_pools->find(t);
	if(iter != s_pools->end()) {
		wyAutoReleasePool* pool = iter->second;
		pool->m_objects->push_back(obj);
	}
}

void wyAutoReleasePool::flush() {
	if(!s_pools)
		return;

	for(ITER iter = s_pools->begin(); s_pools && iter != s_pools->end(); ) {
		ITER cur = iter;
		iter++;
		wyObjectRelease(cur->second);
	}
}

void wyAutoReleasePool::drainCurrent() {
	// if pool map is null, it means the auto release pool is not auto created for this thread
	if(!s_pools)
		return;

	// get current thread id
	ssize_t t = currentThreadId();

	// find pool and drain it
	ITER iter = s_pools->find(t);
	if(iter != s_pools->end()) {
		wyAutoReleasePool* pool = iter->second;
		pool->drain();
	}
}

void wyAutoReleasePool::drain() {
	if(gEventDispatcher)
		gEventDispatcher->queueEventLocked(ET_DRAIN_AUTO_RELEASE_POOL, this);
}
