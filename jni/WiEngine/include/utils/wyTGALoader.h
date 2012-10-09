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
#ifndef __wyTGALoader_h__
#define __wyTGALoader_h__

#include <stdbool.h>
#include "wyTypes.h"
#include "wyAssetInputStream.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @typedef wyTGAError
 *
 * \if English
 * error code when parsing TGA file
 * \else
 * 解析TGA文件时可能出现的错误码
 * \endif
 */
typedef enum {
	TGA_OK,
	TGA_ERROR_FILE_OPEN,
	TGA_ERROR_READING_FILE,
	TGA_ERROR_INDEXED_COLOR,
	TGA_ERROR_MEMORY,
	TGA_ERROR_COMPRESSED_FILE,
} wyTGAError;

typedef struct WIENGINE_API wyTGA {
	/**
	 * \if English
	 * status of file parsing
	 * \else
	 * 解析状态码
	 * \endif
	 */
    wyTGAError status;

    /**
     * \if English
     * TGALoader data type, see TGALoader file format spec for more info
     * \else
     * TGA文件数据类型
     * \endif
     */
    char type;

    /**
     * \if English
     * how many bits a pixel has
     * \else
     * 每个点多少比特位
     * \endif
     */
    int pixelDepth;

    /**
     * \if English
     * bytes of a pixel
     * \else
     * 每个点多少字节
     * \endif
     */
    int bytesPerPixel;

    /**
     * \if English
     * map width
     * \else
     * x方向地图瓦片个数
     * \endif
     */
    int width;

    /**
     * \if English
     * map height
     * \else
     * y方向地图瓦片个数
     * \endif
     */
    int height;

    /**
     * \if English
     * raw data
     * \else
     * 图像原始数据
     * \endif
     */
    char* imageData;

    /**
     * \if English
     * flag indicating the image should be flipped
     * \else
     * true表示图像是y方向颠倒的
     * \endif
     */
    bool flipped;
} wyTGA;

#ifdef __cplusplus
}
#endif

/**
 * @class wyTGALoader
 *
 * \if English
 * parser of TGA file, it loads TGA file and returns \link wyTGA wyTGA\endlink structure
 * \else
 * TGA文件的解析类, 提供load方法从资源或者文件中载入TGA文件, 返回wyTGA结构
 * \endif
 */
class WIENGINE_API wyTGALoader {
private:
	/**
	 * \if English
	 * parse TGA specified by an input stream
	 *
	 * @param ais \link wyAssetInputStream wyAssetInputStream\endlink of
	 * @param tga \link wyTGA wyTGA\endlink to be returned
	 * \else
	 * 从FILE指针中载入wyTGA结构信息
	 *
	 * @param ais \link wyAssetInputStream wyAssetInputStream对象指针\endlink
	 * @param tga \link wyTGA wyTGA结构\endlink
	 * \endif
	 */
	static void load(wyAssetInputStream* ais, wyTGA* tga);

	/**
	 * \if English
	 * load uncompressed image data from TGA
	 *
	 * @param ais \link wyAssetInputStream wyAssetInputStream\endlink
	 * @param tga \link wyTGA wyTGA\endlink to be returned
	 * @return true means successful
	 * \else
	 * 载入TGA的非压缩图像数据
	 *
	 * @param ais \link wyAssetInputStream wyAssetInputStream对象指针\endlink
	 * @param tga \link wyTGA wyTGA结构\endlink
	 * @return true表示载入成功, false表示失败
	 * \endif
	 */
	static bool loadImageData(wyAssetInputStream* ais, wyTGA* tga);

	/**
	 * \if English
	 * load RLE compressed image data from TGA
	 *
	 * @param ais \link wyAssetInputStream wyAssetInputStream\endlink
	 * @param tga \link wyTGA wyTGA\endlink to be returned
	 * @return true means successful
	 * \else
	 * 读取TGA的压缩图像数据, 解压到wyTGA结构中
	 *
	 * @param ais \link wyAssetInputStream wyAssetInputStream对象指针\endlink
	 * @param tga \link wyTGA wyTGA结构\endlink
	 * @return true表示载入成功, false表示失败
	 * \endif
	 */
	static bool loadRLEImageData(wyAssetInputStream* ais, wyTGA* tga);

	/**
	 * \if English
	 * flip image in y axis
	 *
	 * @param tga \link wyTGA wyTGA\endlink
	 * \else
	 * 垂直翻转TGA图片
	 *
	 * @param tga \link wyTGA wyTGA结构\endlink
	 * \endif
	 */
	static void flipImage(wyTGA* tga);

	/**
	 * \if English
	 * load header of TGA file
	 *
	 * @param ais \link wyAssetInputStream wyAssetInputStream\endlink
	 * @param tga \link wyTGA wyTGA\endlink to be returned
	 * \else
	 * 载入TGA文件头部信息
	 *
	 * @param ais \link wyAssetInputStream wyAssetInputStream对象指针\endlink
	 * @param tga \link wyTGA wyTGA结构\endlink
	 * \endif
	 */
	static void loadHeader(wyAssetInputStream* ais, wyTGA* tga);

public:
	/**
	 * \if English
	 * load TGA file by a resource id
	 *
	 * @param resId resource id of TGA file
	 * @return \link wyTGA wyTGA\endlink
	 * \else
	 * 从tga资源文件中载入
	 *
	 * @param resId tga文件的资源id
	 * @return \link wyTGA wyTGA结构\endlink
	 * \endif
	 */
	static wyTGA* load(int resId);

	/**
	 * \if English
	 * load TGA file by a path
	 *
	 * @param path TGA file path
	 * @param isFile true means \c path is an absolute path in file system, false means it is
	 * 		a relative path under assets folder, default is false
	 * @return \link wyTGA wyTGA\endlink
	 * \else
	 * 从assets或者文件系统中载入TGA
	 *
	 * @param path tga文件路径, 可以是assets下的路径或者文件系统路径
	 * @param isFile 可选参数, true表示path是一个文件系统路径, false表示path是一个assets相对路径
	 * @return \link wyTGA wyTGA结构\endlink
	 * \endif
	 */
	static wyTGA* load(const char* path, bool isFile = false);

	/**
	 * \if English
	 * destroy \link wyTGA wyTGA\endlink structure, should call it when you don't want
	 * to use it
	 *
	 * @param tga \link wyTGA wyTGA\endlink to be destroyed
	 * \else
	 * 销毁wyTGA结构
	 *
	 * @param tga \link wyTGA wyTGA结构\endlink
	 * \endif
	 */
	static void destroyTGA(wyTGA* tga);
};

#endif // __wyTGALoader_h__
