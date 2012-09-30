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
#include "wyLog.h"
#include "wyChipmunkPELoader.h"
#include <ctype.h>
#include <libxml/parser.h>
#include "wyTypes.h"
#include "wyUtils.h"

typedef enum enumState {
	State_ready,
	State_parsingMetadata,
	State_parsingBodies,
	State_parsingBody,
	State_parsingFixtures,
	State_parsingFixture,
	State_parsingShapes,
	State_parsingShape,
    State_parsingCircle,
	State_finish
} enumState;

typedef struct wyParseState {
	// last key name
	const char* lastKey;

	// tag stack
	int* tags;
	int num;
	int max;

	// state
	enumState state;

	wyCPBodyMeta* 		bodyMeta;
    wyCPFixtureInfo*    fixtureInfo;

	// shape related properties
	cpVect*	vertices;
	int		vertexCount;
	int		vertexMax;
    
    // for circle
    float   radius;
    wyPoint position;

	bool	isSensor;
} wyParseState;

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

static wyPListTag getPListTag(const char* name) {
	if(!strcmp(name, "plist"))
		return TAG_PLIST;
	else if(!strcmp(name, "dict"))
		return TAG_DICT;
	else if(!strcmp(name, "key"))
		return TAG_KEY;
	else if(!strcmp(name, "real"))
		return TAG_REAL;
	else if(!strcmp(name, "string"))
		return TAG_STRING;
	else if(!strcmp(name, "integer"))
		return TAG_INTEGER;
	else if(!strcmp(name, "true"))
		return TAG_TRUE;
	else if(!strcmp(name, "false"))
		return TAG_FALSE;
	else if(!strcmp(name, "array"))
        return TAG_ARRAY;
	else
	    return UNKNOWN_PLIST_TAG;
}

static void logstate(const char* tag,wyParseState* state) {
    const char* key = (state->lastKey ? state->lastKey : "   null");
    switch(state->state) {
        case State_ready: 
            LOGD("%s %s State_ready", tag, key);
            break;
        case State_parsingMetadata: 
            LOGD("%s %s State_parsingMetadata", tag, key);
            break;
        case State_parsingBodies: 
            LOGD("%s %s State_parsingBodies", tag, key);
            break;
        case State_parsingBody: 
            LOGD("%s %s State_parsingBody", tag, key);
            break;
        case State_parsingFixtures: 
            LOGD("%s %s State_parsingFixtures", tag, key);
            break;
        case State_parsingFixture: 
            LOGD("%s %s State_parsingFixture", tag, key);
            break;
        case State_parsingShapes: 
            LOGD("%s %s State_parsingShapes", tag, key);
            break;
        case State_parsingShape: 
            LOGD("%s %s State_parsingShape", tag, key);
            break;
        case State_parsingCircle: 
            LOGD("%s %s State_parsingCircle", tag, key);
            break; 
        default:
            break;
    }
}

static float getArea(cpVect* vertices, int numVertices) {
    float area = 0.0f;
    int r = (numVertices-1);
    area += vertices[0].x * vertices[r].y - vertices[r].x * vertices[0].y;
    for (int i=0; i<numVertices-1; ++i) {
        area += vertices[r-i].x*vertices[r-(i+1)].y-vertices[r-(i+1)].x*vertices[r-i].y;
    }
    area *= .5f;

    return area;
}

static cpVect getPolyshapeCenter(cpVect* vertices, int numVertices) {
    float centerX = 0.0f;
    float centerY = 0.0f;

    for(int i = 0; i < numVertices - 1; ++i) {
        centerX += vertices[i].x;
        centerY += vertices[i].y;
    }

    centerX /= numVertices;
    centerY /= numVertices;
    
    return cpv(centerX, centerY);
}

wyCPFixtureInfo::wyCPFixtureInfo() :
        m_arrayShapes(wyArrayNew(10)),
        m_mass(0.0f),
        m_momentum(0.0f),
        m_elasticity(0.0f),
        m_friction(0.0f),
        m_surface_velocity(cpvzero),
    	m_group(0),
    	m_layers(-1),
    	m_collisionType(0),
    	m_isSensor(false),
    	m_fixture_type(CP_POLY_SHAPE) {
}
        
