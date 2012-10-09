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
#if IOS || MACOSX

#import "wyNSURLConnectionDelegate.h"
#include "wyEventDispatcher.h"
#include "wyNotifyOnReceiveHttpResponseRunnable.h"
#include "wyNotifyOnHttpFinishLoadingRunnable.h"
#include "wyNotifyOnHttpLoadingFailedRunnable.h"
#include "wyNotifyOnHttpReceiveDataRunnable.h"
#include "wyDirector.h"
#include "wyLog.h"

@implementation wyNSURLConnectionDelegate

- (id)initWithRequest:(wyHttpRequest*)request listener:(wyHttpListener*)listener {
    if(self = [super init]) {
        m_response = NULL;
        m_request = request;
        m_request->retain();
        m_listener = listener;
        return self;
    }
    return nil;
}

- (void)dealloc {
    m_request->release();
    wyObjectRelease(m_response);
    [super dealloc];
}

- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response {
    // create response and set request to it
    m_response = wyHttpResponse_cocoa::make((NSHTTPURLResponse*)response);
    m_response->retain();
    m_response->setRequest(m_request);
    
    // notify listener
	if(m_listener && !m_request->isCancelled()) {
		wyEventDispatcher* d = wyEventDispatcher::getInstanceNoCreate();
		if(d) {
			wyNotifyOnReceiveHttpResponseRunnable* n = wyNotifyOnReceiveHttpResponseRunnable::make(m_response, m_listener);
			d->queueRunnableLocked(n);
		}
	}
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
    // if director is ending, end it
    wyDirector* director = wyDirector::getInstanceNoCreate();
    if(director && director->isEnding()) {
        [connection cancel];
        return;
    }
    
    // if request is cancelled, end it
    if(m_request->isCancelled()) {
        [connection cancel];
        return;
    }
    
    // notify listener
	if(m_listener && !m_request->isCancelled()) {
        wyEventDispatcher* d = wyEventDispatcher::getInstanceNoCreate();
        if(d) {
            m_response->getBodyStream()->reset();
            m_response->getBodyStream()->write((const char*)[data bytes], [data length]);
            wyNotifyOnHttpReceiveDataRunnable* n = wyNotifyOnHttpReceiveDataRunnable::make(m_response, m_listener, m_response->getBody(), m_response->getBodyLength());
            d->queueRunnableLocked(n);
        }
	}
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
    if(m_listener && !m_request->isCancelled()) {
        wyEventDispatcher* d = wyEventDispatcher::getInstanceNoCreate();
        if(d) {
            wyNotifyOnHttpFinishLoadingRunnable* n = wyNotifyOnHttpFinishLoadingRunnable::make(m_response, m_listener);
            d->queueRunnableLocked(n);
        }
	}
}

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
    // create response and set request to it
    if(!m_response) {
        m_response = wyHttpResponse_cocoa::make(nil);
        m_response->retain();
        m_response->setRequest(m_request);
    }
    
    if(m_listener && !m_request->isCancelled()) {
        wyEventDispatcher* d = wyEventDispatcher::getInstanceNoCreate();
        if(d) {
            wyNotifyOnHttpLoadingFailedRunnable* n = wyNotifyOnHttpLoadingFailedRunnable::make(m_response, m_listener);
            d->queueRunnableLocked(n);
        }
	}
}

@end

#endif // #if IOS || MACOSX