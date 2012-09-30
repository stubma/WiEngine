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

#import "WYGestureRecognizer.h"

@interface WYGestureRecognizer (PrivateMethods)

- (void)fail;
- (void)endAllTimers;
- (void)onLongPress:(NSTimer*)timer;
- (void)onShowPress:(NSTimer*)timer;
- (void)onSingleTap:(NSTimer*)timer;
- (void)changeState:(UIGestureRecognizerState)state;

@end

@implementation WYGestureRecognizer

@synthesize firstEvent = m_firstEvent;
@synthesize event = m_event;
@synthesize subState = m_subState;
@synthesize state = m_state;
@synthesize allowableMovement = m_allowableMovement;
@synthesize dx = m_dx;
@synthesize dy = m_dy;

- (id)initWithTarget:(id)target action:(SEL)action {
	if(self = [super init]) {
		m_allowableMovement = 10;
		m_target = target;
		m_action = action;
	}
	return self;
}

- (void)dealloc {
	[self endAllTimers];
	[m_firstEvent release];
	[m_event release];
	[super dealloc];
}

- (void)endAllTimers {
	if(m_longPressTimer) {
		[m_longPressTimer invalidate];
		m_longPressTimer = nil;
	}
	if(m_showPressTimer) {
		[m_showPressTimer invalidate];
		m_showPressTimer = nil;
	}
	if(m_singleTapTimer) {
		[m_singleTapTimer invalidate];
		m_singleTapTimer = nil;
	}
}

- (void)fail {
	[self endAllTimers];
	[self reset];
}

- (void)mouseDown:(NSEvent *)event {
	switch([event clickCount]) {
		case 1:
			// set as first event
			[event retain];
			[m_firstEvent release];
			m_firstEvent = event;
			
			// set as current event
			[event retain];
			[m_event release];
			m_event = event;
			
			// schedule timer to detect show press and long press
			m_showPressTimer = [NSTimer scheduledTimerWithTimeInterval:0.1f
																target:self
															  selector:@selector(onShowPress:) 
															  userInfo:nil
															   repeats:NO];
			m_longPressTimer = [NSTimer scheduledTimerWithTimeInterval:0.5f
																target:self
															  selector:@selector(onLongPress:) 
															  userInfo:nil
															   repeats:NO];
			
			// set state
			m_subState = WYGestureRecognizerSubStateDown;
			[self changeState:UIGestureRecognizerStateBegan];
			break;
		case 2:
			switch(m_state) {
				case UIGestureRecognizerStateChanged:
					switch(m_subState) {
						case WYGestureRecognizerSubStateSingleTapUp:
							[self endAllTimers];
							
							// set as first event
							[event retain];
							[m_firstEvent release];
							m_firstEvent = event;
							
							// set as current event
							[event retain];
							[m_event release];
							m_event = event;
							
							// for long press
							m_longPressTimer = [NSTimer scheduledTimerWithTimeInterval:0.5f
																				target:self
																			  selector:@selector(onLongPress:) 
																			  userInfo:nil
																			   repeats:NO];
							
							// this is a double tap event
							m_inDoubleTap = YES;
							m_subState = WYGestureRecognizerSubStateDoubleTap;
							[self changeState:UIGestureRecognizerStateChanged];
							break;
						default:
							[self fail];
							break;
					}
					break;
				default:
					[self fail];
					break;
			}
			break;
		default:
			[self fail];
			break;
	}
}

