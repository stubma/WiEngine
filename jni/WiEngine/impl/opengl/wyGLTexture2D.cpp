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
#include "wyGLTexture2D.h"
#include "wyUtils.h"
#include "wyTypes.h"
#include "wyEventDispatcher.h"
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "wyLog.h"
#include "wyDirector.h"
#include "wyGlobal.h"
#include "wyColorFilter.h"

extern wyDirector* gDirector;
extern pthread_mutex_t gCondMutex;
extern wyEventDispatcher* gEventDispatcher;

wyGLTexture2D::~wyGLTexture2D() {
	// delete opengl texture if surface is still there
	deleteTexture(gDirector == NULL || !gDirector->isSurfaceCreated() || gDirector->isEnding());

	// release color filter
	wyObjectRelease(m_filter);

	// release specific info
	switch(m_source) {
		case SOURCE_PNG:
		case SOURCE_PVR:
		case SOURCE_JPG:
			if(m_path != NULL)
				wyFree((void*)m_path);
			if(m_mfsName != NULL)
				wyFree((void*)m_mfsName);
			break;
		case SOURCE_LABEL:
			wyFree((void*)m_text);
			if(m_fontName != NULL)
				wyFree((void*)m_fontName);
			if(m_fontPath != NULL)
				wyFree((void*)m_fontPath);
			break;
	}
}

