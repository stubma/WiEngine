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
#include "wyMapInfo.h"
#include <stdlib.h>
#include <string.h>
#include "wyLayerInfo.h"
#include "wyTMXObjectGroup.h"
#include "wyTileSetInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

static bool releaseLayerInfo(wyArray* arr, void* ptr, int index, void* data) {
	wyLayerInfo* info = (wyLayerInfo*)ptr;
	wyLayerInfoDestroy(info);
	return true;
}

static bool releaseTileSetInfo(wyArray* arr, void* ptr, int index, void* data) {
	wyTileSetInfo* info = (wyTileSetInfo*)ptr;
	wyTileSetInfoDestroy(info);
	return true;
}

static bool releaseObjectGroup(wyArray* arr, void* ptr, int index, void* data) {
	wyTMXObjectGroup* info = (wyTMXObjectGroup*)ptr;
	info->release();
	return true;
}

bool releasePropertyHash(void* elt, void* data) {
	wyKeyValueHash* hash = (wyKeyValueHash*)elt;
	wyFree(hash->key);
	wyFree(hash->value);
	wyFree(elt);
	return false;
}

static bool releaseTileHash(void* elt, void* data) {
	wyTileHash* hash = (wyTileHash*)elt;
	wyHashSetFilter(hash->properties, releasePropertyHash, NULL);
	wyHashSetDestroy(hash->properties);
	wyFree(elt);
	return false;
}

int propertyHashEquals(void* ptr, void* elt) {
	return !strcmp(((wyKeyValueHash*)elt)->key, (const char*)ptr);
}

void* buildPropertyHash(void* ptr, void* data) {
	wyKeyValueHash* hash = (wyKeyValueHash*)wyCalloc(1, sizeof(wyKeyValueHash));
	hash->key = (char*)ptr;
	hash->value = (char*)data;
	return hash;
}

static int tileHashEquals(void* ptr, void* elt) {
	wyTileHash* hash = (wyTileHash*)elt;
	return hash->gid == *(int*)ptr;
}

static void* buildTileHash(void* ptr, void* data) {
	wyTileHash* hash = (wyTileHash*)wyCalloc(1, sizeof(wyTileHash));
	hash->gid = *(int*)ptr;
	hash->properties = (wyHashSet*)data;
	return hash;
}

wyMapInfo* wyMapInfoNew() {
	wyMapInfo* info = (wyMapInfo*)wyCalloc(1, sizeof(wyMapInfo));
	info->layers = wyArrayNew(3);
	info->tilesets = wyArrayNew(3);
	info->objectGroups = wyArrayNew(1);
	info->properties = wyHashSetNew(2, propertyHashEquals, buildPropertyHash);
	info->tileProperties = wyHashSetNew(3, tileHashEquals, buildTileHash);
	return info;
}

void wyMapInfoDestroy(wyMapInfo* info) {
    if(info->layers) {
     	wyArrayEach(info->layers, releaseLayerInfo, NULL);
        wyArrayClear(info->layers);
        wyArrayDestroy(info->layers);   
    }
    if(info->tilesets) {
     	wyArrayEach(info->tilesets, releaseTileSetInfo, NULL);
        wyArrayClear(info->tilesets);
        wyArrayDestroy(info->tilesets);   
    }
    if(info->objectGroups) {
        wyArrayEach(info->objectGroups, releaseObjectGroup, NULL);
        wyArrayClear(info->objectGroups);
        wyArrayDestroy(info->objectGroups);   
    }
    if(info->properties) {
        wyHashSetFilter(info->properties, releasePropertyHash, NULL);
        wyHashSetDestroy(info->properties);   
    }
    if(info->tileProperties) {
        wyHashSetFilter(info->tileProperties, releaseTileHash, NULL);
        wyHashSetDestroy(info->tileProperties);   
    }
	if(info->filename)
		wyFree(info->filename);
	wyFree(info);
}

void wyMapInfoAddProperty(wyMapInfo* info, const char* key, const char* value) {
	char* k = (char*)wyCalloc(strlen(key) + 1, sizeof(char));
	strcpy(k, key);
	char* v = (char*)wyCalloc(strlen(value) + 1, sizeof(char));
	strcpy(v, value);
	wyHashSetInsert(info->properties, wyUtils::strHash(k), k, v);
}

char* wyMapInfoGetProperty(wyMapInfo* info, const char* name) {
	wyKeyValueHash* hash = (wyKeyValueHash*)wyHashSetFind(info->properties, wyUtils::strHash(name), (void*)name);
	if(hash != NULL)
		return hash->value;
	else
		return NULL;
}

void wyMapInfoNewTileProperties(wyMapInfo* info, int gid) {
	wyHashSet* properties = wyHashSetNew(3, propertyHashEquals, buildPropertyHash);
	wyHashSetInsert(info->tileProperties, gid, &gid, properties);
}

char* wyMapInfoGetTileProperty(wyMapInfo* info, int gid, const char* key) {
	wyTileHash* tileHash = (wyTileHash*)wyHashSetFind(info->tileProperties, gid, &gid);
	if(tileHash != NULL) {
		wyKeyValueHash* pHash = (wyKeyValueHash*)wyHashSetFind(tileHash->properties, wyUtils::strHash(key), (void*)key);
		if(pHash != NULL)
			return pHash->value;
	}

	return NULL;
}

void wyMapInfoAddTileProperty(wyMapInfo* info, int gid, const char* key, const char* value) {
	wyTileHash* tileHash = (wyTileHash*)wyHashSetFind(info->tileProperties, gid, &gid);
	if(tileHash != NULL) {
		char* k = (char*)wyCalloc(strlen(key) + 1, sizeof(char));
		strcpy(k, key);
		char* v = (char*)wyCalloc(strlen(value) + 1, sizeof(char));
		strcpy(v, value);
		wyHashSetInsert(tileHash->properties, wyUtils::strHash(k), k, v);
	}
}
    
int wyMapInfoGetTileSetIndex(wyMapInfo* info, int gid) {
    for(int i = 0; i < info->tilesets->num; i++) {
        wyTileSetInfo* tileset = (wyTileSetInfo*)wyArrayGet(info->tilesets, i);
        if(tileset->firstGid > gid)
            return i - 1;
    }
    return info->tilesets->num - 1;
}

#ifdef __cplusplus
}
#endif