- (void)mouseDragged:(NSEvent *)event {
	switch(m_state) {
		case UIGestureRecognizerStateBegan:
		case UIGestureRecognizerStateChanged:
			switch(m_subState) {
				case WYGestureRecognizerSubStateLongPress:
				case WYGestureRecognizerSubStateLongPressRepeat:
					m_subState = WYGestureRecognizerSubStateLongPressRepeat;
					break;
				case WYGestureRecognizerSubStateScroll:
				{
					// set as current event
					[event retain];
					[m_event release];
					m_event = event;
					
					// calculate distance
					NSPoint loc = [event locationInWindow];
					
					// calculate distance, cocoa coordinates is same as opengl
					m_dx = m_lastX - loc.x;
					m_dy = loc.y - m_lastY;
					m_lastX = loc.x;
					m_lastY = loc.y;
					
					// compute fling velocity
					NSTimeInterval delta = [event timestamp] - m_lastTimestamp;
					m_lastTimestamp = [event timestamp];
					m_lastFlingVelocity.x = -m_dx / delta;
					m_lastFlingVelocity.y = -m_dy / delta;
					
					// trigger a scroll event
					m_subState = WYGestureRecognizerSubStateScroll;
					[self changeState:UIGestureRecognizerStateChanged];
					break;
				}
				default:
				{
					if([event clickCount] == 1) {
						// set as current event
						[event retain];
						[m_event release];
						m_event = event;
						
						// check distance
						NSPoint loc = [m_event locationInWindow];
						NSPoint firstLoc = [m_firstEvent locationInWindow];
						float distance = wyMath::sqrt(powf(loc.x - firstLoc.x, 2) + powf(loc.y - firstLoc.y, 2));
						if(distance > m_allowableMovement) {
							// ensure timer is ended
							[self endAllTimers];
							
							// calculate distance, cocoa coordinates is same as opengl
							m_dx = firstLoc.x - loc.x;
							m_dy = loc.y - firstLoc.y;
							m_lastX = loc.x;
							m_lastY = loc.y;
							
							// save timestamp
							m_lastTimestamp = [event timestamp];
							
							// trigger a scroll event
							m_subState = WYGestureRecognizerSubStateScroll;
							[self changeState:UIGestureRecognizerStateChanged];
						}						
					}

					break;
				}
			}
			break;
	}
}

- (void)mouseUp:(NSEvent *)event {
	[self endAllTimers];
	
	switch(m_state) {
		case UIGestureRecognizerStateBegan:
		case UIGestureRecognizerStateChanged:
		{
			// set as current event
			[event retain];
			[m_event release];
			m_event = event;
			
			switch(m_subState) {
				case WYGestureRecognizerSubStateDown:
					m_singleTapTimer = [NSTimer scheduledTimerWithTimeInterval:0.2f
																		target:self
																	  selector:@selector(onSingleTap:) 
																	  userInfo:nil
																	   repeats:NO];
					
					m_subState = WYGestureRecognizerSubStateSingleTapUp;
					[self changeState:UIGestureRecognizerStateChanged];
					break;
				case WYGestureRecognizerSubStateShowPress:
					m_subState = WYGestureRecognizerSubStateSingleTapUp;
					[self changeState:UIGestureRecognizerStateEnded];
					break;
				case WYGestureRecognizerSubStateScroll:
				{
					// set as current event
					[event retain];
					[m_event release];
					m_event = event;
					
					/*
					 * 使用最后一次move事件中的抛掷速度, 因为发现在end事件里计算出来的速度不稳定, 主要是因为时间
					 * 变动基本都是0.016秒, 但是在end事件里, 移动的距离可能很小.
					 */
					m_dx = m_lastFlingVelocity.x;
					m_dy = m_lastFlingVelocity.y;
					
					// trigger fling
					m_subState = WYGestureRecognizerSubStateFling;
					[self changeState:UIGestureRecognizerStateEnded];
					break;
				}
				default:
					if(m_inDoubleTap) {
						m_subState = WYGestureRecognizerSubStateDoubleTapEvent;
						[self changeState:UIGestureRecognizerStateEnded];
					} else {
						m_subState = WYGestureRecognizerSubStateNone;
						[self changeState:UIGestureRecognizerStateEnded];
					}
					break;
			}
			
			break;
		}
		default:
			[self fail];
			break;
	}
}

- (void)reset {
	[self endAllTimers];
	m_subState = WYGestureRecognizerSubStateNone;
	m_state = UIGestureRecognizerStateFailed;
	[m_firstEvent release];
	[m_event release];
	m_firstEvent = nil;
	m_event = nil;
	m_inDoubleTap = NO;
}

- (void)onLongPress:(NSTimer*)timer {
	m_longPressTimer = nil;
	m_subState = WYGestureRecognizerSubStateLongPress;
	[self changeState:UIGestureRecognizerStateChanged];
}

- (void)onShowPress:(NSTimer*)timer {
	m_showPressTimer = nil;
	m_subState = WYGestureRecognizerSubStateShowPress;
	[self changeState:UIGestureRecognizerStateChanged];
}

- (void)onSingleTap:(NSTimer*)timer {
	m_singleTapTimer = nil;
	m_subState = WYGestureRecognizerSubStateSingleTapConfirm;
	[self changeState:UIGestureRecognizerStateEnded];
}

- (void)changeState:(UIGestureRecognizerState)state {
	m_state = state;
	switch(m_state) {
		case UIGestureRecognizerStateBegan:
		case UIGestureRecognizerStateChanged:
		case UIGestureRecognizerStateEnded:
            [m_target performSelector:m_action withObject:self];
			break;
	}
}

@end

#endif // #if MACOSX