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

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WYUITouch.h"

/**
 * @class WYUIEvent
 *
 * UIEvent不能被直接复制, 因此通过这个类达到复制UIEvent的目的. 因为有些事件需要
 * 两个event, 而iOS中的UIEvent是共享实例的.
 */
@interface WYUIEvent : NSObject {
@private
	/// 所有的touch对象, 其实是WYUITouch对象
	NSMutableArray* m_touches;
	
	/// 时间戳
	NSTimeInterval m_timestamp;
}

@property (nonatomic, readonly) NSTimeInterval timestamp;

/**
 * 从一个缓冲池中得到一个可以重用的WYUIEvent对象
 *
 * @param event UIEvent对象
 * @return WYUIEvent对象
 */
+ (WYUIEvent*)popEvent:(UIEvent*)event;

/**
 * 从一个缓冲池得到一个复制的WYUIEvent对象
 *
 * @param event 需要复制的WYUIEvent对象
 * @return WYUIEvent对象
 */
+ (WYUIEvent*)popCopy:(WYUIEvent*)event;

/**
 * 把一个WYUIEvent放入池中, 以便以后重用
 *
 * @param event WYUIEvent对象
 */
+ (void)poolEvent:(WYUIEvent*)event;

/**
 * 释放event缓冲对象池
 */
+ (void)releasePools;

/**
 * 绑定一个UITouch, UITouch中的信息会被复制
 * 
 * @param event UIEvent对象
 */
- (void)setUIEvent:(UIEvent*)event;

/**
 * 复制一个WYUIEvent的内容
 *
 * @param event WYUIEvent对象
 */
- (void)copyEvent:(WYUIEvent*)event;

/**
 * 返回所有的WYUITouch对象
 *
 * @return 包含WYUITouch对象的数组
 */
- (NSArray*)allTouches;

/**
 * 得到触摸对象数目
 *
 * @return 触摸对象数
 */
- (int)touchCount;

/**
 * 得到第一个触点对象的相对于view的位置
 *
 * @return 第一个触点对象的相对于view的位置, 如果一个触点也没有, 返回全0的CGPoint
 */
- (CGPoint)firstTouchLocation;

/**
 * 得到处于began状态的touch数量
 *
 * @return 处于began状态的touch数量
 */
- (int)beganTouchCount;

/**
 * 得到处于结束或取消状态的touch数量
 *
 * @return 处于结束或取消状态的touch数量
 */
- (int)endedTouchCount;

/**
 * 删除一个touch
 *
 * @param touch 要删除的WYUITouch对象
 */
- (void)removeTouch:(WYUITouch*)touch;

/**
 * 添加一个touch
 *
 * @param touch 要添加的WYUITouch对象
 */
- (void)addTouch:(WYUITouch*)touch;

/**
 * 删除一个符合某个状态的touch对象
 *
 * @param phase 状态常量
 * @return true表示删除成功, false表示已没有更多此状态的touch
 */
- (BOOL)removeOneTouchInPhase:(UITouchPhase)phase;

/**
 * 删除一个不符合某个状态的touch对象
 *
 * @param phase 状态常量
 * @return true表示删除成功, false表示已没有更多不在此状态的touch
 */
- (BOOL)removeOneTouchNotInPhase:(UITouchPhase)phase;

/**
 * 删除所有符合某个状态的touch对象
 *
 * @param phase 状态常量
 * @return 删除掉的touch数目
 */
- (int)removeAllTouchInPhase:(UITouchPhase)phase;

/**
 * 删除所有不符合某个状态的touch对象
 *
 * @param phase 状态常量
 * @return 删除掉的touch数目
 */
- (int)removeAllTouchNotInPhase:(UITouchPhase)phase;

@end

#endif // #if IOS