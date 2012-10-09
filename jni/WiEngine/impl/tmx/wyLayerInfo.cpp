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
#include "wyLayerInfo.h"
#include <stdlib.h>
#include <string.h>
#include "wyMapInfo.h"
#include "wyTypes.h"
#include "wyUtils.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int propertyHashEquals(void* ptr, void* elt);
extern void* buildPropertyHash(void* ptr, void* data);
extern bool releasePropertyHash(void* elt, void* data);

wyLayerInfo* wyLayerInfoNew() {
	wyLayerInfo* info = (wyLayerInfo*)wyCalloc(1, sizeof(wyLayerInfo));
	info->properties = wyHashSetNew(2, propertyHashEquals, buildPropertyHash);
	return info;
}

void wyLayerInfoDestroy(wyLayerInfo* info) {
    if(info->properties) {
        wyHashSetFilter(info->properties, releasePropertyHash, NULL);
        wyHashSetDestroy(info->properties);
    }
	if(info->name != NULL)
		wyFree(info->name);
	if(info->tiles != NULL)
		wyFree(info->tiles);
	wyFree(info);
}

void wyLayerInfoAddProperty(wyLayerInfo* info, const char* key, const char* value) {
	char* k = (char*)wyCalloc(strlen(key) + 1, sizeof(char));
	strcpy(k, key);
	char* v = (char*)wyCalloc(strlen(value) + 1, sizeof(char));
	strcpy(v, value);
	wyHashSetInsert(info->properties, wyUtils::strHash(k), k, v);
}

char* wyLayerInfoGetProperty(wyLayerInfo* info, const char* name) {
	wyKeyValueHash* hash = (wyKeyValueHash*)wyHashSetFind(info->properties, wyUtils::strHash(name), (void*)name);
	if(hash != NULL)
		return hash->value;
	else
		return NULL;
}

#ifdef __cplusplus
}
#endif
