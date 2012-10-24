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
#include "wyTextureManager.h"
#include <stdlib.h>
#include "wyDirector.h"
#include "wyLog.h"
#include "wyMD5.h"
#include "wyGLTexture2D.h"
#include "wyTypes.h"
#include "wyUtils.h"

wyTextureManager* gTextureManager;

// id start
#define LABEL_ID_START 0x6f000000
#define GL_ID_START 0x5f000000

wyTextureManager::~wyTextureManager() {
	// free real textures
	for(int i = 0; i < m_textureCount; i++) {
		if(m_textures[i] != NULL) {
			m_textures[i]->release();
		}
	}
	wyFree(m_textures);

	// free handle hashs
	for(map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->begin(); iter != m_textureHash->end(); iter++) {
		releaseTexHash(iter->first, iter->second);
	}
	WYDELETE(m_textureHash);
	m_textureHash = NULL;

	// free idle handle array
	WYDELETE(m_idleHandles);

	// nullify self
	gTextureManager = NULL;
}

wyTextureManager::wyTextureManager() :
		m_textureCount(0),
		m_nextLabelId(LABEL_ID_START),
		m_texturePixelFormat(WY_TEXTURE_PIXEL_FORMAT_RGBA8888),
		m_textures((wyGLTexture2D**)wyCalloc(1000, sizeof(wyGLTexture2D*))),
		m_textureHash(WYNEW map<unsigned int, wyTextureHash>()) {
	m_idleHandles = WYNEW vector<int>();
	m_idleHandles->reserve(100);
}

wyTextureManager* wyTextureManager::getInstance() {
	if(gTextureManager == NULL) {
		gTextureManager = WYNEW wyTextureManager();
	}

	return gTextureManager;
}

wyTextureManager* wyTextureManager::getInstanceNoCreate() {
	return gTextureManager;
}

void wyTextureManager::releaseTexHash(unsigned int key, wyTextureHash& hash) {
	switch(hash.type) {
		case CT_PATH:
			wyFree((void*)hash.pp.path);
			break;
		case CT_MFS:
			wyFree((void*)hash.mp.mfsName);
			break;
		case CT_DATA:
			wyFree((void*)hash.dp.data);
			break;
	}
	wyFree((void*)hash.md5);
}

void wyTextureManager::invalidateAllTextures() {
	for(int i = 0; i < m_textureCount; i++) {
		if(m_textures[i])
			m_textures[i]->deleteTexture(true);
	}
}

const char* wyTextureManager::hashForNum(int num) {
	return wyMD5::md5((const void*)&num, sizeof(int));
}

const char* wyTextureManager::hashForStr(const char* str) {
	return wyMD5::md5(str);
}

const char* wyTextureManager::hashForData(const void* data, size_t length) {
	return wyMD5::md5(data, length);
}

bool wyTextureManager::switchToClonedTexture(wyTexture2D* t, int cloneId) {
	for(map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->begin(); iter != m_textureHash->end(); iter++) {
		wyTextureHash& hash = iter->second;
		if(hash.isClone && hash.sourceHandle == t->m_handle && hash.cloneId == cloneId) {
			t->m_handle = hash.handle;
			t->m_md5 = hash.md5;
			t->m_source = hash.source;
			return true;
		}
	}

	return false;
}

bool wyTextureManager::deleteClonedTexture(wyTexture2D* t, int cloneId) {
	for(map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->begin(); iter != m_textureHash->end(); iter++) {
		wyTextureHash& hash = iter->second;
		if(hash.isClone && hash.sourceHandle == t->m_handle && hash.cloneId == cloneId) {
			// release this cloned texture
			if(m_textures[hash.handle]) {
				m_textures[hash.handle]->release();
				m_textures[hash.handle] = NULL;
			}

			// remove this texture hash
			m_idleHandles->push_back(hash.handle);
			releaseTexHash(0, hash);
			m_textureHash->erase(iter);

			return true;
		}
	}

	return false;
}

