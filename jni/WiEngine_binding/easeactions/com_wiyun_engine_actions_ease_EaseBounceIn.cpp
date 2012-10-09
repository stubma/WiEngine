#include "com_wiyun_engine_actions_ease_EaseBounceIn.h"
#include "wyEaseBounceIn.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ease_EaseBounceIn_nativeInit
  (JNIEnv * env, jobject thiz, jobject action) {
	wyIntervalAction* wrapped = action == NULL ? NULL : (wyIntervalAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	wyEaseBounceIn* ease = WYNEW wyEaseBounceIn(wrapped);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ease);
	wyObjectLazyRelease(ease);
}
