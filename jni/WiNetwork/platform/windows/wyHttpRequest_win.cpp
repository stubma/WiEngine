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
#if WINDOWS

#include "wyHttpRequest_win.h"
#include "Poco/URI.h"
#include "Poco/Net/Net.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/Net/HttpClientSession.h"
#include "Poco/Net/BlobPartSource.h"
#include "Poco/Net/StringPartSource.h"
#include "Poco/Net/HTTPResponse.h"
#include "wyLog.h"
#include "wyHttpResponse_win.h"
#include "wyEventDispatcher.h"
#include "wyNotifyOnReceiveHttpResponseRunnable.h"
#include "wyNotifyOnHttpFinishLoadingRunnable.h"
#include "wyNotifyOnHttpLoadingFailedRunnable.h"
#include "wyNotifyOnHttpReceiveDataRunnable.h"
#include "wyThread.h"
#include "wyDirector.h"

wyHttpRequest_win::wyHttpRequest_win(const char* url, Method method) :
		wyHttpRequest(url, method),
		m_pocoReq(NULL),
		m_listener(NULL) {
}

wyHttpRequest_win::~wyHttpRequest_win() {
	if(m_pocoReq)
		delete m_pocoReq;
}

wyHttpRequest* wyHttpRequest::make(const char* url, Method method) {
	wyHttpRequest_win* r = WYNEW wyHttpRequest_win(url, method);
	return (wyHttpRequest*)r->autoRelease();
}

wyHttpResponse* wyHttpRequest_win::syncExec() {
	// create http request
	m_pocoReq = createHttpRequest();

	// create client session
	URI uri(m_url);
	HTTPClientSession s(uri.getHost());

	// perform request
	s.sendRequest(*m_pocoReq);

	// create platform-independent response
	HTTPResponse* pocoResp = new HTTPResponse();
	wyHttpResponse_win* resp = wyHttpResponse_win::make(pocoResp);	
	resp->setRequest(this);

	// read all data into response body
	istream& rs = s.receiveResponse(*pocoResp);
	char buf[1024];
	while(!rs.fail() && !rs.eof()) {
		rs.read(buf, 1024);
		streamsize read = rs.gcount();
		if(read > 0)
			resp->getBodyStream()->write(buf, read);
	}

	return resp;
}

void wyHttpRequest_win::asyncExec(wyHttpListener* listener) {
	// save listener
	m_listener = listener;

	// create http request
	m_pocoReq = createHttpRequest();

	// retain self
	retain();

	// start execute
	wyThread::runThread(wyTargetSelector::make(this, SEL(wyHttpRequest_win::doAsyncExec)));
}

bool wyHttpRequest_win::shouldAbort() {
	return isCancelled() || wyDirector::isEnding();
}

void wyHttpRequest_win::doAsyncExec(wyTargetSelector* ts) {
	// create client session
	URI uri(m_url);
	HTTPClientSession s(uri.getHost());

	// perform request
	s.sendRequest(*m_pocoReq);

	// create platform-independent response
	HTTPResponse* pocoResp = new HTTPResponse();
	wyHttpResponse_win* resp = wyHttpResponse_win::make(pocoResp);	
	resp->retain();
	resp->setRequest(this);

	// read all data into response body
	istream& rs = s.receiveResponse(*pocoResp);

	// check cancel flag
	if(shouldAbort())
		goto Clear;

	// notify
    if(m_listener && !shouldAbort()) {
        wyEventDispatcher* d = wyEventDispatcher::getInstanceNoCreate();
        if(d) {
			wyNotifyOnReceiveHttpResponseRunnable* n = wyNotifyOnReceiveHttpResponseRunnable::make(resp, m_listener);
			d->queueRunnableLocked(n);
		}
	}

	// check status code
	HTTPResponse::HTTPStatus statusCode = pocoResp->getStatus();
	if(statusCode >= 400) {
		if(m_listener && !shouldAbort()) {
			wyEventDispatcher* d = wyEventDispatcher::getInstanceNoCreate();
			if(d) {
				wyNotifyOnHttpLoadingFailedRunnable* n = wyNotifyOnHttpLoadingFailedRunnable::make(resp, m_listener);
				d->queueRunnableLocked(n);
			}
		}
	} else {
		// read all response body
		char buf[65535];
		while(!rs.fail() && !rs.eof() && !shouldAbort()) {
			rs.read(buf, 65535);
			streamsize read = rs.gcount();
			if(read > 0) {
				if(m_listener && !shouldAbort()) {
					resp->getBodyStream()->reset();
					resp->getBodyStream()->write(buf, read);

					// notify
					wyEventDispatcher* d = wyEventDispatcher::getInstanceNoCreate();
					if(d) {
						wyNotifyOnHttpReceiveDataRunnable* n = wyNotifyOnHttpReceiveDataRunnable::make(resp, m_listener, resp->getBody(), resp->getBodyLength());
						d->queueRunnableLocked(n);
					}
				} else {
					break;
				}
			}
		}

		// final
		if(m_listener && !shouldAbort()) {
			wyEventDispatcher* d = wyEventDispatcher::getInstanceNoCreate();
			if(d) {
				wyNotifyOnHttpFinishLoadingRunnable* n = wyNotifyOnHttpFinishLoadingRunnable::make(resp, m_listener);
				d->queueRunnableLocked(n);
			}
		}
	}

Clear:

	// clear
	m_listener = NULL;
	resp->release();

	// balance the retain in asyncExec
	autoRelease();
}

HTTPRequest* wyHttpRequest_win::createHttpRequest() {
	// get method
	string* method = NULL;
	switch(m_method) {
		case GET:
			method = (string*)&HTTPRequest::HTTP_GET;
			break;
		case DELETE:
			method = (string*)&HTTPRequest::HTTP_DELETE;
			break;
		case POST:
			method = (string*)&HTTPRequest::HTTP_POST;
			break;
		case PUT:
			method = (string*)&HTTPRequest::HTTP_PUT;
			break;
	}

	// create request
	URI uri(m_url);
	HTTPRequest* req = new HTTPRequest(*method, uri.getPath(), "HTTP/1.1");

	// set headers
	setHeaders(*req);
	
	// set parameters
	switch(m_method) {
		case GET:
		case DELETE:
		{
			HTMLForm form;
			for(vector<Parameter>::iterator iter = m_parameters->begin(); iter != m_parameters->end(); iter++) {
				form.add(iter->key, iter->value);
			}
			form.prepareSubmit(*req);
			break;
		}
		case POST:
		case PUT:
		{
			HTMLForm form;
			for(vector<Parameter>::iterator iter = m_parameters->begin(); iter != m_parameters->end(); iter++) {
				if(iter->blob) {
					BlobPartSource* bps = new BlobPartSource(iter->value, iter->length);
					form.addPart(iter->key, bps);
				} else {
					StringPartSource* sps = new StringPartSource(iter->value);
					form.addPart(iter->key, sps);
				}
			}
			form.prepareSubmit(*req);
			break;
		}
	}
	
	return req;
}

void wyHttpRequest_win::setHeaders(HTTPRequest& req) {
	for(vector<Header>::iterator iter = m_headers->begin(); iter != m_headers->end(); iter++) {
		req.set(iter->key, iter->value);
	}
}

#endif // #if WINDOWS
