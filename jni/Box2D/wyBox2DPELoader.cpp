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
#include "wyBox2DPELoader.h"
#include <libxml/parser.h>
#include <ctype.h>
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

typedef enum enumFixtureType {
	e_unknown= -1,
	e_circle = 0,
	e_edge = 1,
	e_polygon = 2,
	e_loop = 3,
	e_typeCount = 4,
} enumFixtureType;

typedef struct wyParseState {
	// last key name
	const char* lastKey;

	// tag stack
	int* tags;
	int num;
	int max;

	// state
	enumState state;

	wyB2BodyMeta*	bodyMeta;

	b2Vec2			vertices[b2_maxPolygonVertices];
	int				vertexIndex;
    
    //for circle shape
    float           radius;
    wyPoint         position;

	b2FixtureDef*  	fixtureDef;
	enumFixtureType fixture_type;
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
    }
}

wyB2BodyMeta::wyB2BodyMeta(const char* name) :
    m_arrayFixturedef(wyArrayNew(4)){
    setName(name);
}

wyB2BodyMeta::~wyB2BodyMeta() {
    for(int i = 0; i < m_arrayFixturedef->num; ++i) {
        b2FixtureDef* fixtureDef = (b2FixtureDef*)wyArrayGet(m_arrayFixturedef, i);
        delete fixtureDef->shape;
        delete fixtureDef;
    }
    wyArrayDestroy(m_arrayFixturedef);
}

void wyB2BodyMeta::addFixtureDef(b2FixtureDef* def) {
    wyArrayPush(m_arrayFixturedef, def);
}

b2Body* wyB2BodyMeta::createBody(wyBox2D* box2d) {
    b2Body* body = NULL;
    b2BodyDef bodyDef;

    // create dynamic body by default
    bodyDef.type = b2_dynamicBody;
    body = box2d->getWorld()->CreateBody(&bodyDef);

    for(int i = 0; i < m_arrayFixturedef->num; ++i) {
        b2FixtureDef* fixtureDef = (b2FixtureDef*)wyArrayGet(m_arrayFixturedef, i);
        body->CreateFixture(fixtureDef);
    }

    return body;
}

wyPoint wyBox2DPELoader::parsePoint(const char* v, bool withScale) {
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

void wyBox2DPELoader::startElement(void* ctx, const xmlChar *name, const xmlChar **atts) {
	wyBox2DPELoader* thiz = (wyBox2DPELoader*)ctx;
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
                    wyB2BodyMeta* bodyMeta = WYNEW wyB2BodyMeta(state->lastKey);
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
					break;
                    
				case State_parsingFixture:
                    if(0 == strcmp(state->lastKey, "polygons")) {
                        state->state = State_parsingShapes;
                    }
					break;
                    
				case State_parsingShapes:
                    state->state = State_parsingShape;
                    state->vertexIndex = 0;
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
                        state->fixtureDef->isSensor = true;
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
                        state->fixtureDef->isSensor = false;
                }
                default:
                    break;
			}
			break;
	}
}

