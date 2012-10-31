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
#include "wyMesh.h"

wyMesh::wyMesh() :
		m_mode(TRIANGLES),
		m_lodLevels(NULL),
		m_lineWidth(1),
		m_pointSize(1),
		m_tag(-1),
		m_skip(false) {
	// init member
	memset(&m_data, 0, sizeof(wyUserData));

	// create buffer array
	m_attrConnections = WYNEW vector<AttributeConnection*>();
	m_attrConnections->reserve(5);
}

wyMesh::~wyMesh() {
	for(vector<AttributeConnection*>::iterator iter = m_attrConnections->begin(); iter != m_attrConnections->end(); iter++) {
		releaseAttributeConnection(*iter);
	}
	WYDELETE(m_attrConnections);

	if(m_lodLevels) {
		for(vector<wyBuffer*>::iterator iter = m_lodLevels->begin(); iter != m_lodLevels->end(); iter++) {
			wyObjectRelease(*iter);
		}
		WYDELETE(m_lodLevels);
	}
}

void wyMesh::connectAttribute(const char* name, wyBuffer* buf, int offset, int components) {
	AttributeConnection* conn = (AttributeConnection*)wyMalloc(sizeof(AttributeConnection));
	conn->name = wyUtils::copy(name);
	conn->value.ib.buf = buf;
	wyObjectRetain(buf);
	conn->value.ib.offset = offset;
	conn->value.ib.components = components;
	conn->type = wyShaderVariable::INTERLEAVED_BUFFER;

	m_attrConnections->push_back(conn);
}

void wyMesh::connectAttribute(const char* name, float v) {
	AttributeConnection* conn = (AttributeConnection*)wyMalloc(sizeof(AttributeConnection));
	conn->name = wyUtils::copy(name);
	conn->value.f = v;
	conn->type = wyShaderVariable::FLOAT;

	m_attrConnections->push_back(conn);
}

void wyMesh::connectAttribute(const char* name, kmVec2& v) {
	AttributeConnection* conn = (AttributeConnection*)wyMalloc(sizeof(AttributeConnection));
	conn->name = wyUtils::copy(name);
	kmVec2Fill(&conn->value.v2, v.x, v.y);
	conn->type = wyShaderVariable::VEC2;

	m_attrConnections->push_back(conn);
}

void wyMesh::connectAttribute(const char* name, kmVec3& v) {
	AttributeConnection* conn = (AttributeConnection*)wyMalloc(sizeof(AttributeConnection));
	conn->name = wyUtils::copy(name);
	kmVec3Fill(&conn->value.v3, v.x, v.y, v.z);
	conn->type = wyShaderVariable::VEC3;

	m_attrConnections->push_back(conn);
}

void wyMesh::connectAttribute(const char* name, kmVec4& v) {
	AttributeConnection* conn = (AttributeConnection*)wyMalloc(sizeof(AttributeConnection));
	conn->name = wyUtils::copy(name);
	kmVec4Fill(&conn->value.v4, v.x, v.y, v.z, v.w);
	conn->type = wyShaderVariable::VEC4;

	m_attrConnections->push_back(conn);
}

void wyMesh::releaseAttributeConnection(AttributeConnection* conn) {
	// free name
	wyFree((void*)conn->name);

	// free buffer if necessary
	switch(conn->type) {
		case wyShaderVariable::FLOAT_ARRAY:
		case wyShaderVariable::VEC2_ARRAY:
		case wyShaderVariable::VEC3_ARRAY:
		case wyShaderVariable::VEC4_ARRAY:
		case wyShaderVariable::MAT3_ARRAY:
		case wyShaderVariable::MAT4_ARRAY:
			wyFree(conn->value.a.p);
			break;
		case wyShaderVariable::INTERLEAVED_BUFFER:
			wyObjectRelease(conn->value.ib.buf);
			break;
	}

	// free self
	wyFree(conn);
}

void wyMesh::setLodLevels(wyBuffer** buffers, int count) {
	if(count <= 0)
		return;

	// lazy creation
	if(!m_lodLevels) {
		m_lodLevels = WYNEW vector<wyBuffer*>();
		m_lodLevels->reserve(count);
	} else {
		for(vector<wyBuffer*>::iterator iter = m_lodLevels->begin(); iter != m_lodLevels->end(); iter++) {
			wyObjectRelease(*iter);
		}
		m_lodLevels->clear();
	}

	// push buffers
	for(int i = 0; i < count; i++) {
		m_lodLevels->push_back(buffers[i]);
		buffers[i]->retain();
	}
}

wyBuffer* wyMesh::getLodLevelBuffer(int lodLevel) {
	if(!m_lodLevels)
		return NULL;

	if(lodLevel < 0 || lodLevel >= m_lodLevels->size())
		return NULL;

	return m_lodLevels->at(lodLevel);
}

wyBuffer* wyMesh::getFirstConnectedBuffer() {
	for(vector<AttributeConnection*>::iterator iter = m_attrConnections->begin(); iter != m_attrConnections->end(); iter++) {
		if((*iter)->type == wyShaderVariable::INTERLEAVED_BUFFER) {
			return (*iter)->value.ib.buf;
		}
	}

	return NULL;
}

void wyMesh::setUserData(wyUserData& ud) {
	memcpy(&m_data, &ud, sizeof(wyUserData));
}
