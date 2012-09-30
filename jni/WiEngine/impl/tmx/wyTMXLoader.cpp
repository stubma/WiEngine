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
#include "wyTMXLoader.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLayerInfo.h"
#include "wyTMXObjectGroup.h"
#include "wyTileSetInfo.h"
#include <libxml/parser.h>
#include "wyGlobal.h"
#if ANDROID
	#include "wyJNI.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	UNKNOWN,
	MAP,
	TILESET,
	TILE,
	IMAGE,
	LAYER,
	DATA,
	PROPERTIES,
	PROPERTY,
	OBJECTGROUP,
	OBJECT,
	POLYLINE,
	POLYGON
} wyTMXTag;

typedef enum {
	ATTR_UNKNOWN,
	ATTR_VERSION,
	ATTR_ORIENTATION,
	ATTR_WIDTH,
	ATTR_HEIGHT,
	ATTR_TILEWIDTH,
	ATTR_TILEHEIGHT,
	ATTR_NAME,
	ATTR_FIRSTGID,
	ATTR_SPACING,
	ATTR_MARGIN,
	ATTR_VISIBLE,
	ATTR_OPACITY,
	ATTR_X,
	ATTR_Y,
	ATTR_TYPE,
	ATTR_COLOR,
	ATTR_POINTS
} wyTMXAttr;

typedef struct wyParseState {
	wyMapInfo* map;
	float resScale;
	const char* tmxDir;
	bool isFile;

	// tag stack
	int* tags;
	int num;
	int max;

	// last gid encountered
	int lastGid;

	// for data
	bool compressed;
} wyParseState;

static wyTMXTag getTag(const char* name) {
	if(!strcmp(name, "map"))
		return MAP;
	else if(!strcmp(name, "tileset"))
		return TILESET;
	else if(!strcmp(name, "tile"))
		return TILE;
	else if(!strcmp(name, "image"))
		return IMAGE;
	else if(!strcmp(name, "layer"))
		return LAYER;
	else if(!strcmp(name, "data"))
		return DATA;
	else if(!strcmp(name, "properties"))
		return PROPERTIES;
	else if(!strcmp(name, "property"))
		return PROPERTY;
	else if(!strcmp(name, "objectgroup"))
		return OBJECTGROUP;
	else if(!strcmp(name, "object"))
		return OBJECT;
	else if(!strcmp(name, "polyline"))
		return POLYLINE;
	else if(!strcmp(name, "polygon"))
		return POLYGON;
	else
		return UNKNOWN;
}

static wyTMXAttr getAttr(const char* name) {
	if(!strcmp(name, "version"))
		return ATTR_VERSION;
	else if(!strcmp(name, "orientation"))
		return ATTR_ORIENTATION;
	else if(!strcmp(name, "width"))
		return ATTR_WIDTH;
	else if(!strcmp(name, "height"))
		return ATTR_HEIGHT;
	else if(!strcmp(name, "tilewidth"))
		return ATTR_TILEWIDTH;
	else if(!strcmp(name, "tileheight"))
		return ATTR_TILEHEIGHT;
	else if(!strcmp(name, "name"))
		return ATTR_NAME;
	else if(!strcmp(name, "firstgid"))
		return ATTR_FIRSTGID;
	else if(!strcmp(name, "spacing"))
		return ATTR_SPACING;
	else if(!strcmp(name, "margin"))
		return ATTR_MARGIN;
	else if(!strcmp(name, "visible"))
		return ATTR_VISIBLE;
	else if(!strcmp(name, "opacity"))
		return ATTR_OPACITY;
	else if(!strcmp(name, "x"))
		return ATTR_X;
	else if(!strcmp(name, "y"))
		return ATTR_Y;
	else if(!strcmp(name, "type"))
		return ATTR_TYPE;
	else if(!strcmp(name, "color"))
		return ATTR_COLOR;
	else if(!strcmp(name, "points"))
		return ATTR_POINTS;
	else
		return ATTR_UNKNOWN;
}

static void pushTag(wyParseState* state, int tag) {
	while(state->num >= state->max) {
		state->max *= 2;
		state->tags = (int*)wyRealloc(state->tags, state->max);
	}

	state->tags[state->num++] = tag;
}

