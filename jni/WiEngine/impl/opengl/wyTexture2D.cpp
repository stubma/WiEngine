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
#include "wyTexture2D.h"
#include "wyUtils.h"
#include "wyTypes.h"
#include "wyTextureManager.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyColorFilter.h"

extern wyTextureManager* gTextureManager;

wyTexture2D::wyTexture2D() :
		m_handle(-1),
		m_md5(NULL),
		m_source(SOURCE_INVALID),
		m_text(NULL),
		m_fontSize(0),
		m_width(0),
		m_fontPath(NULL),
		m_isFile(false),
		m_fontName(NULL),
		m_alignment(LEFT),
		m_style(NORMAL) {
}

wyTexture2D::~wyTexture2D() {
	// free text
	if(m_text)
		wyFree((void*)m_text);
	if(m_fontPath)
		wyFree((void*)m_fontPath);
	if(m_fontName)
		wyFree((void*)m_fontName);

	/*
	 * label texture is unique, so label texture will never be referenced after
	 * label is destroyed. It is safe and good to remove label texture. same
	 * as opengl texture.
	 */
	if(m_source == SOURCE_LABEL || m_source == SOURCE_OPENGL) {
		if(gTextureManager)
			gTextureManager->removeTexture(this, true);
	}
}

wyTexture2D* wyTexture2D::makeBMP(int resId) {
	return makeBMP(resId, 0);
}

