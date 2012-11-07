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

#import <QuartzCore/QuartzCore.h>
#import "WYEAGLView.h"
#import "wyGlobal.h"
#import "wyDirector_ios.h"
#import "WYGestureRecognizer.h"
#import "WYUIEvent.h"

// uncomment this to view event detail
//#define DUMP_EVENT

extern wyDirector_ios* gDirector;
extern wyEventDispatcher* gEventDispatcher;

@interface WYEAGLView (PrivateMethods)

- (void)setFramebuffer;
- (void)createFramebuffer;
- (void)deleteFramebuffer;
- (BOOL)presentFramebuffer;
- (void)initContext;
- (void)drawFrame;
- (void)end;
- (NSString*)touchPhaseString:(UITouchPhase)phase;
- (void)onWYGesture:(UIGestureRecognizer*)gestureRecognizer;

@end

@implementation WYEAGLView

@synthesize context = m_context;
@synthesize displayLink = m_displayLink;
@synthesize accelerometerDelay = m_accelerometerDelay;

+ (Class)layerClass {
    return [CAEAGLLayer class];
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

- (void)dealloc {
    [self deleteFramebuffer];    
	
	// delete director
	if(gDirector != NULL)
		wyObjectRelease(gDirector);
	
	// Tear down context.
    if ([EAGLContext currentContext] == m_context)
        [EAGLContext setCurrentContext:nil];
    [m_context release];
	
    [super dealloc];
}

- (void)initContext {
	// init self
	self.multipleTouchEnabled = YES;
	
	// init layer
	CAEAGLLayer* eaglLayer = (CAEAGLLayer*)self.layer;
	eaglLayer.opaque = YES;
	eaglLayer.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:
									[NSNumber numberWithBool:NO], kEAGLDrawablePropertyRetainedBacking,
									kEAGLColorFormatRGBA8, kEAGLDrawablePropertyColorFormat,
									nil];
	
	// create context
	EAGLContext* context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
	if (!context)
		NSLog(@"Failed to create ES context");
	else if (![EAGLContext setCurrentContext:context])
		NSLog(@"Failed to set ES context current");
	self.context = context;
	[context release];
	
	// attach self to director
	wyDirector::getInstance();
	gDirector->attachContext(self);
	gDirector->attachInView(self);
	gDirector->setAccelerometerDelay(DELAY_GAME);
}

- (void)setDetectGesture:(BOOL)flag {
	if(m_detectGesture != flag) {
		// remove all gesture detector first
		NSArray* array = [NSArray arrayWithArray:self.gestureRecognizers];
		for(UIGestureRecognizer* gr in array) {
			[self removeGestureRecognizer:gr];
		}
		
		m_detectGesture = flag;
		if(m_detectGesture) {
			// install long press
			WYGestureRecognizer* wyRecognizer = [[WYGestureRecognizer alloc] initWithTarget:self action:@selector(onWYGesture:)];
			[self addGestureRecognizer:wyRecognizer];
			[wyRecognizer release];
		}
	}
}

- (void)setDetectAcceleration:(BOOL)flag {
	if(flag) {
		if(!m_accelerometerRegistered) {
			[UIAccelerometer sharedAccelerometer].delegate = self;
			[UIAccelerometer sharedAccelerometer].updateInterval = self.accelerometerDelay;
			m_accelerometerRegistered = YES;
		}
	} else {
		if(m_accelerometerRegistered) {
			[UIAccelerometer sharedAccelerometer].delegate = nil;
			m_accelerometerRegistered = NO;
		}
	}
}

- (void)startRender {
    if (!m_rendering) {
        CADisplayLink* displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(drawFrame)];
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        self.displayLink = displayLink;
        
        m_rendering = YES;
    }
}

- (void)stopRender {
    if (m_rendering) {
        [self.displayLink invalidate];
        self.displayLink = nil;
        m_rendering = NO;
    }
}

- (void)end {
	if(wyDevice::apiLevel >= 400) {
		/*
		 * 这些代码仅是为了方便demo. iOS没有退出当前应用的api, end方法也不需要被直接调用
		 */
		if([self.window.rootViewController respondsToSelector:@selector(popViewControllerAnimated:)])
			[(id)self.window.rootViewController popViewControllerAnimated:YES];
		else if(self.window.rootViewController.navigationController != nil)
			[self.window.rootViewController.navigationController popViewControllerAnimated:YES];	
	}
}

- (void)setContext:(EAGLContext *)newContext {
    if (m_context != newContext) {
        [self deleteFramebuffer];
        [m_context release];
        m_context = [newContext retain];
        [EAGLContext setCurrentContext:nil];
    }
}

