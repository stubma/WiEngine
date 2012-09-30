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
#include "wyIAP.h"
#include "wyIAPBackend.h"
#include "wyLog.h"
#if IOS || MACOSX
    #include "wyIAPBackend_appstore.h"
#endif
#if ANDROID
    #include "wyIAPBackend_androidmarket.h"
#endif

// singleton
wyIAP* gIAP = NULL;

wyIAP::wyIAP() :
		m_activeBackend(NULL) {
	// init members
	m_backends = WYNEW vector<wyIAPBackend*>();
	m_backends->reserve(2);
	m_listeners = WYNEW vector<wyIAPListener*>();
	m_listeners->reserve(2);	
            
    // create backend
#if IOS || MACOSX
    registerBackend(wyIAPBackend_appstore::make());
#endif
#if ANDROID
    registerBackend(wyIAPBackend_androidmarket::make());
#endif
}

wyIAP::~wyIAP() {
	for(vector<wyIAPBackend*>::iterator iter = m_backends->begin(); iter != m_backends->end(); iter++) {
		wyObjectRelease(*iter);
	}
	WYDELETE(m_backends);
	WYDELETE(m_listeners);

	// nullify singleton
	gIAP = NULL;
}

wyIAP* wyIAP::getInstance() {
	if(!gIAP) {
		gIAP = WYNEW wyIAP();
	}
	return gIAP;
}

wyIAP* wyIAP::getInstanceNoCreate() {
	return gIAP;
}

void wyIAP::registerBackend(wyIAPBackend* backend) {
	m_backends->push_back(backend);
	backend->retain();
}

bool wyIAP::isBackendAvailable(const char* name) {
	for(vector<wyIAPBackend*>::iterator iter = m_backends->begin(); iter != m_backends->end(); iter++) {
		if((*iter)->getName() && !strcmp((*iter)->getName(), name)) {
			return (*iter)->isAvailable();
		}
	}

	return false;
}

void wyIAP::enableBackend(const char* name) {
	for(vector<wyIAPBackend*>::iterator iter = m_backends->begin(); iter != m_backends->end(); iter++) {
		if((*iter)->getName() && !strcmp((*iter)->getName(), name)) {
			m_activeBackend = *iter;
			break;
		}
	}
}

void wyIAP::addListener(wyIAPListener* l) {
	if(l) {
		m_listeners->push_back(l);
	}
}

void wyIAP::removeListener(wyIAPListener* l) {
	if(l) {
		for(vector<wyIAPListener*>::iterator iter = m_listeners->begin(); iter != m_listeners->end(); iter++) {
			if(l == *iter) {
				m_listeners->erase(iter);
				break;
			}
		}
	}
}

void wyIAP::buy(const char* productId, int quantity) {
	if(m_activeBackend) 
		m_activeBackend->buy(productId, quantity);
}

void wyIAP::restoreTransactions() {
    if(m_activeBackend)
        m_activeBackend->restoreTransactions();
}

void wyIAP::verifyTransaction(const char* pid, const void* receipt, size_t length, bool sandbox) {
    if(m_activeBackend)
        m_activeBackend->verifyTransaction(pid, receipt, length, sandbox);
}

void wyIAP::configBackend(const char* key, const char* value) {
	if(m_activeBackend)
		m_activeBackend->config(key, value);
}
