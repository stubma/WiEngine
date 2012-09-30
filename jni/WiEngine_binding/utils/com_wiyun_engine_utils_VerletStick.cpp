#include "com_wiyun_engine_utils_VerletStick.h"
#include "wyVerletStick.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletStick_nativeInit
  (JNIEnv * env, jobject thiz, jobject a, jobject b) {
	wyVerletPoint* pa = (wyVerletPoint*)env->GetIntField(a, g_fid_BaseObject_mPointer);
	wyVerletPoint* pb = (wyVerletPoint*)env->GetIntField(b, g_fid_BaseObject_mPointer);
	wyVerletStick* s = WYNEW wyVerletStick(pa, pb);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)s);
	s->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletStick_contract
  (JNIEnv * env, jobject thiz, jboolean reverse) {
	wyVerletStick* s = (wyVerletStick*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	s->contract(reverse);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_VerletStick_nativeGetPointA
  (JNIEnv * env, jobject thiz) {
	wyVerletStick* s = (wyVerletStick*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)s->getPointA();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_VerletStick_nativeGetPointB
  (JNIEnv * env, jobject thiz) {
	wyVerletStick* s = (wyVerletStick*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)s->getPointB();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_utils_VerletStick_getLength
  (JNIEnv * env, jobject thiz) {
	wyVerletStick* s = (wyVerletStick*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->getLength();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_utils_VerletStick_getCurrentLength
  (JNIEnv * env, jobject thiz) {
	wyVerletStick* s = (wyVerletStick*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->getCurrentLength();
}
