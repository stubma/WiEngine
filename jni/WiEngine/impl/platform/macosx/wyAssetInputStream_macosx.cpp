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
#if MACOSX

#include "wyAssetInputStream_macosx.h"
#include "wyLog.h"
#include <errno.h>
#include "wyGlobal.h"
#import "WYResMap.h"

wyAssetInputStream* wyAssetInputStream::make(int resId) {
	wyAssetInputStream* ais = WYNEW wyAssetInputStream_macosx(resId);
	return (wyAssetInputStream*)ais->autoRelease();
}

wyAssetInputStream* wyAssetInputStream::make(const char* path, bool isFile) {
	wyAssetInputStream* ais = WYNEW wyAssetInputStream_macosx(path, isFile);
	return (wyAssetInputStream*)ais->autoRelease();
}

wyAssetInputStream_macosx::wyAssetInputStream_macosx(int resId) : 
		wyAssetInputStream(resId),
		m_handle(nil),
		m_length(0) {
	NSString* path = [[WYResMap sharedMap] getResFilePath:resId];
	if(path == nil) {
		LOGW("wyAssetInputStream: Failed to map res id: %d", resId);
	} else {
		// open file
		m_handle = [NSFileHandle fileHandleForReadingAtPath:path];
		[m_handle retain];

		// get file length
		NSFileManager* fm = [NSFileManager defaultManager];
		NSDictionary* attr = [fm attributesOfItemAtPath:path error:NULL];
		m_length = [[attr objectForKey:NSFileSize] intValue];
	}
}

wyAssetInputStream_macosx::wyAssetInputStream_macosx(const char* path, bool isFile) :
		wyAssetInputStream(path, isFile),
		m_handle(nil),
		m_length(0) {
	// get mapped path
	NSString* mappedPath = nil;
	NSString* nsPath = [NSString stringWithCString:path encoding:NSUTF8StringEncoding];
	if(isFile) {
		mappedPath = [[WYResMap sharedMap] getLocalFilePath:nsPath];
	} else {
		mappedPath = [[WYResMap sharedMap] getAssetFilePath:nsPath];
	}

	// is nil?
	if(mappedPath == nil) {
		LOGW("wyAssetInputStream: can't map android path %s", path);
	} else {
		// open file
		m_handle = [NSFileHandle fileHandleForReadingAtPath:mappedPath];
		[m_handle retain];

		// get file length
		NSFileManager* fm = [NSFileManager defaultManager];
		NSDictionary* attr = [fm attributesOfItemAtPath:mappedPath error:NULL];
		m_length = [[attr objectForKey:NSFileSize] intValue];
	}
}

wyAssetInputStream_macosx::~wyAssetInputStream_macosx() {
	[m_handle closeFile];
	[m_handle release];
	m_handle = nil;
}

size_t wyAssetInputStream_macosx::getLength() {
	return m_length;
}

size_t wyAssetInputStream_macosx::getPosition() {
	return [m_handle offsetInFile];
}

size_t wyAssetInputStream_macosx::available() {
	return m_length - [m_handle offsetInFile];
}

char* wyAssetInputStream_macosx::getBuffer() {
	size_t len = getLength();
	char* buf = (char*)wyMalloc(len * sizeof(char));

	NSData* data = [m_handle availableData];
	memcpy(buf, [data bytes], [data length]);

	return buf;
}

void wyAssetInputStream_macosx::close() {
	[m_handle closeFile];
	[m_handle release];
	m_handle = nil;
}

ssize_t wyAssetInputStream_macosx::read(char* buffer, size_t length) {
	NSData* data = [m_handle readDataOfLength:length];
	memcpy(buffer, [data bytes], [data length]);
	return [data length];
}

size_t wyAssetInputStream_macosx::seek(int offset, int mode) {
	switch (mode) {
		case SEEK_CUR:
			[m_handle seekToFileOffset:getPosition() + offset];
			break;
		case SEEK_END:
			[m_handle seekToFileOffset:m_length + offset];
			break;
		case SEEK_SET:
			[m_handle seekToFileOffset:offset];
			break;
	}

	return [m_handle offsetInFile];
}

#endif // #if MACOSX