wyTexture2D* wyTextureManager::cloneTexture(wyTexture2D* t, int sourceHandle, const char* md5, int cloneId) {
	// can't clone empty texture
	if(m_textures[sourceHandle] == NULL)
		return NULL;

	// get hash
	unsigned int hashInt = wyUtils::strHash(md5);
	wyTextureHash& sourceHash = (*m_textureHash)[hashInt];

	// if source is also a clone, clone source of the source
	if(sourceHash.isClone) {
		return cloneTexture(t, sourceHash.sourceHandle, sourceHash.sourceMd5, cloneId);
	}

	// create clone hash and copy source hash
	wyTextureHash cloneHash;
	memcpy(&cloneHash, &sourceHash, sizeof(wyTextureHash));
	switch(sourceHash.type) {
		case CT_PATH:
			cloneHash.pp.path = wyUtils::copy(sourceHash.pp.path);
			break;
		case CT_MFS:
			cloneHash.mp.mfsName = wyUtils::copy(sourceHash.mp.mfsName);
			break;
		case CT_DATA:
			cloneHash.dp.data = wyUtils::copy(sourceHash.dp.data);
			break;
	}

	// handle and source handle must be set for a cloned texture
	cloneHash.handle = nextHandle();
	cloneHash.isClone = true;
	cloneHash.sourceHandle = sourceHash.handle;
	cloneHash.sourceMd5 = sourceHash.md5;
	cloneHash.cloneId = cloneId;

	// md5 must be different
	char buf[64];
	sprintf(buf, "%s_%d", sourceHash.md5, cloneId);
	cloneHash.md5 = hashForStr(buf);
	hashInt = wyUtils::strHash(cloneHash.md5);

	// insert hash
	(*m_textureHash)[hashInt] = cloneHash;

	// create real texture
	wyGLTexture2D* glTex = createGLTexture(sourceHash.md5, t);
	wyObjectRetain(glTex);
	m_textures[cloneHash.handle] = glTex;

	// update proxy texture info so that it points to cloned texture
	wyTexture2D* ct = WYNEW wyTexture2D();
	ct->m_handle = cloneHash.handle;
	ct->m_md5 = cloneHash.md5;
	ct->m_source = cloneHash.source;
	return (wyTexture2D*)ct->autoRelease();
}

wyTexture2D* wyTextureManager::cloneTexture(wyTexture2D* t, int cloneId) {
	return cloneTexture(t, t->m_handle, t->m_md5, cloneId);
}

wyGLTexture2D* wyTextureManager::createGLTexture(const char* md5, wyTexture2D* t) {
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(wyUtils::strHash(md5));
	if(iter != m_textureHash->end()) {
		wyTextureHash& texHash = iter->second;
		switch(texHash.type) {
			case CT_RESID:
				switch(texHash.source) {
					case SOURCE_BMP:
						return wyGLTexture2D::makeBMP(texHash.rp.resId, texHash.transparentColor, texHash.pixelFormat);
					case SOURCE_PNG:
						return wyGLTexture2D::makePNG(texHash.rp.resId, texHash.pixelFormat);
					case SOURCE_JPG:
						return wyGLTexture2D::makeJPG(texHash.rp.resId, texHash.transparentColor, texHash.pixelFormat);
					case SOURCE_PVR:
						return wyGLTexture2D::makePVR(texHash.rp.resId);
				}
				break;
			case CT_PATH:
				switch(texHash.source) {
					case SOURCE_PNG:
						if(texHash.pp.isFile) {
							return wyGLTexture2D::makeFilePNG(texHash.pp.path, texHash.pixelFormat, texHash.inDensity);
						} else {
							return wyGLTexture2D::makePNG(texHash.pp.path, texHash.pixelFormat, texHash.inDensity);
						}
						break;
					case SOURCE_BMP:
						if(texHash.pp.isFile) {
							return wyGLTexture2D::makeFileBMP(texHash.pp.path, texHash.transparentColor, texHash.pixelFormat, texHash.inDensity);
						} else {
							return wyGLTexture2D::makeBMP(texHash.pp.path, texHash.transparentColor, texHash.pixelFormat, texHash.inDensity);
						}
						break;
					case SOURCE_JPG:
						if(texHash.pp.isFile) {
							return wyGLTexture2D::makeFileJPG(texHash.pp.path, texHash.transparentColor, texHash.pixelFormat, texHash.inDensity);
						} else {
							return wyGLTexture2D::makeJPG(texHash.pp.path, texHash.transparentColor, texHash.pixelFormat, texHash.inDensity);
						}
						break;
					case SOURCE_PVR:
						if(texHash.pp.isFile) {
							return wyGLTexture2D::makeFilePVR(texHash.pp.path, texHash.inDensity);
						} else {
							return wyGLTexture2D::makePVR(texHash.pp.path, texHash.inDensity);
						}
						break;
				}
				break;
			case CT_MFS:
				switch(texHash.source) {
					case SOURCE_PNG:
						return wyGLTexture2D::makeMemoryPNG(texHash.mp.mfsName, texHash.pixelFormat, texHash.inDensity);
					case SOURCE_BMP:
						return wyGLTexture2D::makeMemoryBMP(texHash.mp.mfsName, texHash.transparentColor, texHash.pixelFormat, texHash.inDensity);
					case SOURCE_JPG:
						return wyGLTexture2D::makeMemoryJPG(texHash.mp.mfsName, texHash.transparentColor, texHash.pixelFormat, texHash.inDensity);
					case SOURCE_PVR:
						return wyGLTexture2D::makeMemoryPVR(texHash.mp.mfsName, texHash.inDensity);
				}
				break;
			case CT_DATA:
				switch(texHash.source) {
					case SOURCE_PNG:
						return wyGLTexture2D::makeRawPNG(texHash.dp.data, texHash.dp.length, texHash.pixelFormat, texHash.inDensity);
					case SOURCE_BMP:
						return wyGLTexture2D::makeRawBMP(texHash.dp.data, texHash.dp.length, texHash.transparentColor, texHash.pixelFormat, texHash.inDensity);
					case SOURCE_JPG:
						return wyGLTexture2D::makeRawJPG(texHash.dp.data, texHash.dp.length, texHash.transparentColor, texHash.pixelFormat, texHash.inDensity);
					case SOURCE_PVR:
						return wyGLTexture2D::makeRawPVR(texHash.dp.data, texHash.dp.length, texHash.inDensity);
					case SOURCE_RAW:
						return wyGLTexture2D::makeRaw(texHash.dp.data, texHash.dp.width, texHash.dp.height, texHash.pixelFormat);
				}
				break;
			case CT_LABEL:
				if(t->m_fontPath) {
					return wyGLTexture2D::makeLabel(t->m_text, t->m_fontSize, t->m_fontPath, t->m_isFile, t->m_width, t->m_alignment);
				} else {
					return wyGLTexture2D::makeLabel(t->m_text, t->m_fontSize, t->m_style, t->m_fontName, t->m_width, t->m_alignment);
				}
				break;
		}
	}

	return NULL;
}

