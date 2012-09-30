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

#import "WYResMap.h"
#import "WYAndroidStrings.h"

// shared instance
static WYResMap* sInstance = nil;

#pragma mark private methods declaration

@interface WYResMap (PrivateMethods)

/**
 * 初始化WYResMap
 */
- (void)setup;

@end

#pragma mark -
#pragma mark implementation

@implementation WYResMap

+ (WYResMap*)sharedMap {
	if(sInstance == nil) {
		sInstance = [[WYResMap alloc] init];
		[sInstance setup];
	}
	return sInstance;
}

+ (void)destroy {
	if(sInstance != nil) {
		[sInstance release];
		sInstance = nil;
	}
}

- (void)dealloc {
	[m_fileList release];
	[m_resMap release];
	[super dealloc];
}

- (void)setup {
	// get file manager and root
	NSFileManager* fm = [NSFileManager defaultManager];
	NSString* appRoot = [[NSBundle mainBundle] resourcePath];
	
	// list items deeply
	BOOL isDir = NO;
	NSArray* allItems;
	if([fm fileExistsAtPath:appRoot isDirectory:&isDir] && isDir)
		allItems = [fm subpathsAtPath:appRoot];
	
	// make sure the file list is sorted by alphabetic order
	NSMutableArray* tmpList = [[NSMutableArray arrayWithArray:allItems] retain];
    
    // put a placeholder in index 0, because zero resource id is invalid
    [tmpList insertObject:@"__placeholder__" atIndex:0];
    
    // remove localization prefix and put to real list
    m_fileList = [[NSMutableArray array] retain];
    for(NSString* file in tmpList) {
        // remove locale prefix if has
        NSArray* components = [file pathComponents];
        NSString* component = [components objectAtIndex:0];
        if([component hasSuffix:@".lproj"]) {
            NSRange range = [file rangeOfString:@"/"];
            if(range.location != NSNotFound) {
                file = [file substringFromIndex:range.location + 1];
            }
        }
        
        // add file entry
        [m_fileList addObject:file];
    }
	
	// put file to map
	m_resMap = [[NSMutableDictionary dictionaryWithCapacity:[m_fileList count]] retain];
	int resId = 0;
	for(NSString* file in [NSArray arrayWithArray:m_fileList]) {
		// remove extension and lower cased
		NSString* normalize = [file stringByDeletingPathExtension];
		
		// avoid name conflict, will remove conflicted one
		if([m_resMap objectForKey:normalize] != nil) {
			[m_fileList removeObjectAtIndex:resId];
			NSLog(@"Warning: same name (%@) resource in same folder", file);
		} else {
			[m_resMap setObject:[NSNumber numberWithInt:resId] forKey:normalize];
			resId++;	
		}
	}
}

- (NSString*)getResFilePath:(int)resId {
    NSString* relativePath = [self getResRelativeFilePath:resId];
    
    // get file manager
	NSFileManager* fm = [NSFileManager defaultManager];
	NSBundle* bundle = [NSBundle mainBundle];
	NSString* ext = [relativePath pathExtension];
	NSString* filename = [relativePath lastPathComponent];
	NSString* filenameWithoutExt = [filename stringByDeletingPathExtension];
    
    // then check ~/app/assets/xxx
	NSString* dir = [relativePath stringByDeletingLastPathComponent];
	NSString* path = [bundle pathForResource:filenameWithoutExt ofType:ext inDirectory:dir];
	if([fm fileExistsAtPath:path]) {
		return path;
	}
	
	// all not found
	return nil;
}

- (NSString*)getResRelativeFilePath:(int)resId {
    // we add 0x7f000000 to resId so that it keeps same start value with android, need subtract here
	resId -= 0x7f000000;
	
	// actually res id is a index of file list, so simple
	if(resId < 0 || resId >= [m_fileList count])
		return nil;
	else
		return [m_fileList objectAtIndex:resId];
}

- (NSString*)getAssetFilePath:(NSString*)asset {
    // get file manager
	NSFileManager* fm = [NSFileManager defaultManager];
	NSBundle* bundle = [NSBundle mainBundle];
	NSString* ext = [asset pathExtension];
	NSString* filename = [asset lastPathComponent];
	NSString* filenameWithoutExt = [filename stringByDeletingPathExtension];
	
	// check ~/app/file first
	NSString* path = [bundle pathForResource:filenameWithoutExt ofType:ext inDirectory:nil];
	if([fm fileExistsAtPath:path]) {
		return path;
	}
	
	// then check ~/app/assets/xxx
	NSString* dir = [asset stringByDeletingLastPathComponent];
	dir = [@"assets" stringByAppendingPathComponent:dir];
	path = [bundle pathForResource:filenameWithoutExt ofType:ext inDirectory:dir];
	if([fm fileExistsAtPath:path]) {
		return path;
	}
	
	// all not found
	return nil;
}

