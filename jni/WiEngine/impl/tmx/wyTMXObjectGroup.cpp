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
#include "wyTMXObjectGroup.h"
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

#ifdef __cplusplus
}
#endif

wyTMXObjectGroup::wyTMXObjectGroup() :
		m_name(NULL),
		m_offsetX(0),
		m_offsetY(0),
		m_color(0xffffffff),
		m_opacity(1),
		m_objects(WYNEW vector<wyTMXObject*>()),
		m_properties(wyHashSetNew(2, propertyHashEquals, buildPropertyHash)) {
}

wyTMXObjectGroup::~wyTMXObjectGroup() {
	wyHashSetFilter(m_properties, releasePropertyHash, NULL);
	wyHashSetDestroy(m_properties);

	for(vector<wyTMXObject*>::iterator iter = m_objects->begin(); iter != m_objects->end(); iter++) {
		wyObjectRelease(*iter);
	}
	WYDELETE(m_objects);

	if(m_name != NULL)
		wyFree((void*)m_name);
}

wyTMXObjectGroup* wyTMXObjectGroup::make() {
	wyTMXObjectGroup* g = WYNEW wyTMXObjectGroup();
	return (wyTMXObjectGroup*)g->autoRelease();
}

void wyTMXObjectGroup::addProperty(const char* key, const char* value) {
	char* k = (char*)wyCalloc(strlen(key) + 1, sizeof(char));
	strcpy(k, key);
	char* v = (char*)wyCalloc(strlen(value) + 1, sizeof(char));
	strcpy(v, value);
	wyHashSetInsert(m_properties, wyUtils::strHash(k), k, v);
}

const char* wyTMXObjectGroup::getProperty(const char* name) {
	wyKeyValueHash* hash = (wyKeyValueHash*)wyHashSetFind(m_properties, wyUtils::strHash(name), (void*)name);
	if(hash != NULL)
		return hash->value;
	else
		return NULL;
}

wyTMXObject* wyTMXObjectGroup::newObject() {
	wyTMXObject* to = wyTMXObject::make();
	m_objects->push_back(to);
	to->retain();
    return to;
}

wyTMXObject* wyTMXObjectGroup::getObject(const char* name) {
	for(vector<wyTMXObject*>::iterator iter = m_objects->begin(); iter != m_objects->end(); iter++) {
		const char* on = (*iter)->getProperty("name");
		if(on && !strcmp(name, on))
			return *iter;
	}
	return NULL;
}

wyTMXObject* wyTMXObjectGroup::getObjectAt(int index) {
	if(index < 0 || index >= m_objects->size())
		return NULL;
	else
		return m_objects->at(index);
}

void wyTMXObjectGroup::addObjectProperty(wyTMXObject* object, const char* key, const char* value) {
	object->addProperty(key, value);
}

const char* wyTMXObjectGroup::getObjectProperty(wyTMXObject* object, const char* key) {
	return object->getProperty(key);
}

void wyTMXObjectGroup::setName(const char* name) {
	if(m_name) {
		wyFree((void*)m_name);
		m_name = NULL;
	}
	m_name = wyUtils::copy(name);
}