wyCPFixtureInfo::~wyCPFixtureInfo() {
    for(int i = 0; i < m_arrayShapes->num; ++i) {
        wyCPShapeInfo* si = (wyCPShapeInfo*)wyArrayGet(m_arrayShapes, i);
        wyFree(si);
    }    
}

void wyCPFixtureInfo::addShapeInfo(wyCPShapeInfo* si) {
    wyArrayPush(m_arrayShapes, si);    
}

void wyCPFixtureInfo::initialize() {
    switch (m_fixture_type) {
        case CP_POLY_SHAPE:
        {
            float totalArea = 0.0f;
            for(int i = 0; i < m_arrayShapes->num; ++i) {
                wyCPShapeInfo* si = (wyCPShapeInfo*)wyArrayGet(m_arrayShapes, i);
                si->area= getArea(si->vertices, si->vertexCount);
                si->offset = getPolyshapeCenter(si->vertices, si->vertexCount);
                totalArea += si->area;
            }
            
            for(int i = 0; i < m_arrayShapes->num; ++i) {
                wyCPShapeInfo* si = (wyCPShapeInfo*)wyArrayGet(m_arrayShapes, i);
                float mass = m_mass * si->area / totalArea;
                si->momentum = cpMomentForPoly(mass, si->vertexCount, si->vertices, cpvzero);
                m_momentum += si->momentum;
            }

            break;
        }
        case CP_CIRCLE_SHAPE:
        {
            float totalArea = 0.0f;
            for(int i = 0; i < m_arrayShapes->num; ++i) {
                wyCPShapeInfo* si = (wyCPShapeInfo*)wyArrayGet(m_arrayShapes, i);
                si->area= cpAreaForCircle(0, si->radius);
                totalArea += si->area;
            }
            
            for(int i = 0; i < m_arrayShapes->num; ++i) {
                wyCPShapeInfo* si = (wyCPShapeInfo*)wyArrayGet(m_arrayShapes, i);
                float mass = m_mass * si->area / totalArea;
                si->momentum = cpMomentForCircle(mass, 0, si->radius, si->offset);
                m_momentum += si->momentum;
            }
            break;
        }
        default:
            break;
    }
}

wyCPBodyMeta::wyCPBodyMeta(const char* name) :
    m_arrayFixtureInfo(wyArrayNew(4)),
    m_mass(0.0f),
    m_momentum(0.0f) {
    setName(name);
}

wyCPBodyMeta::~wyCPBodyMeta() {
    for(int i = 0; i < m_arrayFixtureInfo->num; ++i) {
        wyCPFixtureInfo* fi = (wyCPFixtureInfo*)wyArrayGet(m_arrayFixtureInfo, i);
        fi->release();
    }
    wyArrayDestroy(m_arrayFixtureInfo);
}

void wyCPBodyMeta::addFixtureInfo(wyCPFixtureInfo* fi) {
    fi->initialize();
    m_mass += fi->m_mass;
    m_momentum += fi->m_momentum;
    wyArrayPush(m_arrayFixtureInfo, fi);
}

