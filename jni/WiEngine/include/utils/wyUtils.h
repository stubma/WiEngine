/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyUtils_h__
#define __wyUtils_h__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "wyTypes.h"
#include "wyRunnable.h"
#include "wyHashSet.h"
#include "wyMath.h"
#include "wyTexture2D.h"
#include "wyCharProvider.h"
#include "wyAction.h"

struct wyBezierConfig;
struct wyLagrangeConfig;
struct wyQuad2D;
struct wyQuad3D;
struct wyColor4B;
struct wyRect;
struct wyAffineTransform;
struct wyPoint;
struct wyKeyEvent;
struct wyMotionEvent;
class wyEventDispatcher;

// for easy of use
#define DP(x) wyUtils::resolveDp((x))
#define DIP(x) DP(x)
#define PX(x) wyUtils::resolvePx((x))
#define SP(x) wyUtils::resolveSp((x))
#define RES(x) wyUtils::getResId((x))
#define STR(x) wyUtils::getString((x))
#define S8(x) STR(x)
#define STR16(x) wyUtils::getString16((x))
#define S16(x) STR16(x)

/**
 * @class wyUtils
 *
 * \if English
 * utility class which provides many static helper methods
 * \else
 * 工具类, 都是静态方法
 * \endif
 */
class WIENGINE_API wyUtils {
	friend class wyEventDispatcher;

private:
	/**
	 * Decode an obfuscated data, if no resource obfuscator installed, just
	 * return the incoming data
	 *
	 * @param data encoded data
	 * @param length data length
	 * @param outLen it holds length of decoded data
	 * @return decoded data or \c data if no decoder installed
	 */
	static const char* decodeObfuscatedData(const char* data, size_t length, size_t* outLen);

	/**
	 * \if English
	 * Grab current opengl frame and save it in a jpeg file. Saving may be a little
	 * slow so it is developer's responsibility to show some hint to user. It uses opengl
	 * api to grab screen and the api may not exist in low version Android. Meanwhile it needs
	 * sd card permission because screenshot is saved in external storage.
	 *
	 * @param path the path to save screenshot, and WiEngine creates all intermediate folders if it doesn't
	 * 		exist. If path is NULL, nothing will be saved. The path will be mapped if not Android platform
	 * \else
	 * 抓取当前帧, 保存为jpg(jpeg)图片. 这个方法会将图片保存到指定路径，由于牵涉到文件
	 * 写操作, 因此速度较慢, 另外使用的OpenGL接口可能在低版本Android系统上没有
	 * 实现. 如果保存的路径在sd卡上, 则应用需要有写sd卡的权限.
	 *
	 * @param path 截图保存的目标路径, 如果指定的路径不存在, 则会自动创建目录. 如果为NULL, 则不做任何事.
	 * 		这个路径在非Android系统上会被映射. jpg保存可以用jpg,jpeg两种后缀
	 * \endif
	 */
	static void makeScreenshotJPG(const char* path);

	/**
	 * \if English
	 * Grab current opengl frame and save it in a jpeg file. Saving may be a little
	 * slow so it is developer's responsibility to show some hint to user. It uses opengl
	 * api to grab screen and the api may not exist in low version Android. Meanwhile it needs
	 * sd card permission because screenshot is saved in external storage.
	 *
	 * @param path the path to save screenshot, and WiEngine creates all intermediate folders if it doesn't
	 * 		exist. If path is NULL, nothing will be saved. The path will be mapped if not Android platform
	 * @param rect screen rect to be shot
	 * \else
	 * 抓取当前帧, 保存为jpg(jpeg)图片. 这个方法会将图片保存到指定路径，由于牵涉到文件
	 * 写操作, 因此速度较慢, 另外使用的OpenGL接口可能在低版本Android系统上没有
	 * 实现. 如果保存的路径在sd卡上, 则应用需要有写sd卡的权限.
	 *
	 * @param path 截图保存的目标路径, 如果指定的路径不存在, 则会自动创建目录. 如果为NULL, 则不做任何事.
	 * 		这个路径在非Android系统上会被映射. jpg保存可以用jpg,jpeg两种后缀
	 * @param rect 需要截取的屏幕矩形范围
	 * \endif
	 */
	static void makeScreenshotJPG(const char* path, wyRect rect);

	/**
	 * \if English
	 * Grab current opengl frame and save it in a png file. Saving may be a little
	 * slow so it is developer's responsibility to show some hint to user. It uses opengl
	 * api to grab screen and the api may not exist in low version Android. Meanwhile it needs
	 * sd card permission because screenshot is saved in external storage.
	 *
	 * @param path the path to save screenshot, and WiEngine creates all intermediate folders if it doesn't
	 * 		exist. If path is NULL, nothing will be saved. The path will be mapped if not Android platform
	 * \else
	 * 抓取当前帧, 保存为png图片. 这个方法会将图片保存到指定路径，由于牵涉到文件
	 * 写操作, 因此速度较慢, 另外使用的OpenGL接口可能在低版本Android系统上没有
	 * 实现. 如果保存的路径在sd卡上, 则应用需要有写sd卡的权限.
	 *
	 * @param path 截图保存的目标路径, 如果指定的路径不存在, 则会自动创建目录. 如果为NULL, 则不做任何事.
	 * 		这个路径在非Android系统上会被映射, 方法本身不会针对平台做路径映射.
	 * \endif
	 */
	static void makeScreenshotPNG(const char* path);

	/**
	 * \if English
	 * Grab current opengl frame and save it in a png file. Saving may be a little
	 * slow so it is developer's responsibility to show some hint to user. It uses opengl
	 * api to grab screen and the api may not exist in low version Android. Meanwhile it needs
	 * sd card permission because screenshot is saved in external storage.
	 *
	 * @param path the path to save screenshot, and WiEngine creates all intermediate folders if it doesn't
	 * 		exist. If path is NULL, nothing will be saved. The path will be mapped if not Android platform
	 * @param rect screen rect to be shot
	 * \else
	 * 抓取当前帧, 保存为png图片. 这个方法会将图片保存到指定路径，由于牵涉到文件
	 * 写操作, 因此速度较慢, 另外使用的OpenGL接口可能在低版本Android系统上没有
	 * 实现. 如果保存的路径在sd卡上, 则应用需要有写sd卡的权限.
	 *
	 * @param path 截图保存的目标路径, 如果指定的路径不存在, 则会自动创建目录. 如果为NULL, 则不做任何事.
	 * 		这个路径在非Android系统上会被映射, 方法本身不会针对平台做路径映射.
	 * @param rect 需要截取的屏幕矩形范围
	 * \endif
	 */
	static void makeScreenshotPNG(const char* path, wyRect rect);

	/**
	 * \if English
	 * inflate a zip content
	 *
	 * @param in zipped data
	 * @param inLength length of zipped data
	 * @param out inflated data buffer
	 * @param outLength a pointer to an integer to hold the length of inflated data
	 * \else
	 * 解压，内部调用
	 *
	 * @param in 输入的压缩过的数据
	 * @param inLength 压缩数据长度
	 * @param out 输出缓冲区指针
	 * @param outLength 整数指针，用于返回解压后的数据长度
	 * \endif
	 */
	static size_t internal_gunzip(char* in, size_t inLength, char** out, size_t* outLength);

	/**
	 * \if English
	 * Convert KeyEvent java object to \link wyKeyEvent wyKeyEvent\endlink structure
	 *
	 * @param pe platform-dependent key event object
	 * @param event to save converted \link wyKeyEvent wyKeyEvent\endlink structure
	 * \else
	 * 把java的KeyEvent对象中的数据转换成\link wyKeyEvent wyKeyEvent结构\endlink
	 *
	 * @param pe 平台相关的按键事件对象
	 * @param event 保存数据的\link wyKeyEvent wyKeyEvent结构\endlink 指针
	 * \endif
	 */
	static void convertKeyEvent(wyPlatformKeyEvent pe, wyKeyEvent* event);

	/**
	 * \if English
	 * Convert java MotionEvent object to \link wyMotionEvent wyMotionEvent\endlink structure
	 *
	 * @param pe platform-dependent event object, for Android it is MotionEvent, for iOS it is UIEvent
	 * @param event to save converted \link wyMotionEvent wyMotionEvent\endlink structure
	 * @param type event type, optional
	 * \else
	 * 把java的MotionEvent对象转换成\link wyMotionEvent wyMotionEvent结构\endlink
	 *
	 * @param pe 平台相关的事件对象, 对Android来说是java端的MotionEvent对象, 对iOS则是UIEvent对象
	 * @param event 保存数据的\link wyMotionEvent wyMotionEvent结构\endlink 指针
	 * @param type 相关的事件类型
	 * \endif
	 */
	static void convertMotionEvent(wyPlatformMotionEvent pe, wyMotionEvent* event, int type = 0);