wyTexture2D* wyTexture2D::makeBMP(int resId, int transparentColor) {
	return makeBMP(resId, transparentColor, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeBMP(int resId, int transparentColor, wyTexturePixelFormat format) {
	return gTextureManager->makeBMP(resId, transparentColor, format);
}

wyTexture2D* wyTexture2D::makeJPG(int resId) {
	return makeJPG(resId, 0);
}

wyTexture2D* wyTexture2D::makeJPG(int resId, int transparentColor) {
	return makeJPG(resId, transparentColor, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeJPG(int resId, int transparentColor, wyTexturePixelFormat format) {
	return gTextureManager->makeJPG(resId, transparentColor, format);
}

wyTexture2D* wyTexture2D::makePNG(int resId) {
	return makePNG(resId, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makePNG(int resId, wyTexturePixelFormat format) {
	return gTextureManager->makePNG(resId, format);
}

wyTexture2D* wyTexture2D::makePVR(int resId) {
	return gTextureManager->makePVR(resId);
}

wyTexture2D* wyTexture2D::makeRawBMP(const char* data, size_t length) {
	return makeRawBMP(data, length, 0);
}

wyTexture2D* wyTexture2D::makeRawBMP(const char* data, size_t length, int transparentColor) {
	return makeRawBMP(data, length, transparentColor, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeRawBMP(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format) {
	return makeRawBMP(data, length, transparentColor, format, 0);
}

wyTexture2D* wyTexture2D::makeRawBMP(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	return gTextureManager->makeRawBMP(data, length, transparentColor, format, inDensity);
}

wyTexture2D* wyTexture2D::makeRawJPG(const char* data, size_t length) {
	return makeRawJPG(data, length, 0);
}

wyTexture2D* wyTexture2D::makeRawJPG(const char* data, size_t length, int transparentColor) {
	return makeRawJPG(data, length, transparentColor, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeRawJPG(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format) {
	return makeRawJPG(data, length, transparentColor, format, 0);
}

wyTexture2D* wyTexture2D::makeRawJPG(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	return gTextureManager->makeRawJPG(data, length, transparentColor, format, inDensity);
}

wyTexture2D* wyTexture2D::makeRawPNG(const char* data, size_t length) {
	return makeRawPNG(data, length, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeRawPNG(const char* data, size_t length, wyTexturePixelFormat format) {
	return makeRawPNG(data, length, format, 0);
}

wyTexture2D* wyTexture2D::makeRawPNG(const char* data, size_t length, wyTexturePixelFormat format, float inDensity) {
	return gTextureManager->makeRawPNG(data, length, format, inDensity);
}

wyTexture2D* wyTexture2D::makeRawPVR(const char* data, size_t length, float inDensity) {
	return gTextureManager->makeRawPVR(data, length, inDensity);
}

wyTexture2D* wyTexture2D::makeBMP(const char* assetPath) {
	return makeBMP(assetPath, 0);
}

wyTexture2D* wyTexture2D::makeBMP(const char* assetPath, int transparentColor) {
	return makeBMP(assetPath, transparentColor, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeBMP(const char* assetPath, int transparentColor, wyTexturePixelFormat format) {
	return makeBMP(assetPath, transparentColor, format, 0);
}

wyTexture2D* wyTexture2D::makeBMP(const char* assetPath, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	return gTextureManager->makeBMP(assetPath, transparentColor, format, inDensity);
}

wyTexture2D* wyTexture2D::makeJPG(const char* assetPath) {
	return makeJPG(assetPath, 0);
}

wyTexture2D* wyTexture2D::makeJPG(const char* assetPath, int transparentColor) {
	return makeJPG(assetPath, transparentColor, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeJPG(const char* assetPath, int transparentColor, wyTexturePixelFormat format) {
	return makeJPG(assetPath, transparentColor, format, 0);
}

wyTexture2D* wyTexture2D::makeJPG(const char* assetPath, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	return gTextureManager->makeJPG(assetPath, transparentColor, format, inDensity);
}

wyTexture2D* wyTexture2D::makePNG(const char* assetPath) {
	return makePNG(assetPath, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makePNG(const char* assetPath, wyTexturePixelFormat format) {
	return makePNG(assetPath, format, 0);
}

wyTexture2D* wyTexture2D::makePNG(const char* assetPath, wyTexturePixelFormat format, float inDensity) {
	return gTextureManager->makePNG(assetPath, format, inDensity);
}

wyTexture2D* wyTexture2D::makePVR(const char* assetPath, float inDensity) {
	return gTextureManager->makePVR(assetPath, inDensity);
}

wyTexture2D* wyTexture2D::makeMemoryBMP(const char* mfsName) {
	return makeMemoryBMP(mfsName, 0);
}

wyTexture2D* wyTexture2D::makeMemoryBMP(const char* mfsName, int transparentColor) {
	return makeMemoryBMP(mfsName, transparentColor, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeMemoryBMP(const char* mfsName, int transparentColor, wyTexturePixelFormat format) {
	return makeMemoryBMP(mfsName, transparentColor, format, 0);
}

wyTexture2D* wyTexture2D::makeMemoryBMP(const char* mfsName, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	return gTextureManager->makeMemoryBMP(mfsName, transparentColor, format, inDensity);
}

wyTexture2D* wyTexture2D::makeMemoryJPG(const char* mfsName) {
	return makeMemoryJPG(mfsName, 0);
}

wyTexture2D* wyTexture2D::makeMemoryJPG(const char* mfsName, int transparentColor) {
	return makeMemoryJPG(mfsName, transparentColor, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeMemoryJPG(const char* mfsName, int transparentColor, wyTexturePixelFormat format) {
	return makeMemoryJPG(mfsName, transparentColor, format, 0);
}

wyTexture2D* wyTexture2D::makeMemoryJPG(const char* mfsName, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	return gTextureManager->makeMemoryJPG(mfsName, transparentColor, format, inDensity);
}

wyTexture2D* wyTexture2D::makeMemoryPNG(const char* mfsName) {
	return makeMemoryPNG(mfsName, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeMemoryPNG(const char* mfsName, wyTexturePixelFormat format) {
	return makeMemoryPNG(mfsName, format, 0);
}

wyTexture2D* wyTexture2D::makeMemoryPNG(const char* mfsName, wyTexturePixelFormat format, float inDensity) {
	return gTextureManager->makeMemoryPNG(mfsName, format, inDensity);
}

wyTexture2D* wyTexture2D::makeMemoryPVR(const char* mfsName, float inDensity) {
	return gTextureManager->makeMemoryPVR(mfsName, inDensity);
}

wyTexture2D* wyTexture2D::makeFileBMP(const char* fsPath) {
	return makeFileBMP(fsPath, 0);
}

wyTexture2D* wyTexture2D::makeFileBMP(const char* fsPath, int transparentColor) {
	return makeFileBMP(fsPath, transparentColor, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeFileBMP(const char* fsPath, int transparentColor, wyTexturePixelFormat format) {
	return makeFileBMP(fsPath, transparentColor, format, 0);
}

wyTexture2D* wyTexture2D::makeFileBMP(const char* fsPath, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	return gTextureManager->makeFileBMP(fsPath, transparentColor, format, inDensity);
}

wyTexture2D* wyTexture2D::makeFileJPG(const char* fsPath) {
	return makeFileJPG(fsPath, 0);
}

wyTexture2D* wyTexture2D::makeFileJPG(const char* fsPath, int transparentColor) {
	return makeFileJPG(fsPath, transparentColor, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeFileJPG(const char* fsPath, int transparentColor, wyTexturePixelFormat format) {
	return makeFileJPG(fsPath, transparentColor, format, 0);
}

wyTexture2D* wyTexture2D::makeFileJPG(const char* fsPath, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	return gTextureManager->makeFileJPG(fsPath, transparentColor, format, inDensity);
}

wyTexture2D* wyTexture2D::makeFilePNG(const char* fsPath) {
	return makeFilePNG(fsPath, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeFilePNG(const char* fsPath, wyTexturePixelFormat format) {
	return makeFilePNG(fsPath, format, 0);
}

wyTexture2D* wyTexture2D::makeFilePNG(const char* fsPath, wyTexturePixelFormat format, float inDensity) {
	return gTextureManager->makeFilePNG(fsPath, format, inDensity);
}

wyTexture2D* wyTexture2D::makeFilePVR(const char* fsPath, float inDensity) {
	return gTextureManager->makeFilePVR(fsPath, inDensity);
}

wyTexture2D* wyTexture2D::makeLabel(const char* text, float fontSize, const char* fontPath, bool isFile, float width, TextAlignment alignment) {
	return gTextureManager->makeLabel(text, fontSize, fontPath, isFile, width, alignment);
}

wyTexture2D* wyTexture2D::makeLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width, TextAlignment alignment) {
	return gTextureManager->makeLabel(text, fontSize, style, fontName, width, alignment);
}

wyTexture2D* wyTexture2D::makeGL(int texture, int w, int h) {
	return gTextureManager->makeGL(texture, w, h);
}

wyTexture2D* wyTexture2D::makeRaw(const char* data, int width, int height) {
	return makeRaw(data, width, height, wyTextureManager::getInstance()->getTexturePixelFormat());
}

wyTexture2D* wyTexture2D::makeRaw(const char* data, int width, int height, wyTexturePixelFormat format) {
	return gTextureManager->makeRaw(data, width, height, format);
}

void wyTexture2D::load() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->load();
}

void wyTexture2D::updateLabel(const char* text) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex) {
		tex->updateLabel(text);

		// save a copy in proxy
		if(m_text) {
			wyFree((void*)m_text);
			m_text = NULL;
		}
		m_text = wyUtils::copy(text);
	}
}

void wyTexture2D::updateLabel(const char* text, float fontSize, const char* fontPath, bool isFile, float lineWidth, TextAlignment alignment) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex) {
		tex->updateLabel(text, fontSize, fontPath, isFile, lineWidth, alignment);

		// save a copy in proxy
		if(m_text) {
			wyFree((void*)m_text);
			m_text = NULL;
		}
		m_text = wyUtils::copy(text);
		m_fontSize = fontSize;
		if(m_fontPath) {
			wyFree((void*)m_fontPath);
			m_fontPath = NULL;
		}
		m_fontPath = wyUtils::copy(fontPath);
		m_alignment = alignment;
	}
}

void wyTexture2D::updateLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName, float lineWidth, TextAlignment alignment) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex) {
		tex->updateLabel(text, fontSize, style, fontName, lineWidth, alignment);

		// save a copy in proxy
		if(m_text) {
			wyFree((void*)m_text);
			m_text = NULL;
		}
		m_text = wyUtils::copy(text);
		m_fontSize = fontSize;
		m_style = style;
		if(m_fontName) {
			wyFree((void*)m_fontName);
			m_fontName = NULL;
		}
		m_fontName = wyUtils::copy(fontName);
		m_alignment = alignment;
	}
}

void wyTexture2D::setAntiAlias(bool on) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->setAntiAlias(on);
}

void wyTexture2D::setRepeat(bool on) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->setRepeat(on);
}

void wyTexture2D::setParameters(int min, int mag, int wrapS, int wrapT) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->setParameters(min, mag, wrapS, wrapT);
}

void wyTexture2D::applyParameters() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->applyParameters();
}

bool wyTexture2D::hasPremultipliedAlpha() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->hasPremultipliedAlpha();
	else
		return false;
}

void wyTexture2D::draw(float x, float y) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->draw(x, y);
}

void wyTexture2D::draw(float x, float y, bool flipX, bool flipY) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->draw(x, y, flipX, flipY);
}

void wyTexture2D::draw(float x, float y, float width, float height) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->draw(x, y, width, height);
}

void wyTexture2D::draw(float x, float y, float width, float height, bool flipX, bool flipY) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->draw(x, y, width, height, flipX, flipY);
}

void wyTexture2D::draw(float x, float y, float width, float height, bool flipX, bool flipY, wyRect texRect) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->draw(x, y, width, height, flipX, flipY, texRect);
}

void wyTexture2D::draw(float x, float y, float width, float height, bool flipX, bool flipY, wyRect texRect, bool rotatedZwoptex) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->draw(x, y, width, height, flipX, flipY, texRect, rotatedZwoptex);
}

void wyTexture2D::draw(float x, float y, float width, float height, float sourceWidth, float sourceHeight, bool flipX, bool flipY, wyRect texRect, bool rotatedZwoptex) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->draw(x, y, width, height, sourceWidth, sourceHeight, flipX, flipY, texRect, rotatedZwoptex);
}

float wyTexture2D::getWidth() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->getWidth();
	else
		return 0;
}

float wyTexture2D::getHeight() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->getHeight();
	else
		return 0;
}

float wyTexture2D::getPreciseWidth() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->getPreciseWidth();
	else
		return 0;
}

float wyTexture2D::getPreciseHeight() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->getPreciseHeight();
	else
		return 0;
}

int wyTexture2D::getPixelWidth() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->getPixelWidth();
	else
		return 0;
}

int wyTexture2D::getPixelHeight() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->getPixelHeight();
	else
		return 0;
}

float wyTexture2D::getWidthScale() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->getWidthScale();
	else
		return 0;
}

float wyTexture2D::getHeightScale() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->getHeightScale();
	else
		return 0;
}

int wyTexture2D::getTexture() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->getTexture();
	else
		return 0;
}

