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

#include "wyAssetOutputStream_macosx.h"
#include "wyLog.h"
#include <stdio.h>
#include <errno.h>
#include "wyGlobal.h"
#import "WYResMap.h"

wyAssetOutputStream* wyAssetOutputStream::make(const char* path, bool append) {
	wyAssetOutputStream* aos = WYNEW wyAssetOutputStream_macosx(path, append);
	return (wyAssetOutputStream*)aos->autoRelease();
}

wyAssetOutputStream_macosx::wyAssetOutputStream_macosx(const char* path, bool append) :
		wyAssetOutputStream(path, append),
		m_handle(nil) {
	NSString* nsPath = [NSString stringWithCString:path encoding:NSUTF8StringEncoding];
    NSString* mappedPath = [[WYResMap sharedMap] getLocalFilePath:nsPath checkExistence:NO];

	// is nil?
	if(mappedPath == nil) {
		LOGW("wyAssetOutputStream: can't map android path %s", path);
	} else {
        m_handle = [NSFileHandle fileHandleForWritingAtPath:mappedPath];
        if(m_handle == nil) {
            [[NSFileManager defaultManager] createDirectoryAtPath:[mappedPath stringByDeletingLastPathComponent] 
                                      withIntermediateDirectories:YES 
                                                       attributes:nil 
                                                            error:nil];
            [[NSFileManager defaultManager] createFileAtPath:mappedPath contents:nil attributes:nil];
            m_handle = [NSFileHandle fileHandleForWritingAtPath:mappedPath];
        }

		if (m_append) {
			[m_handle seekToEndOfFile];
		}
		[m_handle retain];

        // get file length
		NSFileManager* fm = [NSFileManager defaultManager];
		NSDictionary* attr = [fm attributesOfItemAtPath:mappedPath error:NULL];
		m_length = [[attr objectForKey:NSFileSize] intValue];
	}
}

wyAssetOutputStream_macosx::~wyAssetOutputStream_macosx() {
	[m_handle closeFile];
	[m_handle release];
	m_handle = nil;
}

void wyAssetOutputStream_macosx::close() {
	[m_handle closeFile];
	[m_handle release];
	m_handle = nil;
}

ssize_t wyAssetOutputStream_macosx::write(const char* data, size_t len) {
	NSData *nData = [NSData dataWithBytes:data length:len];
	[m_handle writeData:nData];
	return [nData length];
}

ssize_t wyAssetOutputStream_macosx::write(const int* data, size_t len) {
	NSData *nData = [NSData dataWithBytes:data length:len];
	[m_handle writeData:nData];
	return [nData length];
}

size_t wyAssetOutputStream_macosx::getPosition() {
	return [m_handle offsetInFile];
}

size_t wyAssetOutputStream_macosx::seek(int offset, int mode) {
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
