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