	/**
	 * Get index of last slash character, if not found, returns -1
	 */
	static ssize_t lastSlashIndex(const char* path);

	/**
	 * Get index of last dot character, if not found, returns -1
	 */
	static ssize_t lastDotIndex(const char* path);

public:
	
	/*
	 * resource related operations
	 */

	/**
	 * \if English
	 * Get resource id by resource name and type
	 *
	 * @param name resource name
	 * @param type resource type
	 * @param type2 fallback type, if \c type is not found, will search type2
	 * @return resource id
	 * \else
	 * 通过资源名称和资源类型名得到资源id
	 *
	 * @param name 资源名称
	 * @param type 资源类型名
	 * @param type2 资源的其他类型名, 如果在type指定的资源中没有找到，会再尝试在type2中寻找
	 * @return 资源id
	 * \endif
	 */
	static int getResId(const char* name, const char* type, const char* type2);

	/**
	 * \if English
	 * Get resource id from resource full name, such as R.drawable.abc
	 *
	 * @param fullName full name of resource
	 * @return resource id
	 * \else
	 * 通过资源全名获得资源id. 全名指的是"R.drawable.abc"这样的名称.
	 *
	 * @param fullName 资源全名
	 * @return 资源id
	 * \endif
	 */
	static int getResId(const char* fullName);

	/**
	 * \if English
	 * Is a resource existent or not
	 *
	 * @param path file path of resource file
	 * @param isFile true means \c path is an absolute path in file system, or false
	 * 		means \c path is a relative path under assets
	 * @return true means this resource can be opened
	 * \else
	 * 判断一个资源文件是否存在
	 *
	 * @param path 资源文件的路径
	 * @param isFile true表示\c path是一个文件系统的绝对路径, false表示\c path是一个assets下的相对路径
	 * @return true表示资源文件存在
	 * \endif
	 */
	static bool isResExistent(const char* path, bool isFile);

	/**
	 * \if English
	 * Get string from string full resource name, such as R.string.abc
	 *
	 * @param fullName string resource full name
	 * @return string, caller should release it
	 * \else
	 * 通过资源全名获得字符串，全名指的是"R.string.abc"这样的名称
	 *
	 * @param fullName 资源全名
	 * @return 字符串，调用者需要负责释放这个字符串
	 * \endif
	 */
	static const char* getString(const char* fullName);

	/**
	 * \if English
	 * Get string from resource id
	 *
	 * @param resId id of string resource
	 * @return string, caller should release it
	 * \else
	 * 通过资源id获得字符串
	 *
	 * @param resId 字符串资源id
	 * @return 字符串，调用者需要负责释放这个字符串
	 * \endif
	 */
	static const char* getString(int resId);

	/**
	 * \if English
	 * Get utf-16 string from resource full name
	 *
	 * @param fullName string resource full name
	 * @return string in utf-16 encoding, caller should release it
	 * \else
	 * 通过资源全名获得UNICODE格式字符串，全名指的是"R.string.abc"这样的名称
	 *
	 * @param fullName 资源全名
	 * @return 字符串，调用者需要负责释放这个字符串
	 * \endif
	 */
	static const char16_t* getString16(const char* fullName);

	/**
	 * \if English
	 * Get utf-16 string from string resource id
	 *
	 * @param resId string resource id
	 * @return string in utf-16 encoding, caller should release it
	 * \else
	 * 通过资源id获得UNICODE格式字符串
	 *
	 * @param resId 字符串资源id
	 * @return 字符串，调用者需要负责释放这个字符串
	 * \endif
	 */
	static const char16_t* getString16(int resId);
	
