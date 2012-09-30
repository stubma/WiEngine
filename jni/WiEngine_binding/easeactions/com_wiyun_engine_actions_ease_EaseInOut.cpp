#include "com_wiyun_engine_actions_ease_EaseInOut.h"
#include "wyEaseInOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ease_EaseInOut_nativeInit
  (JNIEnv * env, jobject thiz, jobject action, jfloat rate) {
	wyIntervalAction* wrapped = action == NULL ? NULL : (wyIntervalAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	wyEaseInOut* ease = WYNEW wyEaseInOut(rate, wrapped);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ease);
	wyObjectLazyRelease(ease);
}
