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

#import "wyIAPProductDelegate.h"
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

@implementation wyIAPProductDelegate

@synthesize backend = m_backend;

- (id)initWithBackend:(wyIAPBackend_appstore*)backend productId:(NSString*)pid quantity:(int)q {
	if(self = [super init]) {
		m_backend = backend;
		m_productId = [pid retain];
		m_quantity = q;
	}
	return self;
}

- (void)dealloc {
    [m_productId release];
    [super dealloc];
}

- (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:(SKProductsResponse *)response {
	// get products
	NSArray* products = response.products;
	
	// get first product
	if([products count] <= 0) {
		// notify listener about buy product failed
		if(m_backend) {
			const char* cPid = to_CString(m_productId);
			m_backend->notifyOnBuyProductFailed(cPid, wyIAPListener::E_NO_PRODUCT, NULL);
			wyFree((void*)cPid);
		}
	} else {
        if([SKPaymentQueue canMakePayments]) {
            // start pay
            SKProduct* p = [products objectAtIndex:0];
            SKPayment* payment = nil;
            if(m_quantity > 1) {
                SKMutablePayment* mp = [SKMutablePayment paymentWithProduct:p];
                mp.quantity = m_quantity;
                payment = mp;
            } else {
                payment = [SKPayment paymentWithProduct:p];
            }
            [[SKPaymentQueue defaultQueue] addPayment:payment];   
        } else {
            const char* cPid = to_CString(m_productId);
			m_backend->notifyOnBuyProductFailed(cPid, wyIAPListener::E_SERVICE_UNAVAILABLE, NULL);
			wyFree((void*)cPid);
        }
	}
	
	// remove request from cache
    if(m_backend)
        m_backend->removeRequest(request);
		
	// release delegate and request
	[request.delegate release];
	request.delegate = nil;
	[request autorelease];
}
						 
- (void)request:(SKRequest *)request didFailWithError:(NSError *)error {
	// notify listener about buy product failed
	if(m_backend) {
		const char* cPid = to_CString(m_productId);
        const char* err = to_CString(error.localizedDescription);
		m_backend->notifyOnBuyProductFailed(cPid, wyIAPListener::E_GENERAL, err);
		wyFree((void*)cPid);
        if(err)
            wyFree((void*)err);
        
        // remove request from cache
        m_backend->removeRequest((SKProductsRequest*)request);
	}
	
	// release delegate and request
	[request.delegate release];
	request.delegate = nil;
	[request autorelease];
}

@end

#endif // #if IOS || MACOSX