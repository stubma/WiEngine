#include "com_wiyun_engine_actions_ease_EaseSineInOut.h"
#include "wyEaseSineInOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ease_EaseSineInOut_nativeInit
  (JNIEnv * env, jobject thiz, jobject action) {
	wyIntervalAction* wrapped = action == NULL ? NULL : (wyIntervalAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	wyEaseSineInOut* ease = WYNEW wyEaseSineInOut(wrapped);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ease);
	wyObjectLazyRelease(ease);
}
