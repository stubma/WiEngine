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

#import "WYGestureRecognizer.h"

@interface WYGestureRecognizer (PrivateMethods)

- (void)fail;
- (void)endAllTimers;
- (void)onLongPress:(NSTimer*)timer;
- (void)onShowPress:(NSTimer*)timer;
- (void)onSingleTap:(NSTimer*)timer;

@end

@implementation WYGestureRecognizer

@synthesize firstEvent = m_firstEvent;
@synthesize event = m_event;
@synthesize subState = m_subState;
@synthesize allowableMovement = m_allowableMovement;
@synthesize dx = m_dx;
@synthesize dy = m_dy;

- (id)initWithTarget:(id)target action:(SEL)action {
	if(self = [super initWithTarget:target action:action]) {
		m_allowableMovement = 10;
		self.cancelsTouchesInView = NO;
	}
	return self;
}

- (void)dealloc {
	[self endAllTimers];
	[WYUIEvent poolEvent:m_firstEvent];
	[WYUIEvent poolEvent:m_event];
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
	m_subState = WYGestureRecognizerSubStateNone;
	self.state = UIGestureRecognizerStateFailed;
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
	[super touchesBegan:touches withEvent:event];
	
	// check touch count
	NSArray* allTouches = [[event allTouches] allObjects];
	if([allTouches count] == 1) {
		UITouch* touch = [allTouches objectAtIndex:0];
		switch(touch.tapCount) {
			case 1:
				m_firstEvent = [[WYUIEvent popEvent:event] retain];
				m_event = [[WYUIEvent popEvent:event] retain];
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
				
				m_subState = WYGestureRecognizerSubStateDown;
				self.state = UIGestureRecognizerStateBegan;
				break;
			case 2:
				switch(self.state) {
					case UIGestureRecognizerStateChanged:
						switch(m_subState) {
							case WYGestureRecognizerSubStateSingleTapUp:
								[self endAllTimers];
								[m_firstEvent setUIEvent:event];
								[m_event setUIEvent:event];
								
								// for long press
								m_longPressTimer = [NSTimer scheduledTimerWithTimeInterval:0.5f
																					target:self
																				  selector:@selector(onLongPress:) 
																				  userInfo:nil
																				   repeats:NO];
								
								// this is a double tap event
								m_inDoubleTap = YES;
								m_subState = WYGestureRecognizerSubStateDoubleTap;
								self.state = UIGestureRecognizerStateChanged;
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
	} else {
		[self fail];
	}
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
	[super touchesMoved:touches withEvent:event];
	
	switch(self.state) {
		case UIGestureRecognizerStateBegan:
		case UIGestureRecognizerStateChanged:
			switch(m_subState) {
				case WYGestureRecognizerSubStateLongPress:
				case WYGestureRecognizerSubStateLongPressRepeat:
					m_subState = WYGestureRecognizerSubStateLongPressRepeat;
					break;
				case WYGestureRecognizerSubStateScroll:
				{
					// save event
					[m_event setUIEvent:event];
					
					// save timestamp
					NSArray* touches = [[event allTouches] allObjects];
					UITouch* touch = [touches objectAtIndex:0];
					
					// calculate distance
					CGPoint loc = [m_event firstTouchLocation];
					
					/*
					 * 计算滚动距离, x和y是反的, 这是因为Android和iOS的缺省坐标系都和OpenGL坐标系
					 * y轴方向相反, 因此在wyEventDispatcher中是做了一次取反操作的, 因此这里要反着算
					 */
					m_dx = m_lastX - loc.x;
					m_dy = loc.y - m_lastY;
					m_lastX = loc.x;
					m_lastY = loc.y;
					
					// compute fling velocity
					NSTimeInterval delta = touch.timestamp - m_lastTimestamp;
					m_lastTimestamp = touch.timestamp;
					m_lastFlingVelocity.x = -m_dx / delta;
					m_lastFlingVelocity.y = -m_dy / delta;
					
					// trigger a scroll event
					m_subState = WYGestureRecognizerSubStateScroll;
					self.state = UIGestureRecognizerStateChanged;
					break;
				}
				default:
				{
					NSArray* touches = [[event allTouches] allObjects];
					UITouch* touch = [touches objectAtIndex:0];
					if(touch.tapCount == 1) {
						// save event
						[m_event setUIEvent:event];
						
						// check distance
						CGPoint loc = [m_event firstTouchLocation];
						CGPoint firstLoc = [m_firstEvent firstTouchLocation];
						float distance = wyMath::sqrt(powf(loc.x - firstLoc.x, 2) + powf(loc.y - firstLoc.y, 2));
						if(distance > m_allowableMovement) {
							// ensure timer is ended
							[self endAllTimers];
							
							/*
							 * 计算滚动距离, x和y是反的, 这是因为Android和iOS的缺省坐标系都和OpenGL坐标系
							 * y轴方向相反, 因此在wyEventDispatcher中是做了一次取反操作的, 因此这里要反着算
							 */
							m_dx = firstLoc.x - loc.x;
							m_dy = loc.y - firstLoc.y;
							m_lastX = loc.x;
							m_lastY = loc.y;
							
							// save timestamp
							m_lastTimestamp = touch.timestamp;
							
							// trigger a scroll event
							m_subState = WYGestureRecognizerSubStateScroll;
							self.state = UIGestureRecognizerStateChanged;
						}						
					}

					break;
				}
			}
			break;
	}
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
	[super touchesEnded:touches withEvent:event];
	
	[self endAllTimers];
	
	switch(self.state) {
		case UIGestureRecognizerStateBegan:
		case UIGestureRecognizerStateChanged:
		{
			[m_event setUIEvent:event];
			
			switch(m_subState) {
				case WYGestureRecognizerSubStateDown:
					m_singleTapTimer = [NSTimer scheduledTimerWithTimeInterval:0.2f
																		target:self
																	  selector:@selector(onSingleTap:) 
																	  userInfo:nil
																	   repeats:NO];
					
					m_subState = WYGestureRecognizerSubStateSingleTapUp;
					self.state = UIGestureRecognizerStateChanged;
					break;
				case WYGestureRecognizerSubStateShowPress:
					m_subState = WYGestureRecognizerSubStateSingleTapUp;
					self.state = UIGestureRecognizerStateEnded;
					break;
				case WYGestureRecognizerSubStateScroll:
				{
					// save event
					[m_event setUIEvent:event];
					
					/*
					 * 使用最后一次move事件中的抛掷速度, 因为发现在end事件里计算出来的速度不稳定, 主要是因为时间
					 * 变动基本都是0.016秒, 但是在end事件里, 移动的距离可能很小.
					 */
					m_dx = m_lastFlingVelocity.x;
					m_dy = m_lastFlingVelocity.y;
					
					// trigger fling
					m_subState = WYGestureRecognizerSubStateFling;
					self.state = UIGestureRecognizerStateEnded;
					break;
				}
				default:
					if(m_inDoubleTap) {
						m_subState = WYGestureRecognizerSubStateDoubleTapEvent;
						self.state = UIGestureRecognizerStateEnded;
					} else {
						m_subState = WYGestureRecognizerSubStateNone;
						self.state = UIGestureRecognizerStateEnded;
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

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
	[super touchesCancelled:touches withEvent:event];
	
	[self endAllTimers];	
	self.state = UIGestureRecognizerStateFailed;
}

- (void)reset {
	[super reset];
	[self endAllTimers];
	m_subState = WYGestureRecognizerSubStateNone;
	[WYUIEvent poolEvent:m_firstEvent];
	[WYUIEvent poolEvent:m_event];
	[m_firstEvent release];
	[m_event release];
	m_firstEvent = nil;
	m_event = nil;
	m_inDoubleTap = NO;
}

- (void)onLongPress:(NSTimer*)timer {
	m_longPressTimer = nil;
	m_subState = WYGestureRecognizerSubStateLongPress;
	self.state = UIGestureRecognizerStateChanged;
}

- (void)onShowPress:(NSTimer*)timer {
	m_showPressTimer = nil;
	m_subState = WYGestureRecognizerSubStateShowPress;
	self.state = UIGestureRecognizerStateChanged;
}

- (void)onSingleTap:(NSTimer*)timer {
	m_singleTapTimer = nil;
	m_subState = WYGestureRecognizerSubStateSingleTapConfirm;
	self.state = UIGestureRecognizerStateEnded;
}

@end

#endif // #if IOS