void wyBox2DPELoader::endElement(void* ctx, const xmlChar *name) {
	wyBox2DPELoader* thiz = (wyBox2DPELoader*)ctx;
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
					state->state = State_parsingFixtures;
                    break;
                
                case State_parsingCircle:
                    thiz->createFixturesInfo();
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
                    thiz->createFixturesInfo(); 
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

void wyBox2DPELoader::characters(void* ctx, const xmlChar *ch, int len) {
    wyBox2DPELoader* thiz = (wyBox2DPELoader*)ctx;
	wyParseState* state = (wyParseState*)thiz->m_parseState;
    
	// check tag
	switch(topTag(state)) {
		case TAG_KEY:
		{
            char* key = (char*)wyCalloc(len + 1, sizeof(char));
			strncpy(key, (const char*)ch, len);
			wyUtils::trim(key);

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
					if(0 ==strcmp(state->lastKey, "filter_categoryBits"))
						state->fixtureDef->filter.categoryBits = value;
					else if(0 ==strcmp(state->lastKey, "filter_groupIndex"))
					    state->fixtureDef->filter.groupIndex = value;
                    else if(0 ==strcmp(state->lastKey, "filter_maskBits"))
                        state->fixtureDef->filter.maskBits = value;
                    
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
					state->vertices[state->vertexIndex++].Set(p.x / thiz->m_PTMRatio, p.y / thiz->m_PTMRatio);
					break;
				}
                case State_parsingFixture:
				{
					if( 0 == strcmp(state->lastKey, "fixture_type") ) {
						if(0 == strcmp(temp, "POLYGON")) {
                            state->fixture_type = e_polygon;
                        } else if(0 == strcmp(temp, "CIRCLE")) {
                            state->fixture_type = e_circle;
                        } else {
                            LOGE("unknown fixture_type %s", temp);
                        }
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
				case State_parsingMetadata:
				{
					if(0 == strcmp(state->lastKey, "ptm_ratio")) { 
						thiz->m_PTMRatio= value;
                    }
                    break;
				}
                case State_parsingFixture:
                {
					if(0 ==strcmp(state->lastKey, "friction"))
						state->fixtureDef->friction = value;
					else if(0 ==strcmp(state->lastKey, "restitution"))
					    state->fixtureDef->restitution = value;
                    else if(0 ==strcmp(state->lastKey, "density"))
                        state->fixtureDef->density = value;
                    
                    break;
                }
                case State_parsingCircle:
                {
                    if(0 ==strcmp(state->lastKey, "radius"))
						state->radius = (value * thiz->m_resScale) / thiz->m_PTMRatio;
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

void wyBox2DPELoader::warning(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGW("%s", msg);
    va_end(args);
}

void wyBox2DPELoader::error(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGE("%s", msg);
    va_end(args);
}

bool wyBox2DPELoader::releaseHashElm(void* elt, void* data) {
    wyB2BodyMeta* elm = (wyB2BodyMeta*) elt;
    wyObjectRelease(elm);
    return true;
}

int wyBox2DPELoader::hashElemEqual(void* ptr, void* elt) {
    wyB2BodyMeta* elm = (wyB2BodyMeta*)elt;
    return (0 == strcmp((char*)ptr, elm->getName()));
}

void* wyBox2DPELoader::hashElemTrans(void* ptr, void* data) {
    return ptr;
}

wyBox2DPELoader::wyBox2DPELoader() :
        m_bodyMetas(wyHashSetNew(20, hashElemEqual, hashElemTrans)),
		m_resScale(1.0f) {
}

wyBox2DPELoader::wyBox2DPELoader(const char* filePath, bool isFile) :
        m_bodyMetas(wyHashSetNew(20, hashElemEqual, hashElemTrans)),
		m_resScale(1.0f) {
    loadBodies(filePath, isFile);
}

wyBox2DPELoader::wyBox2DPELoader(int resId) :
        m_bodyMetas(wyHashSetNew(20, hashElemEqual, hashElemTrans)),
		m_resScale(1.0f) {
    loadBodies(resId);
}

wyBox2DPELoader::~wyBox2DPELoader() {
    wyHashSetEach(m_bodyMetas, releaseHashElm, NULL);
    wyHashSetDestroy(m_bodyMetas);
}

void wyBox2DPELoader::loadBodies(const char* filePath, bool isFile) {
    size_t outlen = 0;
    char* data = wyUtils::loadRaw(filePath, isFile, &outlen);
    parse(data, outlen);
	wyFree(data);
}

void wyBox2DPELoader::loadBodies(int resId) {
	size_t outlen = 0;
    char* data = wyUtils::loadRaw(resId, &outlen, &m_resScale);
    parse(data, outlen);
	wyFree(data);
}

b2Body* wyBox2DPELoader::createBodyByName(wyBox2D* box2d, const char* name) {
    wyB2BodyMeta* elm = (wyB2BodyMeta*)wyHashSetFind(m_bodyMetas, wyUtils::strHash(name), (void*)name);
    if(elm)
        return elm->createBody(box2d);
    else 
        return NULL;
}

wyPoint wyBox2DPELoader::getAnchorPercent(const char* name) {
    wyB2BodyMeta* elm = (wyB2BodyMeta*)wyHashSetFind(m_bodyMetas, wyUtils::strHash(name), (void*)name);
    if(elm)
        return elm->m_anchorPoint;
    else 
        return wypZero;
}

void wyBox2DPELoader::parse(char* data, int dataLen) {
    m_parseState = wyCalloc(1, sizeof(wyParseState));
    wyParseState* state = (wyParseState*)m_parseState;
	state->tags = (int*)wyMalloc(10 * sizeof(int));
	state->tags[0] = DOCUMENT;
	state->num = 1;
	state->max = 10;
    state->state = State_ready;
    state->fixtureDef = new b2FixtureDef();
    state->bodyMeta = NULL;
    state->vertexIndex = 0;
    
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
    delete state->fixtureDef;
	wyFree(state->tags);
	wyFree(state);
}

void wyBox2DPELoader::createFixturesInfo() {
    wyParseState* state = (wyParseState*)m_parseState;
    switch(state->fixture_type) {
        case e_polygon:
        {
            b2PolygonShape* shape = new b2PolygonShape();
            shape->Set(state->vertices, state->vertexIndex);
            b2FixtureDef* fixtureDef = new b2FixtureDef();
            *fixtureDef = *(state->fixtureDef);
            fixtureDef->shape = shape;

            state->bodyMeta->addFixtureDef(fixtureDef);
            state->vertexIndex = 0;
            break;
        }
        case e_circle:
        {
            b2CircleShape* shape = new b2CircleShape();
            shape->m_radius = state->radius;
            /*
             keep the m_p set to (0, 0), the value read from the plist is always (1, 0),
             this should be PE's bug
            */
            //shape->m_p.Set(state->position.x, state->position.y);
            b2FixtureDef* fixtureDef = new b2FixtureDef();
            *fixtureDef = *(state->fixtureDef);
            fixtureDef->shape = shape;
            
            state->bodyMeta->addFixtureDef(fixtureDef);
            break;
        }
        default:
            LOGE("unknown fixture_type");
            break;
    }
}
