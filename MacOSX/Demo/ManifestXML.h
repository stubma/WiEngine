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

#import <Foundation/Foundation.h>

@interface Activity : NSObject {
@private
	NSString* m_category;
    NSString* m_name;
	NSString* m_descKey;
	NSString* m_layerName;
}

@property(nonatomic, retain) NSString* name;
@property(nonatomic, retain) NSString* category;
@property(nonatomic, retain) NSString* descKey;
@property(nonatomic, retain) NSString* layerName;

- (NSComparisonResult)compare:(Activity*)act;

@end

/**
 * 用来解析AndroidManifest.xml文件, 仅为了Demo而用
 */
@interface ManifestXML : NSObject<NSXMLParserDelegate> {
@private
	/// 分类名列表
	NSMutableArray* m_categories;
	
	/// key是分类名, value是NSArray, 数据对象为Activity
	NSMutableDictionary* m_demos;
	
	/// parse state
	int m_state;
	
	/// current activity
	Activity* m_activity;
}

@property(nonatomic, readonly) NSArray* categories;
@property(nonatomic, readonly) NSDictionary* demos;

/// 得到共享实例
+ (ManifestXML*)sharedInstance;

/// 释放共享实例
+ (void)destroy;

/// 打印解析结果, 调试用
- (void)print;

@end
