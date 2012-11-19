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
 * error code when parsing TGA file
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
	 * status of file parsing
	 */
    wyTGAError status;

    /**
     * TGALoader data type, see TGALoader file format spec for more info
     */
    char type;

    /**
     * how many bits a pixel has
     */
    int pixelDepth;

    /**
     * bytes of a pixel
     */
    int bytesPerPixel;

    /**
     * map width
     */
    int width;

    /**
     * map height
     */
    int height;

    /**
     * raw data
     */
    char* imageData;

    /**
     * flag indicating the image should be flipped
     */
    bool flipped;
} wyTGA;

#ifdef __cplusplus
}
#endif

/**
 * @class wyTGALoader
 *
 * parser of TGA file, it loads TGA file and returns \link wyTGA wyTGA\endlink structure
 */
class WIENGINE_API wyTGALoader {
private:
	/**
	 * parse TGA specified by an input stream
	 *
	 * @param ais \link wyAssetInputStream wyAssetInputStream\endlink of
	 * @param tga \link wyTGA wyTGA\endlink to be returned
	 */
	static void load(wyAssetInputStream* ais, wyTGA* tga);

	/**
	 * load uncompressed image data from TGA
	 *
	 * @param ais \link wyAssetInputStream wyAssetInputStream\endlink
	 * @param tga \link wyTGA wyTGA\endlink to be returned
	 * @return true means successful
	 */
	static bool loadImageData(wyAssetInputStream* ais, wyTGA* tga);

	/**
	 * load RLE compressed image data from TGA
	 *
	 * @param ais \link wyAssetInputStream wyAssetInputStream\endlink
	 * @param tga \link wyTGA wyTGA\endlink to be returned
	 * @return true means successful
	 */
	static bool loadRLEImageData(wyAssetInputStream* ais, wyTGA* tga);

	/**
	 * flip image in y axis
	 *
	 * @param tga \link wyTGA wyTGA\endlink
	 */
	static void flipImage(wyTGA* tga);

	/**
	 * load header of TGA file
	 *
	 * @param ais \link wyAssetInputStream wyAssetInputStream\endlink
	 * @param tga \link wyTGA wyTGA\endlink to be returned
	 */
	static void loadHeader(wyAssetInputStream* ais, wyTGA* tga);

public:
	/**
	 * load TGA file by a resource id
	 *
	 * @param resId resource id of TGA file
	 * @return \link wyTGA wyTGA\endlink
	 */
	static wyTGA* load(int resId);

	/**
	 * load TGA file by a path
	 *
	 * @param path TGA file path
	 * @param isFile true means \c path is an absolute path in file system, false means it is
	 * 		a relative path under assets folder, default is false
	 * @return \link wyTGA wyTGA\endlink
	 */
	static wyTGA* load(const char* path, bool isFile = false);

	/**
	 * destroy \link wyTGA wyTGA\endlink structure, should call it when you don't want
	 * to use it
	 *
	 * @param tga \link wyTGA wyTGA\endlink to be destroyed
	 */
	static void destroyTGA(wyTGA* tga);
};

#endif // __wyTGALoader_h__
