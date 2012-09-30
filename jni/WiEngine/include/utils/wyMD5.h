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

#ifndef __wyMD5_h__
#define __wyMD5_h__

#include <stddef.h>
#include "wyGlobal.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @class wyMD5
 *
 * \if English
 * MD5 utilities
 * \else
 * MD5工具类
 * \endif
 */
class WIENGINE_API wyMD5 {
public:
	/**
	 * \if English
	 * calculate md5 string for a C string
	 *
	 * @param s C string
	 * @return md5 string, caller should release it
	 * \else
	 * 对一个字符串做md5, 返回md5的字符串形式
	 *
	 * @param s 要做md5的字符串
	 * @return md5的字符串形式, 调用者要负责释放字符串
	 * \endif
	 */
	static const char* md5(const char* s);

	/**
	 * \if English
	 * calculate md5 for a binary data
	 *
	 * @param data binary data
	 * @param len data length
	 * @return md5 string, caller should release it
	 * \else
	 * 对一段数据做md5, 返回md5的字符串形式
	 *
	 * @param data 数据
	 * @param len 数据长度
	 * @return md5的字符串形式, 调用者要负责释放
	 * \endif
	 */
	static const char* md5(const void* data, size_t len);
};

#ifdef __cplusplus
}
#endif

#endif // __wyMD5_h__
