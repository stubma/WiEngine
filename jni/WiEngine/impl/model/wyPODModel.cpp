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
#include "wyPODModel.h"
#include "PVRTModelPOD.h"
#include "wyUtils.h"
#include "wyLog.h"

static const char* lightTypeString(EPODLightType type) {
    switch(type) {
        case ePODSpot:
            return "Spot";
        case ePODPoint:
            return "Point";
        case ePODDirectional:
            return "Directional";
        default:
            return "Unknown";
    }
}

wyPODModel::wyPODModel() :
        m_pod(NULL) {
}

wyPODModel::~wyPODModel() {
    if(m_pod)
        delete m_pod;
}

wyPODModel* wyPODModel::make(int resId) {
	wyPODModel* m = WYNEW wyPODModel();
	m->load(resId);
	return (wyPODModel*)m->autoRelease();
}

wyPODModel* wyPODModel::make(const char* path) {
    wyPODModel* m = WYNEW wyPODModel();
	m->load(path);
	return (wyPODModel*)m->autoRelease();
}

wyPODModel* wyPODModel::makeFile(const char* path) {
    wyPODModel* m = WYNEW wyPODModel();
	m->loadFile(path);
	return (wyPODModel*)m->autoRelease();
}

wyPODModel* wyPODModel::makeMemory(const char* mfsName) {
    wyPODModel* m = WYNEW wyPODModel();
	m->loadMemory(mfsName);
	return (wyPODModel*)m->autoRelease();
}

wyPODModel* wyPODModel::makeMemory(const char* data, size_t len) {
    wyPODModel* m = WYNEW wyPODModel();
	m->loadMemory(data, len);
	return (wyPODModel*)m->autoRelease();
}

void wyPODModel::load(int resId) {
    // lazy create
    if(!m_pod) {
        m_pod = new CPVRTModelPOD();
    }
    
    // load pod from raw data
    size_t len;
    char* raw = wyUtils::loadRaw(resId, &len);
    m_pod->ReadFromMemory(raw, len);
    wyFree(raw);
    
    // validate
    if(!m_pod->IsLoaded()) {
        LOGW("wyPODModel::load: failed to load POD resource id: %d", resId);
    }
}

void wyPODModel::load(const char* path) {
    // lazy create
    if(!m_pod) {
        m_pod = new CPVRTModelPOD();
    }
    
    // load pod from raw data
    size_t len;
    char* raw = wyUtils::loadRaw(path, false, &len);
    m_pod->ReadFromMemory(raw, len);
    wyFree(raw);
    
    // validate
    if(!m_pod->IsLoaded()) {
        LOGW("wyPODModel::load: failed to load POD asset file: %s", path);
    }
}

void wyPODModel::loadFile(const char* path) {
    // lazy create
    if(!m_pod) {
        m_pod = new CPVRTModelPOD();
    }
    
    // load pod from file
    const char* mappedPath = wyUtils::mapLocalPath(path);
    m_pod->ReadFromFile(mappedPath);
    wyFree((void*)mappedPath);
    
    // validate
    if(!m_pod->IsLoaded()) {
        LOGW("wyPODModel::loadFile: failed to load POD file: %s", path);
    }
}

void wyPODModel::loadMemory(const char* mfsName) {
    // lazy create
    if(!m_pod) {
        m_pod = new CPVRTModelPOD();
    }
    
    // load pod from raw data
    size_t len;
    char* raw = wyUtils::loadRaw(mfsName, &len);
    m_pod->ReadFromMemory(raw, len);
    wyFree(raw);
    
    // validate
    if(!m_pod->IsLoaded()) {
        LOGW("wyPODModel::loadMemory: failed to load POD memory file: %s", mfsName);
    }
}

void wyPODModel::loadMemory(const char* data, size_t len) {
    // lazy create
    if(!m_pod) {
        m_pod = new CPVRTModelPOD();
    }
    
    // load it
    m_pod->ReadFromMemory(data, len);
    
    // validate
    if(!m_pod->IsLoaded()) {
        LOGW("wyPODModel::loadMemory: failed to load POD memory data");
    }
}

void wyPODModel::dump() {
    LOGD("+++ start of POD dump +++");
    
    // dump texture
    for(int i = 0; i < m_pod->nNumTexture; i++) {
        LOGD("Texture %d: %s", i, m_pod->pTexture[i].pszName);
    }
    
    // dump node
    for(int i = 0; i < m_pod->nNumNode; i++) {
        LOGD("Node %d: %s, parent: %s, material: %d",
             i,
             m_pod->pNode[i].pszName,
             m_pod->pNode[i].nIdxParent == -1 ? "NONE" : m_pod->pNode[m_pod->pNode[i].nIdxParent].pszName,
             m_pod->pNode[i].nIdxMaterial);
    }
    
    // dump mesh
    for(int i = 0; i < m_pod->nNumMesh; i++) {
        LOGD("Mesh %d: vertex: %d, face: %d",
             i,
             m_pod->pMesh[i].nNumVertex,
             m_pod->pMesh[i].nNumFaces);
    }

    // dump light
    for(int i = 0; i < m_pod->nNumLight; i++) {
        LOGD("Light %d: type: %s", i, lightTypeString(m_pod->pLight[i].eType));
    }

    // dump camera
    for(int i = 0; i < m_pod->nNumCamera; i++) {
    	LOGD("Camera %d: target: %d, fov: %f, far: %f, near: %f",
    			i,
    			m_pod->pCamera[i].nIdxTarget,
    			m_pod->pCamera[i].fFOV,
    			m_pod->pCamera[i].fFar,
    			m_pod->pCamera[i].fNear);
    }
    
    // dump material
    for(int i = 0; i < m_pod->nNumMaterial; i++) {
        LOGD("Material %d: %s, effect file: %s, effect: %s",
             i,
             m_pod->pMaterial[i].pszName,
             m_pod->pMaterial[i].pszEffectFile == NULL ? "NONE" : m_pod->pMaterial[i].pszEffectFile,
             m_pod->pMaterial[i].pszEffectName == NULL ? "NONE" : m_pod->pMaterial[i].pszEffectName);
        LOGD("    nIdxTexDiffuse: %d", m_pod->pMaterial[i].nIdxTexDiffuse);
        LOGD("    nIdxTexAmbient: %d", m_pod->pMaterial[i].nIdxTexAmbient);
        LOGD("    nIdxTexSpecularColour: %d", m_pod->pMaterial[i].nIdxTexSpecularColour);
        LOGD("    nIdxTexSpecularLevel: %d", m_pod->pMaterial[i].nIdxTexSpecularLevel);
        LOGD("    nIdxTexBump: %d", m_pod->pMaterial[i].nIdxTexBump);
        LOGD("    nIdxTexEmissive: %d", m_pod->pMaterial[i].nIdxTexEmissive);
        LOGD("    nIdxTexGlossiness: %d", m_pod->pMaterial[i].nIdxTexGlossiness);
        LOGD("    nIdxTexOpacity: %d", m_pod->pMaterial[i].nIdxTexOpacity);
        LOGD("    nIdxTexReflection: %d", m_pod->pMaterial[i].nIdxTexReflection);
        LOGD("    nIdxTexRefraction: %d", m_pod->pMaterial[i].nIdxTexRefraction);
    }
    
    // other info
    LOGD("number of animation frame: %d", m_pod->nNumFrame);
    LOGD("animation fps: %d", m_pod->nFPS);
    LOGD("user data size: %d", m_pod->nUserDataSize);
    LOGD("flags: %d", m_pod->nFlags);

    LOGD("--- end of POD dump ---");
}
