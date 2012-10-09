#include "com_wiyun_engine_actions_ease_EaseBounceInOut.h"
#include "wyEaseBounceInOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ease_EaseBounceInOut_nativeInit
  (JNIEnv * env, jobject thiz, jobject action) {
	wyIntervalAction* wrapped = action == NULL ? NULL : (wyIntervalAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	wyEaseBounceInOut* ease = WYNEW wyEaseBounceInOut(wrapped);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ease);
	wyObjectLazyRelease(ease);
}
