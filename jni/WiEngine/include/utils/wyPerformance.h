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
#ifndef __wyPerformance_h__
#define __wyPerformance_h__

#include "wyGlobal.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \if English
 * start to record time
 *
 * @param name name for this recording
 * \else
 * 开始记录时间
 *
 * @param name 输出时间时显示的字符串，用来标识是什么时间
 * \endif
 */
WIENGINE_API void wyRecordTime(const char* name);

/**
 * \if English
 * output time to log
 * \else
 * 输出时间
 * \endif
 */
WIENGINE_API void wyOutputTime();

#ifdef __cplusplus
}
#endif

#endif // __wyPerformance_h__
