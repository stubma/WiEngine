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

#include "wyDevice.h"
#include "wyUtils_ios.h"
#include "wyLog.h"
#include "wyMD5.h"
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#import <Foundation/Foundation.h>

// language code
static char sLanguage[3];

// country code
static char sCountry[3];

// uuid
static char sUUID[64];

const char* wyDevice::getLanguage() {
	// get language
	NSString* lan = [[NSLocale currentLocale] objectForKey:NSLocaleLanguageCode];
	if(!lan)
		return "en";
	
	// copy to buffer and return
	const char* cLan = wyUtils_ios::to_CString(lan);
	sLanguage[0] = cLan[0];
	sLanguage[1] = cLan[1];
	sLanguage[2] = 0;
	return sLanguage;
}

const char* wyDevice::getCountry() {
	// get country
	NSString* c = [[NSLocale currentLocale] objectForKey:NSLocaleCountryCode];
	if(!c)
		return "en";

	// copy to buffer and return
	const char* cc = wyUtils_ios::to_CString(c);
	sCountry[0] = cc[0];
	sCountry[1] = cc[1];
	sCountry[2] = 0;
	return sCountry;
}

const char* wyDevice::getDeviceId() {
	/*
	 * get mac address
	 */

	int mib[6];
	size_t len;
	char* buf;
	unsigned char* ptr;
	struct if_msghdr* ifm;
	struct sockaddr_dl* sdl;

	mib[0] = CTL_NET;
	mib[1] = AF_ROUTE;
	mib[2] = 0;
	mib[3] = AF_LINK;
	mib[4] = NET_RT_IFLIST;

	if((mib[5] = if_nametoindex("en0")) == 0) {
		LOGW("Error: if_nametoindex error\n");
		return NULL;
	}

	if(sysctl(mib, 6, NULL, &len, NULL, 0) < 0) {
		LOGW("Error: sysctl, take 1\n");
		return NULL;
	}

	buf = (char*)wyMalloc(len);
	if(buf == NULL) {
		LOGW("Could not allocate memory. error!\n");
		return NULL;
	}

	if(sysctl(mib, 6, buf, &len, NULL, 0) < 0) {
		LOGW("Error: sysctl, take 2");
		return NULL;
	}

	ifm = (struct if_msghdr*)buf;
	sdl = (struct sockaddr_dl*)(ifm + 1);
	ptr = (unsigned char*)LLADDR(sdl);
	char mac[64];
	sprintf(mac, "%02x:%02x:%02x:%02x:%02x:%02x", *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3), *(ptr + 4), *(ptr + 5));
	wyFree(buf);

	// make md5
	const char* md5 = wyMD5::md5(mac);
	sprintf(sUUID, "%s", md5);
	wyFree((void*)md5);

	return sUUID;
}

bool wyDevice::hasExternalStorage() {
	return true;
}

#endif // #if IOS