- (NSString*)getAssetRelativeFilePath:(NSString*)asset {
	// get file manager
	NSFileManager* fm = [NSFileManager defaultManager];
	NSBundle* bundle = [NSBundle mainBundle];
	NSString* ext = [asset pathExtension];
	NSString* filename = [asset lastPathComponent];
	NSString* filenameWithoutExt = [filename stringByDeletingPathExtension];
	
	// check ~/app/file first
	NSString* path = [bundle pathForResource:filenameWithoutExt ofType:ext inDirectory:nil];
	if([fm fileExistsAtPath:path]) {
		return filename;
	}
	
	// then check ~/app/assets/xxx
	NSString* dir = [asset stringByDeletingLastPathComponent];
	dir = [@"assets" stringByAppendingPathComponent:dir];
	path = [bundle pathForResource:filenameWithoutExt ofType:ext inDirectory:dir];
	if([fm fileExistsAtPath:path]) {
		return [dir stringByAppendingPathComponent:filename];
	}
	
	// all not found
	return nil;
}

- (NSString*)getLocalFilePath:(NSString*)path {
    return [self getLocalFilePath:path checkExistence:YES];
}

- (NSString*)getLocalFilePath:(NSString *)path checkExistence:(BOOL)flag {
    // get file manager
	NSFileManager* fm = [NSFileManager defaultManager];
	
	// verify path in documents
	NSString* sandboxPath = [@"~/Documents" stringByAppendingPathComponent:path];
	sandboxPath = [sandboxPath stringByExpandingTildeInPath];
    if(flag) {
     	if([fm fileExistsAtPath:sandboxPath]) 
            return sandboxPath;
        else
            return nil;
    } else {
        return sandboxPath;
    }
}

- (int)getResId:(NSString*)resIdString {
	if(resIdString == nil)
		return 0;
	
	// split resource string
	NSArray* parts = [resIdString componentsSeparatedByString:@"."];
	
	// must be 3 part
	if([parts count] != 3) {
		NSLog(@"Invalid res id string: %@", resIdString);
		return 0;
	}
	
	// special case for string res id
	if([[parts objectAtIndex:1] isEqualToString:@"string"]) {
		return [[WYAndroidStrings sharedInstance] getKeyIndex:[parts objectAtIndex:2]];
	} 
	
	// get dir from second resource id part
	NSString* dir = [parts objectAtIndex:1];
    
    // first see if file of @2x version exist, but only do that if retina screen
    NSString* file = [parts objectAtIndex:2];;
    NSString* key = nil;
    NSNumber* resId = nil;
    if(wyDevice::apiLevel >= 400 && [UIScreen mainScreen].scale == 2) {
        NSString* hdFile = [NSString stringWithFormat:@"%@@2x", file];
        key = [NSString stringWithFormat:@"%@/%@", dir, hdFile];
        resId = [m_resMap objectForKey:key];
    }

    // if resource id is not nil, means 2x is found
	if(resId != nil) {
		// we add 0x7f000000 to resId so that it keeps same start value with android
		return [resId intValue] + 0x7f000000;
	}
    
    // then check non-hd version
	key = [NSString stringWithFormat:@"%@/%@", dir, file];
	resId = [m_resMap objectForKey:key];
	if(resId != nil) {
		// we add 0x7f000000 to resId so that it keeps same start value with android
		return [resId intValue] + 0x7f000000;
	}
    
    // if non-hd version is not found for normal screen, try retina version
    NSString* hdFile = [NSString stringWithFormat:@"%@@2x", file];
    key = [NSString stringWithFormat:@"%@/%@", dir, hdFile];
    resId = [m_resMap objectForKey:key];
    
    // if found, use retina image for normal screen
    if(resId != nil) {
        // we add 0x7f000000 to resId so that it keeps same start value with android
		return [resId intValue] + 0x7f000000;
    }
	
	// if not found
	return 0;
}

@end

#endif // #if IOS