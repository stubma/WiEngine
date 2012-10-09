#if IOS || MACOSX

#import "wyReachabilityDelegate.h"

extern NetworkStatus gNetworkStatus;

@implementation wyReachabilityDelegate

- (id)init {
    if(self = [super init]) {
        // Observe the kNetworkReachabilityChangedNotification. When that notification is posted, the
        // method "reachabilityChanged" will be called. 
        [[NSNotificationCenter defaultCenter] addObserver:self 
                                                 selector:@selector(reachabilityChanged:) 
                                                     name:kReachabilityChangedNotification 
                                                   object:nil];
        
        // start listening reachability
        m_reachability = [[wyReachability reachabilityForInternetConnection] retain];
        [m_reachability startNotifier];   
        
        // set init value
        gNetworkStatus = [m_reachability currentReachabilityStatus];
    }
    return self;
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self
                                                    name:kReachabilityChangedNotification
                                                  object:nil];
    [m_reachability stopNotifier];
    [m_reachability release];
    [super dealloc];
}

- (void) reachabilityChanged: (NSNotification* )note {
	wyReachability* curReach = [note object];
    gNetworkStatus = [curReach currentReachabilityStatus];
}

@end

#endif // #if IOS || MACOSX