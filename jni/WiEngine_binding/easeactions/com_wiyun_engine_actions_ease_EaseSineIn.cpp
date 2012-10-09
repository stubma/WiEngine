#include "com_wiyun_engine_actions_ease_EaseSineIn.h"
#include "wyEaseSineIn.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ease_EaseSineIn_nativeInit
  (JNIEnv * env, jobject thiz, jobject action) {
	wyIntervalAction* wrapped = action == NULL ? NULL : (wyIntervalAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	wyEaseSineIn* ease = WYNEW wyEaseSineIn(wrapped);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ease);
	wyObjectLazyRelease(ease);
}
