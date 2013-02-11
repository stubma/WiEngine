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
#ifndef __wySpineLoader_h__
#define __wySpineLoader_h__

#include "wySkeleton.h"
#include "wySkeletalAnimation.h"

class wyJSONObject;

/**
 * loader of spine exported file
 */
class WIENGINE_API wySpineLoader {
private:
	/**
	 * load a spine skeleton model from json object
	 *
	 * @param jo \link wyJSONObject wyJSONObject\endlink
	 * @param scale scale rate for position value
	 * @return \link wySkeleton wySkeleton\endlink
	 */
	static wySkeleton* loadSkeleton(wyJSONObject* jo, float scale);
	
	/**
	 * load a spine skeletal animation from json object
	 *
	 * @param jo \link wyJSONObject wyJSONObject\endlink
	 * @param scale scale rate for position value
	 * @return \link wySkeletalAnimation wySkeletalAnimation\endlink
	 */
	static wySkeletalAnimation* loadAnimation(wyJSONObject* jo, float scale);

public:
	/**
	 * load a spine skeleton model from skeleton resource file
	 *
	 * @param resId resource id of skeleton resource file
	 * @return \link wySkeleton wySkeleton\endlink
	 */
	static wySkeleton* loadSkeleton(int resId);

	/**
	 * load a spine skeleton model from file
	 *
	 * @param path path of file
	 * @param isFile false means \c path is a relative path to assets folder, or true means
	 * 		\c path is an absolute path in file system
	 * @return \link wySkeleton wySkeleton\endlink
	 */
	static wySkeleton* loadSkeleton(const char* path, bool isFile = false);

	/**
	 * load a spine skeleton model from memory file
	 *
	 * @param mfsName memory file name
	 * @return \link wySkeleton wySkeleton\endlink
	 */
	static wySkeleton* loadMemorySkeleton(const char* mfsName);
	
	/**
	 * load a spine skeletal animation from skeleton resource file
	 *
	 * @param resId resource id of skeleton resource file
	 * @return \link wySkeletalAnimation wySkeletalAnimation\endlink
	 */
	static wySkeletalAnimation* loadAnimation(int resId);
	
	/**
	 * load a spine skeletal animation from file
	 *
	 * @param path path of file
	 * @param isFile false means \c path is a relative path to assets folder, or true means
	 * 		\c path is an absolute path in file system
	 * @return \link wySkeletalAnimation wySkeletalAnimation\endlink
	 */
	static wySkeletalAnimation* loadAnimation(const char* path, bool isFile = false);
	
	/**
	 * load a spine skeletal animation from memory file
	 *
	 * @param mfsName memory file name
	 * @return \link wySkeletalAnimation wySkeletalAnimation\endlink
	 */
	static wySkeletalAnimation* loadMemoryAnimation(const char* mfsName);
};

#endif // __wySpineLoader_h__
