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

#import <AppKit/AppKit.h>

@class WYOpenGLView;
@class WYGestureRecognizer;

/**
 * @protocol WYOpenGLViewDelegate
 *
 * \if English
 * delegate of WYOpenGLView frame buffer event, internal used only
 * \else
 * WYOpenGLView的事件回调, 仅内部使用
 * \endif
 */
@protocol WYOpenGLViewDelegate

@optional

/**
 * \if English
 * Invoked when frame buffer is created
 * \else
 * 当帧缓冲创建时被调用
 * \endif
 */
- (void)glView:(WYOpenGLView*)v frameBufferCreatedWithWidth:(int)width height:(int)height;

/**
 * \if English
 * Invoked when glview is destroyed
 * \else
 * 在帧缓冲被销毁时调用
 * \endif
 */
- (void)glViewFrameBufferDestroyed:(WYOpenGLView*)v;

@end

@interface WYOpenGLView : NSOpenGLView {
@private
	/**
	 * \if English
	 * redraw timer
	 * \else
	 * 渲染定时器
	 * \endif
	 */
	NSTimer* m_timer;
	
	/// delegate
	id<WYOpenGLViewDelegate> m_delegate;
	
	/**
	 * \if English
	 * Gesture detector
	 * \else
	 * 手势事件检测
	 * \endif
	 */
	WYGestureRecognizer* m_gestureRecognizer;
	
	/// flag indicating gesture detecting is enabled or not
	BOOL m_detectGesture;
}

@property (nonatomic, assign) id<WYOpenGLViewDelegate> delegate;
@property (nonatomic, assign) BOOL detectGesture;

/// 开始进行OpenGL渲染
- (void)startRender;

/// 停止OpenGL渲染
- (void)stopRender;

/**
 * \if English
 * Enable gesture detecting or not
 *
 * @param flag true means gesture detecting is enabled
 * \else
 * 打开或关闭手势事件检测
 *
 * @param flag true表示打开手势检测
 * \endif
 */
- (void)setDetectGesture:(BOOL)flag;

@end

#endif // #if MACOSX