wyGLTexture2D* wyGLTexture2D::makeBMP(int resId, int transparentColor, wyTexturePixelFormat pixelFormat) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_source = SOURCE_BMP;
	tex->m_resId = resId;
	tex->m_transparentColor = transparentColor;

	// init size
	size_t width, height;
	wyUtils::loadBMP(resId, &width, &height, true);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeJPG(int resId, int transparentColor, wyTexturePixelFormat pixelFormat) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_JPG;
	tex->m_resId = resId;

	// init size
	size_t width, height;
	wyUtils::loadJPG(resId, &width, &height, true);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makePNG(int resId, wyTexturePixelFormat pixelFormat) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_source = SOURCE_PNG;
	tex->m_resId = resId;

	// init size
	size_t width, height;
	wyUtils::loadPNG(resId, &width, &height, true);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makePVR(int resId) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_source = SOURCE_PVR;
	tex->m_resId = resId;

	// init size
	size_t width, height;
	float scale;
	wyUtils::getPVRSize(resId, &width, &height, &scale);
	tex->m_inDensity = wyDevice::density / scale;
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeRawBMP(const char* data, size_t length, int transparentColor, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_BMP;
	tex->m_data = data;
	tex->m_length = length;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	size_t width, height;
	wyUtils::loadBMP(data, length, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return (wyGLTexture2D*)tex->autoRelease();
}

wyGLTexture2D* wyGLTexture2D::makeRawJPG(const char* data, size_t length, int transparentColor, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_JPG;
	tex->m_data = data;
	tex->m_length = length;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	size_t width, height;
	wyUtils::loadJPG(data, length, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return (wyGLTexture2D*)tex->autoRelease();
}

wyGLTexture2D* wyGLTexture2D::makeRawPNG(const char* data, size_t length, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->m_pixelFormat = pixelFormat;
	tex->m_source = SOURCE_PNG;
	tex->m_data = data;
	tex->m_length = length;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	size_t width, height;
	wyUtils::loadPNG(data, length, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return (wyGLTexture2D*)tex->autoRelease();
}

wyGLTexture2D* wyGLTexture2D::makeRawPVR(const char* data, size_t length, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->m_source = SOURCE_PVR;
	tex->m_data = data;
	tex->m_length = length;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	size_t width, height;
	wyUtils::getPVRSize(data, length, &width, &height, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return (wyGLTexture2D*)tex->autoRelease();
}

wyGLTexture2D* wyGLTexture2D::makeBMP(const char* assetPath, int transparentColor, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_BMP;
	tex->m_path = wyUtils::copy(assetPath);
	tex->m_isFile = false;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	size_t width, height;
	wyUtils::loadBMP(assetPath, false, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeJPG(const char* assetPath, int transparentColor, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_JPG;
	tex->m_path = wyUtils::copy(assetPath);
	tex->m_isFile = false;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	size_t width, height;
	wyUtils::loadJPG(assetPath, false, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makePNG(const char* assetPath, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_source = SOURCE_PNG;
	tex->m_path = wyUtils::copy(assetPath);
	tex->m_isFile = false;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	size_t width, height;
	wyUtils::loadPNG(assetPath, false, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makePVR(const char* assetPath, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_source = SOURCE_PVR;
	tex->m_path = wyUtils::copy(assetPath);
	tex->m_isFile = false;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	size_t width, height;
	wyUtils::getPVRSize(assetPath, false, &width, &height, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeMemoryBMP(const char* mfsName, int transparentColor, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_BMP;
	tex->m_mfsName = wyUtils::copy(mfsName);
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// get data from memory file system
	const char* mfsData = NULL;
	size_t length = 0;
	wyUtils::getFile(mfsName, &mfsData, &length);

	// init size
	size_t width, height;
	wyUtils::loadBMP(mfsData, length, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeMemoryJPG(const char* mfsName, int transparentColor, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_JPG;
	tex->m_mfsName = wyUtils::copy(mfsName);
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// get data from memory file system
	const char* mfsData = NULL;
	size_t length = 0;
	wyUtils::getFile(mfsName, &mfsData, &length);

	// init size
	size_t width, height;
	wyUtils::loadJPG(mfsData, length, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeMemoryPNG(const char* mfsName, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_source = SOURCE_PNG;
	tex->m_mfsName = wyUtils::copy(mfsName);
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// get data from memory file system
	const char* mfsData = NULL;
	size_t length = 0;
	wyUtils::getFile(mfsName, &mfsData, &length);

	// init size
	size_t width, height;
	wyUtils::loadPNG(mfsData, length, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeMemoryPVR(const char* mfsName, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_source = SOURCE_PVR;
	tex->m_mfsName = wyUtils::copy(mfsName);
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// get data from memory file system
	const char* mfsData = NULL;
	size_t length = 0;
	wyUtils::getFile(mfsName, &mfsData, &length);

	// init size
	size_t width, height;
	wyUtils::getPVRSize(mfsData, length, &width, &height, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeFileBMP(const char* fsPath, int transparentColor, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_BMP;
	tex->m_path = wyUtils::copy(fsPath);
	tex->m_isFile = true;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	size_t width, height;
	wyUtils::loadBMP(fsPath, true, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeFileJPG(const char* fsPath, int transparentColor, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_JPG;
	tex->m_path = wyUtils::copy(fsPath);
	tex->m_isFile = true;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	size_t width, height;
	wyUtils::loadJPG(fsPath, true, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeFilePNG(const char* fsPath, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_source = SOURCE_PNG;
	tex->m_path = wyUtils::copy(fsPath);
	tex->m_isFile = true;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	size_t width, height;
	wyUtils::loadPNG(fsPath, true, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeFilePVR(const char* fsPath, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_source = SOURCE_PVR;
	tex->m_path = wyUtils::copy(fsPath);
	tex->m_isFile = true;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	size_t width, height;
	wyUtils::getPVRSize(fsPath, true, &width, &height, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeLabel(const char* text, float fontSize, const char* fontPath, bool isFile, float width, wyTexture2D::TextAlignment alignment) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->m_source = SOURCE_LABEL;
	tex->m_text = wyUtils::copy(text);
	tex->m_fontPath = wyUtils::copy(fontPath);
	tex->m_isFile = isFile;
	tex->m_fontSize = fontSize;
	tex->m_lineWidth = width;
	tex->m_alignment = alignment;

	wySize size = wyUtils::calculateTextSize(text, fontSize, fontPath, isFile, width);
	tex->initSize(size.width, size.height);

	return (wyGLTexture2D*)tex->autoRelease();
}

wyGLTexture2D* wyGLTexture2D::makeLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width, wyTexture2D::TextAlignment alignment) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->m_source = SOURCE_LABEL;
	tex->m_text = wyUtils::copy(text);
	tex->m_fontName = wyUtils::copy(fontName);
	tex->m_fontSize = fontSize;
	tex->m_fontStyle = style;
	tex->m_lineWidth = width;
	tex->m_alignment = alignment;

	wySize size = wyUtils::calculateTextSize(text, fontSize, style, fontName, width);
	tex->initSize(size.width, size.height);

	return (wyGLTexture2D*)tex->autoRelease();
}

wyGLTexture2D* wyGLTexture2D::makeGL(int texture, int w, int h) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->m_source = SOURCE_OPENGL;
	tex->m_texture = texture;
	tex->initSize(w, h);
	tex->m_flipY = true;

	return (wyGLTexture2D*)tex->autoRelease();
}

wyGLTexture2D* wyGLTexture2D::makeRaw(const char* data, int width, int height, wyTexturePixelFormat format) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->m_pixelFormat = format;
	tex->m_source = SOURCE_RAW;
	tex->m_data = data;
	tex->m_length = width * height * 4;

	// init size
	tex->initSize(width, height);

	return (wyGLTexture2D*)tex->autoRelease();
}

wyGLTexture2D::wyGLTexture2D() :
		m_source(SOURCE_INVALID),
		m_pixelFormat(WY_TEXTURE_PIXEL_FORMAT_RGBA8888),
		m_transparentColor(0),
		m_resId(0),
		m_path(NULL),
		m_isFile(false),
		m_pvrFormatIndex(0),
		m_hasAlpha(false),
		m_text(NULL),
		m_fontName(NULL),
		m_fontSize(0),
		m_fontStyle(NORMAL),
		m_fontPath(NULL),
		m_alignment(wyTexture2D::LEFT),
		m_needUpdateLabel(false),
		m_widthScale(0),
		m_heightScale(0),
		m_texture(0),
		m_pixelWidth(0),
		m_pixelHeight(0),
		m_width(0),
		m_height(0),
		m_minFilter(GL_LINEAR),
		m_magFilter(GL_LINEAR),
		m_wrapS(GL_REPEAT),
		m_wrapT(GL_REPEAT),
		m_flipX(false),
		m_flipY(false),
		m_mfsName(NULL),
		m_data(NULL),
		m_filter(NULL),
		m_length(0),
		m_inDensity(wyDevice::defaultInDensity) {
}

void wyGLTexture2D::initSize(int realWidth, int realHeight) {
	m_width = realWidth;
	m_height = realHeight;
	m_pixelWidth = wyMath::getNextPOT(realWidth);
	m_pixelHeight = wyMath::getNextPOT(realHeight);
	m_widthScale = m_width / m_pixelWidth;
	m_heightScale = m_height / m_pixelHeight;
}

char* wyGLTexture2D::loadPNG() {
	char* raw = NULL;
	float scale = wyDevice::density / m_inDensity;
	size_t w, h;
	if(m_resId != 0) {
		size_t len;
		char* png = wyUtils::loadRaw(m_resId, &len, &scale);
		raw = wyUtils::loadPNG(png, len, &w, &h, false, 1.f, 1.f);
		wyFree(png);
	} else if(m_path != NULL) {
		raw = wyUtils::loadPNG(m_path, m_isFile, &w, &h, false, 1.f, 1.f);
	} else if(m_data != NULL) {
		raw = wyUtils::loadPNG(m_data, m_length, &w, &h, false, 1.f, 1.f);
	} else if(m_mfsName != NULL) {
		// get data from memory file system
		const char* mfsData = NULL;
		size_t length = 0;
		wyUtils::getFile(m_mfsName, &mfsData, &length);

		// expand data
		raw = wyUtils::loadPNG(mfsData, length, &w, &h, false, 1.f, 1.f);
	} else {
		LOGE("PNG texture doesn't has any input!");
	}

	// post processing
	if(raw) {
		// apply filter
		applyFilter(raw, w, h);

		// scale
		char* scaled = wyUtils::scaleImage(raw, w, h, scale, scale);
		if(raw != scaled) {
			wyFree(raw);
			raw = scaled;
		}
	}

	return raw;
}

char* wyGLTexture2D::loadBMP() {
	// decompress bmp data in RGBA8888
	float scale = wyDevice::density / m_inDensity;
	char* raw = NULL;
	size_t w, h;
	if(m_resId != 0) {
		size_t len;
		char* bmp = wyUtils::loadRaw(m_resId, &len, &scale);
		raw = wyUtils::loadBMP(bmp, len, &w, &h, false, 1.f, 1.f);
		wyFree(bmp);
	} else if(m_path != NULL) {
		raw = wyUtils::loadBMP(m_path, m_isFile, &w, &h, false, 1.f, 1.f);
	} else if(m_data != NULL) {
		raw = wyUtils::loadBMP(m_data, m_length, &w, &h, false, 1.f, 1.f);
	} else if(m_mfsName != NULL) {
		// get data from memory file system
		const char* mfsData = NULL;
		size_t length = 0;
		wyUtils::getFile(m_mfsName, &mfsData, &length);

		// expand data
		raw = wyUtils::loadBMP(mfsData, length, &w, &h, false, 1.f, 1.f);
	} else {
		LOGE("BMP texture doesn't has any input!");
	}

	/*
	 * post processing
	 * we must apply filter first because scaling may change some color
	 */
	if(raw) {
		// check transparent color
		if(m_transparentColor != 0) {
			char* p = raw;
			for(int y = 0; y < h; y++) {
				for(int x = 0; x < w; x++) {
					// get pixel color
					unsigned int r = p[0] & 0xFF;
					unsigned int g = p[1] & 0xFF;
					unsigned int b = p[2] & 0xFF;
					unsigned int c = (r << 16) | (g << 8) | b;

					// if pixel is same as transparent color, set this pixel to transparent
					if((c ^ m_transparentColor) == 0) {
						*(int*)p = 0;
					}

					// increase pointer
					p += 4;
				}
			}
		}

		// apply filter
		applyFilter(raw, w, h);

		// scale
		char* scaled = wyUtils::scaleImage(raw, w, h, scale, scale);
		if(raw != scaled) {
			wyFree(raw);
			raw = scaled;
		}
	}

	return raw;
}

char* wyGLTexture2D::loadJPG() {
	// decompress jpg data in RGBA8888
	float scale = wyDevice::density / m_inDensity;
	char* raw = NULL;
	size_t w, h;
	if(m_resId != 0) {
		size_t len;
		char* jpg = wyUtils::loadRaw(m_resId, &len, &scale);
		raw = wyUtils::loadJPG(jpg, len, &w, &h, false, 1.f, 1.f);
		wyFree(jpg);
	} else if(m_path != NULL) {
		raw = wyUtils::loadJPG(m_path, m_isFile, &w, &h, false, 1.f, 1.f);
	} else if(m_data != NULL) {
		raw = wyUtils::loadJPG(m_data, m_length, &w, &h, false, 1.f, 1.f);
	} else if(m_mfsName != NULL) {
		// get data from memory file system
		const char* mfsData = NULL;
		size_t length = 0;
		wyUtils::getFile(m_mfsName, &mfsData, &length);

		// expand data
		raw = wyUtils::loadJPG(mfsData, length, &w, &h, false, 1.f, 1.f);
	} else {
		LOGE("JPG texture doesn't has any input!");
	}

	/*
	 * post processing
	 * we must apply filter first because scaling may change some color
	 */
	if(raw) {
		// check transparent color
		if(m_transparentColor != 0) {
			char* p = raw;
			for(int y = 0; y < h; y++) {
				for(int x = 0; x < w; x++) {
					// get pixel color
					unsigned int r = p[0] & 0xFF;
					unsigned int g = p[1] & 0xFF;
					unsigned int b = p[2] & 0xFF;
					unsigned int c = (r << 16) | (g << 8) | b;

					// if pixel is same as transparent color, set this pixel to transparent
					if((c ^ m_transparentColor) == 0) {
						*(int*)p = 0;
					}

					// increase pointer
					p += 4;
				}
			}
		}

		// apply filter
		applyFilter(raw, w, h);

		// scale
		char* scaled = wyUtils::scaleImage(raw, w, h, scale, scale);
		if(raw != scaled) {
			wyFree(raw);
			raw = scaled;
		}
	}

	return raw;
}

void wyGLTexture2D::load() {
	// if loaded and no update scheduled, return
	if(m_texture != 0 && !(m_needUpdateLabel && m_source == SOURCE_LABEL))
		return;

	// check thread, if not in gl thread, we need wait
	if(!isGLThread()) {
		pthread_cond_t cond;
		if(pthread_cond_init(&cond, NULL) == 0) {
			if(gEventDispatcher != NULL) {
				pthread_mutex_lock(&gCondMutex);
				gEventDispatcher->queueEventLocked(ET_LOAD_TEXTURE, this, &cond);
				pthread_cond_wait(&cond, &gCondMutex);
				pthread_mutex_unlock(&gCondMutex);
			}

			pthread_cond_destroy(&cond);
		}
	} else {
		doLoad();
	}
}

void wyGLTexture2D::doLoad() {
	switch(m_source) {
		case SOURCE_LABEL:
		{
			// create bitmap
			const char* bitmap = m_fontPath == NULL ?
					wyUtils::createLabelBitmap(m_text, m_fontSize, m_fontStyle, m_fontName, m_lineWidth, m_alignment) :
					wyUtils::createLabelBitmap(m_text, m_fontSize, m_fontPath, m_isFile, m_lineWidth, m_alignment);

			// load texture from bitmap
			if(bitmap != NULL) {
				// make texture ready
				if(m_texture == 0) {
					glGenTextures(1, (GLuint*)&m_texture);
				}
				glBindTexture(GL_TEXTURE_2D, m_texture);
				applyParameters();

				// update texture
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);

				// free
				wyFree((void*)bitmap);
			}

			// reset flag
			m_needUpdateLabel = false;
			break;
		}
		case SOURCE_BMP:
		{
			// generate texture and set parameter
			glGenTextures(1, (GLuint*)&m_texture);
			glBindTexture(GL_TEXTURE_2D, m_texture);
			applyParameters();

			// decompress jpg data in RGBA8888
			char* raw = loadBMP();
			if(raw == NULL)
				return;

			// convert data format
			const char* data = convertPixelFormat(raw);
			if(data != raw) {
				wyFree(raw);
			}

			// generate texture
			switch(m_pixelFormat) {
				case WY_TEXTURE_PIXEL_FORMAT_RGBA8888:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_RGB565:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_pixelWidth, m_pixelHeight, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_RGBA4444:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_RGBA5551:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_A8:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, m_pixelWidth, m_pixelHeight, 0, GL_ALPHA, GL_UNSIGNED_BYTE, data);
					break;
			}

			wyFree((void*)data);
			break;
		}
		case SOURCE_JPG:
		{
			// generate texture and set parameter
			glGenTextures(1, (GLuint*)&m_texture);
			glBindTexture(GL_TEXTURE_2D, m_texture);
			applyParameters();

			// decompress jpg data in RGBA8888
			char* raw = loadJPG();
			if(raw == NULL)
				return;

			// convert data format
			const char* data = convertPixelFormat(raw);
			if(data != raw) {
				wyFree(raw);
			}

			// generate texture
			switch(m_pixelFormat) {
				case WY_TEXTURE_PIXEL_FORMAT_RGBA8888:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_RGB565:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_pixelWidth, m_pixelHeight, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_RGBA4444:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_RGBA5551:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_A8:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, m_pixelWidth, m_pixelHeight, 0, GL_ALPHA, GL_UNSIGNED_BYTE, data);
					break;
			}

			wyFree((void*)data);
			break;
		}
		case SOURCE_PNG:
		{
			// generate texture and set parameter
			glGenTextures(1, (GLuint*)&m_texture);
			glBindTexture(GL_TEXTURE_2D, m_texture);
			applyParameters();

			// get expanded png data in RGBA8888
			char* raw = loadPNG();
			if(raw == NULL)
				return;

			// convert data format
			const char* data = convertPixelFormat(raw);
			if(data != raw) {
				wyFree(raw);
			}

			// generate texture
			switch(m_pixelFormat) {
				case WY_TEXTURE_PIXEL_FORMAT_RGBA8888:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_RGB565:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_pixelWidth, m_pixelHeight, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_RGBA4444:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_RGBA5551:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_A8:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, m_pixelWidth, m_pixelHeight, 0, GL_ALPHA, GL_UNSIGNED_BYTE, data);
					break;
			}

			wyFree((void*)data);
			break;
		}
		case SOURCE_PVR:
		{
			// get fd
			char* raw = NULL;
			bool freeRaw = true;
			if(m_resId != 0) {
				raw = wyUtils::loadRaw(m_resId);
			} else if(m_path != NULL) {
				raw = wyUtils::loadRaw(m_path, m_isFile);
			} else if(m_data != NULL) {
				raw = (char*)m_data;
				freeRaw = false;
			} else if(m_mfsName != NULL) {
				// get data from memory file system
				const char* mfsData = NULL;
				size_t length = 0;
				wyUtils::getFile(m_mfsName, &mfsData, &length);

				raw = (char*)mfsData;
				freeRaw = false;
			} else {
				LOGE("PVR texture doesn't has any input!");
				return;
			}

			// directly copy header out
			wyPVRHeader header;
			memcpy(&header, raw, sizeof(wyPVRHeader));

			// convert endian
			wyUtils::convertPVRHeaderEndian(&header);

			// generate texture and set parameter
			glGenTextures(1, (GLuint*)&m_texture);
			glBindTexture(GL_TEXTURE_2D, m_texture);
			applyParameters();

			// unpack pvr data
			int* mipmapLens = NULL;
			char** mipmaps = wyUtils::unpackPVRData(raw, &header, &mipmapLens, &m_pvrFormatIndex, &m_hasAlpha);

			// start to generate texture
			if(mipmaps != NULL) {
				int size = header.numMipmaps + 1;
				int width = header.width;
				int height = header.height;
				bool nPOT = m_pixelWidth != m_width || m_pixelHeight != m_height;

				for(int i = 0; i < size; i++) {
					int internalFormat = gPVRFormats[m_pvrFormatIndex][PVR_INDEX_INTERNAL_FORMAT];
					int format = gPVRFormats[m_pvrFormatIndex][PVR_INDEX_OPENGL_FORMAT];
					int type = gPVRFormats[m_pvrFormatIndex][PVR_INDEX_OPENGL_TYPE];
					int bpp = gPVRFormats[m_pvrFormatIndex][PVR_INDEX_BPP];
					bool compressed = gPVRFormats[m_pvrFormatIndex][PVR_INDEX_COMPRESSED] == 1;
					if(compressed) {
						// compressed pvr are always POT size
						glCompressedTexImage2D(GL_TEXTURE_2D, i, internalFormat, width, height, 0, mipmapLens[i], mipmaps[i]);
					} else {
						/*
						 * XXX: 在iOS平台上缩放PVR有些麻烦, 暂不支持, 为了保持WiEngine在Android和iOS上的行为一致, 这里
						 * 暂时不再缩放PVR贴图
						 */
						// if density is not 1.0f, need try to scale pvr
						// but some pvr format is not supported by skia
//						float scale = wyDevice::density / m_inDensity;
//						if(scale != 1.0f) {
//							wyPVRFormat pvrFormat = (wyPVRFormat)gPVRFormats[m_pvrFormatIndex][PVR_INDEX_TEXTURE_FORMAT];
//							char* data = wyUtils::scalePVR(pvrFormat, mipmaps[i], width, height, scale);
//							if(data != mipmaps[i]) {
//								wyFree(mipmaps[i]);
//								mipmaps[i] = data;
//								width = width * scale + 0.5f;
//								height = height * scale + 0.5f;
//							}
//						}

						if(nPOT) {
							/*
							 * 之前通过glTexSubImage2D方法来实现对一个POT大小的贴图进行替换, 在Android上运行正常, 
							 * 但是在iOS上却是乱的, 可能和glTexSubImage2D在不同平台的实现有关, 因此在这里使用一种
							 * 更安全的方法, 把非POT数据拷贝到POT数组中再直接调用glTexImage2D. 这个情况只对PVR出现,
							 * 如果是PNG或JPG, 都没有这个问题, 估计和format也有关系, 因为PNG和JPG都是用RGBA8888处理的,
							 * 如果PVR也用RGBA8888, 原来的代码也不会有问题
							 */
							int potWidth = wyMath::getNextPOT(width);
							int potHeight = wyMath::getNextPOT(height);
							GLubyte* pixels = (GLubyte*)wyCalloc(potWidth * potHeight * bpp / 8, sizeof(GLubyte));
							int rowBytes = width * bpp / 8;
							int potRowBytes = potWidth * bpp / 8;
							for(int y = 0; y < height; y++) {
								memcpy(pixels + potRowBytes * y, mipmaps[i] + rowBytes * y, rowBytes);
							}
							glTexImage2D(GL_TEXTURE_2D, i, internalFormat, potWidth, potHeight, 0, format, type, pixels);
							wyFree(pixels);
						} else {
							glTexImage2D(GL_TEXTURE_2D, i, internalFormat, width, height, 0, format, type, mipmaps[i]);
						}
					}

					int err = glGetError();
					if(err != GL_NO_ERROR) {
						LOGW("Error uploading compressed texture level: %d . glError: 0x%04X", i, err);
						break;
					}

					width = MAX(width >> 1, 1);
					height = MAX(height >> 1, 1);

					// free this data
					wyFree(mipmaps[i]);
				}

				// free mipmaps
				wyFree(mipmaps);
				wyFree(mipmapLens);
			}

			// free raw
			if(freeRaw)
				wyFree(raw);

			break;
		}
		case SOURCE_RAW:
		{
			// generate texture and set parameter
			glGenTextures(1, (GLuint*)&m_texture);
			glBindTexture(GL_TEXTURE_2D, m_texture);
			applyParameters();

			// apply filter
			char* data = (char*)m_data;
			if(m_filter) {
				size_t len = sizeof(char) * m_width * m_height * 4;
				data = (char*)wyMalloc(len);
				memcpy(data, m_data, len);
				applyFilter(data, m_width, m_height);
			}

			// convert data format
			data = (char*)convertPixelFormat((const char*)data);

			// generate texture
			switch(m_pixelFormat) {
				case WY_TEXTURE_PIXEL_FORMAT_RGBA8888:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_RGB565:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_pixelWidth, m_pixelHeight, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_RGBA4444:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_RGBA5551:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_pixelWidth, m_pixelHeight, 0, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1, data);
					break;
				case WY_TEXTURE_PIXEL_FORMAT_A8:
					glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, m_pixelWidth, m_pixelHeight, 0, GL_ALPHA, GL_UNSIGNED_BYTE, data);
					break;
			}

			// release
			if(data != m_data) {
				wyFree((void*)data);
			}

			break;
		}
	}

	/*
	 * XXX:
	 * 有时候即使上面的代码已经载入了贴图, 但是实际使用时, 仍然卡一下. 尤其是贴图比较大的时候. 但是
	 * 第二次则不会, 猜测是贴图尚未渲染过的时候, 并不在显卡缓冲中. 为了解决这个问题, 这里强行渲染一次,
	 * 只不过渲染在屏幕之外, 从而保证这个贴图被显卡缓冲, 消除了卡的现象. 目前还不知道是有更好的办法.
	 */
	if(m_texture != 0) {
        // get vertices
        float vertices[] = {
            -10000, -10000, 0.0f,
            -10000 + m_width, -10000, 0.0f,
            -10000, -10000 + m_height, 0.0f,
            -10000 + m_width, -10000 + m_height, 0.0f
        };
        
        // get texture coordination
        float left = 0;
        float right = m_width / m_pixelWidth;
        float top = 0;
        float bottom = m_height / m_pixelHeight;
        float texCoords[] = {
            left, bottom,
            right, bottom,
            left, top,
            right, top
        };
   
		// TODO gles2
//      // get state
//        GLboolean vertexArrayEnabled = glIsEnabled(GL_VERTEX_ARRAY);
//        GLboolean texCoordArrayEnabled = glIsEnabled(GL_TEXTURE_COORD_ARRAY);
//        GLboolean colorArrayEnabled = glIsEnabled(GL_COLOR_ARRAY);
//        GLboolean tex2dEnabled = glIsEnabled(GL_TEXTURE_2D);
//        
//        // enable states
//        if(!vertexArrayEnabled)
//            glEnableClientState(GL_VERTEX_ARRAY);
//        if(!texCoordArrayEnabled)
//            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//        if(colorArrayEnabled)
//            glDisableClientState(GL_COLOR_ARRAY);
//        if(!tex2dEnabled)
//            glEnable(GL_TEXTURE_2D);
//			
//        // ensure current texture is active
//        glBindTexture(GL_TEXTURE_2D, m_texture);
//        
//        // set vertices and texture coordination and draw
//        glVertexPointer(3, GL_FLOAT, 0, vertices);
//        glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
//        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//        
//        // disable states
//        if(!vertexArrayEnabled)
//            glDisableClientState(GL_VERTEX_ARRAY);
//        if(!texCoordArrayEnabled) 
//            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//        if(colorArrayEnabled)
//            glEnableClientState(GL_COLOR_ARRAY);
//        if(!tex2dEnabled)
//            glDisable(GL_TEXTURE_2D);
	}
}

void wyGLTexture2D::updateLabel(const char* text) {
	// create string, update it
	if(m_fontPath == NULL)
		updateLabel(text, m_fontSize, m_fontStyle, m_fontName, m_lineWidth, m_alignment);
	else
		updateLabel(text, m_fontSize, m_fontPath, m_isFile, m_lineWidth, m_alignment);
}

void wyGLTexture2D::updateLabel(const char* text, float fontSize, const char* fontPath, bool isFile, float lineWidth, wyTexture2D::TextAlignment alignment) {
	if(m_source != SOURCE_LABEL) {
		LOGW("Only a label texture can be updated");
		return;
	}

	if(text == NULL) {
		LOGW("Update label: text must be set");
		return;
	}

	// release old value and keep new value
	// ensure the argument is not same current value
	if(m_text != text) {
		if(m_text != NULL) {
			wyFree((void*)m_text);
		}
		m_text = wyUtils::copy(text);
	}
	if(m_fontName != NULL) {
		wyFree((void*)m_fontName);
		m_fontName = NULL;
	}
	if(m_fontPath != fontPath) {
		if(m_fontPath != NULL) {
			wyFree((void*)m_fontPath);
		}
		m_fontPath = wyUtils::copy(fontPath);
	}
	m_fontSize = fontSize;
	m_isFile = isFile;
	m_alignment = alignment;

	// update to new size
	wySize size = wyUtils::calculateTextSize(text, fontSize, fontPath, isFile, lineWidth);
	initSize(size.width, size.height);

	// set flag
	m_needUpdateLabel = true;
}

void wyGLTexture2D::updateLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName, float lineWidth, wyTexture2D::TextAlignment alignment) {
	// it must be a label
	if(m_source != SOURCE_LABEL) {
		LOGW("Only a label texture can be updated");
		return;
	}

	// text must not be empty
	if(text == NULL) {
		LOGW("Update label: text must be set");
		return;
	}

	// release old value and keep new value
	// ensure the argument is not same current value
	if(m_text != text) {
		if(m_text != NULL) {
			wyFree((void*)m_text);
		}
		m_text = wyUtils::copy(text);
	}
	if(m_fontName != fontName) {
		if(m_fontName != NULL) {
			wyFree((void*)m_fontName);
			m_fontName = wyUtils::copy(fontName);
		}
	}
	if(m_fontPath != NULL) {
		wyFree((void*)m_fontPath);
		m_fontPath = NULL;
	}
	m_fontStyle = style;
	m_fontSize = fontSize;
	m_lineWidth = lineWidth;

	// update to new size
	wySize size = wyUtils::calculateTextSize(text, fontSize, style, fontName, lineWidth);
	initSize(size.width, size.height);

	// set flag
	m_needUpdateLabel = true;
}

void wyGLTexture2D::deleteTexture(bool noDeleteGL) {
	/*
	 * opengl context may already destroyed so deleting texture may cause unexpected
	 * problem. If so, set noDeleteGL to true to avoid possible problem
	 */
	if(m_texture != 0) {
		if(!noDeleteGL) {
			if(!isGLThread()) {
				pthread_cond_t cond;
				if(pthread_cond_init(&cond, NULL) == 0) {
					if(gEventDispatcher != NULL) {
						pthread_mutex_lock(&gCondMutex);
						gEventDispatcher->queueEventLocked(ET_DELETE_TEXTURE, this, &cond);
						pthread_cond_wait(&cond, &gCondMutex);
						pthread_mutex_unlock(&gCondMutex);
					}

					pthread_cond_destroy(&cond);
				}
			} else {
				glDeleteTextures(1, (GLuint*)&m_texture);
			}
		}
		m_texture = 0;
	}
}

void wyGLTexture2D::setAntiAlias(bool on) {
	if(on) {
		m_minFilter = GL_LINEAR;
		m_magFilter = GL_LINEAR;
	} else {
		m_minFilter = GL_NEAREST;
		m_magFilter = GL_NEAREST;
	}
}

void wyGLTexture2D::setRepeat(bool on) {
	if(on) {
		m_wrapS = GL_REPEAT;
		m_wrapT = GL_REPEAT;
	} else {
		m_wrapS = GL_CLAMP_TO_EDGE;
		m_wrapT = GL_CLAMP_TO_EDGE;
	}
}

void wyGLTexture2D::setParameters(int min, int mag, int wrapS, int wrapT) {
	m_minFilter = min;
	m_magFilter = mag;
	m_wrapS = wrapS;
	m_wrapT = wrapT;
}

void wyGLTexture2D::applyParameters() {
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_minFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_magFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_wrapS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_wrapT);
}

bool wyGLTexture2D::hasPremultipliedAlpha() {
	// XXX not implemented
	return false;
}

void wyGLTexture2D::draw(float x, float y) {
	draw(x, y, m_flipX, m_flipY);
}

void wyGLTexture2D::draw(float x, float y, bool flipX, bool flipY) {
	wyRect rect = {0, 0, m_width, m_height};
	draw(x, y, m_width, m_height, flipX, flipY, rect);
}

void wyGLTexture2D::draw(float x, float y, float width, float height) {
	draw(x, y, width, height, m_flipX, m_flipY);
}

void wyGLTexture2D::draw(float x, float y, float width, float height, bool flipX, bool flipY) {
	wyRect rect = {0, 0, m_width, m_height};
	draw(x, y, width, height, flipX, flipY, rect);
}

void wyGLTexture2D::draw(float x, float y, float width, float height, bool flipX, bool flipY, wyRect texRect) {
	draw(x, y, width, height, flipX, flipY, texRect, false);
}

void wyGLTexture2D::draw(float x, float y, float width, float height, bool flipX, bool flipY, wyRect texRect, bool rotatedZwoptex) {
	draw(x, y, width, height, width, height, flipX, flipY, texRect, rotatedZwoptex);
}

void wyGLTexture2D::draw(float x, float y, float width, float height, float sourceWidth, float sourceHeight, bool flipX, bool flipY, wyRect texRect, bool rotatedZwoptex) {
	// ensure texture object is created
	load();

	// get vertices
	float vertices[] = {
		x, y, 0.0f,
		width + x, y, 0.0f,
		x, height + y, 0.0f,
		width + x, height + y, 0.0f
	};

	// get texture coordination
    float left = (2 * texRect.x + 1) / (2 * m_pixelWidth);
    float right = left + (texRect.width * 2 - 2) / (2 * m_pixelWidth);
    float top = (2 * texRect.y + 1) / (2 * m_pixelHeight);
    float bottom = top + (texRect.height * 2 - 2) / (2 * m_pixelHeight);
    float texCoords[] = {
		left, bottom,
		right, bottom,
		left, top,
		right, top
    };

    // is a rotated zwoptex frame?
    if(rotatedZwoptex) {
    	float bl_x = texCoords[0];
    	float bl_y = texCoords[1];

    	// tl -> bl
    	texCoords[0] = texCoords[4];
    	texCoords[1] = texCoords[5];

    	// tr -> tl
    	texCoords[4] = texCoords[6];
    	texCoords[5] = texCoords[7];

    	// br -> tr
    	texCoords[6] = texCoords[2];
    	texCoords[7] = texCoords[3];

    	// bl -> br
    	texCoords[2] = bl_x;
    	texCoords[3] = bl_y;
    }

    // if flip y axis
	if(flipY) {
		wyUtils::swap(texCoords, 0, 4);
		wyUtils::swap(texCoords, 1, 5);
		wyUtils::swap(texCoords, 2, 6);
		wyUtils::swap(texCoords, 3, 7);

		// adjust vertices y value
		vertices[1] = sourceHeight - vertices[1];
		vertices[4] = sourceHeight - vertices[4];
		vertices[7] = sourceHeight - vertices[7];
		vertices[10] = sourceHeight - vertices[10];

		// swap bl and tl, swap br and tr
		wyUtils::swap(vertices, 0, 6);
		wyUtils::swap(vertices, 1, 7);
		wyUtils::swap(vertices, 2, 8);
		wyUtils::swap(vertices, 3, 9);
		wyUtils::swap(vertices, 4, 10);
		wyUtils::swap(vertices, 5, 11);
	}

	// if flip x axis
	if(flipX) {
		wyUtils::swap(texCoords, 0, 2);
		wyUtils::swap(texCoords, 1, 3);
		wyUtils::swap(texCoords, 4, 6);
		wyUtils::swap(texCoords, 5, 7);

		// adjust vertices x value
		vertices[0] = sourceWidth - vertices[0];
		vertices[3] = sourceWidth - vertices[3];
		vertices[6] = sourceWidth - vertices[6];
		vertices[9] = sourceWidth - vertices[9];

		// swap bl and br, swap tl and tr
		wyUtils::swap(vertices, 0, 3);
		wyUtils::swap(vertices, 1, 4);
		wyUtils::swap(vertices, 2, 5);
		wyUtils::swap(vertices, 6, 9);
		wyUtils::swap(vertices, 7, 10);
		wyUtils::swap(vertices, 8, 11);
	}

	// TODO gles2
//	// enable states
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//	glEnable(GL_TEXTURE_2D);
//
//	// ensure current texture is active
//	glBindTexture(GL_TEXTURE_2D, m_texture);
//
//	// apply texture parameters in both direction
//	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_wrapS);
//	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_wrapT);
//
//	// set vertices and texture coordination and draw
//	glVertexPointer(3, GL_FLOAT, 0, vertices);
//	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
//	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//
//	// disable states
//	glDisableClientState(GL_VERTEX_ARRAY);
//	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//	glDisable(GL_TEXTURE_2D);
}

const char* wyGLTexture2D::convertPixelFormat(const char* data) {
	int w = (int)m_width;
	int h = (int)m_height;
	if(m_pixelWidth != w || m_pixelHeight != h) {
		switch(m_pixelFormat) {
			case WY_TEXTURE_PIXEL_FORMAT_RGBA8888:
			{
				char* pixels = (char*)wyCalloc(m_pixelWidth * m_pixelHeight * 4, sizeof(char));
				int rowBytes = w * 4;
				int potRowBytes = m_pixelWidth * 4;
				for(int y = 0; y < h; y++) {
					memcpy(pixels + potRowBytes * y, data + rowBytes * y, rowBytes);
				}
				return (const char*)pixels;
			}
			case WY_TEXTURE_PIXEL_FORMAT_RGB565:
			{
				void* ret = wyCalloc(m_pixelWidth * m_pixelHeight * 2, sizeof(char));
				unsigned short* out = (unsigned short*)ret;
				unsigned char* in = (unsigned char*)data;
				for(int y = 0; y < h; y++, out += m_pixelWidth - w) {
					for(int x = 0; x < w; x++, in += 4, out++) {
						*out = (((in[0] & 0xFF) >> 3) << 11) | (((in[1] & 0xFF) >> 2) << 5) | ((in[2] & 0xFF) >> 3);
					}
				}
				return (const char*)ret;
			}
			case WY_TEXTURE_PIXEL_FORMAT_RGBA4444:
			{
				void* ret = wyCalloc(m_pixelWidth * m_pixelHeight * 2, sizeof(char));
				unsigned short* out = (unsigned short*)ret;
				unsigned char* in = (unsigned char*)data;
				for(int y = 0; y < h; y++, out += m_pixelWidth - w) {
					for(int x = 0; x < w; x++, in += 4, out++) {
						*out = (((in[0] & 0xFF) >> 4) << 12) | (((in[1] & 0xFF) >> 4) << 8) | (((in[2] & 0xFF) >> 4) << 4) | ((in[3] & 0xFF) >> 4);
					}
				}
				return (const char*)ret;
			}
			case WY_TEXTURE_PIXEL_FORMAT_RGBA5551:
			{
				void* ret = wyCalloc(m_pixelWidth * m_pixelHeight * 2, sizeof(char));
				unsigned short* out = (unsigned short*)ret;
				unsigned char* in = (unsigned char*)data;
				for(int y = 0; y < h; y++, out += m_pixelWidth - w) {
					for(int x = 0; x < w; x++, in += 4, out++) {
						*out = (((in[0] & 0xFF) >> 3) << 11) | (((in[1] & 0xFF) >> 3) << 6) | (((in[2] & 0xFF) >> 3) << 1) | ((in[3] & 0xFF) >> 7);
					}
				}
				return (const char*)ret;
			}
			case WY_TEXTURE_PIXEL_FORMAT_A8:
			{
				void* ret = wyCalloc(m_pixelWidth * m_pixelHeight, sizeof(char));
				unsigned char* out = (unsigned char*)ret;
				unsigned char* in = (unsigned char*)data;
				for(int y = 0; y < h; y++, out += m_pixelWidth - w) {
					for(int x = 0; x < w; x++, in += 4, out++) {
						// we don't use alpha component as the final value, but use red component
						*out = in[0] & 0xFF;
					}
				}
				return (const char*)ret;
			}
			default:
				LOGE("Unknown texture pixel format: %d", m_pixelFormat);
				return NULL;
		}
	} else {
		switch(m_pixelFormat) {
			case WY_TEXTURE_PIXEL_FORMAT_RGBA8888:
				return data;
			case WY_TEXTURE_PIXEL_FORMAT_RGB565:
			{
				void* ret = wyMalloc(w * h * 2);
				unsigned short* out = (unsigned short*)ret;
				unsigned char* in = (unsigned char*)data;
				size_t length = w * h;
				for(int i = 0; i < length; i++, in += 4) {
					*out++ = (((in[0] & 0xFF) >> 3) << 11) | (((in[1] & 0xFF) >> 2) << 5) | ((in[2] & 0xFF) >> 3);
				}
				return (const char*)ret;
			}
			case WY_TEXTURE_PIXEL_FORMAT_RGBA4444:
			{
				void* ret = wyMalloc(w * h * 2);
				unsigned short* out = (unsigned short*)ret;
				unsigned char* in = (unsigned char*)data;
				size_t length = w * h;
				for(int i = 0; i < length; i++, in += 4) {
					*out++ = (((in[0] & 0xFF) >> 4) << 12) | (((in[1] & 0xFF) >> 4) << 8) | (((in[2] & 0xFF) >> 4) << 4) | ((in[3] & 0xFF) >> 4);
				}
				return (const char*)ret;
			}
			case WY_TEXTURE_PIXEL_FORMAT_RGBA5551:
			{
				void* ret = wyMalloc(w * h * 2);
				unsigned short* out = (unsigned short*)ret;
				unsigned char* in = (unsigned char*)data;
				size_t length = w * h;
				for(int i = 0; i < length; i++, in += 4) {
					*out++ = (((in[0] & 0xFF) >> 3) << 11) | (((in[1] & 0xFF) >> 3) << 6) | (((in[2] & 0xFF) >> 3) << 1) | ((in[3] & 0xFF) >> 7);
				}
				return (const char*)ret;
			}
			case WY_TEXTURE_PIXEL_FORMAT_A8:
			{
				void* ret = wyMalloc(w * h);
				unsigned char* out = (unsigned char*)ret;
				unsigned char* in = (unsigned char*)data;
				size_t length = w * h;
				for(int i = 0; i < length; i++, in += 4) {
					// we don't use alpha component as the final value, but use red component
					*out = in[0] & 0xFF;
				}
				return (const char*)ret;
			}
			default:
				LOGE("Unknown texture pixel format: %d", m_pixelFormat);
				return NULL;
		}
	}
}

void wyGLTexture2D::doUpdateRaw() {
	char* oldTmp = (char*)m_tmp;
	char* tmp = oldTmp;
	if(m_filter) {
		// copy tmp data to a new buffer
		size_t len = sizeof(char) * m_width * m_height * 4;
		tmp = (char*)wyMalloc(len);
		memcpy(tmp, m_tmp, len);

		// apply filter
		m_tmp = tmp;
		applyFilter();
	}

	// bind texture and update
	glBindTexture(GL_TEXTURE_2D, m_texture);
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_width, m_height, GL_RGBA, GL_UNSIGNED_BYTE, m_tmp);

	// free new buffer
	if(tmp != oldTmp)
		wyFree(tmp);
}

void wyGLTexture2D::updateRaw(const char* raw) {
	// if no texture generated, return
	// or if raw is NULL, return
	if(m_texture == 0 || raw == NULL)
		return;

	// check thread, if not in gl thread, we need wait
	m_tmp = raw;
	if(!isGLThread()) {
		pthread_cond_t cond;
		if(pthread_cond_init(&cond, NULL) == 0) {
			if(gEventDispatcher != NULL) {
				pthread_mutex_lock(&gCondMutex);
				gEventDispatcher->queueEventLocked(ET_UPDATE_TEXTURE, this, &cond);
				pthread_cond_wait(&cond, &gCondMutex);
				pthread_mutex_unlock(&gCondMutex);
			}

			pthread_cond_destroy(&cond);
		}
	} else {
		doUpdateRaw();
	}
}

void wyGLTexture2D::setColorFilter(wyColorFilter* filter) {
	wyObjectRetain(filter);
	wyObjectRelease(m_filter);
	m_filter = filter;
}

void wyGLTexture2D::applyFilter() {
	if(m_texture != 0) {
		// check thread, if not in gl thread, we need wait
		if(!isGLThread()) {
			pthread_cond_t cond;
			if(pthread_cond_init(&cond, NULL) == 0) {
				if(gEventDispatcher != NULL) {
					pthread_mutex_lock(&gCondMutex);
					gEventDispatcher->queueEventLocked(ET_APPLY_COLOR_FILTER, this, &cond);
					pthread_cond_wait(&cond, &gCondMutex);
					pthread_mutex_unlock(&gCondMutex);
				}

				pthread_cond_destroy(&cond);
			}
		} else {
			doApplyFilter();
		}
	}
}

void wyGLTexture2D::applyFilter(void* data, int width, int height) {
	if(m_filter) {
		m_filter->apply(data, width, height);
	}
}

void wyGLTexture2D::doApplyFilter() {
	char* raw = NULL;
	switch(m_source) {
		case SOURCE_JPG:
		{
			// loadJPG do everything for you
			raw = loadJPG();
			if(raw == NULL)
				return;

			break;
		}
		case SOURCE_PNG:
		{
			// loadPNG do everything for you
			raw = loadPNG();
			if(raw == NULL)
				return;

			break;
		}
		case SOURCE_RAW:
		{
			size_t len = sizeof(char) * m_width * m_height * 4;
			raw = (char*)wyMalloc(len);
			memcpy(raw, m_data, len);
			applyFilter(raw, m_width, m_height);

			break;
		}
		default:
			LOGW("wyGLTexture2D::doApplyFilter: doesn't support applying color filter for source %d", m_source);
			return;
	}

	if(raw) {
		// bind texture and update
		glBindTexture(GL_TEXTURE_2D, m_texture);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_width, m_height, GL_RGBA, GL_UNSIGNED_BYTE, raw);

		// free
		wyFree(raw);
	}
}