cpBody* wyCPBodyMeta::createBody(wyChipmunk* chipmunk) {
    cpBody* body = cpBodyNew(m_mass, m_momentum);
    cpSpaceAddBody(chipmunk->getSpace(), body);
   
    for(int i = 0; i < m_arrayFixtureInfo->num; ++i) {
        wyCPFixtureInfo* fi = (wyCPFixtureInfo*)wyArrayGet(m_arrayFixtureInfo, i);
        
        switch (fi->m_fixture_type) {
            case CP_CIRCLE_SHAPE:
            {
                wyArray* arrayShapeInfo = fi->m_arrayShapes;
                for(int j = 0; j < arrayShapeInfo->num; ++j) {
                    wyCPShapeInfo* si = (wyCPShapeInfo*)wyArrayGet(arrayShapeInfo, j);
                    
                    cpShape* shape = cpCircleShapeNew(body, si->radius, si->offset);
                    shape->e = fi->m_elasticity;
                    shape->u = fi->m_friction;
                    shape->surface_v = fi->m_surface_velocity;
                    shape->group = fi->m_group;
                    shape->layers = fi->m_layers;
                    shape->collision_type = fi->m_collisionType;
                    shape->sensor = fi->m_isSensor;
                    
                    cpSpaceAddShape(chipmunk->getSpace(), shape);
                }   
                break;
            }
            case CP_POLY_SHAPE:
            {
                wyArray* arrayShapeInfo = fi->m_arrayShapes;
                
                for(int j = 0; j < arrayShapeInfo->num; ++j) {
                    wyCPShapeInfo* si = (wyCPShapeInfo*)wyArrayGet(arrayShapeInfo, j);
                    
                    cpShape* shape = cpPolyShapeNew(body, si->vertexCount, si->vertices, cpvzero);
                    shape->e = fi->m_elasticity;
                    shape->u = fi->m_friction;
                    shape->surface_v = fi->m_surface_velocity;
                    shape->group = fi->m_group;
                    shape->layers = fi->m_layers;
                    shape->collision_type = fi->m_collisionType;
                    shape->sensor = fi->m_isSensor;
                    
                    cpSpaceAddShape(chipmunk->getSpace(), shape);
                }            
                break;
            }
            default:
                LOGE("unknown fixture_type");
                break;
        }
    }

    return body;
}

wyPoint wyChipmunkPELoader::parsePoint(const char* v, bool withScale) {
	size_t len = strlen(v);
	char* tmp = (char*)wyCalloc(len + 1, sizeof(char));
	for(int i = 0, j = 0; i < len; i++) {
		if(!isspace(v[i])) {
			tmp[j++] = v[i];
		}
	}

	float w, h;
	sscanf(tmp, "{%f,%f}", &w, &h);
	wyFree(tmp);

    if(withScale)
	    return wyp(m_resScale * w, m_resScale * h);
    else
        return wyp(w, h);
}

void wyChipmunkPELoader::startElement(void* ctx, const xmlChar *name, const xmlChar **atts) {
	wyChipmunkPELoader* thiz = (wyChipmunkPELoader*)ctx;
	wyParseState* state = (wyParseState*)thiz->m_parseState;
    wyHashSet* hashSet = thiz->m_bodyMetas;
    
	// set tag
	pushTag(state, getPListTag((const char*)name));

	switch(topTag(state)) {
		case TAG_DICT:
			if(state->lastKey == NULL)
				break;

			switch(state->state) {
				case State_ready:
                {
					if(0 == strcmp(state->lastKey, "metadata"))
						state->state = State_parsingMetadata;
					else if(0 == strcmp(state->lastKey, "bodies"))
						state->state = State_parsingBodies;
					break;
                }
                case State_parsingBodies:
                {
                    wyCPBodyMeta* bodyMeta = WYNEW wyCPBodyMeta(state->lastKey);
                    wyHashSetInsert(hashSet, wyUtils::strHash(state->lastKey), bodyMeta, NULL);
                    
                    state->bodyMeta = bodyMeta;
                    state->state = State_parsingBody;
					break;
                }
                case State_parsingFixtures:
                {
					state->state = State_parsingFixture;
                    break;
                }
                case State_parsingFixture:
                {
                    if(0 == strcmp(state->lastKey, "circle")) {
                        state->state = State_parsingCircle;
                    }
                }                    
                default:
                    break;
			}
			break;

        case TAG_ARRAY:
            switch(state->state) {
				case State_parsingBody:
                    if(0 == strcmp(state->lastKey, "fixtures"))
                        state->state = State_parsingFixtures;
                        thiz->createFixtureInfo();
					break;
                    
				case State_parsingFixture:
                    if(0 == strcmp(state->lastKey, "polygons")) {
                        state->state = State_parsingShapes;
                    }
					break;
                    
				case State_parsingShapes:
                    state->state = State_parsingShape;
                    state->vertexCount = 0;
					break;

                default:
                    break;
			}

            break;
            
		case TAG_TRUE:
            switch(state->state) {
				case State_parsingFixture:
                {
                    if(0 == strcmp(state->lastKey, "isSensor"))
                        state->isSensor= true;
                }
                default:
                    break;
			}
			break;
		case TAG_FALSE:
            switch(state->state) {
				case State_parsingFixture:
                {
                    if(0 == strcmp(state->lastKey, "isSensor"))
                        state->isSensor = false;
                }
                default:
                    break;
			}
			break;
	}
}

