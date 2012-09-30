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

#import "WYOpenGLView.h"
#import "WYGestureRecognizer.h"
#include "wyDirector_macosx.h"
#include "wyEventDispatcher_macosx.h"

// comment if event should not be dumped
//#define DUMP_EVENT

// global singleton
extern wyDirector_macosx* gDirector;
extern wyEventDispatcher_macosx* gEventDispatcher;

/*
 * private methods of WYOpenGLView
 */

@interface WYOpenGLView (Private)

///　Get default pixel format used by WYOpenGLView
+ (NSOpenGLPixelFormat*)getPixelFormat;

///　setup necessary thing for startup
- (void)initContext;

///　render frame
- (void)drawFrame;

/// end
- (void)end;

/// express modifiers in string
- (NSString*)modifierFlags:(NSUInteger)flags;

/// action be triggerred by gesture detector
- (void)onWYGesture:(WYGestureRecognizer*)gr;

@end

/*
 * implementation of WYOpenGLView
 */

@implementation WYOpenGLView

@synthesize delegate = m_delegate;
@synthesize detectGesture = m_detectGesture;

+ (NSOpenGLPixelFormat*)getPixelFormat {
    NSOpenGLPixelFormatAttribute attributes [] = {
        NSOpenGLPFAWindow,
        NSOpenGLPFADoubleBuffer,
        NSOpenGLPFADepthSize, 16, 
        nil
    };
    return [[[NSOpenGLPixelFormat alloc] initWithAttributes:attributes] autorelease];
}

- (void)dealloc {
	// release members
	[m_gestureRecognizer release];
	
	// end timer
	[self stopRender];
	
	// release director
    if(gDirector) {
		gDirector->onSurfaceDestroyed();
		wyObjectRelease(gDirector);
	}
	
    [super dealloc];
}

- (id)initWithCoder:(NSCoder*)coder {
    self = [super initWithCoder:coder];
	if (self) {
		[self initContext];
    }
    
    return self;
}

- (id)init {
	if(self = [super init]) {
		[self initContext];
	}
	return self;
}

- (id)initWithFrame:(NSRect)frameRect {
	NSOpenGLPixelFormat* pf = [WYOpenGLView getPixelFormat];	
	if(self = [super initWithFrame:frameRect pixelFormat:pf]) {
		[self initContext];
	}
    return self;
}

- (void)initContext {
	// init gesture recognizer
	m_gestureRecognizer = [[WYGestureRecognizer alloc] initWithTarget:self action:@selector(onWYGesture:)];
	
	// attach self to director
	wyDirector::getInstance();
	gDirector->attachContext(self);
	gDirector->attachInView(self);
	gDirector->setAccelerometerDelay(DELAY_GAME);
}

- (NSString*)modifierFlags:(NSUInteger)flags {
	NSMutableString* buf = [NSMutableString stringWithCapacity:64];
	if(flags & NSAlphaShiftKeyMask)
		[buf appendString:@"CapsLock "];
	if(flags & NSShiftKeyMask)
		[buf appendString:@"Shift "];
	if(flags & NSControlKeyMask)
		[buf appendString:@"Ctrl "];
	if(flags & NSAlternateKeyMask)
		[buf appendString:@"Alt "];
	if(flags & NSCommandKeyMask)
		[buf appendString:@"Cmd "];
	if(flags & NSNumericPadKeyMask)
		[buf appendString:@"Num "];
	if(flags & NSHelpKeyMask)
		[buf appendString:@"Help "];
	if(flags & NSFunctionKeyMask)
		[buf appendString:@"Fn "];
	
	if([buf length] == 0)
		[buf appendString:@"None"];
	else
		[buf deleteCharactersInRange:NSMakeRange([buf length] - 1, 1)];
	
	return [NSString stringWithString:buf];
}
- (void)prepareOpenGL {
	// set to vbl sync
    GLint swapInt = 1;
    [[self openGLContext] setValues:&swapInt forParameter:NSOpenGLCPSwapInterval];
	
	// notify director
	if(gDirector != NULL) {
		gDirector->onSurfaceCreated();
		gDirector->onSurfaceChanged(self.frame.size.width, self.frame.size.height);
		
		// call delegate
		if([(id)self.delegate respondsToSelector:@selector(glView:frameBufferCreatedWithWidth:height:)]) {
			[self.delegate glView:self
	  frameBufferCreatedWithWidth:self.frame.size.width
						   height:self.frame.size.height];
		}
	}
	
	// start render timer
	[self startRender];
	
	// require self as first responder
	[self.window makeFirstResponder:self];
}

