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
 * @class WYResMap
 *
 * \par
 * 用来将iOS应用中的资源文件映射成为一个整数id, 这样为了android编写的WiEngine应用可以更
 * 方便的进行移植. 假设一个资源的id在android中是R.drawable.image, 那么WYResMap会在应用
 * 的drawable目录下搜索
 *
 * \par
 * 寻找image时是忽略扩展名的, 所以如果在同一个目录有名称相同但是扩展名相同的文件是不行的. 
 * 如果找到对应文件, 则返回一个代表文件的唯一id
 * 
 * \par
 * WYResMap也负责映射原来存放在assets或者文件系统中的文件, 对于原来存放在assets下的资源文件,
 * 在移植到iOS平台时, 直接把资源文件放在app/assets下就可以, 这样原来的代码不需要修改
 *
 * \par
 * 如果是文件系统中的文件, WYResMap会在app的documents目录下寻找, 假如原来的文件系统路径是
 * /sdcard/test.png, 则WYResMap会尝试寻找~/Documents/sdcard/test.png文件. 这里的~指向的
 * 是应用沙箱位置
 */
@interface WYResMap : NSObject {
@private
	/// app目录下的所有文件列表
	NSMutableArray* m_fileList;
	
	/// app目录下的文件和id映射表, key是文件路径, value是资源id
	NSMutableDictionary* m_resMap;
}

/**
 * 获得WYResMap的共享实例
 * 
 * @return \link WYResMap WYResMap\endlink
 */
+ (WYResMap*)sharedMap;

/**
 * 销毁WYResMap的共享实例
 */
+ (void)destroy;

/**
 * 通过资源id得到文件相对于应用的路径
 *
 * @param resId 资源id
 * @return 文件的完整路径, 如果没有, 返回nil
 */
- (NSString*)getResFilePath:(int)resId;

/**
 * 通过资源id得到文件相对于应用的路径
 *
 * @param resId 资源id
 * @return 文件相对于应用的路径, 如果没有找到, 返回nil
 */
- (NSString*)getResRelativeFilePath:(int)resId;

/**
 * 把一个资源id字符串映射成资源id
 * 
 * @param resIdString 资源id字符串, 比如"R.drawable.test"
 * @return 资源id, 以后可以通过这个id取得文件路径, 如果映射失败, 返回-1
 */
- (int)getResId:(NSString*)resIdString;

/**
 * 把原来在Android中的一个assets下的资源文件路径映射到iOS下的资源文件路径, 例如
 * 原来的assets路径是folder/test.png, 那么WYResMap会首先寻找~/[app目录]/test.png, 其次
 * 再找~/[app目录]/assets/folder/test.png.
 * 
 * @param asset 原来的Android下的assets资源路径
 * @return 映射后的iOS资源文件的完整路径
 */
- (NSString*)getAssetFilePath:(NSString*)asset;

/**
 * 把原来在Android中的一个assets下的资源文件路径映射到iOS下的资源文件路径, 例如
 * 原来的assets路径是folder/test.png, 那么WYResMap会首先寻找~/[app目录]/test.png, 其次
 * 再找~/[app目录]/assets/folder/test.png.
 * 
 * @param asset 原来的Android下的assets资源路径
 * @return 映射后的iOS资源文件相对于app的路径, 如果没有找到匹配的, 则返回nil
 */
- (NSString*)getAssetRelativeFilePath:(NSString*)asset;

/**
 * 把原来在Android文件系统中的一个文件路径映射成为app沙箱路径, 应用会在~/Documents下寻找匹配的
 * 文件
 *
 * @param path Android文件系统路径
 * @return 在app沙箱中的路径, 返回的路径是一个绝对路径, 如果找不到匹配文件, 返回nil
 */
- (NSString*)getLocalFilePath:(NSString*)path;

/**
 * 把原来在Android文件系统中的一个文件路径映射成为app沙箱路径, 应用会在~/Documents下寻找匹配的
 * 文件
 *
 * @param path Android文件系统路径
 * @param flag YES表示检查映射后的文件路径是否存在，false表示不检查。
 * @return 在app沙箱中的路径, 返回的路径是一个绝对路径, 如果flag是YES并且映射后的文件路径不存在，则返回nil
 */
- (NSString*)getLocalFilePath:(NSString *)path checkExistence:(BOOL)flag;

@end

#endif // #if IOS