void wyChipmunkPELoader::endElement(void* ctx, const xmlChar *name) {
	wyChipmunkPELoader* thiz = (wyChipmunkPELoader*)ctx;
	wyParseState* state = (wyParseState*)thiz->m_parseState;

	switch(topTag(state)) {
		case TAG_DICT:
			if(state->lastKey == NULL)
				break;

			switch(state->state) {
				case State_ready:
                    state->state = State_finish;
					break;

                case State_parsingMetadata:
                case State_parsingBodies:
					state->state = State_ready;
					break;

                case State_parsingBody:
					state->state = State_parsingBodies;
					break;

                case State_parsingFixture:
                    state->bodyMeta->addFixtureInfo(state->fixtureInfo);
					state->state = State_parsingFixtures;
                    break;
                    
                case State_parsingCircle:
                    thiz->createShape();
                    state->state = State_parsingFixture;
                    break;
                    
                default:
                    break;
			}
			break;

        case TAG_ARRAY:
            switch(state->state) {
				case State_parsingFixtures:
                    state->state = State_parsingBody;                        
					break;
                    
				case State_parsingShapes:
                    state->state = State_parsingFixture;
					break;
                    
				case State_parsingShape:
                    thiz->createShape(); 
                    state->state = State_parsingShapes;
					break;

                 default:
                    break;
			}

            break;
            
		case TAG_TRUE:
		case TAG_FALSE:

			break;
	}

	popTag(state);
}

