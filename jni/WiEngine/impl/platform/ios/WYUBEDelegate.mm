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
#if IOS

#import "WYUBEDelegate.h"

/**
 * The URL to POST to and post data
 */
#define ANALYTICS_URL "http://d.wiyun.com/wiengine/r"

// parameters
#define AP_DEVICE_ID "u"
#define AP_OS "o"
#define AP_OS_VERSION "v"
#define AP_BRAND "b"
#define AP_MODEL "m"
#define AP_DIMENSION "d"
#define AP_LANGUAGE "l"
#define AP_PACKAGE "pkg"
#define AP_WIENGINE_VERSION "ev"

static bool sSent = false;

@implementation WYUBEDelegate

- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response {
	NSHTTPURLResponse* r = (NSHTTPURLResponse*)response;
	if([r statusCode] < 300)
		sSent = true;
}

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
	[connection release];
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
	[connection release];
}

@end

void analyst() {
	// if sent, return
	if(sSent)
		return;
	
	// don't send ube if WiEngineDemos
	NSBundle* bundle = [NSBundle mainBundle];
	if([@"com.wiyun.WiEngine" isEqualToString:[bundle bundleIdentifier]]) {
		return;
	}
	
	UIDevice* device = [UIDevice currentDevice];
	UIScreen* screen = [UIScreen mainScreen];
	float scale = wyDevice::apiLevel >= 400 ? screen.scale : 1.0f;
	NSString* url = [NSString stringWithFormat:@"%@?%@=%@&%@=%@&%@=%@&%@=%@&%@=%@&%@=%@&%@=%@&%@=%@&%@=%@",
					 @ANALYTICS_URL,
					 @AP_DEVICE_ID, device.uniqueIdentifier,
					 @AP_OS, @"iOS",
					 @AP_OS_VERSION, device.systemVersion,
					 @AP_BRAND, @"Apple",
					 @AP_MODEL, device.model,
					 @AP_DIMENSION, [NSString stringWithFormat:@"%dx%dx%d", (int)(screen.bounds.size.width * scale), (int)(screen.bounds.size.height * scale), (int)(160 * scale)],
					 @AP_LANGUAGE, [[NSLocale currentLocale] objectForKey:NSLocaleLanguageCode],
					 @AP_PACKAGE, [bundle bundleIdentifier],
					 @AP_WIENGINE_VERSION, @WIENGINE_VERSION];
	NSURLRequest* req = [NSURLRequest requestWithURL:[NSURL URLWithString:[url stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]]];
	NSURLConnection* conn = [[NSURLConnection alloc] initWithRequest:req delegate:[[[WYUBEDelegate alloc] init] autorelease]];
	[conn start];
}

#endif // #if IOS