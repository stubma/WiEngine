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

/**
 * @class WYUITouch
 *
 * UITouch不能被直接复制, 因此通过这个类来达到复制UITouch的目的.
 */
@interface WYUITouch : NSObject {
@private
	/// 时间戳
	NSTimeInterval m_timestamp;
	
	/// 点击数
	NSUInteger m_tapCount;
	
	/// 阶段
	UITouchPhase m_phase;
	
	/// 点击位置, 相对于WYEAGLView
	CGPoint m_location;
	
	/// iOS系统层touch对象哈希
	int m_hash;
}

@property (nonatomic, readonly) NSTimeInterval timestamp;
@property (nonatomic, readonly) NSUInteger tapCount;
@property (nonatomic, assign) UITouchPhase phase;
@property (nonatomic, readonly) CGPoint location;
@property (nonatomic, readonly) int hash;

/**
 * 通过UITouch创建一个对象, UITouch中的信息将被复制
 * 
 * @param touch UITouch对象
 */
- (void)setUITouch:(UITouch*)touch;

/**
 * 复制一个WYUITouch对象的内容
 *
 * @param touch 要复制的WYUITouch对象
 */
- (void)copyTouch:(WYUITouch*)touch;

@end

#endif // #if IOS