void wyChipmunkPELoader::characters(void* ctx, const xmlChar *ch, int len) {
    wyChipmunkPELoader* thiz = (wyChipmunkPELoader*)ctx;
	wyParseState* state = (wyParseState*)thiz->m_parseState;
    
	// check tag
	switch(topTag(state)) {
		case TAG_KEY:
		{
            char* key = (char*)wyCalloc(len + 1, sizeof(char));
			strncpy(key, (const char*)ch, len);
			wyUtils::trim(key);

            if(state->state == State_parsingFixture && 0 == strcmp(state->lastKey, "fixture_type")) {
                if(0 == strcmp(key, "POLYGON")) {
                    state->fixtureInfo->m_fixture_type = CP_POLY_SHAPE;
                } else if(0 == strcmp(key, "CIRCLE")) {
                    state->fixtureInfo->m_fixture_type = CP_CIRCLE_SHAPE;
                } else {
                    LOGE("unknown fixture_type %s", key);
                }                    
            }
            
			// save the last key
			if(state->lastKey != NULL) {
				wyFree((void*)state->lastKey);
			}
			state->lastKey = key;
			break;
		}
		case TAG_INTEGER:
		{ 
            char* temp = (char*)wyCalloc(len + 1, sizeof(char));
			strncpy(temp, (const char*)ch, len);
			wyUtils::trim(temp);
            int value = atoi(temp);
            
			switch(state->state) {
				case State_parsingMetadata:
				{
					if(0 == strcmp(state->lastKey, "format")) 
						thiz->m_plistFormat = value;

                    break;
				}
                case State_parsingFixture:
                {
					if(0 ==strcmp(state->lastKey, "layers"))
						state->fixtureInfo->m_layers = value;
					else if(0 ==strcmp(state->lastKey, "group"))
					    state->fixtureInfo->m_group = value;
                    else if(0 ==strcmp(state->lastKey, "collision_type"))
                        state->fixtureInfo->m_collisionType = value;
                    
                    break;
                }
			}
            wyFree(temp);
			break;
		}
		case TAG_STRING:
		{   
            char* temp = (char*)wyCalloc(len + 1, sizeof(char));
			strncpy(temp, (const char*)ch, len);
			wyUtils::trim(temp);
            
			switch(state->state) {
				case State_parsingBody:
				{
					if( 0 == strcmp(state->lastKey, "anchorpoint") ) {
                        state->bodyMeta->m_anchorPoint = thiz->parsePoint(temp, false);
					}
					break;
				}
                case State_parsingShape:
				{
                    wyPoint p = thiz->parsePoint(temp);
                    if(state->vertexCount == state->vertexMax) {
                        state->vertexMax *=2;
                        cpVect* newVertices = new cpVect[state->vertexMax];
                        for(int i = 0; i < state->vertexCount; ++i)
                            newVertices[i] = state->vertices[i];

                        delete[] state->vertices;
                        state->vertices = newVertices;
                    }
					state->vertices[state->vertexCount].x = p.x;
                    state->vertices[state->vertexCount].y = p.y;
                    state->vertexCount++;
					break;
				}
                case State_parsingFixture:
				{
					if( 0 == strcmp(state->lastKey, "fixture_type") ) {
						if(0 == strcmp(temp, "POLYGON")) {
                            state->fixtureInfo->m_fixture_type = CP_POLY_SHAPE;
                        } else if(0 == strcmp(temp, "CIRCLE")) {
                            state->fixtureInfo->m_fixture_type = CP_CIRCLE_SHAPE;
                        } else {
                            LOGE("unknown fixture_type %s", temp);
                        }
					}
                    if( 0 == strcmp(state->lastKey, "surface_velocity") ) {
						wyPoint v = thiz->parsePoint(temp);
                        state->fixtureInfo->m_surface_velocity.x = v.x;
                        state->fixtureInfo->m_surface_velocity.y = v.y;
					}
					break;
				}
                case State_parsingCircle:
                {
                    if(0 == strcmp(state->lastKey, "position"))
						state->position = thiz->parsePoint(temp);
                    break;
                }
                    
                default:
                    break;
			}
            wyFree(temp);
            break;
		}

        case TAG_REAL: {
            char* temp = (char*)wyCalloc(len + 1, sizeof(char));
			strncpy(temp, (const char*)ch, len);
			wyUtils::trim(temp); 
            float value = atof(temp);

			switch(state->state) {
                case State_parsingFixture:
                {
					if(0 ==strcmp(state->lastKey, "friction"))
						state->fixtureInfo->m_friction = value;
					else if(0 ==strcmp(state->lastKey, "elasticity")) {
					    state->fixtureInfo->m_elasticity= value;
                    }
                    else if(0 ==strcmp(state->lastKey, "mass")) {
                        state->fixtureInfo->m_mass = value;
                    }
                    
                    break;
                }
                case State_parsingCircle:
                {
                    if(0 ==strcmp(state->lastKey, "radius"))
						state->radius = value * thiz->m_resScale;
                    break;
                }
                default:
                    break;
			}
            
            wyFree(temp);
            break;
        }
        
        default:
            break;
	}

    
}

void wyChipmunkPELoader::warning(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGW("%s", msg);
    va_end(args);
}

void wyChipmunkPELoader::error(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGE("%s", msg);
    va_end(args);
}

bool wyChipmunkPELoader::releaseHashElm(void* elt, void* data) {
    wyCPBodyMeta* elm = (wyCPBodyMeta*) elt;
    wyObjectRelease(elm);
    return true;
}

int wyChipmunkPELoader::hashElemEqual(void* ptr, void* elt) {
    wyCPBodyMeta* elm = (wyCPBodyMeta*)elt;
    return (0 == strcmp((char*)ptr, elm->getName()));
}

void* wyChipmunkPELoader::hashElemTrans(void* ptr, void* data) {
    return ptr;
}

wyChipmunkPELoader::wyChipmunkPELoader() :
        m_bodyMetas(wyHashSetNew(20, hashElemEqual, hashElemTrans)),
		m_resScale(1.0f) {
}

wyChipmunkPELoader::wyChipmunkPELoader(const char* filePath, bool isFile) :
        m_bodyMetas(wyHashSetNew(20, hashElemEqual, hashElemTrans)),
		m_resScale(1.0f) {
    loadBodies(filePath, isFile);
}

