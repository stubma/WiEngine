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

#include "wyHttpRequest_cocoa.h"
#include "wyHttpResponse_cocoa.h"
#import "wyNSURLConnectionDelegate.h"
#include "wyLog.h"

#define BOUNDARY "======###WiNetwork###======"

extern NSString* to_NSString(const char* s);
extern const char* to_CString(NSString* s);

wyHttpRequest_cocoa::wyHttpRequest_cocoa(const char* url, Method method) :
        wyHttpRequest(url, method) {
    
}

wyHttpRequest_cocoa::~wyHttpRequest_cocoa() {
    
}

wyHttpRequest* wyHttpRequest::make(const char* url, Method method) {
	wyHttpRequest_cocoa* r = WYNEW wyHttpRequest_cocoa(url, method);
	return (wyHttpRequest*)r->autoRelease();
}

wyHttpResponse* wyHttpRequest_cocoa::syncExec() {
    // create request
    NSURLRequest* request = createHttpRequest();
    
    // execute it
    NSURLResponse* response = nil;
    NSError* error = nil;
    NSData* body = [NSURLConnection sendSynchronousRequest:request 
                                         returningResponse:&response 
                                                     error:&error];
    
    // create response
    wyHttpResponse_cocoa* r = wyHttpResponse_cocoa::make((NSHTTPURLResponse*)response);
    r->setRequest(this);
    
    // set body data
    if(body) {
        r->getBodyStream()->write((const char*)[body bytes], [body length]);
    }
    
    return r;
}

void wyHttpRequest_cocoa::asyncExec(wyHttpListener* listener) {
    // create request
    NSURLRequest* request = createHttpRequest();
    
    // execute it
    wyNSURLConnectionDelegate* delegate = [[[wyNSURLConnectionDelegate alloc] initWithRequest:this listener:listener] autorelease];
    NSURLConnection* conn = [NSURLConnection connectionWithRequest:request delegate:delegate];
    [conn start];
}

NSURLRequest* wyHttpRequest_cocoa::createHttpRequest() {  
    // request
    NSMutableURLRequest* request = nil;
    
    // set method
    switch(m_method) {
		case wyHttpRequest::GET:
        case wyHttpRequest::DELETE:
        {
            // create request with full url if method is GET or DELETE
            const char* fullUrl = buildQueryString();
            NSURL* url = [NSURL URLWithString:to_NSString(fullUrl)];
            request = [NSMutableURLRequest requestWithURL:url];
            wyFree((void*)fullUrl);
            
            // set method
            if(m_method == wyHttpRequest::GET)
                [request setHTTPMethod:@"GET"];
            else
                [request setHTTPMethod:@"DELETE"];
            break;
        }
        case wyHttpRequest::POST:
        case wyHttpRequest::PUT:
        {
            // create request
            NSURL* url = [NSURL URLWithString:to_NSString(m_url)];
            request = [NSMutableURLRequest requestWithURL:url];
            
            // set method
            if(m_method == wyHttpRequest::POST)
                [request setHTTPMethod:@"POST"];
            else
                [request setHTTPMethod:@"PUT"];
            
            // build post body
			if(hasBlobParam())
				buildMultipart(request);
			else
				buildKeyValuePost(request);
            
            break;
        }
    }
    
    // add headers
    for(vector<Header>::iterator iter = m_headers->begin(); iter != m_headers->end(); iter++) {
        [request setValue:to_NSString(iter->key) 
       forHTTPHeaderField:to_NSString(iter->value)];
    }
    
    return request;
}

void wyHttpRequest_cocoa::buildMultipart(NSMutableURLRequest* request) {
    if(m_parameters->size() > 0) {
        // set content type
        [request setValue:[NSString stringWithFormat:@"multipart/form-data; boundary=%@", @BOUNDARY]
       forHTTPHeaderField:@"Content-Type"];
        
        // build parts
        NSMutableData* body = [NSMutableData data];
		for(vector<Parameter>::iterator iter = m_parameters->begin(); iter != m_parameters->end(); iter++) {
            // begin of one part
            [body appendData:[[NSString stringWithFormat:@"--%@\r\n", @BOUNDARY] dataUsingEncoding:NSUTF8StringEncoding]];
            
            // part content
			if(iter->blob) {
                [body appendData:[[NSString stringWithFormat:@"Content-Disposition: form-data; name=\"%s\";filename=\"%s\"\r\n", iter->key, iter->key] dataUsingEncoding:NSUTF8StringEncoding]];
                [body appendData:[@"Content-Type: application/octet-stream\r\n\r\n" dataUsingEncoding:NSUTF8StringEncoding]];
                [body appendBytes:iter->value length:iter->length];
            } else {
                [body appendData:[[NSString stringWithFormat:@"Content-Disposition: form-data; name=\"%s\"\r\n", iter->key] dataUsingEncoding:NSUTF8StringEncoding]];
                [body appendData:[[NSString stringWithFormat:@"Content-Type: text/plain; charset=utf-8\r\n"] dataUsingEncoding:NSUTF8StringEncoding]];
                [body appendData:[[NSString stringWithFormat:@"Content-Transfer-Encoding: 8bit\r\n\r\n"] dataUsingEncoding:NSUTF8StringEncoding]];
                [body appendBytes:iter->value length:iter->length];
            }
            
            // end of one part
            [body appendData:[@"\r\n" dataUsingEncoding:NSUTF8StringEncoding]];
        }
        
        // end of multipart
        [body appendData:[[NSString stringWithFormat:@"--%@--\r\n", @BOUNDARY] dataUsingEncoding:NSUTF8StringEncoding]];
        
        // set body
        [request setHTTPBody:body];
    }
}

void wyHttpRequest_cocoa::buildKeyValuePost(NSMutableURLRequest* request) {
    if(m_parameters->size() > 0) {
        bool first = true;
        NSMutableData* body = [NSMutableData data];
        for(vector<Parameter>::iterator iter = m_parameters->begin(); iter != m_parameters->end(); iter++) {
            if(first) {
                [body appendData:[[NSString stringWithFormat:@"%s=%s", iter->key, iter->value] dataUsingEncoding:NSUTF8StringEncoding]];
                first = false;
            } else {
                [body appendData:[[NSString stringWithFormat:@"&%s=%s", iter->key, iter->value] dataUsingEncoding:NSUTF8StringEncoding]];   
            }
        }
        
        // set body
        [request setHTTPBody:body];
    }
}

#endif // #if IOS || MACOSX