- (void)createFramebuffer {
    if (m_context && !m_defaultFramebuffer) {
        [EAGLContext setCurrentContext:m_context];
		
		// set scale factor
		if(wyDevice::apiLevel >= 400)
			self.contentScaleFactor = [UIScreen mainScreen].scale;
		
        // Create default framebuffer object.
        glGenFramebuffers(1, &m_defaultFramebuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, m_defaultFramebuffer);
        
        // Create color render buffer and allocate backing store.
		GLint w, h;
        glGenRenderbuffers(1, &m_colorRenderbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderbuffer);
        [m_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:(CAEAGLLayer *)self.layer];
		glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &w);
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &h);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_colorRenderbuffer);
        
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            NSLog(@"Failed to make complete framebuffer object %x", glCheckFramebufferStatus(GL_FRAMEBUFFER));
		
		// notify director
		if(gDirector != NULL) {
			gDirector->onSurfaceCreated();
			gDirector->onSurfaceChanged(w, h);
		}
    }
}

- (void)deleteFramebuffer {
    if (m_context) {
        [EAGLContext setCurrentContext:m_context];
        
        if (m_defaultFramebuffer) {
            glDeleteFramebuffers(1, &m_defaultFramebuffer);
            m_defaultFramebuffer = 0;
        }
        
        if (m_colorRenderbuffer) {
            glDeleteRenderbuffers(1, &m_colorRenderbuffer);
            m_colorRenderbuffer = 0;
        }
		
		// notify director
		if(gDirector != NULL)
			gDirector->onSurfaceDestroyed();
    }
}

- (void)setFramebuffer {
    if (m_context) {
        [EAGLContext setCurrentContext:m_context];
        
        if (!m_defaultFramebuffer)
            [self createFramebuffer];
        
        glBindFramebuffer(GL_FRAMEBUFFER, m_defaultFramebuffer);
    }
}

- (BOOL)presentFramebuffer {
    BOOL success = NO;
    
    if (m_context) {
        [EAGLContext setCurrentContext:m_context];
        
        glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderbuffer);
        
        success = [m_context presentRenderbuffer:GL_RENDERBUFFER];
    }
    
    return success;
}

- (void)layoutSubviews {
    // The framebuffer will be re-created at the beginning of the next setFramebuffer method call.
    [self deleteFramebuffer];
}

- (void)drawFrame {
	[self setFramebuffer];

	// call director to render scene
	if(gDirector != NULL)
		gDirector->drawFrame();
	
	[self presentFramebuffer];
}

- (NSString*)touchPhaseString:(UITouchPhase)phase {
	switch (phase) {
		case UITouchPhaseBegan:
			return @"UITouchPhaseBegan";
		case UITouchPhaseCancelled:
			return @"UITouchPhaseCancelled";
		case UITouchPhaseEnded:
			return @"UITouchPhaseEnded";
		case UITouchPhaseMoved:
			return @"UITouchPhaseMoved";
		case UITouchPhaseStationary:
			return @"UITouchPhaseStationary";
		default:
			return @"";
	}
}

