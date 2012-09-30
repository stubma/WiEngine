#include "com_wiyun_engine_actions_ease_EaseOut.h"
#include "wyEaseOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ease_EaseOut_nativeInit
  (JNIEnv * env, jobject thiz, jobject action, jfloat rate) {
	wyIntervalAction* wrapped = action == NULL ? NULL : (wyIntervalAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	wyEaseOut* ease = WYNEW wyEaseOut(rate, wrapped);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ease);
	wyObjectLazyRelease(ease);
}
