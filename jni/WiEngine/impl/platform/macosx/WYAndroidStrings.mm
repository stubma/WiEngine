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

#import "WYAndroidStrings.h"

static WYAndroidStrings* sInstance;

@interface WYAndroidStrings (PrivateMethods)

- (void)parse:(NSString*)path;

@end

@implementation WYAndroidStrings

+ (WYAndroidStrings*)sharedInstance {
	if(sInstance == nil) {
		sInstance = [[WYAndroidStrings alloc] init];
	}
	return sInstance;
}

+ (void)destroy {
	if(sInstance != nil) {
		[sInstance release];
		sInstance = nil;
	}
}

- (id)init {
	if(self = [super init]) {
		m_keyMap = [[NSMutableDictionary dictionary] retain];
		m_keyList = [[NSMutableArray array] retain];
		m_strings = [[NSMutableDictionary dictionary] retain];
	}
	return self;
}

- (void)dealloc {
	[m_keyMap release];
	[m_keyList release];
	[m_strings release];
	[super dealloc];
}

- (void)addStrings:(NSString*)file forLanguage:(NSString*)lan {
	NSBundle* bundle = [NSBundle mainBundle];
	NSString* path = [bundle pathForResource:file ofType:@"xml"];
	if(path == nil) {
		path = [bundle pathForResource:file ofType:nil];
	}
	
	// create string dict
	m_tmpDict = [NSMutableDictionary dictionary];
	[m_strings setObject:m_tmpDict forKey:lan];
	
	// parse xml
	[self parse:path];
	
	// add key
	[m_keyMap addEntriesFromDictionary:m_tmpDict];
	
	// sort key flag
	m_keyListDirty = YES;
	
	// nullify
	m_tmpDict = nil;
}

- (NSString*)getString:(NSString*)key {
	NSString* lan = [[NSLocale currentLocale] objectForKey:NSLocaleLanguageCode];
	NSString* cc = [[NSLocale currentLocale] objectForKey:NSLocaleCountryCode];
	NSString* lan_cc = [NSString stringWithFormat:@"%@_%@", lan, cc];
	
	// search lan_cc first, such as zh_CN
	NSMutableDictionary* dict = [m_strings objectForKey:lan_cc];
	NSString* s = [dict objectForKey:key];
	
	// if not found, try lan, such as zh
	if(s == nil) {
		dict = [m_strings objectForKey:lan];
		s = [dict objectForKey:key];
		
		// still not found, try en
		if(s == nil && ![lan isEqualToString:@"en"]) {
			dict = [m_strings objectForKey:@"en"];
			s = [dict objectForKey:key];
		}
	}
	
	return s;
}

- (int)getKeyIndex:(NSString*)key {
	if(m_keyListDirty) {
		m_keyListDirty = NO;
		[m_keyList removeAllObjects];
		[m_keyList addObjectsFromArray:[m_keyMap allKeys]];
		[m_keyList sortUsingSelector:@selector(caseInsensitiveCompare:)];
	}
	
	return (int)[m_keyList indexOfObject:key];
}

- (NSString*)getKey:(int)index {
	if(index < 0 || index >= [m_keyList count])
		return nil;
	else
		return [m_keyList objectAtIndex:index];
}

- (void)parse:(NSString*)path {
    NSURL *xmlURL = [NSURL fileURLWithPath:path];
    NSData *xmlData = [NSData dataWithContentsOfURL:xmlURL];
	NSXMLParser* parser = [[NSXMLParser alloc] initWithData:xmlData];
	[parser setDelegate:self];
	[parser parse];
	[parser release];
}

- (void)parserDidStartDocument:(NSXMLParser *)parser {
	m_stringBuf = [[NSMutableString string] retain];
}

- (void)parserDidEndDocument:(NSXMLParser *)parser {
	[m_stringBuf release];
	m_stringBuf = nil;
}

- (void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qualifiedName attributes:(NSDictionary *)attributeDict {
	if([elementName isEqualToString:@"string"]) {
		m_inStringTag = YES;
		m_stringKey = [[attributeDict objectForKey:@"name"] retain];
		[m_stringBuf setString:@""];
	}
}

- (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName {
	if([elementName isEqualToString:@"string"]) {
		[m_tmpDict setObject:[NSString stringWithString:m_stringBuf] forKey:m_stringKey];
		m_inStringTag = NO;
		[m_stringKey release];
		m_stringKey = nil;
	}
}

- (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string {
	if(m_inStringTag) {
		[m_stringBuf appendString:string];
	}
}

- (void)print:(NSString*)lan {
	NSMutableDictionary* dict = [m_strings objectForKey:lan];
	if(dict != nil)
		NSLog(@"%@", dict);
}

@end

#endif // #if MACOSX