- (void)drawFrame {
	// render frame
	if(gDirector != NULL) {
		gDirector->drawFrame();
	}
	
	// flush buffer
	[[self openGLContext] flushBuffer];
}

- (void)startRender {
	if(m_timer == nil) {
		m_timer = [NSTimer timerWithTimeInterval:1.0f / 60.0f
										  target:self 
										selector:@selector(drawFrame)
										userInfo:nil
										 repeats:YES];
		[[NSRunLoop currentRunLoop] addTimer:m_timer
									 forMode:NSDefaultRunLoopMode];
		[[NSRunLoop currentRunLoop] addTimer:m_timer 
									 forMode:NSEventTrackingRunLoopMode];
	}
}

- (void)stopRender {
	if(m_timer != nil) {
		[m_timer invalidate];
		m_timer = nil;
	}
}

- (void)end {
	[self stopRender];
	[self.window makeFirstResponder:nil];
	[self removeFromSuperview];
	
	// delegate
	if([(id)self.delegate respondsToSelector:@selector(glViewFrameBufferDestroyed:)]) {
		[self.delegate glViewFrameBufferDestroyed:self];
	}
}

- (BOOL)acceptsFirstResponder {
	return YES;
}

- (void)onWYGesture:(WYGestureRecognizer*)gr {
	switch(gr.state) {
		case UIGestureRecognizerStateBegan:
		case UIGestureRecognizerStateChanged:
		case UIGestureRecognizerStateEnded:
#ifdef DUMP_EVENT
			switch(gr.subState) {
				case WYGestureRecognizerSubStateDoubleTap:
					NSLog(@"WYGestureRecognizerSubStateDoubleTap");
					break;
				case WYGestureRecognizerSubStateDoubleTapEvent:
					NSLog(@"WYGestureRecognizerSubStateDoubleTapEvent");
					break;
				case WYGestureRecognizerSubStateDown:
					NSLog(@"WYGestureRecognizerSubStateDown");
					break;
				case WYGestureRecognizerSubStateFling:
					NSLog(@"WYGestureRecognizerSubStateFling");
					break;
				case WYGestureRecognizerSubStateLongPress:
					NSLog(@"WYGestureRecognizerSubStateLongPress");
					break;
				case WYGestureRecognizerSubStateLongPressRepeat:
					NSLog(@"WYGestureRecognizerSubStateLongPressRepeat");
					break;
				case WYGestureRecognizerSubStateNone:
					NSLog(@"WYGestureRecognizerSubStateLongPress");
					break;
				case WYGestureRecognizerSubStateScroll:
					NSLog(@"WYGestureRecognizerSubStateScroll");
					break;
				case WYGestureRecognizerSubStateShowPress:
					NSLog(@"WYGestureRecognizerSubStateShowPress");
					break;
				case WYGestureRecognizerSubStateSingleTapConfirm:
					NSLog(@"WYGestureRecognizerSubStateSingleTapConfirm");
					break;
				case WYGestureRecognizerSubStateSingleTapUp:
					NSLog(@"WYGestureRecognizerSubStateSingleTapUp");
					break;
			}
#endif
			
			switch(gr.subState) {
				case WYGestureRecognizerSubStateDown:
					gEventDispatcher->queueEventLocked(ET_ON_DOWN, gr.event);
					break;
				case WYGestureRecognizerSubStateShowPress:
					gEventDispatcher->queueEventLocked(ET_ON_SHOW_PRESS, gr.event);
					break;
				case WYGestureRecognizerSubStateSingleTapUp:
					gEventDispatcher->queueEventLocked(ET_ON_SINGLE_TAP_UP, gr.event);
					break;
				case WYGestureRecognizerSubStateSingleTapConfirm:
					gEventDispatcher->queueEventLocked(ET_SINGLE_TAP_CONFIRMED, gr.event);
					break;
				case WYGestureRecognizerSubStateDoubleTap:
					gEventDispatcher->queueEventLocked(ET_DOUBLE_TAP, gr.event);
					gEventDispatcher->queueEventLocked(ET_DOUBLE_TAP_EVENT, gr.event);
					break;
				case WYGestureRecognizerSubStateDoubleTapEvent:
					gEventDispatcher->queueEventLocked(ET_DOUBLE_TAP_EVENT, gr.event);
					break;
				case WYGestureRecognizerSubStateLongPress:
					gEventDispatcher->queueEventLocked(ET_ON_LONG_PRESS, gr.event);
					break;
				case WYGestureRecognizerSubStateScroll:
					gEventDispatcher->queueEventLocked(ET_ON_SCROLL, gr.firstEvent, gr.event, gr.dx, gr.dy);
					break;
				case WYGestureRecognizerSubStateFling:
					gEventDispatcher->queueEventLocked(ET_ON_FLING, gr.firstEvent, gr.event, gr.dx, gr.dy);
					break;
			}
			
			break;
	}
	
	// reset detector if ended
	if(gr.state == UIGestureRecognizerStateEnded)
		[gr reset];
}

