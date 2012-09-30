/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wySPXLoader_h__
#define __wySPXLoader_h__

#include "wySPXFileData.h"

/**
 * @class wySPXLoader
 *
 * \if English
 * Loader of SpriteX file
 * \else
 * 负责解析， 载入SpriteX的导出文件
 * \endif
 */
class WIENGINE_API wySPXLoader {
private:
	/**
	 * \if English
	 * Load a SpriteX file and return file data object
	 *
	 * @param data SpriteX file raw data
	 * @param length length of \c data
	 * @param resScale resource scale of SpriteX file data
	 * @return \link wySPXFileData wySPXFileData\endlink, or NULL if loading failed
	 * \else
	 * 解析一个SpriteX文件，返回文件数据对象
	 *
	 * @param data SpriteX文件的原始数据
	 * @param length \c data的长度
	 * @param resScale 大小，位置相关的数值需要进行缩放的比率, 缺省是1, 即不缩放
	 * @return \link wySPXFileData wySPXFileData\endlink, 如果载入失败, 返回NULL
	 * \endif
	 */
	static wySPXFileData* load(const char* data, size_t length, float resScale = 1.f);

public:
	/**
	 * \if English
	 * Load a SpriteX file and return file data object
	 *
	 * @param spxResId resource id of SpriteX file
	 * @return \link wySPXFileData wySPXFileData\endlink
	 * \else
	 * 解析一个SpriteX文件，返回文件数据对象
	 *
	 * @param spxResId SpriteX文件的资源id
	 * @return \link wySPXFileData wySPXFileData\endlink
	 * \endif
	 */
	static wySPXFileData* load(int spxResId);

	/**
	 * \if English
	 * Load a SpriteX file and return file data object
	 *
	 * @param spxPath path of SpriteX file
	 * @param isFile true if \c spxPath is an absolute path in file system, false if \c spxPath
	 * 		is relative path under assets
	 * @return \link wySPXFileData wySPXFileData\endlink
	 * \else
	 * 解析一个SpriteX文件，返回文件数据对象
	 *
	 * @param spxPath SpriteX文件的路径
	 * @param isFile true表示\c spxPath是一个文件系统的绝对路径， false表示\c spxPath是一个assets
	 * 		下的相对路径
	 * @return \link wySPXFileData wySPXFileData\endlink
	 * \endif
	 */
	static wySPXFileData* load(const char* spxPath, bool isFile = false);

	/**
	 * \if English
	 * Load a SpriteX file and return file data object
	 *
	 * @param mfsName name of memory file
	 * @return \link wySPXFileData wySPXFileData\endlink
	 * \else
	 * 解析一个SpriteX内存文件，返回文件数据对象
	 *
	 * @param mfsName 内存文件名称
	 * @return \link wySPXFileData wySPXFileData\endlink
	 * \endif
	 */
	static wySPXFileData* loadMemory(const char* mfsName);
};

#endif // __wySPXLoader_h__
