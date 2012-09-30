//
//	AMCollectionViewItem.m
//	AMCollectionViewTest
//
//	Created by Andreas on 20.11.07.
//	Copyright 2007 Andreas Mayer. All rights reserved.
//

#import "AMCollectionViewItem.h"
#import "AMCollectionView.h"


@implementation AMCollectionViewItem

- (id)initWithCollectionView:(AMCollectionView *)theCollectionView
{
	self = [super init];
	if (self != nil) {
		[self setCollectionView:theCollectionView];
	}
	return self;
}

- (id)initWithCollectionView:(AMCollectionView *)theCollectionView representedObject:(id)theObject
{
	self = [self initWithCollectionView:theCollectionView];
	if (self != nil) {
		[self setRepresentedObject:theObject];
	}
	return self;
}


- (void)dealloc
{
	[representedObject release];
	[view release];
	[super dealloc];
}

- (id)copyWithZone:(NSZone *)zone
{
	id result = [[AMCollectionViewItem allocWithZone:zone] init];
	[result setView:[self view]];
	[result setRepresentedObject:[self representedObject]];
	[result setCollectionView:[self collectionView]];
	[result setSelected:[self isSelected]];
	return result;
}

- (void)removeFromCollectionView
{
	[[self view] removeFromSuperview];
	[self setView:nil];
	[self setRepresentedObject:nil];
}


- (AMCollectionView *)collectionView
{
	return collectionView;
}

- (void)setCollectionView:(AMCollectionView *)value
{
	if (collectionView != value) {
		collectionView = value;  // weak reference
	}
}

- (id)representedObject
{
	return [[representedObject retain] autorelease];
}

- (void)setRepresentedObject:(id)value
{
	if (representedObject != value) {
		[representedObject release];
		representedObject = [value retain];
	}
}

- (NSView *)view
{
	return [[view retain] autorelease];
}

- (void)setView:(NSView *)value
{
	if (view != value) {
		[view release];
		view = [value retain];
	}
}

- (BOOL)isSelected
{
	return selected;
}

- (void)setSelected:(BOOL)value
{
	if (selected != value) {
		selected = value;
	}
}

- (BOOL)isFirstResponder
{
	BOOL result = NO;
	id theFirstResponder = [[[self view] window] firstResponder];
	if (!(result = (theFirstResponder == self))) {
		if ([theFirstResponder isKindOfClass:[NSView class]]) {
			while ((theFirstResponder = [theFirstResponder superview])) {
				if (theFirstResponder == self) {
					result = YES;
					break;
				}
			}
		}
	}
	return result;
}


//============================================================================
#pragma mark	NSCoding methods
//============================================================================

- (id)initWithCoder:(NSCoder *)coder
{
	self = [super init];
	[self setView:[coder decodeObjectForKey:@"AMCVIView"]];
	[self setCollectionView:[coder decodeObjectForKey:@"AMCVICollectionView"]];
	[self setRepresentedObject:[coder decodeObjectForKey:@"AMCVIObject"]];
	[self setSelected:[coder decodeBoolForKey:@"AMCVISelected"]];
	return self;
}

- (void)encodeWithCoder:(NSCoder *)coder
{
	[coder encodeObject:view forKey:@"AMCVIView"];
	[coder encodeConditionalObject:collectionView forKey:@"AMCVICollectionView"];
	[coder encodeConditionalObject:representedObject forKey:@"AMCVIObject"];
	[coder encodeBool:selected forKey:@"AMCVISelected"];
}


@end
