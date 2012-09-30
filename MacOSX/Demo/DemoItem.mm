/*
 * Copyright (c) 2010 WiYun Inc.
 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#import "DemoItem.h"
#import "ManifestXML.h"
#import "wyTypes.h"
#import "wyUtils.h"

static const char* to_CString(NSString* s) {
	size_t len = [s lengthOfBytesUsingEncoding:NSUTF8StringEncoding] + 1;
	char* buf = (char*)calloc(len, sizeof(char));
	[s getCString:buf maxLength:len encoding:NSUTF8StringEncoding];
	return (const char*)buf;
}

static NSString* to_NSString(const char* text) {
	if(text == NULL)
		return nil;
	return [NSString stringWithCString:text encoding:NSUTF8StringEncoding];
}

@implementation DemoItem

- (id)initWithCollectionView:(AMCollectionView *)theCollectionView representedObject:(id)theObject {
	self = [super initWithCollectionView:theCollectionView representedObject:theObject];
	if (self != nil) {
		if ([NSBundle loadNibNamed:@"DemoItem" owner:self]) {
			if([theObject isKindOfClass:[Activity class]]) {
				Activity* act = (Activity*)theObject;
				[self setName:act.name];
                const char* key = to_CString([NSString stringWithFormat:@"R.string.%@", act.descKey]);
				[self setDescription:to_NSString(wyUtils::getString(key))];
                free((void*)key);
			} else {
				[self setName:theObject];
                NSString* s = [NSString stringWithFormat:@"R.string.%@_desc", [[name lowercaseString] stringByReplacingOccurrencesOfString:@" " withString:@"_"]];
                const char* key = to_CString(s);
				[self setDescription:to_NSString(wyUtils::getString(key))];
                free((void*)key);
			}
		} else {
			[self release];
			self = nil;
		}
	}
	return self;
}

- (void)dealloc {
	[view release];
	[super dealloc];
}

- (NSString*)name {
	return name;
}

- (void)setName:(NSString*)n {
	[n retain];
	[name release];
	name = n;
}

- (NSString*)description {
	return description;
}

- (void)setDescription:(NSString*)d {
	[d retain];
	[description release];
	description = d;
	
	[[self collectionView] noteSizeForItemsChanged:[NSArray arrayWithObject:self]];
}

- (NSSize)sizeForViewWithProposedSize:(NSSize)newSize {
	NSMutableParagraphStyle* mps = [[[NSMutableParagraphStyle alloc] init] autorelease];
	[mps setParagraphStyle:[NSParagraphStyle defaultParagraphStyle]];
	[mps setLineBreakMode:NSLineBreakByWordWrapping];
	NSRect bound = [descLabel.stringValue boundingRectWithSize:NSMakeSize(descLabel.frame.size.width, 100000)
													  options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading
												   attributes:[NSDictionary dictionaryWithObjectsAndKeys:descLabel.font, NSFontAttributeName, 
															   mps, NSParagraphStyleAttributeName, nil]];
	NSRect frame = descLabel.frame;
	frame.size.height = bound.size.height;
	descLabel.frame = frame;
	return NSMakeSize(newSize.width, bound.size.height + 45);
}

@end
