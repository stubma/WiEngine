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
#include "wyHttpRequest.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyMemoryOutputStream.h"

wyHttpRequest::wyHttpRequest(const char* url, Method method) :
		m_url(wyUtils::copy(url)),
		m_method(method),
		m_timeout(30000),
		m_cancelled(false) {
	m_parameters = WYNEW vector<Parameter>();
	m_parameters->reserve(10);
	m_headers = WYNEW vector<Header>();
	m_headers->reserve(3);
}

wyHttpRequest::~wyHttpRequest() {
	wyFree((void*)m_url);
	for(vector<Parameter>::iterator iter = m_parameters->begin(); iter != m_parameters->end(); iter++) {
		releaseParameter(*iter);
	}
	WYDELETE(m_parameters);
	for(vector<Header>::iterator iter = m_headers->begin(); iter != m_headers->end(); iter++) {
		releaseHeader(*iter);
	}
	WYDELETE(m_headers);
}

void wyHttpRequest::releaseParameter(Parameter& p) {
	wyFree((void*)p.key);
	wyFree((void*)p.value);
}

void wyHttpRequest::releaseHeader(Header& h) {
	wyFree((void*)h.key);
	wyFree((void*)h.value);
}

void wyHttpRequest::addParameter(const char* key, const char* value) {
	Parameter p = {
			wyUtils::copy(key),
			wyUtils::copy(value),
			strlen(value),
			false
	};
	m_parameters->push_back(p);
}

void wyHttpRequest::addParameter(const char* key, const char* blob, size_t length) {
	Parameter p = {
			wyUtils::copy(key),
			wyUtils::copy(blob, 0, length),
			length,
			true
	};
	m_parameters->push_back(p);
}

bool wyHttpRequest::hasBlobParam() {
	for(vector<Parameter>::iterator iter = m_parameters->begin(); iter != m_parameters->end(); iter++) {
		if(iter->blob) {
			return true;
		}
	}
    
	return false;
}

void wyHttpRequest::addHeader(const char* key, const char* value) {
	Header h = {
			wyUtils::copy(key),
			wyUtils::copy(value)
	};
	m_headers->push_back(h);
}

const char* wyHttpRequest::buildQueryString() {
	// create stream
	wyMemoryOutputStream* mos = wyMemoryOutputStream::make(4096, false);

	// write url
	mos->write(m_url, strlen(m_url));

	// write all parameters
	bool first = true;
	for(vector<Parameter>::iterator iter = m_parameters->begin(); iter != m_parameters->end(); iter++) {
		if(!iter->blob) {
			// write separator
			if(first) {
				first = false;
				mos->write("?", 1);
			} else {
				mos->write("&", 1);
			}

			// write key value
			mos->write(iter->key, strlen(iter->key));
			mos->write("=", 1);
			mos->write(iter->value, iter->length);
		}
	}

	// return
	return mos->getBuffer();
}
