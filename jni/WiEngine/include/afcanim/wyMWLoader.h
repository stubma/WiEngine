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
#ifndef __wyMWLoader_h__
#define __wyMWLoader_h__

#include "wyMWFileData.h"

/**
 * @class wyMWLoader
 *
 * Loader of Motion Welder file
 */
class wyMWLoader {
private:
	/**
	 * Load a Motion Welder file and return file data object
	 *
	 * @param data Motion Welder file raw data
	 * @param length length of \c data
	 * @param resScale resource scale of Motion Welder file data
	 * @return \link wyMWFileData wyMWFileData\endlink, or NULL if loading failed
	 */
	static wyMWFileData* load(const char* data, size_t length, float resScale = 1.f);

public:
	/**
	 * Load a Motion Welder file and return file data object
	 *
	 * @param mwResId resource id of Motion Welder file
	 * @return \link wyMWFileData wyMWFileData\endlink
	 */
	static wyMWFileData* load(int mwResId);

	/**
	 * Load a Motion Welder file and return file data object
	 *
	 * @param path path of Motion Welder file
	 * @param isFile true if \c path is an absolute path in file system, false if \c path
	 * 		is relative path under assets
	 * @return \link wyMWFileData wyMWFileData\endlink
	 */
	static wyMWFileData* load(const char* path, bool isFile = false);

	/**
	 * Load a Motion Welder file and return file data object
	 *
	 * @param mfsName name of memory file
	 * @return \link wyMWFileData wyMWFileData\endlink
	 */
	static wyMWFileData* loadMemory(const char* mfsName);
};

#endif // __wyMWLoader_h__
