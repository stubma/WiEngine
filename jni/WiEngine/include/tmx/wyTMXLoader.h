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
#ifndef __wyTMXLoader_h__
#define __wyTMXLoader_h__

#include "wyMapInfo.h"
#include <stdlib.h>

typedef unsigned char xmlChar;

/**
 * @class wyTMXLoader
 *
 * 用于载入Tiled Qt设计的瓦片地图描述文件
 */
class WIENGINE_API wyTMXLoader {
private:
	/**
	 * 载入TMX地图文件
	 *
	 * @param data TMX文件的raw数据
	 * @param length data的长度
	 * @param mi \link wyMapInfo wyMapInfo\endlink, 解析完成后该结构保存了所有地图信息
	 * @param tmxDir 如果tmx文件是从assets或者文件系统中载入的, 则tmxDir是tmx文件的目录路径
	 * @param isFile 如果tmx文件是从assets或者文件系统中载入的, 则isFile说明tmxDir参数表示的是assets路径还是文件系统路径
	 * @param resScale 地图中的和大小，位置相关的数值需要进行缩放的比率, 缺省是1, 即不缩放
	 */
	static wyMapInfo* load(char* data, size_t length, wyMapInfo* mi, const char* tmxDir = NULL, bool isFile = false, float resScale = 1.f);

	static void startElement(void* ctx, const xmlChar *name, const xmlChar **atts);
	static void endElement(void* ctx, const xmlChar *name);
	static void characters(void* ctx, const xmlChar *ch, int len);
	static void warning(void* ctx, const char* msg, ...);
	static void error(void* ctx, const char* msg, ...);

public:
	/*
	 * 载入TMX地图文件
	 *
	 * @param resId TMX文件资源id
	 * @return \link wyMapInfo wyMapInfo\endlink, 解析完成后该结构保存了所有地图信息
	 */
	static wyMapInfo* load(int resId);

	/*
	 * 载入TMX地图文件
	 *
	 * @param path TMX文件的路径
	 * @param isFile true表示path表示的是一个文件系统路径, false表示path表示的是一个assets下面的相对路径
	 * @return \link wyMapInfo wyMapInfo\endlink, 解析完成后该结构保存了所有地图信息
	 */
	static wyMapInfo* load(const char* path, bool isFile);
};

#endif // __wyTMXLoader_h__
