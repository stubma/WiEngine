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
#include "CEGUIWiEngineImageCodec.h"
#include "CEGUISize.h"
#include "WiEngine.h"

namespace CEGUI 
{

WiEngineImageCodec::WiEngineImageCodec() :
		ImageCodec("WiEngineImageCodec - Official WiEngine based image codec") {
	d_supportedFormat = "png jpg bmp";
}

WiEngineImageCodec::~WiEngineImageCodec() {
}
    
Texture* WiEngineImageCodec::load(const RawDataContainer& data, Texture* result) {
	// get pointer and size
	const uint8* p = data.getDataPtr();
	size_t size = data.getSize();

	// check image type and load
	float w, h;
	float scale = wyDevice::density / wyDevice::defaultInDensity;
	char* decoded = NULL;
	if(isPNG(p, size)) {
		decoded = wyUtils::loadPNG((const char*)p, size, &w, &h, false, scale, scale);
	} else if(isJPG(p, size)) {
		decoded = wyUtils::loadJPG((const char*)p, size, &w, &h, false, scale, scale);
	} else if(isBMP(p, size)) {
		decoded = wyUtils::loadBMP((const char*)p, size, &w, &h, false, scale, scale);
	}

	// if image is decoded successfully, create Texture
	if(decoded) {
	    result->loadFromMemory((const void*)decoded, Size(w, h), Texture::PF_RGBA);
	} else {
		return NULL;
	}
}

bool WiEngineImageCodec::isPNG(const uint8* p, size_t size) {
	if(size >= 8 &&
			p[0] == 0x89 &&
			p[1] == 0x50 &&
			p[2] == 0x4E &&
			p[3] == 0x47 &&
			p[4] == 0x0D &&
			p[5] == 0x0A &&
			p[6] == 0x1A &&
			p[7] == 0x0A)
		return true;
	else
		return false;
}

bool WiEngineImageCodec::isJPG(const uint8* p, size_t size) {
	if(size >= 4 &&
			p[0] == 0xFF &&
			p[1] == 0xD8 &&
			p[2] == 0xFF &&
			p[3] == 0xE0)
		return true;
	else
		return false;
}

bool WiEngineImageCodec::isBMP(const uint8* p, size_t size) {
	if(size >= 2 && p[0] == 'B' && p[1] == 'M')
		return true;
	else
		return false;
}

} // End of CEGUI namespace section
