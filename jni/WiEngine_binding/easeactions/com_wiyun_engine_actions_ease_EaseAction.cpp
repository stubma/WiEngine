#include "com_wiyun_engine_actions_ease_EaseAction.h"
#include "wyEaseAction.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ease_EaseAction_setWrappedAction
  (JNIEnv * env, jobject thiz, jobject wrapped) {
	wyIntervalAction* w = (wyIntervalAction*)env->GetIntField(wrapped, g_fid_BaseObject_mPointer);
	wyEaseAction* ease = (wyEaseAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ease->setWrappedAction(w);
}
