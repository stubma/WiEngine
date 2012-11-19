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
#ifndef __wyAutoReleasePool_h__
#define __wyAutoReleasePool_h__

#include "wyObject.h"

class wyDirector;

/**
 * @class wyAutoReleasePool
 *
 * pool of objects which need to be auto released. Maintained for
 * every thread so that objects got released when thread exits
 */
class WIENGINE_API wyAutoReleasePool : public wyObject {
	friend class wyObject;
	friend class wyDirector;

private:
	/// thread id of this autorelease pool
	ssize_t m_thread;

	/// objects need to be released
	vector<wyObject*>* m_objects;

protected:
	wyAutoReleasePool();

	/// add an object to autorelease pool of current thread
	static void addToPool(wyObject* obj);

	/// flush all pending object, release them now
	static void flush();

public:
	virtual ~wyAutoReleasePool();
	static wyAutoReleasePool* make();

	/**
	 * Drain autorelease pool of current thread
	 */
	static void drainCurrent();

	/**
	 * Drain pool to release all objects in it
	 */
	void drain();
};

#endif // __wyAutoReleasePool_h__
