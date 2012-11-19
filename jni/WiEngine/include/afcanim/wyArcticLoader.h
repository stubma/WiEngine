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
#ifndef __wyArcticLoader_h__
#define __wyArcticLoader_h__

#include "wyArcticFileData.h"

/**
 * @class wyArcticLoader
 *
 * Loader of ASprite file
 */
class WIENGINE_API wyArcticLoader {
private:
	/**
	 * Load a ASprite file and return file data object
	 *
	 * @param data ASprite file raw data
	 * @param length length of \c data
	 * @param resScale resource scale of ASprite file data
	 * @return \link wyArcticFileData wyArcticFileData\endlink, or NULL if loading failed
	 */
	static wyArcticFileData* load(const char* data, size_t length, float resScale = 1.f);

public:
	/**
	 * Load a ASprite file and return file data object
	 *
	 * @param asResId resource id of ASprite file
	 * @return \link wyArcticFileData wyArcticFileData\endlink
	 */
	static wyArcticFileData* load(int asResId);

	/**
	 * Load a ASprite file and return file data object
	 *
	 * @param asPath path of ASprite file
	 * @param isFile true if \c asPath is an absolute path in file system, false if \c asPath
	 * 		is relative path under assets
	 * @return \link wyArcticFileData wyArcticFileData\endlink
	 */
	static wyArcticFileData* load(const char* asPath, bool isFile = false);

	/**
	 * Load a ASprite file and return file data object
	 *
	 * @param mfsName name of memory file
	 * @return \link wyArcticFileData wyArcticFileData\endlink
	 */
	static wyArcticFileData* loadMemory(const char* mfsName);
};

#endif // __wyArcticLoader_h__