wyChipmunkPELoader::wyChipmunkPELoader(int resId) :
        m_bodyMetas(wyHashSetNew(20, hashElemEqual, hashElemTrans)),
		m_resScale(1.0f) {
    loadBodies(resId);
}

wyChipmunkPELoader::~wyChipmunkPELoader() {
    wyHashSetEach(m_bodyMetas, releaseHashElm, NULL);
    wyHashSetDestroy(m_bodyMetas);
}

void wyChipmunkPELoader::loadBodies(const char* filePath, bool isFile) {
    size_t outlen = 0;
    char* data = wyUtils::loadRaw(filePath, isFile, &outlen);
    parse(data, outlen);
	wyFree(data);
}

void wyChipmunkPELoader::loadBodies(int resId) {
	size_t outlen = 0;
    char* data = wyUtils::loadRaw(resId, &outlen, &m_resScale);
    parse(data, outlen);
	wyFree(data);
}

cpBody* wyChipmunkPELoader::createBodyByName(wyChipmunk* chipmunk, const char* name) {
    unsigned int hashValue = wyUtils::strHash(name);
    wyCPBodyMeta* elm = (wyCPBodyMeta*)wyHashSetFind(m_bodyMetas, hashValue, (void*)name);
    if(elm)
        return elm->createBody(chipmunk);
    else 
        return NULL;
}

void wyChipmunkPELoader::parse(char* data, int dataLen) {
    m_parseState = wyCalloc(1, sizeof(wyParseState));
    wyParseState* state = (wyParseState*)m_parseState;
	state->tags = (int*)wyMalloc(10 * sizeof(int));
	state->tags[0] = DOCUMENT;
	state->num = 1;
	state->max = 10;
    state->state = State_ready;
    state->bodyMeta = NULL;
    state->fixtureInfo = NULL;
    state->vertexMax = 20;
    state->vertices = new cpVect[state->vertexMax];
    state->vertexCount = 0; 
    
	// declare handler
	xmlSAXHandlerV1 saxHandler = {
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

	// start to parser xml file
	xmlSAXUserParseMemory((xmlSAXHandlerPtr)&saxHandler, this, data, dataLen);

	// clean parser
	xmlCleanupParser();

    if(state->lastKey)
		wyFree((void*)state->lastKey);
    delete[] state->vertices;
	wyFree(state->tags);
	wyFree(state);
}

void wyChipmunkPELoader::createFixtureInfo() {
    wyParseState* state = (wyParseState*)m_parseState;
    state->fixtureInfo = WYNEW wyCPFixtureInfo();
}

void wyChipmunkPELoader::createShape() {
    wyParseState* state = (wyParseState*)m_parseState;
    
    switch(state->fixtureInfo->m_fixture_type) {
        case CP_POLY_SHAPE:
        {
            wyCPShapeInfo* si = (wyCPShapeInfo*)wyMalloc(sizeof(wyCPShapeInfo) + sizeof(cpVect) * state->vertexCount);
            si->area = 0.0;
            si->momentum = 0.0f;
            si->vertexCount = state->vertexCount;
            memcpy(si->vertices, state->vertices, sizeof(cpVect) * state->vertexCount);
            state->fixtureInfo->addShapeInfo(si);

            state->vertexCount = 0;
            break;
        }
        case CP_CIRCLE_SHAPE:
        {
            wyCPShapeInfo* si = (wyCPShapeInfo*)wyMalloc(sizeof(wyCPShapeInfo));
            si->area = 0.0;
            si->momentum = 0.0f;
            si->radius = state->radius;
            //si->offset.x = state->position.x;
            //si->offset.y = state->position.y;
            si->offset = cpvzero;
            state->fixtureInfo->addShapeInfo(si);
            break;
        }       
        default:
            LOGE("unknown fixture_type");
            break;
    }


}

wyPoint wyChipmunkPELoader::getAnchorPercent(const char* name) {
    wyCPBodyMeta* elm = (wyCPBodyMeta*)wyHashSetFind(m_bodyMetas, wyUtils::strHash(name), (void*)name);
    if(elm)
        return elm->m_anchorPoint;
    else 
        return wypZero;
}
