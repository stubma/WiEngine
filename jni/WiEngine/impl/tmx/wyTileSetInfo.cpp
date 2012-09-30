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
#include "wyTileSetInfo.h"
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

wyTileSetInfo* wyTileSetInfoNew() {
	wyTileSetInfo* info = (wyTileSetInfo*)wyCalloc(1, sizeof(wyTileSetInfo));
	return info;
}

void wyTileSetInfoDestroy(wyTileSetInfo* info) {
    wyObjectRelease(info->texture);
	if(info->name != NULL)
		wyFree((void*)info->name);
	if(info->sourceImagePath != NULL)
		wyFree((void*)info->sourceImagePath);
	wyFree(info);
}

wyRect wyTileSetInfoGetRect(wyTileSetInfo* info, int gid) {
	wyRect rect = wyrZero;
	rect.width = info->tileWidth;
	rect.height = info->tileHeight;

	gid -= info->firstGid;
	int maxX = (int)((info->imageWidth - info->margin * 2 + info->spacing) / (info->tileWidth + info->spacing));
	rect.x = (gid % maxX) * (info->tileWidth + info->spacing) + info->margin;
	rect.y = (gid / maxX) * (info->tileHeight + info->spacing) + info->margin;

	return rect;
}

wyTileSetInfo* wyTileSetInfoCopy(wyTileSetInfo* info) {
	wyTileSetInfo* copy = wyTileSetInfoNew();
	memcpy(copy, info, sizeof(wyTileSetInfo));
	copy->name = (char*)wyCalloc(strlen(info->name) + 1, sizeof(char));
	strcpy((char*)copy->name, info->name);
	if(info->sourceImagePath != NULL) {
		copy->sourceImagePath = (char*)wyCalloc(strlen(info->sourceImagePath) + 1, sizeof(char));
		strcpy((char*)copy->sourceImagePath, info->sourceImagePath);
	}
	return copy;
}

#ifdef __cplusplus
}
#endif
