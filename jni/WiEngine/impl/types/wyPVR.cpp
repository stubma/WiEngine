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
#include "wyPVR.h"
#include "wyGlobal.h"

// - PVR texture format
// - OpenGL internal format
// - OpenGL format
// - OpenGL type
// - bpp
// - compressed
int gPVRFormats[][6] = {
	/*
	 * 4444, 5551 and 565 has problem in testing, so only enabled for iOS
	 * pvrtc 2/4 is power vr only, also for iOS
	 */
	{ PVR_RGBA_4444, GL_RGBA, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, 16, 0 },
	{ PVR_RGBA_5551, GL_RGBA, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1, 16, 0 },
    { PVR_RGBA_8888, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, 32, 0 },
	{ PVR_RGB_565, GL_RGB, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, 16, 0 },
    { PVR_I_8, GL_LUMINANCE, GL_LUMINANCE, GL_UNSIGNED_BYTE, 8, 0 },
    { PVR_AI_88, GL_LUMINANCE_ALPHA, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, 16, 0 },
#if IOS
	{ PVR_PVRTC_2, GL_COMPRESSED_RGBA_PVRTC_2BPPV1_IMG, -1, -1, 2, 1 },
	{ PVR_PVRTC_4, GL_COMPRESSED_RGBA_PVRTC_4BPPV1_IMG, -1, -1, 4, 1 },
	{ PVR_BGRA_8888, GL_RGBA, GL_BGRA, GL_UNSIGNED_BYTE, 32, 0 },
#endif
    { PVR_A_8, GL_ALPHA, GL_ALPHA, GL_UNSIGNED_BYTE, 8, 0 }
};
int PVR_FORMAT_TABLE_ELEMENTS = (sizeof(gPVRFormats) / sizeof(gPVRFormats[0]));
