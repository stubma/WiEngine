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
#import "UIKit.h"

/**
 * @typedef WYGestureRecognizerSubState
 *
 * 用来表示一些子状态, 以便模拟Android上的show press, single tap up等事件
 */
typedef	enum {
	/// 无子状态
	WYGestureRecognizerSubStateNone,
	
	/// 第一个触点按下了
	WYGestureRecognizerSubStateDown,
	
	/// 当前处于show press, 其在long press之前, 表示有可能发生long press
	WYGestureRecognizerSubStateShowPress,
	
	/// show press之后, 但是在long press之前, 触摸结束了
	WYGestureRecognizerSubStateSingleTapUp,
	
	/// 在show press之前触摸即结束了
	WYGestureRecognizerSubStateSingleTapConfirm,
	
	/// 双击发生
	WYGestureRecognizerSubStateDoubleTap,
	
	/// tap数是2的事件, 包括按下, 松开, 移动
	WYGestureRecognizerSubStateDoubleTapEvent,
	
	/// 长按发生了
	WYGestureRecognizerSubStateLongPress,
	
	/// 长按重复发生, 这是为了避免反复触发长按事件而增加的一个可忽略状态
	WYGestureRecognizerSubStateLongPressRepeat,
	
	/// 发生了滚动
	WYGestureRecognizerSubStateScroll,
	
	/// 发生了fling
	WYGestureRecognizerSubStateFling
} WYGestureRecognizerSubState;

/**
 * @class WYGestureRecognizer
 *
 * 长按手势检测器, 负责模拟Android中的show press, single tap up和long press
 * 三个事件
 */
@interface WYGestureRecognizer : NSObject {
@private
	/// target
	id m_target;
	
	/// action
	SEL m_action;
	
	/// first event
	NSEvent* m_firstEvent;
	
	/// event
	NSEvent* m_event;
	
	/// timer
	NSTimer* m_longPressTimer;
	
	/// show press timer
	NSTimer* m_showPressTimer;
	
	/// single tap confirm timer
	NSTimer* m_singleTapTimer;
	
	/// state
	UIGestureRecognizerState m_state;
	
	/// sub state
	WYGestureRecognizerSubState m_subState;
	
	/// 长按被判定前允许的最大触摸位移
	float m_allowableMovement;
	
	/// 上一次事件的x坐标
	float m_lastX;
	
	/// 上一次事件的y坐标
	float m_lastY;
	
	/// scroll事件的x移动量或者fling事件的x方向速度
	float m_dx;
	
	/// scroll事件的y移动量或者fling事件的y方向速度
	float m_dy;
	
	/// true表示当前处于一个点击数为2的阶段
	BOOL m_inDoubleTap;
	
	/// 上一次事件的timestamp
	NSTimeInterval m_lastTimestamp;
	
	/// 最后一次move事件中的速度
	NSPoint m_lastFlingVelocity;
}

@property (nonatomic, readonly) NSEvent* firstEvent;
@property (nonatomic, readonly) NSEvent* event;
@property (nonatomic, readonly) WYGestureRecognizerSubState subState;
@property (nonatomic, readonly) UIGestureRecognizerState state;
@property (nonatomic, assign) float allowableMovement;
@property (nonatomic, readonly) float dx;
@property (nonatomic, readonly) float dy;

- (id)initWithTarget:(id)target action:(SEL)action;
- (void)reset;
- (void)mouseDown:(NSEvent *)event;
- (void)mouseDragged:(NSEvent *)event;
- (void)mouseUp:(NSEvent *)event;

@end

#endif // #if MACOSX