static inline void popTag(wyParseState* state) {
	state->num--;
}

static inline int topTag(wyParseState* state) {
	return state->tags[state->num - 1];
}

static inline int parentTag(wyParseState* state) {
	return state->tags[state->num - 2];
}

static inline int grandpaTag(wyParseState* state) {
	return state->tags[state->num - 3];
}

static const char* getAttrValue(const char** atts, const char* name) {
	for(int i = 0; atts[i] != NULL; i += 2) {
		if(!strcmp(atts[i], name))
			return atts[i + 1];
	}
	return NULL;
}

#ifdef __cplusplus
}
#endif

void wyTMXLoader::startElement(void* ctx, const xmlChar *name, const xmlChar **atts) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;

	// set tag
	pushTag(state, getTag((const char*)name));

	switch(topTag(state)) {
		case MAP:
			for(int i = 0; atts[i] != NULL; i += 2) {
				// get attr and value
				const char* key = (const char*)atts[i];
				const char* value = (const char*)atts[i + 1];
				wyTMXAttr attr = getAttr(key);

				// check attr
				switch(attr) {
					case ATTR_VERSION:
						if(strcmp("1.0", value)) {
							LOGE("Doesn't support TMX file whose version is not 1.0");
						}
						break;
					case ATTR_ORIENTATION:
						if(!strcmp(value, "orthogonal"))
							state->map->orientation = ORIENTATION_ORTHOGONAL;
						else if(!strcmp(value, "isometric"))
							state->map->orientation = ORIENTATION_ISOMETRIC;
						else if(!strcmp(value, "hexagonal"))
							state->map->orientation = ORIENTATION_HEXAGONAL;
						else {
							LOGE("Unsupported orientation: %s", value);
						}
						break;
					case ATTR_WIDTH:
						state->map->mapWidth = atoi(value);
						break;
					case ATTR_HEIGHT:
						state->map->mapHeight = atoi(value);
						break;
					case ATTR_TILEWIDTH:
						state->map->tileWidth = atof(value) * state->resScale;
						break;
					case ATTR_TILEHEIGHT:
						state->map->tileHeight = atof(value) * state->resScale;
						break;
				}
			}
			break;
		case TILESET:
		{
			const char* externalFile = getAttrValue((const char**)atts, "source");
			if(externalFile == NULL) {
				wyTileSetInfo* tileset = wyTileSetInfoNew();
				wyArrayPush(state->map->tilesets, tileset);

				for(int i = 0; atts[i] != NULL; i += 2) {
					// get attr and value
					const char* key = (const char*)atts[i];
					const char* value = (const char*)atts[i + 1];
					wyTMXAttr attr = getAttr(key);

					// check attr
					switch(attr) {
						case ATTR_NAME:
							tileset->name = (char*)wyCalloc(strlen(value) + 1, sizeof(char));
							strcpy((char*)tileset->name, value);
							break;
						case ATTR_FIRSTGID:
							tileset->firstGid = atoi(value);
							break;
						case ATTR_SPACING:
							tileset->spacing = atof(value) * state->resScale;
							break;
						case ATTR_MARGIN:
							tileset->margin = atof(value) * state->resScale;
							break;
						case ATTR_TILEWIDTH:
							tileset->tileWidth = atof(value) * state->resScale;
							break;
						case ATTR_TILEHEIGHT:
							tileset->tileHeight = atof(value) * state->resScale;
							break;
					}
				}
			} else {
				if(state->tmxDir == NULL) {
					int id = wyUtils::getResId(externalFile, "raw", "xml");
					if(id != 0) {
						size_t len;
						char* data = wyUtils::loadRaw(id, &len);
						load(data, len, state->map, state->tmxDir, state->isFile, state->resScale);
						wyFree(data);
					}
				} else {
					size_t len;
					const char* path = wyUtils::appendPathComponent(state->tmxDir, externalFile);
					char* data = wyUtils::loadRaw(path, state->isFile, &len);
					load(data, len, state->map, state->tmxDir, state->isFile, state->resScale);
					wyFree(data);
					wyFree((void*)path);
				}

				// firstgid is not written in external tileset, so we must read it from current tmx
				wyTileSetInfo* tileset = (wyTileSetInfo*)wyArrayPeek(state->map->tilesets);
				for(int i = 0; atts[i] != NULL; i += 2) {
					// get attr and value
					const char* key = (const char*)atts[i];
					const char* value = (const char*)atts[i + 1];
					wyTMXAttr attr = getAttr(key);

					// check attr
					switch(attr) {
						case ATTR_FIRSTGID:
							tileset->firstGid = atoi(value);
							break;
					}
				}
			}
			break;
		}
		case IMAGE:
		{
			const char* imageName = wyUtils::lastPathComponent(getAttrValue((const char**)atts, "source"));
			if(state->tmxDir == NULL) {
				int id = wyUtils::getResId(imageName, "drawable", NULL);
				if(id != 0) {
					wyTileSetInfo* tileset = (wyTileSetInfo*)wyArrayPeek(state->map->tilesets);
					tileset->sourceImageId = id;
				}
			} else {
				const char* path = wyUtils::appendPathComponent(state->tmxDir, imageName);
				if(path != NULL) {
					wyTileSetInfo* tileset = (wyTileSetInfo*)wyArrayPeek(state->map->tilesets);
					tileset->sourceImagePath = path;
					tileset->sourceImageIsFile = state->isFile;
				}
			}
			wyFree((void*)imageName);
			break;
		}
		case TILE:
		{
			wyTileSetInfo* tileset = (wyTileSetInfo*)wyArrayPeek(state->map->tilesets);
			state->lastGid = tileset->firstGid + atoi(getAttrValue((const char**)atts, "id"));
			wyMapInfoNewTileProperties(state->map, state->lastGid);
			break;
		}
		case PROPERTY:
			switch(grandpaTag(state)) {
				case MAP:
					wyMapInfoAddProperty(state->map, getAttrValue((const char**)atts, "name"), (const char*)getAttrValue((const char**)atts, "value"));
					break;
				case TILE:
					wyMapInfoAddTileProperty(state->map, state->lastGid, getAttrValue((const char**)atts, "name"), (const char*)getAttrValue((const char**)atts, "value"));
					break;
				case LAYER:
				{
					wyLayerInfo* layer = (wyLayerInfo*)wyArrayPeek(state->map->layers);
					wyLayerInfoAddProperty(layer, getAttrValue((const char**)atts, "name"), getAttrValue((const char**)atts, "value"));
					break;
				}
				case OBJECTGROUP:
				{
					wyTMXObjectGroup* group = (wyTMXObjectGroup*)wyArrayPeek(state->map->objectGroups);
					group->addProperty(getAttrValue((const char**)atts, "name"), getAttrValue((const char**)atts, "value"));
					break;
				}
				case OBJECT:
				{
					wyTMXObjectGroup* group = (wyTMXObjectGroup*)wyArrayPeek(state->map->objectGroups);
					wyTMXObject* object = group->getObjectAt(group->getObjectCount() - 1);
					group->addObjectProperty(object, getAttrValue((const char**)atts, "name"), getAttrValue((const char**)atts, "value"));
					break;
				}
			}
			break;
		case LAYER:
		{
			wyLayerInfo* layer = wyLayerInfoNew();
			wyArrayPush(state->map->layers, layer);

			for(int i = 0; atts[i] != NULL; i += 2) {
				// get attr and value
				const char* key = (const char*)atts[i];
				const char* value = (const char*)atts[i + 1];
				wyTMXAttr attr = getAttr(key);

				// check some optional attribute
				const char* visible = getAttrValue((const char**)atts, "visible");
				if(visible == NULL)
					layer->visible = true;
				const char* alpha = getAttrValue((const char**)atts, "opacity");
				if(alpha == NULL)
					layer->alpha = 255;

				// check attr
				switch(attr) {
					case ATTR_NAME:
						layer->name = (char*)wyCalloc(strlen(value) + 1, sizeof(char));
						strcpy(layer->name, value);
						break;
					case ATTR_WIDTH:
						layer->layerWidth = atoi(value);
						break;
					case ATTR_HEIGHT:
						layer->layerHeight = atoi(value);
						break;
					case ATTR_VISIBLE:
						layer->visible = atoi(value) == 1;
						break;
					case ATTR_OPACITY:
						layer->alpha = atof(value) * 255.f;
						break;
					case ATTR_X:
						layer->offsetX = atof(value) * state->resScale;
						break;
					case ATTR_Y:
						layer->offsetY = atof(value) * state->resScale;
						break;
				}
			}
			break;
		}
		case DATA:
		{
			// check encoding
			const char* encoding = getAttrValue((const char**)atts, "encoding");
			if(strcmp(encoding, "base64")) {
				LOGE("Unsupported layer data encoding: %s", encoding);
				break;
			}

			// check compression
			const char* compression = getAttrValue((const char**)(atts), "compression");
			state->compressed = compression != NULL;
			if(compression != NULL && strcmp(compression, "gzip") && strcmp(compression, "zlib")) {
				LOGE("Unsupported layer data compression: %s", compression);
				break;
			}

			break;
		}
		case OBJECTGROUP:
		{
			wyTMXObjectGroup* group = wyTMXObjectGroup::make();
			wyArrayPush(state->map->objectGroups, group);
			group->retain();

			for(int i = 0; atts[i] != NULL; i += 2) {
				// get attr and value
				const char* key = (const char*)atts[i];
				const char* value = (const char*)atts[i + 1];
				wyTMXAttr attr = getAttr(key);

				// check attr
				switch(attr) {
					case ATTR_NAME:
						group->setName(value);
						break;
					case ATTR_X:
						group->setOffsetX(atof(value) * state->resScale);
						break;
					case ATTR_Y:
						group->setOffsetY(atof(value) * state->resScale);
						break;
					case ATTR_COLOR:
						group->setColor(atoi(value));
						break;
					case ATTR_OPACITY:
						group->setOpacity(atof(value));
						break;
				}
			}

			break;
		}
		case OBJECT:
		{
			// create new object hash
			wyTMXObjectGroup* group = (wyTMXObjectGroup*)wyArrayPeek(state->map->objectGroups);
			wyTMXObject* object = group->newObject();

			// set object property
			for(int i = 0; atts[i] != NULL; i += 2) {
				// get attr and value
				const char* key = (const char*)atts[i];
				const char* value = (const char*)atts[i + 1];
				wyTMXAttr attr = getAttr(key);

				// check attr
				switch(attr) {
					case ATTR_NAME:
					case ATTR_TYPE:
						group->addObjectProperty(object, key, value);
						break;
					case ATTR_X:
					{
						float x = atof(value) * state->resScale;
						char buf[30];
						sprintf(buf, "%f", x);
						group->addObjectProperty(object, key, buf);
						break;
					}
					case ATTR_Y:
					{
						float y = atof(value) * state->resScale;
						char buf[30];
						sprintf(buf, "%f", y);
						group->addObjectProperty(object, key, buf);
						break;
					}
					case ATTR_WIDTH:
					case ATTR_HEIGHT:
					{
						float f = atof(value) * state->resScale;
						char buf[30];
						sprintf(buf, "%f", f);
						group->addObjectProperty(object, key, buf);
						break;
					}
				}
			}
			break;
		}
		case POLYGON:
		case POLYLINE:
		{
			switch(parentTag(state)) {
				case OBJECT:
				{
					wyTMXObjectGroup* group = (wyTMXObjectGroup*)wyArrayPeek(state->map->objectGroups);
					wyTMXObject* object = group->getObjectAt(group->getObjectCount() - 1);

					// set type
					switch(topTag(state)) {
						case POLYGON:
							object->setType(wyTMXObject::POLYGON);
							break;
						case POLYLINE:
							object->setType(wyTMXObject::POLYLINE);
							break;
					}

					// parse attributes
					for(int i = 0; atts[i] != NULL; i += 2) {
						// get attr and value
						const char* key = (const char*)atts[i];
						const char* value = (const char*)atts[i + 1];
						wyTMXAttr attr = getAttr(key);

						// check attr
						switch(attr) {
							case ATTR_POINTS:
							{
								// make a copy of value string
								char* v = (char*)wyUtils::copy(value);

								// parse space character
								char* p = strtok(v, " ");
								char* n = NULL;
								while(p) {
									n = strtok(NULL, " ");

									// parse point
									float x, y;
									sscanf(p, "%f,%f", &x, &y);
									object->getPoints().addPoint(x * state->resScale, y * state->resScale);

									// next token
									p = n;
								}

								// free
								wyFree(v);
								break;
							}
						}
					}

					break;
				}
			}
			break;
		}
	}
}

