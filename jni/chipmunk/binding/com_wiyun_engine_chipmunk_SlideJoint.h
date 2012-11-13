/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_wiyun_engine_chipmunk_SlideJoint */

#ifndef _Included_com_wiyun_engine_chipmunk_SlideJoint
#define _Included_com_wiyun_engine_chipmunk_SlideJoint
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_wiyun_engine_chipmunk_SlideJoint
 * Method:    init
 * Signature: (Lcom/wiyun/engine/chipmunk/Body;Lcom/wiyun/engine/chipmunk/Body;FFFFFF)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_init
  (JNIEnv *, jobject, jobject, jobject, jfloat, jfloat, jfloat, jfloat, jfloat, jfloat);

/*
 * Class:     com_wiyun_engine_chipmunk_SlideJoint
 * Method:    getMin
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_getMin
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_SlideJoint
 * Method:    setMin
 * Signature: (F)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_setMin
  (JNIEnv *, jobject, jfloat);

/*
 * Class:     com_wiyun_engine_chipmunk_SlideJoint
 * Method:    getMax
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_getMax
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_SlideJoint
 * Method:    setMax
 * Signature: (F)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_setMax
  (JNIEnv *, jobject, jfloat);

/*
 * Class:     com_wiyun_engine_chipmunk_SlideJoint
 * Method:    getAnchor1X
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_getAnchor1X
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_SlideJoint
 * Method:    getAnchor1Y
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_getAnchor1Y
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_SlideJoint
 * Method:    getAnchor2X
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_getAnchor2X
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_SlideJoint
 * Method:    getAnchor2Y
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_getAnchor2Y
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_SlideJoint
 * Method:    setAnchor1
 * Signature: (FF)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_setAnchor1
  (JNIEnv *, jobject, jfloat, jfloat);

/*
 * Class:     com_wiyun_engine_chipmunk_SlideJoint
 * Method:    setAnchor2
 * Signature: (FF)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_setAnchor2
  (JNIEnv *, jobject, jfloat, jfloat);

#ifdef __cplusplus
}
#endif
#endif