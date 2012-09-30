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

#if ANDROID

#include <jni.h>
/* Header for class com_wiyun_engine_events_Accelerometer */

#ifndef _Included_com_wiyun_engine_events_Accelerometer
#define _Included_com_wiyun_engine_events_Accelerometer
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_wiyun_engine_events_Accelerometer
 * Method:    hasAccelHandlers
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_Accelerometer_hasAccelHandlers
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_events_Accelerometer
 * Method:    accelerometerChanged
 * Signature: (FFF)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_events_Accelerometer_accelerometerChanged
  (JNIEnv *, jobject, jfloat, jfloat, jfloat);

#ifdef __cplusplus
}
#endif
#endif

#endif // #if ANDROID
