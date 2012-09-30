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

#include "wyPrefs.h"
#include "wyTypes.h"
#include "wyUtils_ios.h"
#import <Foundation/Foundation.h>

int wyPrefs::getInt(const char* key, int defValue) {
	int ret = 0;

	NSString* k = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
	if([[NSUserDefaults standardUserDefaults] objectForKey:k] == nil)
		ret = defValue;
	else
		ret = [[NSUserDefaults standardUserDefaults] integerForKey:k];

	return ret;
}

void wyPrefs::setInt(const char* key, int value) {
	NSString* k = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
	[[NSUserDefaults standardUserDefaults] setInteger:value forKey:k];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

bool wyPrefs::getBool(const char* key, bool defValue) {
	bool ret = 0;

	NSString* k = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
	if([[NSUserDefaults standardUserDefaults] objectForKey:k] == nil)
		ret = defValue;
	else
		ret = [[NSUserDefaults standardUserDefaults] boolForKey:k];

	return ret;
}

void wyPrefs::setBool(const char* key, bool value) {
	NSString* k = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
	[[NSUserDefaults standardUserDefaults] setBool:value forKey:k];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

void wyPrefs::setInt64(const char* key, int64_t value) {
	NSString* k = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
	[[NSUserDefaults standardUserDefaults] setObject:[NSNumber numberWithLongLong:value] forKey:k];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

int64_t wyPrefs::getInt64(const char* key, int64_t defValue) {
	int64_t ret = 0;

	NSString* k = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
	if([[NSUserDefaults standardUserDefaults] objectForKey:k] == nil)
		ret = defValue;
	else
		ret = [[[NSUserDefaults standardUserDefaults] objectForKey:k] longLongValue];

	return ret;
}

const char* wyPrefs::getString(const char* key, const char* defValue) {
	const char* ret = 0;

	NSString* k = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
	if([[NSUserDefaults standardUserDefaults] objectForKey:k] == nil)
		ret = wyUtils::copy(defValue);
	else {
		NSString* v = [[NSUserDefaults standardUserDefaults] stringForKey:k];
		return wyUtils_ios::to_CString(v);
	}

	return ret;
}

void wyPrefs::setString(const char* key, const char* value) {
	NSString* k = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
	NSString* v = [NSString stringWithCString:value encoding:NSUTF8StringEncoding];
	[[NSUserDefaults standardUserDefaults] setObject:v forKey:k];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

void wyPrefs::clear() {
	NSBundle* bundle = [NSBundle mainBundle];
	[[NSUserDefaults standardUserDefaults] removePersistentDomainForName:[bundle bundleIdentifier]];
	[[NSUserDefaults standardUserDefaults] synchronize];
}

void wyPrefs::remove(const char* key) {
	NSString* k = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
	[[NSUserDefaults standardUserDefaults] removeObjectForKey:k];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

#endif // #if IOS
