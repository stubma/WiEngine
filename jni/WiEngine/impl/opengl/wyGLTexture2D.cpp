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
#include "PVRTTextureAPI.h"

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
		case SOURCE_IMG:
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

wyGLTexture2D* wyGLTexture2D::make(int resId, int transparentColor, wyTexturePixelFormat pixelFormat) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_source = SOURCE_IMG;
	tex->m_resId = resId;
	tex->m_transparentColor = transparentColor;

	// init size
	float width, height;
	wyUtils::loadImage(resId, &width, &height, true);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeRaw(const char* data, size_t length, int transparentColor, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_IMG;
	tex->m_data = data;
	tex->m_length = length;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	float width, height;
	wyUtils::loadImage(data, length, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return (wyGLTexture2D*)tex->autoRelease();
}

wyGLTexture2D* wyGLTexture2D::make(const char* assetPath, int transparentColor, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_IMG;
	tex->m_path = wyUtils::copy(assetPath);
	tex->m_isFile = false;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	float width, height;
	wyUtils::loadImage(assetPath, false, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeMemory(const char* mfsName, int transparentColor, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_IMG;
	tex->m_mfsName = wyUtils::copy(mfsName);
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	float width, height;
	wyUtils::loadImage(mfsName, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
	tex->initSize(width, height);

	return tex;
}

wyGLTexture2D* wyGLTexture2D::makeFile(const char* fsPath, int transparentColor, wyTexturePixelFormat pixelFormat, float inDensity) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->autoRelease();
	tex->m_pixelFormat = pixelFormat;
	tex->m_transparentColor = transparentColor;
	tex->m_source = SOURCE_IMG;
	tex->m_path = wyUtils::copy(fsPath);
	tex->m_isFile = true;
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	tex->m_inDensity = inDensity;

	// init size
	float width, height;
	wyUtils::loadImage(fsPath, true, &width, &height, true, wyDevice::density / inDensity, wyDevice::density / inDensity);
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

wyGLTexture2D* wyGLTexture2D::makeRaw8888(const char* data, int width, int height, wyTexturePixelFormat format) {
	wyGLTexture2D* tex = WYNEW wyGLTexture2D();
	tex->m_pixelFormat = format;
	tex->m_source = SOURCE_RAW8888;
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
		m_preciseWidth(0),
		m_preciseHeight(0),
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

void wyGLTexture2D::initSize(float realWidth, float realHeight) {
	m_preciseWidth = realWidth;
	m_preciseHeight = realHeight;
	m_width = (int)(realWidth + 0.5f);
	m_height = (int)(realHeight + 0.5f);
	m_pixelWidth = wyMath::getNextPOT(realWidth);
	m_pixelHeight = wyMath::getNextPOT(realHeight);
	m_widthScale = m_width / m_pixelWidth;
	m_heightScale = m_height / m_pixelHeight;
}

char* wyGLTexture2D::loadRaw(size_t* outLen, float* outScale, bool* outNeedFree) {
	// decompress bmp data in RGBA8888
	*outScale = wyDevice::density / m_inDensity;
	char* raw = NULL;
	if(m_resId != 0) {
		raw = wyUtils::loadRaw(m_resId, outLen, outScale);
        *outNeedFree = true;
	} else if(m_path != NULL) {
		raw = wyUtils::loadRaw(m_path, m_isFile, outLen);
        *outNeedFree = true;
	} else if(m_data != NULL) {
        raw = (char*)m_data;
        *outLen = m_length;
        *outNeedFree = false;
	} else if(m_mfsName != NULL) {
		raw = wyUtils::loadRaw(m_mfsName, outLen);
        *outNeedFree = true;
	} else {
		LOGE("texture doesn't has any input!");
	}

	return raw;
}

char* wyGLTexture2D::loadImage(char* raw, size_t len, float scale) {
	// get image data in rgba8888
	float w, h;
	char* rgba = wyUtils::loadImage(raw, len, &w, &h, false, 1.f, 1.f);

	/*
	 * post processing
	 * we must apply filter first because scaling may change some color
	 */
	if(rgba) {
		// check transparent color
		if(m_transparentColor != 0) {
			char* p = rgba;
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
		applyFilter(rgba, w, h);

		// scale
		char* scaled = wyUtils::scaleImage(rgba, w, h, scale, scale);
		if(rgba != scaled) {
			wyFree(rgba);
			rgba = scaled;
		}
	}

	return rgba;
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
		case SOURCE_IMG:
		{
			// get raw data of image
			size_t len;
			float scale;
            bool needFree;
			char* raw = loadRaw(&len, &scale, &needFree);

			// special case for PVR
			if(wyUtils::isPVR(raw, len)) {
				EPVRTError error = PVRTTextureLoadFromPointer(raw, (GLuint*)&m_texture);
				if(error != PVR_SUCCESS) {
					LOGW("wyGLTexture2D::doLoad: failed to load PVR texture");
				}
			} else {
				// generate texture and set parameter
				glGenTextures(1, (GLuint*)&m_texture);
				glBindTexture(GL_TEXTURE_2D, m_texture);
				applyParameters();

				// decompress data in RGBA8888
				char* rgba = loadImage(raw, len, scale);
				if(rgba == NULL)
					return;

				// convert data format
				const char* data = convertPixelFormat(rgba);
				if(data != rgba) {
					wyFree(rgba);
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

				// free data
				wyFree((void*)data);
			}

			// free raw data
            if(needFree)
                wyFree(raw);

			break;
		}
		case SOURCE_RAW8888:
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
	char* rgba = NULL;
	switch(m_source) {
		case SOURCE_IMG:
		{
			// get raw data of image
			size_t len;
			float scale;
            bool needFree;
			char* raw = loadRaw(&len, &scale, &needFree);
			if(!raw)
				return;

			// special case for PVR
			if(!wyUtils::isPVR(raw, len)) {
				// decompress data in RGBA8888
				rgba = loadImage(raw, len, scale);
				if(rgba == NULL)
					return;
			}

			// free raw
            if(needFree)
                wyFree(raw);

			break;
		}
		case SOURCE_RAW8888:
		{
			size_t len = sizeof(char) * m_width * m_height * 4;
			rgba = (char*)wyMalloc(len);
			memcpy(rgba, m_data, len);
			applyFilter(rgba, m_width, m_height);

			break;
		}
		default:
			LOGW("wyGLTexture2D::doApplyFilter: doesn't support applying color filter for source %d", m_source);
			return;
	}

	if(rgba) {
		// bind texture and update
		glBindTexture(GL_TEXTURE_2D, m_texture);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_width, m_height, GL_RGBA, GL_UNSIGNED_BYTE, rgba);

		// free
		wyFree(rgba);
	}
}
