#include "com_wiyun_engine_actions_ease_EaseIn.h"
#include "wyEaseIn.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ease_EaseIn_nativeInit
  (JNIEnv * env, jobject thiz, jobject action, jfloat rate) {
	wyIntervalAction* wrapped = action == NULL ? NULL : (wyIntervalAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	wyEaseIn* ease = WYNEW wyEaseIn(rate, wrapped);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ease);
	wyObjectLazyRelease(ease);
}
