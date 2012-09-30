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

#import "wyIAPPaymentObserver.h"
#include "wyIAPBackend_appstore.h"
#include "wyLog.h"
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

@implementation wyIAPPaymentObserver

@synthesize backend = m_backend;

- (id)initWithBackend:(wyIAPBackend_appstore*)backend {
	if(self = [super init]) {
		m_backend = backend;
	}
	return self;
}

- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions {
	for(SKPaymentTransaction* trans in transactions) {
        // get pid c string
        const char* cPid = to_CString(trans.payment.productIdentifier);
        
        // check transaction state
        switch (trans.transactionState) {
            case SKPaymentTransactionStateFailed:
            {
                LOGW("App Store IAP: Payment failed for product: %@", trans.payment.productIdentifier);
                if(m_backend) {
                    const char* err = to_CString(trans.error.localizedDescription);
                    m_backend->notifyOnBuyProductFailed(cPid, wyIAPListener::E_GENERAL, err);
                    wyFree((void*)err);   
                }
                
                // finish it
                [[SKPaymentQueue defaultQueue] finishTransaction:trans];
                
                break;
            }
            case SKPaymentTransactionStatePurchased:
                if(m_backend) {
                    m_backend->notifyOnBuyProductOK(cPid, 
#if IOS
                                                    [trans.transactionReceipt bytes], 
                                                    [trans.transactionReceipt length]
#else
                                                    NULL,
                                                    0
#endif
                                                    );
                }
                
                // finish it
                [[SKPaymentQueue defaultQueue] finishTransaction:trans];
                
                break;
            case SKPaymentTransactionStatePurchasing:
                break;
            case SKPaymentTransactionStateRestored:
                if(m_backend)
                    m_backend->notifyOnBuyProductRestored(cPid, 
#if IOS
                                                          [trans.originalTransaction.transactionReceipt bytes], 
                                                          [trans.originalTransaction.transactionReceipt length]
#else
                                                          NULL,
                                                          0
#endif
                                                          );
                break;
            default:
                LOGW("App Store IAP: Payment transaction unknown state: %d", trans.transactionState);
                break;
        }
        
        // free pid c string
        wyFree((void*)cPid);
    }
}

@end

#endif // #if IOS || MACOSX