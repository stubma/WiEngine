#if IOS || MACOSX

#import <Foundation/Foundation.h>

@interface NSData (Base64)

- (NSData*)base64Encode;
- (NSData*)base64Decode;

@end

#endif // #if IOS || MACOSX