const char* wyTexture2D::getText() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->getText();
	else
		return NULL;
}

wyTextureSource wyTexture2D::getSource() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->getSource();
	else
		return SOURCE_INVALID;
}

bool wyTexture2D::isFlipY() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->isFlipY();
	else
		return false;
}

bool wyTexture2D::isFlipX() {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		return tex->isFlipX();
	else
		return false;
}

void wyTexture2D::setFlipX(bool flipX) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->setFlipX(flipX);
}

void wyTexture2D::setFlipY(bool flipY) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->setFlipY(flipY);
}

void wyTexture2D::updateRaw(const char* data) {
	wyGLTexture2D* tex = gTextureManager->getTexture(this);
	if(tex)
		tex->updateRaw(data);
}

void wyTexture2D::setTexture(int tex) {
	wyGLTexture2D* t = gTextureManager->getTexture(this);
	if(t)
		t->setTexture(tex);
}

void wyTexture2D::setColorFilter(wyColorFilter* filter) {
	wyGLTexture2D* t = gTextureManager->getTexture(this);
	if(t)
		t->setColorFilter(filter);
}

void wyTexture2D::applyFilter() {
	wyGLTexture2D* t = gTextureManager->getTexture(this);
	if(t)
		t->applyFilter();
}

wyTexture2D* wyTexture2D::clone(int cloneId) {
	return gTextureManager->cloneTexture(this, cloneId);
}

bool wyTexture2D::switchToClone(int cloneId) {
	return gTextureManager->switchToClonedTexture(this, cloneId);
}
