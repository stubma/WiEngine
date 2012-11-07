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

#import <UIKit/UIKit.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

@class EAGLContext;
@class WYEAGLView;

// This class wraps the CAEAGLLayer from CoreAnimation into a convenient UIView subclass.
// The view content is basically an EAGL surface you render your OpenGL scene into.
// Note that setting the view non-opaque will only work if the EAGL surface has an alpha channel.
@interface WYEAGLView : UIView <UIAccelerometerDelegate> {
@private    
    /// The OpenGL ES names for the framebuffer and renderbuffer used to render to this view.
    GLuint m_defaultFramebuffer, m_colorRenderbuffer;
	
	/// context of gl surface
	EAGLContext* m_context;
	
	// display link
	CADisplayLink* m_displayLink;
	
	/// rendering flag
	BOOL m_rendering;
	
	/// true表示已经接收了加速器事件
	BOOL m_accelerometerRegistered;
	
	/// 加速器事件触发间隔, 缺省是62毫秒一次, 相当于android中的DELAY_GAME
	NSTimeInterval m_accelerometerDelay;
	
	/// true表示手势事件已经开始检测
	BOOL m_detectGesture;
}

@property (nonatomic, retain) EAGLContext* context;
@property (nonatomic, retain) CADisplayLink* displayLink;
@property (nonatomic, assign) NSTimeInterval accelerometerDelay;

/// 开始进行OpenGL渲染
- (void)startRender;

/// 停止OpenGL渲染
- (void)stopRender;

/**
 * 设置是否进行手势事件探测, 这个方法由WiEngine内部调用. 一般不需要直接使用
 * 
 * @param flag YES表示打开手势事件探测
 */
- (void)setDetectGesture:(BOOL)flag;

/**
 * 设置是否接收加速器事件
 *
 * @param flag YES表示打开加速器事件
 */
- (void)setDetectAcceleration:(BOOL)flag;

@end

#endif // #if IOS
