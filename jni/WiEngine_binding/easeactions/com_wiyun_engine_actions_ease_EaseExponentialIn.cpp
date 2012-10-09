#include "com_wiyun_engine_actions_ease_EaseExponentialIn.h"
#include "wyEaseExponentialIn.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ease_EaseExponentialIn_nativeInit
  (JNIEnv * env, jobject thiz, jobject action) {
	wyIntervalAction* wrapped = action == NULL ? NULL : (wyIntervalAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	wyEaseExponentialIn* ease = WYNEW wyEaseExponentialIn(wrapped);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ease);
	wyObjectLazyRelease(ease);
}