- (void)mouseDown:(NSEvent *)theEvent {
#ifdef DUMP_EVENT
	NSLog(@"---- mouseDown dump start");
	NSPoint loc = [theEvent locationInWindow];
	loc = [self convertPoint:loc fromView:nil];
	NSLog(@"obj: %x, tap: %d, x: %f, y: %f, modifier: %@, pressure: %f", 
		  theEvent, [theEvent clickCount], loc.x, loc.y, [self modifierFlags:[theEvent modifierFlags]], [theEvent pressure]);
	NSLog(@"**** mouseDown dump end");
#endif
	
	if(m_detectGesture)
		[m_gestureRecognizer mouseDown:theEvent];
	
	if(gEventDispatcher != NULL) {
		gEventDispatcher->queueEventLocked(ET_TOUCH_BEGAN, theEvent);
	}
}

- (void)mouseDragged:(NSEvent *)theEvent {
#ifdef DUMP_EVENT
	NSLog(@"---- mouseDragged dump start");
	NSPoint loc = [theEvent locationInWindow];
	loc = [self convertPoint:loc fromView:nil];
	NSLog(@"obj: %x, tap: %d, x: %f, y: %f, modifier: %@, pressure: %f", 
		  theEvent, [theEvent clickCount], loc.x, loc.y, [self modifierFlags:[theEvent modifierFlags]], [theEvent pressure]);
	NSLog(@"**** mouseDragged dump end");
#endif
	
	if(m_detectGesture)
		[m_gestureRecognizer mouseDragged:theEvent];
	
	if(gEventDispatcher != NULL) {
		gEventDispatcher->queueEventLocked(ET_TOUCH_MOVED, theEvent);
	}
}

- (void)mouseUp:(NSEvent *)theEvent {
#ifdef DUMP_EVENT
	NSLog(@"---- mouseUp dump start");
	NSPoint loc = [theEvent locationInWindow];
	loc = [self convertPoint:loc fromView:nil];
	NSLog(@"obj: %x, tap: %d, x: %f, y: %f, modifier: %@, pressure: %f", 
		  theEvent, [theEvent clickCount], loc.x, loc.y, [self modifierFlags:[theEvent modifierFlags]], [theEvent pressure]);
	NSLog(@"**** mouseUp dump end");
#endif
	
	if(m_detectGesture)
		[m_gestureRecognizer mouseUp:theEvent];
	
	if(gEventDispatcher != NULL) {
		gEventDispatcher->queueEventLocked(ET_TOUCH_ENDED, theEvent);
	}
}

- (void)keyDown:(NSEvent *)theEvent {
#ifdef DUMP_EVENT
	NSLog(@"---- keyDown dump start");
	NSLog(@"obj: %x, keyCode: %x, char: %@, modifier: %@, isrepeat: %d", 
		  theEvent, [theEvent keyCode], [theEvent characters], [self modifierFlags:[theEvent modifierFlags]], [theEvent isARepeat]);
	NSLog(@"**** keyDown dump end");
#endif
	
	if(gEventDispatcher != NULL) {
		gEventDispatcher->queueKeyEventLocked([theEvent isARepeat] ? ET_KEY_MULTIPLE : ET_KEY_DOWN, theEvent);
	}
}

- (void)keyUp:(NSEvent *)theEvent {
#ifdef DUMP_EVENT
	NSLog(@"---- keyUp dump start");
	NSLog(@"obj: %x, keyCode: %x, char: %@, modifier: %@, isrepeat: %d", 
		  theEvent, [theEvent keyCode], [theEvent characters], [self modifierFlags:[theEvent modifierFlags]], [theEvent isARepeat]);
	NSLog(@"**** keyUp dump end");
#endif
	
	if(gEventDispatcher != NULL) {
		gEventDispatcher->queueKeyEventLocked(ET_KEY_UP, theEvent);
	}
}

@end

#endif // #if MACOSX