void wyTMXLoader::endElement(void* ctx, const xmlChar *name) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;

	// pop
	popTag(state);
}

void wyTMXLoader::characters(void* ctx, const xmlChar *ch, int len) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;

	// check tag
	switch(topTag(state)) {
		case DATA:
		{
			// decode
			size_t outLen = 0;
			char* tmp = (char*)wyCalloc(len + 1, sizeof(char));
			strncpy(tmp, (const char*)ch, len);
			outLen = wyUtils::trim(tmp);
			char* data = wyUtils::decodeBase64((const char*)tmp, outLen, &outLen);
			wyFree(tmp);

			// decompress
			if(state->compressed) {
				char* inflate = NULL;
				outLen = wyUtils::gunzip(data, outLen, &inflate);
				wyFree(data);
				data = inflate;
			}

			// convert to int array
			if(outLen % 4 == 0) {
				wyLayerInfo* layer = (wyLayerInfo*)wyArrayPeek(state->map->layers);
				layer->tiles = (int*)wyMalloc(outLen / 4 * sizeof(int));
				for(int i = 0; i < outLen; i += 4) {
					layer->tiles[i / 4] = ((data[i + 3] & 0xFF) << 24) | ((data[i + 2] & 0xFF) << 16) | ((data[i + 1] & 0xFF) << 8) | (data[i] & 0xFF);
				}
			}

			wyFree(data);
			break;
		}
	}
}

