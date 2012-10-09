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
#if WINDOWS

#ifndef __wyResMap_h__
#define __wyResMap_h__

#include "wyGlobal.h"

/**
 * @class wyResMap
 *
 * Resource mapping helper class for windows platform
 */
class wyResMap {
private:
	/// cache for module dir
	char* m_moduleDir;

	/// path of module config ini
	char* m_moduleConfigINI;

	/// cache for mapped full path
	char* m_fullPath;

	/// file list, element is file path relative to module dir
	vector<const char*>* m_fileList;

	/// file map, key is file relative path hash, value is resource id
	map<unsigned int, int>* m_resMap;

protected:
	wyResMap();

	/// setup resource mapping cache
	void setup();

	/**
	 * Renew module directory path string
	 */
	void updateModuleDir();

	/// collect file list recursively
	void collectFileList(char* dir, char* path, char* relativePath);

	/// copy string
	const char* copy(const char* src);

public:
	virtual ~wyResMap();
	static wyResMap* getInstance();

	/**
	 * Get path of config.ini file
	 */
	const char* getConfigINI() { return m_moduleConfigINI; }

	/**
	 * \if English
	 * Get resource id for a resource name
	 * 
	 * @param name full resource name, same as android rules
	 * @return resource id, or zero if not found
	 */
	int getResId(const char* name);

	/**
	 * map a resource id to windows file full path
	 *
	 * @param resId resource id
	 * @return file full path, caller should NOT release it
	 */
	const char* getResFilePath(int resId);

	/**
	 * map an asset file to windows full file path
	 *
	 * @param path path relative to assets folder
	 * @return file full path, caller should NOT release it
	 */
	const char* getAssetFilePath(const char* path);

	/**
	 * map a platform-independent file path to windows file full path
	 *
	 * @param path file absolute path but it is platform-independent
	 * @return file full path for windows platform, caller should NOT release it
	 */
	const char* getLocalFilePath(const char* path);
};

#endif // __wyResMap_h__

#endif // #if WINDOWS
