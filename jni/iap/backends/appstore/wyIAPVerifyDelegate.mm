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