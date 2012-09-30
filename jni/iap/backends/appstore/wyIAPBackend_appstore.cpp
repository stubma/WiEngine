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

#include "wyIAPBackend_appstore.h"
#include "wyIAP.h"
#if IOS
    #include "wyUtils_ios.h"
#else
    #include "wyUtils_macosx.h"
#endif
#import "wyIAPProductDelegate.h"
#import "NSData-Base64.h"

static NSString* to_NSString(const char* s) {
#if IOS
	return wyUtils_ios::to_NSString(s);
#else
	return wyUtils_macosx::to_NSString(s);
#endif
}

wyIAPBackend_appstore::wyIAPBackend_appstore() {
	// set name
	setName(IAP_BACKEND_APP_STORE);
	
	// init members
	m_requests = [NSMutableArray array];
	[m_requests retain];
    m_verifyDelegates = [NSMutableArray array];
    [m_verifyDelegates retain];
	
	// add payment observer
	m_observer = [[wyIAPPaymentObserver alloc] initWithBackend:this];
	[[SKPaymentQueue defaultQueue] addTransactionObserver:m_observer];
}

wyIAPBackend_appstore::~wyIAPBackend_appstore() {
	// release product request
    m_observer.backend = nil;
	for(SKProductsRequest* req in m_requests) {
		((wyIAPProductDelegate*)req.delegate).backend = nil;
        [req cancel];
	}
	[m_requests release];
    
    // reset verify delegate
    for(wyIAPVerifyDelegate* d in m_verifyDelegates) {
        d.backend = nil;
    }
    [m_verifyDelegates release];
	
	// remove observer
	[[SKPaymentQueue defaultQueue] removeTransactionObserver:m_observer];
	[m_observer release];
}

wyIAPBackend_appstore* wyIAPBackend_appstore::make() {
	wyIAPBackend_appstore* b = WYNEW wyIAPBackend_appstore();
	return (wyIAPBackend_appstore*)b->autoRelease();
}

bool wyIAPBackend_appstore::isAvailable() {
	return [SKPaymentQueue canMakePayments];
}

void wyIAPBackend_appstore::buy(const char* productId, int quantity) {
    if([SKPaymentQueue canMakePayments]) {
     	// build product request and start
        NSString* pid = to_NSString(productId);
        SKProductsRequest* req = [[SKProductsRequest alloc] initWithProductIdentifiers:[NSSet setWithObject:pid]];
        req.delegate = [[wyIAPProductDelegate alloc] initWithBackend:this 
                                                           productId:pid 
                                                            quantity:quantity];
        [m_requests addObject:req];
        [req start];   
    } else {
        notifyOnBuyProductFailed(productId, wyIAPListener::E_USER_NOT_AUTHORIZED, NULL);
    }
}

void wyIAPBackend_appstore::restoreTransactions() {
    [[SKPaymentQueue defaultQueue] restoreCompletedTransactions];
}

void wyIAPBackend_appstore::verifyTransaction(const char* pid, const void* receipt, size_t length, bool sandbox) {
    // create request
    NSString* urlString = sandbox ? @"https://sandbox.itunes.apple.com/verifyReceipt" : @"https://buy.itunes.apple.com/verifyReceipt";
    NSURL* url = [NSURL URLWithString:urlString];
    NSMutableURLRequest* req = [NSMutableURLRequest requestWithURL:url];
    
    // set method
    [req setHTTPMethod:@"POST"];
    
    // set body
    NSData* body = [NSData dataWithBytes:receipt length:length];
    body = [body base64Encode];
    NSString* bodyStr = [[[NSString alloc] initWithBytes:[body bytes] 
                                                  length:[body length] 
                                                encoding:NSUTF8StringEncoding] autorelease];
    bodyStr = [NSString stringWithFormat:@"{ \"receipt-data\" : \"%@\" }", bodyStr];
    [req setHTTPBody:[bodyStr dataUsingEncoding:NSUTF8StringEncoding]];
    
    // create connection
    wyIAPVerifyDelegate* d = [[[wyIAPVerifyDelegate alloc] initWithBackend:this
                                                                 productId:pid] autorelease];
    [m_verifyDelegates addObject:d];
    NSURLConnection* conn = [NSURLConnection connectionWithRequest:req delegate:d];
    [conn start];
}

void wyIAPBackend_appstore::config(const char* key, const char* value) {
	// do nothing because it doesn't need any parameter
}

void wyIAPBackend_appstore::removeRequest(SKProductsRequest* req) {
	[m_requests removeObject:req];
}

void wyIAPBackend_appstore::removeVerifyDelegate(wyIAPVerifyDelegate* d) {
    [m_verifyDelegates removeObject:d];
}

#endif // #if IOS || MACOSX