	/**
	 * \if English
	 * Load bmp RGBA8888 data from bmp resource id
	 *
	 * @param resId resource id of bmp file
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从资源文件中载入bmp图片
	 *
	 * @param resId bmp图片资源id
	 * @param w 保存png图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存png图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得bmp图片大小, 不解析bmp图片数据
	 * @return 经过解析后的png图片数据, RGBA8888格式, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadBMP(int resId, size_t* w, size_t* h, bool sizeOnly);

	/**
	 * \if English
	 * Load bmp RGBA8888 data from memory bmp data
	 *
	 * @param data bmp file data in memory
	 * @param length \c data length
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从内存的数组中载入bmp图片
	 *
	 * @param data bmp文件的字节数组, 这必须是bmp文件的原始文件数据，即未经任何解码的bmp文件数据
	 * @param length data的长度
	 * @param w 保存bmp图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存bmp图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得bmp图片大小, 不解析bmp图片数据
	 * @param scaleX 缺省的X缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @param scaleY 缺省的Y缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 经过解析后的bmp图片数据, RGBA8888格式, 如果sizeOnly是true, 则返回NULL
	 * \endif
	 */
	static char* loadBMP(const char* data, size_t length, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * \if English
	 * Load BMP RGBA8888 data from a C file pointer, it will close file pointer when done
	 *
	 * @param f C FILE pointer
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从一个标准FILE指针中读取BMP图片，这个方法会负责关闭文件
	 *
	 * @param f FILE指针
	 * @param w 保存BMP图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存BMP图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得BMP图片大小, 不解析BMP图片数据
	 * @param scaleX 缺省的X缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @param scaleY 缺省的Y缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 适合于创建OpenGL贴图的数据, 如果sizeOnly是true, 则返回NULL, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadBMP(FILE* f, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * \if English
	 * Load BMP RGBA8888 data from assets or file system
	 *
	 * @param path BMP file path
	 * @param isFile true indicating \c path is an absolute path in file system, false if \c path is a relative path under assets
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从文件系统或者asset中载入png图片
	 *
	 * @param path BMP图片的路径
	 * @param isFile true表示这是一个文件系统上的文件, false表示这是一个asset中的文件
	 * @param w 保存BMP图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存BMP图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得BMP图片大小, 不解析BMP图片数据
	 * @param scaleX 缺省的X缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @param scaleY 缺省的Y缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 适合于创建OpenGL贴图的数据, 如果sizeOnly是true, 则返回NULL, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadBMP(const char* path, bool isFile, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * \if English
	 * Load png RGBA8888 data from png resource id
	 *
	 * @param resId resource id of png file
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从资源文件中载入png图片
	 *
	 * @param resId png图片资源id
	 * @param w 保存png图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存png图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得png图片大小, 不解析png图片数据
	 * @return 经过解析后的png图片数据, RGBA8888格式, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadPNG(int resId, size_t* w, size_t* h, bool sizeOnly);

	/**
	 * \if English
	 * Load png RGBA8888 data from memory png data
	 *
	 * @param data png file data in memory
	 * @param length \c data length
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从内存的数组中载入png图片
	 *
	 * @param data png文件的字节数组, 这必须是png文件的原始文件数据，即未经任何解码的png文件数据
	 * @param length data的长度
	 * @param w 保存png图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存png图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得png图片大小, 不解析png图片数据
	 * @param scaleX 缺省的X缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @param scaleY 缺省的Y缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 经过解析后的png图片数据, RGBA8888格式, 如果sizeOnly是true, 则返回NULL
	 * \endif
	 */
	static char* loadPNG(const char* data, size_t length, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * \if English
	 * Load png RGBA8888 data from a C file pointer, it will close file pointer when done
	 *
	 * @param f C FILE pointer
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从一个标准FILE指针中读取png图片，这个方法会负责关闭文件
	 *
	 * @param f FILE指针
	 * @param w 保存png图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存png图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得png图片大小, 不解析png图片数据
	 * @param scaleX 缺省的X缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @param scaleY 缺省的Y缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 适合于创建OpenGL贴图的数据, 如果sizeOnly是true, 则返回NULL, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadPNG(FILE* f, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * \if English
	 * Load png RGBA8888 data from assets or file system
	 *
	 * @param path png file path
	 * @param isFile true indicating \c path is an absolute path in file system, false if \c path is a relative path under assets
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从文件系统或者asset中载入png图片
	 *
	 * @param path png图片的路径
	 * @param isFile true表示这是一个文件系统上的文件, false表示这是一个asset中的文件
	 * @param w 保存png图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存png图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得png图片大小, 不解析png图片数据
	 * @param scaleX 缺省的X缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @param scaleY 缺省的Y缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 适合于创建OpenGL贴图的数据, 如果sizeOnly是true, 则返回NULL, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadPNG(const char* path, bool isFile, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * \if English
	 * Load jpg RGBA8888 data from C file pointer, it will close file pointer when done
	 *
	 * @param f C file pointer
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从一个标准FILE指针中读取jpg图片，这个方法会负责关闭文件
	 *
	 * @param f FILE指针
	 * @param w 保存png图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存png图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得png图片大小, 不解析png图片数据
	 * @param scaleX 缺省的X缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @param scaleY 缺省的Y缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 适合于创建OpenGL贴图的数据, 如果sizeOnly是true, 则返回NULL, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadJPG(FILE* f, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * \if English
	 * Load jpg RGBA8888 data from assets or file system
	 *
	 * @param path jpg file path
	 * @param isFile true indicating \c path is an absolute path in file system, false if \c path is a relative path under assets
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从文件系统或者asset中载入jpg图片
	 *
	 * @param path jpg图片的路径
	 * @param isFile true表示这是一个文件系统上的文件, false表示这是一个asset中的文件
	 * @param w 保存jpg图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存jpg图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得jpg图片大小, 不解析jpg图片数据
	 * @param scaleX 缺省的X缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @param scaleY 缺省的Y缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 适合于创建OpenGL贴图的数据, 如果sizeOnly是true, 则返回NULL, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadJPG(const char* path, bool isFile, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * \if English
	 * Load jpg RGBA8888 data from memory png data
	 *
	 * @param data jpg file data in memory
	 * @param length \c data length
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从内存的数组中载入jpg图片
	 *
	 * @param data jpg文件的字节数组, 这必须是jpg文件的原始文件数据，即未经任何解码的jpg文件数据
	 * @param length data的长度
	 * @param w 保存jpg图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存jpg图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得jpg图片大小, 不解析jpg图片数据
	 * @param scaleX 缺省的X缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @param scaleY 缺省的Y缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 经过解析后的jpg图片数据, RGBA8888格式, 如果sizeOnly是true, 则返回NULL, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadJPG(const char* data, size_t length, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * \if English
	 * Load jpg RGBA8888 data from jpg resource id
	 *
	 * @param resId resource id of jpg file
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从资源文件中载入jpg图片
	 *
	 * @param resId jpg图片资源id
	 * @param w 保存jpg图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存jpg图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得jpg图片大小, 不解析jpg图片数据
	 * @return 经过解析后的jpg图片数据, RGBA8888格式, 如果sizeOnly是true, 则返回NULL
	 * \endif
	 */
	static char* loadJPG(int resId, size_t* w, size_t* h, bool sizeOnly);
	
	/**
	 * \if English
	 * Load raw data from a C file pointer, it will close file pointer when done
	 *
	 * @param f C file pointer
	 * @param outLen length of data finally returned
	 * @param noDecode true means don't decode even if the data is encoded
	 * @return read data, caller should release it
	 * \else
	 * 从某个FILE指针中读取所有内容, 读取完成后会关闭文件指针
	 *
	 * @param f 文件的FILE指针
	 * @param outLen 最后返回的数据长度
	 * @param noDecode true表示不管数据有没有被编码, 反正不执行解码操作
	 * @return 文件数据, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadRaw(FILE* f, size_t* outLen, bool noDecode = false);

	/**
	 * \if English
	 * Load raw data from assets or file system
	 *
	 * @param path file path
	 * @param isFile true indicating \c path is an absolute path in file system, false if \c path is a relative path under assets
	 * @param outLen optional, returns file length
	 * @param noDecode true means don't decode even if the data is encoded
	 * @return raw data of file, caller should release it
	 * \else
	 * 载入文件系统或者asset中某个文件的内容
	 *
	 * @param path 文件在文件系统中的路径
	 * @param isFile true表示path是一个文件系统路径
	 * @param outLen 可选参数, 如果不为NULL, 将返回文件总长度
	 * @param noDecode true表示不管数据有没有被编码, 反正不执行解码操作
	 * @return 文件数据, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadRaw(const char* path, bool isFile, size_t* outLen = NULL, bool noDecode = false);

	/**
	 * \if English
	 * Load raw data of a resource file
	 *
	 * @param resId resource id
	 * @param outLen optional, returns file length
	 * @param outScale optional, returns scale of resource
	 * @param noDecode true means don't decode even if the data is encoded
	 * @return raw data, caller should release it
	 * \else
	 * 载入资源文件的raw数据
	 *
	 * @param resId 资源id
	 * @param outLen 可选参数, 如果不为NULL, 将返回文件总长度
	 * @param outScale 可选参数，如果不为NULL，将返回这个资源的scale。例如：如果资源存放在有hdpi后缀的文件夹里，
	 * 		则outScale会返回1.5
	 * @param noDecode true表示不管数据有没有被编码, 反正不执行解码操作
	 * @return 文件数据, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadRaw(int resId, size_t* outLen = NULL, float* outScale = NULL, bool noDecode = false);

	/**
	 * \if English
	 * Load a C string from resource id, null terminator is appended automatically.
	 * This resource must be a plain text resource.
	 *
	 * @param resId resource id
	 * @return raw data followed a null terminator so it is a C string. Caller should release it.
	 * \else
	 * 从资源文件中读取一个0结尾字符串, 0是由方法自动
	 * 追加的. 这个资源文件必须是一个纯文本文件
	 *
	 * @param resId 资源id
	 * @return 未经处理的原始数据, 结尾跟一个0字节, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadCString(int resId);

	/**
	 * \if English
	 * Load a C string from assets or file system, null terminator is appended automatically.
	 * This file must be a plain text resource.
	 *
	 * @param path file path
	 * @param isFile true indicating \c path is an absolute path in file system, false if \c path is a relative path under assets
	 * @return raw data followed a null terminator so it is a C string. Caller should release it.
	 * \else
	 * 从文件系统或者asset中载入一个c字符串.
	 *
	 * @param path 文件路径, 必须是一个纯文本文件
	 * @param isFile true表示path是一个文件系统路径, false表示是一个asset下的路径
	 * @return 未经处理的原始数据, 结尾跟一个0字节, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadCString(const char* path, bool isFile);

	/**
	 * \if English
	 * Get size of PVR image
	 *
	 * @param data PVR image data
	 * @param length \c data length
	 * @param w returns width of PVR, NULL if you don't care
	 * @param h returns height of PVR, NULL if you don't care
	 * @param scale scale rate, 1 for no scale
	 * @return true means successful, or false if failed
	 * \else
	 * 得到PVR图片的大小
	 *
	 * @param data PVR数据数组
	 * @param length PVR数据数组长度
	 * @param w 保存pvr图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存pvr图片高度的指针, 为NULL则不返回高度
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return true表示获得大小成功, false表示失败
	 * \endif
	 */
	static bool getPVRSize(const char* data, size_t length, size_t* w, size_t* h, float scale);

	/**
	 * \if English
	 * Get size of PVR image
	 *
	 * @param resId resource id of PVR file
	 * @param w returns width of PVR, NULL if you don't care
	 * @param h returns height of PVR, NULL if you don't care
	 * @param outScale returns scale of PVR resource, decided from resource density
	 * @return true means successful, or false if failed
	 * \else
	 * 得到PVR图片的大小
	 *
	 * @param resId pvr图片资源id
	 * @param w 保存pvr图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存pvr图片高度的指针, 为NULL则不返回高度
	 * @param outScale 用于返回缩放比例，这个比例从资源的density中获得，如果资源的density
	 * 		是160, 而当前屏幕是hdpi(即240)，则scale会等于1.5. 这个参数一般只对图片有用，
	 * 		如果不需要，可以传NULL
	 * @return true表示获得大小成功, false表示失败
	 * \endif
	 */
	static bool getPVRSize(int resId, size_t* w, size_t* h, float* outScale);

	/**
	 * \if English
	 * Get size of PVR image
	 *
	 * @param f C file pointer
	 * @param w returns width of PVR, NULL if you don't care
	 * @param h returns height of PVR, NULL if you don't care
	 * @param scale scale rate, 1 for no scale
	 * @return true means successful, or false if failed
	 * \else
	 * 得到PVR图片的大小
	 *
	 * @param f pvr文件的FILE指针
	 * @param w 保存pvr图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存pvr图片高度的指针, 为NULL则不返回高度
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return true表示获得大小成功, false表示失败
	 * \endif
	 */
	static bool getPVRSize(FILE* f, size_t* w, size_t* h, float scale);

	/**
	 * \if English
	 * Get size of PVR image
	 *
	 * @param path file path
	 * @param isFile true indicating \c path is an absolute path in file system, false if \c path is a relative path under assets
	 * @param w returns width of PVR, NULL if you don't care
	 * @param h returns height of PVR, NULL if you don't care
	 * @param scale scale rate, 1 for no scale
	 * @return true means successful, or false if failed
	 * \else
	 * 得到PVR图片的大小
	 *
	 * @param path pvr文件在文件系统或者asset中的路径
	 * @param isFile true表示path是一个文件系统路径
	 * @param w 保存pvr图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存pvr图片高度的指针, 为NULL则不返回高度
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return true表示获得大小成功, false表示失败
	 * \endif
	 */
	static bool getPVRSize(const char* path, bool isFile, size_t* w, size_t* h, float scale);
	
	/**
	 * \if English
	 * Convert byte order of PVR header. It is little endian but we need host endian
	 *
	 * @param header \link wyPVRHeader wyPVRHeader\endlink
	 * \else
	 * PVR头部的字段是little endian的, 这个方法把它们转换为host endian
	 *
	 * @param header \link wyPVRHeader wyPVRHeader\endlink
	 * \endif
	 */
	static void convertPVRHeaderEndian(wyPVRHeader* header);

	/**
	 * \if English
	 * Unpack PVR data
	 *
	 * @param data PVR raw data
	 * @param header \link wyPVRHeader wyPVRHeader\endlink
	 * @param mipmapLens contains length of every mipmap
	 * @param pvrFormatIndex PVR file format index in gPVRFormats array
	 * @param hasAlpha returns flag about PVR alpha channel existence
	 * @return PVR data array for every mipmap
	 * \else
	 * 解压PVR原始数据
	 *
	 * @param data PVR的原始数据
	 * @param header \link wyPVRHeader wyPVRHeader\endlink
	 * @param mipmapLens 返回PVR中每个mipmap图片数据的长度
	 * @param pvrFormatIndex 用来返回PVR文件的格式, 这个索引是gPVRFormats数组中的索引
	 * @param hasAlpha 用来返回PVR是否有alpha通道
	 * @return PVR图像数据， 这是一个二级指针， 包含了所有mipmap的数据
	 * \endif
	 */
	static char** unpackPVRData(char* data, wyPVRHeader* header, int** mipmapLens, int* pvrFormatIndex, bool* hasAlpha);

	/**
	 * \if English
	 * Scale PVR image
	 *
	 * @param format PVR file format
	 * @param originData image data
	 * @param originWidth width of image
	 * @param originHeight height of image
	 * @param scale scale rate
	 * @return scaled data
	 * \else
	 * 缩放PVR图片
	 *
	 * @param format PVR文件格式
	 * @param originData PVR原始数据
	 * @param originWidth PVR原始宽度
	 * @param originHeight PVR与原始高度
	 * @param scale 缩放比例
	 * @return 缩放后的图片数据
	 * \endif
	 */
	static char* scalePVR(wyPVRFormat format, char* originData, int originWidth, int originHeight, float scale);

	/**
	 * \if English
	 * Check whether a PVR image can be scaled by WiEngine
	 *
	 * @param format PVR format
	 * @return true means we can do that
	 * \else
	 * 检查PVR格式是否可以被自动拉伸
	 *
	 * @param format PVR格式常量
	 * @return true表示PVR可以根据屏幕分辨率自动拉伸
	 * \endif
	 */
	static bool canScalePVR(wyPVRFormat format);

	/**
	 * \if English
	 * Scale an image
	 *
	 * @param originData original RGBA8888 data of image
	 * @param originWidth original width of image
	 * @param originHeight original height of image
	 * @param scaleX x scale, 1 for no x scale
	 * @param scaleY y scale, 1 for no y scale
	 * @return scaled data, may be same as \c originData if no scale, if not same, then caller should release originData
	 * \else
	 * 缩放一个图片
	 *
	 * @param originData 图像的原始RGBA8888数据
	 * @param originWidth 图像原始宽度
	 * @param originHeight 图像原始告诉
	 * @param scaleX x方向的缩放比例
	 * @param scaleY y方向的缩放比例
	 * @return 缩放后的图像RGBA8888数据, 如果不需要缩放则和\c originData一样, 如果不一样, 则调用者要负责释放originData
	 * \endif
	 */
	static char* scaleImage(char* originData, int originWidth, int originHeight, float scaleX, float scaleY);

	/*
	 * Event related operations
	 */
	
	/**
	 * \if English
	 * Convert point from Android coordinate system to OpenGL coordinate system
	 *
	 * @param p \link wyPoint wyPoint\endlink structure to be converted
	 * \else
	 * 把坐标从Android坐标系转换到OpenGL坐标系
	 *
	 * @param p \link wyPoint wyPoint结构\endlink 指针
	 * \endif
	 */
	static void convertToGL(wyPoint* p);
	
	/**
	 * \if English
	 * Convert point from Android coordinate system to OpenGL coordinate system
	 *
	 * @param x x position
	 * @param y y position
	 * \else
	 * 把坐标从Android坐标系转换到OpenGL坐标系
	 *
	 * @param x 坐标x值指针
	 * @param y 坐标y值指针
	 * \endif
	 */
	static void convertToGL(float* x, float* y);

	/*
	 * time helper
	 */

	/**
	 * \if English
	 * Get milliseconds from 1970-1-1
	 *
	 * @return milliseconds from 1970-1-1
	 * \else
	 * 得到当前时间距离1970年1月1日的毫秒数
	 *
	 * @return 当前时间距离1970年1月1日的毫秒数
	 * \endif
	 */
	static int64_t currentTimeMillis();

	/*
	 * Array helper
	 */

	/**
	 * \if English
	 * Swap two elements in a float array
	 *
	 * @param f pointer of float array
	 * @param index1 index of element 1
	 * @param index2 index of element 2
	 * \else
	 * 交换浮点数组中的两个元素
	 *
	 * @param f 浮点数组指针
	 * @param index1 元素1位置
	 * @param index2 元素2位置
	 * \endif
	 */
	static void swap(float* f, int index1, int index2);

	/**
	 * \if English
	 * Swap two integers
	 *
	 * @param a pointer of integer 1
	 * @param b pointer of integer 2
	 * \else
	 * 整数值交换
	 *
	 * @param a 整数a的指针
	 * @param b 整数b的指针
	 * \endif
	 */
	static void swap(int* a, int* b);

	/**
	 * \if English
	 * Do a binary search in an integer array
	 *
	 * @param a pointer to integer array
	 * @param len length of array
	 * @param key number to be found
	 * @return if found, returns index, if not, returns a negative value whose absolute value minus 1 equals to
	 * 		insertion point
	 * \else
	 * 在整数数组中进行二分查找
	 *
	 * @param a 整数数组指针
	 * @param len 数组长度
	 * @param key 要查找的整数
	 * @return 如果找到了，返回索引位置，如果没有找到，将返回值取绝对值再减1就是插入位置
	 * \endif
	 */
	static int binarySearch(int* a, size_t len, int key);

	/*
	 * encode/decode support
	 */

	/**
	 * \if English
	 * Base64 encoder
	 *
	 * @param src source
	 * @param len length of \c src
	 * @param out_len returns length of encoded content
	 * @return data of encoded
	 * \else
	 * 编码base64
	 *
	 * @param src 原文内容
	 * @param len 数组长度
	 * @param out_len 用来返回编码后的长度
	 * @return base64解码的数组
	 * \endif
	 */
	static char* encodeBase64(const char* src, size_t len, size_t* out_len);

	/**
	 * \if English
	 * Decode base64 content
	 *
	 * @param enc data of encoded
	 * @param length length of \c enc
	 * @param retLen returns length of decoded content
	 * @return data of decoded
	 * \else
	 * 解码base64
	 *
	 * @param enc base64编码的数组
	 * @param length 数组长度
	 * @param retLen 用来返回解码后的长度
	 * @return 解码后的数组指针
	 * \endif
	 */
	static char* decodeBase64(const char* enc, size_t length, size_t* retLen);

	/**
	 * \if English
	 * Unzip
	 *
	 * @param in data of zipped
	 * @param inLength length of \c in
	 * @param out hold bytes of unzipped content
	 * @return length of unzipped content
	 * \else
	 * 解压
	 *
	 * @param in 保存压缩数据的数组
	 * @param inLength 数组长度
	 * @param out 用来返回解压数据的缓冲区指针
	 * @return 解压后的数组长度
	 * \endif
	 */
	static size_t gunzip(char* in, size_t inLength, char** out);

	/*
	 * string helper
	 */

	/**
	 * \if English
	 * Replace a char with other char
	 *
	 * @param s string
	 * @param c char to be replaced
	 * @param sub char to be replaced to
	 * @return new string, caller should release it. returns NULL if \c s is NULL
	 * \else
	 * 替换一个字符串中的字符为其它字符
	 *
	 * @param s 字符串
	 * @param c 需要替换的字符
	 * @param sub 替换成的字符, 如果只是需要删掉字符, 可以传入0
	 * @return 替换后的字符串, 调用者要负责释放指针. 如果s本身是NULL, 则返回NULL
	 * \endif
	 */
	static const char* replaceChar(const char* s, char c, char sub);

	/**
	 * \if English
	 * Read data until encounter new line or carriage return. \c data will point to next
	 * line when reading finished
	 *
	 * @param data pointer of data pointer, data encoding must be utf-8
	 * @param buf buffer to hold the line read, including new line or carriage return
	 * @return length of line, contains new line and carriage return character
	 * \else
	 * 从指定数据中读取一行, 即直到碰到回车或者换行字符为止. 读取完毕后
	 * *data会指向下一行的起始位置.
	 *
	 * @param data 原始数据的二级指针, 数据需要是utf-8编码
	 * @param buf 缓冲区, 必须要足够大能够包含一行的内容以及结尾的0字符, 返回的内容包括回车换行符.
	 * @return 返回读取的长度, 这个长度包含了回车换行符
	 * \endif
	 */
	static int readLine(char** data, char* buf);

	/**
	 * \if English
	 * Check whether a string starts with another string
	 *
	 * @param s string to check
	 * @param sub sub string
	 * @return true means \c s starts with \c sub
	 * \else
	 * 检查某个字符串是否是以某个字符串开头的
	 *
	 * @param s 要检查的字符串
	 * @param sub 子串
	 * @return true表示s是以sub开头的
	 * \endif
	 */
	static bool startsWith(const char* s, const char* sub);

	/**
	 * \if English
	 * Check whether a string ends with another string
	 *
	 * @param s string to check
	 * @param sub sub string
	 * @return true means \c s ends with \c sub
	 * \else
	 * 检查某个字符串是否是以某个字符串结束的
	 *
	 * @param s 要检查的字符串
	 * @param sub 子串
	 * @return true表示s是以sub开头的
	 * \endif
	 */
	static bool endsWith(const char* s, const char* sub);

	/**
	 * \if English
	 * Convert utf-16 string to utf-8 string
	 *
	 * @param s16 utf-16 string, can be NULL
	 * @return string in utf-8 encoding, or zero length string if \c s16 is NULL. caller should release it
	 * \else
	 * 把unicode字符串转换为utf-8字符串
	 *
	 * @param s16 unicode字符串, 可以为NULL，如果是NULL，返回长度为0的字符串
	 * @return utf-8编码的字符串, 该字符串需要调用者进行释放.
	 * \endif
	 */
	static const char* utf16toutf8(const char16_t* s16);

	/**
	 * \if English
	 * Convert utf-16 char to utf-8 char
	 *
	 * @param c integer format of utf-32 char
	 * @return integer format of utf-8 char
	 * \else
	 * 把一个utf-16编码的字符转换为utf-8字符
	 *
	 * @param c utf-32编码字符的整数形式
	 * @return utf-8编码字符的整数形式
	 * \endif
	 */
	static int utf32toutf8(char32_t c);

	/**
	 * \if English
	 * Convert a wide char string to utf-8 encoded string. However, wchar_t
	 * doesn't have same size in different platform.
	 *
	 * @param ws wide char string
	 * @return utf-8 encoded string, caller should release it
	 * \else
	 * 把一个宽字符字符串转换为utf-8编码的字符串, 不过wchar_t在不同平台上具有不同的
	 * 字节大小
	 *
	 * @param ws 宽字节字符串
	 * @return utf-8编码的字符串, 调用者要负责释放指针
	 * \endif
	 */
	static const char* wctoutf8(const wchar_t* ws);

	/**
	 * \if English
	 * Convert utf-8 string to utf-16 string
	 *
	 * @param s8 utf-8 string
	 * @return utf-16 string, caller should release it
	 * \else
	 * 把utf-8字符串转换为unicode字符串
	 *
	 * @param s8 utf-8编码的字符串
	 * @return unicode字符串，该字符串需要调用者进行释放
	 * \endif
	 */
	static const char16_t* toUTF16(const char* s8);

	/**
	 * \if English
	 * Get length of unicode string, in character
	 *
	 * @param str unicode string
	 * @return count of unicode character
	 * \else
	 * 判断unicode字符串的长度
	 *
	 * @param str unicode编码的字符串
	 * @return unicode字符数
	 * \endif
	 */
	static size_t strlen16(const char16_t* str);

	/**
	 * \if English
	 * Get length of utf-32 string, in character
	 *
	 * @param str utf-32 string
	 * @return count of unicode character
	 * \else
	 * 判断utf-32编码字符串的长度
	 *
	 * @param str utf-32编码的字符串
	 * @return unicode字符数
	 * \endif
	 */
	static size_t strlen32(const char32_t* str);

	/**
	 * \if English
	 * Get length of wide char string, in character
	 *
	 * @param ws wide char string
	 * @return count of character
	 * \else
	 * 判断宽字节字符串的长度
	 *
	 * @param ws 宽字节字符串
	 * @return 字符数
	 * \endif
	 */
	static size_t strlenW(const wchar_t* ws);

	/**
	 * \if English
	 * Search a sub string in an unicode string
	 *
	 * @param str unicode string
	 * @param search utf-8 string
	 * @return if found, return start pointer, or returns NULL if not found
	 * \else
	 * 在一个unicode字符串中搜索一个子串
	 *
	 * @param str unicode编码的字符串
	 * @param search utf-8编码的子串
	 * @return 如果搜索到, 返回起始指针, 否则返回NULL
	 * \endif
	 */
	static const char16_t* str16str(const char16_t* str, const char* search);

	/**
	 * \if English
	 * Get count of utf-8 character in a string
	 *
	 * @param s utf-8 string
	 * @return count of utf-8 character
	 * \else
	 * 计算一个utf-8编码的字符串中的字符个数，比如"我hello"则返回6
	 *
	 * @param s utf-8编码的字符串，因此可以包含非英文字符
	 * @return 字符个数
	 * \endif
	 */
	static int strlen8(const char* s);

	/**
	 * \if English
	 * Calculate how many bytes of a utf-8 encoded character
	 *
	 * @param c first byte of character in utf-8 encoding
	 * @return byte length of this character
	 * \else
	 * 计算utf8编码块的字节数
	 *
	 * @param c utf-8编码字符的首字节
	 * @return utf-8编码字符的字节长度
	 * \endif
	 */
	static int getUTF8Bytes(unsigned char c);

	/**
	 * \if English
	 * Remove heading and tailing white spaces
	 *
	 * @param s input string, after trimming it becomes string without heading and tailing white spaces
	 * @return length after trimming
	 * \else
	 * 去掉字符串头尾的空格字符
	 *
	 * @param s 输入字符串, trim完成后该字符串将成为无头尾空格的
	 * @return 去掉空格后字符串的长度
	 * \endif
	 */
	static size_t trim(char* s);

	/**
	 * \if English
	 * Check string is empty or not
	 *
	 * @param s string, can be NULL
	 * @return true means string is empty, false if not
	 * \else
	 * 判断字符串是否为空
	 *
	 * @param s 字符串指针，可以为NULL
	 * @return true表示字符串为NULL或者没有内容
	 * \endif
	 */
	static bool isEmpty(char* s);

	/**
	 * \if English
	 * Convert a string to lowercase, it only converts ASCII characters in string
	 *
	 * @param s string
	 * \else
	 * 把一个字符串转换为小写
	 *
	 * @param s 源字符串，完成后s中的大写字母变成小写
	 * \endif
	 */
	static void toLowercase(char* s);

	/**
	 * \if English
	 * Replace character with another in a string
	 *
	 * @param s string
	 * @param from character need to be replaced
	 * @param to character will be replaced to
	 * \else
	 * 替换一个字符串中的字符为其它字符
	 *
	 * @param s 字符串
	 * @param from 需要替换的字符
	 * @param to 替换成的字符
	 * \endif
	 */
	static void replaceChar(char* s, char from, char to);

	/**
	 * \if English
	 * Copy a string
	 *
	 * @param src source string
	 * @return copied string, caller should release it
	 * \else
	 * 拷贝一个字符串
	 *
	 * @param src 源字符串
	 * @return 拷贝后的字符串, 调用者要负责释放该字符串. returns NULL if \c src is NULL
	 * \endif
	 */
	static const char* copy(const char* src);

	/**
	 * \if English
	 * Copy a string
	 *
	 * @param src source string
	 * @param start start position to copy
	 * @param len length to copy
	 * @return copied string, caller should release it. returns NULL if \c src is NULL
	 * \else
	 * 拷贝一个字符串
	 *
	 * @param src 源字符串
	 * @param start 拷贝的起始位置
	 * @param len 拷贝的长度
	 * @return 拷贝后的字符串，调用者要负责释放该字符串
	 * \endif
	 */
	static const char* copy(const char* src, int start, size_t len);

	/**
	 * \if English
	 * Copy a memory data
	 *
	 * @param data data pointer, caller should release it
	 * @param len length to copy
	 * @param copied data, caller should release it, returns NULL if \c data is NULL
	 * \else
	 * 拷贝一段内存数据
	 *
	 * @param data 内存数据指针, 调用者要负责释放
	 * @param len 要拷贝的长度
	 * @return 拷贝后的数据，调用者要负责释放内存
	 * \endif
	 */
	static const char* copyData(const char* data, size_t len);

	/**
	 * \if English
	 * Calculate hash value of a string, using BKDR algorithm. It can not avoid conflict but result
	 * is acceptable
	 *
	 * @param str string
	 * @return hash value
	 * \else
	 * 计算字符串的哈希值，算法是BKDR. 不能保证一定没有冲突，但是可以接受
	 *
	 * @param str 字符串
	 * @return 哈希值
	 * \endif
	 */
	static unsigned int strHash(const char* str);

	/**
	 * \if English
	 * Break lines for an utf-8 encoded string
	 *
	 * @param chars utf-8 encoded string
	 * @param provider provider of characters which can decide how wide a char is
	 * @param width line width in pixels, and zero means no limit
	 * @param spaceWidth space character width in pixels
	 * @param tabSize space count which one tab equals to
	 * @return a vector contains all lines, the caller should release every line and vector
	 * \else
	 * 对一个utf-8编码的字符串进行断行
	 *
	 * @param chars utf-8编码的字符串
	 * @param provider 字符的提供者接口实现, 用来查询字符的信息
	 * @param width 行宽, 0表示不限制
	 * @param spaceWidth 如果不存在空格字符, 则为空格填充的像素宽度
	 * @param tabSize 一个tab相当于多少个空格
	 * @return 一个包含了所有行的数组, 调用者必须要释放每一行的内存和数组对象
	 * \endif
	 */
	static vector<const char*>* breakLines(const char* chars, wyCharProvider* provider, float width, float spaceWidth, float tabSize);

	/*
	 * resolution helper
	 */

	/**
	 * \if English
	 * Convert a DP value to pixel value
	 *
	 * @param dp DP value
	 * @return pixel value
	 * \else
	 * 把一个DP值转换为像素值
	 *
	 * @param dp dp值
	 * @return 对应到当前设备上的像素值
	 * \endif
	 */
	static float resolveDp(float dp);

	/**
	 * \if English
	 * Convert a SP value to pixel value
	 *
	 * @param sp SP value
	 * @return pixel value
	 * \else
	 * 把一个SP值转换为像素值
	 *
	 * @param sp sp值
	 * @return 对应到当前设备上的像素值
	 * \endif
	 */
	static float resolveSp(float sp);

	/**
	 * \if English
	 * Convert a pixel value to DP value
	 *
	 * @param px pixel value
	 * @return DP value
	 * \else
	 * 把一个像素值转换为DP值
	 *
	 * @param px 像素值
	 * @return 对应到当前设备上的DP值
	 * \endif
	 */
	static float resolvePx(float px);

	/**
	 * \if English
	 * Treat field in a \link wyRect wyRect\endlink as DP value, convert them to pixel value
	 *
	 * @param rect \link wyRect wyRect\endlink
	 * @return \link wyRect wyRect\endlink converted
	 * \else
	 * 把一个矩形里的值作为dp值转换为像素值
	 *
	 * @param rect 原始的dp值矩形
	 * @return 像素值矩形
	 * \endif
	 */
	static wyRect resolveRect(wyRect rect);

	/**
	 * \if English
	 * Treat field in a \link wyPoint wyPoint\endlink as DP value, convert them to pixel value
	 *
	 * @param point \link wyPoint wyPoint\endlink
	 * @return \link wyPoint wyPoint\endlink converted
	 * \else
	 * 把一个点的值作为dp值转换为像素值
	 *
	 * @param point 原始的dp值点
	 * @return 像素值点
	 * \endif
	 */
	static wyPoint resolvePoint(wyPoint point);
	
	/*
	 * system ui helper
	 */

	/**
	 * \if English
	 * Show a confirm dialog and the dialog is backed by system, not Node
	 *
	 * @param title title text
	 * @param msg content text
	 * @param positiveButton text of positive button, default is NULL which means it is "OK"
	 * @param negativeButton text of negative button, default is NULL which means it is "Cancel"
	 * @param onOK callback when ok button is clicked
	 * @param onCancel callback when cancel button is clicked
	 * \else
	 * 显示一个系统的确认对话框, 并非节点的实现
	 *
	 * @param title 标题
	 * @param msg 内容
	 * @param positiveButton 确定按钮的文字, 缺省是NULL, 表示使用"确定"
	 * @param negativeButton 取消按钮的文字, 缺省是NULL, 表示使用"取消"
	 * @param onOK 确定按钮按下时调用的方法
	 * @param onCancel 取消按钮按下时调用的方法
	 * \endif
	 */
	static void showSystemConfirmDialog(const char* title, const char* msg, const char* positiveButton = NULL, const char* negativeButton = NULL, wyTargetSelector* onOK = NULL, wyTargetSelector* onCancel = NULL);
    
    /**
	 * \if English
	 * Show a alert dialog and the dialog is backed by system, not Node
	 *
	 * @param title title text
	 * @param msg content text
	 * @param positiveButton text of positive button, default is NULL which means it is "OK"
	 * @param onOK callback when ok button is clicked
	 * \else
	 * 显示一个系统的警告对话框, 并非节点的实现
	 *
	 * @param title 标题
	 * @param msg 内容
	 * @param positiveButton 确定按钮的文字, 缺省是NULL, 表示使用"确定"
	 * @param onOK 确定按钮按下时调用的方法
	 * \endif
	 */
	static void showSystemAlertDialog(const char* title, const char* msg, const char* positiveButton = NULL, wyTargetSelector* onOK = NULL);

	/*
	 * font helper
	 */

	/**
	 * \if English
	 * Calculate bounding size of a string
	 *
	 * @param text string to be examined
	 * @param fontSize font size in pixel
	 * @param fontPath font file path in assets, or NULL if use system font
	 * @param isFile true means \c fontPath is an absolute path in file system, false means
	 * 		\c fontPath is a relative path under assets
	 * @param width line width or zero means single line
	 * @return \link wySize wySize\endlink
	 * \else
	 * 计算字符串的渲染大小
	 *
	 * @param text 字符串
	 * @param fontSize 字体大小
	 * @param fontPath 自定义字体在assets目录下的路径, 为NULL表示使用系统缺省字体
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个相对于assets的相对路径
	 * @param width 最大行宽，如果为0，表示不折行
	 * @return \link wySize wySize\endlink
	 * \endif
	 */
	static wySize calculateTextSize(const char* text, float fontSize, const char* fontPath, bool isFile = false, float width = 0);

	/**
	 * \if English
	 * Calculate bounding size of a string
	 *
	 * @param text string to be examined
	 * @param fontSize font size in pixel
	 * @param style font style
	 * @param fontName font name, or NULL if use system font
	 * @param width line width or zero means single line
	 * @return \link wySize wySize\endlink
	 * \else
	 * 计算字符串的渲染大小
	 *
	 * @param text 字符串
	 * @param fontSize 字体大小
	 * @param style 字体样式
	 * @param fontName 字体名称, 为NULL表示使用系统缺省字体
	 * @param width 最大行宽，如果为0，表示不折行
	 * @return \link wySize wySize\endlink
	 * \endif
	 */
	static wySize calculateTextSize(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width = 0);

	/**
	 * \if English
	 * Create a bitmap for a string, in RGBA8888 format
	 *
	 * @param text string
	 * @param fontSize font size in pixel
	 * @param fontPath font file path in assets, or NULL if use system font
	 * @param isFile true means \c fontPath is an absolute path in file system, false means
	 * 		\c fontPath is a relative path under assets
	 * @param width the width of the label, in pixels
	 * @param alignment text alignment, default is left
	 * @return generated bitmap data, in RGBA8888 format, caller should release it
	 * \else
	 * 把字符串转变为内存中的图片，生成的内存数据可以直接通过OpenGL调用转换为OpenGL贴图
	 *
	 * @param text 字符串
	 * @param fontSize 字体大小
	 * @param fontPath 自定义字体在assets目录下的路径, 为NULL表示使用系统缺省字体
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个相对于assets的相对路径
	 * @param width 最大行宽，如果为0，表示不折行
	 * @param alignment 文字对齐方式, 缺省是左对齐
	 * @return 生成的图片RGBA8888数据, 调用者要负责释放内存
	 * \endif
	 */
	static const char* createLabelBitmap(const char* text, float fontSize, const char* fontPath, bool isFile = false, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * \if English
	 * Create a bitmap for a string, in RGBA8888 format
	 *
	 * @param text string
	 * @param fontSize font size in pixel
	 * @param style font style
	 * @param fontName font name, or NULL if use system font
	 * @param width line width or zero means single line
	 * @param alignment text alignment, default is left
	 * @return generated bitmap data, in RGBA8888 format, caller should release it
	 * \else
	 * 把字符串转变为内存中的图片，生成的内存数据可以直接通过OpenGL调用转换为OpenGL贴图
	 *
	 * @param text 字符串
	 * @param fontSize 字体大小
	 * @param style 字体样式
	 * @param fontName 字体名称, 为NULL表示使用系统缺省字体
	 * @param width 最大行宽，如果为0，表示不折行
	 * @param alignment 文字对齐方式, 缺省是左对齐
	 * @return 生成的图片RGBA8888数据, 调用者要负责释放内存
	 * \endif
	 */
	static const char* createLabelBitmap(const char* text, float fontSize, wyFontStyle style = NORMAL, const char* fontName = NULL, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);
	
	/*
	 * memory file system
	 */

	/**
	 * \if English
	 * Get memory file data
	 *
	 * @param filename file name to identify a memory file
	 * @param buffer buffer to hold file data, you don't need release it
	 * @param size returns length of file data
	 * @return true if successful, or false if failed
	 * \else
	 * 得到一个内存文件
	 *
	 * @param filename 内存文件的标识名称，一般就是这个文件的文件名
	 * @param buffer 返回内存文件数据的缓冲区二级指针，不需要释放因为数据并不是拷贝得到的
	 * @param size 用来返回文件数据的长度
	 * @return true表示成功， false表示失败
	 * \endif
	 */
	static bool getFile(const char* filename, const char** buffer, size_t* size);
	
	/*
	 * opengl screenshot
	 */

	/**
	 * \if English
	 * Grab current OpenGL frame, and save it as png or jpg image. This method save image to specified path and
	 * may be slow because file I/O involved. It uses glReadPixels API so lower version Android may not support
	 * it. It requires permission of writing external storage.
	 *
	 * @param path destination path of screenshot image, it will be created if it doesn't exist. If NULL, do nothing.
	 * 		The path will be mapped if not Android platform.  The extension of path determinate format of image
	 * 		generated. The extension can be png, jpg, jpeg.
	 * \else
	 * 抓取当前帧, 保存为png或jpg图片. 这个方法会将图片保存到指定路径，由于牵涉到文件
	 * 写操作, 因此速度较慢, 另外使用的OpenGL接口可能在低版本Android系统上没有
	 * 实现. 如果保存的路径在sd卡上, 则应用需要有写sd卡的权限.
	 *
	 * @param path 截图保存的目标路径, 如果指定的路径不存在, 则会自动创建目录. 如果为NULL, 则不做任何事.
	 * 		这个路径在非Android平台上会被映射. 目前支持jpg,png两种格式. 根据传递的文件名称后缀判断是png还
	 * 		是jpg, jpg保存可以用jpg,jpeg两种后缀
	 * \endif
	 */
	static void makeScreenshot(const char* path);

	/**
	 * \if English
	 * Grab current OpenGL frame, and save it as png or jpg image. This method save image to specified path and
	 * may be slow because file I/O involved. It uses glReadPixels API so lower version Android may not support
	 * it. It requires permission of writing external storage.
	 *
	 * @param path destination path of screenshot image, it will be created if it doesn't exist. If NULL, do nothing.
	 * 		The path will be mapped if not Android platform.  The extension of path determinate format of image
	 * 		generated. The extension can be png, jpg, jpeg.
	 * @param rect screen rect to be shot
	 * \else
	 * 抓取当前帧, 保存为png或jpg图片. 这个方法会将图片保存到指定路径，由于牵涉到文件
	 * 写操作, 因此速度较慢, 另外使用的OpenGL接口可能在低版本Android系统上没有
	 * 实现. 如果保存的路径在sd卡上, 则应用需要有写sd卡的权限.
	 *
	 * @param path 截图保存的目标路径, 如果指定的路径不存在, 则会自动创建目录. 如果为NULL, 则不做任何事.
	 * 		这个路径在非Android平台上会被映射. 目前支持jpg,png两种格式. 根据传递的文件名称后缀判断是png还
	 * 		是jpg, jpg保存可以用jpg,jpeg两种后缀
	 * @param rect 需要截取的屏幕矩形范围
	 * \endif
	 */
	static void makeScreenshot(const char* path, wyRect rect);

	/**
	 * file helper
	 */

	/**
	 * \if English
	 * Calculate md5 of an file in file system. The md5 is calculated
	 * from file content but it depends on file size. If file size is
	 * smaller or equal than 60k, all file bytes is calculated. If larger than 60k,
	 * MD5 is calculated from head, middle and tail 20k bytes.
	 *
	 * @param path path of file in file system
	 * @return md5 hex string and caller should release it. Returns NULL if failed
	 * \else
	 * 计算文件的md5值. 如果文件小于等于60k, 所有的文件字节都被计算, 如果大于60k, 取
	 * 头, 中, 尾三段20k内容进行md5计算.
	 *
	 * @param path 文件路径
	 * @return md5形式的字符串, 调用者要负责释放. 如果计算失败, 返回NULL
	 * \endif
	 */
	static const char* fileMd5(const char* path);

	/**
	 * \if English
	 * Get file size
	 *
	 * @param f C file pointer
	 * @return byte length of file
	 * \else
	 * 得到文件的大小
	 *
	 * @param f FILE指针
	 * @return 文件字节大小
	 * \endif
	 */
	static size_t getFileSize(FILE* f);

	/**
	 * \if English
	 * Get parent path of a path
	 *
	 * \note
	 * It doesn't map path, if input path is /sdcard/test, then returns /sdcard in all platforms
	 *
	 * @param path path string
	 * @return if \c path is NULL, returns NULL. If not NULL, return parent path. If \c path is root path,
	 * 		returns NULL. Caller should release returned path string
	 * \else
	 * 得到某个路径的父路径
	 *
	 * \note
	 * 该方法不会对路径进行映射，假如传入的路径是/sdcard/test, 则在各平台上都返回/sdcard
	 *
	 * @param path 路径字符串
	 * @return 如果\c path为NULL, 则返回NULL. 如果path不为NULL, 返回path的父目录路径. 如果path已经是顶层路径, 则返回
	 * 		NULL. 返回的字符串需要被调用者释放
	 * \endif
	 */
	static const char* getParentPath(const char* path);

	/**
	 * \if English
	 * Check existence of a path
	 *
	 * \note
	 * Method will map path in iOS. Generally an absoluate path will be mapped to ~/Documents. So
	 * it ensure no code modification needed when port to iOS platform
	 *
	 * @param path path string
	 * @return true if path exists, or false if not. If \c path is NULL, returns true
	 * \else
	 * 检查某个路径是否存在
	 *
	 * \note
	 * 方法会对iOS平台进行路径映射，会被映射到~/Documents下。因此在进行跨平台移植时代码
	 * 不用修改
	 *
	 * @param path 路径字符串
	 * @return true如果路径存在, false则不存在. 如果\c path是NULL, 返回的是true
	 * \endif
	 */
	static bool isPathExistent(const char* path);

	/**
	 * \if English
	 * Delete a file pointed by path, if path is a folder, do nothing
	 *
	 * \node
	 * Method will map path in iOS platform. Generally it will be mapped to ~/Documents so no need to
	 * modify code when porting
	 *
	 * @param path path string
	 * @return true if successful, or false if failed
	 * \else
	 * 删除某个文件, 如果传入的路径实际上是个目录，则不做任何操作
	 *
	 * \note
	 * 方法会对iOS平台进行路径映射，会被映射到~/Documents下。因此在进行跨平台移植时代码
	 * 不用修改
	 *
	 * @param path 文件路径，如果路径指向的位置是一个目录，则不做任何操作
	 * @return true表示删除文件成功
	 * \endif
	 */
	static bool deleteFile(const char* path);

	/**
	 * \if English
	 * For a path, create all intermediate folders
	 *
	 * \note
	 * Method will map path if not Android platform.
	 *
	 * @param path path string
	 * @return true if successful, or false if failed
	 * \else
	 * 对给定的一个路径, 创建它的所有父目录
	 *
	 * \note
	 * 对于非Android平台, 方法会进行路径映射
	 *
	 * @param path 路径字符串
	 * @return true表示创建成功, false表示创建失败
	 * \endif
	 */
	static bool createIntermediateFolders(const char* path);

	/**
	 * \if English
	 * Create a folder for a path, which doesn't create intermediate folders
	 *
	 * \note
	 * Method will map path if not Android platform.
	 *
	 * @param path path string
	 * @return true if successful, or false if failed
	 * \else
	 * 对给定的一个路径, 创建这个路径所指的文件夹
	 *
	 * \note
	 * 对于非Android平台, 方法会进行路径映射
	 *
	 * @param path 路径字符串
	 * @return true表示创建成功, false表示创建失败
	 * \endif
	 */
	static bool createFolder(const char* path);

	/**
	 * \if English
	 * Delete last component in a path, for example:<br>
	 * Input					Output<br>
	 * "/tmp/scratch.tiff"      "/tmp"<br>
	 * "/tmp/scratch"           "/tmp"<br>
	 * "/tmp/"                  "/"<br>
	 * "scratch"                ""<br>
	 * "/" 						"/"<br>
	 *
	 * @param path path string
	 * @return path without last segment, caller should release returned path string
	 * \else
	 * 删除路径中最后一节的内容, 该方法的效果如下所示:<br>
	 * 输入                      输出<br>
	 * "/tmp/scratch.tiff"      "/tmp"<br>
	 * "/tmp/scratch"           "/tmp"<br>
	 * "/tmp/"                  "/"<br>
	 * "scratch"                ""<br>
	 * "/" 						"/"<br>
	 *
	 * @param path 原始路径
	 * @return 删除掉最后一节的路径, 调用者要负责释放这个字符串
	 * \endif
	 */
	static const char* deleteLastPathComponent(const char* path);

	/**
	 * \if English
	 * Delete last path component in same string buffer
	 * 
	 * @param path path string
	 * \else
	 * 删除路径字符串中的最后一个路径部分, 删除操作会修改传入的路径字符串, 而不是返回一个
	 * 新字符串
	 * 
	 * @param path 路径字符串
	 * \endif
	 */
	static void deleteLastPathComponentInSameBuffer(char* path);

	/**
	 * \if English
	 * Delete path extension of last path component
	 *
	 * @param path path string
	 * @return path after deleted extension, caller should release it
	 * \else
	 * 删除路径中最后一个部件的扩展名
	 *
	 * @param path 路径字符串
	 * @return 删除了扩展名的路径字符串, 调用者需要释放该指针
	 * \endif
	 */
	static const char* deletePathExtension(const char* path);

	/**
	 * \if English
	 * Delete path extension of last path component, in passed in \c path buffer
	 *
	 * @param path path string
	 * \else
	 * 删除路径中最后一个部件的扩展名
	 *
	 * @param path 路径字符串
	 * \endif
	 */
	static void deletePathExtensionInSameBuffer(char* path);

	/**
	 * \if English
	 * Append a path segment to another path, for example:<br>
	 * Input					Output<br>
	 * "/tmp", "/scratch.tiff"  "/tmp/scratch.tiff"<br>
	 * "/tmp//", "/scratch"     "/tmp/scratch"<br>
	 * "/tmp", "/"              "/tmp"<br>
	 * "/", "tmp/" 				"/tmp/"<br>
	 *
	 * @param path path string
	 * @param component segment to be added
	 * @return new path, caller should release returned path string
	 * \else
	 * 在某个路径后追加一节, 该方法的效果如下所示:<br>
	 * 输入                      输出<br>
	 * "/tmp", "/scratch.tiff"  "/tmp/scratch.tiff"<br>
	 * "/tmp//", "/scratch"     "/tmp/scratch"<br>
	 * "/tmp", "/"              "/tmp"<br>
	 * "/", "tmp/" 				"/tmp/"<br>
	 *
	 * @param path 原始路径
	 * @param component 需要追加的内容
	 * @return 新的路径, 调用者要负责释放这个字符串
	 * \endif
	 */
	static const char* appendPathComponent(const char* path, const char* component);

	/**
	 * \if English
	 * Return last segment of a path, for example:<br>
	 * Input					Output<br>
	 * "/tmp/scratch.tiff"      "scratch.tiff"<br>
	 * "/tmp/scratch"           "scratch"<br>
	 * "/tmp/"                  "tmp"<br>
	 * "scratch"                "scratch"<br>
	 * "/" 						"/"<br>
	 *
	 * @param path path string
	 * @return last segment of \c path, caller should return returned string
	 * \else
	 * 返回路径的最后一节, 对应关系是:<br>
	 * 输入                      输出<br>
	 * "/tmp/scratch.tiff"      "scratch.tiff"<br>
	 * "/tmp/scratch"           "scratch"<br>
	 * "/tmp/"                  "tmp"<br>
	 * "scratch"                "scratch"<br>
	 * "/" 						"/"<br>
	 *
	 * @param path 输入的路径
	 * @return 路径的最后一节, 调用者要负责释放内存
	 * \endif
	 */
	static const char* lastPathComponent(const char* path);

	/**
	 * \if English
	 * Map an Android file system path to iOS. If current platform is Android, do nothing.
	 *
	 * @param path file path
	 * @preturn mapped path, caller should release returned path string
	 * \else
	 * 对某个文件系统路径做映射，在Android平台上，这个方法不做任何事，只是直接
	 * 返回path的拷贝。在iOS平台，会将path映射到iOS的路径.
	 *
	 * @param path 文件路径
	 * @return 映射后的路径, 调用者要负责释放返回的这个路径
	 * \endif
	 */
	static const char* mapLocalPath(const char* path);

	/**
	 * \if English
	 * Map an Android assets path to iOS. If current platform is Android, do nothing.
	 *
	 * @param path path relative to assets
	 * @return mapped path, caller should release returned path string
	 * \else
	 * 对某个assets下的相对路径做映射，在Android平台上，这个方法不做任何事，只是直接
	 * 返回path的拷贝。在iOS平台，会将path映射到iOS的路径.
	 *
	 * @param path assets下的文件相对路径
	 * @return 映射后的路径, 调用者要负责释放返回的这个路径
	 * \endif
	 */
	static const char* mapAssetsPath(const char* path);

	/*
	 * thread helper
	 */

	/**
	 * \if English
	 * Ensure something is executed in OpenGL thread, the logic is packed as
	 * a \link wyRunnable wyRunnable\endlink object
	 *
	 * @param runnable \link wyRunnable wyRunnable\endlink
	 * \else
	 * 在GL线程中执行一个\link wyRunnable wyRunnable\endlink 对象
	 *
	 * @param runnable \link wyRunnable wyRunnable\endlink
	 * \endif
	 */
	static void runOnGLThread(wyRunnable* runnable);

	/*
	 * video helper
	 */

	/**
	 * \if English
	 * Play a video
	 *
	 * @param resId video resource id
	 * \else
	 * 播放一段视频
	 *
	 * @param resId 视频文件的资源id
	 * \endif
	 */
	static void playVideo(int resId);

	/**
	 * \if English
	 * Play a video
	 *
	 * @param path path of video
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 *		is a relative path under assets
	 * \else
	 * 播放一段视频
	 *
	 * @param path 视频文件在assets下的路径
	 * @param isFile true表示path是一个文件系统的绝对路径, false表示这是一个assets下的相对路径
	 * \endif
	 */
	static void playVideo(const char* path, bool isFile = false);

	/*
	 * network helper
	 */

	/**
	 * \if English
	 * Open an url, generally it will open a browser
	 *
	 * @param url url string
	 * \else
	 * 打开一个url地址, 一般这会打开一个浏览器
	 *
	 * @param url url地址
	 * \endif
	 */
	static void openUrl(const char* url);

	/**
	 * \if English
	 * add an android string file, e.g.string.xml. After the file is added,
	 * strings defined can be accessed through R.string.xxx
	 * 
	 * \note
     * This function takes no effect on android
	 
	 * @param fileName the file to be added. On windows, it should be a valid file path
	 * @param langId the identity of locale, for example, "en" means english, "zh" means chinese.
	 *
	 * \else
	 * 添加一个android字符串文件，比如string.xml. 文件添加后，定义在改文件中的字符串便可以以
	 * R.string.xxx的方式访问了。
	 * 
	 * \note
     * 在android上没效果，是一个空实现
	 *
	 * @param fileName 文件名. 在windows上，应该为一个有效的文件路径
	 * @param langId 字符串文件的本地化标识，比如，"en"表示英语，"zh"表示中文
	 * \endif
	 */
	static void addAndroidStrings(const char* fileName, const char* langId);

#if ANDROID
	/*
	 * jni helper, only for android
	 */

	/**
	 * \if English
	 * Get a pionter of JNIEnv
	 *
	 * @return pointer of JNIEnv
	 * \else
	 * 获得一个JNIEnv指针，一般需要进行一些jni相关操作时，可以用这个方法
	 * 得到环境指针
	 *
	 * @return JNI环境指针
	 * \endif
	 */
	static JNIEnv* getJNIEnv();
#endif // #if ANDROID
};

#endif // __wyUtils_h__