void wyTMXLoader::warning(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGW("%s", msg);
    va_end(args);
}

void wyTMXLoader::error(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGE("%s", msg);
    va_end(args);
}

wyMapInfo* wyTMXLoader::load(char* data, size_t len, wyMapInfo* mi, const char* tmxDir, bool isFile, float resScale) {
	xmlSAXHandlerV1 sSAXHandler = {
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		startElement,
		endElement,
		NULL,
		characters,
		NULL,
		NULL,
		NULL,
		warning,
		error,
		NULL,
		NULL,
		NULL,
		NULL,
		0
	};

	// create map object
	wyMapInfo* map = mi == NULL ? wyMapInfoNew() : mi;
	wyParseState* state = (wyParseState*)wyCalloc(1, sizeof(wyParseState));
	state->map = map;
	state->resScale = resScale;
	state->tmxDir = wyUtils::copy(tmxDir);
	state->isFile = isFile;
	state->tags = (int*)wyMalloc(10 * sizeof(int));
	state->tags[0] = -1;
	state->num = 1;
	state->max = 10;

	// start to parser xml file
	xmlSAXUserParseMemory((xmlSAXHandlerPtr)&sSAXHandler, state, data, len);

	// clean parser
	xmlCleanupParser();

	// release helper struct
	wyFree(state->tags);
	wyFree((void*)state->tmxDir);
	wyFree(state);

	return map;
}

wyMapInfo* wyTMXLoader::load(int resId) {
	size_t len;
	float scale;
	char* data = wyUtils::loadRaw(resId, &len, &scale);
	wyMapInfo* map = load(data, len, NULL, NULL, false, scale);
	wyFree(data);
	return map;
}

wyMapInfo* wyTMXLoader::load(const char* path, bool isFile) {
	size_t len;
	char* data = wyUtils::loadRaw(path, isFile, &len);
	const char* dir = wyUtils::deleteLastPathComponent(path);
	wyMapInfo* map = load(data, len, NULL, dir, isFile, wyDevice::density / wyDevice::defaultInDensity);
	wyFree((void*)dir);
	wyFree(data);
	return map;
}
