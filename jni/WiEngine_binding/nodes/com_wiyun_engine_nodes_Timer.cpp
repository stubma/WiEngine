#include "com_wiyun_engine_nodes_Timer.h"
#include "wyScheduler.h"
#include <stdlib.h>

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Timer_nativeInit__Lcom_wiyun_engine_utils_TargetSelector_2F
  (JNIEnv * env, jobject thiz, jobject ts, jfloat interval) {
	wyTargetSelector* targetSelector = wyTargetSelector::make(ts);
	wyTimer* timer = WYNEW wyTimer(targetSelector, interval);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)timer);
	wyObjectLazyRelease(timer);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Timer_nativeInit__Lcom_wiyun_engine_utils_TargetSelector_2I
  (JNIEnv * env, jobject thiz, jobject ts, jint frame) {
	wyTargetSelector* targetSelector = wyTargetSelector::make(ts);
	wyTimer* timer = WYNEW wyTimer(targetSelector, frame);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)timer);
	wyObjectLazyRelease(timer);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Timer_setInterval
  (JNIEnv * env, jobject thiz, jfloat interval) {
	wyTimer* timer = (wyTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	timer->setInterval(interval);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Timer_getInterval
  (JNIEnv * env, jobject thiz) {
	wyTimer* timer = (wyTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return timer->getInterval();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Timer_setFrame
  (JNIEnv * env, jobject thiz, jint frame) {
	wyTimer* timer = (wyTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	timer->setFrame(frame);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Timer_getFrame
  (JNIEnv * env, jobject thiz) {
	wyTimer* timer = (wyTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return timer->getFrame();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Timer_setOneShot
  (JNIEnv * env, jobject thiz, jboolean oneShot) {
	wyTimer* timer = (wyTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	timer->setOneShot(oneShot);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Timer_isOneShot
  (JNIEnv * env, jobject thiz) {
	wyTimer* timer = (wyTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return timer->isOneShot();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Timer_setMaxInvocation
  (JNIEnv * env, jobject thiz, jint max) {
	wyTimer* timer = (wyTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	timer->setMaxInvocation(max);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Timer_getMaxInvocation
  (JNIEnv * env, jobject thiz) {
	wyTimer* timer = (wyTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return timer->getMaxInvocation();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Timer_getCurrentInvocationCount
  (JNIEnv * env, jobject thiz) {
	wyTimer* timer = (wyTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return timer->getCurrentInvocationCount();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Timer_fire
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyTimer* timer = (wyTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	timer->fire(delta);
}