- (BOOL)canBecomeFirstResponder {
	return YES;
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
#ifdef DUMP_EVENT
	NSLog(@"---- touchesBegan dump start");
	int i = 0;
	NSArray* allTouches = [[event allTouches] allObjects];
	for(UITouch* touch in allTouches) {
		CGPoint loc = [touch locationInView:self];
		NSLog(@"%d: obj: %x, tap: %d, x: %f, y: %f, phase: %@", i++, touch, touch.tapCount, loc.x, loc.y, [self touchPhaseString:touch.phase]);
	}
	NSLog(@"**** touchesBegan dump end");
#endif
	
	// if I am not the first responder, becomes it
	if(![self isFirstResponder])
		[self becomeFirstResponder];
	
	if(gEventDispatcher != NULL) {
		WYUIEvent* e = [WYUIEvent popEvent:event];
		gEventDispatcher->queueEventLocked(ET_TOUCH_BEGAN, e);
	}
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
#ifdef DUMP_EVENT
	NSLog(@"---- touchesMoved dump start");
	int i = 0;
	NSArray* allTouches = [[event allTouches] allObjects];
	for(UITouch* touch in allTouches) {
		CGPoint loc = [touch locationInView:self];
		NSLog(@"%d: obj: %x, tap: %d, x: %f, y: %f, phase: %@", i++, touch, touch.tapCount, loc.x, loc.y, [self touchPhaseString:touch.phase]);
	}
	NSLog(@"**** touchesMoved dump end");
#endif
	
	if(gEventDispatcher != NULL) {
		WYUIEvent* e = [WYUIEvent popEvent:event];
		gEventDispatcher->queueEventLocked(ET_TOUCH_MOVED, e);
	}
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
#ifdef DUMP_EVENT
	NSLog(@"---- touchesEnded dump start");
	int i = 0;
	NSArray* allTouches = [[event allTouches] allObjects];
	for(UITouch* touch in allTouches) {
		CGPoint loc = [touch locationInView:self];
		NSLog(@"%d: obj: %x, tap: %d, x: %f, y: %f, phase: %@", i++, touch, touch.tapCount, loc.x, loc.y, [self touchPhaseString:touch.phase]);
	}
	NSLog(@"**** touchesEnded dump end");
#endif
	
	if(gEventDispatcher != NULL) {
		WYUIEvent* e = [WYUIEvent popEvent:event];
		gEventDispatcher->queueEventLocked(ET_TOUCH_ENDED, e);
	}
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
#ifdef DUMP_EVENT
	NSLog(@"---- touchesCancelled dump start");
	int i = 0;
	NSArray* allTouches = [[event allTouches] allObjects];
	for(UITouch* touch in allTouches) {
		CGPoint loc = [touch locationInView:self];
		NSLog(@"%d: obj: %x, tap: %d, x: %f, y: %f, phase: %@", i++, touch, touch.tapCount, loc.x, loc.y, [self touchPhaseString:touch.phase]);
	}
	NSLog(@"**** touchesCancelled dump end");
#endif
	
	if(gEventDispatcher != NULL) {
		WYUIEvent* e = [WYUIEvent popEvent:event];
		gEventDispatcher->queueEventLocked(ET_TOUCH_CANCELLED, e);
	}
}

- (void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration {
#ifdef DUMP_EVENT
	NSLog(@"acceleration: %f, %f, %f", acceleration.x, acceleration.y, acceleration.z);
#endif
	
	if(gEventDispatcher != NULL) {
		gEventDispatcher->queueEventLocked(acceleration.x, acceleration.y, acceleration.z);
	}
}

- (void)onWYGesture:(UIGestureRecognizer*)gestureRecognizer {
	if(gEventDispatcher != NULL) {
		WYGestureRecognizer* gr = (WYGestureRecognizer*)gestureRecognizer;
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
						gEventDispatcher->queueEventLocked(ET_ON_DOWN, [WYUIEvent popCopy:gr.event]);
						break;
					case WYGestureRecognizerSubStateShowPress:
						gEventDispatcher->queueEventLocked(ET_ON_SHOW_PRESS, [WYUIEvent popCopy:gr.event]);
						break;
					case WYGestureRecognizerSubStateSingleTapUp:
						gEventDispatcher->queueEventLocked(ET_ON_SINGLE_TAP_UP, [WYUIEvent popCopy:gr.event]);
						break;
					case WYGestureRecognizerSubStateSingleTapConfirm:
						gEventDispatcher->queueEventLocked(ET_SINGLE_TAP_CONFIRMED, [WYUIEvent popCopy:gr.event]);
						break;
					case WYGestureRecognizerSubStateDoubleTap:
						gEventDispatcher->queueEventLocked(ET_DOUBLE_TAP, [WYUIEvent popCopy:gr.event]);
						gEventDispatcher->queueEventLocked(ET_DOUBLE_TAP_EVENT, [WYUIEvent popCopy:gr.event]);
						break;
					case WYGestureRecognizerSubStateDoubleTapEvent:
						gEventDispatcher->queueEventLocked(ET_DOUBLE_TAP_EVENT, [WYUIEvent popCopy:gr.event]);
						break;
					case WYGestureRecognizerSubStateLongPress:
						gEventDispatcher->queueEventLocked(ET_ON_LONG_PRESS, [WYUIEvent popCopy:gr.event]);
						break;
					case WYGestureRecognizerSubStateScroll:
						gEventDispatcher->queueEventLocked(ET_ON_SCROLL, [WYUIEvent popCopy:gr.firstEvent], [WYUIEvent popCopy:gr.event], gr.dx, gr.dy);
						break;
					case WYGestureRecognizerSubStateFling:
						gEventDispatcher->queueEventLocked(ET_ON_FLING, [WYUIEvent popCopy:gr.firstEvent], [WYUIEvent popCopy:gr.event], gr.dx, gr.dy);
						break;
				}
				break;
		}
	}
}

@end

#endif // #if IOS