wyGLTexture2D* wyTextureManager::getTexture(wyTexture2D* t) {
	size_t handle = t->m_handle;
	if(m_textures[handle] == NULL) {
		m_textures[handle] = createGLTexture(t->m_md5, t);
		wyObjectRetain(m_textures[handle]);
	}
	return m_textures[handle];
}

wyTexture2D* wyTextureManager::makeBMP(int resId, int transparentColor, wyTexturePixelFormat format) {
	if(resId <= 0) {
		LOGE("%s invalid resource ID: %d", __FUNCTION__, resId);
		return NULL;
	}

	wyTextureHash texHash;
	const char* hash = hashForNum(resId);
	unsigned int hashInt = wyUtils::strHash(hash);
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_RESID;
		texHash.pixelFormat = format;
		texHash.transparentColor = transparentColor;
		texHash.source = SOURCE_BMP;
		texHash.md5 = hash;
		texHash.handle = nextHandle();
		texHash.rp.resId = resId;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeBMP(resId, transparentColor, format);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeBMP(const char* assetPath, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	const char* hash = hashForStr(assetPath);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_PATH;
		texHash.pixelFormat = format;
		texHash.transparentColor = transparentColor;
		texHash.source = SOURCE_BMP;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.pp.path = wyUtils::copy(assetPath);
		texHash.pp.isFile = false;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeBMP(assetPath, transparentColor, format, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeRawBMP(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	const char* hash = hashForData(data, length);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_DATA;
		texHash.pixelFormat = format;
		texHash.transparentColor = transparentColor;
		texHash.source = SOURCE_BMP;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.dp.data = wyUtils::copy(data, 0, length);
		texHash.dp.length = length;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeRawBMP(texHash.dp.data, length, transparentColor, format, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeMemoryBMP(const char* mfsName, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	const char* hash = hashForStr(mfsName);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_MFS;
		texHash.pixelFormat = format;
		texHash.transparentColor = transparentColor;
		texHash.source = SOURCE_BMP;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.mp.mfsName = wyUtils::copy(mfsName);

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeMemoryBMP(mfsName, transparentColor, format, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeFileBMP(const char* fsPath, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	const char* hash = hashForStr(fsPath);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_PATH;
		texHash.pixelFormat = format;
		texHash.transparentColor = transparentColor;
		texHash.source = SOURCE_BMP;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.pp.path = wyUtils::copy(fsPath);
		texHash.pp.isFile = true;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeFileBMP(fsPath, transparentColor, format, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeJPG(int resId, int transparentColor, wyTexturePixelFormat format) {
	if(resId <= 0) {
		LOGE("%s invalid resource ID: %d", __FUNCTION__, resId);
		return NULL;
	}
	
	const char* hash = hashForNum(resId);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_RESID;
		texHash.pixelFormat = format;
		texHash.transparentColor = transparentColor;
		texHash.source = SOURCE_JPG;
		texHash.md5 = hash;
		texHash.handle = nextHandle();
		texHash.rp.resId = resId;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeJPG(resId, transparentColor, format);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeRawJPG(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	const char* hash = hashForData(data, length);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_DATA;
		texHash.pixelFormat = format;
		texHash.transparentColor = transparentColor;
		texHash.source = SOURCE_JPG;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.dp.data = wyUtils::copy(data, 0, length);
		texHash.dp.length = length;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeRawJPG(texHash.dp.data, length, transparentColor, format, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeJPG(const char* assetPath, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	const char* hash = hashForStr(assetPath);
	unsigned int hashInt = wyUtils::strHash(hash);
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	wyTextureHash texHash;
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_PATH;
		texHash.pixelFormat = format;
		texHash.transparentColor = transparentColor;
		texHash.source = SOURCE_JPG;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.pp.path = wyUtils::copy(assetPath);
		texHash.pp.isFile = false;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeJPG(assetPath, transparentColor, format, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeMemoryJPG(const char* mfsName, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	const char* hash = hashForStr(mfsName);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_MFS;
		texHash.pixelFormat = format;
		texHash.transparentColor = transparentColor;
		texHash.source = SOURCE_JPG;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.mp.mfsName = wyUtils::copy(mfsName);

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeMemoryJPG(mfsName, transparentColor, format, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeFileJPG(const char* fsPath, int transparentColor, wyTexturePixelFormat format, float inDensity) {
	const char* hash = hashForStr(fsPath);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_PATH;
		texHash.pixelFormat = format;
		texHash.transparentColor = transparentColor;
		texHash.source = SOURCE_JPG;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.pp.path = wyUtils::copy(fsPath);
		texHash.pp.isFile = true;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeFileJPG(fsPath, transparentColor, format, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makePNG(int resId, wyTexturePixelFormat format) {
	if(resId <= 0) {
		LOGE("%s invalid resource ID: %d", __FUNCTION__, resId);
		return NULL;
	}
	
	const char* hash = hashForNum(resId);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_RESID;
		texHash.pixelFormat = format;
		texHash.source = SOURCE_PNG;
		texHash.md5 = hash;
		texHash.handle = nextHandle();
		texHash.rp.resId = resId;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makePNG(resId, format);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeRawPNG(const char* data, size_t length, wyTexturePixelFormat format, float inDensity) {
	const char* hash = hashForData(data, length);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_DATA;
		texHash.pixelFormat = format;
		texHash.source = SOURCE_PNG;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.dp.data = wyUtils::copy(data, 0, length);
		texHash.dp.length = length;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeRawPNG(texHash.dp.data, length, format, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makePNG(const char* assetPath, wyTexturePixelFormat format, float inDensity) {
	const char* hash = hashForStr(assetPath);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_PATH;
		texHash.pixelFormat = format;
		texHash.source = SOURCE_PNG;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.pp.path = wyUtils::copy(assetPath);
		texHash.pp.isFile = false;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makePNG(assetPath, format, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeMemoryPNG(const char* mfsName, wyTexturePixelFormat format, float inDensity) {
	const char* hash = hashForStr(mfsName);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_MFS;
		texHash.pixelFormat = format;
		texHash.source = SOURCE_PNG;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.mp.mfsName = wyUtils::copy(mfsName);

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeMemoryPNG(mfsName, format, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeFilePNG(const char* fsPath, wyTexturePixelFormat format, float inDensity) {
	const char* hash = hashForStr(fsPath);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_PATH;
		texHash.pixelFormat = format;
		texHash.source = SOURCE_PNG;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.pp.path = wyUtils::copy(fsPath);
		texHash.pp.isFile = true;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeFilePNG(fsPath, format, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makePVR(int resId) {
	if(resId <= 0) {
		LOGE("%s invalid resource ID: %d", __FUNCTION__, resId);
		return NULL;
	}

	const char* hash = hashForNum(resId);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_RESID;
		texHash.source = SOURCE_PVR;
		texHash.md5 = hash;
		texHash.handle = nextHandle();
		texHash.rp.resId = resId;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makePVR(resId);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeRawPVR(const char* data, size_t length, float inDensity) {
	const char* hash = hashForData(data, length);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_DATA;
		texHash.source = SOURCE_PVR;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.dp.data = wyUtils::copy(data, 0, length);
		texHash.dp.length = length;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeRawPVR(data, length, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makePVR(const char* assetPath, float inDensity) {
	const char* hash = hashForStr(assetPath);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_PATH;
		texHash.source = SOURCE_PVR;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.pp.path = wyUtils::copy(assetPath);
		texHash.pp.isFile = false;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makePVR(assetPath, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeMemoryPVR(const char* mfsName, float inDensity) {
	const char* hash = hashForStr(mfsName);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_MFS;
		texHash.source = SOURCE_PVR;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.mp.mfsName = wyUtils::copy(mfsName);

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeMemoryPVR(mfsName, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeFilePVR(const char* fsPath, float inDensity) {
	const char* hash = hashForStr(fsPath);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_PATH;
		texHash.source = SOURCE_PVR;
		texHash.md5 = hash;
		texHash.inDensity = inDensity;
		texHash.handle = nextHandle();
		texHash.pp.path = wyUtils::copy(fsPath);
		texHash.pp.isFile = true;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeFilePVR(fsPath, inDensity);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeLabel(const char* text, float fontSize, const char* fontPath, bool isFile, float width, wyTexture2D::TextAlignment alignment) {
	const char* hash = hashForNum(m_nextLabelId++);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_LABEL;
		texHash.source = SOURCE_LABEL;
		texHash.md5 = hash;
		texHash.handle = nextHandle();

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeLabel(text, fontSize, fontPath, isFile, width, alignment);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	tex->m_text = wyUtils::copy(text);
	tex->m_fontSize = fontSize;
	tex->m_width = width;
	tex->m_isFile = isFile;
	tex->m_fontPath = wyUtils::copy(fontPath);
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width, wyTexture2D::TextAlignment alignment) {
	const char* hash = hashForNum(m_nextLabelId++);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_LABEL;
		texHash.source = SOURCE_LABEL;
		texHash.md5 = hash;
		texHash.handle = nextHandle();

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeLabel(text, fontSize, style, fontName, width, alignment);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	tex->m_text = wyUtils::copy(text);
	tex->m_fontSize = fontSize;
	tex->m_style = style;
	tex->m_width = width;
	tex->m_fontName = wyUtils::copy(fontName);
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeGL(int texture, int w, int h) {
	const char* hash = hashForNum(GL_ID_START + texture);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_OPENGL;
		texHash.source = SOURCE_OPENGL;
		texHash.md5 = hash;
		texHash.handle = nextHandle();
		texHash.gp.ref = 1;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeGL(texture, w, h);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		// increase reference
		texHash = iter->second;
		texHash.gp.ref++;

        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

wyTexture2D* wyTextureManager::makeRaw(const char* data, int width, int height, wyTexturePixelFormat format) {
	size_t length = width * height * 4;
	const char* hash = hashForData(data, length);
	unsigned int hashInt = wyUtils::strHash(hash);
	wyTextureHash texHash;
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(hashInt);
	if(iter == m_textureHash->end()) {
		// create hash
		memset(&texHash, 0, sizeof(wyTextureHash));
		texHash.type = CT_DATA;
		texHash.pixelFormat = format;
		texHash.source = SOURCE_RAW;
		texHash.md5 = hash;
		texHash.handle = nextHandle();
		texHash.dp.data = wyUtils::copy(data, 0, length);
		texHash.dp.length = length;
		texHash.dp.width = width;
		texHash.dp.height = height;

		// create real texture
		wyGLTexture2D* glTex = wyGLTexture2D::makeRaw(texHash.dp.data, width, height, format);
		glTex->retain();
		m_textures[texHash.handle] = glTex;

		// insert hash
		(*m_textureHash)[hashInt] = texHash;
	} else {
		texHash = iter->second;
        wyFree((void*) hash);
    }

	// create texture proxy and return
	wyTexture2D* tex = WYNEW wyTexture2D();
	tex->m_handle = texHash.handle;
	tex->m_md5 = texHash.md5;
	tex->m_source = texHash.source;
	return (wyTexture2D*)tex->autoRelease();
}

size_t wyTextureManager::nextHandle() {
	if(m_idleHandles->size() > 0) {
		int handle = m_idleHandles->back();
		m_idleHandles->pop_back();
		return handle;
	} else {
		return m_textureCount++;
	}
}

int wyTextureManager::getTextureCount() {
	int count = 0;
	for(int i = 0; i < m_textureCount; i++) {
		if(m_textures[i]) {
			count++;
		}
	}

	return count;
}

void wyTextureManager::releaseClonedTexture(int sourceHandle, bool removeHandle) {
	for(map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->begin(); iter != m_textureHash->end(); iter++) {
		wyTextureHash& hash = iter->second;
		if(hash.isClone && hash.sourceHandle == sourceHandle) {
			// release this cloned texture
			if(m_textures[hash.handle]) {
				m_textures[hash.handle]->release();
				m_textures[hash.handle] = NULL;
			}

			if(removeHandle) {
				// remove this texture hash
				m_idleHandles->push_back(hash.handle);
				releaseTexHash(0, hash);
				m_textureHash->erase(iter);
			}
		}
	}
}

void wyTextureManager::removeTexture(wyTexture2D* tex, bool removeHandle) {
	if(tex == NULL)
		return;

	/*
	 * for opengl source texture, must check reference count
	 * in wyTexture2D deconstructor, removeTexture will be invoked when source is opengl,
	 * so we won't miss it
	 */
	if(tex->m_source == SOURCE_OPENGL) {
		map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(wyUtils::strHash(tex->m_md5));
		if(iter != m_textureHash->end()) {
			// decrease reference count
			wyTextureHash& texHash = iter->second;
			texHash.gp.ref--;

			// if reference count still larger than 0, no need process
			if(texHash.gp.ref > 0)
				return;
		} else {
			// if no texture hash found, no need process
			return;
		}
	}

	// release real texture
	int handle = tex->m_handle;
	if(m_textures[handle]) {
		m_textures[handle]->release();
		m_textures[handle] = NULL;
	}

	// no need to keep handle if removeHandle flag is set, this means the texture is a label opengl texture
	bool needReleaseClone = false;
	if(removeHandle) {
		const char* hash = tex->m_md5;
		map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(wyUtils::strHash(hash));
		if(iter != m_textureHash->end()) {
			wyTextureHash& texHash = iter->second;
			if(!texHash.isClone)
				needReleaseClone = true;
			m_idleHandles->push_back(texHash.handle);
			releaseTexHash(0, texHash);
			m_textureHash->erase(iter);
		}
	}

	// release cloned texture
	if(needReleaseClone)
		releaseClonedTexture(handle, removeHandle);
}

void wyTextureManager::removeTexture(int resId) {
	const char* hash = hashForNum(resId);
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(wyUtils::strHash(hash));
	if(iter != m_textureHash->end()) {
		wyTextureHash& texHash = iter->second;
		if(m_textures[texHash.handle]) {
			m_textures[texHash.handle]->release();
			m_textures[texHash.handle] = NULL;
		}

		// release cloned texture if it is not cloned texture
		if(!texHash.isClone)
			releaseClonedTexture(texHash.handle);
	}
	wyFree((void*)hash);
}

void wyTextureManager::removeTexture(const char* name) {
	const char* hash = hashForStr(name);
	map<unsigned int, wyTextureHash>::iterator iter = m_textureHash->find(wyUtils::strHash(hash));
	if(iter != m_textureHash->end()) {
		wyTextureHash& texHash = iter->second;
		if(m_textures[texHash.handle]) {
			m_textures[texHash.handle]->release();
			m_textures[texHash.handle] = NULL;
		}

		// release cloned texture if it is not cloned texture
		if(!texHash.isClone)
			releaseClonedTexture(texHash.handle);
	}
	wyFree((void*)hash);
}

void wyTextureManager::removeAllTextures() {
	for(int i = 0; i < m_textureCount; i++) {
		if(m_textures[i]) {
			m_textures[i]->release();
			m_textures[i] = NULL;
		}
	}
}
