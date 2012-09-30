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

#import "wyIAPVerifyDelegate.h"
#include "wyUtils.h"
#include "wyIAPBackend_appstore.h"
#import "SBJSON.h"
#import "NSString+SBJSON.h"
#include "wyIAPListener.h"
#if IOS
    #include "wyUtils_ios.h"
#else
    #include "wyUtils_macosx.h"
#endif

static const char* to_CString(NSString* s) {
#if IOS
	return wyUtils_ios::to_CString(s);
#else
	return wyUtils_macosx::to_CString(s);
#endif
}

@implementation wyIAPVerifyDelegate

@synthesize backend = m_backend;

- (id)initWithBackend:(wyIAPBackend_appstore*)backend productId:(const char*)pid {
	if(self = [super init]) {
		m_backend = backend;
        m_pid = wyUtils::copy(pid);
        m_body = [[NSMutableData data] retain];
        m_success = NO;
	}
	return self;
}

- (void)dealloc {
    wyFree((void*)m_pid);
    [m_body release];
    [super dealloc];
}

- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response {
    NSHTTPURLResponse* r = (NSHTTPURLResponse*)response;
    m_success = [r statusCode] < 300;
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
    if(m_success) {
        [m_body appendData:data];
    }
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
    // get json object from body data
    NSString* s = [[[NSString alloc] initWithBytes:[m_body bytes] 
                                            length:[m_body length] 
                                          encoding:NSUTF8StringEncoding] autorelease];
    NSDictionary* json = [s JSONValue];
    if(json) {
        int status = [[json objectForKey:@"status"] intValue];
        if(status == 0) {
            if(m_backend) {
                m_backend->notifyOnVerifyReceiptOK(m_pid);
            }
        } else {
            if(m_backend) {
                m_backend->notifyOnVerifyReceiptFailed(m_pid, wyIAPListener::E_GENERAL, NULL);
            }
        }
    } else {
        if(m_backend) {
            m_backend->notifyOnVerifyReceiptFailed(m_pid, wyIAPListener::E_GENERAL, NULL);
        }
    }
    
    if(m_backend)
        m_backend->removeVerifyDelegate(self);
}

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
    if(m_backend) {
        if(m_backend) {
            const char* err = to_CString(error.localizedDescription);
            m_backend->notifyOnVerifyReceiptFailed(m_pid, wyIAPListener::E_GENERAL, err);
            wyFree((void*)err);
        }
        
        m_backend->removeVerifyDelegate(self);
    }
}

@end

#endif // #if IOS || MACOSX