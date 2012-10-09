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

#import "WYUIEvent.h"

static NSMutableArray* sEventPool;
static NSMutableArray* sTouchPool;

@interface WYUIEvent (PrivateMethods) 

+ (WYUITouch*)popTouch:(UITouch*)touch;
+ (WYUITouch*)popTouchCopy:(WYUITouch*)touch;
+ (void)poolTouch:(WYUITouch*)touch;
- (void)recycle;

@end

@implementation WYUIEvent

@synthesize timestamp = m_timestamp;

+ (void)releasePools {
	[sEventPool release];
	sEventPool = nil;
	[sTouchPool release];
	sTouchPool = nil;
}

+ (WYUIEvent*)popEvent:(UIEvent*)event {
	if(sEventPool == nil) {
		sEventPool = [[NSMutableArray array] retain];
	}
	
	WYUIEvent* e = nil;
	if([sEventPool count] == 0) {
		e = [[WYUIEvent alloc] init];
	} else {
		e = [sEventPool lastObject];
		[e retain];
		[sEventPool removeLastObject];
	}
	
	[e setUIEvent:event];
	return [e autorelease];
}

+ (WYUIEvent*)popCopy:(WYUIEvent*)event {
	if(sEventPool == nil) {
		sEventPool = [[NSMutableArray array] retain];
	}
	
	WYUIEvent* e = nil;
	if([sEventPool count] == 0) {
		e = [[WYUIEvent alloc] init];
	} else {
		e = [sEventPool lastObject];
		[e retain];
		[sEventPool removeLastObject];
	}
	
	[e copyEvent:event];
	return [e autorelease];
}

+ (void)poolEvent:(WYUIEvent*)event {
	if(sEventPool != nil && event != nil) {
		[event recycle];
		[sEventPool addObject:event];
	}
}

+ (WYUITouch*)popTouch:(UITouch*)touch {
	if(sTouchPool == nil) {
		sTouchPool = [[NSMutableArray array] retain];
	}
	
	WYUITouch* t = nil;
	if([sTouchPool count] == 0) {
		t = [[WYUITouch alloc] init];
	} else {
		t = [sTouchPool lastObject];
		[t retain];
		[sTouchPool removeLastObject];
	}
	
	[t setUITouch:touch];
	return [t autorelease];
}

+ (WYUITouch*)popTouchCopy:(WYUITouch*)touch {
	if(sTouchPool == nil) {
		sTouchPool = [[NSMutableArray array] retain];
	}
	
	WYUITouch* t = nil;
	if([sTouchPool count] == 0) {
		t = [[WYUITouch alloc] init];
	} else {
		t = [sTouchPool lastObject];
		[t retain];
		[sTouchPool removeLastObject];
	}
	
	[t copyTouch:touch];
	return [t autorelease];
}

+ (void)poolTouch:(WYUITouch*)touch {
	if(sTouchPool != nil && touch != nil) {
		[sTouchPool addObject:touch];
	}
}

- (id)init {
	if(self = [super init]) {
		m_touches = [[NSMutableArray array] retain];
	}
	return self;
}

- (void)recycle {
	for(WYUITouch* touch in m_touches) {
		[WYUIEvent poolTouch:touch];
	}
	[m_touches removeAllObjects];
}

- (void)setUIEvent:(UIEvent*)event {
	m_timestamp = event.timestamp;
	NSArray* touches = [[event allTouches] allObjects];
	[m_touches removeAllObjects];
	for(UITouch* touch in touches) {
		WYUITouch* wyTouch = [WYUIEvent popTouch:touch];
		[m_touches addObject:wyTouch];
	}
}

- (void)copyEvent:(WYUIEvent*)event {
	m_timestamp = event.timestamp;
	NSArray* touches = [event allTouches];
	[m_touches removeAllObjects];
	for(WYUITouch* touch in touches) {
		WYUITouch* wyTouch = [WYUIEvent popTouchCopy:touch];
		[m_touches addObject:wyTouch];
	}
}

- (void)dealloc {
	[m_touches release];
	[super dealloc];
}

- (NSArray*)allTouches {
	return m_touches;
}

- (int)touchCount {
	return [m_touches count];
}

- (CGPoint)firstTouchLocation {
	if([m_touches count] == 0)
		return CGPointZero;
	else {
		WYUITouch* touch = [m_touches objectAtIndex:0];
		return touch.location;
	}
}

- (int)beganTouchCount {
	int beganTouches = 0;
	for(WYUITouch* touch in m_touches) {
		if(touch.phase == UITouchPhaseBegan)
			beganTouches++;
	}
	return beganTouches;
}

- (int)endedTouchCount {
	int touches = 0;
	for(WYUITouch* touch in m_touches) {
		if(touch.phase == UITouchPhaseEnded || touch.phase == UITouchPhaseCancelled)
			touches++;
	}
	return touches;
}

- (void)removeTouch:(WYUITouch*)touch {
	[m_touches removeObject:touch];
}

- (void)addTouch:(WYUITouch*)touch {
	[m_touches addObject:touch];
}

- (BOOL)removeOneTouchInPhase:(UITouchPhase)phase {
	for(WYUITouch* touch in m_touches) {
		if(touch.phase == phase) {
			[self removeTouch:touch];
			return YES;
		}
	}
	
	return NO;
}

- (BOOL)removeOneTouchNotInPhase:(UITouchPhase)phase {
	for(WYUITouch* touch in m_touches) {
		if(touch.phase != phase) {
			[self removeTouch:touch];
			return YES;
		}
	}
	
	return NO;
}

- (int)removeAllTouchInPhase:(UITouchPhase)phase {
	int ret = 0;
	for(WYUITouch* touch in m_touches) {
		if(touch.phase == phase) {
			[self removeTouch:touch];
			ret++;
		}
	}
	
	return ret;
}

- (int)removeAllTouchNotInPhase:(UITouchPhase)phase {
	int ret = 0;
	for(WYUITouch* touch in m_touches) {
		if(touch.phase != phase) {
			[self removeTouch:touch];
			ret++;
		}
	}
	
	return ret;
}

@end

#endif // #if IOS