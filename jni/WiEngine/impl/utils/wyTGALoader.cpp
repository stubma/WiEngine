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
#include "wyTGALoader.h"
#include <stdlib.h>
#include "wyUtils.h"
#include <stdio.h>
#include <errno.h>
#include "wyLog.h"
#if ANDROID
	#include "wyJNI.h"
#endif

void wyTGALoader::loadHeader(wyAssetInputStream* ais, wyTGA* tga) {
	// skip id length and color map type
	ais->seek(2, SEEK_CUR);

    // read image type
	ais->read(&(tga->type), 1);

    // skip color map spec
    // skip unused image spec
    // read width and height
	ais->seek(9, SEEK_CUR);
	char a;
	char b;
	ais->read(&a, 1);
	ais->read(&b, 1);
	tga->width = (a & 0xff) | ((b & 0xff) << 8);
	ais->read(&a, 1);
	ais->read(&b, 1);
	tga->height = (a & 0xff) | ((b & 0xff) << 8);

    // read pixel depth
	ais->read(&a, 1);
	tga->pixelDepth = a & 0xff;
	tga->bytesPerPixel = tga->pixelDepth / 8;

    // read a garbage byte which contains flip flag
	ais->read(&a, 1);
    tga->flipped = false;
    if ((a & 0x20) != 0)
    	tga->flipped = true;
}

void wyTGALoader::flipImage(wyTGA* tga) {
    // mode equal the number of components for each pixel
    int rowbytes = tga->width * tga->bytesPerPixel;
    char* row = (char*)wyMalloc(rowbytes * sizeof(char));

    for (int y = 0; y < (tga->height / 2); y++) {
    	memcpy(row, tga->imageData + y * rowbytes, rowbytes * sizeof(char));
    	memcpy(tga->imageData + y * rowbytes, tga->imageData + (tga->height - (y + 1)) * rowbytes, rowbytes * sizeof(char));
    	memcpy(tga->imageData + (tga->height - (y + 1)) * rowbytes, row, rowbytes * sizeof(char));
    }

    tga->flipped = false;
	wyFree(row);
}

bool wyTGALoader::loadRLEImageData(wyAssetInputStream* ais, wyTGA* tga) {
    // total is the number of unsigned chars we'll have to read
    int total = tga->height * tga->width;

    char a;
    int pixel = 0;
    int bytes = 0;
    int runlength = 0;
    char buf[4] = { 0, 0, 0, 0};
    while(pixel < total) {
    	ais->read(&a, 1);
    	runlength = a & 0xff;
    	if(runlength < 128) {
    		// If the run length is < 128, it means the that is the number of
            // RAW color packets minus 1
    		runlength++;
    		for(int i = 0; i < runlength; i++) {
                // read in the pixel data
                if (ais->read(buf, tga->bytesPerPixel) != tga->bytesPerPixel) {
                	LOGW("Failed to read TAGLoader file");
                	return false;
                }

                // stores it as BGR(A) so we'll have to swap R and B.
                tga->imageData[bytes] = buf[2];
                tga->imageData[bytes + 1] = buf[1];
                tga->imageData[bytes + 2] = buf[0];

                // adjust pointer
                bytes += tga->bytesPerPixel;
                pixel++;

                // check current pixel and total pixel
                if(pixel > total) {
                    // if there is too many... Display an error!
                    LOGW("Too many pixels read");
                    return false;
                }
    		}
    	} else {
    		// run length > 128 RLE data, next color repeated run length - 127 times
    		runlength -= 127;

            // read in the pixel data
            if (ais->read(buf, tga->bytesPerPixel) != tga->bytesPerPixel) {
            	 LOGW("Failed to read TAGLoader file");
            	 return false;
            }

            // copy the color into the image data as many times as dictated
            for(int i = 0; i < runlength; i++) {
            	// stores it as BGR(A) so we'll have to swap R and B.
            	tga->imageData[bytes] = buf[2];
            	tga->imageData[bytes + 1] = buf[1];
            	tga->imageData[bytes + 2] = buf[0];

                // adjust pointer
                bytes += tga->bytesPerPixel;
                pixel++;

                // check current pixel and total pixel
                if(pixel > total) {
                    // if there is too many... Display an error!
                    LOGW("Too many pixels read");
                    return false;
                }
            }
    	}
    }

    return true;
}

bool wyTGALoader::loadImageData(wyAssetInputStream* ais, wyTGA* tga) {
    // total is the number of unsigned chars we'll have to read
    int total = tga->height * tga->width * tga->bytesPerPixel;
    if(ais->read(tga->imageData, total) != total) {
    	LOGE("wyTGALoader.loadImageData: failed to read %d bytes", total);
    	return false;
    }

    // mode=3 or 4 implies that the image is RGB(A). However TAGLoader
    // stores it as BGR(A) so we'll have to swap R and B.
    if (tga->bytesPerPixel >= 3) {
        for (int i = 0; i < total; i += tga->bytesPerPixel) {
            unsigned char aux = tga->imageData[i];
            tga->imageData[i] = tga->imageData[i + 2];
            tga->imageData[i + 2] = aux;
        }
    } else {
    	LOGE("wyTGALoader.loadImageData: doesn't support bpp less than 3");
    	return false;
    }

    return true;
}

void wyTGALoader::load(wyAssetInputStream* ais, wyTGA* tga) {
    // load the header
    loadHeader(ais, tga);

    // check if the image is color indexed
    if (tga->type == 1) {
    	tga->status = TGA_ERROR_INDEXED_COLOR;
    	return;
    }

    // check for wrapped types (compressed images)
    if ((tga->type != 2) && (tga->type != 3) && (tga->type != 10)) {
    	tga->status = TGA_ERROR_COMPRESSED_FILE;
        return;
    }

    // total is the number of unsigned chars to read
    int total = tga->height * tga->width * tga->bytesPerPixel;

    // allocate memory for image pixels
    tga->imageData = (char*)wyMalloc(total * sizeof(char));

    // finally load the image pixels
	if (tga->type == 10) {
		if(!loadRLEImageData(ais, tga)) {
			tga->status = TGA_ERROR_READING_FILE;
	        return;
		}
	} else if(!loadImageData(ais, tga)) {
		tga->status = TGA_ERROR_READING_FILE;
        return;
	}
    tga->status = TGA_OK;

    if (tga->flipped) {
        flipImage(tga);
        if (tga->flipped)
        	tga->status = TGA_ERROR_MEMORY;
    }
}

wyTGA* wyTGALoader::load(int resId) {
	// allocate wyTGA
	wyTGA* tga = (wyTGA*)wyCalloc(1, sizeof(wyTGA));

	// open resource
	wyAssetInputStream* ais = wyAssetInputStream::make(resId);

	// load
	load(ais, tga);

	return tga;
}

wyTGA* wyTGALoader::load(const char* path, bool isFile) {
	// allocate wyTGA
	wyTGA* tga = (wyTGA*)wyCalloc(1, sizeof(wyTGA));

	// open file
	wyAssetInputStream* ais = wyAssetInputStream::make(path, isFile);

	// load from input stream
	load(ais, tga);

	return tga;
}

void wyTGALoader::destroyTGA(wyTGA* tga) {
    if (tga != NULL) {
        if (tga->imageData != NULL) {
        	wyFree(tga->imageData);
            tga->imageData = NULL;
        }
        wyFree(tga);
    }
}
