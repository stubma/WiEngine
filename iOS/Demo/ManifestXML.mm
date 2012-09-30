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
#import "ManifestXML.h"

#define STATE_APPLICATION 1
#define STATE_ACTIVITY 2

static ManifestXML* sInstance;

@implementation Activity

@synthesize name = m_name;
@synthesize category = m_category;
@synthesize descKey = m_descKey;
@synthesize layerName = m_layerName;

- (void)dealloc {
	[m_name release];
	[m_category release];
	[m_descKey release];
	[m_layerName release];
	[super dealloc];
}

- (NSComparisonResult)compare:(Activity*)act {
	return [m_name caseInsensitiveCompare:act.name];
}

- (NSString*)description {
	return [NSString stringWithFormat:@"%@, %@", m_name, m_descKey];
}

@end

@interface ManifestXML (PrivateMethods)

- (void)setup;
- (void)parse:(NSString*)path;

@end

@implementation ManifestXML

@synthesize categories = m_categories;
@synthesize demos = m_demos;

+ (ManifestXML*)sharedInstance {
	if(sInstance == nil) {
		sInstance = [[ManifestXML alloc] init];
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
	[m_categories release];
	[m_demos release];
	[super dealloc];
}

- (void)setup {
	// init members
	m_categories = [[NSMutableArray array] retain];
	m_demos = [[NSMutableDictionary dictionary] retain];
	
	// get xml path
	NSBundle* bundle = [NSBundle mainBundle];
	NSString* path = [bundle pathForResource:@"AndroidManifest" ofType:@"xml"];
	
	// parse
	[self parse:path];
}

- (void)parse:(NSString*)path {
    NSURL *xmlURL = [NSURL fileURLWithPath:path];
    NSData *xmlData = [NSData dataWithContentsOfURL:xmlURL];
	NSXMLParser* parser = [[NSXMLParser alloc] initWithData:xmlData];
	[parser setDelegate:self];
	[parser parse];
	[parser release];
}

- (void)print {
	NSLog(@"%@", m_demos);
}

- (void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qualifiedName attributes:(NSDictionary *)attributeDict {
	if([elementName isEqualToString:@"application"]) {
		m_state = STATE_APPLICATION;
	} else if([elementName isEqualToString:@"activity"]) {
		if(m_state == STATE_APPLICATION) {
			m_state = STATE_ACTIVITY;
			
			NSString* name = [attributeDict objectForKey:@"android:name"];
			if([name rangeOfString:@".tests."].location == 0) {
				// check custom no_ios attribute
				NSString* noIOS = [attributeDict objectForKey:@"no_ios"];
				if(noIOS != nil && [@"true" isEqualToString:noIOS]) {
					return;
				}
				
				m_activity = [[Activity alloc] init];
				NSString* label = [attributeDict objectForKey:@"android:label"];
				NSArray* parts = [label componentsSeparatedByString:@"/"];
				m_activity.category = [parts objectAtIndex:0];
				m_activity.name = [parts objectAtIndex:1];
				parts = [name componentsSeparatedByString:@"."];
				m_activity.layerName = [parts lastObject];
			}			
		}
	} else if([elementName isEqualToString:@"meta-data"]) {
		switch(m_state) {
			case STATE_ACTIVITY:
				if(m_activity != nil) {
					NSString* descKey = [attributeDict objectForKey:@"android:resource"];
					if(descKey != nil) {
						NSArray* parts = [descKey componentsSeparatedByString:@"/"];
						m_activity.descKey = [parts objectAtIndex:1];	
					}
				}
				break;
		}
	}
}

- (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName {
	if([elementName isEqualToString:@"activity"]) {
		if(m_state == STATE_ACTIVITY) {
			m_state = STATE_APPLICATION;
			
			if(m_activity != nil) {
				// ensure the category is available
				if(![m_categories containsObject:m_activity.category]) 
					[m_categories addObject:m_activity.category];
				
				// append activity to category list
				NSMutableArray* activities = [m_demos objectForKey:m_activity.category];
				if(activities == nil) {
					activities = [NSMutableArray array];
					[m_demos setObject:activities forKey:m_activity.category];
				}
				[activities addObject:m_activity];
				[m_activity release];
				m_activity = nil;		
			}
		}
	}
}

- (void)parserDidEndDocument:(NSXMLParser *)parser {
	[m_categories sortUsingSelector:@selector(caseInsensitiveCompare:)];
	for(NSMutableArray* demos in [m_demos allValues]) {
		[demos sortUsingSelector:@selector(compare:)];
	}
}

@end
