#include "com_wiyun_engine_nodes_Scheduler.h"
#include "wyScheduler.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern wyScheduler* gScheduler;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Scheduler_nativeGetInstance
  (JNIEnv * env, jclass clazz) {
	return (jint)gScheduler;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Scheduler_getTimeScale
  (JNIEnv * env, jobject thiz) {
	wyScheduler* s = (wyScheduler*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->getTimeScale();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Scheduler_setTimeScale
  (JNIEnv * env, jobject thiz, jfloat timeScale) {
	wyScheduler* s = (wyScheduler*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	s->setTimeScale(timeScale);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Scheduler_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyScheduler* scheduler = wyScheduler::getInstance();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)scheduler);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Scheduler_schedule
  (JNIEnv * env, jobject thiz, jobject t) {
	wyTimer* timer = (wyTimer*)env->GetIntField(t, g_fid_BaseObject_mPointer);
	wyScheduler* s = (wyScheduler*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	s->scheduleLocked(timer);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Scheduler_unschedule
  (JNIEnv * env, jobject thiz, jobject t) {
	wyTimer* timer = (wyTimer*)env->GetIntField(t, g_fid_BaseObject_mPointer);
	wyScheduler* s = (wyScheduler*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	s->unscheduleLocked(timer);
}
