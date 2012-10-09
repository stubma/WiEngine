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
