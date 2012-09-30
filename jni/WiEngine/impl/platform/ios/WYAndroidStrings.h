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
 * @class WYAndroidStrings
 *
 * 解析Android的strings.xml文件, 用来支持将Android中的字符串资源id映射到一个字符串.
 * 这个类是为了方便重用Android原始文件而设计, 如果游戏一开始就是iOS版本, 则无必要使用
 * 该类.
 */
@interface WYAndroidStrings : NSObject<NSXMLParserDelegate> {
@private
	/// 保存strings.xml中的字符串映射, key是语言代码, value是NSMutableDictionary
	NSMutableDictionary* m_strings;
	
	/// 保存字符串唯一的key列表, 排序过的
	NSMutableArray* m_keyList;
	
	/// true表示key列表需要被重新排序
	BOOL m_keyListDirty;
	
	/// 用来确保key唯一的hash
	NSMutableDictionary* m_keyMap;
	
	/// true indicating parsing string tag
	BOOL m_inStringTag;
	
	/// current string name
	NSString* m_stringKey;
	
	/// current string
	NSMutableString* m_stringBuf;
	
	/// current dictionary
	NSMutableDictionary* m_tmpDict;
}

/// 得到共享实例
+ (WYAndroidStrings*)sharedInstance;

/// 释放共享实例
+ (void)destroy;

/**
 * 添加一种语言的字符串映射
 * 
 * @param file Android的字符串描述文件在iOS应用下的相对路径, 带或者不带xml扩展名都可以
 * @param lan 该字符串文件对应的语言代码, 为两字符代码, 比如en, zh
 */
- (void)addStrings:(NSString*)file forLanguage:(NSString*)lan;

/**
 * 打印指定语言的所有字符串, 调试用
 *
 * @param lan 打印的字符串对应的语言
 */
- (void)print:(NSString*)lan;

/**
 * 根据字符串键值获得字符串. 会根据当前系统语言进行查找, 如果没有找到, 会查找英文字符串, 如果英文字符串也没有
 * 找到, 返回nil
 * 
 * @param key 字符串键值
 * @return 字符串
 */
- (NSString*)getString:(NSString*)key;

/**
 * 得到一个字符串键值排序后的索引
 *
 * @param key 字符串键值
 * @return 键值在排序后的键值列表中的索引
 */
- (int)getKeyIndex:(NSString*)key;

/**
 * 根据字符串键值索引得到字符串键
 *
 * @param index 键值索引, 可以通过getKeyIndex得到
 * @return 字符串键值, 如果索引超出范围, 则返回nil
 */
- (NSString*)getKey:(int)index;

@end

#endif // #if IOS
