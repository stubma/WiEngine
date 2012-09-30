#include "com_wiyun_engine_actions_FiniteTimeAction.h"
#include "wyFiniteTimeAction.h"


extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_actions_FiniteTimeAction_getElapsed
  (JNIEnv * env, jobject thiz) {
	wyFiniteTimeAction* action = (wyFiniteTimeAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return action->getElapsed();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_actions_FiniteTimeAction_getDuration
  (JNIEnv * env, jobject thiz) {
	wyFiniteTimeAction* action = (wyFiniteTimeAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return action->getDuration();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_FiniteTimeAction_setDuration
  (JNIEnv * env, jobject thiz, jfloat duration) {
	wyFiniteTimeAction* action = (wyFiniteTimeAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	action->setDuration(duration);
}
