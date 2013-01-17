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
#ifndef __wyLoadableObject_h__
#define __wyLoadableObject_h__

#include "wyObject.h"

/**
 * a base abstraction of object which can be loaded from somewhere, such as file, memory or something
 * else
 */
class WIENGINE_API wyLoadableObject : public wyObject {
public:
	/**
	 * load object from a resource file identified by a resource id
	 *
	 * @param resId resource id of file
	 */
	virtual void load(int resId) = 0;

	/**
	 * load object from asset file
	 *
	 * @param path relative path in assets folder
	 */
	virtual void load(const char* path) = 0;

	/**
	 * load object from a file in local file system
	 *
	 * @param path absolute path in file system
	 */
	virtual void loadFile(const char* path) = 0;

	/**
	 * load object from a memory file
	 *
	 * @param mfsName name of memory file
	 */
	virtual void loadMemory(const char* mfsName) = 0;

	/**
	 * load object from a memory data
	 *
	 * @param data memory data
	 * @param len length of data
	 */
	virtual void loadMemory(const char* data, size_t len) = 0;
};

#endif // __wyLoadableObject_h__
