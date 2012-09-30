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
#ifndef __wyPVR_h__
#define __wyPVR_h__

/**
 * @typedef wyPVRFlag
 *
 * PVR的贴图的标志掩码
 */
typedef enum {
	PVR_TEXTURE_FLAG_TYPE_MASK = 0xff,
	PVR_TEXTURE_FLAG_FLIPPED_MASK = 0x10000
} wyPVRFlag;

/**
 * @typedef wyPVRFormat
 *
 * PVR贴图格式
 */
typedef enum {
	PVR_RGBA_4444 = 0x10,
	PVR_RGBA_5551 = 0x11,
	PVR_RGBA_8888 = 0x12,
	PVR_RGB_565 = 0x13,
	PVR_RGB_555 = 0x14,
	PVR_RGB_888 = 0x15,
	PVR_I_8 = 0x16,
	PVR_AI_88 = 0x17,
	PVR_PVRTC_2 = 0x18,
	PVR_PVRTC_4 = 0x19,
	PVR_BGRA_8888 = 0x1A,
	PVR_A_8 = 0x1B
} wyPVRFormat;

// field index
typedef enum {
	PVR_INDEX_TEXTURE_FORMAT,
	PVR_INDEX_INTERNAL_FORMAT,
	PVR_INDEX_OPENGL_FORMAT,
	PVR_INDEX_OPENGL_TYPE,
	PVR_INDEX_BPP,
	PVR_INDEX_COMPRESSED,
} wyPVRIndex;

extern int gPVRFormats[][6];
extern int PVR_FORMAT_TABLE_ELEMENTS;

/**
 * @struct wyPVRHeader
 *
 * PVR文件头部结构
 */
typedef struct wyPVRHeader {
	int headerLength;
	int height;
	int width;
	int numMipmaps;
	int flags;
	int dataLength;
	int bpp;
	int bitmaskRed;
	int bitmaskGreen;
	int bitmaskBlue;
	int bitmaskAlpha;
	int pvrTag;
	int numSurfs;
} wyPVRHeader;

#endif // __wyPVR_h__
